#include "HC_05.h"

#include <SoftwareSerial.h>

SoftwareSerial mySerial(soft_rx, soft_tx);  // rx, tx

/**
 * @brief Construct a new hc 05::hc 05 object
 *
 * @param uuid HC_05 모듈의 이름 (스캔 동작에 노출되는 이름)
 * @param uart HC_05 모듈의 통신보율 (통신 보율)
 * @param pswd HC_05 모듈의 패스워드 (SPP 연결시 사용)
 * @param polar HC_05 모듈의 LED 동작 (DTR 신호에 사용)
 * @param role HC_05 모듈의 역할 설정 (마스터, 슬레이브)
 * @param cmode HC_05 모듈의 연결 모드 (바인드, 페어, 패시브)
 * @param pin
 */
HC_05::HC_05(String uuid, String uart, String pswd, String polar, String role, String cmode, int16_t pin) {
    uuid_p = uuid;
    uart_p = uart;
    pswd_p = pswd;
    polar_p = polar;
    role_p = role;
    cmode_p = cmode;
    key_p = pin;
    pinMode(key_p, OUTPUT);
}

// 블루투스 모듈 AT 명령 제어 핀
void HC_05::setATPort(int16_t pin) {
    int16_t key_p = pin;
    pinMode(key_p, OUTPUT);
    delay(100);
}

void HC_05::initDevice(int baud) {
    mySerial.begin(baud);  // HC-05 모듈의 기본 통신은 보율이 9600로 설정되어있다.
    ATHead();
    writeSerialString("AT+NAME=" + uuid_p);
    writeSerialString("AT+UART=" + uart_p + ",0,0");
    writeSerialString("AT+POLAR=" + polar_p);  // 기본 설정 1, 1
    writeSerialString("AT+ROLE=" + role_p);
    writeSerialString("AT+CMODE=" + cmode_p);
    writeSerialString("AT+PSWD=" + pswd_p);
    ATEnd();
    mySerial.begin(115200);
}

void HC_05::ATHead() {
    digitalWrite(key_p, HIGH);
    writeSerialString("AT");
}
void HC_05::ATCommand(String s1, String s2) { writeSerialString(s1 + s2); }
void HC_05::ATEnd() {
    writeSerialString("AT+RESET");
    delay(50);
    digitalWrite(key_p, LOW);
    delay(50);
}

// 가끔 명령이 씹히거나 에러를 출력하는 경우가 있어 여러번 보내도록 함.
// 3번을 기본으로 설정됨
void HC_05::writeSerialString(String str, int n) {
    for (int i = n; i > 0; i--) {
        mySerial.println(str);
        debugln(str);
        delay(100);
    }
}