#include <stdio.h>

void insertionSort(int arr[], int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i - 1;
        while (key<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
    
}

int main() {
    int arr[100],i,n;
    printf("Enter how many elements you want to insert ");
    scanf("%d",&n);
    printf("Enter all the values: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("After sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;

}