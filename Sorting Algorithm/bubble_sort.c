#include <stdio.h>

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
    int a[] = {6, 2, 8, 4, 5, 1, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    printArr(a, n);

    bubbleSort(a, n);
    printf("Bubble sort: ");
    printArr(a, n);

    return 0;
}