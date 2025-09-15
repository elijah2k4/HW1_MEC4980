#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int buttonPin1 = 6;
int buttonPin2 = 10;  
int buttonPin3 = 12;
int buttonPin4 = 13; 
int ledPin1 = 5; 
int ledPin2 = 9;
int ledPin3 = 11;
int ledPin4 = A5; 

// lock variables 
int lockOne = 0; 
int lockTwo = 0; 
int lockThree = 0; 
int lockFour = 0;
 

// unsigned long makes all values positive and able to store more values for the first light function 
unsigned long startTime = 0;
bool timerActive = false; 
bool lightOn = false; 

void setup() {
  Serial.begin(115200);  
  delay(2000); 
  Serial.println("Starting Top Secret Military Project ");
  pinMode(buttonPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(ledPin4, OUTPUT);

}// functions to turn on the LEDs
void turnOnLED1() { 
  digitalWrite(ledPin1, HIGH);
}

void turnOnLED2() { 
  digitalWrite(ledPin2, HIGH);
}

void turnOnLED3() { 
  digitalWrite(ledPin3, HIGH);
}

void turnOnLED4() { 
  digitalWrite(ledPin4, HIGH);
}


void firstLight() {
  int buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH && !timerActive && lockOne == 0) {
    Serial.println("Loading a new energy device. Please wait... ");
    startTime = millis(); 
    timerActive = true; 
    delay(500);
    }
  
  else if (buttonState1 == HIGH && timerActive && lockOne == 0) { 
      Serial.println("Loading sequence cancelled. Press the button again to restart."); 
      timerActive = false; 
      startTime = 0; 
      delay(500);
  }
  
  if (timerActive == true && millis() - startTime >= 2500 && lockOne == 0) { 
  turnOnLED1(); 
  Serial.println("Loading process complete! Ready for material loading. ");
  timerActive = false;
  lightOn = true;
  lockOne = 1;
}
}

void secondLight() {
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH && lockTwo == 0 && lockOne == 1) {
    Serial.println("Material loading in progress. Please wait... ");
    delay(1000); 
    turnOnLED2(); 
    Serial.println("Material loading complete! Detonation sequence ready. ");
    lockTwo = 1;
  }
}

void blinkLight3() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin3, HIGH); 
    delay(250); 
    digitalWrite(ledPin3, LOW); 
    delay(250); 
    digitalWrite(ledPin3, HIGH); 
    delay(250); 
    digitalWrite(ledPin3, LOW); 
    delay(250); 
  }
}

void thirdLight() {
  int buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 == HIGH && lockThree == 0 && lockTwo == 1) {
    Serial.println("Detonation sequence initiated. Stand by for countdown. ");
    blinkLight3(); 
    Serial.println("5 seconds to detonation.   ");
    digitalWrite(ledPin3, HIGH); 
    delay(500); 
    digitalWrite(ledPin3, LOW);  
    delay(500); 
    Serial.println("4 seconds to detonation.   ");
    digitalWrite(ledPin3, HIGH); 
    delay(500); 
    digitalWrite(ledPin3, LOW);
    delay(500); 
    Serial.println("3 seconds to detonation.   ");
    digitalWrite(ledPin3, HIGH); 
    delay(500); 
    digitalWrite(ledPin3, LOW); 
    delay(500); 
    Serial.println("2 seconds to detonation.   ");
    digitalWrite(ledPin3, HIGH); 
    delay(500); 
    digitalWrite(ledPin3, LOW); 
    delay(500);        
    Serial.println("1 seconds to detonation.   ");
    digitalWrite(ledPin3, HIGH); 
    delay(500); 
    digitalWrite(ledPin3, LOW);   
    delay(500);      
    Serial.println("BOOM! Detonation complete. Energy extracted. Ready for loading process. ");
    turnOnLED3(); 
    lockThree = 1;
  }
}

void fourthLight() {
  int buttonState4 = digitalRead(buttonPin4);
  if (buttonState4 == HIGH && lockFour == 0 && lockThree == 1) {
    Serial.println("Vehicle is en route to the detonation site. ");
    delay(4000); 
    turnOnLED4(); 
    Serial.println("Vehicle has arrived and the device is ready to be loaded. ");
    delay(500); 
    Serial.println("To reset the system, press the top and botton buttons simultaneously. ");
    lockFour = 1;
  }
} 

void resetProcess() { 
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  if (buttonState1 == HIGH && buttonState4 == HIGH && lockOne == lockTwo == lockThree == lockFour == 1) {
    Serial.println("System reset initiated. All processes are ready again. ");
        digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
    lockOne = 0; 
    lockTwo = 0; 
    lockThree = 0; 
    lockFour = 0; 
    startTime = 0; 
    lightOn = false;
    delay(2000); 
  }
}

void loop(){ 
  // All functions called to be used 
  firstLight();
  secondLight(); 
  thirdLight(); 
  fourthLight(); 
  resetProcess();
}

