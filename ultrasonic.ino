/*
 * created by Rui Santos: complete guide for ultrasonic sensor HC-SR04 
 * 
 * ultrasonic pins:
 *  VCC: +5V DC
 *  Trig: Trigger (INPUT) pin 11
 *  Echo: Echo (OUTPUT) pin 12
 *  GND
 * 
 * name: Allan Vikiru
 * St.No 098587
 * Date: 13/06/2023
  */

int trigPin = 11;
int echoPin = 12;
long duration, cm, inches;

void setup() {
  // serial port begin
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // the sensor is triggered by a HIGH pulse of 10 or more microseconds. 
  // give a short LOW pulse beforehand to ensure clean HIGH pulse.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending 
  // of the ping to reception of its echo off an object
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);

}
