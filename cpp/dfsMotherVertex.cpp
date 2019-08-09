#include<vector>
#include<iostream>
using namespace std;

class Graph
{
private:
vector<int> *adj;
int n;
int *visited;
void dfsUtil(int v)
{
    if(visited[v]==1)return;    
    int a;
    visited[v]=1;
    for(int i=0;i<adj[v].size();++i)
    {
        a=adj[v][i];
        if(visited[a]!=1)dfsUtil(a);
    }    
    //cout<<v<<endl;                  //Do whatever
}
public:
Graph(int n)
{
    this->adj=new vector<int>[n];
    this->visited=(int*)malloc(sizeof(int)*n);
    this->n=n;
}
~Graph()
{
    free(this->visited);
}
void addEdge(int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);//Add this line to make a directed graph
}
void clearVisited()
{
    for(int i=0;i<n;++i)visited[i]=0;
}
void dfs(int v)
{
    dfsUtil(v);
    clearVisited();
}
int lastFinishingNode()
{
    int lf;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            dfsUtil(i);
            lf=i;
        }
    }
    clearVisited();
    return lf;
}
int motherVertex()
{
    int lf;
    lf=lastFinishingNode();
    dfsUtil(lf);
    for(int i=0;i<n;++i)
    {
        if(visited[i]!=1)
        {
            return -1;
        }
    }
    return lf;
}
};
int main()
{   
    int n=6;    
    Graph g(n);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 4); 
    g.addEdge(3, 1); 
    g.addEdge(3, 5); 
    g.addEdge(4, 5); 
    g.dfs(0);
    cout<<"Last Finishing: "<<g.lastFinishingNode()<<endl;
    cout<<"Mother Vertex: "<<g.motherVertex()<<endl;

    return 0;
}