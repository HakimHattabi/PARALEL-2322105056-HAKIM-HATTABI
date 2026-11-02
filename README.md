# Project UTS Komputer Paralel - Opsi A
**Mata Kuliah:** Komputer Paralel (Sistem Terdistribusi)  
**NIM:** 2322105056  
**Nama:** Hakim Hattabi  
**Kasus:** Perkalian Matriks (Pthreads vs OpenMP)

## Deskripsi Project
Project ini mengimplementasikan perkalian matriks berukuran 1000x1000 menggunakan tiga pendekatan:
1. `serial.c` : Baseline (Sekuensial)
2. `pthreads.c` : Paralelisasi eksplisit menggunakan POSIX Threads
3. `openmp.c` : Paralelisasi compiler directive menggunakan OpenMP

Semua program menggunakan optimasi *cache locality* (perubahan urutan *loop* menjadi `i-k-j`) untuk performa yang lebih baik.

## Prasyarat (Requirements)
Pastikan sistem Anda (Linux/Mac/WSL) memiliki:
- Compiler `gcc`
- Library `pthread` (biasanya sudah *built-in* di Linux)
- Dukungan OpenMP (biasanya sudah *built-in* di gcc)

## Cara Compile (Build)
Gunakan `Makefile` yang sudah disediakan. Buka terminal di direktori ini dan jalankan perintah:
```bash
make all