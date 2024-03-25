#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct partikel{
    int proton;
    int elektron;
    int neutron;
};

partikel muatan[200]{
    {1, 1, 0},
    {4, 4, 5},
    {8, 8, 8},
    {6, 6, 6},
    {7, 7, 7},
    {28, 28, 31},
};

struct atom{
    string nama;
    string singkatan;
    string wujud;
    int nomor_atom;
    int nomor_massa;
    partikel muatan;
};

atom unsur[200] = {
    {"Hidrogen", "H" , "GAS"  ,  1,  1, { 1,  1,  0}},
    {"Berilium", "Be", "PADAT",  4,  9, { 4,  4,  5}},
    {"Oksigen", "O"  , "GAS"  ,  8, 16, { 8,  8,  8}},
    {"Carbon", "C"   , "PADAT",  6, 12, { 6,  6,  6}},
    {"Nitrogen", "N" , "GAS"  ,  7, 14, { 7,  7,  7}},
    {"Nikel", "N"    , "PADAT", 28, 59, {28, 28, 31}},
    
};

int panjang_array = 6;

void beranda_utama();
void menu_tampilkan_unsur();

void tampilkan_unsur(){
    for (int i = 0; i < panjang_array; i++){
        if (i % 2 == 0){
            cout << "|)| [" << i + 1 << "]" << " " << unsur[i].nama << endl;
            
        } else {
            cout << "|(| [" << i + 1 << "]" << " " << unsur[i].nama << endl;
        }
    }
}

string pilih_wujud_zat(int indeks){
    string wujud_zat_str;
    bool ulang = true;
    while (true){
        try{
            cout << "|(| Wujud Zat                                                                 |)|" << endl;
            cout << "|)| [1] PADAT                                                                 |(|" << endl;
            cout << "|(| [2] CAIR                                                                  |)|" << endl;
            cout << "|)| [3] GAS                                                                   |(|" << endl;
            cout << "|(| [4] PLASMA                                                                |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|)| Pilih wujud zat: ";
            cin >> wujud_zat_str;

            int wujud_zat = stoi(wujud_zat_str);

            if (wujud_zat == 1){
                return "PADAT";

            }else if (wujud_zat == 2){
                return "CAIR";

            }else if (wujud_zat == 3){
                return "GAS";

            } else if (wujud_zat == 4){
                return "PLASMA";

            } else {
                cout << "|(| Pilihan tidak ada                                                         |)|" << endl;
                cout << "|)|                                                                           |(|" << endl;
            }

        } catch (invalid_argument){
            cout << "|(| Harap Masukkan angka yang ada, bukan huruf                                |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;
            continue;
        }
    }
}

int delete_data(int indeks){
    if (indeks > panjang_array){
        panjang_array -= 1;
        cout << "=================================================================================" << endl;
        cout << "======================== BERHASIL MENGHAPUS DATA UNSUR ==========================" << endl;
        cout << "=================================================================================" << endl;
        beranda_utama();
        return 0;

    } else {
        unsur[indeks] = unsur[indeks + 1];
        return delete_data(indeks + 1);
    }
}

void menu_delete(){
    bool ulang = true;
    while (ulang){
        cout << endl;
        cout << endl;
        cout << "=================================================================================" << endl;
        cout << "========================== TAMPILAN DAFTAR UNSUR KIMIA ==========================" << endl;
        cout << "=================================================================================" << endl;
        cout << "|(|                                                                           |)|"<< endl;

        tampilkan_unsur();

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk menghapus data                    |)|" << endl;
            cout << "|)| - Masukkan apa saja selain angka untuk kembali ke tampilan sebelumnya     |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Masukkan: ";
            cin >> pilih;

            for (int indeks = 0; indeks <= panjang_array; indeks++){
                if (indeks == stoi(pilih)){
                    delete_data(indeks - 1);
                }
            }

            cout << "=================================================================================" << endl;
            cout << "=============================== PILIHAN TIDAK ADA ===============================" << endl;
            cout << "=================================================================================" << endl;

        } catch (invalid_argument){
            cout << "=================================================================================" << endl;
            cout << "=================================== KEMBALI =====================================" << endl;
            cout << "=================================================================================" << endl;
            beranda_utama();
        }
    }
}

void update_data(int indeks){
    string nama_atom, singkatan_atom, wujud_zat_str, jumlah_proton_str, jumlah_neutron_str;
    int jumlah_proton, jumlah_neutron;

    cout << endl;
    cout << endl;
    cout << "=================================================================================" << endl;
    cout << "================================ UBAH DATA UNSUR ================================" << endl;
    cout << "=================================================================================" << endl;
    cout << "|(|                                                                           |)|"<< endl;
    cout << "|)|                                                                           |(|" << endl;
    cout << "|(| Nama unsur/atom sebelumnya: " << unsur[indeks - 1].nama << "                                      |)|" << endl;
    cout << "|)| Masukkan nama unsur/atom yang baru: ";
    getline(cin.ignore(), nama_atom);

    unsur[indeks - 1].nama = nama_atom;

    bool ulang = true;
    while (ulang){
        cout << "|(| Singkatan sebelumnya: " << unsur[indeks - 1].singkatan << "                                                   |)|" << endl;
        cout << "|)| Masukkan singkatan atom yang baru: ";
        cin >> singkatan_atom;

        unsur[indeks - 1].singkatan = singkatan_atom;

        int panjang_singkatan_atom = singkatan_atom.length();

        if (panjang_singkatan_atom > 2){
            cout << "|(| Singkatan harus dari 1 sampai 2 huruf                                     |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;

        } else {
            ulang = false;
        }
    }

    cout << "|(|                                                                           |)|" << endl;

    ulang = true;
    while (ulang){
        try{
            cout << "|)| Jumlah proton sebelumnya: " << unsur[indeks - 1].muatan.proton << "                                               |(|" << endl; 
            cout << "|(| Masukkan jumlah proton/muatan positif: ";
            cin >> jumlah_proton_str;

            jumlah_proton = stoi(jumlah_proton_str);

        } catch (invalid_argument){
            cout << "|)| Harap masukkan angka, bukan huruf                                         |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            continue;
        }
        
        if (jumlah_proton < 0){
            cout << "|)| Harap masukkan angka positif                                              |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
        }
        unsur[indeks - 1].muatan.proton = jumlah_proton;
        unsur[indeks - 1].muatan.elektron = jumlah_proton;
        unsur[indeks - 1].nomor_atom = jumlah_proton;
        break;
    }

    ulang = true;
    while (ulang){
        try{
            cout << "|)| Jumlah neutron sebelumnya: " << unsur[indeks - 1].muatan.neutron << "                                              |(|" << endl; 
            cout << "|(| Masukkan jumlah neutron/muatan netral: ";
            cin >> jumlah_neutron_str;

            jumlah_neutron = stoi(jumlah_neutron_str);

        } catch (invalid_argument){
            cout << "|(| Harap masukkan angka, bukan huruf                                         |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;
            continue;
        }
        
        if (jumlah_neutron < 0){
            cout << "|(| Harap masukkan angka positif                                              |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;
        }
        unsur[indeks - 1].muatan.neutron = jumlah_neutron;
        unsur[indeks - 1].nomor_massa = jumlah_neutron + jumlah_proton;

        break;
    }
    
    cout << "|)|                                                                           |(|" << endl;

    cout << "|(| Wujud zat sebelumnya: " << unsur[indeks - 1].wujud << "                                                 |)|" << endl;
    unsur[indeks - 1].wujud = pilih_wujud_zat(indeks);

    cout << "|(|                                                                           |)|" << endl;

    cout << "=================================================================================" << endl;
    cout << "======================== BERHASIL MENGUBAH DATA UNSUR ===========================" << endl;
    cout << "=================================================================================" << endl;
    beranda_utama();
}

void menu_update(){
    bool ulang = true;
    while (ulang){
        cout << endl;
        cout << endl;
        cout << "=================================================================================" << endl;
        cout << "========================== TAMPILAN DAFTAR UNSUR KIMIA ==========================" << endl;
        cout << "=================================================================================" << endl;
        cout << "|(|                                                                           |)|"<< endl;

        tampilkan_unsur();

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk mengubah data                     |)|" << endl;
            cout << "|)| - Masukkan apa saja selain angka untuk kembali ke tampilan sebelumnya     |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Masukkan: ";
            cin >> pilih;

            for (int indeks = 0; indeks <= panjang_array; indeks++){
                if (indeks == stoi(pilih)){
                    update_data(indeks);
                }
            }

            cout << "=================================================================================" << endl;
            cout << "=============================== PILIHAN TIDAK ADA ===============================" << endl;
            cout << "=================================================================================" << endl;

        } catch (invalid_argument){
            cout << "=================================================================================" << endl;
            cout << "=================================== KEMBALI =====================================" << endl;
            cout << "=================================================================================" << endl;
            beranda_utama();
        }
    }
}

void menu_create(){
    string nama_atom, singkatan_atom, wujud_zat_str, jumlah_proton_str, jumlah_neutron_str;
    int jumlah_proton, jumlah_neutron;

    cout << endl;
    cout << endl;
    cout << "=================================================================================" << endl;
    cout << "============================= TAMBAHKAN UNSUR BARU ==============================" << endl;
    cout << "=================================================================================" << endl;
    cout << "|(|                                                                           |)|"<< endl;
    cout << "|)|                                                                           |(|" << endl;
    cout << "|(| Masukkan nama unsur/atom: ";
    getline(cin.ignore(), nama_atom);

    unsur[panjang_array].nama = nama_atom;

    bool ulang = true;
    while (ulang){
        cout << "|)| Masukkan singkatan atom: ";
        cin >> singkatan_atom;

        unsur[panjang_array].singkatan = singkatan_atom;

        int panjang_singkatan_atom = singkatan_atom.length();

        if (panjang_singkatan_atom > 2){
            cout << "|(| Singkatan harus dari 1 sampai 2 huruf" << endl;
            cout << "|)|" << endl;

        } else {
            ulang = false;
        }
    }

    cout << "|(|                                                                           |)|" << endl;

    ulang = true;
    while (ulang){
        try{
            cout << "|)| Masukkan jumlah proton/muatan positif: ";
            cin >> jumlah_proton_str;

            jumlah_proton = stoi(jumlah_proton_str);

        } catch (invalid_argument){
            cout << "|(| Harap masukkan angka, bukan huruf                                         |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;
            continue;
        }
        
        if (jumlah_proton < 0){
            cout << "|(| Harap masukkan angka positif                                              |)|" << endl;
            cout << "|)|                                                                           |(|" << endl;
        }
        unsur[panjang_array].muatan.proton = jumlah_proton;
        unsur[panjang_array].muatan.elektron = jumlah_proton;
        unsur[panjang_array].nomor_atom = jumlah_proton;
        break;
    }

    ulang = true;
    while (ulang){
        try{
            cout << "|(| Masukkan jumlah neutron/muatan netral: ";
            cin >> jumlah_neutron_str;

            jumlah_neutron = stoi(jumlah_neutron_str);

        } catch (invalid_argument){
            cout << "|)| Harap masukkan angka, bukan huruf" << endl;
            cout << "|(|                                                                           |)|" << endl;
            continue;
        }
        
        if (jumlah_neutron < 0){
            cout << "|)| Harap masukkan angka positif                                              |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
        }
        unsur[panjang_array].muatan.neutron = jumlah_neutron;
        unsur[panjang_array].nomor_massa = jumlah_neutron + jumlah_proton;

        break;
    }
    
    cout << "|(|                                                                           |)|" << endl;

    unsur[panjang_array].wujud = pilih_wujud_zat(panjang_array);

    cout << "|(|                                                                           |)|" << endl;

    panjang_array++;

    cout << "=================================================================================" << endl;
    cout << "======================= BERHASIL MENAMBAHKAN UNSUR BARU =========================" << endl;
    cout << "=================================================================================" << endl;
    beranda_utama();
}

void informasi_detail_unsur(int indeks){
    int panjang_singkatan = unsur[indeks - 1].singkatan.length();
    bool ulang = true;
    string pilih;
    while (ulang)
        if (panjang_singkatan == 1){
            cout << endl;
            cout << endl;
            cout << "=================================================================================" << endl;
            cout << "=============================== INFORMASI DETAIL ================================" << endl;
            cout << "=================================================================================" << endl;
            cout << "|(|                                                                           |)|"<< endl;
            cout << "|)|                                                                           |(|"<< endl;

            cout << "|(|                                 ===========                               |)|" << endl;
            cout << "|)|                                 ||       ||                               |(|" << endl;
            cout << "|(|                                 ||   " << unsur[indeks - 1].singkatan << "   ||                               |)|" << endl;
            cout << "|)|                                 ||       ||                               |(|" << endl;
            cout << "|(|                                 ===========                               |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;

            cout << "|(| Nama Atom      : " << unsur[indeks - 1].nama << endl;
            cout << "|)| Singkatan      : " << unsur[indeks - 1].singkatan << endl;
            cout << "|(| Jumlah Proton  : " << unsur[indeks - 1].muatan.proton << endl;
            cout << "|)| Jumlah Elektron: " << unsur[indeks - 1].muatan.elektron << endl;
            cout << "|(| Jumlah Neutron : " << unsur[indeks - 1].muatan.neutron << endl;
            cout << "|)| Nomor Atom     : " << unsur[indeks - 1].nomor_atom << endl;
            cout << "|(| Nomor Massa    : " << unsur[indeks - 1].nomor_massa << endl;
            cout << "|)| Wujud Zat      : " << unsur[indeks - 1].wujud << endl;
            
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| [B] untuk kembali ke tampilan sebelumnya                                  |(|" << endl;
            cout << "|(| Masukkan: ";
            cin >> pilih;

            if (pilih == "B"){
                cout << "=================================================================================" << endl;
                cout << "=================================== KEMBALI =====================================" << endl;
                cout << "=================================================================================" << endl;
                menu_tampilkan_unsur();
                ulang = false;

            } else {
                ulang = true;
            }
            

        } else if (panjang_singkatan == 2){
            cout << endl;
            cout << endl;
            cout << "=================================================================================" << endl;
            cout << "=============================== INFORMASI DETAIL ================================" << endl;
            cout << "=================================================================================" << endl;
            cout << "|(|                                                                           |)|"<< endl;
            cout << "|)|                                                                           |(|"<< endl;

            cout << "|(|                                ============                               |)|" << endl;
            cout << "|)|                                ||        ||                               |(|" << endl;
            cout << "|(|                                ||   " << unsur[indeks - 1].singkatan << "   ||                               |)|" << endl;
            cout << "|)|                                ||        ||                               |(|" << endl;
            cout << "|(|                                ============                               |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;

            cout << "|(| Nama Atom      : " << unsur[indeks - 1].nama << endl;
            cout << "|)| Singkatan      : " << unsur[indeks - 1].singkatan << endl;
            cout << "|(| Jumlah Proton  : " << unsur[indeks - 1].muatan.proton << endl;
            cout << "|)| Jumlah Elektron: " << unsur[indeks - 1].muatan.elektron << endl;
            cout << "|(| Jumlah Neutron : " << unsur[indeks - 1].muatan.neutron << endl;
            cout << "|)| Nomor Atom     : " << unsur[indeks - 1].nomor_atom << endl;
            cout << "|(| Nomor Massa    : " << unsur[indeks - 1].nomor_massa << endl;
            cout << "|)| Wujud Zat      : " << unsur[indeks - 1].wujud << endl;
            
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| [B] untuk kembali ke tampilan sebelumnya                                  |(|" << endl;
            cout << "|(| Masukkan: ";
            cin >> pilih;

            if (pilih == "B"){
                cout << "=================================================================================" << endl;
                cout << "=================================== KEMBALI =====================================" << endl;
                cout << "=================================================================================" << endl;
                menu_tampilkan_unsur();
                ulang = false;

            } else {
                ulang = true;
            }
        }
    
}

void menu_tampilkan_unsur(){
    
    bool ulang = true;
    while (ulang){
        cout << endl;
        cout << endl;
        cout << "=================================================================================" << endl;
        cout << "========================== TAMPILAN DAFTAR UNSUR KIMIA ==========================" << endl;
        cout << "=================================================================================" << endl;
        cout << "|(|                                                                           |)|"<< endl;

        tampilkan_unsur();

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk melihat informasi lebih detail    |)|" << endl;
            cout << "|)| - Masukkan apa saja selain angka untuk kembali ke tampilan sebelumnya     |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Masukkan: ";
            cin >> pilih;

            for (int indeks = 0; indeks <=panjang_array; indeks++){
                if (indeks == stoi(pilih)){
                    cout << "=================================================================================" << endl;
                    cout << "=============================== INFORMASI DETAIL ================================" << endl;
                    cout << "=================================================================================" << endl;
                    informasi_detail_unsur(indeks);
                }
            }

            cout << "=================================================================================" << endl;
            cout << "=============================== PILIHAN TIDAK ADA ===============================" << endl;
            cout << "=================================================================================" << endl;

        } catch (invalid_argument){
            cout << "=================================================================================" << endl;
            cout << "=================================== KEMBALI =====================================" << endl;
            cout << "=================================================================================" << endl;
            beranda_utama();
        }
    }
    
}

void beranda_utama(){
    string pilih;
    
    bool ulang = true;

    while(ulang){
        cout << endl;
        cout << endl;
        cout << "=================================================================================" << endl;
        cout << "================================= BERANDA UTAMA =================================" << endl;
        cout << "=================================================================================" << endl;
        cout << "|(|                                                                           |)|" << endl;
        cout << "|)|                                                                           |(|" << endl;

        cout << "|(| [1] Untuk tampilkan daftar unsur kimia                                    |)|" << endl;
        cout << "|)| [2] Untuk menambah unsur kimia                                            |(|" << endl;
        cout << "|(| [3] Untuk mengubah unsur kimia                                            |)|" << endl;
        cout << "|)| [4] Untuk menghapus unsur kimia                                           |(|" << endl;
        cout << "|(| [EXIT] Untuk keluar dari program                                          |)|" << endl;
        cout << "|)|                                                                           |(|" << endl;
    
        cout << "|(| Masukkan pilihan: ";
        cin >> pilih;
        

        if (pilih == "1"){
            cout << "=================================================================================" << endl;
            cout << "========================== TAMPILKAN DAFTAR UNSUR KIMIA =========================" << endl;
            cout << "=================================================================================" << endl;
            menu_tampilkan_unsur();
            break;
            
        } else if (pilih == "2"){
            cout << "=================================================================================" << endl;
            cout << "============================== MENAMBAH UNSUR KIMIA =============================" << endl;
            cout << "=================================================================================" << endl;
           menu_create();
           break;

        } else if (pilih == "3"){
            cout << "=================================================================================" << endl;
            cout << "============================== MENGUBAH UNSUR KIMIA =============================" << endl;
            cout << "=================================================================================" << endl;
            menu_update();
            break;

        } else if (pilih == "4"){
            cout << "=================================================================================" << endl;
            cout << "============================= MENGHAPUS UNSUR KIMIA =============================" << endl;
            cout << "=================================================================================" << endl;
            menu_delete();
            break;

        } else if (pilih == "EXIT"){
            cout << "=================================================================================" << endl;
            cout << "=============================== ANDA TELAH KELUAR ===============================" << endl;
            cout << "=================================================================================" << endl;
            exit(0);

        } else {
            cout << "=================================================================================" << endl;
            cout << "=============================== PILIHAN TIDAK ADA ===============================" << endl;
            cout << "=================================================================================" << endl;
        }
    }
}

int main(){
    string user = "aldi daffa arisyi";
    string password = "2309106017";
    string user_name, user_nim;

    int ulang = 1;
    while (ulang <= 3){
        cout << "=================================================================================" << endl;
        cout << "=============================== DAFTAR UNSUR KIMIA ==============================" << endl;
        cout << "=================================================================================" << endl;
        cout << "|(|                                                                           |)|" << endl;
        cout << "|)| Login dengan Nama dan NIM sebelum masuk                                   |(|" << endl;
        cout << "|(|                                                                           |)|" << endl;

        cout << "|)| Masukkan nama mahasiswa -> (aldi daffa arisyi): ";
        getline(cin, user_name);
        
        cout << "|(| Masukkan NIM mahasiswa -> (2309106017): ";
        getline(cin, user_nim);

        cout << "|(|                                                                           |)|" << endl;

        if (user_name == user && user_nim == password){
            cout << "=================================================================================" << endl;
            cout << "================================= LOGIN BERHASIL ================================" << endl;
            cout << "=================================================================================" << endl;
            beranda_utama();
            break;

        } else {
            cout << "=================================================================================" << endl;
            cout << "================================== GAGAL LOGIN ==================================" << endl;
            cout << "=================================================================================" << endl;
            cout << endl;
            cout << endl;
            ulang++;
        }
    }

}