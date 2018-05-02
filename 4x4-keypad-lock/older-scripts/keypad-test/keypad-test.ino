/*

1x4 Keypad from Adafruit.com (Unofficial Source) 
Original Source: Button
Referenced Tutorial on Arduino.com: http://arduino.cc/en/Tutorial/InputPullupSerial
Referenced: http://arduino.cc/en/Reference/pinMode

Turns on and off specified Pin or Prints to Serial Monitor when keys are press on a 1x4 keypad from Adafruit.com

The (OLD) circuit:
* LED attached from pin 13 to ground
* pushbutton attached to pin 2 from +5V
* pushbutton attached to pin 3 from +5V
* 10K resistor attached to pin 2 from ground

The (NEW) circuit (2014):

* Whichever component you want attached to Pin 13 (e.g- LED)
* 1x4 Keypad w/ primary pin attached to Ground and 1-4 keys attached to PINS 9-12
* Serial Monitor used for output (for testing, when not using anything attached to Pin 13) 

* Note: 
 
 

created 2005
by DojoDave 
modified 30 Aug 2011
by Tom Igoe
modified 10 Apr 2012
by mpilchfamily
modified 8 Dec 2014 
by C Cunningham

* 
* 
 */

#include <Keypad.h>
const byte rows = 1;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', '4'}
}
byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

// constants won't change. They're used here to
// set pin numbers:
//const int button1 = 9;
//const int button2 = 10;
//const int button3 = 11;
//const int button4 = 12;
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  // initialize the Serial Monitor @ 9600
  Serial.begin(9600);
  
  // initialize the keypad pin(s) as an input:
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP); 
  pinMode(button4, INPUT_PULLUP); 
}

void loop(){
  Serial.print(digitalRead(button1));

  int button1Status = digitalRead(button1);
  int button2Status = digitalRead(button2);
  int button3Status = digitalRead(button3);
  int button4Status = digitalRead(button4);

  Serial.println(button1Status);
  Serial.println(button2Status);
  Serial.println(button3Status);
  Serial.println(button4Status);

  delay(1000);
  
//  // read the state of the keypad value:
//  for(int x=0; x<2; x++)
//  {
//    //signifying the state of which the button is in by reading the appropriate pin #
//    buttonState = digitalRead(buttonPin[x]);
//
//    // check if the pushbutton on the keypad is pressed.
//    // if it is, the buttonState is LOW:
//    if (buttonState == HIGH && buttonPin[x] == 9) {    
//      // turn LED off:   
//      Serial.print("OFF * ");
//       digitalWrite(ledPin, LOW); 
//    }
//    if (buttonState == LOW && buttonPin[x] == 10) {
//      // turn LED off:
//      Serial.print("ON *");
//      digitalWrite(ledPin, HIGH);
//    }
//  }
}
