#include <iostream>
using namespace std;

int main() {
    string kode;
    int jamKeluar;

    cout << "Masukkan kode parkir (10 digit): ";
    cin >> kode;
    cout << "Masukkan jam keluar (Format HHMM): ";
    cin >> jamKeluar;

    // Ambil jenis kendaraan
    string jenisKode = kode.substr(0,2);
    string jenis;
    int tarifAwal = 0, tarifLanjut = 0;

    if (jenisKode == "10") {
        jenis = "Mobil pribadi";
        tarifAwal = 5000;
        tarifLanjut = 3000;
    } else if (jenisKode == "20") {
        jenis = "Motor";
        tarifAwal = 3000;
        tarifLanjut = 2000;
    } else if (jenisKode == "30") {
        jenis = "Bus";
        tarifAwal = 10000;
        tarifLanjut = 7000;
    } else {
        jenis = "Tidak diketahui";
    }

    // Ambil waktu masuk
    int jamMasuk = stoi(kode.substr(2,2));
    int menitMasuk = stoi(kode.substr(4,2));

    int jamK = jamKeluar / 100;
    int menitK = jamKeluar % 100;

    // Hitung total menit
    int totalMasuk = jamMasuk * 60 + menitMasuk;
    int totalKeluar = jamK * 60 + menitK;

    int selisihMenit = totalKeluar - totalMasuk;
    int jamParkir = selisihMenit / 60;
    if (selisihMenit % 60 != 0) {
        jamParkir++; // dibulatkan ke atas
    }

    // Hitung biaya
    int totalBiaya = 0;
    if (jamParkir > 0) {
        totalBiaya = tarifAwal;
        if (jamParkir > 1) {
            totalBiaya += (jamParkir - 1) * tarifLanjut;
        }
    }

    // Ambil lokasi
    string lokasi = kode.substr(6,4);

    // Output
    cout << "\n=== Informasi Parkir ===" << endl;
    cout << "Jenis Kendaraan : " << jenis << endl;
    cout << "Waktu Masuk     : " << jamMasuk << ":" << menitMasuk << endl;
    cout << "Waktu Keluar    : " << jamK << ":" << menitK << endl;
    cout << "Lama Parkir     : " << jamParkir << " jam" << endl;
    cout << "Lokasi Parkir   : " << lokasi << endl;
    cout << "Total Biaya     : Rp " << totalBiaya << endl;

    return 0;
}

/*
ALGORITMA / LOGIKA PROGRAM:

1. Program meminta input:
   - Kode parkir (10 digit)
   - Jam keluar dalam format HHMM

2. Mengambil 2 digit pertama dari kode untuk menentukan jenis kendaraan:
   - "10" → Mobil pribadi
   - "20" → Motor
   - "30" → Bus
   Setiap jenis memiliki tarif awal dan tarif lanjutan per jam.

3. Mengambil waktu masuk dari kode:
   - Digit ke-3 dan ke-4 → jam masuk
   - Digit ke-5 dan ke-6 → menit masuk

4. Memisahkan jam keluar menjadi:
   - Jam (HH)
   - Menit (MM)

5. Menghitung total waktu dalam menit:
   - TotalMasuk = jamMasuk × 60 + menitMasuk
   - TotalKeluar = jamKeluar × 60 + menitKeluar

6. Menghitung selisih waktu parkir dalam menit, lalu dikonversi ke jam:
   - Jika ada sisa menit, dibulatkan ke atas menjadi 1 jam tambahan

7. Menghitung biaya parkir:
   - Jam pertama menggunakan tarif awal
   - Jam berikutnya menggunakan tarif lanjutan

8. Mengambil 4 digit terakhir dari kode sebagai lokasi parkir

9. Menampilkan:
   - Jenis kendaraan
   - Waktu masuk dan keluar
   - Lama parkir
   - Lokasi parkir
   - Total biaya
*/


