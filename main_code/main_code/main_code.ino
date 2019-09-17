/* Author: Niklas Kamm, Julian Krieger, Pascal Gläß
 * License: See github.com/KriegersBlog/color_sorting_machine
 *                                                                                      // LICHTSCHRANKE M2 wird gebraucht (schritte)
 * This code is optimized to work on a Arduino Uno R3 to manage
 * the whole color sorting process. For more information: See documentation
 */
// CONSTANT VARIABLES

const int motor[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110}; // Dreht Motor im Uhrzeigersinn

// positions
const int position_start = -10;
const int position_color_recognition = 1; // HIER STEPS EINFÜGEN

// colors
const int min_values[3] = {1,2,3}; // Minimalster Wert, um als Farbe erkannt zu werden
const int color_steps[4] = {1,2,3,4}; // Schritte Rot, Gruen, Blau, Gold im Uhrzeigersinn

// pins
const byte motor1_pins[4] = {7, 5, 8, 6}; // IN3, IN1, IN4, IN2
const byte motor2_pins[4] = {11, 9, 12, 10}; // L1, L2, L3, L4
byte motorpins[4];
const byte leds[3] = {4,3,2}; // Red, Green, Blue
const byte light_barrier1 = A1; // upper light barrier
const byte light_barrier2 = A0; // lower light barrier
const byte color_sensor = A2; // sensor for color recognition

//UNCONSTANT VARIABLES

int active_light_barrier;   // value: cached pin of the active light_barrier (dependent on active motor)
int position_color;  // value: cached steps for the determined color
int color_values[3]; // value: cached input of A2


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  for(int i = 2; i < 13; i++)
    pinMode(i, OUTPUT);
}

void loop() { // M2 zu position_start -> Beachten: Kugel kann durchfallen, vielleicht muss man extra andere Methode machen (ggn. UZS)
  motorcontrol(M1, position_start);
  delay(500); // Zeit damit die Kugel reinfallen kann
  motorcontrol(M1, position_color_recognition); 
  position_color = color_recognition(); // mit position_start wird die variable überflüssig 
  motorcontrol(M2, position_color);
  motorcontrol(M1, position_start); // Muss nicht Farbe sein, da wir vorbei fahren können
  delay(500); // Kugel rausfallen lassen
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
      light_barrier = light_barrier2;
  }
  else if(_motor == "M2"){
    for(int i = 0; i<4; i++)
      motorpins[i] = motor2_pins[i];
      active_light_barrier = light_barrier2;
  }

  if(_position == -10)
    while(analogRead(active_light_barrier) <= 1){        // HIER WERT FINDEN, LICHTSCHRANKE
      move_motor();
    }
  else
  for(int i = 0; i < _position; i++){
    move_motor();
  }
}

void move_motor(){
  for(int x = 0; x < 4; x++){
      digitalWrite(motorpins[0], motor[x] & 0b00000001);
      digitalWrite(motorpins[1], motor[x] & 0b00000010);
      digitalWrite(motorpins[2], motor[x] & 0b00000100);
      digitalWrite(motorpins[3], motor[x] & 0b00001000);
      delay(2);
      }
}
