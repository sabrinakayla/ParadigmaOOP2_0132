#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
private:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    string getNama() { return namaNasabah; }
    double getSaldo() { return saldo; }

    void kurangiSaldo(double jumlah) {
        saldo -= jumlah;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal) 
        : RekeningBank(nama, saldoAwal) {}
    void potongAdmin() override {
        cout << "Rekening Syariah (" << getNama() << "): Bebas biaya admin. Saldo tetap: Rp " << getSaldo() << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal) 
        : RekeningBank(nama, saldoAwal) {}
    void potongAdmin() override {
        kurangiSaldo(15000);
        cout << "Rekening Konvensional (" << getNama() << "): Dipotong Rp 15.000. Saldo sekarang: Rp " << getSaldo() << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal) 
        : RekeningBank(nama, saldoAwal) {}
    void potongAdmin() override {
        if (getSaldo() > 10000000) {
            cout << "Rekening Premium (" << getNama() << "): Saldo di atas 10 Juta (Bebas Admin). Saldo: Rp " << getSaldo() << endl;
        } else {
            kurangiSaldo(50000);
            cout << "Rekening Premium (" << getNama() << "): Saldo <= 10 Juta (Dipotong Rp 50.000). Saldo sekarang: Rp " << getSaldo() << endl;
        }
    }
};

int main() {
    RekeningBank* daftarServerBank[4];
    daftarServerBank[0] = new RekeningSyariah("Kayla", 5000000);
    daftarServerBank[1] = new RekeningKonvensional("Joan", 3000000);
    daftarServerBank[2] = new RekeningPremium("Syifa", 15000000);
    daftarServerBank[3] = new RekeningPremium("Satria", 8000000);
    cout << "=== PROSES OTOMATISASI AKHIR BULAN SERVER BANK ===" << endl;
    
    for (int i = 0; i < 4; i++) {
        daftarServerBank[i]->potongAdmin(); 
    }
    for (int i = 0; i < 4; i++) {
        delete daftarServerBank[i];
    }
    return 0;
}