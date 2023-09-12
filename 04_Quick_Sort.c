#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
return j;
}

void QuickSort(int a[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);
        QuickSort(a, low, partitionindex - 1);
        QuickSort(a, partitionindex + 1, high);
    }
}

int main()
{
    int arr[] = {4, 9, 5, 8, 3, 6,1,0,6,79};
    int n = 10;

    printf("\nUnSorted array : ");
    printarray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("Sorted array   : ");
    printarray(arr, n);

    return 0;
}