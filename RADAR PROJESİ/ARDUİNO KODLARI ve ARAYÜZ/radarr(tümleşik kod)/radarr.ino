#include <Servo.h>// kütüphane dahil edilir.
const int Trigger=7;
const int echo=6;
float sure;
float mesafe;
int ps=0;
 Servo sg90; // nesne türetilir.
   
void setup() {
  pinMode(Trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  sg90.attach(5); // servo motorun hangi pinde takılı olduğunu söyleyen komut kullanılır.
}

void loop() {
  for(ps=15; ps<=165; ps++) // döngü aracılığıyla motorun dönme aralığı belirlenir.
  {
    sg90.write(ps);
    delay(15);
    mesafe= hesaplamesafe();
    Serial.print(ps);
    Serial.print("Mesafe:");
    Serial.print(mesafe);
    Serial.println("cm");
  }
  for(ps=165; ps>15; ps--)
  {
    sg90.write(ps);
    delay(15);
    mesafe= hesaplamesafe();
    Serial.print(ps);
    Serial.print("Mesafe:");
    Serial.print(mesafe);
    Serial.println("cm");
  }
}
 float hesaplamesafe(){
  digitalWrite(Trigger, HIGH); // Trigger pinine güç vererek engel olup olmadığına bakılır. Bu yüzden güç gönderilir.
  delayMicroseconds(1000);    // Devamlı güç göndermemesi ve mesafe aralıklarının düzenli olması için zaman belirtilir.
  digitalWrite(Trigger, LOW);  // pine giren güç kesilir.
  sure= pulseIn(echo, HIGH);  // komut belirtilen pini takibe alır. Echo pin YÜKSEK durumdan alçağa geçene kadar süreye bakıp değişkene aktarılmasını sağlar. 
  mesafe= (sure/2)/28.7;     // süre yardımıyla mesafenin hesaplanma işlemini yapar.
 }
