#include <iostream>
#include <string>
#include <iomanip> // library untuk mengatur format output

using namespace std;

#define MaxTiket 100 // maksimal jumlah tiket

int main (){
    string nama, nim;
    int login = 0;

    //proses login
    while (login < 3){
        cout << "Silakan login dengan memasukkan Nama dan NIM" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        
        // mengecek login
        if (nama == "Nadia Rahmah" && nim == "2409106018"){
            cout << "Login Berhasil! Selamat datang " << nama << endl;
            break;

        } else {
            login++;
            cout << "Login gagal! Nama atau NIM salah." << endl;
        }
    }
    // jika login sudah 3 kali, maka login gagal dan program akan berhenti.
    if (login == 3) {
        cout << "Anda sudah mencoba 3 Kali. Program berhenti." << endl;
        return 0;
    }

    // Variabel array untuk menyimpan data tiket:
    bool hari[MaxTiket]; // array hari(Weekend/Weekday)
    string durasi[MaxTiket]; // array durasi bermain
    double harga[MaxTiket]; //array harga tiket
    bool kausKaki[MaxTiket]; // array apakah membawa kaus kaki
    double totalHarga[MaxTiket]; // array jumlah harga tiket
    int JumlahTiket = 0; 

    int pilihan;
    do { 
        cout << "\n Menu Tiket" << endl;
        cout << "1. Tambah Tiket" << endl;
        cout << "2. Tampilkan Tiket" << endl;
        cout << "3. Ubah data Tiket" << endl;
        cout << "4. Hapus Tiket" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                if (JumlahTiket < MaxTiket) {
                    int inputHari;
                    int inputDurasi;
                    char inputKausKaki;
                    double hargaTiket = 0; // variabel Harga tiket
                    double hargaWeekend = 0; // variabel untuk harga tambahan weekend
                    double hargaKausKaki = 0; // variabel untuk harga tambahan kaus kaki

                    cout << "1. Weekend" << endl;
                    cout << "2. Weekday" << endl;
                    cout << "Weekend Harga tiket + 5.000" << endl;
                    cout << "Masukkan Hari (1/2): ";
                    cin >> inputHari;
                    // jika kondisi memenuhi Tambahan biaya
                    if (inputHari == 1) {
                        hargaWeekend = 5000; // Tambahan biaya untuk weekend
                        hari[JumlahTiket] = true;
                    } else if (inputHari == 2){
                        hargaWeekend = 0; // tidak ada tambahan karena weekday
                        hari[JumlahTiket] = false;
                    } else {
                        cout << "Hari tidak tersedia" << endl;
                        break;
                    }
                    cout << "\n Durasi bermain dan Harga Tiket" << endl;
                    cout << "1. 1 Jam : 20.000" << endl;
                    cout << "2. 2 Jam : 35.000" << endl;
                    cout << "3. Sepuasnya : 45.000" << endl;
                    cout << "Masukkan Durasi bermain(1/2/3) : ";
                    cin >> inputDurasi;
                    // menetapkan durasi bermain, menetapkan harga tiket dan simpan data durasi
                    if (inputDurasi == 1) {
                        durasi[JumlahTiket] = "1 Jam";
                        hargaTiket = 20000;
                    } else if (inputDurasi == 2) {
                        durasi[JumlahTiket] = "2 Jam";
                        hargaTiket = 35000;
                    } else if (inputDurasi == 3) {
                        durasi[JumlahTiket] = "Sepuasnya";
                        hargaTiket = 45000;
                    } else {
                        cout << "Durasi tidak tersedia" << endl;
                        break;
                    } 
                    cout << "Apakah membawa Kaus Kaki (Y/T): ";
                    cin >> inputKausKaki;   
                    if (inputKausKaki == 'T') {
                        hargaKausKaki = 10000; // tambahan biaya untuk kaus kaki   
                    } else if (inputKausKaki == 'Y') {
                        hargaKausKaki = 0; // tidak ada tambahan karena membawa kaus kaki 
                    } else {
                        cout << "pilihan tidak valid" << endl;
                        break;
                    }

                    totalHarga[JumlahTiket] = hargaTiket + hargaWeekend + hargaKausKaki; // hitung total harga
                    hari[JumlahTiket] = (inputHari == true);
                    harga[JumlahTiket] = hargaTiket; 
                    kausKaki[JumlahTiket] = (inputKausKaki == 'Y');
                    JumlahTiket++;

                    cout << "Tiket berhasil ditambahkan." << endl;
                        
                } else {
                    cout << "Penjualan tiket sudah mencapai batas maksimum" << endl;
                }
                break;
            }
            case 2: {
                cout << "\nDaftar Tiket: " << endl;
                cout << left << setw(14) << "Index"
                     << setw(14) << "Hari"  
                     << setw(14) << "Durasi"
                     << setw(14) << "Harga Normal"
                     << setw(14) << "Kaus Kaki"
                     << setw(14) << "Total Harga" << endl;
                cout << string(84, '-') << endl; 
                for (int i = 0; i < JumlahTiket; i++) {
                    cout << left << setw(14) << (i + 1) // Menampilkan index
                         << setw(14) << (hari[i] ? "Weekend" : "Weekday")
                         << setw(14) << durasi[i] 
                         << setw(14) << harga[i] 
                         << setw(14) << (kausKaki[i] ? "Ya" : "Tidak") 
                         << setw(14) << totalHarga[i] << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "\nDaftar Tiket: " << endl;
                cout << left << setw(14) << "Index"
                     << setw(14) << "Hari"  
                     << setw(14) << "Durasi"
                     << setw(14) << "Harga Normal"
                     << setw(14) << "Kaus Kaki"
                     << setw(14) << "Total Harga" << endl;
                cout << string(84, '-') << endl; 
                for (int i = 0; i < JumlahTiket; i++) {
                    cout << left << setw(14) << (i + 1) 
                         << setw(14) << (hari[i] ? "Weekend" : "Weekday")
                         << setw(14) << durasi[i] 
                         << setw(14) << harga[i] 
                         << setw(14) << (kausKaki[i] ? "Ya" : "Tidak") 
                         << setw(14) << totalHarga[i] << endl;
                }
                cout << "Masukkan nomer tiket yang ingin diubah: ";
                cin >> index;
                index--;
                if (index >= 0 && index < JumlahTiket) {
                    int inputHari;
                    int inputDurasi;
                    char inputKausKaki;
                    double hargaTiket = 0; // Variabel Harga tiket
                    double hargaWeekend = 0; // Variabel untuk harga tambahan weekend
                    double hargaKausKaki = 0; // Variabel untuk harga tambahan kaus kaki

                    cout << "1. Weekend" << endl;
                    cout << "2. Weekday" << endl;
                    cout << "Weekend Harga tiket + 5.000" << endl;
                    cout << "Masukkan Hari (1/2): ";
                    cin >> inputHari;
                    if (inputHari == 1) {
                        hargaWeekend = 5000; // Tambahan biaya untuk weekend
                    } else if (inputHari == 2){
                        hargaWeekend = 0; // tidak ada tambahan karena weekday
                    } else {
                        cout << "Hari tidak tersedia" << endl;
                        break;
                    } 
                    cout << "\n Durasi bermain dan Harga Tiket" << endl;
                    cout << "1. 1 Jam : 20.000" << endl;
                    cout << "2. 2 Jam : 35.000" << endl;
                    cout << "3. Sepuasnya : 45.000" << endl;
                    cout << "Masukkan Durasi bermain : ";
                    cin >> inputDurasi;
                    // menetapkan durasi bermain, menetapkan harga tiket dan simpan data durasi
                    if (inputDurasi == 1) {
                        durasi[index] = "1 Jam";
                        hargaTiket = 20000;
                    } else if (inputDurasi == 2) {
                        durasi[index] = "2 Jam";
                        hargaTiket = 35000;
                    } else if (inputDurasi == 3) {    
                        durasi[index] = "Sepuasnya";
                        hargaTiket = 45000;
                    } else {
                        cout << "Durasi tidak tersedia" << endl;
                        break;
                    }
                    cout << "Apakah membawa Kaus Kaki (Y/T): ";
                    cin >> inputKausKaki;
                    if (inputKausKaki == 'T') {
                        hargaKausKaki = 10000; // tambahan biaya untuk kaus kaki   
                    } else if (inputKausKaki == 'Y') {
                        hargaKausKaki = 0; // tidak ada tambahan karena membawa kaus kaki 
                    } else {
                        cout << "pilihan tidak valid" << endl;
                        break;
                    }
                    totalHarga[index] = hargaTiket + hargaWeekend + hargaKausKaki;  // Hitung total harga
                    hari[index] = inputHari;
                    harga[index] = hargaTiket; 
                    kausKaki[index] = (inputKausKaki == 'Y'); // Update status kaus kaki
                    cout << "Tiket berhasil diupdate." << endl;
                } else {
                    cout << "Nomer Tidak valid." << endl;
                }
                break;
            }    
            case 4: {
                int index;
                cout << "\nDaftar Tiket: " << endl;
                cout << left << setw(14) << "Index"
                     << setw(14) << "Hari"  
                     << setw(14) << "Durasi"
                     << setw(14) << "Harga Normal"
                     << setw(14) << "Kaus Kaki"
                     << setw(14) << "Total Harga" << endl;
                cout << string(84, '-') << endl; 
                for (int i = 0; i < JumlahTiket; i++) {
                    cout << left << setw(14) << (i + 1) // Menampilkan index
                         << setw(14) << (hari[i] ? "Weekend" : "Weekday")
                         << setw(14) << durasi[i] 
                         << setw(14) << harga[i] 
                         << setw(14) << (kausKaki[i] ? "Ya" : "Tidak") 
                         << setw(14) << totalHarga[i] << endl;
                }
                cout << "Masukkan nomer tiket yang ingin dihapus: ";
                cin >> index;
                index--;
                if (index >= 0 && index < JumlahTiket) {
                    for (int i = index; i < JumlahTiket - 1; i++) {
                        hari[i] = hari[i + 1];
                        durasi[i] = durasi[i + 1];
                        harga[i] = harga[i + 1]; 
                        kausKaki[i] = kausKaki[i + 1]; 
                        totalHarga[i] = totalHarga[i + 1];
                    }
                    JumlahTiket--;
                    cout << "Tiket berhasil dihapus" << endl;
                } else {
                    cout << "Nomer Tidak valid." << endl; 
                }
                break;
            }
            case 5: {
                cout << "Terima kasih! Program selesai." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 5);

    return 0;  
}
