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
#define s seconf
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

vi graph[1001];
bool dis[1001];
int low[1001], in[1001], timer = 0;

void dfs(int node, int par){
    dis[node] = true;
    in[node] = low[node] = timer;
    timer++;
    for(int child : graph[node]){
        if(child == par){continue;}
        else if(dis[child]){
            // above condition means that it's a back edge
            low[node] = min(low[node], in[child]);
        }
        else{
            // It's means that is a forwerd edge
            dfs(child,node);

            if(low[child] > in[node]){
                cout<<node<<" - "<<child<<" is a bridge\n";
            }

            low[node] = min(low[child], low[node]);
        }
    }
    
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while(e--){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }    
    dfs(1,-1);
    return 0;
}