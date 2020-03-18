//Motor Connection
const int motorLeftForwards = 9;
const int motorLeftBackwards = 13;
const int motorRightForwards = 7;
const int motorRightBackwards = 8;
const int rightAnalog = 5;
const int leftAnalog = 11;


//Sensor Connection
const int left_sensor_pin = 2;
const int right_sensor_pin = 4;
const int center_sensor_pin = 12;

int left_sensor_state;
int right_sensor_state;
int center_sensor_state;
int turn_delay = 10;

int lastSensor = 1; // 0 = left, 1 = center, 2 = right

void setup() {
  pinMode(motorRightForwards, OUTPUT);
  pinMode(motorLeftForwards, OUTPUT);
  pinMode(motorRightBackwards, OUTPUT);
  pinMode(motorLeftBackwards, OUTPUT);

  pinMode(rightAnalog, OUTPUT);
  pinMode(leftAnalog, OUTPUT);

  Serial.begin(9600);
}

void loop() {  

  // 0 == on WHITE
  // 1 == off BLACK
  
  left_sensor_state = digitalRead(left_sensor_pin);
  right_sensor_state = digitalRead(right_sensor_pin);
  center_sensor_state = digitalRead(center_sensor_pin);
 
//  //Forward
  if (left_sensor_state == 0 && right_sensor_state == 0 && center_sensor_state == 1 || left_sensor_state == 0 && right_sensor_state == 0 && center_sensor_state == 0) {
  forward();
  }
  
  //Left
  if ((left_sensor_state == 1 && right_sensor_state == 0 && center_sensor_state == 1) || (left_sensor_state == 1 && right_sensor_state == 0 && center_sensor_state == 0)) {
  turnLeft();
  }
  
//  //Right
  if ((left_sensor_state == 0 && right_sensor_state == 1 && center_sensor_state == 1) || (left_sensor_state == 0 && right_sensor_state == 1 && center_sensor_state == 0)) {
  turnRight();

  }
  
  if (left_sensor_state == 1 && right_sensor_state == 1 && center_sensor_state == 1) {
  stopmoving();
  }
}

  void forward(){
    Serial.println("Going forward");
    analogWrite(rightAnalog, 32);
    digitalWrite (motorRightForwards, HIGH);
    analogWrite(leftAnalog, 24);
    digitalWrite(motorLeftForwards, HIGH);
}

  void turnRight() {
    Serial.println("Going right");
    
    analogWrite(rightAnalog, 0);
    digitalWrite (motorRightForwards, HIGH);
    analogWrite(leftAnalog, 50);
    digitalWrite(motorLeftForwards, HIGH);

  }

    void turnLeft() {
    Serial.println("going left");
    
    analogWrite(rightAnalog, 50);
    digitalWrite (motorRightForwards, HIGH);
    analogWrite(leftAnalog, 0);  
    digitalWrite(motorLeftForwards, HIGH);
  }

  
  void stopmoving() {
    Serial.println("Stopped");
    analogWrite(rightAnalog, 0);
    digitalWrite (motorRightForwards, LOW);
    analogWrite(leftAnalog, 0);
    digitalWrite(motorLeftForwards, LOW);
  }
