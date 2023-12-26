#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <wincon.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "mylib.h"
#include <time.h>


void main() {
    int i;

    int k = 7;
    int num;
    int wait;
    char* nm[7];

    double tm[6];

    for (i = 0; i < 6; i++) {
        tm[i] = 0;
    }

    nm[0] = "Пузырек";
    nm[1] = "Улучшенная сортировка пузырька";
    nm[2] = "Сортировка Шелла";
    nm[3] = "Сортировка поиска минимального";
    nm[4] = "Cортировка вставками";
    nm[5] = "Сортировка шейкером";
    nm[6] = "Exit";
    create_test_numbers();
    wait = _getch();

    time_t start, end;

    FILE* file;
    char filename[] = "random_numbers.txt"; // Имя вашего файла

    // Открываем файл для чтения
    file = fopen(filename, "r");

    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    int n;

    // Считаем количество чисел в файле
    fscanf(file, "%d", &n);

    // Создаем массив
    int* arr = (int*)malloc(n * sizeof(int));

    
    // Считываем числа из файла в массив
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    // Закрываем файл
    fclose(file);


    

    do {
        num = menu(nm, k, 0, 0);
        switch (num) {
        case 0: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("Сортировка....");

            start = time(NULL);

            bubble(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[0] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 1: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);


            printf("Сортировка....");

            start = time(NULL);

            bestbubble(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[1] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 2: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("Сортировка....");
            start = time(NULL);

            shell(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[2] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 3: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("Сортировка....");

            start = time(NULL);

            serachmin(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[3] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 4: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("Сортировка....");

            start = time(NULL);

            Sort_Slin(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[4] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 5: {
            // Создаем второй массив для теста и копируем в него данные чтобы не потерять исходный который сортируем
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("Сортировка....");

            start = time(NULL);

            replace(destinationArray, n, 1);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[5] = difftime(end, start);

            //Очищаем скопированный массив
            free(destinationArray);

            wait = _getch();
            break;
        }
        }
    } while (num != k - 1);

    printf("\nМассив из %d чисел был отортирован разными способами\n", n);
    printf("\n%-40s %-10s\n", "Название сортировки", "Время выполнения\n");

    for (int i = 0; i < 6; i++) {
        printf("%-40s %-10.3f\n", nm[i], tm[i]);
    }


}
