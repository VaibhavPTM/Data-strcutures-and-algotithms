// Link : https://leetcode.com/problems/perfect-squares/
// Topic : leetcode - 279
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
int numSquares(int n) {
    if (n <= 3)
        return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++){
        dp[i] = i; // maximum square that we can make
        for (int j = 1; j * j <= i; j++){
            // now we have to minimaize the number of square
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << numSquares(n);
    return 0;
}