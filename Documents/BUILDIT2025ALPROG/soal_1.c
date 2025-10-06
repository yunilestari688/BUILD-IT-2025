#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    double X[1000];
    double total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lf", &X[i]);
        total += X[i];
    }

    // cari nilai maksimum
    double max = X[0];
    for (int i = 1; i < N; i++) {
        if (X[i] > max)
            max = X[i];
    }

    // hitung berapa kali muncul dan simpan hari
    int count = 0;
    int days[1000];
    for (int i = 0; i < N; i++) {
        if (X[i] == max) {
            days[count] = i + 1;  // simpan hari (1-based)
            count++;
        }
    }

    // hitung persentase
    double percentage = ((max * count) / total) * 100;

    // tampilkan hasil
    printf("Max : %.0lf\n", max);
    printf("Count : %d\n", count);
    printf("days : ");
    for (int i = 0; i < count; i++) {
        printf("%d", days[i]);
        if (i < count - 1) printf(" ");
    }
    printf("\n");
    printf("Percentage : %.3lf%%\n", percentage);

    return 0;
}