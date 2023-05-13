#include<iostream>
using namespace std;
void print(int **edges,int n,bool *visited,int sv)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
       if(i==sv)
       {
           continue;
       }
       if(edges[sv][i]==1&&visited[i]==false)
       {
           print(edges,n,visited,i);
       }
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
    int **edges=new int* [n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<"enter edges in between"<<endl;
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;

    }
bool *visited=new bool[n];
for(int i=0;i<n;i++)
{
    visited[i]=false;
}
print(edges,n,visited,0);
for(int i=0;i<n;i++)
{
    delete [] edges[i];
}
delete [] edges;
delete [] visited;
}
