#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int Get(struct Array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array* arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}

int Max(struct Array arr){
    int max=arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min=arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int s = 0;
    for (int i = 0; i < arr.length; ++i) {
        s+=arr.A[i];
    }
    return s;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array* arr){
    int* B=(int*)malloc(arr->length*sizeof(int));
    for (int i = arr->length-1,j=0; i>=0 ; --i,j++) {
        B[j]=arr->A[i];
    }
    for (int k = 0; k>arr->length; ++k) {
        arr->A[k]=B[k];
    }
}

void Reverse2(struct Array* arr){
    for (int i = 0,j=arr->length-1; i < j ; ++i, ++j) {
        Swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertSort(struct Array* arr,int x){
    if(arr->length==arr->size){
        return;
    }
    int i = arr->length-1;
    while(i >= 0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

bool IsSorted(struct Array arr){
    for (int i = 0; i < arr.length-1; ++i) {
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void Rearrange(struct Array* arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i]>0)i++;
        while(arr->A[i]<=0)j--;
        if(i<j)Swap(&arr->A[i],&arr->A[j]);
    }
}

int main() {
    struct Array arr1 = {{2,23,14,5,6,9,8,12},10,8};
    Display(arr1);
    return 0;
}
