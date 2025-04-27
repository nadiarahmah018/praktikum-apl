#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MaxTiket 40

struct Tiket{
    string hari;
    string durasi;
    double harga;
    bool kausKaki;
    double totalHarga;
    string status;
};

struct User{
    string username;
    string password;
};

User daftarUser[40];  
int jumlahUser = 0; 

int main(){
    User user; 
    string inputUsername,inputPassword;
    int login;
    bool udahLogin = false;
    Tiket daftarTiket[MaxTiket];
    int jumlahTiket = 0;

    while (true){
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu (1/2/3): ";
        int pilih;
        cin >> pilih;

        if (pilih == 1){
            //menu regist
            cout << "=== Registrasi ===" << endl;
            cout << "Masukkan Username: " ;
            cin.ignore();
            getline(cin, user.username);
            cout << "Masukkan Password: " ;
            getline(cin, user.password);
            
            cout << "Registrasi berhasil! Silakan lanjut login." << endl;

        } else if (pilih == 2){
            //menu login
            login = 0;
            bool udahLogin = false;

            while (login < 3 && !udahLogin) {
                cout << "Masukkan Username: ";
                cin >> ws;
                getline(cin, inputUsername);
                cout << "Masukkan Password: ";
                cin >> ws;
                getline(cin, inputPassword);
                
                // cek apakah username dan password cocok
                if (inputUsername == user.username && inputPassword == user.password){
                    cout << "Login berhasil! Selamat datang " << user.username <<"!" << endl;
                    udahLogin = true;
                    break;

                } else {
                    login++;
                    cout << "Username atau password salah! Coba lagi" << endl;
                }
            }    
            if (login == 3) {
                cout << "Anda sudah mencoba 3 Kali. Program berhenti." << endl;
                return 0;
            }
            // menu tiket
            
            do {
                cout << "\n=== Menu Tiket  ===" << endl;
                cout << "1. Tambah Tiket" << endl;
                cout << "2. Tampilkan Tiket" << endl;
                cout << "3. Ubah data Tiket" << endl;
                cout << "4. Hapus Tiket" << endl;
                cout << "5. Keluar" << endl;
                cout << "Pilih menu (1/2/3/4/5): ";
                int pilihan;
                cin >> pilihan;
                cin.ignore();
                
                if (pilihan == 1){
                    if(jumlahTiket < MaxTiket){
                        int inputHari, inputDurasi;
                        char inputKausKaki;
                        double hargaTiket = 0, hargaWeekend =0, hargaKausKaki = 0;
                        Tiket tiketBaru;

                        cout << "1. Weekend" << endl;
                        cout << "2. Weekday" << endl;
                        cout << "Weekend Harga tiket + 5.000" << endl;
                        cout << "Masukkan Hari (1/2): ";
                        cin >> inputHari;
                        tiketBaru.hari = (inputHari == 1) ? "Weekend" : "Weekday";
                        hargaWeekend = (inputHari == 1) ? 5000 : 0;

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
                        
                        cout << "Apakah Anda membawa kaus kaki? (Y untuk Ya, T untuk Tidak): ";
                        cin >> inputKausKaki;
                        tiketBaru.kausKaki = (inputKausKaki == 'Y' || inputKausKaki == 'y');
                        hargaKausKaki = tiketBaru.kausKaki ? 0 : 10000;

                        tiketBaru.totalHarga = tiketBaru.harga + hargaWeekend + hargaKausKaki;
                        tiketBaru.status = "Tersedia";
                        daftarTiket[jumlahTiket++] = tiketBaru;
                        cout << "Tiket berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Jumlah tiket sudah mencapai batas maksimum!" << endl;
                    }
                } else if (pilihan ==2){
                    if (jumlahTiket == 0) {
                        cout << "Tidak ada tiket tersedia" << endl;
                    }else {
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
                } else if (pilihan == 3){
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
                    int no;
                    cout << "Masukkan nomor tiket yang ingin diubah: ";
                    cin >> no;
                    cin.ignore(); // Mengabaikan newline setelah cin

                    if (no < 1 || no > jumlahTiket) {
                        cout << "Nomor tiket tidak valid!" << endl;
                    } else {
                        Tiket &tiket = daftarTiket[no - 1];
                        int inputHari,inputDurasi;
                        char inputKausKaki;
                        double hargaTiket = 0, hargaWeekend =0, hargaKausKaki = 0;
                        Tiket tiketBaru;

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
                        hargaKausKaki = tiket.kausKaki ? 0 : 10000;

                        tiket.totalHarga = tiket.harga + hargaWeekend + hargaKausKaki;
                        
                        cout << "Masukkan status baru tiket: ";
                        cin.ignore();
                        getline(cin, tiket.status);

                        cout << "Tiket berhasil diubah!" << endl;
                    }
                } else if (pilihan == 4) {
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
                    int no;
                    cout << "Masukkan nomor tiket yang ingin dihapus: ";
                    cin >> no;

                    if (no < 1 || no > jumlahTiket) {
                        cout << "Nomor tiket tidak valid!" << endl;
                    } else {
                        for (int i = no - 1; i < jumlahTiket - 1; i++) {
                            daftarTiket[i] = daftarTiket[i + 1]; // Menggeser tiket ke kiri
                        }
                        jumlahTiket--; // Mengurangi jumlah tiket
                        cout << "Tiket berhasil dihapus!" << endl;
                    }
                } else if(pilihan == 5){
                    break;

                }else {
                    cout << "Pilihan tidak valid" << endl;
                }
            } while (true);

        } else if (pilih == 3){
            cout << "Terima Kasih!" << endl;
            break;
        }else {
            cout << "Pilihan tidak valid! Silahkan pilih lagi." << endl;
        }
    }
    return 0;
}