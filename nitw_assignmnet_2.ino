#include <Servo.h>
int us_1,us_2,ir_1,ir_2,ir_3,ir_4,led_r,led_b,led_g,led_y,servo_1=0,servo_2=0;
Servo servo_11;
Servo servo_3;
long incoming(int triggerPin, int echoPin)
{ 
   pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
void gate_1_open(){
  for (servo_1 = 0; servo_1 <= 50; servo_1 += 1) {
    servo_11.write(servo_1);
    delay(15);
  }
    delay(3000);
  for (servo_1 = 50; servo_1 >= 0; servo_1 -= 1) {
    servo_11.write(servo_1);
    delay(15); 
  }
}
void collecting_order(){
  ir_1=digitalRead(12); 
  ir_2=digitalRead(10); 
  ir_3=digitalRead(9); 
  ir_4=digitalRead(8); 
  if(ir_1){ 
    digitalWrite(7, HIGH);//red_led will glow 
    }
    if(ir_2){ 
    digitalWrite(6, HIGH);//blue_led will glow 
    }
    if(ir_3){ 
    digitalWrite(5, HIGH);//green_led will glow 
    }
    if(ir_4){ 
    digitalWrite(4, HIGH);//yellow_led will glow 
    }
  }
 long outgoing(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
 }
 void gate_2_open(){
  for (servo_2 = 0; servo_2 <= 50; servo_2 += 1) {
    servo_3.write(servo_2);
    delay(15);
  }
    delay(3000);
  for (servo_2 = 50; servo_2 >= 0; servo_2 -= 1) {
    servo_3.write(servo_2);
    delay(15); 
  }
 }
void setup() {
 pinMode(13,OUTPUT);//ultrasonic_sensor_1
 servo_11.attach(11, 500, 2500);////servomotor_1
 pinMode(12,OUTPUT);//infrared_sensor_1
 pinMode(10,OUTPUT);//infrared_sensor_2
 pinMode(9,OUTPUT);//infrared_sensor_3
 pinMode(8,OUTPUT);//infrared_sensor_4
 pinMode(7,OUTPUT);//led_red
 pinMode(6,OUTPUT);//led_blue
 pinMode(5,OUTPUT);//led_green
 pinMode(4,OUTPUT);//led_yellow
 pinMode(2,OUTPUT);//ultrasonic_sensor_2
 servo_3.attach(3, 500, 2500);//servomotor_2
 Serial.begin(9600);
}
void loop() {
us_1=0.01723 * incoming(13,13);//entry distance of the car in cm
Serial.print(us_1);
Serial.println(" cm_of_us_1");
if(us_1<=140){
gate_1_open();
}
collecting_order();
us_2=(0.01723 * outgoing(2, 2));//exit distance of the car in cm
Serial.print(us_2);
Serial.println(" cm_of_us_2");
if(us_2<=69.5){
gate_2_open();
  }
}        
