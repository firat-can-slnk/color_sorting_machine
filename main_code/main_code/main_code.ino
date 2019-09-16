/* Author: Niklas Kamm, Julian Krieger, Pascal Gläß
 * License: See github.com/KriegersBlog/color_sorting_machine
 * 
 * This code is optimized to work on a Arduino Uno R3 to manage
 * the whole color sorting process. For more information: See documentation
 */

const int motor[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110};
const int min_values[3] = {1,2,3}; // Minimalster Wert, um als Farbe erkannt zu werden
int color_values[3]; // Gemessene Werte
int color_steps[4] = {1,2,3,4}; // Schritte Rot, Gruen, Blau, Gold

// PIN BELEGUNGEN
const byte motor1_pins[4] = {7, 5, 8, 6}; // PINS ÜBERPRÜFEN (Wegen Kabeltausch)
const byte motor2_pins[4] = {11, 9, 12, 10}; // PINS ÜBERPRÜFEN (Wegen Kabeltausch)
byte motorpins[4];

const byte leds[3] = {4,3,2}; // Red, Green, Blue

const byte light_barrier1 = A1; // upper light barrier
const byte light_barrier2 = A0; // lower light barrier
const byte color_sensor = A2; // sensor for color recognition



void setup() {

}

void loop() {

}




int color_recognition(){
  
  for(int i = 0; i<3; i++){
    digitalWrite(leds[i], HIGH);
    delay(500);
    color_values[i] = analogRead(color_sensor);
    delay(500);
    digitalWrite(leds[i], LOW);
  }

  // If color red gets recognized
  if(color_values[0] >= min_values[0] || color_values[1] < min_values[1] || color_values[2] < min_values[2]){
    return color_steps[0];
  }
  // If color green gets recognized
  else if(color_values[0] < min_values[0] || color_values[1] >= min_values[1] || color_values[2] < min_values[2]){
    return color_steps[1];
  }
  // If color blue gets recognized
  else if(color_values[0] < min_values[0] || color_values[1] < min_values[1] || color_values[2] >= min_values[2]){
    return color_steps[2];
  }
  // If all colors are recognized
  else if(color_values[0] >= min_values[0] || color_values[1] >= min_values[1] || color_values[2] >= min_values[2]){
    return color_steps[2];
  }
  // If no color gets recognized (maybe error)
  else return 0;
}


void motorcontrol(String _motor, int _position){
  
  if(_motor == "M1"){
    for(int i = 0; i<4; i++)
      motorpins[i] = motor1_pins[i];
  }
  else if(_motor == "M2"){
    for(int i = 0; i<4; i++)
      motorpins[i] = motor2_pins[i];
  }
  
  for(int i = 0; i < _position; i++){
    for(int x = 0; x < 4; x++){
      digitalWrite(motorpins[0], motor[x] & 0b00000001);
      digitalWrite(motorpins[1], motor[x] & 0b00000010);
      digitalWrite(motorpins[2], motor[x] & 0b00000100);
      digitalWrite(motorpins[3], motor[x] & 0b00001000);
      }
      delay(2);
  }
}
