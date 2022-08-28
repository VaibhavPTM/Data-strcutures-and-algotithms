// Link : 
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int i = 0, j = 0, res = 0, t = 0;
    map<int,int> mp;
    while(j < n){
        if(mp.find(ar[j]) == mp.end() || mp[ar[j]] == 0) {
            mp[ar[j]]++;
            j++;
            t++;
            res = max(res,t);
        }
        else {
            mp[ar[i]]--;
            i++;
            t--;
        }
    }
    cout << res;
    return 0;
}