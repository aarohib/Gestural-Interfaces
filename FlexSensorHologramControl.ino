/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/
int fs1value;                   // variable to capture flex sensor values               

// the setup routine runs once when you press reset:
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;
void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // Adding a smoothening process to stabilize the readings so the hologram doesn't look glitchy or keep moving.
      // read the input pin:
      fs1value = analogRead(A0);
      // subtract the last reading:
      total = total - readings[readIndex];
      // read from the sensor:
      readings[readIndex] = fs1value;
      // add the reading to the total:
      total = total + readings[readIndex];
      // advance to the next position in the array:
      readIndex = readIndex + 1;
    
      // if we're at the end of the array...
      if (readIndex >= numReadings) {
        // ...wrap around to the beginning:
        readIndex = 0;
      }
      // calculate the average:
      average = total / numReadings;
  // send it to the computer as ASCII digits
  // Serial.println(average);
  // print out the state of the button:
  // Serial.println(fs1value);

  float values[] = {average, 0, 0};                      //creates an array of the values coming in from the sensor reading. 
  Serial.flush();                                        //clears any possible left over information
  Serial.print(map(values[0], 100, 300, 0, 360));        //Resizes values from the range on arduino input to 360 of rotation. These values are sent to the Unity code.
  Serial.print(",");
  Serial.print(map(values[1], 100, 300, 0, 360));
  Serial.print(",");
  Serial.print(map(values[2], 100, 300, 0, 360));
  Serial.println();
  delay(10);
}
