//This program contains qno 16:-

#include <iostream>
using namespace std;

void merge(int a[], int l, int u)
{
    int mid = (l + u) / 2;
    int newarr[(u - l) + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= u)
    {
        if (a[i] < a[j])
        {
            newarr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            newarr[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        newarr[k] = a[i];
        i++;
        k++;
    }
    while (j <= u)
    {
        newarr[k] = a[j];
        j++;
        k++;
    }
    for (int i = 0, k = l; k <= u; i++, k++)
    {
        a[k] = newarr[i];
    }
}
void mergesort(int arr[], int lower, int upper)
{
    if (lower >= upper)
    {
        return;
    }
    int mid = (lower + upper) / 2;
    mergesort(arr, lower, mid);
    mergesort(arr, mid + 1, upper);
    merge(arr, lower, upper);
}
int main()
{
    int a[100];
    int size1;
    cout << "enter the size of first array " << endl;
    cin >> size1;
    cout << "enter the elements of first array" << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> a[i];
    }

    mergesort(a, 0, size1 - 1);
    cout << " the sorted array is " << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << a[i] << " ";
    }
}
