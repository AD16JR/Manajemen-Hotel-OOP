#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Buku {
   public:
    string Judul, Pengarang, tahunTerbit, ISBN, Status;

    Buku(string injudul, string inpengarang, string inisbn, string intahun, string instatus) {
        Buku::Judul = injudul;
        Buku::Pengarang = inpengarang;
        Buku::ISBN = inisbn;
        Buku::tahunTerbit = intahun;
        Buku::Status = instatus;
    }
    string IsiBuku() {
        return "\n" + Judul + " " + Pengarang + " " + ISBN + " " + tahunTerbit + " " + Status;
    }
};
class DBuku {
   public:
    ifstream in;
    ofstream out;
    string fileName;

    DBuku(const char* fileName) {
        DBuku::fileName = fileName;
    }

    void Simpan(Buku data) {
        cout << data.Judul << endl;
        cout << data.Pengarang << endl;
        cout << data.ISBN << endl;
        cout << data.tahunTerbit << endl;
        cout << data.Status << endl;

        DBuku::out.open(DBuku::fileName, ios::app);
        DBuku::out << data.IsiBuku();
        DBuku::out.close();
    }

    void Tampil() {
        DBuku::in.open(DBuku::fileName, ios::in);
        string Judul, Pengarang, tahunTerbit, ISBN, Status;
        int nomor;

        while (!DBuku::in.eof()) {
            DBuku::in >> Judul;
            DBuku::in >> Pengarang;
            DBuku::in >> ISBN;
            DBuku::in >> tahunTerbit;
            DBuku::in >> Status;

            cout << Judul << "\t";
            cout << Pengarang << "\t";
            cout << ISBN << "\t";
            cout << tahunTerbit << "\t";
            cout << Status << endl;

            DBuku::in.close();
        }
    };
};

class Anggota {
   public:
    string Nama, Nomor, Alamat, Pinjam;

    Anggota(string innama, string innomor, string inalamat, string inpinjam) {
        Anggota::Nama = innama;
        Anggota::Nomor = innomor;
        Anggota::Alamat = inalamat;
        Anggota::Pinjam = inpinjam;
    }

    string IsiAnggota() {
        return "\n" + Nama + " " + Nomor + " " + Alamat + " " + Pinjam;
    }
};

class DAnggota {
   public:
    ifstream in;
    ofstream out;
    string fileName;

    DAnggota(const char* fileName) {
        DAnggota::fileName = fileName;
    }

    void Simpan(Anggota data) {
        cout << data.Nama << endl;
        cout << data.Nomor << endl;
        cout << data.Alamat << endl;
        cout << data.Pinjam << endl;

        DAnggota::out.open(DAnggota::fileName, ios::app);
        DAnggota::out << data.IsiAnggota();
        DAnggota::out.close();
    }

    void Tampil() {
        DAnggota::in.open(DAnggota::fileName, ios::in);
        string Nama, Nomor, Alamat, Pinjam;

        while (!DAnggota::in.eof()) {
            DAnggota::in >> Nama;
            DAnggota::in >> Nomor;
            DAnggota::in >> Alamat;
            DAnggota::in >> Pinjam;

            cout << Nama << "\t";
            cout << Nomor << "\t";
            cout << Alamat << "\t";
            cout << Pinjam << endl;
        }
        DAnggota::in.close();
    }
};

int main() {
    int Menu, Pilihan;

    cout << "==== Manajemen Buku ====" << endl;
    cout << "Menu: " << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Mendaftar Anggota" << endl;
    cout << "3. Meminjam Buku" << endl;
    cout << "4. Mengembalikan Buku" << endl;
    cout << "5. Menampilkan Daftar Buku" << endl;
    cout << "6. Informasi Anggota beserta Pinjaman" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> Menu;
    cin.ignore();

    switch (Menu) {
        case 1: {
            string Judul, Pengarang, tahunTerbit, ISBN, Status;

            DBuku info = DBuku("Buku.txt");
            cout << "== Tambah Buku ==\n";
            cout << "Judul : ";
            cin >> Judul;
            cout << "Pengarang : ";
            cin >> Pengarang;
            cout << "ISBN : ";
            cin >> ISBN;
            cout << "Tahun Terbit : ";
            cin >> tahunTerbit;
            cout << "Status : ";
            cin >> Status;
            cout << endl;

            Buku infoBuku = Buku(Judul, Pengarang, ISBN, tahunTerbit, Status);

            info.Simpan(infoBuku);

            cout << "\nDaftar Buku" << endl;
            info.Tampil();
        } break;

        case 2: {
            string Nama, Nomor, Alamat, Pinjam;

            DAnggota info = DAnggota("Anggota.txt");
            cout << "== Tambah Anggota ==\n";
            cout << "Nama : ";
            cin >> Nama;
            cout << "Nomor Anggota : ";
            cin >> Nomor;
            cout << "Alamat : ";
            cin >> Alamat;
            cout << "Pinjam : ";
            cin >> Pinjam;
            cout << endl;

            Anggota infoAnggota = Anggota(Nama, Nomor, Alamat, Pinjam);

            info.Simpan(infoAnggota);

            cout << "\nDaftar Buku" << endl;
            info.Tampil();
        }
    }
    return 0;
}