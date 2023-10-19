
#define TMP36_INPUT 0  // A0
#define CDS_INPUT 1    // A1

void setup() { 
  Serial.begin(9600);
}

void loop(){
  int temp_value = analogRead(TMP36_INPUT);
  float voltage = temp_value * 5.0 * 1000; 
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ; 

  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));  

  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
  delay(1000);
}

double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  
  double lux=(2500/Vout-500)/10;  
  return lux;
}
