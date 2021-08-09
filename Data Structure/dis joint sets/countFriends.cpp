// Link : https://www.hackerearth.com/problem/algorithm/count-friends-190fcb36/
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define si set<int>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define mod 1000000007
#define sin(n) scanf("%d",&n)
#define endl "\n"
vector<int> par(100001,-1);
int fin(int x){
    if(par[x] < 0){
        return x;
    }
    return par[x] = fin(par[x]);
}

int main()
{
    int n , e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        int x = fin(a);
        int y = fin(b);
        if(x != y){
            par[x] += par[y];
            par[y] = x;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        int t = fin(i);
        cout<<abs(par[t])-1<<" ";
    }
    
    return 0;
}