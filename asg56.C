#include <iostream>
#include <string>

template<class T>
void swap(T& a, T& b) {
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void reverse(T arr[], int size) {
    for (int i=0; i<size/2; ++i) {swap(arr[i],arr[size-1-i]);}
}

template<class T>
void printArray(const T arr[], int size) {
    for (int i=0; i<size; ++i) {std::cout << arr[i] << " ";}
    std::cout << std::endl;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Before reversing:" << std::endl;
    printArray(intArr, 5);
    printArray(doubleArr, 5);
    printArray(charArr, 5);

    reverse(intArr, 5);
    reverse(doubleArr, 5);
    reverse(charArr, 5);

    std::cout << "\nAfter reversing:" << std::endl;
    printArray(intArr, 5);
    printArray(doubleArr, 5);
    printArray(charArr, 5);
    
}
   
