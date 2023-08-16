#include<iostream>
using namespace std;

void insertionSort(int *array, int size)
{
    int key, j;
    for(int i = 1; i<size; i++)
    {
        key = array[i];//take value
        j = i;
        while(j > 0 && array[j-1]>key)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;   //insert in right place
    }
}

void display(int *array, int size)
{
    for(int i = 0; i<size; i++)
        cout << array[i]<<endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting: "<<endl;
    display(arr, n);
    insertionSort(arr, n);
    cout << "Array after Sorting: "<<endl;
    display(arr, n);
}
