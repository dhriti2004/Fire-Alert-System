#define gasSensor A0
#define tempSensor A1
#define buzzer 4
#define led 5

int gasThreshold = 300;    // Adjust as needed
int tempThreshold = 51;    // Celsius for LM35

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);    // LED off by default
}

void loop() {
  int gasValue = analogRead(gasSensor);
  int tempValue = analogRead(tempSensor);
  float voltage = tempValue * (5000.0 / 1024.0); // in millivolts
  float temperature = voltage / 10; // 10mV per °C


  Serial.print("Gas: "); Serial.print(gasValue);
  Serial.print(" | Temp: "); Serial.println(temperature);

  if (gasValue > gasThreshold || temperature > tempThreshold) {
    digitalWrite(buzzer, HIGH);  // Buzzer on
    digitalWrite(led, HIGH);     // LED on
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  } else {
    digitalWrite(buzzer, LOW);   // Buzzer off
    digitalWrite(led, LOW);      // LED off
  }
  delay(1000);
}
