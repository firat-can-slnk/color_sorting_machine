/* Author: Niklas Kamm, Julian Krieger, Pascal Gläß
 * License: See github.com/KriegersBlog/color_sorting_machine
 * 
 * This code is optimized to work on a Arduino Uno R3 to manage
 * the whole color sorting process. For more information: See documentation
 */

const int motor[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110};
const int motor1_pins[4] = { hier l1,l2,l3,l4 eintragen};
const int motor2_pins[4] = { hier l1,l2,l3,l4 eintragen};



void setup() {

}

void loop() {

}




int color_recognition(){
  1. ROT SENDEN
  2. Wert auslesen
  3. GRÜN SENDEN
  4. Wert auslesen
  5. BLAU SENDEN
  6. Wert auslesen
  7. Wenn ROT im Bereich A-B, BLAU im Bereich C-D und GRÜN im Bereich E-F
    dann:
    (Rot 1, Blau 0, grün 0) Rote Kugel -> gibt positionswert zurück
}




void motorcontrol(_motor, _position){
  
  if(_motor == "M1"){
    for(int i = 0; i<4; i++)
      motorpins[i] = motor1_pins[i];
  }
  else if(_motor == "M2"){
    for(int i = 0; i<4; i++)
      motorpins[i] = motor2_pins[i];
  }
  
  for(int i = 0; i < _position; i++)
    for(int x = 0; x < 4; x++){
      digitalWrite(M2[0], motor[x] & 0b00000001);
      digitalWrite(M2[1], motor[x] & 0b00000010);
      digitalWrite(M2[2], motor[x] & 0b00000100);
      digitalWrite(M2[3], motor[x] & 0b00001000);
      }
}
