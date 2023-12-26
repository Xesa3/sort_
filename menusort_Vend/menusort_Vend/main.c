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

    nm[0] = "�������";
    nm[1] = "���������� ���������� ��������";
    nm[2] = "���������� �����";
    nm[3] = "���������� ������ ������������";
    nm[4] = "C��������� ���������";
    nm[5] = "���������� ��������";
    nm[6] = "Exit";
    create_test_numbers();
    wait = _getch();

    time_t start, end;

    FILE* file;
    char filename[] = "random_numbers.txt"; // ��� ������ �����

    // ��������� ���� ��� ������
    file = fopen(filename, "r");

    // ���������, ������� �� ������� ����
    if (file == NULL) {
        printf("�� ������� ������� ����.\n");
        return 1;
    }

    int n;

    // ������� ���������� ����� � �����
    fscanf(file, "%d", &n);

    // ������� ������
    int* arr = (int*)malloc(n * sizeof(int));

    
    // ��������� ����� �� ����� � ������
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    // ��������� ����
    fclose(file);


    

    do {
        num = menu(nm, k, 0, 0);
        switch (num) {
        case 0: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("����������....");

            start = time(NULL);

            bubble(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[0] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 1: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);


            printf("����������....");

            start = time(NULL);

            bestbubble(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[1] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 2: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("����������....");
            start = time(NULL);

            shell(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[2] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 3: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("����������....");

            start = time(NULL);

            serachmin(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[3] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 4: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("����������....");

            start = time(NULL);

            Sort_Slin(destinationArray, n);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[4] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        case 5: {
            // ������� ������ ������ ��� ����� � �������� � ���� ������ ����� �� �������� �������� ������� ���������
            int* destinationArray = (int*)malloc(n * sizeof(int));
            copyArray(arr, destinationArray, n);

            printf("����������....");

            start = time(NULL);

            replace(destinationArray, n, 1);

            end = time(NULL);

            output(destinationArray, n, start, end);

            tm[5] = difftime(end, start);

            //������� ������������� ������
            free(destinationArray);

            wait = _getch();
            break;
        }
        }
    } while (num != k - 1);

    printf("\n������ �� %d ����� ��� ����������� ������� ���������\n", n);
    printf("\n%-40s %-10s\n", "�������� ����������", "����� ����������\n");

    for (int i = 0; i < 6; i++) {
        printf("%-40s %-10.3f\n", nm[i], tm[i]);
    }


}
