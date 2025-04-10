#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MaxTiket 40

struct Tiket {
    string hari;
    string durasi;
    double harga;
    bool kausKaki;
    double totalHarga;
    string status;
};

struct User {
    string username;
    string password;
};

User daftarUser[40];
int jumlahUser = 0;
Tiket daftarTiket[MaxTiket];
int jumlahTiket = 0;

void registrasi(User &user);
bool login(User &user);
void menuTiket();
void tambahTiket();
void tampilkanTiket();
void ubahTiket();
void hapusTiket();

void menuUtama(){
    User user;
    while (true){
        cout << "========================" << endl;
        cout << "|      MENU UTAMA      |" << endl;
        cout << "========================" << endl;
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu (1/2/3): ";
        int pilih;
        cin >> pilih;     
        
        if (pilih == 1){
            registrasi(user);
        }else if(pilih == 2){
            if (login(user)){
                menuTiket();
            }
        } else if (pilih == 3) { 
            cout << "Terima Kasih!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
        }
    }
}

void registrasi(User &user) {
    cout << "=== Registrasi ===" << endl;
    cout << "Masukkan Username: ";
    cin.ignore();
    getline(cin, daftarUser[jumlahUser].username);
    cout << "Masukkan Password: ";
    getline(cin, daftarUser[jumlahUser].password);
    cout << "Registrasi berhasil! Silakan lanjut login." << endl; 
    jumlahUser++;   
}

bool login(User &user) {
    string inputUsername, inputPassword;
    int login = 0;
    while (login < 3) {
        cout << "Masukkan Username: ";
        cin >> ws;
        getline(cin, inputUsername);
        cout << "Masukkan Password: ";
        cin >> ws;
        getline(cin, inputPassword);
        
        for (int i = 0; i < jumlahUser; i++) {
            if (inputUsername == daftarUser[i].username && inputPassword == daftarUser[i].password) {
                user = daftarUser[i]; 
                cout << "Login berhasil! Selamat datang " << user.username << "!" << endl;
                return true;
            }
        } 
        login++;
        if (login < 3) {
            cout << "Username atau password salah! Coba lagi" << endl;
        }
    }
    cout << "Anda sudah mencoba 3 Kali. Program berhenti." << endl;
    exit(0);
}
void menuTiket() {
    while (true) {
        cout << "========================" << endl;
        cout << "|       MENU TIKET     |" << endl;
        cout << "========================" << endl;
        cout << "1. Tambah Tiket" << endl;
        cout << "2. Tampilkan Tiket" << endl;
        cout << "3. Ubah data Tiket" << endl;
        cout << "4. Hapus Tiket" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        int pilihan;
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahTiket();
                break;
            case 2:
                tampilkanTiket();
                break;
            case 3:
                ubahTiket();
                break;
            case 4:
                hapusTiket();
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }
}
void tambahTiket() {
    if (jumlahTiket < MaxTiket) {
        Tiket tiketBaru;
        int inputHari, inputDurasi;
        char inputKausKaki;

        cout << "1. Weekend (+ 5.000)" << endl;
        cout << "2. Weekday" << endl;
        cout << "Masukkan Hari (1/2): ";
        cin >> inputHari;
        tiketBaru.hari = (inputHari == 1) ? "Weekend" : "Weekday";

        cout << "1. 1 Jam 20.000" << endl;
        cout << "2. 2 Jam 35.000" << endl;
        cout << "3. Sepuasnya 45.000" << endl;
        cout << "Masukkan Durasi (1/2/3): ";
        cin >> inputDurasi;
        if (inputDurasi == 1) {
            tiketBaru.durasi = "1 Jam";
            tiketBaru.harga = 20000;
        } else if (inputDurasi == 2) {
            tiketBaru.durasi = "2 Jam";
            tiketBaru.harga = 35000;
        } else {
            tiketBaru.durasi = "Sepuasnya";
            tiketBaru.harga = 45000;
        }

        cout << "***Jika tidak membawa kaus kaki, maka diwajibkan membeli seharga 10.000 ***" << endl;
        cout << "Apakah Anda membawa kaus kaki? (Y untuk Ya, T untuk Tidak): ";
        cin >> inputKausKaki;
        tiketBaru.kausKaki = (inputKausKaki == 'Y' || inputKausKaki == 'y');
        tiketBaru.totalHarga = tiketBaru.harga + ((inputHari == 1) ? 5000 : 0) + (tiketBaru.kausKaki ? 0 : 10000);
        tiketBaru.status = "Aktif";
        daftarTiket[jumlahTiket++] = tiketBaru;
        cout << "Tiket berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah tiket sudah mencapai batas maksimum!" << endl;
    }
}

void tampilkanTiket() {
    if (jumlahTiket == 0) {
        cout << "Tidak ada tiket tersedia" << endl;
    } else {
        cout << setw(10) << "No" << setw(15) << "Hari" << setw(15) << "Durasi" << setw(10) << "Harga" << setw(15) << "Kaus Kaki" << setw(15) << "Total Harga" << setw(15) << "Status" << endl;
        for (int i = 0; i < jumlahTiket; i++) {
            cout << setw(10) << (i + 1)
                 << setw(15) << daftarTiket[i].hari
                 << setw(15) << daftarTiket[i].durasi
                 << setw(10) << daftarTiket[i].harga
                 << setw(15) << (daftarTiket[i].kausKaki ? "Ya" : "Tidak")
                 << setw(15) << daftarTiket[i].totalHarga
                 << setw(15) << daftarTiket[i].status << endl;
        }
    }
}

void ubahTiket() {
    tampilkanTiket();
    int no;
    cout << "Masukkan nomor tiket yang ingin diubah: ";
    cin >> no;

    if (no < 1 || no > jumlahTiket) {
        cout << "Nomor tiket tidak valid!" << endl;
        return;
    }

    Tiket &tiket = daftarTiket[no - 1];
    int inputHari, inputDurasi;
    char inputKausKaki;

    cout << "1. Weekend" << endl;
    cout << "2. Weekday" << endl;
    cout << "Masukkan Hari baru (1/2): ";
    cin >> inputHari;
    tiket.hari = (inputHari == 1) ? "Weekend" : "Weekday";

    cout << "1. 1 Jam 20.000" << endl;
    cout << "2. 2 Jam 35.000" << endl;
    cout << "3. Sepuasnya 45.000" << endl;
    cout << "Masukkan Durasi baru (1/2/3): ";
    cin >> inputDurasi;
    if (inputDurasi == 1) {
        tiket.durasi = "1 Jam";
        tiket.harga = 20000;
    } else if (inputDurasi == 2) {
        tiket.durasi = "2 Jam";
        tiket.harga = 35000;
    } else {
        tiket.durasi = "Sepuasnya";
        tiket.harga = 45000;
    }

    cout << "Apakah Anda membawa kaus kaki? (Y untuk Ya, T untuk Tidak): ";
    cin >> inputKausKaki;
    tiket.kausKaki = (inputKausKaki == 'Y' || inputKausKaki == 'y');
    tiket.totalHarga = tiket.harga + ((inputHari == 1) ? 5000 : 0) + (tiket.kausKaki ? 0 : 10000);

    cout << "Masukkan status baru tiket: ";
    cin.ignore();
    getline(cin, tiket.status);

    cout << "Tiket berhasil diubah!" << endl;
}

void hapusTiket() {
    tampilkanTiket();
    int no;
    cout << "Masukkan nomor tiket yang ingin dihapus: ";
    cin >> no;

    if (no < 1 || no > jumlahTiket) {
        cout << "Nomor tiket tidak valid!" << endl;
        return;
    }

    for (int i = no - 1; i < jumlahTiket - 1; i++) {
        daftarTiket[i] = daftarTiket[i + 1]; // Menggeser tiket ke kiri
    }
    jumlahTiket--; // Mengurangi jumlah tiket
    cout << "Tiket berhasil dihapus!" << endl;
}

int main() {
    cout << "==============================================================" << endl;
    cout << "| SELAMAT DATANG DI APLIKASI PEMBELIAN TIKET MINI PLAYGROUND |" << endl;
    cout << "==============================================================" << endl;
    cout << " Silakan registrasi atau login untuk mulai menggunakan\n";
    menuUtama();
    return 0;
}