// Link : https://leetcode.com/problems/push-dominoes/
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
string pushDominoes(string d)
{
    int n = d.size();
    vector<int> forc(n, 0);
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 'R')
            f = n;
        else if (d[i] == 'L')
            f = 0;
        else
            f = max(f - 1, 0);
        forc[i] += f;
    }
    f = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (d[i] == 'L')
            f = n;
        else if (d[i] == 'R')
            f = 0;
        else
            f = max(f - 1, 0);
        forc[i] -= f;
    }
    string res;
    for (int i : forc)
    {
        cout << i << " ";
        if (i > 0)
            res.push_back('R');
        else if (i < 0)
            res.push_back('L');
        else
            res.push_back('.');
    }
    return res;
}
int main(){
    /*
    Constraints:
        n == dominoes.length
        1 <= n <= 105
        dominoes[i] is either 'L', 'R', or '.'.*/

    return 0;
}