// 11. Write C program to implement Binary search
#include <stdio.h>

int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int start = 0, end = 9;
    int mid = (start+end)/2, sv;
    printf("Enter a serch value ");
    scanf("%d",&sv);
    while (start<=end)
    {
        if(arr[mid]==sv){
            printf("%d is found!\n",sv);
            break;
        }
        if(sv<arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = (start+end)/2;
    }
    if(start>end){
        printf("%d is not found!\n",sv);
    }
    return 0;

}