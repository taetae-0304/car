#include <Servo.h> //서보모터 라이브러리
const int TRIG1 = 9;
const int ECHO1 = 8;
const int IN1 = 7; 
const int IN2 = 6;
const int ENA = 5;
const int TRIG2 = 4;
const int ECHO2 = 3;
const int sw1 = 2; //좌회전 버튼
const int sw2 = 10; //우회전 버튼
const int servopin = 11; //피니언 역할을 하는 서보모터

Servo servo_piniun; //서보모터 객체 생성
int currentAngle = 90;  // 시작 각도 (중간)

void setup() {
  Serial.begin(9600); 
  pinMode(TRIG1,OUTPUT);
  pinMode(ECHO1,INPUT);
  pinMode(TRIG2,OUTPUT);
  pinMode(ECHO2,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  servo_piniun.attach(servopin); //서보모터 핀 설정
  servo_piniun.write(currentAngle); //서보모터 핀 설정
}

void loop() {
 long duration1, distance1;  
 digitalWrite(TRIG1, LOW); 
 delayMicroseconds(2); 
 digitalWrite(TRIG1, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(TRIG1, LOW); 
 duration1 = pulseIn (ECHO1, HIGH);
  
 distance1 = duration1 * 17 / 1000;


 Serial.println(duration1 ); 
 Serial.print("\nDIstance1 : "); 
 Serial.print(distance1);  
 Serial.println(" Cm"); 
 delay(1000); 

 long duration2, distance2;   
 digitalWrite(TRIG2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(TRIG2, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(TRIG2, LOW); 
 duration2 = pulseIn (ECHO2, HIGH);
  
 distance2 = duration2 * 17 / 1000; 


 Serial.println(duration2 ); 
 Serial.print("\nDIstance2 : "); 
 Serial.print(distance2);  
 Serial.println(" Cm"); 
 delay(1000); 


 if(distance1 < 5)
 {
  digitalWrite(IN1, LOW); 
 digitalWrite(IN2, HIGH);
 analogWrite(ENA, 200);
 }else {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
}

if(distance2 > 5)
 {
  digitalWrite(IN1, LOW); 
 digitalWrite(IN2, HIGH);
 analogWrite(ENA, 200);
 }else {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
}


if (digitalRead(sw1) == HIGH) {
    if (currentAngle < 180) {
      currentAngle++;
      servo_piniun.write(currentAngle); //.write는 모터 움직이는 명령어
      delay(15);  // 서보가 움직일 시간
    }
  } else if (digitalRead(sw2) == HIGH) {
    if (currentAngle > 0) {
      currentAngle--;
      servo_piniun.write(currentAngle);
      delay(15);
    }
  }
  // 둘 다 안 눌렀으면 각도 변화 없음 누를때만 작동


}
