#define gasSensor A0
#define tempSensor A1
#define buzzer 4
#define led 5

int gasThreshold = 300;    
int tempThreshold = 50;    

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);   
}

void loop() {
  int gasValue = analogRead(gasSensor);
  int tempValue = analogRead(tempSensor);
  float voltage = tempValue * (5000.0 / 1024.0); 
  float temperature = voltage / 10; 


  Serial.print("Gas: "); Serial.print(gasValue);
  Serial.print(" | Temp: "); Serial.println(temperature);

  if (gasValue > gasThreshold || temperature > tempThreshold) {
    digitalWrite(buzzer, HIGH);  
    digitalWrite(led, HIGH);     
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  } else {
    digitalWrite(buzzer, LOW);   
    digitalWrite(led, LOW);      // LED off
  }
  delay(1000);
}
