#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

void Bubblesort(int *arr, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("Working on pass no. : %d\n",i+1);
        issorted = 1;

        for (int j = 0; j < n - 1 - i; j++) // for comparision in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }

        }
            if (issorted){ return ;}
    }
}

int main()
{
    int A[] = {1, 22, 3, 4, 5, 6};
    int n = 6;
    printf("\n\nArray before sorting : ");
    printarray(A, n); // before sorting

    Bubblesort(A, n); // calling function for sorting

    printf("Array after sorting  : ");
    printarray(A, n); // after sorting
    printf("\n");

    return 0;
}