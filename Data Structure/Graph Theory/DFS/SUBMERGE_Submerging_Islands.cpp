#include<iostream>
#include<vector>
#include<set>


#define vi vector<int>
#define si set<int>
#define pb push_back

#define endl "\n"
using namespace std;

vi arr[100001];
int in[100001], low[100001];
int timer = 0;
int vis[100001];
set<int> s;


void dfs(int node, int par){
    vis[node] = true;
    in[node] = low[node] = timer++;
    int child = 0;
    for(int i : arr[node]){
        if(i == par)continue;
        if(vis[i]){
            low[node] = min(low[node], in[i]);
        }
        else{
            dfs(i,node);
            low[node] = min(low[node] , low[i]);
            if(low[i] >= in[node] && par != -1){
                s.emplace(node);
            }
            child++;
        }
    }
    if(par == -1 && child >= 2)s.emplace(node);
}
int main()
{
    int v,e,a,b;
    while (1)
    {
        cin>>v>>e;
        if(v == 0 && e == 0)break;


        for(int i = 1; i<= v; i++){
            arr[i].clear(),in[i] = 0, low[i] = 0,vis[i] = 0;
        }
        timer = 0, s.clear();
        while (e--)
        {
            cin>>a>>b;
            arr[a].pb(b);
            arr[b].pb(a);
        }
        dfs(1,-1);
        cout<<s.size()<<endl;
    }
    
    return 0;
}