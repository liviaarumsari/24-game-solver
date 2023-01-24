# Tucil1_13521094
Tugas Kecil 1 IF2211 Strategi Algoritma - Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Table of Contents
* [General Information](#general-information)
* [Features](#features)
* [Requirements](#requirements)
* [How to Compile and Run](#how-to-compile-and-run)
* [Repository Structure](#repository-structure)
* [Author](#author)

## General Information
Program ini memberikan solusi dari permainan kartu 24 dengan memanfaatkan algoritma brute force. Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mengubah 4 buah angka dari kartu sehingga mendapatkan hasil akhir sejumlah 24. Sedangkan algoritma brute force yaitu pendekatan yang straightforward untuk memecahkan persoalan.

## Features
- Menampilkan solusi Permainan Kartu 24 berdasarkan input kartu pengguna.
- Menampilkan solusi Permainan Kartu 24 berdasarkan kartu yang dipilih secara random.
- Menyimpan solusi Permainan Kartu 24 ke dalam file .txt

## Requirements
Untuk dapat menjalankan program ini, Anda harus menginstall bahasa C++ dan compiler g++.

## How to Compile and Run
Tanpa melakukan kompilasi, Anda dapat langsung menjalankan perintah berikut pada folder utama
```
./bin/main.exe
```

Namun, jika ingin melakukan kompilasi ulang, dapat mengikuti langkah berikut:
1. Buka folder src dengan menjalankan command berikut pada folder utama
```
cd src
```

2. Lakukan compile program dengan menjalankan perintah berikut

```
g++ -o ../bin/main.exe main.cpp game_solver.cpp io.cpp
```
Jika menggunakan os Windows, langsung jalankan file run.bat dengan perintah berikut
```
./run.bat
```

3. Jalankan program utama dengan perintah berikut

```
../bin/main.exe
```

## Repository Structure
```
|   .gitignore
|   README.md
|
+---bin
|       main.exe
|
+---doc
|       Tucil1_K2_13521094_Angela Livia Arumsari.pdf
|
+---src
|       game_solver.cpp
|       game_solver.h
|       io.cpp
|       io.h
|       main.cpp
|       run.bat
|
\---test
        test01.txt
        test02.txt
        test03.txt
        test04.txt
        test05.txt
        test06.txt
        test07.txt
        test08.txt
```

## Author
Angela Livia Arumsari (13521094)