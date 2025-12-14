#ifndef KONTAK_H
#define KONTAK_H
#include <string>
using namespace std;


class Kontak {
public:
string owner, id, nama, nomor, email, kategori;


Kontak(string o="", string i="", string n="", string no="", string e="", string k="");
string toCSV() const;
void tampil() const;
};


#endif