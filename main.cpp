#include <Arduino.h>
// set pin numbers
const int buttonPin = 4;  // the number of the pushbutton pin
const int ledPin =  5;    // the number of the LED pin

const int buttunPin = 12;
const int LedPin2 = 11;

const int buttunpin3 = 1;
const int ledpin3 = 10;

const int buttunpin4 = 6;
const int ledpin4 = 7;

// variable for storing the pushbutton status
int buttonState = 0;
bool botao4 = 0;
bool botao12 = 0;
bool botao13 = 0;
bool botao14 = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  pinMode(4, INPUT);

    pinMode(12, INPUT);
    pinMode(8, OUTPUT);

   pinMode(3, INPUT);
   pinMode(2, OUTPUT);

  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
 //   // read the state of the pushbutton value
  // buttonState = digitalRead(buttonPin);
  // Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  // if (buttonState == HIGH) {
    // turn LED on
    // digitalWrite(ledPin, HIGH);
  // } else {
    // turn LED off
    // digitalWrite(ledPin, LOW);
  // }
  botao4 =digitalRead(4);
  Serial.println(botao4);

  if (botao4 == HIGH)  {
    digitalWrite(ledPin, HIGH);
  } else {
     digitalWrite(ledPin, LOW);
  }
 

  botao12= digitalRead(12);
  Serial.println(botao12);
  if (botao12 == HIGH) {
    digitalWrite(8, HIGH);
 
  } else {
    digitalWrite(8, LOW);
  }
 

  botao13= digitalRead(3);
 Serial.println(botao13);
  if (botao13 == HIGH) {
    digitalWrite(2, HIGH);
 
  } else {
    digitalWrite(2, LOW);
  }


   botao14= digitalRead(6);
 Serial.println(botao14);
  if (botao14 == HIGH) {
    digitalWrite(7, HIGH);
 
  } else {
    digitalWrite(7, LOW);
  }
}