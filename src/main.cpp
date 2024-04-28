/**
 * @file main.cpp
 * @author AnnajinK (hee.kim6133@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <HC_05.h>

/**
 * 기본 정의 된 소프으퉤어 시리얼 핀은 2, 3 입니다.
 * 다른 핀으로 정의하려면 다음과 같이 정의하세요.
 * #define soft_rx 핀 번호
 * #define soft_tx 핀 번호
 */

// 스캔 동작에 노출되는 블루투스 모듈의 이름입니다.
// 원하는 이름으로 변경해보세요.
String D_NAME = "Arduino_Uno_BT";

/**
 * @brief Construct a new hc 05::hc 05 object
 * @param uuid HC_05 모듈의 이름 (스캔 동작에 노출되는 이름)
 * @param uart HC_05 모듈의 통신보율 (통신 보율)
 * @param pswd HC_05 모듈의 패스워드 (SPP 연결시 사용)
 * @param role HC_05 모듈의 역할 설정 (마스터, 슬레이브)
 * @param cmode HC_05 모듈의 연결 모드 (바인드, 페어, 패시브)
 * @param pin HC_05 모듈의 Key 핀이 연결되는 포트입니다.
 *
 * 기본 세팅
 * name : Arduino_Uno_BT
 * pass : 0000
 * baud : 115200
 * polar : 1,0
 * role : 0
 * cmode : 1
 * AT pin : D4
 *
 * HC_05 과 소프트 웨어 시리얼로 통신하도록 되어있습니다.
 * HC_05 와 연결된 상태로 이 프로그램을 아두이노에 업로드 하면
 * HC_05 를 통한 블루투스 펌웨어 업로드가 가능하도록 HC_05 을 세팅합니다
 */
HC_05 uno_bt(D_NAME);

void setup() {
    Serial.begin(115200);
    // 만약 HC - 05 모듈의 설정이 정상적으로 적용되지 않거나 문자열이 손상되어 출력된다면
    // uno_bt.initDevice(); 로 재시도 해보고 그래도 안된다면,
    // uno_bt.initDevice(115200); 을 사용하여 HC-05 을 재설정 해봅니다.
    // 통신 보율은 115200 로 적용되었으나 블루투스 이름 설정이나 기타 설정 명령을 인식하지 못했을 가능성이 있습니다.
    uno_bt.initDevice();
    delay(200);
    Serial.println();
    Serial.println("잠시 후 HC-05 모듈의 세팅이 완료됩니다!");
    Serial.println("1. HC-05 모듈의 RX 는 아두이노의 TX 에 연결합니다. (로직 레벨 컨버터 사용 권장!)");
    Serial.println("2. HC-05 모듈의 TX 는 아두이노의 RX 에 연결합니다.");
    Serial.println("3. HC-05 모듈의 State 핀과 아두이노의 Reset 핀 사이에 1uF 이상의 세라믹 콘덴서를 연결합니다.");
    Serial.println("4. 아두이노의 D4 에 연결된 Key 핀을 제거합니다.");
    Serial.println("5. PC 에서 블루투스 장치를 스캔하여 Arduino_Uno_BT 장치를 찾아 연결하세요.");
    Serial.println("6. 기본으로 설정된 블루투스 비밀번호는 0000 입니다.");
    Serial.println("7. HC-05 모듈이 PC와 성공적으로 연결되면 컴퓨테어 2개의 COM Port 가 생성됩니다.");
    Serial.println("8. 둘 중 하나의 COM Port 만 시리얼 통신으로 사용가능합니다.");
    Serial.println("9. 시리얼 통신이 가능한 포트가 펌웨어 업로드가 가능한 포트입니다");
    Serial.println("10. Blink 예제를 업로드하여 정상적으로 업로드되는 포트를 사용합니다.");
    Serial.println("11. 사용자가 리셋 버튼을 누르지 않아도 스스로 펌웨어가 업로드되면 DTR 설정이 정상적으로 완료된것입니다.");
    Serial.println("12. HC-05 모듈이 연결된 상태에서는 USB UART 를 정상적으로 사용할 수 없으니 주의하세요.");
    Serial.println();
}

void loop() {  // 메인루프
}