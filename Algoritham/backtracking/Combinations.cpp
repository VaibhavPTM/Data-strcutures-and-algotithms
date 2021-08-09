#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"
vii res;
void help(int n, int k, vi t, int curr){
    if(k == 0) res.pb(t);
    for(int i = curr; i <= n; i++){
        t.pb(i);
        help(n,k-1,t,i+1);
        t.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vi t;
    help(n, k, t, 1);

    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    combine(n,k);
    for(auto i : res){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}