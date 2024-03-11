#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int panjang_array = 6;
string unsur[200]            = {"Hidrogen", "Berilium", "Oksigen", "Carbon", "Nitrogen", "Nikel"};
string singkatan[200]        = {"H", "Be", "O", "C", "N", "Ni"};
int proton[200]              = {1, 4, 8, 6, 7, 28};
int elektron[200]            = {1, 4, 8, 6, 7, 28};
int nomor_atom[200]          = {1, 4, 8, 6, 7, 28};
int neutron[200]             = {0, 5, 8, 6, 7, 31};
int nomor_massa[200]         = {1, 9, 16, 12, 14, 59};
string wujud[200]            = {"GAS", "PADAT", "GAS", "PADAT", "GAS", "PADAT"};

void beranda_utama();
void menu_tampilkan_unsur();

void delete_data(int indeks){
    for (int i = indeks; i < panjang_array; i++){
        unsur[i - 1] = unsur[i];
        singkatan[i - 1] = singkatan[i];
        proton[i - 1] = proton[i];
        elektron[i - 1] = elektron[i];
        neutron[i - 1] = neutron[i];
        nomor_atom[i - 1] = nomor_atom[i];
        nomor_massa[i - 1] = nomor_massa[i];
    }
    panjang_array -= 1;
    cout << "=================================================================================" << endl;
    cout << "======================== BERHASIL MENGHAPUS DATA UNSUR ==========================" << endl;
    cout << "=================================================================================" << endl;
    beranda_utama();
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

        for (int i = 0; i < panjang_array; i++){
            if (i % 2 == 0){
                cout << "|)| [" << i + 1 << "]" << " " <<unsur[i] << endl;

            } else {
                cout << "|(| [" << i + 1 << "]" << " " <<unsur[i] << endl;
            }
        }

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk menghapus data                    |)|" << endl;
            cout << "|)| - Masukkan apa saja selain untuk kembali ke tampilan sebelumnya           |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Masukkan: ";
            cin >> pilih;

            for (int indeks = 0; indeks <=panjang_array; indeks++){
                if (indeks == stoi(pilih)){
                    delete_data(indeks);
                }
            }

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
    cout << "|(| Nama unsur/atom sebelumnya: " << unsur[indeks - 1] << "                                      |)|" << endl;
    cout << "|)| Masukkan nama unsur/atom yang baru: ";
    getline(cin.ignore(), nama_atom);

    unsur[indeks - 1] = nama_atom;

    bool ulang = true;
    while (ulang){
        cout << "|(| Singkatan sebelumnya: " << singkatan[indeks - 1] << "                                                   |)|" << endl;
        cout << "|)| Masukkan singkatan atom yang baru: ";
        cin >> singkatan_atom;

        singkatan[indeks - 1] = singkatan_atom;

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
            cout << "|)| Jumlah proton sebelumnya: " << proton[indeks - 1] << "                                               |(|" << endl; 
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
        proton[indeks - 1] = jumlah_proton;
        elektron[indeks - 1] = jumlah_proton;
        nomor_atom[indeks - 1] = jumlah_proton;
        break;
    }

    ulang = true;
    while (ulang){
        try{
            cout << "|)| Jumlah neutron sebelumnya: " << neutron[indeks - 1] << "                                              |(|" << endl; 
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
        neutron[indeks - 1] = jumlah_neutron;
        nomor_massa[indeks - 1] = jumlah_neutron + jumlah_proton;

        break;
    }
    
    cout << "|)|                                                                           |(|" << endl;

    ulang = true;
    while (true){
        try{
            cout << "|(| Wujud Zat                                                                 |)|" << endl;
            cout << "|)| [1] PADAT                                                                 |(|" << endl;
            cout << "|(| [2] CAIR                                                                  |)|" << endl;
            cout << "|)| [3] GAS                                                                   |(|" << endl;
            cout << "|(| [4] PLASMA                                                                |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| Wujud zat sebelumnya: " << wujud[indeks - 1] << "                                                 |)|" << endl;
            cout << "|)| Pilih wujud zat: ";
            cin >> wujud_zat_str;

            int wujud_zat = stoi(wujud_zat_str);

            if (wujud_zat == 1){
                wujud[indeks - 1] = "PADAT";
                break;

            }else if (wujud_zat == 2){
                wujud[indeks - 1] = "CAIR";
                break;

            }else if (wujud_zat == 3){
                wujud[indeks - 1] = "GAS";
                break;

            } else if (wujud_zat == 4){
                wujud[indeks - 1] = "PLASMA";
                break;

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

        for (int i = 0; i < panjang_array; i++){
            if (i % 2 == 0){
                cout << "|)| [" << i + 1 << "]" << " " <<unsur[i] << endl;

            } else {
                cout << "|(| [" << i + 1 << "]" << " " <<unsur[i] << endl;
            }
        }

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk mengubah data                     |)|" << endl;
            cout << "|)| - Masukkan apa saja selain untuk kembali ke tampilan sebelumnya           |(|" << endl;
            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Masukkan: ";
            cin >> pilih;

            for (int indeks = 0; indeks <=panjang_array; indeks++){
                if (indeks == stoi(pilih)){
                    update_data(indeks);
                }
            }

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

    unsur[panjang_array] = nama_atom;

    bool ulang = true;
    while (ulang){
        cout << "|)| Masukkan singkatan atom: ";
        cin >> singkatan_atom;

        singkatan[panjang_array] = singkatan_atom;

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
        proton[panjang_array] = jumlah_proton;
        elektron[panjang_array] = jumlah_proton;
        nomor_atom[panjang_array] = jumlah_proton;
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
        neutron[panjang_array] = jumlah_neutron;
        nomor_massa[panjang_array] = jumlah_neutron + jumlah_proton;

        break;
    }
    
    cout << "|(|                                                                           |)|" << endl;

    ulang = true;
    while (true){
        try{
            cout << "|)| Wujud Zat                                                                 |(|" << endl;
            cout << "|(| [1] PADAT                                                                 |)|" << endl;
            cout << "|)| [2] CAIR                                                                  |(|" << endl;
            cout << "|(| [3] GAS                                                                   |)|" << endl;
            cout << "|)| [4] PLASMA                                                                |(|" << endl;

            cout << "|(|                                                                           |)|" << endl;
            cout << "|)| Pilih wujud zat: ";
            cin >> wujud_zat_str;

            int wujud_zat = stoi(wujud_zat_str);

            if (wujud_zat == 1){
                wujud[panjang_array] = "PADAT";
                break;

            }else if (wujud_zat == 2){
                wujud[panjang_array] = "CAIR";
                break;

            }else if (wujud_zat == 3){
                wujud[panjang_array] = "GAS";
                break;

            } else if (wujud_zat == 4){
                wujud[panjang_array] = "PLASMA";
                break;

            } else {
                cout << "|(|Pilihan tidak ada                                                          |)|" << endl;
                cout << "|)|                                                                           |(|" << endl;
            }

        } catch (invalid_argument){
            cout << "|(| Harap Masukkan angka yang ada, bukan huruf" << endl;
            cout << "|)|                                                                           |(|" << endl;
            continue;
        }
    }
    cout << "|(|                                                                           |)|" << endl;

    panjang_array++;

    cout << "=================================================================================" << endl;
    cout << "======================= BERHASIL MENAMBAHKAN UNSUR BARU =========================" << endl;
    cout << "=================================================================================" << endl;
    beranda_utama();
}

void informasi_detail_unsur(int indeks){
    int panjang_singkatan = singkatan[indeks - 1].length();
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
            cout << "|(|                                 ||   " << singkatan[indeks - 1] << "   ||                               |)|" << endl;
            cout << "|)|                                 ||       ||                               |(|" << endl;
            cout << "|(|                                 ===========                               |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;

            cout << "|(| Nama Atom      : " << unsur[indeks - 1] << endl;
            cout << "|)| Singkatan      : " << singkatan[indeks - 1] << endl;
            cout << "|(| Jumlah Proton  : " << proton[indeks - 1] << endl;
            cout << "|)| Jumlah Elektron: " << elektron[indeks - 1] << endl;
            cout << "|(| Jumlah Neutron : " << neutron[indeks - 1] << endl;
            cout << "|)| Nomor Atom     : " << nomor_atom[indeks - 1] << endl;
            cout << "|(| Nomor Massa    : " << nomor_massa[indeks - 1] << endl;
            cout << "|)| Wujud Zat      : " << wujud[indeks - 1] << endl;
            
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
            cout << "|(|                                ||   " << singkatan[indeks - 1] << "   ||                               |)|" << endl;
            cout << "|)|                                ||        ||                               |(|" << endl;
            cout << "|(|                                ============                               |)|" << endl;

            cout << "|)|                                                                           |(|" << endl;

            cout << "|(| Nama Atom      : " << unsur[indeks - 1] << endl;
            cout << "|)| Singkatan      : " << singkatan[indeks - 1] << endl;
            cout << "|(| Jumlah Proton  : " << proton[indeks - 1] << endl;
            cout << "|)| Jumlah Elektron: " << elektron[indeks - 1] << endl;
            cout << "|(| Jumlah Neutron : " << neutron[indeks - 1] << endl;
            cout << "|)| Nomor Atom     : " << nomor_atom[indeks - 1] << endl;
            cout << "|(| Nomor Massa    : " << nomor_massa[indeks - 1] << endl;
            cout << "|)| Wujud Zat      : " << wujud[indeks - 1] << endl;
            
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

        for (int i = 0; i < panjang_array; i++){
            if (i % 2 == 0){
                cout << "|)| [" << i + 1 << "]" << " " <<unsur[i] << endl;

            } else {
                cout << "|(| [" << i + 1 << "]" << " " <<unsur[i] << endl;
            }
        }

        try{
            string pilih;

            cout << "|)|                                                                           |(|" << endl;
            cout << "|(| - Masukkan angka pada unsur kimia untuk melihat informasi lebih detail    |)|" << endl;
            cout << "|)| - Masukkan apa saja selain untuk kembali ke tampilan sebelumnya           |(|" << endl;
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