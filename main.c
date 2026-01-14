#include <stdio.h>
//Ad Soyad   : Neslihan Gürel
//Öğrenci No: 2320171034
//Sertifika : https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=MAZUEJxaVj


//Ders      : Veri Yapıları Ve Algoritmalar
//Konu      : Baloncuk Sıralama ve İkili Arama

void dizi_yazdir(float dizi[], int bas_ind, int son_ind) {
    int i;
    for (i = bas_ind; i <= son_ind; i++) {
        printf(" %.2f", dizi[i]);
    }
    printf("\n");
}

void takas(float *ap, float *bp) {
    float gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

void baloncuk_sirala(float dizi[], int BOYUT) {
    int i, j;
    int takas_oldu = 0;

    // buyukten kucuge siralama
    for (i = 1; i <= BOYUT - 1; i++) {
        for (j = 0; j < BOYUT - 1; j++) {
            if (dizi[j] < dizi[j + 1]) {
                takas(dizi + j, dizi + j + 1);
                takas_oldu = 1;
            }
        }

        if (takas_oldu == 0)
            break;

        printf("iter.%2d: ", i);
        dizi_yazdir(dizi, 0, BOYUT - 1);
        takas_oldu = 0;
    }
}

// buyukten kucuge sirali dizi icin ikili arama
int ikili_arama(float dizi[], int BOYUT, float aranan) {
    int sol = 0, sag = BOYUT - 1, orta;

    while (sol <= sag) {
        orta = (sol + sag) / 2;

        if (dizi[orta] == aranan)
            return orta;
        else if (dizi[orta] < aranan)
            sag = orta - 1;
        else
            sol = orta + 1;
    }
    return -1;
}

int main() {
    float A[] = {1.49, 2.20, 2.13, 1.87, 1.74, 2.00, 1.68};
    int N = sizeof(A) / sizeof(A[0]);
    float aranan;
    int sonuc;

    printf("Dizinin ilk hali:\n");
    dizi_yazdir(A, 0, N - 1);

    printf("\nBaloncuk siralama adimlari:\n");
    baloncuk_sirala(A, N);

    printf("\nSiralanmis dizi:\n");
    dizi_yazdir(A, 0, N - 1);

    printf("\nAranacak degeri giriniz: ");
    scanf("%f", &aranan);

    sonuc = ikili_arama(A, N, aranan);

    if (sonuc != -1)
        printf("Aranan deger dizide bulundu. Indeks: %d\n", sonuc);
    else
        printf("Aranan deger dizide bulunamadi.\n");

    return 0;
}
