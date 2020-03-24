#include <iostream>
#include "Array.h"

int main() {
    Array arr1;
    int ch;
    int x;
    int index;

    do
    {
        std::cout << "\n\nMenu\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Sum\n";
        std::cout << "5. Display\n";
        std::cout << "6.Exit\n";

        std::cout << "\nEnter your choice ";
        std::cin >> ch;

        switch(ch)
        {
            case 1: std::cout << "Enter an element and index ";
                std::cin >> x >> index;
                arr1.Insert(index,x);
                break;
            case 2: std::cout << "Enter index ";
                std::cin >> index;
                x=arr1.Delete(index);
                std::cout << "Deleted Element is " << x;
                break;
            case 3: std::cout << "Enter element to search ";
                std::cin >> x;
                index=arr1.LinearSearch(x);
                std::cout << "Element index " << index << "\n";
                break;
            case 4: std::cout << "Sum is " << arr1.Sum() << "\n";
                break;
            case 5: arr1.Display();

        }
    }while(ch<6);
    return 0;

}
