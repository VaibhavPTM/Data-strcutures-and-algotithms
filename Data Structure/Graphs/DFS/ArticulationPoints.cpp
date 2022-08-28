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
 
vi graph[10001] , in, low;
vector<bool> vis;
set<int> arti_point;
int timer = 0;
void dfs(int node,int par){
    vis[node] = true;
    low[node] = in[node] = timer;
    timer++;
    int childeran = 0;
    for(int i : graph[node]){
        if(i == par)continue;
        if(vis[i]){
            // Finding a back edge
            low[node] = min(low[node],in[i]);
        }
        else{
            // Finding a forwerd edge
            dfs(i,node);
            low[node] = min(low[node] , low[i]);
            if(low[i] >= in[node] && par != -1){
                arti_point.emplace(node);
            }
            childeran++;
        }
    }
    if(par == -1 && childeran >= 2){
        arti_point.emplace(node);
    }
}
int main()
{
    int v,e,a,b;
    cin>>v>>e;
    vis.assign(v,false);
    in.assign(v,0);
    low.assign(v,0);
    while (e--)
    {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,-1);

    for(auto i : arti_point){
        if(arti_point.empty()){
            cout<<"no points";
            break;
        }
        cout<<i<<" ";
    }
    
    return 0;
}