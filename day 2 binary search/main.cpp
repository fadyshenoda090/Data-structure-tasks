#include<iostream>

using namespace std;

int binarysearch(int arr[], int first, int last, int middle)
{
    while (first <= last)
    {
        int m =(last + first) / 2;

        if (arr[m] == middle)
        {
            return m;
        }
        else if (arr[m] < middle)
        {
            first = m + 1;
        }
        else
        {
            last = m - 1;

        }
    }

    return -1;  //
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40, 49 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int num;
    cout << "Enter the number that you want to find: \n";
    cin >> num;

    int result = binarysearch(arr, 0, n - 1, num);
    if (result == -1)
        cout << num << " Was Not Found" << endl;
    else
        cout << arr[result] << " Was Found At Index: " << result << endl;

    return 0;
}
