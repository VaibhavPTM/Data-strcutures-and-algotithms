// Link : https://codeforces.com/problemset/problem/1559/D1
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

int par1[100001], par2[100001];

int find(int &x) {
    if(par1[x] == x) return x;
    return par1[x] = find(par1[x]);
}
int find2(int &x) {
    if(par2[x] == x) return x;
    return par2[x] = find2(par2[x]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m1, m2, res = 0;
    v(pii) ed;
    cin >> n >> m1 >> m2;
    
    for(int i = 1; i <= n; i++) par1[i] = i, par2[i] = i;
    for(int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        par1[find(a)] = find(b);
    }
    for(int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        par2[find2(a)] = find2(b);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(find(i) != find(j) && find2(i) != find2(j)) {
                par1[find(i)] = find(j);
                par2[find2(i)] = find2(j);
                ed.push_back({i,j});
                res++;
            }
        }
    }
    cout << res << endl;
    for(int i = 0; i < ed.size(); i++) {
        cout << ed[i].first << " " << ed[i].second << endl;
    }
    return 0;
}