#include <Wire.h>
#include <Stepper.h>

// CONSTANTS
const int pResistor1 = ; // position of photoresistor 1 ex A0
const int pResistor2 = ; // position of photoresistor 2 
const int pResistor3 = ; // position of photoresistor 3
const int pResistor4 = ; // position of photoresistor 4
const int pResistor5 = ; // position of photoresistor 5
const int pResistor6 = ; // position of photoresistor 6
const int pResistor7 = ; // position of photoresistor 7
const int pResistor8 = ; // position of photoresistor 8

const int stepsPerRevo = ; // however many steps per revolution for motor
Stepper myStepper(stepsPerRevo,8,9,10,11); // 8,9,10,11 represent the pins where the stepper is placed, can change if necessary

const int soilReader = ; // position of soil sensor
const int AirValue = 520;
const int WaterValue = 260;
int intervals = (AirValue - WaterValue)/3;

const int waterPump = ; // position of dc motor that powers water pump



// Variables

int value1 = 0; // store value from photoresistor 1
int value2 = 0; // store value from photoresistor 2
int value3 = 0; // store value from photoresistor 3
int value4 = 0; // store value from photoresistor 4
int value5 = 0; // store value from photoresistor 5
int value6 = 0; // store value from photoresistor 6
int value7 = 0; // store value from photoresistor 7
int value8 = 0; // store value from photoresistor 8

int soilMoistureValue = 0; // store value of soilMoisture



void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(60); // sets stepper speed at 60 rpm (can change if necessary)
  Serial.begin(9600); // initializes the serial port -- not sure what this does?
  pinMode(waterPump, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  /* Within this block of code, our smart pot takes light intensity readings, and rotates the plant accordingly to provide optimal sunlight to all areas of the plant. 
   *  It constantly takes soil moisutre readings, and when soil is too dry, the pot waters the soil. 
   */
  
  // This will constantly take light intensity readings from our photoresistors
  value1 = analogRead(pResistor1);
  value2 = analogRead(pResistor2);
  value3 = analogRead(pResistor3);
  value4 = analogRead(pResistor4);
  value5 = analogRead(pResistor5);
  value6 = analogRead(pResistor6);
  value7 = analogRead(pResistor7);
  value8 = analogRead(pResistor8);

  soilMoistureValue = analogRead(soilReader);

  // If a pResistor exceeds a certain light intensity reading, then rotate the motor half a revolution so that the pResistor getting the least light now receives the most
  // or if a pResistor is failing to read a certain intensity of light, it will rotate so that it is receiving that amount of light
  
  // CHANGE LIGHT INTENSITY THRESHOLDS 
  if (value1 > 25 || value5 < 5) { 
    Serial.println("clockwise");
    myStepper.step(stepsPerRevo / 2);
    delay(500);
  }

  else if (value2 > 25 || value6 < 5) {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevo / 2);
    delay(500);
  }

  else if (value3 > 25 || value7 < 5) {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevo / 2);
    delay(500);
  }

  else if (value4 > 25 || value 8 < 5) {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevo / 2);
    delay(500);
  }

  // Releases water when soil is dry, and stops releasing water once soil moisture falls outside of this range
  if (soilMoistureValue < AirValue && soilMoistureValue > Airvalue - intervals) {
    delay(500); // wait half a second to begin watering
    digitalWrite(waterPump,HIGH); // begin watering
    delay(3000); // water for 3 sec
    digitalWrite(waterPump,LOW); // turn off pump
  }

  

}
