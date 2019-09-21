const byte motorpins[4] = {11, 9, 12, 10};
const int motor[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110};
void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);}

void loop() {
  // put your main code here, to run repeatedly:
  
for(int i = 0; i < 6300; i++){
    for(int x = 0; x < 4; x++){
      digitalWrite(motorpins[0], motor[x] & 0b00000001);
      digitalWrite(motorpins[1], motor[x] & 0b00000010);
      digitalWrite(motorpins[2], motor[x] & 0b00000100);
      digitalWrite(motorpins[3], motor[x] & 0b00001000);
      delay(2);
      }
      
  }
}
