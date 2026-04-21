#include <iostream>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    if (kode.length() != 8) {
        cout << "Kode tidak valid!" << endl;
        return 0;
    }

    // Ambil bagian kode
    string kodeHari = kode.substr(0,2);
    string kodeMember = kode.substr(2,2);
    int belanja = stoi(kode.substr(4,4)); // dalam kelipatan 100rb

    string hari, member;
    int poinPer100 = 0;

    // Tentukan jenis hari
    if (kodeHari == "01") hari = "Hari kerja";
    else if (kodeHari == "02") hari = "Akhir pekan";
    else if (kodeHari == "03") hari = "Hari libur nasional";
    else {
        cout << "Kode tidak valid!" << endl;
        return 0;
    }

    // Tentukan jenis member
    if (kodeMember == "01") member = "Biasa";
    else if (kodeMember == "02") member = "Silver";
    else if (kodeMember == "03") member = "Gold";
    else {
        cout << "Kode tidak valid!" << endl;
        return 0;
    }

    // Tentukan poin
    if (kodeHari == "01") {
        if (kodeMember == "01") poinPer100 = 1;
        else if (kodeMember == "02") poinPer100 = 2;
        else if (kodeMember == "03") poinPer100 = 3;
    } else if (kodeHari == "02") {
        if (kodeMember == "01") poinPer100 = 2;
        else if (kodeMember == "02") poinPer100 = 3;
        else if (kodeMember == "03") poinPer100 = 5;
    } else if (kodeHari == "03") {
        if (kodeMember == "01") poinPer100 = 3;
        else if (kodeMember == "02") poinPer100 = 5;
        else if (kodeMember == "03") poinPer100 = 7;
    }

    // Hitung total
    int totalBelanja = belanja * 100000;
    int totalPoin = belanja * poinPer100;

    // Output
    cout << "\n=== Hasil Transaksi ===" << endl;
    cout << "Jenis Hari      : " << hari << endl;
    cout << "Jenis Pelanggan : " << member << endl;
    cout << "Jumlah Belanja  : Rp " << totalBelanja << endl;
    cout << "Total Poin      : " << totalPoin << endl;

    return 0;
}

/*
ALGORITMA / LOGIKA PROGRAM:

1. Program meminta input kode transaksi sebanyak 8 digit.
2. Jika panjang kode tidak sama dengan 8 digit, program berhenti dan menampilkan "Kode tidak valid".

3. Memecah kode menjadi beberapa bagian:
   - 2 digit pertama → kode hari
   - 2 digit berikutnya → kode member
   - 4 digit terakhir → jumlah belanja (dalam kelipatan 100.000)

4. Menentukan jenis hari berdasarkan kode:
   - "01" → Hari kerja
   - "02" → Akhir pekan
   - "03" → Hari libur nasional
   Jika tidak sesuai, program dihentikan.

5. Menentukan jenis pelanggan:
   - "01" → Biasa
   - "02" → Silver
   - "03" → Gold
   Jika tidak sesuai, program dihentikan.

6. Menentukan poin per 100.000 berdasarkan kombinasi hari dan jenis member:
   - Hari kerja → poin lebih kecil
   - Akhir pekan → poin sedang
   - Hari libur → poin terbesar

7. Menghitung:
   - Total belanja = nilai belanja × 100.000
   - Total poin = nilai belanja × poin per 100.000

8. Menampilkan hasil:
   - Jenis hari
   - Jenis pelanggan
   - Total belanja
   - Total poin yang didapat
*/