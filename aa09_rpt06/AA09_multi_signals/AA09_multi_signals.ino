/*
  Multi Signals
  Simulation of multiple random signals  
*/
// signals: humi, temp, lux
int temp=0; //온도
int humi=0; //습도
int lux=0; //조도


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // Multi signals
temp = random(-10,30);
humi = random(40,90);
lux = random(150,250);  
  //Serial.print("AA09, Ambient lux: ");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(humi);
  Serial.print(",");
  Serial.println(lux);
  //Serial.print(" , Humidity: ");
  //Serial.print(" , Temperature: ");
  delay(1000);        // delay in between reads for stability
}
