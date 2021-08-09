// Name : Bertown roads
// Link : https://codeforces.com/problemset/problem/118/E

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

vi graph[100001];
vector<pair<int,int>> edgeList;
int in[100001], low[100001] , timer;
bool vis[100001];
bool hasBridge;
void dfs(int node, int par){
    vis[node] = true;
    low[node] = in[node] = timer++;
    for(int child : graph[node]){
        if(child == par){
            continue;
        }
        else if(vis[child]){
            // it means it's back edge
            low[node] = min(low[node] , in[child]);
            if(in[node] > in[child]) // in time of node is grater then in time of child because it's time would be assingd before child
            edgeList.pb({node,child});
        }
        else{
            dfs(child,node);
            if(low[child] > in[node]){
                // find a bridge
                hasBridge = true;
                return;
            }
            edgeList.pb({node,child});
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while(e--){
        cin>>a>>b;
        graph[a].pb(b),graph[b].pb(a);
    }
    dfs(1,-1);
    
    if(hasBridge){
        cout<<0;
    }
    else{
        for(auto e : edgeList){
            cout<<e.f<<" "<<e.s<<endl;
        }
    }
    return 0;
}