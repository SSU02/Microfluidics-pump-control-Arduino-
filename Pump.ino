#define MOTOR_IN1 9
#define MOTOR_IN2 10
#define POT_PIN A0

int speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {
  speed = analogRead(POT_PIN) / 4; // map analog input (0-1023) to PWM value (0-255)
  Serial.print("Speed: ");
  Serial.println(speed);
 
  // ramp up forward
  digitalWrite(MOTOR_IN1, LOW);
  for (int i=0; i<speed; i++) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
  }

  // forward full speed for one second
  delay(20000);
 
  // ramp down forward
  for (int i=speed; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
  }

  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<speed; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }

  // backward full speed for one second
  delay(30000);

  // ramp down backward
  for (int i=speed; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }
}



int pwmPin = 12; // assigns pin 12 to variable pwm

int pot = A0; // assigns analog input A0 to variable pot

int c1 = 0;   // declares variable c1

int c2 = 0;   // declares variable c2


void setup()  // setup loop

{

  pinMode(pwmPin, OUTPUT);

  pinMode(pot, INPUT);  

}


void loop()

{

  c2= analogRead(pot);

  c1= 1024-c2;         // subtracts c2 from 1000 ans saves the result in c1

  digitalWrite(pwmPin, HIGH);

  delayMicroseconds(c1);  

  digitalWrite(pwmPin, LOW);  

  delayMicroseconds(c2);  

}
