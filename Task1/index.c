#include <stdio.h>
#include <math.h>
#include <windows.h>

void arrayGeometricProgression(int N, int A, int D, int array[]);

int main() {
    SetConsoleOutputCP(65001);
    // 1. Дано ціле число N > 1 а також перший член A та знаменник D
    // геометричної прогресії. Сформувати та вивести масив розміру N, що
    // містить N перших членів даної прогресії:
    // A, A·D, A·D2, A·D3, ... .

    int N, A, D;

    printf("Введіть ціле число N > 1: ");
    scanf("%d", &N);
    printf("Введіть перший член A: ");
    scanf("%d", &A);
    printf("Введіть знаменник D: ");
    scanf("%d", &D);

    if (N > 1) {
        int array[N];

        arrayGeometricProgression(N, A, D, array);

        printf("Масив геометричної прогресії: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("N повинно бути більше 1\n");
    }

    return 0;
}

void arrayGeometricProgression(int N, int A, int D, int array[]) { // функція для додавання геометричної прогресії у масив
    for (int i = 0; i < N; i++) {
        array[i] = A * pow(D, i);
    }
}