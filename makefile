# Makefile untuk Kompilasi Project UTS
# NIM: 2322105056
# Nama: Hakim Hattabi

CC = gcc
CFLAGS = -O3 -Wall

# Target utama: meng-compile semua file
all: serial pthreads openmp

# Kompilasi program serial
serial: serial.c
	$(CC) $(CFLAGS) -o serial serial.c

# Kompilasi program Pthreads (butuh flag -pthread)
pthreads: pthreads.c
	$(CC) $(CFLAGS) -pthread -o pthreads pthreads.c

# Kompilasi program OpenMP (butuh flag -fopenmp)
openmp: openmp.c
	$(CC) $(CFLAGS) -fopenmp -o openmp openmp.c

# Membersihkan file executable
clean:
	rm -f serial pthreads openmp