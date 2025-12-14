#include <iostream>
#include <limits>
#include "Sistem.h"
using namespace std;


int main() {
Sistem s;
s.load();


int p;
do {
cout << "\n1. Login\n2. Daftar\n3. Keluar\nPilih: ";
cin >> p;
cin.ignore(numeric_limits<streamsize>::max(), '\n');


if (p==2) s.daftar();
else if (p==1 && s.login()) {
int m;
do {
cout << "\n1.Tambah\n2.Lihat Semua\n3.Edit\n4.Hapus\n5.Filter Kategori\n6.Logout\nPilih: ";
cin >> m;
cin.ignore(numeric_limits<streamsize>::max(), '\n');


if (m==1) s.tambah();
else if (m==2) s.tampilSemua();
else if (m==3) s.editKontak();
else if (m==4) s.hapusKontak();
else if (m==5) s.filterKategori();
} while (m!=6);
}
} while (p!=3);


return 0;
}