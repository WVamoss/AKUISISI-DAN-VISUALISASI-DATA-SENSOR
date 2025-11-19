
# Akuisisi dan Visualisasi Data Sensor

Proyek ini bertujuan untuk mengumpulkan data dari berbagai jenis sensor menggunakan **Arduino** dan kemudian memvisualisasikan data tersebut di komputer. Dengan menggunakan perangkat keras seperti Arduino dan berbagai sensor, proyek ini memungkinkan pengguna untuk memperoleh data sensor secara real-time dan menampilkan hasilnya dalam bentuk visual yang mudah dipahami.

## Fitur Utama

- **Akuisisi Data Sensor dengan Arduino**: Mengumpulkan data dari berbagai sensor, seperti sensor suhu, kelembapan, dan sensor lainnya, menggunakan platform Arduino.
- **Visualisasi Data**: Menampilkan data yang dikumpulkan dalam bentuk grafik dan chart di komputer untuk memudahkan analisis.
- **Pemrosesan Data Real-Time**: Data yang dikumpulkan dari sensor diproses secara langsung dan dapat dilihat hasilnya secara seketika.
- **Kemudahan Pengaturan**: Pengguna dapat dengan mudah mengonfigurasi dan menambah sensor baru pada Arduino sesuai kebutuhan.

## Persyaratan Sistem

### Perangkat Keras:
- **Arduino Board** (misalnya Arduino Uno, Mega, atau lainnya).
- **Sensor** yang terhubung ke Arduino, seperti:
  - Sensor suhu (contoh: DHT11, DHT22)
  - Sensor kelembapan
  - Sensor lainnya sesuai dengan kebutuhan proyek.

### Perangkat Lunak:
- **Arduino IDE** untuk menulis dan mengunggah kode ke board Arduino.
- **Python 3.x** di komputer untuk pemrosesan dan visualisasi data.
- **Pustaka Python yang dibutuhkan**:
  - `numpy`
  - `matplotlib`
  - `pandas`
  - `pyserial` (untuk komunikasi serial antara Arduino dan komputer)

### Instalasi Dependensi Python:

Untuk menginstal pustaka yang dibutuhkan, jalankan perintah berikut di terminal:

```bash
pip install -r requirements.txt
````

## Cara Instalasi

### 1. Siapkan Arduino dan Sensor

* Hubungkan sensor ke board Arduino Anda sesuai dengan skema yang ada.
* Pastikan board Arduino terhubung dengan komputer menggunakan kabel USB.

### 2. Clone Repositori Proyek

Clone repositori ini ke dalam direktori lokal Anda:

```bash
git clone https://github.com/WVamoss/AKUISISI-DAN-VISUALISASI-DATA-SENSOR.git
```

### 3. Program Arduino

1. Masuk ke folder proyek dan buka file **`arduino_code.ino`** di **Arduino IDE**.
2. Upload kode ke board Arduino Anda.
3. Pastikan komunikasi serial terhubung dengan baik agar data dapat diterima oleh komputer.

### 4. Instalasi Dependensi Python

Pindah ke folder proyek dan instal pustaka Python yang diperlukan:

```bash
pip install -r requirements.txt
```

## Cara Penggunaan

### 1. Mengumpulkan Data dari Sensor

1. Pastikan board Arduino terhubung dengan komputer.
2. Jalankan program Python untuk mulai menerima data dari Arduino:

```bash
python collect_data.py
```

Skrip ini akan membaca data dari port serial yang terhubung dengan Arduino dan menyimpannya.

### 2. Visualisasi Data

Setelah data terkumpul, Anda dapat memvisualisasikan data yang diperoleh dengan menjalankan skrip visualisasi:

```bash
python visualize_data.py
```

Skrip ini akan menghasilkan grafik dan chart berdasarkan data yang terkumpul dari sensor.

## Contoh Visualisasi

Proyek ini mendukung beberapa jenis visualisasi, di antaranya:

* **Grafik Waktu-Seri**: Menampilkan perubahan data sensor dari waktu ke waktu.
* **Heatmap**: Menampilkan data berbasis lokasi atau parameter tertentu.
* **Histogram**: Menunjukkan distribusi data yang dikumpulkan.

