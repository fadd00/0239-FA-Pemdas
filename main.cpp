#include <iostream>
using namespace std;

class MasukUniversitas
{
protected: // encapsulasi + abstraksi
    int uangPendaftaran;
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;

public:
    MasukUniversitas()
    {
        uangPendaftaran = 0;
        uangSemesterPertama = 0;
        uangBangunan = 0;
        totalBiaya = 0;
    }

    virtual void namaJalurMasuk()
    {
        cout << "Jalur Masuk " << endl;
    }

    void setUangPendaftaran(int nilai)
    {
        uangPendaftaran = nilai;
    }

    float getUangPendaftaran()
    {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(int nilai)
    {
        uangSemesterPertama = nilai;
    }

    float getUangSemesterPertama()
    {
        return uangSemesterPertama;
    }

    void setUangBangunan(int nilai)
    {
        uangBangunan = nilai;
    }

    float getUangBangunan()
    {
        return uangBangunan;
    }

    virtual void hitungTotalBiaya()
    {
        totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
    }

    float getTotalBiaya()
    {
        return totalBiaya;
    }

    virtual void tampilkanTotalBiaya() // membuat bentuk func dengan class nya
    {
        cout << "Total Biaya: " << totalBiaya << endl;

        if (totalBiaya >= 50000)
        {
            cout << "Kategori: Mahal" << endl;
            cout << "Rekomendasi: Tidak direkomendasikan" << endl;
        }
        else if (totalBiaya >= 25000 && totalBiaya < 50000)
        {
            cout << "Kategori: Sedang" << endl;
            cout << "Rekomendasi: Dipertimbangkan" << endl;
        }
        else
        {
            cout << "Kategori: Murah" << endl;
            cout << "Rekomendasi: Direkomendasikan" << endl;
        }
    }

    virtual void input()
    {
        cout << "Masukkan uang pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: ";
        cin >> uangSemesterPertama;
        cout << "masukan uang bangunan: ";
        cin >> uangBangunan;
        hitungTotalBiaya();
        tampilkanTotalBiaya();
    }
};

class SNBT : public MasukUniversitas // innharitance
{
public:
    void namaJalurMasuk() override // untuk override namaJalurMasuk kedalam SNBT
    {
        cout << "SNBT (Seleksi Nasional Berdasarkan Tes)" << endl;
    }

    void hitungTotalBiaya() override
    {
        totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
    }
};

class SNBP : public MasukUniversitas
{
public:
    void namaJalurMasuk() override
    {
        cout << "SNBP (Seleksi Nasional Berdasarkan Prestasi)" << endl;
    }

    void input() override
    {
        MasukUniversitas::input();
        hitungTotalBiaya();
        tampilkanTotalBiaya();
    }

    void hitungTotalBiaya() override
    {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }
};

int main()
{
    int pilihanJalur, pilihanMenu;

    do
    {
        cout << "Pilih Jalur Masuk:" << endl;
        cout << "1. SNBT" << endl;
        cout << "2. SNBP" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihanJalur;

        if (pilihanJalur == 1)
        {
            SNBT snbt;
            snbt.namaJalurMasuk();
            snbt.input();
        }
        else if (pilihanJalur == 2)
        {
            SNBP snbp;
            snbp.namaJalurMasuk();
            snbp.input();
        }
        else if (pilihanJalur == 3)
        {
            cout << "Keluar dari program." << endl;
        }
        else
        {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihanJalur != 3);

    return 0;
}