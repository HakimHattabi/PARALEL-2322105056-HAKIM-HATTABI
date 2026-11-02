/*
 * File: serial.c
 * Deskripsi: Implementasi perkalian matriks sekuensial (baseline).
 * NIM: 2322105056
 * Nama: Hakim Hattabi
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 1000

// Deklarasi matriks global agar aman dari stack overflow
double A[N][N], B[N][N], C[N][N];

int main() {
    // Inisialisasi pseudo-random dengan seed 42 (sesuai soal)
    srand(42);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0.0;
        }
    }

    struct timeval start, end;
    gettimeofday(&start, NULL); // Mulai hitung waktu

    // Algoritma Perkalian Matriks (Optimasi Cache Locality: i-k-j)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            double temp = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += temp * B[k][j];
            }
        }
    }

    gettimeofday(&end, NULL); // Selesai hitung waktu
    
    double time_spent = (end.tv_sec - start.tv_sec) + 
                        (end.tv_usec - start.tv_usec) / 1000000.0;
    
    printf("=== SERIAL ===\n");
    printf("Waktu eksekusi: %f detik\n", time_spent);
    
    return 0;
}