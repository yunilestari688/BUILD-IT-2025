#include <stdio.h>
#include <string.h>

int main() {
    // Menyediakan buffer untuk input string sesuai batasan (1000 + cadangan)
    char input_string[1002];

    // Array 2D untuk menyimpan setiap kata yang telah dipecah
    // Format: [jumlah_kata_maksimum][panjang_kata_maksimum + 1 untuk '\0']
    char words[301][72];
    int word_count = 0;

    // 1. Membaca satu baris penuh dari input, termasuk spasi
    fgets(input_string, sizeof(input_string), stdin);

    // Menghilangkan karakter newline ('\n') yang sering ditambahkan oleh fgets
    // Ini penting agar perbandingan string bekerja dengan benar
    input_string[strcspn(input_string, "\n")] = 0;

    // 2. Memulai proses memecah string menjadi kata-kata (tokenisasi)
    char *token = strtok(input_string, " ");

    // Loop untuk mengambil setiap kata
    while (token != NULL) {
        // 3. Salin kata yang ditemukan ke dalam array 'words'
        strcpy(words[word_count], token);
        word_count++;
        // Lanjutkan untuk mengambil kata berikutnya dari string yang sama
        token = strtok(NULL, " ");
    }

    // Flag untuk menangani spasi agar tidak ada spasi di akhir output
    int is_first_word = 1;

    // 4. Loop untuk memeriksa setiap kata dan mencari duplikat
    for (int i = 0; i < word_count; i++) {
        int is_duplicate = 0; // Asumsikan kata ini unik (bukan duplikat)

        // Loop untuk membandingkan kata saat ini (words[i]) dengan semua kata sebelumnya
        for (int j = 0; j < i; j++) {
            // strcmp() akan mengembalikan 0 jika kedua string sama persis
            if (strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1; // Jika sama, tandai sebagai duplikat
                break; // Hentikan pencarian karena duplikat sudah ditemukan
            }
        }

        // 5. Jika kata tersebut BUKAN duplikat, cetak kata itu
        if (!is_duplicate) {
            // Jika ini bukan kata pertama yang dicetak, beri spasi sebelumnya
            if (!is_first_word) {
                printf(" ");
            }
            printf("%s", words[i]);
            is_first_word = 0; // Set flag menjadi false setelah kata pertama dicetak
        }
    }

    // Cetak baris baru di akhir output untuk kebersihan
    printf("\n");

    return 0;
}