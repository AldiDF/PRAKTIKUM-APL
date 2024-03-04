#include <iostream>

using namespace std;

double hitung_kurs(string mata_uang_yang_dikonversi, string mata_uang_pengkonversi){
    double nilai_mata_uang, hasil_kurs;
    double ulang = true;

    while (ulang){
        try{
            string str_nilai_mata_uang;
            cout << "Kurs " << mata_uang_yang_dikonversi << " --> " << mata_uang_pengkonversi << endl;
            cout << "Masukkan nilai mata uang yang dikurskan (dalam " << mata_uang_yang_dikonversi << "): ";
            cin >> str_nilai_mata_uang;
            cout << endl;

            nilai_mata_uang = stoi(str_nilai_mata_uang);

        } catch(invalid_argument){
            cout << "Gagal mengkonversi mata uang" << endl;
            cout << "Harap masukkan angka bukan huruf" <<endl;
            cout << endl;
            continue;
        }

        if (nilai_mata_uang < 0){
            cout << "Gagal mengkonversi mata uang" << endl;
            cout << "Harap masukkan bilangan positif" << endl;
            cout << endl;

        } else {
            if (mata_uang_yang_dikonversi == "Dollar"){
                if (mata_uang_pengkonversi == "Euro"){
                    hasil_kurs = nilai_mata_uang * 0.92;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Rupiah"){
                    hasil_kurs = nilai_mata_uang * 15701.95;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Yen"){    
                    hasil_kurs = nilai_mata_uang * 150.09;
                    return hasil_kurs;
                }

            } else if (mata_uang_yang_dikonversi == "Euro"){
                if (mata_uang_pengkonversi == "Dollar"){
                    hasil_kurs = nilai_mata_uang * 1.09;
                    return hasil_kurs;
    
                } else if (mata_uang_pengkonversi == "Rupiah"){
                    hasil_kurs = nilai_mata_uang * 17043.68;
                    return hasil_kurs;
    
                } else if (mata_uang_pengkonversi == "Yen"){
                    hasil_kurs = nilai_mata_uang * 162.92;
                    return hasil_kurs;
                }

            } else if (mata_uang_yang_dikonversi == "Rupiah"){
                if (mata_uang_pengkonversi == "Dollar"){
                    hasil_kurs = nilai_mata_uang * 0.000064;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Euro"){
                    hasil_kurs = nilai_mata_uang * 0.000059;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Yen"){
                    hasil_kurs = nilai_mata_uang * 0.0096;
                    return hasil_kurs;
                }

            } else if (mata_uang_yang_dikonversi == "Yen"){
                if (mata_uang_pengkonversi == "Dollar"){
                    hasil_kurs = nilai_mata_uang * 0.0067;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Euro"){
                    hasil_kurs = nilai_mata_uang * 0.0061;
                    return hasil_kurs;

                } else if (mata_uang_pengkonversi == "Rupiah"){
                    hasil_kurs = nilai_mata_uang * 104.61;
                    return hasil_kurs;
                }
            }
        }
    }

    return 0;
}

void menu_kurs(string mata_uang_utama, string mata_uang_selain_utama1, string mata_uang_selain_utama2, string mata_uang_selain_utama3){
    int pilihan_kurs;
    bool ulang = true;
    double hasil_kurs;
    
    while (ulang){
        cout << "Pilih  Konversi (Kurs) Untuk Mata Uang " << mata_uang_utama << endl;
        cout << "[1] " << mata_uang_utama << " ke " << mata_uang_selain_utama1 << endl;
        cout << "[2] " << mata_uang_utama << " ke " << mata_uang_selain_utama2 << endl;
        cout << "[3] " << mata_uang_utama << " ke " << mata_uang_selain_utama3 << endl;
        cout << endl;

        try{
            string str_pilihan_kurs;
            cout << "Masukkan angka yang tersedia: ";
            cin >> str_pilihan_kurs;
            cout << endl;

            pilihan_kurs = stoi(str_pilihan_kurs);

        } catch(invalid_argument){
            cout << "Pilihan tidak ada" << endl;
            cout << "Harap masukkan angka yang tersedia" << endl;
            cout << endl;
            continue;
        }

        switch (pilihan_kurs){
        case 1:
        hasil_kurs = hitung_kurs(mata_uang_utama, mata_uang_selain_utama1);
        cout << "Hasil kurs dari " << mata_uang_utama << " ke " << mata_uang_selain_utama1 << " adalah: " << hasil_kurs << " " << mata_uang_selain_utama1 << endl;

        ulang = false;
        break;

        case 2:
        hasil_kurs = hitung_kurs(mata_uang_utama, mata_uang_selain_utama2);
        cout << "Hasil kurs dari " << mata_uang_utama << " ke " << mata_uang_selain_utama2 << " adalah: " << hasil_kurs << " " << mata_uang_selain_utama2<< endl;

        ulang = false;
        break;

        case 3:
        hasil_kurs = hitung_kurs(mata_uang_utama, mata_uang_selain_utama3);
        cout << "Hasil kurs dari " << mata_uang_utama << " ke " << mata_uang_selain_utama3 << " adalah: " << hasil_kurs << " " << mata_uang_selain_utama3 << endl;

        ulang = false;
        break;

        default:
        cout << "Pilihan tidak ada" << endl;
        cout << "Harap masukkan angka yang tersedia" << endl;
        cout << endl;
        break;
        }
    }
}

void menu_mata_uang(){
    int pilihan_mata_uang;
    bool ulang;

    ulang = true;

    while (ulang){
        cout << "Pilih Mata Uang Untuk Dikonversi (kurs)" << endl;
        cout << "[1] Dollar" << endl;
        cout << "[2] Euro" << endl;
        cout << "[3] Rupiah" << endl;
        cout << "[4] Yen" << endl;
        cout << endl;
        
        try{
            string str_pilihan_kurs;
            cout << "Masukkan angka yang tersedia: ";
            cin >> str_pilihan_kurs;
            cout << endl;

            pilihan_mata_uang = stoi(str_pilihan_kurs);

        } catch (invalid_argument){
            cout << "Pilihan tidak ada" << endl;
            cout << "Harap masukkan angka yang tersedia" << endl;
            cout << endl;
            continue;
        }

        switch (pilihan_mata_uang){
            case 1:
            menu_kurs("Dollar", "Euro", "Rupiah", "Yen");
            ulang = false;
            break;

            case 2:
            menu_kurs("Euro", "Dollar", "Rupiah", "Yen");
            ulang = false;
            break;

            case 3:
            menu_kurs("Rupiah", "Dollar", "Euro", "Yen");
            ulang = false;
            break;

            case 4:
            menu_kurs("Yen", "Dollar", "Euro", "Rupiah");
            ulang = false;
            break;

            default:
            cout << "Pilihan tidak ada" << endl;
            cout << "Harap masukkan angka yang tersedia" << endl;
            cout << endl;
            break;
        }
    }
}

int main(){
    string user = "aldi daffa arisyi";
    string password = "2309106017";
    string user_name, user_nim;
    double hasil_kurs;

    cout << "==========================================================================" << endl;
    cout << "========================= PROGRAM KURS MATA UANG =========================" << endl;
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "Login dengan Nama dan NIM sebelum masuk ke menu kurs" << endl;
    cout << endl;

    int ulang = 1;
    while (ulang <= 3){
        cout << "Masukkan nama mahasiswa -> (aldi daffa arisyi): ";
        getline(cin, user_name);
        
        cout << "Masukkan NIM mahasiswa -> (2309106017): ";
        getline(cin, user_nim);

        cout << endl;

        if (user_name == user && user_nim == password){
            menu_mata_uang();
            break;

        } else {
            cout << "Gagal login, harap masukkan Nama dan NIM dengan benar" << endl;
            cout << endl;
            ulang++;
        }
    }

    return 0;
}



