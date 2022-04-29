#include<iostream>
using namespace std;

template<typename T>
void Max(T * arr, int size)
{
    T max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    cout << "The largest value is: " << max << endl;
}
template<typename T>
void Min(T * arr, int size)
{
    T min = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(min > arr[i])
            min = arr[i];
    }
    cout << "The smallest value is: " << min << endl;
}


int main()
{
    float *arr;
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    arr = new float[size];
    cout << "input the values of the array: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    Min(arr, size);
    Max(arr, size);
    return 0;
}