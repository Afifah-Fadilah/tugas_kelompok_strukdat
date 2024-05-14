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

void enqueue() { //membuat fungsi untuk menambah data ke dalam antrian queue
    if (isFull()) { //pengkondisian dengan memanggil bool isFull untuk mengecek apababila data sudah penuh
        cout << "Queue Penuh\n"; //maka akan menampilkan seperti ini
    } else { //kondisi lain yang akan terjadi atau dengan kata lain antrian belum penuh dan masih bisa di tambahkan 
        int numData; //membuat var bernama numData bertipe integer
        cout << "\n\n    Enqueue (menambah data ke dalam queue)\n"; //maka akan ada tampilan yang mmemerintah untuk menambahkan data
        cout << "---------------------------------------------\n";
        cout << "Masukkan jumlah data yang ingin dimasukkan: "; //perintah untuk memasukkan jumlah data yang ingin di tambahkan
        cin >> numData; //input user berupa angka, untuk memasukkan jumlah data yang ingin di inputkan

        for (int i = 0; i < numData; i++) { //perulangan dari i = 0 hingga numData yang tadi user inputkan
            if (isFull()) { //pengkondisian yang memanggil bool isFull yang mana apabila data yang akan ditambahkan tidak muat dalam antrian maka
                cout << "Queue penuh, hanya berhasil memasukkan " << i << " data.\n"; //akan menampilkan seperti ini
                break; //dan program di hentikan dalam loopingan for
            }

            char data; //membuat var bernama data bertipe char
            cout << "Masukkan data ke-" << (Q.rear + 1) << ": "; //membuat perulangan yang memerintah untuk memasukkan data dengan penomoran 
            cin >> data; //inputan user berupa data char
            Q.data[Q.rear] = data;  // Menyimpan data yang diinputkan user ke dalam antrian di posisi rear
            Q.rear++;  // Menambah nilai rear untuk menunjukkan posisi kosong berikutnya dalam antrian
        }
        cout << "----------------------------\n";
        cout << "Data berhasil ditambahkan\n";
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

int main() { //fungsi utama
    int pilih; //membuat var bernama pilih bertipe integer
    do { //perulangan yang akan terus berjalan sampai dihentikan oleh pilihan user
        cout << "\n\t  Program Queue Array\n"; //judul program
        cout << "---------------------------------------\n";
        cout << "Menu pilihan :\n";
        cout << "[1] Enqueue\n";
        cout << "[2] Tampilkan\n";
        cout << "[3] Keluar\n";
        cout << "---------------------------------------\n";
        cout << "Masukkan Pilihan : "; //perintah untuk memasukkan pilihan menu di atas
        cin >> pilih; //inputan user yang masuk ke dalam var pilih
        switch (pilih) { //pengkondisian yang akan dijalankan sesuai dengan pilihan user di atas
            case 1: //blok kode yang akan di jalankan apabila user menginputkan 1 maka
                system("cls"); //fungsi untuk membersihkan tampilan 
                enqueue(); //memanggil fungsi enqueue yang sudah di buat di atas
                cout << "\ntekan keyboard untuk kembali ke menu..."; 
                getch(); //memanggil fungsi getch untuk menjeda blok kode setelahnya, untuk melanjutkan klik keyboard
                system("cls"); //tampilan akan dibersihkan 
                break; //program dalam case 1 di hentikan, sehingga akan kembali menampilkan menu
            case 2: //blok kode yang akan di jalankan apabila user menginputkan 2 maka
                system("cls"); 
                printQueue(); //memanggil fungsi printQueue yang sudah di buat di atas
                if(isEmpty()){ //pengkondisian yang terjadi dengan memanggil bool isEmpty untuk mengecek apakah ada data dalam antrian
                    ""; //apabila tidak ada jawaban apakah queue tersebut palindrom atau tidak
                }else{ //kondisi lain yang akan di jalankan, yaitu dengan kata lain ada data dalam antrian
                    if (isPalindrome(Q.data, Q.rear)) { //membuat pengkondisian dengan memanggil fungsi isPalindrome yang sudah di buat
                    cout << "\nQueue diatas adalah palindrom.\n"; // Jika fungsi isPalindrome mengembalikan true, maka cetak pesan bahwa queue adalah palindrom
                    } else { //kode yang akan dijelankan selain kondisi di atas
                    cout << "Queue diatas bukan palindrom.\n"; // Jika fungsi isPalindrome mengembalikan false, maka cetak pesan bahwa queue bukan palindrom
                    }
                }
                cout << "\ntekan keyboard untuk kembali ke menu...";
                getch();
                system("cls");
                break;
            case 3: //blok kode yang akan di jalankan apabila user menginputkan 3 maka
                system("cls");
                cout << "\n\t   Program selesai\n"; //akan ada tampilan pembuat program
                cout << "---------------------------------------\n";
                cout << "program ini dibuat oleh : \n";
                cout << "[1] Afifah Fadilah | 2310631170003\n";
                cout << "[2] Rachelia Achmara | 2310631170111\n";
                cout << "[3] Riva Sestia Praba | 2310631170045\n";
                return 0; //dan program berhenti dengan di tandai return 0, yaitu program berhenti dengan baik
            default: //blok kode yang akan di jalankan apabila user menginputkan selain 1,2,dan 3
                cout << "pilihan tidak tersedia";
                break; 
        }
    }while(pilih); //batasan dari perulangan do while
}