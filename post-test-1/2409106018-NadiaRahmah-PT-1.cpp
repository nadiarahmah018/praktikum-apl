#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama, nim;
    int login = 0;

    // proses login 
    while (login < 3) {
        cout << "Silakan login dengan memasukkan Nama dan NIM" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin,nim);

        // mengecek login
        if (nama == "Nadia Rahmah" && nim == "2409106018") {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            login++;
            cout << "LOGIN GAGAL! Nama atau NIM salah" << endl;
        }
    }     
    // jika login sudah 3 kali, maka login gagal dan program akan berhenti.
    if (login == 3) {
        cout << "Anda sudah mencoba 3 Kali. Program berhenti." << endl;
        return 0 ;
    }
    // menu konversi satuan panjang
    while (true) {
        int pilihan;
        cout << "\nMenu Konversi:\n";
        cout << "1. Konversi Meter ke (Centimeter, Mile, Foot)\n";
        cout << "2. Konversi Centimeter ke (Meter, Mile, Foot)\n";
        cout << "3. Konversi Mile ke (Meter, Centimeter, Foot)\n";
        cout << "4. Konversi Foot ke (Meter, Centimeter, Mile)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;  
        
        if (pilihan == 1){
            double meter;
            cout << "Masukkan nilai dalam satuan Meter: ";
            cin >> meter;
            cout << meter << " Meter = " << meter * 100 << " Centimeter" << endl;
            cout << meter << " Meter = " << meter * 0.000621371 << " Mile" << endl;
            cout << meter << " Meter = " << meter * 3.28084 << " Foot" << endl;

        } else if (pilihan == 2){
            double centimeter;
            cout << "Masukkan nilai dalam satuan Centimeter: ";
            cin >> centimeter;
            cout << centimeter << " Centimeter = " << centimeter * 0.01 << " Meter" << endl;
            cout << centimeter << " Centimeter = " << centimeter * 0.00000621371 << " Mile" << endl;
            cout << centimeter << " Centimeter = " << centimeter * 0.0328084 << " Foot" << endl;

        } else if (pilihan == 3){
            double mile;
            cout << "Masukkan nilai dalam satuan Mile: ";
            cin >> mile;
            cout << mile << " Mile = " << mile * 1609.34 << " Meter" << endl;
            cout << mile << " Mile = " << mile * 160934.0 << " Centimeter" << endl;
            cout << mile << " Mile = " << mile * 5280.0 << " Foot" << endl;

        } else if (pilihan == 4){
            double foot;
            cout << "Masukkan nilai dalam Foot): ";
            cin >> foot;
            cout << foot << " Foot = " << foot * 0.3048 << " Meter" << endl;
            cout << foot << " Foot = " << foot * 30.48 << " Centimeter" << endl;
            cout << foot << " Foot = " << foot * 0.000189394 << " Mile" << endl;
        
        } else if (pilihan == 5){
            cout << "Terimakasih! Program selesai." << endl;
            break;

        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi" << endl;
        }
    }
    return 0;
}