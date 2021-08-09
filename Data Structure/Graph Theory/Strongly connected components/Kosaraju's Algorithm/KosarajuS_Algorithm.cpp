// Here we are going to find strongly connected componants for directed graph
#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

vi ar[1001],tra[1001],nodes,ncc;
bool vis[1001];

void dfs(int node){
    vis[node] = true;
    for(int i : ar[node]){
        if(!vis[i])
        dfs(i);
    }
    nodes.pb(node);  // it's like we count a time time (push back nodes depands on thair out time)
}
void dfs2(int node){
    vis[node] = true;
    for(int i : tra[node]){
        if(!vis[i])
        dfs2(i);
    }
    ncc.pb(node);  // it's like we count a time time (push back nodes depands on thair out time)
}

int main()
{
    int v,e;
    cin>>v>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].pb(b);
        tra[b].pb(a);
    }
    for(int i = 1;i <= v; i++) if(!vis[i]) dfs(i);

    for(int i = 1;i <= v; i++) vis[i] = false;
    
    for(int i = 1;i <= v; i++){
        if(!vis[nodes[v-i]]){
            ncc.clear();
            dfs2(nodes[v-i]);
            cout<<"dfs(i) would call from "<<nodes[v-i]<<" and its connected componants are (in one strongly connected graph"<<endl;
            for(int j : ncc){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}