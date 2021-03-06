

int Led = A5; 
int Sensor = A4;
int hbridge_in1 = 6;
int hbridge_in2 = 5;

int V = 0;
int VN = 0;
int VMin = 1023;
int VMax = 0;

void setup() {
  
   
  pinMode(Led, OUTPUT);
  pinMode(Sensor, INPUT);
  pinMode(hbridge_in1,OUTPUT);
  pinMode(hbridge_in2,OUTPUT);
  
  digitalWrite(Led, HIGH);
  
  while (millis() <5000) {
    V = analogRead(Sensor);
  
  if (V > VMax) {
      VMax = V;
    } 
    
  if (V < VMin) {
      VMin = V;
    }
  }
  
  digitalWrite(Led, LOW);

    
  Serial.begin(9600); 

}

void loop() {
  V = analogRead(Sensor);
  
VN = map(V, VMin, VMax, 0, 255);
VN = constrain (VN, 0, 255);

 analogWrite(hbridge_in1,VN);
 analogWrite(hbridge_in2,0);
 
   
  Serial.print(V);
  Serial.print(" --> ");
  Serial.println(VN);
  delay(250);
}
