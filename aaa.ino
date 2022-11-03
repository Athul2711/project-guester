/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/
int validityok=0;
// These constants won't change. They're used to give names to the pins used:
const int finger1 = A0;  // Analog input pin that the potentiometer is attached to
const int finger2 = A1;  // Analog input pin that the potentiometer is attached to
const int finger3 = A2;  // Analog input pin that the potentiometer is attached to
const int finger4 = A3;  // Analog input pin that the potentiometer is attached to
const int finger5 = A4;  // Analog input pin that the potentiometer is attached to

const int batteryvolt = A5;  // Analog input pin that the potentiometer is attached to






int finger1threshok[6] = 0;        // value read from the pot
int finger1threshyou[6] = 0;        // value output to the PWM (analog out)



int sensorValue[6] = 0;        // value read from the pot
int outputValue[6] = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue(1) = analogRead(finger1);
  sensorValue(2) = analogRead(finger2);
  sensorValue(3) = analogRead(finger3);
  sensorValue(4) = analogRead(finger4);
  sensorValue(5) = analogRead(finger5);

  // map it to the range of the analog out:
  // change the analog out value:

  // print the results to the Serial Monitor:
  for(int i=0;i<=5;i++){
if((sensorValue(i)<finger1threshok(i)+10) && (sensorValue(i)>finger1threshok(i)-10)    ){

  validityok++;
}
}

  for(int i=0;i<=5;i++){
if((sensorValue(i)<finger1threshyou(i)+10) && (sensorValue(i)>finger1threshyou(i)-10)    ){

  validityyou++;
}
}

if(validityyou>=5){
  delay(2000);

validityyou=0;
  Serial.print("YOU ");

  
}


if(validityok>=5){
  delay(2000);

validityok=0;
  Serial.print("OK ");

  
}




}
