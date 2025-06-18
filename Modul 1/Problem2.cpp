#include <iostream>
using namespace std;
struct kendaraan{
    char plat[10]    = "DA1234MK";
    char jenis[10]   = "RUSH";
    char pemilik[20] = "Andika Hartanto";
    char alamat[20]  = "Jl. Kayu Tangi 1";
    char kota[20]    = "Banjarmasin";
};
int main(){
    kendaraan mobil;

    cout <<"Plat Nomor Kendaraan : " << mobil.plat << endl;
    cout <<"Jenis Kendaraan      : " << mobil.jenis << endl;
    cout <<"Nama Pemilik         : " << mobil.pemilik << endl;
    cout <<"Alamat               : " << mobil.alamat << endl;
    cout <<"Kota                 : " << mobil.kota << endl;
    
    return 0;
}