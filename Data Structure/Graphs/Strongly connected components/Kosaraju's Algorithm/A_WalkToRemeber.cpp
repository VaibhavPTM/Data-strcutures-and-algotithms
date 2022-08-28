// Name : A Walk to Remember
// Link : https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/

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
#define max 100001
#define endl "\n"
using namespace std;

vi ar[max],tra[max],order,scc;
bool vis[max];
int ans[max];

void dfs(int node){
    vis[node] = true;
    for(int i : ar[node]){
        if(!vis[i])
        dfs(i);
    }
    order.pb(node);
}
void dfs1(int node){
    vis[node] = true;
    for(int i : tra[node]){
        if(!vis[i])
        dfs1(i);
    }
    scc.pb(node);
}
void updeteAns(){
    if(scc.size() <= 1){
        return;
    }
    for(int i : scc){
        ans[i] = 1;
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        ar[a].pb(b);
        tra[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i])
        dfs(i);
    }
    for(int i = 1; i <= n; i++){
        vis[i] = false;
    }
    reverse(order.begin(),order.end());
    for(int i : order){
        if(!vis[i]){
            scc.clear();
            dfs1(i);
            updeteAns();
        }
    }
    for(int i = 1; i<= n; i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}