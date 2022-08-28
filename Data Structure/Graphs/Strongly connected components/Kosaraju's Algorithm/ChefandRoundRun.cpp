// Name : Chef and Round Run
// Link : https://www.codechef.com/problems/CHEFRRUN

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
#define max 1000001
#define endl "\n"
using namespace std;

vi ar[max],tra[max],SCC,order;
bool vis[max];
int val[max];

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
    SCC.pb(node);
}

int main()
{
    int t,res,n;
    cin>>t;
    while(t--){
        res = 0,order.clear();
        cin>>n;
        forj(i,n){
            vis[i] = false,ar[i].clear(),tra[i].clear();
            cin>>val[i];
        }
        // creating a graph
        forj(i,n){
            int a = i;
            int b = (i + val[i] + 1) % n;
            ar[a].pb(b);
            tra[b].pb(a);
        }
        forj(i,n){
            if(!vis[i])
            dfs(i);
        }
        forj(i,n){
            vis[i] = false;
        }

        reverse(order.begin() , order.end());
        for(int i:order){
            if(!vis[i]){
                SCC.clear();
                dfs1(i);

                if(SCC.size() == 1 && (SCC[0] != ar[SCC[0]][0])) continue; // it means a single node don't have a self cycle

                res += SCC.size();
            }
        }
        cout<<res<<endl;
    }
    return 0;
}