int a = 0; //For potentiometer calibration delay
int b = 0; //For potentiometer calibration delay
int x = 0; //Variable that ensures potentiometer ccalibration only happens once at beginning
int PotSenValue = 0;
int SoilSenValue = 0;
int WatSenState = 0; //Digital button for water resovoir level

const int Pump = 2; //Pin 7 on Attiny85
const int LedPin= 1; //Pin 6 on Attiny85
const int WatSen = 0; //Pin 5 on Attiny85
const int SoilSen = A2; //Pin 2 on Attiny85
const int PotSen = A3; //Pin 3 on Attiny85



void setup() {
  pinMode(Pump, OUTPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(WatSen, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  
  while (x < 1) {
   /*  //If the Pot value is less than 505, an led will speed up the closer you spin it to the value 505. 
   If the Pot value is more than 515, an led will speed up the closer you spin it to 515. If the Pot is
  within the parameters of 505-515, it is centered, and thus calibrated. The rapidbly flashing led 
  will turn off indicating thus, and x will equal 1. because x is now higher than zero, this while loop
  is eliminated, and the rest of the code will repeat itself indefinetley. 
  */
   int PotSenValue = analogRead(PotSen);
  
   if (PotSenValue < 505) {
    Serial.println(PotSenValue);
    int a = 0.5 * (505 - PotSenValue);
    digitalWrite(LedPin, HIGH);
    delay(a);
    digitalWrite(LedPin, LOW);
    delay(a);  
  }
  
  else if (PotSenValue > 515) {
    Serial.println(PotSenValue);
    int b = 0.5 * (PotSenValue - 505);
    digitalWrite(LedPin, HIGH);
    delay(b);
    digitalWrite(LedPin, LOW);
    delay(b);
  }
   
    if ( (PotSenValue > 505) && (PotSenValue < 515) ) {
     digitalWrite(LedPin, LOW);
     x = 1;
  }
  } //Thus marks the end of the calibrative while loop
  
  SoilSenValue = analogRead(SoilSen); //This is the rest of the code that will repeat forever
  PotSenValue = analogRead(PotSen);
  if (SoilSenValue < PotSenValue) {
    Serial.println("The soil value is ");
    Serial.println(SoilSenValue);
    Serial.print("Pump operational");
    digitalWrite(Pump, HIGH);
    delay(500);
    digitalWrite(Pump, LOW);
  }
  
  WatSenState = digitalRead(WatSen);
  if (WatSen == LOW) {
    Serial.println("The water resovoir needs to be replenished");
    digitalWrite(LedPin, HIGH);
    delay(500);
    digitalWrite(LedPin, LOW);
  }
  
  delay(100);
  
}

