#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, smallIdx, noOfComp;
    for (i = 0; i < n - 1; i++)
    {
        smallIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIdx])
            {
                smallIdx = j;
            }
        }
        swap(&arr[smallIdx], &arr[i]);
    }
}

int main()
{
    int arr[100], i, n;
    printf("Enter how many elements you want to insert ");
    scanf("%d", &n);
    printf("Enter all the values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("After sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}