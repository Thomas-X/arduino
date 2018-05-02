// constants
// pin 9 = 1, pin 10 = 2, pin 11 = 3, pin 12 = 4
const int buttonPin[] = {10,9,11,12};     // the number of the pushbutton pins
const int ledPin =  13;      // the number of the LED pin

// non-constants

void setup() {
  // initialize the LED pin as an output:
//  pinMode(ledPin, OUTPUT);  
  // initialize the Serial Monitor @ 9600
  Serial.begin(9600);  
  // initialize the keypad pin(s) as an input:
  for(int x=0; x<4; x++) {
    pinMode(buttonPin[x], INPUT_PULLUP); 
  }  
}

int buttonStates[] = { 0, 0, 0, 0 };
void loop(){
  // Only register keypresses, no holds
  for (int i = 0; 0 < 4; i++) {
      int buttonState = digitalRead(buttonPin[i]);
      if(buttonState == 0 && buttonStates[i] != buttonState) {
        Serial.println("You pressed something, we dont know");
        buttonStates[i] = buttonState;
      }
  }
}
