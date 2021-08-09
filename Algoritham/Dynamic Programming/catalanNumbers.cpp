// The number of BSTs with n nodes is called Catalan Number and is denoted by Cn
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
#define sin(n) scanf("%d",&n)
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define mx 1000000007
#define endl "\n"

int memo[1001];

int help(int n){
    if(n == 0) return 1;
    if(memo[n] != -1) return memo[n];
    memo[n] = 0;
    for(int i = 1; i <= n; i++){
        memo[n] += help(i-1) * help(n-i);
    }
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof memo);
    int n;
    sin(n);
    cout<<"Number of nodes : "<<help(n);
    return 0;
}