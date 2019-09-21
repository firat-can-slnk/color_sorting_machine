byte color = 5;
byte sensor = 3;

void setup() {
  pinMode(color, OUTPUT);
  pinMode(sensor, OUTPUT);
  Serial.begin(9600);
  digitalWrite(color, HIGH);

}

void loop() {
  Serial.println(analogRead(sensor));
}
