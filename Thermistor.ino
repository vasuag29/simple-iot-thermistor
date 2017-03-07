#define SeriesR 10000
#define ThermPin A0

int relay=8;


void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
pinMode(relay,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
float reading;
reading= analogRead(ThermPin);
Serial.println("\n\nXXXX NEW READING XXXX\nAnalog Reading :  ");
Serial.println(reading);
reading=(1023/reading)-1;
reading=SeriesR/reading;
Serial.print("Thermistor Resistance :  ");
Serial.println(reading);

float steinhart;
steinhart=reading/10000;
steinhart=log(steinhart);
steinhart/=3950;
steinhart+=1.0/(25+273.15);
steinhart=1.0/steinhart;
steinhart-=273.15;
steinhart+=41;
if(steinhart>40)
{
digitalWrite(relay,HIGH);
}
else
{
digitalWrite(relay,LOW);
delay(1000);
}


Serial.print("Temperature ");
Serial.print(steinhart);
Serial.print(" *C");
delay(1000);
}
