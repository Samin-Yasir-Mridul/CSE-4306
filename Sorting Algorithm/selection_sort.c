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
    int a[] = {5, 7, 2, 1, 3, 9, 6};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    printArr(a, n);

    selectionSort(a, n);
    printf("Selection sort: ");
    printArr(a, n);
    
    return 0;
}
