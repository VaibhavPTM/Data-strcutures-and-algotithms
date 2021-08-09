#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

int dp[1001][1001];
int GetLenght(string s1, string s2){
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}
string getString(string s1, string s2){
    string ans;
    for (int i = s1.size(), j = s2.size(); i > 0 && j > 0;)
    {
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{

// Vaibhav
// vhiqv
    int t;
    cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;
        cout<<GetLenght(str1,str2)<<endl;
        cout<<getString(str1,str2);
    }
    return 0;
}