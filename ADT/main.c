#include <stdio.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("\nElements are:\n");
    for (int i = 0; i < arr.length; ++i) {
        printf("%d ",arr.A[i]);
    }
}

void Swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array* arr,int key){
    for (int i = 0; i < arr->length; ++i) {
        if(key==arr->A[i]){
            Swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key){
    int low=0;
    int high=arr.length-1;
    int mid=(low+high)/2;

    while(low<=high){
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int RBinarySearch(int a[],int low, int high, int key){
    int mid=(low+high)/2;
    if(low<=high){
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            return RBinarySearch(a,low,mid-1,key);
        }
        else{
            return RBinarySearch(a,mid+1,high,key);
        }
    }
    return -1;
}

int main() {
    struct Array arr1 = {{2,23,14,5,6,9,8,12},10,8};
    Display(arr1);
    return 0;
}
