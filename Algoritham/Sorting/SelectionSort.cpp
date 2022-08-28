#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if((s[i] == '1' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')) {
                res = 1;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }   
    return 0;
}