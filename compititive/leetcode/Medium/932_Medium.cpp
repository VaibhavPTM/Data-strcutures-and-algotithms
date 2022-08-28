// Link : https://leetcode.com/problems/beautiful-array/
// Topic : Beautiful Array
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
vector<int> beautifulArray(int n) {
    vector<int> res = {1};
    while (res.size() < n) {
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] * 2 - 1 <= n) {
                odd.push_back(res[i] * 2 - 1);
            }
            if (res[i] * 2 <= n) {
                even.push_back(res[i] * 2);
            }
        }
        res.clear();
        // for(auto & i : odd) res.push_back(i);
        // for(auto & i : even) res.push_back(i);
        res.insert(res.end(), odd.begin(), odd.end());
        res.insert(res.end(), even.begin(), even.end());
    }
    return res;
}
int main()
{
    // Constraints:
    //     1 <= n <= 1000
    int n;
    cin >> n;
    vi v = beautifulArray(n);
    for(int &i : v) cout << i << " ";

    return 0;
}