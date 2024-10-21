#include <iostream>
#include <string>
using namespace std;

struct date {
    int date;
    string checkNullDate; // berfungsi untuk menyimpan dalam teks agar bisa digunakan untuk validasi input kosong
};

struct zodiak {
    string zodiak;
    string sifatZodiak;
    int tglAwal;
    int bulanAwal;
    int tglAkhir;
    int bulanAkhir;
};

// function untuk mengisi tanggal lahir
void isiTanggalLahir (date dt[], int dateF){
    cout << "Masukkan tanggal lahir anda : " << endl;

    for (int i = 0; i < dateF; i++){
        // perkondisian pertama untuk memvalidasi tanggal jika input kosong atau input lebih dari 31 atau kurang dari 0
        if (i == 0){
            do {
                do {
                    cout << "Tanggal lahir (dd)" << endl;
                    cout << "=> ";
                    getline(cin, dt[i].checkNullDate);

                    if (dt[i].checkNullDate == ""){ // pengecekan jika input kosong
                        cout << "Mohon isi tanggal lahir!" << endl << endl;
                    }
                } while (dt[i].checkNullDate == "");

                dt[i].date = stoi(dt[i].checkNullDate); // jika input tidak kosong, maka konversi string array date index ke-0 menjadi integer

                if (dt[0].date > 31 || dt[0].date < 0){ // pengecekan input lebih dari 31 atau kurang dari 0
                    cout << "Tanggal tidak valid! Mohon input ulang" << endl << endl;
                }
            } while (dt[0].date > 31 || dt[0].date < 0);
        // perkondisian kedua untuk memvalidasi bulan jika input kosong atau input lebih dari 12 atau kurang dari 0
        } else if (i == 1){
            do {
                do {
                    cout << "Bulan lahir (MM)" << endl;
                    cout << "=> ";
                    getline(cin, dt[i].checkNullDate);

                    if (dt[i].checkNullDate == ""){
                        cout << "Mohon isi bulan lahir!" << endl << endl;
                    }
                } while (dt[i].checkNullDate == "");

                dt[i].date = stoi(dt[i].checkNullDate);

                if (dt[1].date > 12 || dt[1].date < 0){
                    cout << "Bulan tidak valid! Mohon input ulang" << endl << endl;
                }
            } while (dt[1].date > 12 || dt[1].date < 0);
        // perkondisian ketiga untuk memvalidasi tahun jika input kosong atau input lebih dari 2050 atau kurang dari 1000
        } else if (i == 2){
            do {
                do {
                    cout << "Tahun lahir (yyyy)" << endl;
                    cout << "=> ";
                    getline(cin, dt[i].checkNullDate);

                    if (dt[i].checkNullDate == ""){
                        cout << "Mohon isi tahun lahir!" << endl << endl;
                    }
                } while (dt[i].checkNullDate == "");

                dt[i].date = stoi(dt[i].checkNullDate);

                if (dt[2].date > 2050 || dt[2].date < 1000){
                    cout << "Tahun tidak valid! Mohon input ulang" << endl << endl;
                }
            } while (dt[2].date > 2050 || dt[2].date < 1000);
        }
    }
}

// function untuk menampilkan zodiak berdasarkan input tanggal lahir
void tampilZodiak (date dt[], zodiak zd[], int jumZodiak, const string namaBulan[]){
    for (int i = 0; i < jumZodiak; i++){ // perulangan sampai Jumlah Zodiak = 12
        for (int j = 0; j < 1; j++) { // perulangan hanya diulang satu kali untuk pengecekan langsung array date

            /* perkondisian jika tanggal lahir >= tanggal awal zodiak dan bulan lahir sama dengan bulan awal zodiak
                atau tanggal lahir <= tanggal akhir zodiak dan bulan lahir sama dngan bulan akhir zodiak*/
            if (dt[j].date >= zd[i].tglAwal && dt[j+1].date == zd[i].bulanAwal || dt[j].date <= zd[i].tglAkhir && dt[j+1].date == zd[i].bulanAkhir) {
                // perkondisian jika tanggal dan bulan atau tanggal atau bulan kurang dari 10, maka ditambahkan angka 0 sebelum tanggal atau bulan
                if (dt[j].date < 10 && dt[j+1].date < 10){
                    cout << " \nTanggal Lahir        : 0" << dt[j].date << "-0" << dt[j+1].date << "-" << dt[j+2].date << endl;
                } else if (dt[j].date < 10){
                    cout << " \nTanggal Lahir        : 0" << dt[j].date << "-" << dt[j+1].date << "-" << dt[j+2].date << endl;
                } else if (dt[j+1].date < 10){
                    cout << " \nTanggal Lahir        : " << dt[j].date << "-0" << dt[j+1].date << "-" << dt[j+2].date << endl;
                } else {
                    cout << " \nTanggal Lahir        : " << dt[j].date << "-" << dt[j+1].date << "-" << dt[j+2].date << endl;
                }

                cout << "Zodiak Anda          : " << zd[i].zodiak << endl;
                cout << "Anda mempunyai sifat : \n" << zd[i].sifatZodiak << endl << endl;
                cout << zd[i].zodiak << " : " << zd[i].tglAwal << " " << namaBulan[zd[i].bulanAwal - 1] << " - " << zd[i].tglAkhir << " " << namaBulan[zd[i].bulanAkhir - 1] << endl;
            }
        }
    }
}

const int dateFormat = 3, jmlZodiak = 12;
const string namaBulan[12] = {"Januari", "Februari", "Maret",
                                "April", "Mei", "Juni",
                                "Juli", "Agustus", "September",
                                "Oktober", "November", "Desember"};

int main(){
    string pilih;
    date dt[dateFormat]; // array struct dari date di set 3 karena untuk format tanggal, yaitu tanggal-bulan-tahun
    zodiak zd[jmlZodiak] = {{"Aries", "Penuh semangat, berani, suka berpetualang, mempunyai jiwa leadership kuat.\nSerta ambisius juga suka dengan tantangan baru.", 21, 3, 19, 4},
                     {"Taurus", "Stabil, tekun, praktis, tabah, dan sabar.", 20, 4, 20, 5},
                     {"Gemini", "Dapat beradaptasi, bersosialisasi, dan berinteraksi yang tinggi.", 21, 5, 20, 6},
                     {"Cancer", "Penuh kasih sayang, loyal, emosional, dan sensitif.", 21, 6, 22, 7},
                     {"Leo", "Percaya diri, karismatik, dan jiwa leadership yang kuat.", 23, 7, 22, 8},
                     {"Virgo", "Praktis, analitis, perfeksionis, suka membantu orang lain.\nSangat detail-oriented dan menjaga segala sesuatunya tetap terorganisir.", 23, 8, 22, 9},
                     {"Libra", "Adil, diplomatis, memiliki rasa estetika yang tinggi, dan cinta damai." , 23, 9, 22, 10},
                     {"Scorpio", "Energik, misterius, dan bertekad kuat. \nBerintuisi tajam yang sangat intens dan penuh dengan misteri.", 23, 10, 21, 11},
                     {"Sagitarius", "Optimis, suka kebebasan, dan pengetahuan baru.\nJuga bersifat terbuka dan jujur dalam setiap aspek kehidupan.", 22, 11, 21, 12},
                     {"Capricorn", "Disiplin, ambisius, dan bertanggung jawab.\nSangat fokus pada tujuan hidupnya, sangat menghargai waktu, dan pantang menyerah.", 22, 12, 19, 1},
                     {"Aquarius", "Inovatif, visioner, mandiri, dan sangat menghargai kebebasan.", 20, 1, 18, 2},
                     {"Pisces", "Intuitif, artistik, dan empatiknya yang tinggi.\nMemiliki kedalaman emosional yang besar dan sangat peka terhadap perasaan orang lain.", 19, 2, 20, 3}};

    // perulangan jika ingin input tanggal lahir kembali ke awal
    do {
        isiTanggalLahir(dt, dateFormat);

        tampilZodiak(dt, zd, jmlZodiak, namaBulan);

        do {
            do {
                cout << endl << "Apakah anda ingin mengulangi lagi? (y/n) : ";
                getline(cin, pilih);
                if (pilih == ""){
                    cout << "Input kosong!" << endl;
                }
            } while (pilih == "");
            if (pilih != "y" && pilih != "Y" && pilih != "n" && pilih != "N"){
                cout << "Input tidak valid!" << endl;
            }
        } while (pilih != "y" && pilih != "Y" && pilih != "n" && pilih != "N");
        cout << endl;
    } while (pilih == "y" || pilih == "Y");

    cout << "Anda keluar dari program. Terima kasih banyak" << endl;

    return 0;
}
