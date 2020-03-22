#include <iostream>
#include "Array.h"

void Array::Display(){
    std::cout << "\nElements are:\n" << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << A[i] << "\n";
    }
}

void Array::Swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch(int key){
    for (int i = 0; i < length; ++i) {
        if(key==A[i]){
            Swap(A[i],A[0]);
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

struct Array* Merge(struct Array* arr1, struct Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array* arr3=(struct Array*)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array* arr3=(struct Array*)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array* arr3=(struct Array*)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr1->A[i]==arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array* arr3=(struct Array*)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;

    }
}
int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;

    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }

    return 0;
}
