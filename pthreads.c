/*
 * File: pthreads.c
 * Deskripsi: Implementasi perkalian matriks paralel dengan Pthreads.
 * NIM: 2322105056
 * Nama: Hakim Hattabi
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define N 1000
#define NUM_THREADS 4 // Silakan ubah angka ini untuk pengujian (1, 2, 4, 8)

double A[N][N], B[N][N], C[N][N];

// Struct untuk mengirim argumen ke thread
typedef struct {
    int thread_id;
    int num_threads;
} ThreadArg;

// Fungsi worker yang dijalankan oleh setiap thread
void* multiply(void* arg) {
    ThreadArg* t_arg = (ThreadArg*)arg;
    
    // Pembagian workload (Data Decomposition per baris)
    int start = (N / t_arg->num_threads) * t_arg->thread_id;
    int end = (t_arg->thread_id == t_arg->num_threads - 1) ? N : start + (N / t_arg->num_threads);

    // Eksekusi perkalian matriks pada blok baris milik thread ini
    for (int i = start; i < end; i++) {
        for (int k = 0; k < N; k++) {
            double temp = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += temp * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArg thread_args[NUM_THREADS];

    srand(42);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Membuat thread
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].num_threads = NUM_THREADS;
        pthread_create(&threads[i], NULL, multiply, (void*)&thread_args[i]);
    }

    // Menunggu semua thread selesai (Sinkronisasi)
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    double time_spent = (end.tv_sec - start.tv_sec) + 
                        (end.tv_usec - start.tv_usec) / 1000000.0;
    
    printf("=== PTHREADS (%d Thread) ===\n", NUM_THREADS);
    printf("Waktu eksekusi: %f detik\n", time_spent);
    
    return 0;
}