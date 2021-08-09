// Link : https://leetcode.com/problems/max-points-on-a-line/
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
int maxPoints(vector<vector<int>> &points)
{
    int res = 1;
    unordered_map<double, int> m;
    for (int i = 0; i < points.size(); i++){
        m.clear();
        for (int j = i + 1; j < points.size(); j++){
            double slope = 0;
            if (points[i][0] == points[j][0]){
                slope = numeric_limits<double>::infinity();
            }
            else{
                slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
            }
            m[slope]++;
        }
        for (auto i : m){
            res = max(res, 1 + i.second);
        }
    }
    return res;
}
int main()
{
//     Constraints:
        // 1 <= points.length <= 300
        // points[i].length == 2
        // -104 <= xi, yi <= 104
        // All the points are unique.
    vii tt = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout<<maxPoints(tt);

    return 0;
}