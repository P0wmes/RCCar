// Gleichstrommotor 1

int GSM1 = 7;
int lMotorF = 8;
int lMotorB  = 9;

// Gleichstrommotor 2

int GSM2 = 4;
int rMotorF = 6;
int rMotorB = 5;

char t;

void setup()
{
  pinMode(lMotorF, OUTPUT);  //left motors forward
  pinMode(lMotorB, OUTPUT);  //left motors reverse
  pinMode(rMotorF, OUTPUT);  //right motors forward
  pinMode(rMotorB, OUTPUT);  //right motors reverse
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("Start Engine");

}
void loop()
{
  if (Serial1.available()) {
    t = Serial1.read();
    Serial.println(t);
  }

  if (t == 'F') {          //move forward(all motors rotate in forward direction)
    digitalWrite(lMotorF, HIGH);
    digitalWrite(rMotorF, HIGH);
  }

  else if (t == 'B') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(lMotorB, HIGH);
    digitalWrite(rMotorB, HIGH);
  }

  else if (t == 'L') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(rMotorF, HIGH);
     digitalWrite(lMotorB, HIGH);
  }

  else if (t == 'R') {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(lMotorF, HIGH);
    digitalWrite(rMotorB, HIGH);
  }

  else if (t == 'W') {  //turn led on or off)
    digitalWrite(9, HIGH);
  }
  else if (t == 'w') {
    digitalWrite(9, LOW);
  }
  else if (t == 'S') {    //STOP (all motors stop)
    digitalWrite(lMotorF, LOW);
    digitalWrite(lMotorB, LOW);
    digitalWrite(rMotorF, LOW);
    digitalWrite(rMotorB, LOW);
  }
  delay(100);
}
