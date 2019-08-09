#include<vector>
#include<iostream>
using namespace std;

class Graph
{
private:
vector<int> *adj;
int n;
int *visited;
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
    //adj[v].push_back(u);//Remove this line to make a directed graph
}
void dfs(int v)
{
    if(visited[v]==1)return;    
    visited[v]=1;
    int a;
    for(int i=0;i<adj[v].size();++i)
    {
        a=adj[v][i];
        if(visited[a]!=1)dfs(a);
    }    
    cout<<v<<endl;
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
    return 0;
}