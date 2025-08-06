const int TRIG = 9;
const int ECHO = 8;
const int m1 = 7;
const int m2 = 6;
const int m3 = 5;
const int m4 = 4;

void setup() {
  Serial.begin(9600); //통신속도
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
}

void loop() {
 long duration, distance;   //long == int라 생각 대신 저장 공간이 더 많은
 digitalWrite(TRIG, LOW); 
 delayMicroseconds(2); 
 digitalWrite(TRIG, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(TRIG, LOW); 
 duration = pulseIn (ECHO, HIGH);
  
 distance = duration * 17 / 1000; //초음파가 이동한 거리를 cm으로 변환하는 공식


 Serial.println(duration ); //시리얼 모니터에 표시하는 것
 Serial.print("\nDIstance : "); 
 Serial.print(distance);  
 Serial.println(" Cm"); 
 delay(1000); 

}
