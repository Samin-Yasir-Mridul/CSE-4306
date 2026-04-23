#include <stdio.h>

void selectionSort(int a[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

void bubbleSort(int a[], int n)
{
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void printArr(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a1[] = {5, 7, 2, 1, 3, 9, 6};
    int n1 = sizeof(a1) / sizeof(a1[0]);

    int a2[] = {1, 8, 3, 9, 4, 5, 7};
    int n2 = sizeof(a2) / sizeof(a2[0]);

    int a3[] = {1, 5, 8, 10, 9, 3, 2};
    int n3 = sizeof(a3) / sizeof(a3[0]);

    printf("Before sorting: ");
    printArr(a1, n1);
    selectionSort(a1, n1);
    printf("Selection sort: ");
    printArr(a1, n1);
    printf("\n");

    printf("Before sorting: ");
    printArr(a2, n2);
    bubbleSort(a2, n2);
    printf("Bubble sort:    ");
    printArr(a2, n2);
    printf("\n");

    printf("Before sorting: ");
    printArr(a3, n3);
    insertionSort(a3, n3);
    printf("Insertion sort: ");
    printArr(a3, n3);

    return 0;
}
