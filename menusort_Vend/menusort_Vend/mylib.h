#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <wincon.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>



// менюшка

int menu(char** name, int n, int x, int y) {
    int num = 0;
    int i;
    int code;

    //system("cls");
    setlocale(LC_ALL, "Rus");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    do {                    // 10 - цвет выбора, 15 - основной цвет, фон черный по умолчанию
        system("cls");
        for (i = 0; i < n; i++) {
            if (i == num) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                printf("%s\n", name[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else {
                printf("%s\n", name[i]);
            }
        }
        code = _getch();
        if (code == 224) {
            code = _getch();
        }
        if (code == 0x48) {
            num--;
            if (num < 0) {
                num = n - 1;
            }
        }
        if (code == 0x50) {
            num++;
            if (num == n) {
                num = 0;
            }
        }
    } while (code != 13);
    return num;
}

// Заполнение числами

int create_test_numbers() {
    setlocale(LC_ALL, "Rus");
    FILE* file;
    int n, i;

    printf("Введите количество чисел: ");
    scanf("%d", &n);

    // Открываем файл для записи
    file = fopen("random_numbers.txt", "w");

    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 0;
    }

    // Используем текущее время в качестве seed для генератора случайных чисел
    srand(time(NULL));
    fprintf(file, "%d\n", n);
    // Заполняем файл рандомными числами
    for (i = 0; i < n; i++) {
        fprintf(file, "%d ", rand());
    }

    // Закрываем файл
    fclose(file);

    printf("Файл успешно создан и заполнен рандомными числами.\n");
    return 0;
}




void copyArray(int* source, int* destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}


// вывод на экран

void output(int* st, int n, time_t start, time_t end) {
    //int i;
    printf("\n\nThe list was sorted in time:");
    /*
    for (i = 0; i < n; i++) {
        printf("%d  ", st[i]);
    }*/
    printf("%s%f", "\n", difftime(end, start));
}

//сортировка пузырьком



void bubble(int* B, int n)
{
    int i, f, l, tmp;
    l = n - 1;
    do
    {
        f = 0; // Признак упорядоченности
        for (i = 0; i < l; i++)
        {
            if (B[i] > B[i + 1]) {
                tmp = B[i];
                B[i] = B[i + 1];
                B[i + 1] = tmp;
                f = 1;
            }
        }
        l -= 1;
    } while (f == 1);
}


// улучшенная сортировка пузырьком

void bestbubble(int* B, int n) {
    int i, f, l, tmp; \
    int start = 0;
    l = n - 1;
    do
    {
        f = 0; // Признак упорядоченности
        for (i = start; i < l; i++)
        {
            if (B[i] > B[i + 1]) {
                tmp = B[i];
                B[i] = B[i + 1];
                B[i + 1] = tmp;
                f = 1;
            }
        }
        l -= 1;
        if (f == 1) {
            f = 0;
            for (i = l; i > start; i--)
            {
                if (B[i] < B[i - 1]) {
                    tmp = B[i];
                    B[i] = B[i - 1];
                    B[i - 1] = tmp;
                    f = 1;
                }
            }
            start++;
        }
    } while (f == 1);
}


// Сортировка Шелла

void shell(int* B, int n) {

    int i, f, l, tmp;
    int d = n;
    l = n;
    do
    {
        d = (d + 1) / 2;
        f = 0; // Признак упорядоченности
        for (i = 0; i < l - d; i++)
        {
            if (B[i] > B[i + d]) {
                tmp = B[i];
                B[i] = B[i + d];
                B[i + d] = tmp;
                f = 1;
            }
        }
        if ((d == 1) && (f == 1)) {
            l--;
        }
    } while ((d != 1) || (f == 1));
}



// Сортировка поиска минимального

void serachmin(int* B, int n) {
    int i, l, j, min;
    for (i = 1; i < n - 1; i++)
    {
        min = B[i];
        l = i;
        for (j = i; j < n; j++)
        {
            if (min > B[j]) {
                min = B[j];
                l = j;
            }
        }
        B[l] = B[i];
        B[i] = min;
    }

}



// cортировка со вставками


void slin(int* a, int k, int* first, int nf, int* second, int ns) {
    first[nf] = abs(first[nf - 1]);
    if (ns > 0) {
        first[nf] += abs(second[ns - 1]);
    }
    second[ns] = first[nf];
    int p = 0, q = 0, count = 0;
    while (count < nf + ns) {
        if (first[p] < second[q]) {
            a[k + count] = first[p++];
        }
        else {
            a[k + count] = second[q++];
        }

        count++;
    }
}



void Sort_Slin(int* a, int n) {
    int d, k, nf, ns;
    int* first, * second;
    first = (int*)malloc(n * sizeof(int));
    second = (int*)malloc((n / 2 + 1) * sizeof(int));
    d = 1;
    while (d < n) {
        k = 0;
        while (k < n) {
            nf = 0;
            while ((nf < d) && (nf + k < n)) {
                first[nf] = a[k + nf]; nf++;
            }
            ns = 0;
            while ((ns < d) && (ns + k + d < n)) {
                second[ns] = a[k + d + ns]; ns++;
            }
            slin(a, k, first, nf, second, ns);
            k += 2 * d;
        }
        d *= 2;
    }
}


void replace(int* B, int n, int k) {
    int i, j, tmp;
    for (i = k; i < n; i++)
    {
        tmp = B[i];
        j = i - 1;
        while ((j >= 0) && (tmp < B[j])) {
            B[j + 1] = B[j];
            j--;
        }
        B[j + 1] = tmp;

    }

}
