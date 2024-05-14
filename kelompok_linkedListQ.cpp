#include <iostream>
#include <conio.h> //library untuk memanggil getch(), fungsi nya untuk menekan dulu keyboard ketika layar akan dibersihkan

using namespace std;

struct Node{ //membuat struct bernama Node yang mana jenisnya adalah linkedList
    char data; //variabel untuk menyimpan data yang ingin di simpan dalam linked list
    Node* next; //pointer yang menunjuk ke Node berikutnya dalam linked list. 
};

struct Queue { //struct bernama queue yang mengelompokkan 2 pointer
    Node* front; //pointer ini menunjukkan ke elemen pertama dalam antrian
    Node* rear; //pointer ini menunjukkan ke elemen terakhir dalam antrian
};

void initQueue(Queue* q) { //fungsi yang menginisialisasikan antrean di awal program
    q->front = q->rear = NULL; //ini menunjukkan bahwa antrian dalam front maupun rear adalah kosong (NULL)
}

bool isEmpty(Queue* q) { //membuat fungsi yang memeriksa apakah antrian kosong atau tidak
    return (q->front == NULL && q->rear ==NULL); //dengan memeriksa apakah kedua pointer front & rear kosong
}

void enqueue(Queue* q, int numData) { //fungsi untuk menambahkan elemen ke dalam antrian (queue)
    for (int i = 0; i < numData; ++i) { //dengan membuat perulangan dari berapa data yang ingin di masukkan
        char data; //dengan menggunakan tipe data char
        cout << "Masukkan data ke-" << i+1 << ": "; //perintah untuk memasukkan data secara berulang sesuai perulangan
        cin >> data; //inputan dari user

        Node* newNode = new Node; //membuat node baru dalam memori secara dinamis menggunakan operator new
        newNode->data = data; //Setelah node baru dibuat, data yang dimasukkan oleh pengguna disimpan di dalam var data dari node baru tsb
        newNode->next = NULL; //pointer next dari node baru diatur NULL, karena pada saat ini node baru berada di ujung antrian

        //kondisi untuk memeriksa apakah antrian kosong atau tidak. 
        if (isEmpty(q)) { //Jika antrian kosong, maka front dan rear diatur untuk menunjuk ke node baru. node baru ini satu-satunya node dalam antrian.
            q->front = q->rear = newNode;
        } else { //jika antrian tidak kosong, node baru ditambahkan di belakang antrian, dan rear diperbarui untuk menunjuk ke node baru
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
    cout << "----------------------------\n"; //penegasan bahwa data sudah berhasil masuk ke antrian
    cout << "Data berhasil ditambahkan\n";
}


void display(Queue* q){ //fungsi untuk menampilkan elemen dalam antrian (queue)
    if(isEmpty(q)){ //kondisi apabila queue kosong
        cout << "Queue kosong\n"; //maka akan menampilkan output ini
    }
    else{ //kondisi lain yang akan ditampilkan apabila elemen dalam antrian ada
        Node* temp = q->front; //Pointer temp dibuat untuk menunjuk ke elemen pertama dalam antrian, yaitu front.
        int counter = 1; // Variabel counter untuk nomor data
        while(temp != NULL) { //perulangan selama pointer temp tidak menunjuk ke NULL, berarti masih ada elemen dalam antrian yang harus ditampilkan.
            cout << "data ke-" << counter << " : " << temp->data << "\n"; //Baris ini bertugas untuk menampilkan data dari setiap node dalam antrian
            temp = temp->next; //setelah data dalam temp ditampilkan, pointer temp diperbarui untuk menunjuk ke node berikutnya dalam antrian
            counter++; //membuat nomor urutan dari tiap data nya
        }
    }
}

bool isPalindrome(Queue* q) { // Membuat fungsi yang mengecek apakah elemen dalam antrian (queue) adalah palindrom atau bukan palindrom
    if (isEmpty(q)) {
        return true; // Jika elemen dalam antrian kosong (NULL) maka didefinisikan palindrom
    }

    // Membuat dua pointer untuk menelusuri antrian dari kedua ujung
    Node* frontPtr = q->front;
    Node* rearPtr = q->rear;

    // Menelusuri antrian dari kedua ujung dan membandingkan karakter-karakternya
    while (frontPtr != NULL && rearPtr != NULL) {
        // Jika karakter pada posisi saat ini tidak sama, maka bukan palindrom
        if (frontPtr->data != rearPtr->data) {
            return false;
        }
        frontPtr = frontPtr->next;
        rearPtr = rearPtr->next;
    }

    // Jika semua karakter cocok, maka itu adalah palindrom
    return true;
}

int main() { //fungsi utama
    Queue q; //menginisialisasikan queue menjadi q
    initQueue(&q); //memanggil fungsi yang menunjukkan kondisi awal dalam antiran (queue)

    int pilih; //membuat var bernama pilih bertipe int
    char data; //membuat var bernama data bertipe char, fungsi nya untuk memasukkan data ke dalam antrian (queue)
    do{
        cout << "\n\tProgram Queue linkedList\n"; //membuat menu pilihan dalam program
        cout << "---------------------------------------\n";
        cout << "Menu pilihan :\n";
        cout << "[1] Enqueue\n";
        cout << "[2] Tampilkan\n";
        cout << "[3] Keluar\n";
        cout << "---------------------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilih; //inputan dari user yang dimasukkan ke var pilih

        switch(pilih) { //pengkondisian yang akan dijalankan dari var pilih yang sudah user input tadi
            case 1: //blok kode yang akan dijalankan apabila user meninputkan 1
                int numData; //var bernama numData bertipe int
                system("cls"); //membersihkan tampilan terminal
                cout << "\n   Enqueue (menambah data ke dalam queue)\n"; //membuat judul untuk menegaskan bahwa ini adalah menu enqueue
                cout << "---------------------------------------------\n"; 
                cout <<"Masukkan jumlah data yang ingin dimasukkan: ";
                cin >> numData; //inputan user yang masuk ke var numData 
                enqueue(&q, numData); //memanggil fungsi enqueue yang mana akan memerintah user untuk menginputkan data ke dalam antrian (queue)
                cout << "\ntekan keyboard untuk kembali ke menu...";
                getch(); //memberikan jeda untuk melanjutkan ke kode selanjutnya, untuk lanjut user bisa klik tombol dalam keyboard
                system("cls"); //yaitu kode yang akan membersihkan tampilan terminal
                break;
            case 2: //blok kode yang akan terjadi apabila user menginputkan 2 
                system("cls"); //membersihkan tampilan di terminal
                cout << "\n\n   Display Queue (menampilkan data dalam queue)\n"; //membuat judul yang menegaskan bahwa ini adalah menu display
                cout << "---------------------------------------------------\n";
                display(&q); //memanggil fungsi display yang mana akan menampilkan data - data dalam antrian (queue)
                if (isPalindrome(&q)) { //kondisi yang memanggil bool ispalindrome, yang mana jika data memenuhi bool ini maka akan 
                    cout << "\nQueue diatas adalah palindrom.\n"; //diinisialisasikan bahwa antrian (queue) tersebut adalah palindrom
                } else { //dan jika bool tersebut tidak memenuhi kondisi diatas, maka
                    cout << "\nQueue diatas bukan palindrom.\n"; //palindrome tersebut bukan lah palindrom
    }           
                cout << "\ntekan keyboard untuk kembali ke menu...";
                getch(); //memberikan jeda untuk melanjutkan ke kode berikutnya
                system("cls"); //yaitu membersihkan tampilan dalam terminal
                break;
            case 3:  //blok kode yang akan dijalankan apabila user menginputkan 3
                system("cls"); //membersihkan tampilan terminal
                cout << "\n\t   Program selesai\n"; //menujukkan keterangan bahwa program selesai
                cout << "-----------------------------------------\n";
                cout << "program ini dibuat oleh : \n"; //menunjukkan bahwa program dibuat oleh
                cout << "[1] Afifah Fadilah | 2310631170003\n";
                cout << "[2] Rachelia Achmara | 2310631170111\n";
                cout << "[3] Riva Sestia Praba | 2310631170045\n";
                return 0; //yang ditandai dengan return 0, yang mana program berhenti dengan baik
            default: //blok kode yang akan dijalankan apabila user menginputkan selain 1,2,3
                system("cls"); //memberihkan tampilan terminal
                cout << "Pilihan tidak tersedia\n";
                break;
        }
    } while(pilih); //perulangan yang akan terus dijalankan blok kode do while
}