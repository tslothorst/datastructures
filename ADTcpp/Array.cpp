#include <iostream>
#include "Array.h"

Array::Array(){
    size = 15;
    length = 0;
    A = new int[size];
}

Array::~Array(){
    delete[] A;
}

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
            Swap(&A[i],&A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key){
    int low=0;
    int high=length-1;
    int mid=(low+high)/2;

    while(low<=high){
        if(key==A[mid]){
            return mid;
        }
        else if(key<A[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int Array::RBinarySearch(int a[],int low, int high, int key){
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

int Array::Get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x){
    if(index>=0 && index<length){
        A[index]=x;
    }
}

int Array::Max(){
    int max=A[0];
    for (int i = 1; i < length; ++i) {
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min=A[0];
    for (int i = 1; i < length; ++i) {
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int s = 0;
    for (int i = 0; i < length; ++i) {
        s+=A[i];
    }
    return s;
}

float Array::Avg(){
    return (float)Sum()/(float)length;
}

void Array::Reverse(){
    int* B= new int[length];
    for (int i = length-1,j=0; i>=0 ; --i,j++) {
        B[j]=A[i];
    }
    for (int k = 0; k>length; ++k) {
        A[k]=B[k];
    }
}

void Array::Reverse2(){
    for (int i = 0,j=length-1; i < j ; ++i, ++j) {
        Swap(&A[i],&A[j]);
    }
}

void Array::InsertSort(int x){
    if(length==size){
        return;
    }
    int i = length-1;
    while(i >= 0 && A[i]>x){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

bool Array::IsSorted(){
    for (int i = 0; i < length-1; ++i) {
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}

void Array::Rearrange(){
    int i = 0;
    int j = length-1;
    while(i<j){
        while(A[i]>0)i++;
        while(A[i]<=0)j--;
        if(i<j)Swap(&A[i],&A[j]);
    }
}

Array* Array::Merge(Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    Array* arr3= new Array;

    while(i<length && j<arr2->length){
        if(A[i]<arr2->A[j]){
            arr3->A[k++]=A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<length;i++){
        arr3->A[k++]=A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=length+arr2->length;
    arr3->size=10;

    return arr3;
}

Array* Array::Union(Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    Array* arr3=new Array;

    while(i<length && j<arr2->length){
        if(A[i]<arr2->A[j]){
            arr3->A[k++]=A[i++];
        }
        else if(arr2->A[j]<A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++){
        arr3->A[k++]=A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

Array* Array::Intersection(Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    Array* arr3= new Array;

    while(i<length && j<arr2->length){
        if(A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<A[i]){
            j++;
        }
        else if(A[i]==arr2->A[j]){
            arr3->A[k++]=A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

Array* Array::Difference(Array* arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    Array* arr3= new Array;

    while(i<length && j<arr2->length){
        if(A[i]<arr2->A[j]){
            arr3->A[k++]=A[i++];
        }
        else if(arr2->A[j]<A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<length;i++){
        arr3->A[k++]=A[i];
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

void Array::Insert(int index,int x)
{
    int i;
    if(index>=0 && index <=length)
    {
        for(i=length;i>index;i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;

    }
}
int Array::Delete(int index)
{
    int x=0;
    int i;

    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index;i<length-1;i++)
            A[i]=A[i+1];
        length--;
        return x;
    }

    return 0;
}
