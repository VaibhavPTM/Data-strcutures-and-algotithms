// Link : https://leetcode.com/problems/basic-calculator/
// Topic : stack (Hard - leetcode)
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int> , grater<int> >
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"

int calculate(string s){
    stack<int> st;
    int ans = 0;
    int sing = 1;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            int n = 0;
            while(isdigit(s[i])){
                n = (n * 10) + (s[i] - '0');
                i++;
            }
            i--;
            n *= sing;
            sing = 1;
            ans += n;
        }
        else if(s[i] == '('){
            st.push(ans);
            ans = 0;
            st.push(sing);
            sing = 1;
        }
        else if(s[i] == ')'){
            ans *= st.top();
            st.pop();
            ans += st.top();
            st.pop();
        }
        else if(s[i] == '-'){
            sing = -1;
        }
    }
    return ans;
}

int main()
{
    // Only +, -,( and ) are velid
    string str;
    cin>>str;

    cout<<calculate(str);
    return 0;
}