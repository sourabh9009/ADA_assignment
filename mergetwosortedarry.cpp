//This program contains qno 14:-

#include<iostream>
 using namespace std;
 void merge(int a[],int b[],int size1,int size2)
    {
        int newarr[size1+size2];
        int i=0,j=0,k=0;
        while(i<size1&&j<size2)
       {
           if(a[i]<b[j])
           {
               newarr[k]=a[i];
               k++;
               i++;

           }
           else
           {
               newarr[k]=b[j];
               k++;
               j++;
           }

       }
       while(i<size1)
       {
           newarr[k]=a[i];
           i++;
           k++;

       }
       while(j<size2)
       {
           newarr[k]=b[j];
           j++;
           k++;
       }
       cout<<"New array is"<<endl;
       for(int i=0;i<(size1+size2);i++)
       {
           cout<<newarr[i]<<" ";
       }
    }
    int main()
 {
     int a[100];
     int b[100],size1,size2;
     cout<<"enter the size of first array "<<endl;
     cin>>size1;
     cout<<"enter the elements of first array in sorted order"<<endl;
     for(int i=0;i<size1;i++)
     {
         cin>>a[i];
     }
      cout<<"enter the size of second array  "<<endl;
     cin>>size2;
     cout<<"enter the elements of second array in sorted order"<<endl;
     for(int i=0;i<size2;i++)
     {
         cin>>b[i];
     }
     merge(a,b,size1,size2);
 }
