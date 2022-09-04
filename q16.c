16. Write C program to implement Binary Search Using recursion.. 
#include <stdio.h>
#include <stdlib.h>

int bSearch(int arr[],int start, int end, int mid, int sv){
    if(arr[mid]==sv){
        return 1;
    }
    if(start>end){
        return 0;
    }
    if(sv>arr[mid]){
        start = mid + 1;
        mid = (start + end)/2;
        bSearch(arr,start,end,mid,sv);
    }
    else{
        end = mid - 1;
        mid = (start + end)/2;
        bSearch(arr,start,end,mid,sv);
    }
}
int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int start = 0, end = 9;
    int mid = (start+end)/2, sv;
    printf("Enter a serch value ");
    scanf("%d",&sv);
    if(bSearch(arr,start,end,mid,sv)){
        printf("%d found\n",sv);
    }
    else{
        printf("%d not found\n",sv);
    }
    
    return 0;

}