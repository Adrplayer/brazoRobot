// brazo.ino

//************************************
// Proyecto Introducción a mecatronica
//
// Proyecto: brazo robot
//
// Integrantes: - Adrian Becerra
//              - Adriana Cirilo
//              - Andrea Muñoz
//              - Andy Gutierrez
//              - Alessandro Lugo
//
//
//************************************

// Librerias
#include <Servo.h> // Libreria de control de servomotores

// Definiciones
#define B 3
#define S1 5
#define S2 6
#define S3 9
#define G 10
#define T1 2
#define T2 4
#define E1 7
#define E2 8

// Declaración de servos
Servo base;
Servo servo1;
Servo servo2;
Servo servo3;
Servo grip;

const float Velson = 34000.0;
const float crossfire = 9;

float distancia1;
float distancia2;

// Variables
int pos_base = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos_grip = 0;
int t = 2;
String inputString;

 
void setup() {

  // Inicio de Serial
  Serial.begin(9600);

  // Organización de servos
  base.attach(B);
  servo1.attach(S1);
  servo2.attach(S2);
  servo3.attach(S3);
  grip.attach(G);

  pinMode(T1,OUTPUT);
  pinMode(T2,OUTPUT);
  pinMode(E1,INPUT);
  pinMode(E2,INPUT);
}
 
void loop() {
  inT1();
  unsigned long tiempo1 = pulseIn(E1,HIGH);
  distancia1 = tiempo1 * 0.000001 * Velson / 2.0;
  inT2();
  unsigned long tiempo2 = pulseIn(E2,HIGH);
  distancia2 = tiempo2 * 0.000001 * Velson / 2.0;
  delay(100);
  SerialEvent();
  if (min(distancia1,distancia2) > crossfire){
    moveto(base,pos_base);
    moveto(servo1,pos1);
    moveto(servo2,pos2);
    moveto(servo3,pos3);
    grip.write(pos_grip);

  }
  delay(15);                       
}

void SerialEvent(){
  while(Serial.available()){
    char inputChar = Serial.read();
    inputString += inputChar;
  }
  byte prevPos = inputString.indexOf(':');
  String id = inputString.substring(0,prevPos);
  int value = inputString.substring(prevPos+1).toInt();
  if(id.equals("B")){
    pos_base = value;
  }else if(id.equals("S1")){
    pos1 = value;
  }else if(id.equals("S2")){
    pos2 = value;
  }else if(id.equals("S3")){
    pos3 = value;
  }else if(id.equals("G")){
    pos_grip = value;
  }

  inputString = "";
}

void inT1(){
  digitalWrite(T1,LOW);
  delayMicroseconds(2);
  digitalWrite(T1,HIGH);
  delayMicroseconds(10);
  digitalWrite(T1,LOW);
}
void inT2(){
  digitalWrite(T2,LOW);
  delayMicroseconds(2);
  digitalWrite(T2,HIGH);
  delayMicroseconds(10);
  digitalWrite(T2,LOW);
}

void moveto(Servo s, int x){
  int pos = s.read();
  int dif =  x - pos;
  if(dif > 0){
    for(int i = pos; i <= x; i++){
      s.write(i);
      delay(t);
    }
  }
  if(dif < 0){
    for (int i = pos; i >= x; i--){
      s.write(i);
      delay(t);
    }
    
  }
}
