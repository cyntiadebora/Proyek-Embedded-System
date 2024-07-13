#include <Wire.h> // Library untuk komunikasi I2C
#include <LiquidCrystal_I2C.h> // Library untuk mengendalikan LCD I2C

// Deklarasi pin
int buzzer = A0; // Pin untuk buzzer
int sensor_getar = 9; // Pin untuk sensor getar
int led_h = 10; // Pin untuk LED hijau
int led_k = 11; // Pin untuk LED kuning
int led_m = 12; // Pin untuk LED merah

// Inisialisasi LCD dengan alamat I2C 0x27, lebar 16 karakter, dan tinggi 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Konfigurasi pin
  pinMode(sensor_getar, INPUT); // Sensor getar sebagai input
  pinMode(buzzer, OUTPUT); // Buzzer sebagai output
  pinMode(led_h, OUTPUT); // LED hijau sebagai output
  pinMode(led_k, OUTPUT); // LED kuning sebagai output
  pinMode(led_m, OUTPUT); // LED merah sebagai output

  // Inisialisasi komunikasi serial dengan baud rate 9600
  Serial.begin(9600);

  // Inisialisasi LCD
  lcd.begin(); // Memulai LCD
  lcd.backlight(); // Menyalakan lampu latar LCD
  lcd.setCursor(0, 0); // Mengatur kursor ke baris pertama
  lcd.print("Alat Pendeteksi"); // Menampilkan pesan di baris pertama
  lcd.setCursor(0, 1); // Mengatur kursor ke baris kedua
  lcd.print("Gempa"); // Menampilkan pesan di baris kedua
}

void loop() {
  // Membaca nilai dari sensor getar
  int getar_value = pulseIn(sensor_getar, HIGH);

  // Menampilkan nilai sensor pada serial monitor
  Serial.println(getar_value);

  if (getar_value > 1000) {
    // Jika getar_value lebih dari 1000, berarti ada gempa besar
    for (int i = 0; i < 5; i++) {
      analogWrite(buzzer, 255); // Buzzer menyala penuh
      lcd.clear(); // Membersihkan layar LCD
      lcd.setCursor(0, 0); // Mengatur kursor ke baris pertama
      lcd.print("Bahaya ada gempa!"); // Menampilkan pesan bahaya gempa
      lcd.setCursor(0, 1); // Mengatur kursor ke baris kedua
      lcd.print("Segera keluar"); // Menampilkan pesan segera keluar
      digitalWrite(led_m, HIGH); // LED merah menyala
      digitalWrite(led_k, LOW); // LED kuning mati
      digitalWrite(led_h, LOW); // LED hijau mati
      delay(300); // Jeda selama 300 ms
      analogWrite(buzzer, 0); // Buzzer mati
      delay(300); // Jeda selama 300 ms
    }
  } else if (getar_value >= 100 && getar_value < 1000) {
    // Jika getar_value antara 100 dan 1000, berarti ada getaran sedang
    analogWrite(buzzer, 150); // Buzzer menyala dengan intensitas sedang
    lcd.clear(); // Membersihkan layar LCD
    lcd.setCursor(0, 0); // Mengatur kursor ke baris pertama
    lcd.print("Status: Hati-hati"); // Menampilkan pesan status hati-hati
    lcd.setCursor(0, 1); // Mengatur kursor ke baris kedua
    lcd.print("Terdeteksi Getaran"); // Menampilkan pesan terdeteksi getaran
    digitalWrite(led_m, LOW); // LED merah mati
    digitalWrite(led_k, HIGH); // LED kuning menyala
    digitalWrite(led_h, LOW); // LED hijau mati
    delay(500); // Jeda selama 500 ms
    analogWrite(buzzer, 0); // Buzzer mati
    delay(500); // Jeda selama 500 ms
  } else {
    // Jika getar_value kurang dari 100, berarti kondisi aman
    analogWrite(buzzer, 0); // Buzzer mati
    lcd.clear(); // Membersihkan layar LCD
    lcd.setCursor(0, 0); // Mengatur kursor ke baris pertama
    lcd.print("Status: Aman"); // Menampilkan pesan status aman
    lcd.setCursor(0, 1); // Mengatur kursor ke baris kedua
    lcd.print("Hari Baik :)"); // Menampilkan pesan hari baik
    digitalWrite(led_m, LOW); // LED merah mati
    digitalWrite(led_k, LOW); // LED kuning mati
    digitalWrite(led_h, HIGH); // LED hijau menyala
    delay(500); // Jeda selama 500 ms
  }

  // Jeda untuk mengurangi frekuensi pembacaan sensor
  delay(100);
}
