#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) {
	 int *output=new int[n];
     output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
          if(arr[j]>=arr[i])
          {
              continue;
          }
            int possibleans=output[j]+1;
            if(possibleans>output[i])
            {
                output[i]=possibleans;
            }
        }
    }
    int finalans=0;
        for(int i=0;i<n;i++)
        {
            if(output[i]>finalans)
            {
                finalans=output[i];
            }
        }
    delete output;
    return finalans;
    // Write your code here
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
