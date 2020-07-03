#include <Servo.h>

int sensorPin1 = A0;
Servo myservo1;
float angle1 = 0;
float volume1 = 0;

int sensorPin2 = A1;
Servo myservo2;
float angle2 = 0;
float volume2 = 0;


void setup() {
  myservo1.attach(10);
  myservo2.attach(9);
  Serial.begin(9600);
}

void loop() {
  volume1 = analogRead(sensorPin1);
  volume1 = mapfloat(volume1,0,1023,0.001,0.01);
  float n = (float) sin(angle1);
  float val1 = n * 90.0 + 90.0;
  myservo1.write(val1);
  
  volume2 = analogRead(sensorPin2);
  volume2 = mapfloat(volume2,0,1023,0.001,0.01);
  float m = (float) sin(angle2);
  float val2 = m * 90.0 + 90.0;
  myservo2.write(val2);

  
  delay(5);
  angle1 += volume1 * 5;
  angle2 += volume2 * 5;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
