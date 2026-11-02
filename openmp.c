/*
 * File: openmp.c
 * Deskripsi: Implementasi perkalian matriks paralel dengan OpenMP.
 * NIM: 2322105056
 * Nama: Hakim Hattabi
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Header wajib untuk OpenMP

#define N 1000

double A[N][N], B[N][N], C[N][N];

int main() {
    srand(42);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }

    // OpenMP menggunakan fungsi waktu sendiri
    double start = omp_get_wtime();

    // PARALELISASI OPENMP: Menggunakan pragma pada loop terluar
    #pragma omp parallel for shared(A, B, C)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            double temp = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += temp * B[k][j];
            }
        }
    }

    double end = omp_get_wtime();
    
    printf("=== OPENMP ===\n");
    printf("Waktu eksekusi: %f detik\n", end - start);
    
    return 0;
}