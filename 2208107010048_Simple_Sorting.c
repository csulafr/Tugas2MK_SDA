#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int *numbers, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        numbers[i] = rand(); 
    }
}

void bubbleSort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < numbers[min_idx]) {
                min_idx = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[min_idx];
        numbers[min_idx] = temp;
    }
}

void insertionSort(int *numbers, int n) {
    for (int i = 1; i < n; i++) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void saveNumbersToFile(int *numbers, int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);
}

int main() {
    int max_numbers = 1000000; // Ubah sesuai dengan jumlah maksimal bilangan yang diinginkan
    int *numbers = (int*)malloc(max_numbers * sizeof(int));

    generateRandomNumbers(numbers, max_numbers);
    saveNumbersToFile(numbers, max_numbers, "unsorted_numbers.txt");

    clock_t start, end;
    double cpu_time_used;

    FILE *resultFile = fopen("sorting_results.txt", "w");
    if (resultFile == NULL) {
        printf("Failed to open result file.\n");
        return 1;
    }

    fprintf(resultFile, "Jenis Algoritma\tJumlah Bilangan\tWaktu Eksekusi (ms)\n");
    fprintf(resultFile, "---------------------------------------------------------------------\n");

    for (int n = 100000; n <= max_numbers; n += 100000) {
        generateRandomNumbers(numbers, n);

        fprintf(resultFile, "Bubble Sort\t%d\t", n);
        start = clock();
        bubbleSort(numbers, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        fprintf(resultFile, "%.2f\n", cpu_time_used);
        printf("Sorting %d numbers using Bubble Sort: %.2f ms\n", n, cpu_time_used);

        fprintf(resultFile, "Selection Sort\t%d\t", n);
        start = clock();
        selectionSort(numbers, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        fprintf(resultFile, "%.2f\n", cpu_time_used);
        printf("Sorting %d numbers using Selection Sort: %.2f ms\n", n, cpu_time_used);

        fprintf(resultFile, "Insertion Sort\t%d\t", n);
        start = clock();
        insertionSort(numbers, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        fprintf(resultFile, "%.2f\n", cpu_time_used);
        printf("Sorting %d numbers using Insertion Sort: %.2f ms\n", n, cpu_time_used);
        
        fprintf(resultFile, "---------------------------------------------------------------------\n");
    }

    fclose(resultFile);
    free(numbers);

    return 0;
}
