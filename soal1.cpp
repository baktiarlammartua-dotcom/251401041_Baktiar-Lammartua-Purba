#include <iostream>
using namespace std;

int main() {
    string kartu;
    cout << "Masukkan nomor kartu: ";
    cin >> kartu;

    int panjang = kartu.length();
    string jenis = "Tidak diketahui";

    // Cek jenis kartu
    if (panjang == 14 && kartu.substr(0,2) == "65") {
        jenis = "NUSANTARA";
    } else if (panjang == 16 && (kartu.substr(0,2) == "77" || kartu.substr(0,2) == "78")) {
        jenis = "GARUDA";
    } else if (panjang == 15 && kartu.substr(0,2) == "91") {
        jenis = "MERDEKA";
    }

    // Validasi dengan algoritma
    int total = 0;
    bool kali2 = true;

    for (int i = panjang - 2; i >= 0; i--) {
        int digit = kartu[i] - '0';

        if (kali2) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total += digit;
        kali2 = !kali2;
    }

    // Tambah digit terakhir
    total += kartu[panjang - 1] - '0';

    // Output hasil
    cout << "Tipe Kartu: " << jenis << endl;

    if (jenis != "Tidak diketahui" && total % 10 == 0) {
        cout << "Nomor Kartu VALID." << endl;
    } else {
        cout << "Nomor Kartu TIDAK VALID." << endl;
    }

    return 0;
}

/*
ALGORITMA / LOGIKA PROGRAM:

1. Program meminta pengguna memasukkan nomor kartu dalam bentuk string.
2. Menghitung panjang nomor kartu untuk membantu identifikasi jenis kartu.
3. Menentukan jenis kartu berdasarkan:
   * Panjang kartu
   * Dua digit awal kartu
   Jika tidak memenuhi syarat, maka jenis = "Tidak diketahui".

4. Melakukan validasi nomor kartu menggunakan metode mirip algoritma Luhn:
   a. Mulai dari digit kedua terakhir hingga digit pertama.
   b. Setiap digit dikalikan 2 secara bergantian.
   c. Jika hasil perkalian lebih dari 9, jumlahkan digitnya.
   d. Tambahkan semua hasil ke dalam variabel total.

5. Tambahkan digit terakhir kartu ke total.

6. Cek validitas:
   * Jika jenis kartu dikenali DAN total habis dibagi 10 --> VALID
   * Selain itu --> TIDAK VALID

7. Tampilkan jenis kartu dan status validitas ke layar.
*/
