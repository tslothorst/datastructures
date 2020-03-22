#ifndef ADTCPP_ARRAY_H
#define ADTCPP_ARRAY_H

class Array {
private:
    int* A;
    int size;
    int length;
    void Swap(int* x, int* y);
public:
    Array();
    void Display();
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RBinarySearch(int a[],int low, int high, int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    bool IsSorted();
    void Rearrange();
    Array* Merge(Array* arr2);
    Array* Union(Array* arr2);
    Array* Intersection(struct Array* arr2);
    Array* Difference(Array* arr2);
    void Insert(int index,int x);
    int Delete(int index);
    ~Array();
};

#endif //ADTCPP_ARRAY_H
