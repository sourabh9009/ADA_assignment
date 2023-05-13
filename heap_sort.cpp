#include <iostream>


using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
void heapSort(int arr[], int n) {
    if(n==0)
    {
        return;
    }
    int i=1;
    while(i<n)
    {
        int child=i;
        while(child>0)
        { int parent=(child-1)/2;
          if(arr[child]<arr[parent])
          {
              int temp=arr[parent];
              arr[parent]=arr[child];
              arr[child]=temp;
          }
         else
         {
             break;
         }
        child=parent;
        
        
        }
        i++;
    }
    int size=n;
    while(size>0)
    {
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        int parent=0;
        int leftchild=(2*parent)+1;
        int rightchild=(2*parent)+2;
        size--;
     while(leftchild<size)
     {
         int minindex=parent;
         if(arr[leftchild]<arr[minindex])
         {
             minindex=leftchild;
         }
         if(rightchild<size&&arr[rightchild]<arr[minindex])
         {
             minindex=rightchild;
         }
         if(minindex==parent)
         {
             break;
         }
         temp=arr[minindex];
         arr[minindex]=arr[parent];
         arr[parent]=temp;
         parent=minindex;
         leftchild=(2*parent)+1;
         rightchild=(2*parent)+2;
     }
        
    }
     
    // Write your code
}
