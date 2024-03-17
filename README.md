*TUGAS 2 MK STRUKTUR DATA DAN ALGORITMA*

1. Cara menjalankan kode program
- Buka terminal atau command prompt.
- Navigasi ke direktori tempat Anda menyimpan file kode program tersebut menggunakan perintah cd (change directory). Misalnya, jika file disimpan di folder Desktop, gunakan perintah cd Desktop di terminal atau command prompt.
- Compile kode program dengan menggunakan compiler C seperti GCC (GNU Compiler Collection) dengan perintah gcc <nama_file_program.c> -o <nama_output>. Misalnya, jika nama file program Anda adalah 2208107010048_Simple_Sorting.c dan nama output yang diinginkan adalah 2208107010048_Simple_Sorting, maka perintahnya adalah gcc 2208107010048_Simple_Sorting.c -o 2208107010048_Simple_Sorting.
- Setelah berhasil dikompilasi tanpa kesalahan, jalankan program dengan mengetikkan ./2208107010048_Simple_Sorting di terminal.

2. Fungsi-fungsi yang terdapat pada kode program
- generateRandomNumbers(int *numbers, int n): Fungsi ini digunakan untuk mengisi array numbers dengan bilangan acak sebanyak n elemen.
- bubbleSort(int *numbers, int n): Fungsi ini mengimplementasikan algoritma Bubble Sort untuk mengurutkan array numbers yang berisi n elemen.
- selectionSort(int *numbers, int n): Fungsi ini mengimplementasikan algoritma Selection Sort untuk mengurutkan array numbers yang berisi n elemen.
- insertionSort(int *numbers, int n): Fungsi ini mengimplementasikan algoritma Insertion Sort untuk mengurutkan array numbers yang berisi n elemen.
- saveNumbersToFile(int *numbers, int n, char *filename): Fungsi ini digunakan untuk menyimpan array numbers yang berisi n elemen ke dalam file dengan nama filename.
- Selain itu, dalam fungsi main(), program ini melakukan pengukuran waktu eksekusi dari setiap algoritma sorting untuk setiap 100k bilangan yang diurutkan. Hasil dari pengukuran waktu eksekusi tersebut kemudian disimpan ke dalam file "sorting_results.txt" bersama dengan jenis algoritma, jumlah bilangan yang diurutkan, dan waktu eksekusi (dalam milidetik).
