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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PerpustakaanHeader.h"

int main()
{
    dataBuku *Buku1 = (dataBuku *)malloc(sizeof(dataBuku) * 1);
    dataBuku *Buku2 = (dataBuku *)malloc(sizeof(dataBuku) * 1);
    dataDosen *Dosen1 = (dataDosen *)malloc(sizeof(dataDosen) * 1);
    dataDosen *Dosen2 = (dataDosen *)malloc(sizeof(dataDosen) * 1);
    int opsi, pilih_dosen = 1, batas, i;
    char NIDN[20];

    strcpy(Buku1->ISBN, "BOOK56");
    strcpy(Buku1->JudulBuku, "Data Visualization Made Simple");
    strcpy(Buku1->JenisBuku, "Technology");
    strcpy(Buku1->Author, "Kristen Sosulski");
    strcpy(Buku1->NIDN, "532636145");
    Buku1->jumlah = 2;
    Buku1->alamat = Buku2;

    strcpy(Buku2->ISBN, "BOOK10");
    strcpy(Buku2->JudulBuku, "The Soul of a New Machine");
    strcpy(Buku2->JenisBuku, "Technology");
    strcpy(Buku2->Author, "Tracy Kidder");
    strcpy(Buku2->NIDN, "76294176");
    Buku2->jumlah = 2;
    Buku2->alamat = NULL;

    strcpy(Dosen1->NIDN, "DOSEN14");
    strcpy(Dosen1->nama, "Andrew Thomas");
    strcpy(Dosen1->no_telp, "08216741432");
    Dosen1->alamat = Dosen2;

    strcpy(Dosen2->NIDN, "DOSEN64");
    strcpy(Dosen2->nama, "Windarto Purwanto");
    strcpy(Dosen2->no_telp, "082198655241");
    Dosen2->alamat = NULL;

    printf("SELAMAT DATANG DI PERPUSTAKAAN IT DEL\n");
    printf("------------------menu------------------\n");

    printf("1. Tampilkan Semua Buku\n");
    printf("2. Tampilkan Data Dosen\n");
    printf("3. Cari Buku Berdasarkan ISBN\n");
    printf("4. Cari Buku Berdasarkan NIDN\n");
    printf("5. Tambahkan Buku\n");
    printf("6. Tambahkan Dosen\n");
    printf("7. Keluar\n");

    do
    {
        printf("\nPILIH MENU\t: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            printf("\n------DATA BUKU------\n");
            cetakBuku(Buku1);
            printf("\n");
            break;
        case 2:
            printf("\n------DATA DOSEN------\n");
            cetakDosen(Dosen1);
            printf("\n");
            break;
        case 3:
            printf("\nCARI BUKU BERDASARKAN ISBN\n");
            char cari[100];
            printf("Masukkan ISBN: ");
            scanf("%s", &cari);
            cariBuku(Buku1, cari);
            printf("\n");
            break;
        case 4:
            printf("\nCARI JUMLAH BUKU YANG DIDONASIKAN DOSEN\n");
            char search[100];
            printf("Masukkan NIDN: ");
            scanf("%s", &search);
            cariNIDN(Dosen1, Buku1, search);
            printf("\n");
            break;
        case 5:
            printf("TAMBAH DATA BUKU\n");
            printf("Data Dosen\n");
            cetakDosen(Dosen1);
            if (Dosen1 == NULL)
            {
                printf("Data Dosen masih kosong!\n");
                break;
            }
            else
            {
                printf("Pilih dosen yang ingin donasi buku: ");
                scanf("%i", &pilih_dosen);
                if (ambilNIDN(Dosen1, pilih_dosen) == NULL)
                {
                    break;
                }
                else
                {
                    strcpy(NIDN, ambilNIDN(Dosen1, pilih_dosen));
                }
            }
            printf("Masukkan Jumlah Data Buku:");
            scanf(" %d", &batas);

            for (i = 1; i <= batas; i++)
            {
                dataBuku *DataBuku = malloc(sizeof(dataBuku) * 1);
                printf("Masukkan ISBN %d: ", i);
                scanf("%s", DataBuku->ISBN);
                getchar();
                printf("Masukkan Judul Buku %d: ", i);
                scanf("%s", DataBuku->JudulBuku);
                getchar();
                printf("Masukkan Jenis Buku %d: ", i);
                scanf("%s", DataBuku->JenisBuku);
                getchar();
                printf("Masukkan Author %d: ", i);
                scanf("%s", DataBuku->Author);
                getchar();
                strcpy(DataBuku->NIDN, NIDN);
                printf("Masukkan Jumlah %d: ", i);
                scanf("%d", &DataBuku->jumlah);

                if (Buku1 == NULL)
                {
                    tambahDataBaruBuku(&Buku1, DataBuku);
                }
                else
                {
                    tambahNextDataBuku(&Buku1, DataBuku);
                }
            }
            printf("\n");
            cetakBuku(Buku1);
            break;
        case 6:
            printf("====Tambah DATA Dosen====\n");
            printf("Masukkan Jumlah Data Dosen:");
            scanf("%i", &batas);

            for (i = 1; i <= batas; i++)
            {
                dataDosen *DataDosen = malloc(sizeof(dataDosen) * 1);
                printf("Masukkan NIDN %d:", i);
                scanf("%s", DataDosen->NIDN);
                getchar();
                printf("Masukkan Nama Dosen %d:", i);
                scanf("%[^\n]s", DataDosen->nama);
                getchar();
                printf("Masukkan Nomor Telepon %d:", i);
                scanf("%s", DataDosen->no_telp);
                getchar();
                if (Dosen1 == NULL)
                {
                    tambahDataBaruDosen(&Dosen1, DataDosen);
                }
                else
                {
                    tambahNextDataDosen(&Dosen1, DataDosen);
                }
            }
            printf("\n");
            cetakDosen(Dosen1);
            break;
        case 7:
            printf("Anda keluar dari aplikasi\n");
            break;
        default:
            break;
        }

    } while (opsi != 0);

    return 1;
}
