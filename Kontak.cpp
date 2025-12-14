#include "Kontak.h"
#include <iostream>


Kontak::Kontak(string o, string i, string n, string no, string e, string k)
: owner(o), id(i), nama(n), nomor(no), email(e), kategori(k) {}


string Kontak::toCSV() const {
return owner + "," + id + "," + nama + "," + nomor + "," + email + "," + kategori;
}


void Kontak::tampil() const {
cout << "ID: " << id
<< " | Nama: " << nama
<< " | Nomor: " << nomor
<< " | Email: " << email
<< " | Kategori: " << kategori << endl;
}