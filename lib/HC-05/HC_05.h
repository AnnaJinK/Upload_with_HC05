#ifndef HC_05_H
#define HC_05_H

#ifdef ARDUINO
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#endif

#if DEBUG == true
#define debug(...) Serial.print(__VA_ARGS__)
#define debugln(...) Serial.println(__VA_ARGS__)
#else
#define debug(...)
#define debugln(...)
#endif

#ifndef soft_rx
#define soft_rx 2
#endif
#ifndef soft_tx
#define soft_tx 3
#endif

class HC_05 {
   public:
    HC_05(String uuid, String uart = "115200", String pswd = "0000", String polar = "1,0", String role = "0", String cmode = "1", int16_t pin = 4);

    void setATPort(int16_t pin);       // 블루투스 모듈 AT 명령 제어 핀
    void initDevice(int baud = 9600);  // HC_05 모듈 초기화
    void ATHead();
    void ATCommand(String s1, String s2 = "");  // 명령어 조합
    void ATEnd();
    void writeSerialString(String str, int n = 3);  // 문자열 전송

   protected:
    String AT_Feedback = "";
    String uuid_p;
    String uart_p;
    String polar_p;
    String pswd_p;
    String role_p;
    String cmode_p;
    int16_t key_p;
};

#endif  // HC_05_H