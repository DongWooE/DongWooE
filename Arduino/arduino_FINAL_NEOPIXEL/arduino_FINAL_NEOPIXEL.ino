#include <Adafruit_NeoPixel.h>

int num = 11;  // 연결된 핀 번호
int pixel = 2;  //네오픽셀의 개수
int data;

Adafruit_NeoPixel neo = Adafruit_NeoPixel(pixel, num, NEO_GRB + NEO_KHZ800);

void setup() {
  neo.begin(); //네오픽셀 시작
  Serial.begin(9600);  //키보드 콜백을 받으려면 시리얼 통신이 필요
}

void loop() {
  //간단한 네오픽셀 출력
  //neo.setPixelColor(0, 0, 0, 255);
  //neo.setPixelColor(1,0, 255, 0);
  //delay(1000);
  //neo.show();

  if(Serial.available() > 0){
    data = Serial.read();  //data에 키보드로 받는 값을 대입
    }
  if(data == 'a'){
    neo.setPixelColor(0,255,0,0);
    neo.setPixelColor(1,255,0,0);
    neo.show();
    }
  if(data == 'b'){
    neo.setPixelColor(0,0,255,0);
    neo.setPixelColor(1,0,255,0);
    neo.show();
    }
  if(data == 'c'){
    neo.setPixelColor(0,0,0,255);
    neo.setPixelColor(1,0,0,255);
    neo.show();
    }
}
