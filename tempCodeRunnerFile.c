
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