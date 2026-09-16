#include <stdio.h>

// Merge two sorted subarrays
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}
// Merge Sort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
int main()
{
    int arr[] = {125, 181, 130, 25, 61, 887};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is:\n");
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("\nSorted array is:\n");
    printArray(arr, size);
    return 0;
}

Output:

Given array is:
125 181 130 25 61 887
Sorted array is:
25 61 125 130 181 887
