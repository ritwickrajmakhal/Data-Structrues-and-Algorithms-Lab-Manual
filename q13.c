#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void pass(int arr[], int n, int i){
    if(n==i){
        return;
    }
    if(arr[i-1]>arr[i]){
        swap(&arr[i-1],&arr[i]);
    }
    pass(arr,n,i+1);
}
void bubbleSort(int arr[], int n){
    if(n>1){
        pass(arr,n,1);
        bubbleSort(arr,n-1);
    }
}

int main() {
    int arr[100], i, n;
    printf("Enter how many elements you want to insert ");
    scanf("%d", &n);
    printf("Enter all the values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr,n);
    printf("After sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}