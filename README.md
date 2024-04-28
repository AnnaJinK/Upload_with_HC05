## What is this?

HC-05 모듈을 사용하여 아두이노에 무선으로 펌웨어를 업로드하기 위해 필요한 모듈 세팅을 수항하는 스케치입니다.  
간단한 AT 커맨드 설정과 회로 구성으로 HC-05 모듈의 State 핀을 아두이노를 위한 DTR 신호 전달 핀으로 사용할수 있습니다.  
이 스케치에 작성된 코드를 실행하면 HC-05 로 아두이노에 펌웨어를 업로드할때 사용자가 직접 리셋 버튼을 누르지 않아도 됩니다.

## Introduction

이 스케치는 2.0-20100601 버전의 펌웨어가 적용된 HC-05 모듈을 기준으로 작성되었습니다
2.0 보다 높은 버전의 펌웨어가 설치된 모듈에서는 AT 명령어 셋이 달라 사용할 수 없을 수 있습니다.

다음은 HC_05 클래스 구성입니다.
인스턴스 선언시 블루투스 모듈의 이름 핀번호 동작 모드 등을 설정할 수 있습니다.

HC-05 모듈 설정시 아두이노와 시리얼 통신은 소프트웨어 시리얼을 사용하여 연결됩니다.
HC-05 모듈의 설정 과정을 시리얼 모니터로 관전 할수 있습니다.

```c
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
```

HC-05 모듈의 설정 완료후 펌웨어 업로드와 시리얼 통신에 사용하기 위해 회로를 다시 구성 해야합니다.

1. HC-05 모듈의 RX 는 아두이노의 TX 에 연결합니다. (로직 레벨 컨버터 사용 권장!)
2. HC-05 모듈의 TX 는 아두이노의 RX 에 연결합니다.
3. HC-05 모듈의 State 핀과 아두이노의 Reset 핀 사이에 1uF 이상의 세라믹 콘덴서를 연결합니다.
4. 아두이노의 D4 에 연결된 Key 핀을 제거합니다.
5. PC 에서 블루투스 장치를 스캔하여 Arduino_Uno_BT 장치를 찾아 연결하세요.
6. 기본으로 설정된 블루투스 비밀번호는 0000 입니다.
7. HC-05 모듈이 PC와 성공적으로 연결되면 컴퓨테어 2개의 COM Port 가 생성됩니다.
8. 둘 중 하나의 COM Port 만 시리얼 통신으로 사용가능합니다.
9. 시리얼 통신이 가능한 포트가 펌웨어 업로드가 가능한 포트입니다
10. Blink 예제를 업로드하여 정상적으로 업로드되는 포트를 사용합니다.
11. 사용자가 리셋 버튼을 누르지 않아도 스스로 펌웨어가 업로드되면 DTR 설정이 정상적으로 완료된것입니다.
12. HC-05 모듈이 연결된 상태에서는 USB UART 를 정상적으로 사용할 수 없으니 주의하세요.

로직 레벨 컨버터를 사용한 회로는 다음과 같습니다.

