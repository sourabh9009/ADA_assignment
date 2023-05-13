#include<iostream>
#include<climits>
using namespace std;
int minvertex(int *distance,bool* visited,int n)
{
    int minver=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(minver==-1||distance[minver]>distance[i]))
        {
            minver=i;
        }
    }
    return minver;
}
void dijs(int **arr,int n,int e)
{
    bool *visited=new bool[n];
    int *distance=new int[n];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    parent[0]=-1;
    distance[0]=0;
    for(int i=0;i<n;i++)
    {
        int minver=minvertex(distance,visited,n);
        visited[minver]=true;
        for(int j=0;j<n;j++)
        {
            if(arr[minver][j]!=0 && !visited[j])
            {
              int dis=distance[minver]+arr[minver][j];
              if(dis<distance[j])
              {
                  distance[j]=dis;
              }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }

}
int main()
{
    cout<<"enter no of vertices"<<endl;
    int n;
    cin>>n;
    cout<<"enter no of edges"<<endl;
    int e;
    cin>>e;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        arr[f][s]=w;
        arr[s][f]=w;
    }
    dijs(arr,n,e);
    for(int i=0;i<n;i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
}
