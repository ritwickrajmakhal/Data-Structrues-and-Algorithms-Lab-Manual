#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int lb, int mid, int ub){
    int i, j, k;
    int n1 = mid - lb + 1; // Calculating the size of left sub Array
    int n2 = ub - mid; // Calculating the size of right sub Array
    int leftArr[n1], rightArr[n2]; // Defining the left and right sub array
    for(int i=0;i<n1;i++){ // Storing all the elements in left sub array after dividing the arr
        leftArr[i] = arr[lb + i];
    }
    for(i=0;i<n2;i++){ // Storing all the elements in right sub array after dividing the arr
        rightArr[i] = arr[mid + 1 + i];
    }
    i = 0, j = 0, k = lb;
    while (i<n1 && j<n2) // Storing correct element in arr from left or right sub array, until any of or both of sub array is exhausted
    {
        if(leftArr[i]<rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(j<n2){ // Storing all the elements present in right sub array if left sub array is already exhausted
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    while(i<n1){ // Storing all the elements present in left sub array if right sub array is already exhausted
        arr[k] = leftArr[i];
        i++;
        k++;
    }
}
void mergeSort(int arr[],int lb, int ub){
    if (lb < ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,lb,mid); // dividing to the left
        mergeSort(arr,mid+1,ub); // dividing to the right
        merge(arr,lb,mid,ub); // merging after dividing is completed
    }
    else{
        return;
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
    mergeSort(arr, 0,n-1);
    printf("After sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;

}