#include "Sistem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

string Sistem::pilihKategori() {
    int p;
    cout << "1. Teman\n2. Keluarga\n3. Bisnis\nPilih: ";
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (p == 1) return "Teman";
    if (p == 2) return "Keluarga";
    if (p == 3) return "Bisnis";
    return "Lainnya";
}

void Sistem::load() {
    users.clear();
    kontak.clear();

    ifstream fu("users.csv");
    ifstream fk("contacts.csv");
    string line;

    if (fu.is_open()) {
        getline(fu, line);
        while (getline(fu, line)) {
            string u, p;
            stringstream ss(line);
            getline(ss, u, ',');
            getline(ss, p, ',');
            users.push_back({u, p});
        }
        fu.close();
    }

    if (fk.is_open()) {
        getline(fk, line);
        while (getline(fk, line)) {
            string o,i,n,no,e,k;
            stringstream ss(line);
            getline(ss,o,',');
            getline(ss,i,',');
            getline(ss,n,',');
            getline(ss,no,',');
            getline(ss,e,',');
            getline(ss,k,',');
            kontak.push_back(Kontak(o,i,n,no,e,k));
        }
        fk.close();
    }
}

void Sistem::save() {
    ofstream fu("users.csv");
    ofstream fk("contacts.csv");

    fu << "username,password\n";
    for (auto &u : users)
        fu << u.first << "," << u.second << "\n";

    fk << "owner,id,nama,nomor,email,kategori\n";
    for (auto &k : kontak)
        fk << k.toCSV() << "\n";
}

void Sistem::daftar() {
    string u, p;
    cout << "Username: ";
    getline(cin, u);
    cout << "Password: ";
    getline(cin, p);
    users.push_back({u, p});
    save();
    cout << "Akun berhasil dibuat.\n";
}

bool Sistem::login() {
    string u, p;
    cout << "Username: ";
    getline(cin, u);
    cout << "Password: ";
    getline(cin, p);

    for (auto &x : users) {
        if (x.first == u && x.second == p) {
            userAktif = u;
            cout << "Login berhasil.\n";
            return true;
        }
    }
    cout << "Login gagal.\n";
    return false;
}

void Sistem::tambah() {
    string id, n, no, e;
    cout << "ID Kontak: ";
    getline(cin, id);
    cout << "Nama: ";
    getline(cin, n);
    cout << "Nomor: ";
    getline(cin, no);
    cout << "Email: ";
    getline(cin, e);

    string k = pilihKategori();
    kontak.push_back(Kontak(userAktif, id, n, no, e, k));
    save();
}

void Sistem::tampilSemua() {
    cout << "\n--- SEMUA KONTAK ---\n";
    for (auto &k : kontak) {
        if (k.owner == userAktif)
            k.tampil();
    }
}

void Sistem::editKontak() {
    string id;
    cout << "ID Kontak: ";
    getline(cin, id);

    for (auto &k : kontak) {
        if (k.owner == userAktif && k.id == id) {
            cout << "Nama baru: ";
            getline(cin, k.nama);
            cout << "Nomor baru: ";
            getline(cin, k.nomor);
            cout << "Email baru: ";
            getline(cin, k.email);
            k.kategori = pilihKategori();
            save();
            return;
        }
    }
    cout << "Kontak tidak ditemukan.\n";
}

void Sistem::hapusKontak() {
    string id;
    cout << "ID Kontak: ";
    getline(cin, id);

    for (auto it = kontak.begin(); it != kontak.end(); ++it) {
        if (it->owner == userAktif && it->id == id) {
            kontak.erase(it);
            save();
            cout << "Kontak dihapus.\n";
            return;
        }
    }
    cout << "Kontak tidak ditemukan.\n";
}

void Sistem::filterKategori() {
    string kat = pilihKategori();
    for (auto &k : kontak) {
        if (k.owner == userAktif && k.kategori == kat)
            k.tampil();
    }
}
