# Proyek-Embedded-System
Sistem untuk mendeteksi getaran gempa bumi

### * Komponen-komponen yang digunakan
1. Arduino Mega sebagai mikrokontroller
2. Sensor Vibration sebagai pendeteksi getaran gempa
3. LCD I2C untuk menampilkan informasi realtime kepada pengguna
4. LED yang terdiri dari warna merah, kuning, dan hijau sebagai penanda kondisi secara realtime
5. Buzzer untuk memberi peringatan bahaya dengan menghasilkan suara
6. Kabel Fiber Optik untuk menghubungkan semua komponen


### * Berikut adalah sketsa dari rangkaian yang dibuat menggunakan aplikasi Fritzing

![Sketsa Rangkaian](https://raw.githubusercontent.com/cyntiadebora/Proyek-Embedded-System/2aa27c3bd156ee8f1234eb72a1b92c1786a2c64d/Picture1.png)


### * Berikut adalah implementasi dari komponen-komponen hardware tanpa menggunakan case

![Rangkaian Tanpa Case](https://github.com/cyntiadebora/Proyek-Embedded-System/blob/main/Picture2.png?raw=true)


### * Berikut adalah alat setelah menggunakan case

![Case Sistem](https://raw.githubusercontent.com/cyntiadebora/Proyek-Embedded-System/cfae2f9d310caf8f84340595970bf90ed8aac3cf/Picture3.png)


### * LED Hijau akan selalu menyala selama sistem tidak mendeteksi adanya getaran gempa

![LED Hijau](https://github.com/cyntiadebora/Proyek-Embedded-System/blob/main/Picture4.png?raw=true)


### * LED Kuning akan menyala untuk memberikan peringatan dini ketika terdeteksi getaran gempa namun tidak terlalu kuat 

![LED Kuning](https://github.com/cyntiadebora/Proyek-Embedded-System/blob/main/Picture5.png?raw=true)


### * LED Merah akan menyala ketika getaran gempa terdeteksi kuat yang artinya sudah ada bahaya

![LED Merah](https://github.com/cyntiadebora/Proyek-Embedded-System/blob/main/Picture6.png?raw=true)


