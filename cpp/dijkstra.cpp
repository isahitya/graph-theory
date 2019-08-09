#include<vector>
#include<queue>
#include<iostream>
#include<functional>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt)
{
    adj[u].push_back(pair<int,int>(v,wt));
    adj[v].push_back(pair<int,int>(u,wt));
}
int *wgt;
class Compare
{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
    return wgt[a.first]>wgt[b.first];
    }
};
//Parameters: adjacency matrix, number of nodes, source, destination
void dijkstra(vector<pair<int,int>> adj[],int n,int src,int dst)
{
    int i;
    int visited[n];
    int weight[n];
    int path[n];
    wgt=weight;
    for(i=0;i<n;++i)
    {
        visited[i]=0;
        weight[i]=-1;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    pq.push(pair<int,int>(src,0));
    weight[src]=0;
    int sum;
    pair<int,int> c,a;//current,adjacent
    while(!pq.empty())
    {
        c=pq.top();
        pq.pop();
        visited[c.first]=1;
        if(c.first==dst)break;
        for(i=0;i<(adj[c.first].size());++i)
        {   
            a=adj[c.first][i];
            sum=weight[c.first]+a.second;
            if(a.first==src || visited[a.first]==1)continue;
            if(weight[a.first]!=-1 && sum>=weight[a.first])continue;                                    
            weight[a.first]=sum;
            path[a.first]=c.first;
            pq.push(pair<int,int>(a.first,a.second));
        }
    }
    if(visited[dst]==1)
    {
        cout<<"Shortest Distance: "<<weight[dst]<<endl;
        i=dst;
        cout<<"Path: ";
        while(1)
        {
            cout<<i;
            if(i==src)break;
            cout<<" <- ";
            i=path[i];
        }
    }else cout<<"No path.";
}

int main()
{
    int n=5;    
    vector<pair<int,int>> adj[n];//adjacency matrix, an array of vectors.
    addEdge(adj, 0, 1,10); 
   // addEdge(adj, 0, 4,20);
    addEdge(adj, 1, 2,30); 
    addEdge(adj, 1, 3,40); 
    addEdge(adj, 1, 4,50); 
    addEdge(adj, 2, 3,60); 
    addEdge(adj, 3, 4,70);
    dijkstra(adj,n,0,4);
    return 0;
}