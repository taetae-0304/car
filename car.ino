const int TRIG1 = 9;
const int ECHO1 = 8;
const int IN1 = 7; //후륜으로 바퀴 2개 이용 & L298N 사용하여 제어
const int IN2 = 6;
const int ENA = 5;
const int TRIG2 = 4;
const int ECHO2 = 3;

void setup() {
  Serial.begin(9600); //통신속도
  pinMode(TRIG1,OUTPUT);
  pinMode(ECHO1,INPUT);
  pinMode(TRIG2,OUTPUT);
  pinMode(ECHO2,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
}

void loop() {
 long duration1, distance1;   //long == int라 생각 대신 저장 공간이 더 많은
 digitalWrite(TRIG1, LOW); 
 delayMicroseconds(2); 
 digitalWrite(TRIG1, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(TRIG1, LOW); 
 duration1 = pulseIn (ECHO1, HIGH);
  
 distance1 = duration1 * 17 / 1000; //초음파가 이동한 거리를 cm으로 변환하는 공식


 Serial.println(duration1 ); //시리얼 모니터에 표시하는 것
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


 if(distance1 < 5) //벽과의 거리를
 {
  digitalWrite(IN1, LOW); 
 digitalWrite(IN2, HIGH);
 analogWrite(ENA, 200);
 }else {
  // 5cm 이상일 때
  digitalWrite(IN1, HIGH); //L298N 사용해서 정방향 이동 속도는 200으로 한 것
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
}

if(distance2 > 5) //바닥과의 거리를
 {
  digitalWrite(IN1, LOW); 
 digitalWrite(IN2, HIGH);
 analogWrite(ENA, 200);
 }else {
  // 5cm 이하일 때
  digitalWrite(IN1, HIGH); //L298N 사용해서 정방향 이동 속도는 200으로 한 것
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
}


}
