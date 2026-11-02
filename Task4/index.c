#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void generateRandomArray(double*, int);
void findAverage(double*, int, int, int, double*);
double* createNewArray(double*, int, double, int*);

int main() {
    SetConsoleOutputCP(65001);
    // 4. Дано масив дійсних чисел розміру N (значення елементів
    // згенерувати випадковим чином) і цілі числа K і L (1 ≤ K ≤L ≤N).
    // Знайти середнє арифметичне всіх елементів масиву, крім елементів із
    // номерами від K до L включно. В окремій функції сформувати новий
    // масив (функція має повернути цей масив) з елементів, які менші ніж
    // середнє арифметичне.

    srand(time(NULL));


    int N, K, L;
    printf("Введіть розмір масиву (N > 0): ");
    scanf("%d", &N);
    printf("Введіть значення K (1 ≤ K ≤ N): ");
    scanf("%d", &K);
    printf("Введіть значення L (K ≤ L ≤ N): ");
    scanf("%d", &L);

    if (N <= 0 || K < 1 || L < K || L > N) {
        printf("Некоректні значення N, K або L.\n");
    } else {
        double array[N];
        generateRandomArray(array, N);

        double average;
        findAverage(array, N, K, L, &average);

        printf("Середнє арифметичне: %.2f\n", average);

        int newArraySize = 0;
        double* newArray = createNewArray(array, N, average, &newArraySize);
        if (newArray != NULL) {
            printf("Новий масив: ");
            for (int i = 0; i < newArraySize; i++) {
                printf("%.2f ", newArray[i]);
            }
            free(newArray);
        } else {
            printf("Новий масив не створено\n");
        }
    }

    return 0;
}

double* createNewArray(double* array, int size, double average, int* newArraySize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < average) {
            count++;
        }
    }

    *newArraySize = count;
    double* newArray = (double*)malloc(count * sizeof(double));
    if (newArray == NULL) {
        printf("Помилка виділення пам'яті\n");
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < average) {
            newArray[index++] = array[i];
        }
    }

    return newArray;
}


void findAverage(double* array, int size, int K, int L, double* average) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (i < K - 1 || i > L - 1) {
            printf("array[%d] = %.2f\n", i + 1, array[i]);
            sum += array[i];
            count++;
        }
    }

    if (count == 0) {
        printf("Неможливо обчислити середнє арифметичне, оскільки всі елементи масиву виключені.\n");
        *average = 0;
    } else {
        *average = sum / count;
    }
}

void generateRandomArray(double* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 10000) / 10.0;
        printf("array[%d] = %.2f\n", i + 1, array[i]);
    }
}