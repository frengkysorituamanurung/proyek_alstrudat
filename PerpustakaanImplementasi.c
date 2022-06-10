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

void cetakBuku(dataBuku *data)
{
    while (data != NULL)
    {
        printf("ISBN\t: %s\nJudul\t: %s\nJenis\t: %s\nAuthor\t: %s\nJumlah\t: %d\nNIDN\t: %s\n\n", data->ISBN, data->JudulBuku, data->JenisBuku, data->Author, data->jumlah, data->NIDN);
        data = data->alamat;
    }
}

void cetakDosen(dataDosen *data)
{
    while (data != NULL)
    {
        printf("NIDN\t\t: %s\nNama Dosen\t: %s\nNomor Telepon\t: %s\n\n", data->NIDN, data->nama, data->no_telp);
        data = data->alamat;
    }
}

void cariBuku(dataBuku *data, char *cari)
{
    while (data != NULL)
    {
        if (strcmp(data->ISBN, cari) == 0)
        {
            printf("ISBN\t: %s\nJudul\t: %s\nJenis\t: %s\nAuthor\t: %s\nJumlah\t: %d\nNIDN\t: %s\n", data->ISBN, data->JudulBuku, data->JenisBuku, data->Author, data->jumlah, data->NIDN);
        }
        data = data->alamat;
    }
}

void cariNIDN(dataDosen *data, dataBuku *isi, char *cari)
{
    while (data != NULL)
    {
        if (strcmp(data->NIDN, cari) == 0)
        {
            printf("NIDN\t\t\t: %s\nNama Dosen\t\t: %s\nNomor Telepon\t\t: %s\n", data->NIDN, data->nama, data->no_telp);
            printf("Jumlah buku yang di donasi\t: %d\n", isi->jumlah);
        }
        data = data->alamat;
    }
}

dataDosen *tambahDataBaruDosen(dataDosen **nodeRef, dataDosen *data)
{
    dataDosen *DataDosen = (dataDosen *)malloc(sizeof(dataDosen) * 1);
    strcpy(DataDosen->NIDN, data->NIDN);
    strcpy(DataDosen->nama, data->nama);
    strcpy(DataDosen->no_telp, data->no_telp);

    DataDosen->alamat = (*nodeRef);
    (*nodeRef) = DataDosen;
    return DataDosen;
}

dataDosen *tambahNextDataDosen(dataDosen **nodeRef, dataDosen *data)
{
    dataDosen *nextData = (dataDosen *)malloc(sizeof(dataDosen) * 1);
    dataDosen *last = *nodeRef;

    nextData->alamat = NULL;

    strcpy(nextData->NIDN, data->NIDN);
    strcpy(nextData->nama, data->nama);
    strcpy(nextData->no_telp, data->no_telp);

    if (*nodeRef == NULL)
    {
        *nodeRef = nextData;
        return 0;
    }

    while (last->alamat != NULL)
    {
        last = last->alamat;
    }

    last->alamat = nextData;
}

dataBuku *tambahDataBaruBuku(dataBuku **nodeRef, dataBuku *data)
{
    dataBuku *DataBuku = (dataBuku *)malloc(sizeof(dataBuku) * 1);
    strcpy(DataBuku->ISBN, data->ISBN);
    strcpy(DataBuku->JudulBuku, data->JudulBuku);
    strcpy(DataBuku->JenisBuku, data->JenisBuku);
    strcpy(DataBuku->Author, data->Author);
    strcpy(DataBuku->NIDN, data->NIDN);
    DataBuku->jumlah = data->jumlah;

    DataBuku->alamat = (*nodeRef);
    (*nodeRef) = DataBuku;
    return DataBuku;
}

dataBuku *tambahNextDataBuku(dataBuku **nodeRef, dataBuku *data)
{
    dataBuku *next_node = malloc(sizeof(dataBuku) * 1);
    dataBuku *last = *nodeRef;

    next_node->alamat = NULL;

    strcpy(next_node->ISBN, data->ISBN);
    strcpy(next_node->JudulBuku, data->JudulBuku);
    strcpy(next_node->JenisBuku, data->JenisBuku);
    strcpy(next_node->Author, data->Author);
    strcpy(next_node->NIDN, data->NIDN);
    next_node->jumlah = data->jumlah;

    if (*nodeRef == NULL)
    {
        *nodeRef = next_node;
        return 0;
    }

    while (last->alamat != NULL)
    {
        last = last->alamat;
    }

    last->alamat = next_node;
}

char *ambilNIDN(dataDosen *data, int pilihan)
{
    int i = 1;
    while (data != NULL)
    {
        if (i == pilihan)
        {
            return data->NIDN;
        }
        else
        {
            i++;
            data = data->alamat;
        }
    }
}
