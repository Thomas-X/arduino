int reading;
//Analog pin thats connected to the LM35 sensor
int tempraturePin = 0; 


void setup() {
 Serial.begin(9600);
 // Set analog voltage to 1.1v instead of 5v (for more accurate reading)
 analogReference(INTERNAL);
}

float voltage = 1.1;
unsigned long sum;
int count = 0;
double calibrationModifier = 10;
void loop() { 
  if(count <= 100) {
    reading = analogRead(tempraturePin);

    // voltage = 1.1
    // reading = the mv measured in volts, so if its 22 centigrade, de measurement would be 22 mv
    // 10 = since 10 mv = 1 C we convert to C
    // calibrationModifier = the modifier used for calibration for getting accurate readings. (this number is pretty arbitrary imho)
    // 1023 = analog divider for reading from a voltage (which we are doing to read the temprature) 
    // more info on the mysterious 1023: https://forum.arduino.cc/index.php?topic=303189.0
    float tempratureInCelsius = ((voltage * reading * 10) * calibrationModifier) / 1023;
    sum += tempratureInCelsius;
    count++;
  }
  if(count == 100) {
     double avgTemprature = (sum / count);
     
     Serial.println("AVG TEMP IN CELSIUS: ");
     Serial.println(avgTemprature);
     Serial.println("");

     // reset readings & count
     count = 0;
     sum = 0;
  }

  // delay per average reading = delayInMs * countMax
  // 20 * 100 = 2000ms, every 2sec avg reading is done
  // 60 * 100 = 6000ms, every 6sec avg reading is done
  delay(60);
}
