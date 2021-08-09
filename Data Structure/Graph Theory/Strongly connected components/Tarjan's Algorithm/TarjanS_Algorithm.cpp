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

vi ar[1001];
bool vis[1001],onStack[1001];
int in[1001],low[1001];
stack<int> st;
int timer = 1,scc=0;

void dfs(int node){
    vis[node] = true;
    st.push(node);
    in[node] = low[node] = timer++;
    onStack[node] = true;
    for(int i : ar[node]){
        if(vis[i] == true && onStack[i] == true){
            low[node] = min(low[node],in[i]);
        }
        else if(vis[i] == false){
            dfs(i);
            low[node] = min(low[node],low[i]);
        }
    }
    if(in[node] == low[node]){
        scc++;
        cout<<"SCC #"<<scc<<endl;
        int u;
        while(1){
            u = st.top();
            st.pop(),onStack[u] = false;
            cout<<u<<" ";
            if(u == node) break;
        }
        cout<<endl;
    }
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while(e--){
        cin>>a>>b,ar[a].pb(b);
    }
    fori(i,v){
        if(!vis[i]){
            dfs(i);
        }
    }
    return 0;
}