#include <iostream>
using namespace std;

int main() {
    int N;
    string S;

    cout << "Masukkan jumlah babak: ";
    cin >> N;
    cout << "Masukkan hasil (A/B/C): ";
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;

            if (streakA == 3) {
                poinA += 2;
                streakA = 0; // reset setelah bonus
            }

        } else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;

            if (streakB == 3) {
                poinB += 2;
                streakB = 0; // reset setelah bonus
            }

        } else if (S[i] == 'C') {
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }
    }

    cout << "\nPoin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB) {
        cout << "Pemenangnya adalah pemain A" << endl;
    } else if (poinB > poinA) {
        cout << "Pemenangnya adalah pemain B" << endl;
    } else {
        cout << "Hasil pertandingan Seri!" << endl;
    }

    return 0;
}

/*
ALGORITMA / LOGIKA PROGRAM:

1. Program meminta input:
   - Jumlah babak (N)
   - String hasil pertandingan (S) yang terdiri dari karakter A, B, atau C

2. Inisialisasi:
   - poinA dan poinB = 0
   - streakA dan streakB = 0 (untuk menghitung kemenangan beruntun)

3. Perulangan sebanyak N kali:
   - Jika hasil = 'A':
     a. Tambah poinA sebanyak 3
     b. Tambah streakA, reset streakB
     c. Jika streakA mencapai 3:
        - Tambah bonus 2 poin ke poinA
        - Reset streakA

   - Jika hasil = 'B':
     a. Tambah poinB sebanyak 3
     b. Tambah streakB, reset streakA
     c. Jika streakB mencapai 3:
        - Tambah bonus 2 poin ke poinB
        - Reset streakB

   - Jika hasil = 'C' (seri):
     a. Tambah poinA dan poinB masing-masing 1
     b. Reset streakA dan streakB

4. Setelah perulangan selesai:
   - Tampilkan poin akhir pemain A dan B

5. Tentukan pemenang:
   - Jika poinA > poinB → A menang
   - Jika poinB > poinA → B menang
   - Jika sama → hasil seri

6. Tampilkan hasil pertandingan ke layar.
*/
