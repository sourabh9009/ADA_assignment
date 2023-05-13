//This program contains qno 10:-

#include <iostream>
using namespace std;
class Array
{
    int arr[100];
    int size;

public:
    Array(int siz)
    {
        size = siz;
        cin >> size;
        cout << "enter the elements of an array :" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        cout << "your array elements are :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void insertion_sort()
    {

        for (int i = 1; i < size; i++)
        {
            int z = i;
            for (int j = z - 1; j >= 0; j--)
            {
                if (arr[z] < arr[j])
                {
                    int temp = arr[z];
                    arr[z] = arr[j];
                    arr[j] = temp;
                }
                z--;
            }
        }
    }
};

int main()
{
    int size, num;
    cout << "enter the size of an array " << endl;
    Array arr(size);
    arr.insertion_sort();
    arr.display();
    
    }
