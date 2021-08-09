// Link : https://leetcode.com/problems/remove-invalid-parentheses/submissions/
// Name : Remove Invalid Parentheses
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

bool isValid(string s)
{
    int t = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') t++;
        else if(s[i] == ')') {
            if(t > 0) t--;
            else return false;
        }
    }
    return t == 0;
}
vector<string> removeInvalidParentheses(string s)
{
    queue<string> q;
    unordered_set<string> st;
    int sz = s.size();
    vector<string> res;
    q.push(s);
    st.insert(s);
    bool found = false;
    while (!q.empty()){
        string curr = q.front();
        q.pop();
        if (found && curr.size() < sz)
            continue;
        if (isValid(curr)){
            found = true;
            sz = curr.size();
            res.push_back(curr);
            continue;
        }
        for(int i = 0; i < curr.size(); i++){
            if(curr[i] == '(' || curr[i] == ')'){
                string t = curr;
                t.erase(i,1);
                if(st.find(t) == st.end()){
                    st.insert(t);
                    q.push(t);
                }   
            }
        }
    }
    return res;
}
int main()
{
    string in;
    cin >> in;
    vector<string> res = removeInvalidParentheses(in);
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}