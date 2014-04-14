const int sensorPin = 0;

//int lightLevel, high = 0, low = 1023;

const int BLUE = 9;
const int GREEN = 10;
const int RED = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void blinkAlert() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(50);
  
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(250);
}


int brightness = 5;
int fadeAmount = 5;

void fadeWhite(){
  
  analogWrite(RED, brightness);
  analogWrite(BLUE, brightness);
  analogWrite(GREEN, brightness);
  
  brightness = brightness + fadeAmount;
  
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  
  delay(25);
}

void fadeYellow(){
  
  analogWrite(RED, brightness);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, brightness);
  
  brightness = brightness + fadeAmount;
  
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  
  delay(5);
}

void test() {
  analogWrite(RED, 0);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, 255);
}


void loop()
{
  
  int lightLevel = analogRead(sensorPin);
  float voltage = lightLevel * (5.0 / 1023.0);
  Serial.println(voltage);
 
 if(voltage >= 0 && voltage < 0.8){
  blinkAlert();
  /*analogWrite(RED, 255);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, 0);*/
  } 
 
 if(voltage >= 0.8 && voltage < 0.9) {
  fadeYellow();
  /*analogWrite(RED, 0);
  analogWrite(BLUE, 255);
  analogWrite(GREEN, 0);*/
  }
  
 if(voltage >= 0.9) {
  fadeWhite();
  /*analogWrite(RED, 0);
  analogWrite(BLUE, 0);
  analogWrite(GREEN ,255);*/
  }

}




