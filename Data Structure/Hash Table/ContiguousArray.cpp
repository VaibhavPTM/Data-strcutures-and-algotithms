// Link : https://leetcode.com/problems/contiguous-array/
// Topic :
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> mp;
    int cnt = 0, res = 0;
    for (int i = 0; i < nums.size(); i++) {
        cnt += nums[i] == 0 ? -1 : 1;
        if (cnt == 0) {
            res = max(res, i + 1);
        }
        else if (mp.find(cnt) != mp.end()) {
            res = max(res, i - mp[cnt]);
        }
        else {
            mp[cnt] = i;
        }
    }
    return res;
}
int main() {
    // Constraints:
    //     1 <= nums.length <= 105
    //     nums[i] is either 0 or 1.
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    

    return 0;
}