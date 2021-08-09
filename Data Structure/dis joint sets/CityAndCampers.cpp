#include <bits/stdc++.h>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define endl "\n"
using namespace std;

int sz[100005];
set<pair<int,int>> s;
int par[100005];


int find(int n){
    return (par[n] == 0) ? n : par[n] = find(par[n]);
}
void mearg(int x,int y){
    if(x == y) return;
    par[x] = y;
    s.erase(make_pair(sz[y],y));
    s.erase(make_pair(sz[x],x));
    sz[y] += sz[x];
    s.insert(make_pair(sz[y],y));
}
int main()
{
    ios_base::sync_with_stdio(0); 
    int n, q, a, b;
    cin>>n;
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        s.insert(make_pair(1,i));
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        a = find(a);
        b = find(b);
        mearg(a,b);
        auto end = s.end();end--;
        auto start = s.begin();
        cout<<(*end).first - (*start).first<<endl;
    }

    return 0;
}