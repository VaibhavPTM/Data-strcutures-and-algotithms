#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    string s;
    cin >> s;
    int ar[26] = {};
    for(char &c : s) {
        ar[c-'A']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++) if(ar[i]&1) odd++;
    if(odd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    s.clear();
    for(int i = 0; i < 26; i++) {
        if(ar[i] % 2 == 0) {
            for(int j = 0; j < ar[i]/2; j++) {
                s.push_back((char)('A'+i));
            }
        }
    }
    for(int i = 0; i < 26; i++) {
        if(ar[i] % 2) {
            for(int j = 0; j < ar[i]; j++) s.push_back(i + 'A');
        }
    }
    for(int i = 25; i >= 0; i--) {
        if(ar[i] % 2 == 0) {
            for(int j = 0; j < ar[i]/2; j++) {
                s.push_back((char)('A'+i));
            }
        }
    }
    cout << s << endl;
    
    return 0;
}