#include <Servo.h>

int LED_LEFT = 37;

// IR Sensors 
int IR1 = A8; // the number of the Arduino PIN, that line tracing sensor 1 is connected to.
int IR2 = A9; // the number of the Arduino PIN, that line tracing sensor 2 is connected to.
int IR3 = A10;// the number of the Arduino PIN, that line tracing sensor 3 is connected to.
int IR4 = A11;// the number of the Arduino PIN, that line tracing sensor 4 is connected to.
int IR5 = A12;// the number of the Arduino PIN, that line tracing sensor 5 is connected to.
int IR6 = A13;// the number of the Arduino PIN, that line tracing sensor 6 is connected to.
int IR7 = A14;// the number of the Arduino PIN, that line tracing sensor 7 is connected to.
int IR8 = A15;// the number of the Arduino PIN, that line tracing sensor 8 is connected to.

Servo Oshan ;

 
//Motors 
#define LEFT_FRONT_MOTOR_EN 8
#define LEFT_FRONT_MOTOR_A 26
#define LEFT_FRONT_MOTOR_B 27

#define LEFT_BACK_MOTOR_EN 7
#define LEFT_BACK_MOTOR_B 5
#define LEFT_BACK_MOTOR_A 6

#define RIGHT_FRONT_MOTOR_EN 10
#define RIGHT_FRONT_MOTOR_A 28
#define RIGHT_FRONT_MOTOR_B 29

#define RIGHT_BACK_MOTOR_EN 9
#define RIGHT_BACK_MOTOR_A 30
#define RIGHT_BACK_MOTOR_B 31

int s1, s2, s3, s4, s5 , s6, s7, s8;

const int FRONT_TRIG_PIN = A5; // the number of the PIN, that front ultrasonic sensor's trigger PIN is connected to.
const int FRONT_ECHO_PIN = 43;// the number of the PIN, that front ultrasonic sensor's echo PIN is connected to.

long FRONT_DURATION;//variable to store the duration.
int FRONT_DISTANCE;//variable to store the duration.


void setup() {
 
pinMode(LED_LEFT,OUTPUT);
  
  // Making all IR sensors to take Inputs 
  pinMode(leftVeryMost, INPUT);
  pinMode(leftMost, INPUT);
  pinMode(left, INPUT);
  pinMode(middleLeft, INPUT);
  pinMode(middleRight, INPUT);
  pinMode(right, INPUT);
  pinMode(rightMost, INPUT);
  pinMode(rightVeryMost, INPUT);

  //making all motor driver PINs as output PINs
  pinMode(LEFT_FRONT_MOTOR_EN, OUTPUT);
  pinMode(LEFT_FRONT_MOTOR_A, OUTPUT);
  pinMode(LEFT_FRONT_MOTOR_B, OUTPUT);

  pinMode(LEFT_BACK_MOTOR_EN, OUTPUT);
  pinMode(LEFT_BACK_MOTOR_A, OUTPUT);
  pinMode(LEFT_BACK_MOTOR_B, OUTPUT);

  pinMode(RIGHT_FRONT_MOTOR_EN, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_B, OUTPUT);

  pinMode(RIGHT_BACK_MOTOR_EN, OUTPUT);
  pinMode(RIGHT_BACK_MOTOR_A, OUTPUT);
  pinMode(RIGHT_BACK_MOTOR_B, OUTPUT);



  pinMode(FRONT_TRIG_PIN, OUTPUT);
  pinMode(FRONT_ECHO_PIN, INPUT);

  Oshan.attach (9);
  Oshan.write(0);


Serial.begin(9600);

}

void loop() {
  // Putting Diferent IR sensors reading to Variables 
  s1 = digitalRead(leftVeryMost);
  s2 = digitalRead(leftMost);
  s3 = digitalRead(left);
  s4 = digitalRead(middleLeft);
  s5 = digitalRead(middleRight);
  s6 = digitalRead(right);
  s7 = digitalRead(rightMost);
  s8 = digitalRead(rightVeryMost);

  // Forward Going  

  if(s1==1 && s2==1 && s3==0 && s4==0 && s5==0 && s6==1 && s7==1 && s8==1){
    foward();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==0 && s6==1 && s7==1 && s8==1){
    foward();
  }
  if(s1==1 && s2==1 && s3==1 && s4==0 && s5==1 && s6==1 && s7==1 && s8==1){
    foward();
  }
    

  // Stoping
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    stopAll();
  } 

  //Turning Left
  if(s1==1 && s2==1 && s3==0 && s4==0  && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==1 && s2==0 && s3==0 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==0 && s2==0 && s3==0 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==0 && s2==0 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==0 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==1 && s2==1 && s3==0 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  if(s1==1 && s2==0 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1){
    left1();
  }
  
  //Turning Right
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==0 && s6==0 && s7==1 && s8==1){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==0 && s7==0 && s8==1){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==0 && s7==0 && s8==0){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==0 && s8==0){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1  && s7==1 && s8==0){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==0  && s7==1 && s8==1){
    right1();
  }
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1  && s7==0 && s8==1){
    right1();
  }


//-------------------------front ultrasonic sensor------------------------------

digitalWrite(FRONT_TRIG_PIN, LOW);//turning off the trigger if its already on.
delayMicroseconds(2);//waiting for two microseconds.

digitalWrite(FRONT_TRIG_PIN, HIGH);//turning on the trigger.
delayMicroseconds(10);//waiting for ten microseconds.

digitalWrite(FRONT_TRIG_PIN, LOW);//turning off the trigger.

//doing the calculations
FRONT_DURATION = pulseIn(FRONT_ECHO_PIN, HIGH);
FRONT_DISTANCE = FRONT_DURATION * 0.034 / 2;

//printing calculations to the serial monitor.
Serial.println("FRONT_DISTANCE: ");
Serial.println(FRONT_DISTANCE);  











}
void foward() {
  // Funtion to move the Car Forward 
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
if (FRONT_DISTANCE < 5){

  barrier();
}
else {
  barrierno();
}

}
void backward() {
  // Funtion to move the car backwards 
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);
  digitalWrite(LEFT_FRONT_MOTOR_A, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_A, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);

if (FRONT_DISTANCE < 5){

  barrier();
}
else {
  barrierno();
}
}
void left1() {
  //Funtion to turn the car left 
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  digitalWrite(LEFT_FRONT_MOTOR_A, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);

  digitalWrite(LEFT_BACK_MOTOR_A, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);

if (FRONT_DISTANCE < 5){

  barrier();
}
else {
  barrierno();
}
}
void right1() {
  // Funtion to turn the car right
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);
if (FRONT_DISTANCE < 5){

  barrier();
}
else {
  barrierno();
}
}
void stopAll() {
  //Funtion to stop the car 
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
}

void  barrier(){

    digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
delay (100);

digitalWrite (LED_LEFT,HIGH);
delay (3000);

Oshan.write(0);
delay (1000);

Oshan.write(180);
delay (1000);
}

void barrierno(){
       digitalWrite (LED_LEFT,LOW);
}
  
