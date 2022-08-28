// Link : https://cses.fi/problemset/task/2205
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

vector<string> getGrayCode(int n) {
    if(n == 1) {
        return {"0","1"};
    }
    vector<string> t = getGrayCode(n-1), res;
    for(int i = 0; i < t.size(); i++) {
        res.push_back("0"+t[i]);
    }
    for(int i = t.size()-1; i >= 0; i--) {
        res.push_back("1"+t[i]);
    }
    for(itn i 0; i < n; i++) {
        ar[i] = a[i-1] + ;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<string> res = getGrayCode(n);
    for(auto &str : res) {
        cout << str << endl;
    }
    return 0;
}