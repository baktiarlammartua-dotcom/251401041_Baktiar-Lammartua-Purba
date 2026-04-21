#include <iostream>
using namespace std;

int main() {
    string kartu;
    cout << "Masukkan nomor kartu: ";
    cin >> kartu;

    int panjang = kartu.length();
    string jenis = "Tidak diketahui";

    if (panjang == 14 && kartu.substr(0,2) == "65") {
        jenis = "NUSANTARA";
    } 
    else if (panjang == 16 && (kartu.substr(0,2) == "77" || kartu.substr(0,2) == "78")) {
        jenis = "GARUDA";
    } 
    else if (panjang == 15 && kartu.substr(0,2) == "91") {
        jenis = "MERDEKA";
    }

    // Validasi algoritma
    int total_kali2 = 0;
    int total_biasa = 0;
    bool kali2 = true;

    // Mulai dari digit ke-2 dari belakang
    for (int i = panjang - 2; i >= 0; i--) {
        int digit = kartu[i] - '0';

        if (kali2) {
            digit *= 2;

            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }

            total_kali2 += digit;
        } 
        else {
            total_biasa += digit;
        }

        kali2 = !kali2;
    }

    // Tambahkan digit terakhir
    total_biasa += kartu[panjang - 1] - '0';

    // Total akhir
    int total = total_kali2 + total_biasa;

    //  Output
    cout << "Tipe Kartu: " << jenis << endl;

    if (jenis != "Tidak diketahui" && total % 10 == 0) {
        cout << "Nomor Kartu VALID" << endl;
    } else {
        cout << "Nomor Kartu TIDAK VALID" << endl;
    }

    return 0;
}

/*
ALGORITMA / LOGIKA PROGRAM:

1. Mulai program.
2. Input nomor kartu dalam bentuk string.
3. Hitung panjang nomor kartu.

4. Tentukan jenis kartu:
   - Jika panjang 14 dan diawali 65 → NUSANTARA
   - Jika panjang 16 dan diawali 77 atau 78 → GARUDA
   - Jika panjang 15 dan diawali 91 → MERDEKA
   - Selain itu → Tidak diketahui

5. Inisialisasi:
   - total_kali2 = 0 (untuk digit yang dikali 2)
   - total_biasa = 0 (untuk digit yang tidak dikali)
   - kali2 = true (penanda selang-seling)

6. Lakukan perulangan dari digit ke-2 dari belakang hingga awal:
   a. Ambil satu digit.
   b. Jika posisi dikali 2:
      - Kalikan digit dengan 2.
      - Jika hasil > 9, jumlahkan digitnya.
      - Tambahkan ke total_kali2.
   c. Jika tidak:
      - Tambahkan ke total_biasa.
   d. Ubah status kali2 (true ↔ false).

7. Tambahkan digit terakhir ke total_biasa.

8. Hitung total akhir:
   total = total_kali2 + total_biasa

9. Validasi:
   - Jika jenis kartu dikenali DAN total % 10 == 0 → VALID
   - Selain itu → TIDAK VALID

10. Tampilkan jenis kartu dan hasil validasi.

11. Selesai.
*/