//아두이노 시작하기
//아두이노 홈페이지 들어가서 스케치 다운로드
//아두이노 UNO를 노트북과 연결
//LED 또는 네오픽셀을 아두이노 회로에 연결
//LED는 +(더 긴것)은 GND포트에 -는 13포트
//NEOPIXEL은 I <-> O와 연결 후 O의 I를 ~11에 G(+)를 GND, V(-)를 5V에 연결 


#include <Adafruit_NeoPixel.h>  //adafruit_Neopixel 라이브러리 포함 ( 툴 -> 라이브러리 관리에서 설치)

int num = 11;  //핀 num
int pixel = 2;  //pixel 개수



Adafruit_NeoPixel neo = Adafruit_NeoPixel(pixel, num, NEO_GRB + NEO_KHZ800); //객체 선언, 마지막 인수는 네오픽셀의 종류

int led = 11;

void setup() {  //설정 구조
  //pinMode(led, OUTPUT);  //LED MODE
  neo.begin();  //네오픽셀 mode begin
}

void loop() {  //설정된 것의 동작을 설정
 // LED 디지털
 // digitalWrite(13, HIGH);  
 // delay(1000);
 // digitalWrite(13, LOW);
 // delay(1000);

 //LED 아날로그
   //analogWrite(11,255);
   //delay(1000);
   //analogWrite(11,180);
   //delay(1000);
   //analogWrite(11,50);
   //delay(1000);
   //analogWrite(11,180);
   //delay(1000);

  //좀 더 부드럽게 작성
  //for(int i =0; i< 256; i++){  //점점 밝게
  //  analogWrite(11, i);
  //  delay(50);
  //}

  //for(int i =255; i >=0; i--){  //점점 어둡게
  //  analogWrite(11, i);
  //  delay(50);
  //}

  // 네오픽셀 
  // adafruit neopixel 라이브러리 설치

  //neo.setPixelColor(0, 255, 0, 0);  //첫번째 0은 아두이노 보드에서 얼마나 가까운지, 색깔은 빨간색 
  //neo.setPixelColor(1, 0, 255, 0);  //멀리 떨어진 neopixel은 초록색
  //neo.show();

  //네오픽셀 색깔 바꾸기
  neo.setPixelColor(0, 255, 0, 0);
  neo.setPixelColor(1, 0, 255, 0);
  delay(1000);
  neo.show();
  neo.setPixelColor(0, 50, 30, 20);
  neo.setPixelColor(1, 20, 70, 30);
  delay(1000);
  neo.show();
}
