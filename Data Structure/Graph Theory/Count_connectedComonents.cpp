// This is a problem for HackerEarch and the name is Connected Components in a Graph
// Link : https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include<iostream>
#include<vector>
using namespace std;
int vertex;
int edge;
void impl_graph(vector<int> graph[]){
    
    while (edge--)
    {
        int source, root;
        cin>>source>>root;
        graph[source].push_back(root);
        graph[root].push_back(source);
    }
}

void dfs(vector<int> graph[], vector<bool>& discoverd, int v){
    discoverd[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        if (!discoverd[child])
        {
            dfs(graph,discoverd,child);
        }
    }
    
}

int main()
{
    
    cin>>vertex>>edge;
    int count = 0;
    vector<int> graph[vertex + 1];
    vector<bool> discover(vertex + 1);
    impl_graph(graph);
    for (int i = 1; i <= vertex; i++)
    {
        if(!discover[i]){
            dfs(graph,discover,i);
            count++;
        }
    }
    cout<<count;
    return 0;
}

// We can also like this but it takes too much memory in the starting
/*
using namespace std;
int n,m;
vector<int> adj[100005];
int visited[100005];
void dfs(int a)
{
    visited[a] = 1;
    for(int i=0;i<adj[a].size();i++)
    {
        if(visited[adj[a][i]] == 0)
        {
            dfs(adj[a][i]);
        }
    }
}
int main()
{
    int i,j,k,l,p,t,u,v;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    p = 0;
    for(i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            p++;
        }
    }
    cout<<p<<"\n";
}
*/