const int sensorPin = 0;

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

const float MaxDark = 2.5;

float StartPCCVoltage;
float LightPCCVoltage;
  
void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  delay(1000);
  StartPCCVoltage = getPCCVoltage();
  Serial.println("AnalogRead on setup: "); Serial.println(StartPCCVoltage);
  blinkINIT(); 
  
  delay(5000);
  LightPCCVoltage = getPCCVoltage();
  Serial.println("AnalogRead LIGHT on setup: "); Serial.println(LightPCCVoltage);
  blinkINIT(); 
}



void loop()
{  
  
  //get current PCCVoltage
  float PCCVoltage = getPCCVoltage();
  Serial.println("AnalogRead now: "); Serial.println(PCCVoltage); 
  //create delta from DW and start
  float PCCVoltageDelta = StartPCCVoltage + LightPCCVoltage; 
  float StartYellow = PCCVoltageDelta/2;

if(PCCVoltage > 0 && PCCVoltage <= StartYellow) {blinkAlert();}
if(PCCVoltage > StartYellow && PCCVoltage < StartPCCVoltage){fadeYellow();}
if(PCCVoltage >= StartPCCVoltage){fadeWhite();}

}  


float getPCCVoltage(){
  float PCCLightLevel = analogRead(sensorPin);
  float PCCVoltage = PCCLightLevel * (5.0 / 1023.0);
  return(PCCVoltage);
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

void blinkINIT() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  delay(1000);
  
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

