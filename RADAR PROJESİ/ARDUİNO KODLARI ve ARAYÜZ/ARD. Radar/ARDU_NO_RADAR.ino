const int Trigger=7; //Sensörü bağladığımız pinleri belirtir.
const int echo=6;
float sure;  // değişkenler tanımlanır. Mesafenin küsüratını merak ettiğim için float cinsinden tanımlıdır.
float mesafe;


void setup() {

 pinMode(Trigger,OUTPUT); //Triggerdan ses dalgaları çıkış sağladığı için.
 pinMode(echo, INPUT);    // Gelen ses dalgalarını algıladığı(giriş) ve bilgi verdiği için.  
 Serial.begin(9600); // seri port ekranını başlatmak için kullanılır.
 

}

void loop() {
  digitalWrite(Trigger, HIGH); // Trigger pinine güç vererek engel olup olmadığına bakılır. Bu yüzden güç gönderilir.
  delayMicroseconds(1000);    // Devamlı güç göndermemesi ve mesafe aralıklarının düzenli olması için zaman belirtilir.
  digitalWrite(Trigger, LOW);  // pine giren güç kesilir.
  sure= pulseIn(echo, HIGH);  // komut belirtilen pini takibe alır. Echo pin YÜKSEK durumdan alçağa geçene kadar süreye bakıp değişkene aktarılmasını sağlar. 
  mesafe= (sure/2)/28.7;     // süre yardımıyla mesafenin hesaplanma işlemini yapar.

  Serial.print("mesafe:"); // seri ekrana yazdırılma işlemini yapar.
  Serial.print(mesafe); // değişkeni yazar.
  Serial.println("cm");
  delay(500); // bekletme fonksiyonudur.
}
