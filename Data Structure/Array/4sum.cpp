// Link :
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
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> res;

    for (int i = 0; i < n - 3; i++){
        for (int j = i + 1; j < n - 2; j++){
            int t = target - nums[i] - nums[j];
            int l = j + 1, r = n - 1;
            while (l < r){
                if (nums[l] + nums[r] == t){
                    res.insert({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < t)
                    l++;
                else
                    r--;
            }
        }
    }
    vector<vector<int>> res2(res.begin(), res.end());
    return res2;
}
int main(){
    int t;
    vector<int> v;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>t;
        v.push_back(t);
    }
    cin >> t;
    vii res = fourSum(v,t);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] <<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}