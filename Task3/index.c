#include <stdio.h>
#include <windows.h>

void swapMaxMinIndex(int N, int array[]);

int main() {
    SetConsoleOutputCP(65001);
    // 3. Дано масив A розміру N. Знайти максимальний і мінімальний
    // елементи серед елементів з непарними номерами масиву і поміняти їх
    // місцями. (результати, отримані у функціях мають бути доступними у
    // main () ).

    int N;
    printf("Введіть розмір масиву N > 3: ");
    scanf("%d", &N);

    if (N > 3) {
        int array[N];
        printf("Введіть елементи масиву:\n");
        for (int i = 0; i < N; i++) {
            printf("Елемент [%d] = ", i);
            scanf("%d", &array[i]);
        }

        swapMaxMinIndex(N, array);

        printf("Масив після обміну:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("Розмір масиву повинен бути більше 3\n");
    }

    return 0;
}

void swapMaxMinIndex(int N, int array[]) {
    int maxIndex = 1, minIndex = 1;
    int maxValue = array[1], minValue = array[1];

    for (int i = 1; i < N; i += 2) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            maxIndex = i;
        }
        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }

    int temp = array[maxIndex];
    array[maxIndex] = array[minIndex];
    array[minIndex] = temp;
}