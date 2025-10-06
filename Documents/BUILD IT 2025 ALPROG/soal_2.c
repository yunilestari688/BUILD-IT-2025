#include <stdio.h>

int main() {
    // Mendeklarasikan variabel N untuk menyimpan tinggi pohon
    int N;

    // Membaca input dari pengguna
    scanf("%d", &N);

    // Menghitung lebar maksimum dari bagian daun pohon
    // Lebar ini ada di baris ke-(N-1)
    int maxWidth = 2 * (N - 1) - 1;

    // --- Loop untuk mencetak DAUN POHON ---
    // Loop berjalan dari baris 1 hingga N-1
    for (int i = 1; i < N; i++) {
        // Menghitung jumlah bintang untuk baris saat ini
        int stars = 2 * i - 1;
        // Menghitung jumlah spasi yang dibutuhkan di sisi kiri untuk membuat pola rata tengah
        int spaces = (maxWidth - stars) / 2;

        // Loop untuk mencetak spasi di sebelah kiri
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Loop untuk mencetak bintang
        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        // Pindah ke baris baru setelah satu baris selesai
        printf("\n");
    }

    // --- Mencetak BATANG POHON ---
    // Menghitung jumlah spasi untuk batang agar berada di tengah
    int trunkSpaces = (maxWidth - 1) / 2;

    // Loop untuk mencetak spasi di sebelah kiri batang
    for (int i = 0; i < trunkSpaces; i++) {
        printf(" ");
    }

    // Mencetak batang (satu bintang) dan pindah ke baris baru
    printf("*\n");

    return 0;
}