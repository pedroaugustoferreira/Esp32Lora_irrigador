void setup() {
  Serial.begin(115200); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  int val;
  val = analogRead(36); //connect sensor to Analog 0
  Serial.println(val); //print the value to serial port
  delay(1000);
}