// Link : https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
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
int equilibriumPoint(long long a[], int n)
{
    int af[n] = {0}, ab[n] = {0};
    af[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        af[i] = af[i - 1] + a[i];
    }
    ab[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ab[i] = ab[i + 1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (af[i] == ab[i])
            return i;
    }
    return -1;
}
int main()
{
    int A[] = {1, 3, 5, 2, 2};
    int n = 5;
    cout << equilibriumPoint(a, n);
    return 0;
}