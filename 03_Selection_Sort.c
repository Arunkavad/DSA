#include <stdio.h>

void SelectionSort(int *ptr, int n)
{
    int indexofmin, temp;
    for (int i = 0; i < n-1 ; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ptr[j] < ptr[indexofmin])
            {
                indexofmin = j;
            }
        }
        // swaping ptr[i] and ptr[indexofmin]
        temp = ptr[i];
        ptr[i] = ptr[indexofmin];
        ptr[indexofmin] = temp;
    }
}

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n\n");
}

int main()
{
    int n = 5;
    int arr[] = {32, 54, 69, 78, 25};
   
    printf("\nUnSorted array : ");
    printarray(arr, n);
   
    SelectionSort(arr, n);
   
    printf("Sorted array   : ");
    printarray(arr, n);
    return 0;
}