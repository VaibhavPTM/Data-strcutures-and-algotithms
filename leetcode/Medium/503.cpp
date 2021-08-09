// Link : https://leetcode.com/problems/next-greater-element-ii/
// Topic : Next Greater Element II
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define ff first
#define ss second
#define print(x) for (auto it : x) cout << it << " ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i % n])
        {
            res[st.top()] = nums[i % n];
            st.pop();
        }
        st.push(i % n);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Constraints:
    //     1 <= nums.length <= 104
    //     -109 <= nums[i] <= 109

    return 0;
}