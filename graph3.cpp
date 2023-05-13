#include<iostream>
#include<queue>
using namespace std;
void printbfs(int **edges,int n,bool *visited,int vs)
{
    queue<int> pending;
    pending.push(vs);
    visited[vs]=true;
    while(pending.size()!=0)
    {
        int front=pending.front();
        pending.pop();
        cout<<front<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==front)
            {
                continue;
            }
            if(edges[front][i]==1&&!visited[i])
            {
                pending.push(i);
                visited[i]=true;
            }
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
for(int i=0;i<n;i++)
{
if(visited[i]==false)
{
printbfs(edges,n,visited,i);
}
}
for(int i=0;i<n;i++)
{
    delete [] edges[i];
}
delete [] edges;
delete [] visited;
}
