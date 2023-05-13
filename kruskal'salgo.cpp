 #include<iostream>
#include<algorithm>
using namespace std;
class edge
{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(edge e1,edge e2)
{
    return (e1.weight<e2.weight);
}
int findparent(int v,int* parent)
{
    if(v==parent[v])
    {
        return v;
    }
    findparent(parent[v],parent);
}
void kruskal(edge *input,int n,int e)
{
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    edge *output=new edge[n-1];
    int count=0;
    int k=0;
    while(count<n-1)
    { edge current=input[k];
      int v1p=findparent(current.source,parent);
      int v2p=findparent(current.dest,parent);
      if(v1p!=v2p)
      {
          output[count]=current;
           count++;
           parent[v1p]=v2p;
      }
      k++;
        
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].dest<<endl;
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
    edge *input=new edge[e];
    for(int i=0;i<e;i++)
    {
      int first,second,weight;
      cin>>first>>second>>weight;
      input[i].source=first;
      input[i].dest=second;
      input[i].weight=weight;
    }
    sort(input,input+e,compare);
      kruskal(input,e,n);

}
