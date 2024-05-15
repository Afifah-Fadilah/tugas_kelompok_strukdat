#include <iostream>
#include <conio.h> //library untuk memanggil getch(), fungsi nya untuk menekan dulu keyboard ketika layar akan dibersihkan
#define maks 20 //membuat batas maksimal dalam queue

using namespace std;

struct Queue { //membuat struct bernama queue yang jenis nya adalah array
    int front, rear; //var bernama front dan rear berjenis integer
    char data[maks]; //membuat array data yang memiliki jumlah sesuai dengan maks, maks disini adalah 20
} Q; //membuat penyebutan pada struct ini yaitu Q

bool isFull() { //untuk mengecek apakah data dalam queue penuh
    return Q.rear == maks; //indeks bagian belakang antrian (rear) telah mencapai kapasitas maksimum, menunjukkan bahwa antrian penuh.
}

bool isEmpty() { //untuk mengecek apakah data dalam queue kosong
    return Q.rear == 0; //indeks bagian belakang (rear) sama dengan nol, ini berarti tidak ada data dalam Queue
}

void printQueue() { //fungsi untuk mencetak antrian data dalam queue
    if (isEmpty()) { //pengkondisian yang memanggil bool isEmpty, yang mana menunjukan bahwa antrian kosong
        cout << "Queue Kosong\n"; //maka program akan menampilkan ini
    } else { //pengkondisian lain yang akan di proses, atau dengan kata lain adanya data dalam antrian, maka
        cout << "\n\n   Display Queue (menampilkan data dalam queue)\n"; //program akan menampilkan data antrian
        cout << "---------------------------------------------------\n";
        for (int i = Q.front; i < Q.rear; i++) { //dengan memanggil perulangan dari front hingga rear untuk mencetak setiap elemen antrian
            cout << "data ke-" << i - Q.front + 1 << ": "; // Menampilkan nomor urut data dalam antrian (menggunakan offset dari Q.front)
            cout << Q.data[i] << endl; // Menampilkan data pada posisi i dalam antrian array
        }
    }
}

bool isPalindrome(char arr[], int size) { //untuk mmengecek apakah data dalam antrian termasuk palindrom atau bukan
    for (int i = 0; i < size / 2; i++) { // Perulangan dari 0 hingga setengah ukuran array,untuk membandingkan elemen dari depan dan belakang secara berpasangan
        if (arr[i] != arr[size - i - 1]) { // Memeriksa apakah elemen pada posisi i tidak sama dengan elemen pada posisi simetrisnya dari belakang
            return false; // Jika ditemukan elemen yang tidak sama, fungsi akan mengembalikan false dan menghentikan pengecekan lebih lanjut
        }
    }
    return true; // Jika seluruh elemen simetris sama, fungsi akan mengembalikan true, menandakan array adalah palindrom
}

void checkPalindrome() {
    Q.front = 0; // Reset queue
    Q.rear = 0;

    string input;
    cout << "Masukkan kata yang ingin dicek: ";
    cin >> input;

    for (char c : input) {
        if (Q.rear < maks) {
            Q.data[Q.rear] = c;
            Q.rear++;
        } else {
            cout << "Queue penuh, tidak bisa menambahkan lebih banyak karakter.\n";
            break;
        }
    }

    printQueue();

    if (isPalindrome(Q.data, Q.rear)) {
        cout << "\nQueue diatas adalah palindrom.\n";
    } else {
        cout << "Queue diatas bukan palindrom.\n";
    }
}

int main() { //fungsi utama
    char pilihan; //membuat var bernama pilihan bertipe char
    do {
        system("cls"); // Membersihkan layar
        cout << "\n\tProgram Queue Array untuk Mengecek Palindrom\n";
        cout << "---------------------------------------------\n";
        checkPalindrome(); // Memanggil fungsi untuk mengecek palindrom
        cout << "\nApakah Anda ingin mengecek kata lain? (y/n): ";
        cin >> pilihan; // Memasukkan pilihan user
    } while (pilihan == 'y' || pilihan == 'Y'); // Perulangan berdasarkan pilihan user

    cout << "\n\tProgram selesai\n";
    cout << "---------------------------------------\n";
    cout << "program ini dibuat oleh : \n";
    cout << "[1] Afifah Fadilah | 2310631170003\n";
    cout << "[2] Rachelia Achmara | 2310631170111\n";
    cout << "[3] Riva Sestia Praba | 2310631170045\n";
    return 0; //program berhenti dengan di tandai return 0, yaitu program berhenti dengan baik
}
