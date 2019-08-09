#include<vector>
#include<iostream>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v);
        adj[v].push_back(u);//Remove this line to make a directed graph
}

bool dfs(vector<int> adj[],int n,int src,int dst)
{
int visited[n];
vector<int> stk;
stk.push_back(src);
int c,a;//current,adjacent
while(!stk.empty())
{
c=stk.back();
stk.pop_back();
if(c==src && visited[c]==1)continue;
    for(int i=0;i<adj[c].size();++i)
    {
        a=adj[c][i];
        if(a==src || visited[a]==1)
        {
            ++i;
            continue;
        }
        visited[a]=1;        
        if(a==dst)break;
        else stk.push_back(a);        
    }
    if(visited[dst]==1)break;
}//stk loop
if(visited[dst]==1)return true;
return false;
}

int main()
{   
    int n=5;    
    vector<int> adj[n];//adjacency matrix, an array of vectors.
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2); 
    //addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    //addEdge(adj, 2, 3); 
    //addEdge(adj, 3, 4);
    cout<<dfs(adj,n,0,3)<<endl;
    return 0;
}