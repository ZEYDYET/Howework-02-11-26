#include <stdio.h>
#include <windows.h>

void printEvenNumbers(int N, int array[], int* K);

int main() {
    SetConsoleOutputCP(65001);
    // 2. Дано цілочислений масив розміру N. вивести всі парні числа, що
    // містяться в даному масиві, в порядку зменшення їх індексів, а також їх
    // кількість K.

    int N, K = 0;
    printf("Введіть розмір масиву: ");
    scanf("%d", &N);

    if (N > 0) {
        int array[N];
        printf("Введіть елементи масиву:\n");
        for (int i = 0; i < N; i++) {
            printf("Елемент [%d] = ", i + 1);
            scanf("%d", &array[i]);
        }

        printEvenNumbers(N, array, &K);
    } else {
        printf("Розмір масиву повинен бути більше 0\n");
    }

    return 0;
}

void printEvenNumbers(int N, int array[], int* K) { // функція для виведення парних чисел у порядку зменшення індексів
    printf("Парні числа у порядку зменшення індексів: ");
    for (int i = N - 1; i >= 0; i--) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
            (*K)++;
        }
    }
    printf("\nКількість парних чисел: %d\n", *K);
}