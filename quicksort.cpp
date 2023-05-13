//This program contains qno 17:-

#include<iostream>
using namespace std;
int partition(int [],int,int);
void Sort(int [],int,int);
void Sort(int input[],int start,int end)
{
	if(start>=end)
	return;
 int ans=partition(input,start,end);
 Sort(input,start,ans-1);
 Sort(input,ans+1,end);
 
}
int partition(int input[],int start,int end)
{
	int count=0;
	for(int i=start;i<=end;i++)
	{
		if(input[i]<input[start])
		count++;
	
	}
	int p=start+count;
	int temp=input[p];
	input[p]=input[start];
	input[start]=temp;
	int i=start,j=end;
	while(i<p&&j>p)
	{
		if(input[i]<input[p])
		i++;
		else if(input[j]>input[p])
		j--;
		else
		{
			int temp=input[i];
			input[i]=input[j];
			input[j]=temp;
		}
	}
	return p;
	
}

void sort(int input[],int n)
{
	if(n<=1)
	return;
	 Sort(input,0,n-1);
	
	
}





int main()
{
	int n;
    cout<<"enter size of array"<<endl;
	cin>>n;
	int *input=new int[n];
    cout<<"enter elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}
	sort(input,n);
	cout<<endl;
    cout<<"elements in sorted order are"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<input[i]<<" ";
		
	}
	delete [] input;
}
