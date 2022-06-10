// # -------------------------------------------------#
// #¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤#
// #	¤                                            ¤   #
// #	¤              Proyek Alstrudat              ¤   #
// #	¤--------------------------------------------¤   #
// #	¤              Kelompok 9                    ¤   #
// #	¤--------------------------------------------¤   #
// #	¤                                            ¤   #
// #	¤   13321005_Frengky Soritua Manurung        ¤   #
// #	¤   13321025_Jesica Panjaitan                ¤   #
// #	¤  	13321028_Josua Raja Pratam Marbun		 ¤   #
// #	¤  	13321049_Trisna Paulina Lumban Raja		 ¤   #
// #	¤   13321051_Ruth Pratiwi Simamora           ¤   #
// #	¤--------------------------------------------¤   #
// #	¤    Topik Perpustakaan IT DEL               ¤   #
// #	¤                                            ¤   #
// #	¤                                            ¤   #
// #¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤#
// # -------------------------------------------------#

typedef struct DataBuku dataBuku;
struct DataBuku
{
    char ISBN[10];
    char JudulBuku[100];
    char JenisBuku[100];
    char Author[100];
    char NIDN[20];
    int jumlah;
    dataBuku *alamat;
};

typedef struct DataDosen dataDosen;
struct DataDosen
{
    char NIDN[20];
    char nama[50];
    char no_telp[15];
    dataDosen *alamat;
};

void cetakBuku(dataBuku *data);
void cetakDosen(dataDosen *data);
void cariBuku(dataBuku *data, char *cari);
void cariNIDN(dataDosen *data, dataBuku *isi, char *cari);
dataDosen *tambahDataBaruDosen(dataDosen **nodeRef, dataDosen *data);
dataDosen *tambahNextDataDosen(dataDosen **nodeRef, dataDosen *data);
dataBuku *tambahDataBaruBuku(dataBuku **nodeRef, dataBuku *data);
dataBuku *tambahNextDataBuku(dataBuku **nodeRef, dataBuku *data);
char *ambilNIDN(dataDosen *data, int pilihan);
