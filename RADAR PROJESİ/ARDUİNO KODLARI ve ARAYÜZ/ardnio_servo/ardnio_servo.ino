#include <Servo.h>// kütüphane dahil edilir.
 Servo sg90; // nesne türetilir.
 int ps=0;  //pozisyon tanımlanır.
void setup() {
  sg90.attach(5); // servo motorun hangi pinde takılı olduğunu söyleyen komut kullanılır.
}

void loop() {
  for(ps=15; ps<=165; ps++) // döngü aracılığıyla motorun dönme aralığı belirlenir.
  {
    sg90.write(ps);
    delay(15);
  }
  for(ps=165; ps>15; ps--)
  {
    sg90.write(ps);
    delay(15);
  }
}
