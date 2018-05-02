
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
    {'1','2','3','4'},
    {'5','6','7','8'},
    {'9','0','0','0'},
    {'0','0','0','0'}
};

// digital pins, 
byte rowPins[ROWS] = {4, 5, 6, 7}; 
byte colPins[COLS] = {9,10,11,12};

const int GREEN_LED = 3;
const int RED_LED = 2;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );; 

void setup(){
  Serial.begin(9600);

  // Register LED pins
  // red
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);

  // green
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
}

int values1 = 0;
int values2 = 0;
int values3 = 0;
int values4 = 0;

int idx = 0;
void loop(){
  // Add values to current data set
  char keyValue = keypad.getKey();
  if (keyValue && keyValue > 0){
    // Typecast char to int
    if(idx == 0) {
      values1 = (int)keyValue - 48;
    }
    if(idx == 1) {
      values2 = (int)keyValue - 48;
    }
    if(idx == 2) {
      values3 = (int)keyValue - 48;
    }
    if(idx == 3) {
      values4 = (int)keyValue - 48;
    }
    idx++;
    if(idx > 3) {
      idx = 0;
    }
  }
  
  // Unlock check stuffss
  if(values1 == 1 && values2 == 2 && values3 == 3 && values4 == 4) {
    Serial.println("Unlock!");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(5000);
    values1 = 0;
    values2 = 0;
    values3 = 0;
    values4 = 0;
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}
