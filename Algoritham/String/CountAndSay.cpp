// Link : https://leetcode.com/problems/count-and-say/
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
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define mod 1000000007
#define sin(n) scanf("%d", &n)
#define endl "\n"

string countAndSay(int n)
{
    if (n == 1){
        return "1";
    }
    string res = "1", curr;
    for (int i = 2; i <= n; i++){
        curr = "";
        for (int j = 0; j < res.size();){
            int start = j;
            int temp = 0;
            while (j < res.size() && res[start] == res[j]){
                j++;
                temp++;
            }
            curr.push_back(temp + '0');
            curr.push_back(res[start]);
        }
        res = curr;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n);
    return 0;
}