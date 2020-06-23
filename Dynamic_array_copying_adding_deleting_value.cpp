#include <iostream>
using namespace std;

void FillArray(int * const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }

}

void ShowArray(const int * const arr, const int  size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void push_begin(int *&arr, int &size, const int value)//add first element to the array
{
    int* newArray = new int[size + 1];
    newArray[0] = value;
    for (int i = 1; i < size + 1; i++)
    {
        newArray[i] = arr[i-1];
    }
    size++;
    delete[] arr;
    arr = newArray;
}
 
void pop_begin(int *&arr, int &size) //delete first element from the array
{
    size--;
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[] arr;
    arr = newArray;
}
void push_middle(int *&arr, int &size, const int value)//add new element in the middle
{
    int middle_index = (size - 1) / 2;
    int* newArray = new int[size + 1];
    newArray[middle_index] = value;
    for (int i = 0; i < middle_index; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = middle_index + 1; i < size + 1; i++)
    {
        newArray[i] = arr[i-1];
    }
    size++;
    delete[] arr;
    arr = newArray;
}
void pop_middle(int*& arr, int& size)//delete an element from the middle
{
    int middle_index = (size - 1) / 2;
    size--;
    int* newArray = new int[size];
    for (int i = 0; i < middle_index; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = middle_index; i < size; i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[] arr;
    arr = newArray;
}
void push_back(int *&arr, int &size, const int value)
{
    int* newArray = new int[size + 1];
    newArray[size] = value;
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }
    size++;
    delete[] arr;
    arr = newArray;
}
void pop_back(int*& arr, int& size)
{
    size--;
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }
    delete[] arr;
    arr = newArray;
}

int main()

{
    int size;
    cout << "Enter number of elemens in the array: " << endl;
    cin >> size;
    int* array = new int[size];
    FillArray(array, size);
    ShowArray(array, size);
    push_begin(array, size, 50);
    ShowArray(array, size);
    pop_begin(array, size);
    ShowArray(array, size);
    push_middle(array, size, 8);
    ShowArray(array, size);
    pop_middle(array, size);
    ShowArray(array, size);
    push_back(array, size, 94);
    ShowArray(array, size);
    pop_back(array, size);
    ShowArray(array, size);

    
    return 0;

}


