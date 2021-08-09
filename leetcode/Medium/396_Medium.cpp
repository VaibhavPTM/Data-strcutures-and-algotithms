// Link : https://leetcode.com/problems/rotate-function/
// Topic : Rotate Function
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
// Brute force approch (n^2)
// int maxRotateFunction(vector<int> &nums) {
//     int res = INT_MIN;
//     int t = nums.size();
//     for (int i = 0; i < nums.size(); i++) {
//         int tres = 0;
//         int k = 0;
//         for (int j = t; j < nums.size(); j++) {
//             tres += (k * nums[j]);
//             k++;
//         }
//         for (int j = 0; j < t; j++) {
//             tres += (k * nums[j]);
//             k++;
//         }
//         t--;
//         res = max(res, tres);
//     }
//     return res;
// }

int main()
{
    // Constraints:
    //     n == nums.length
    //     1 <= n <= 105
    //     -100 <= nums[i] <= 100

    return 0;
}