#include<iostream>
#include<climits>
using namespace std;
int minvertex(int *weight,bool* visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(minvertex==-1||weight[minvertex]>weight[i]))
        {
            minvertex=i;
        }
    }
    return minvertex;
}
void prim(int** input,int n,int e)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int *weight=new int[n];
    
    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
    }
    int *parent=new int[n];
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n;i++)
    {
        int minver=minvertex(weight,visited,n);
        visited[minver]=true;
        for(int j=0;j<n;j++)
        {
            if(input[minver][j]!=0&&!visited[j])
            {
                if(weight[j]>input[minver][j])
                {
                    weight[j]=input[minver][j];
                    parent[j]=minver;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    delete [] parent;
    delete [] visited;
    delete [] weight;
}
int main()
{
    cout<<"enter number of vertices "<<endl;
    int n;
    cin>>n;
    cout<<"enter number of edges"<<endl;
    int e;
    cin>>e;
    int **ed=new int*[n];
    for(int i=0;i<n;i++)
    {
        ed[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            ed[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int first,second,weight;
        cin>>first>>second>>weight;
        ed[first][second]=weight;
        ed[second][first]=weight;
    }
    prim(ed,n,e);
    for(int i=0;i<n;i++)
    {
        delete [] ed[i];
    }
    delete [] ed;
    }
