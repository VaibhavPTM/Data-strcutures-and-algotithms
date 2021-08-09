// T(n) = 2 * T(i) * T(i-1);

#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
#define iil long long int
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
#define max 1000000007
#define endl "\n"
// recursion
iil help(iil n){
    if(n == 0 || n == 1){
        return 2;
    }
    long long int sum = 0;
    for(iil i = 1; i < n; i++){
        sum += 2 * help(i) * help(i-1);
    }
    return sum % max;
}
// dp  
iil help1(int n){
    long long int dp[n+1];
    dp[0] = dp[1] = 2;
    dp[2] = 2 * dp[0] * dp[1];
    for(int i = 3; i <= n; i++){ // i represents n
        dp[i] = dp[i-1] + 2 * dp[i-1] * dp[i-2];
    }
    return dp[n] % max;
}
int main()
{
    iil n;
    cin>>n;
    cout<<help(n)<<endl;
    cout<<help1(n);
    return 0;
}