/* 
1. STRUKTUR DASAR C++
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
2. OUTPUT DAN INPUT
    OUTPUT : COUT << data yang ingin ditampilkan;  (baris baru pakai : endl)
    INPUT : cin >> variabel; 
3. Tipe data
    a. Tipe data primitif (untuk operasi dasar)
    int, float, double, char, bool, string
    b. Tipe data kolektif(berupa rangkaian kumpulan data yg memiliki indeks)
    list, array
    c.Tipe data abstrak
    struct(sekumpulan variabel bertipe data abstrak & dinyatakan dg sbuah nama)
4. Variabel (tempat menyipan nilai)
tipe data nama variabel = nilai;   contoh: int umur = 18;
5.Operator
    a.operator aritmatika
    penjumlahan +, pengurangan-, perkalian*, pembagian/, sisa bagi/modulus %, inccrement ++, decrement --
    b.operator penugasan(memberikan tugas pd variabel utk mengisikan nilai)
    penugasan =, penambahan+=,pengurangan-=, perkalian *=,pembagian /=, modulud %=, 
    pergeseran bit ke kiri >>=, ke kanan <<=, bitwise and &=, bitwise or Ekslusif ^=, bitwise or inklusif |=
    c. operator perbandingan 
    sama dgn ==, tidak sama dgn!=, kurang dari <, lebih dari> kurang dr sm dgn <=, lebih dr smdgn >=
    d.operator logika
    AND &&, OR||, NOT!
    e.operator bitwise
    AND &, OR|, XOR ^, NOT ~, pergeseran ke kiri<<, pergeseran ke kanan>>alignas
    f.operator ternary (menulis code if else dlm satu baris)
    kondisi ? ekspreji_jika_benar :ekspresi_jika_salah
    g.operator increment(++,a++,++a) dan decrement(--,a--,--a)
6. Percabangan
    a. if(satu blok oilihan)
    b. if else (dua blok pilihan)
    c. Else if(lebih dari dua blok)
    d.switch case (bentuk lain percabangan if-else-if)
    e.nested if(percabangan if yang ada di dalam if)
    f.ternary operator(if-else dlm satu baris)
7.Perulangan
    a.For(sudah ditentukan dan jelas berapakali dia akan mengulang)
    b.While(tdk ditentukan berapa kali ia akan berulang, akan terus berulang selama kondisi terpenuhi)
    c.Do while(eksekusi perintah 1 kali dlu,kemudian meriksa kondisi perulangan)
    d.perulangan foreach(mengakses element dari array/colection)
8.Flowchart(langkah-langkah dan keputusan dalam suatu proses)

*/
