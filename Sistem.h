#ifndef SISTEM_H
#define SISTEM_H

#include <vector>
#include <string>
#include <utility>
#include "Kontak.h"
using namespace std;

class Sistem {
private:
    vector<pair<string,string>> users;
    vector<Kontak> kontak;
    string userAktif;

    string pilihKategori();

public:
    void load();
    void save();

    void daftar();
    bool login();

    void tambah();
    void tampilSemua();
    void editKontak();
    void hapusKontak();
    void filterKategori();
};

#endif
