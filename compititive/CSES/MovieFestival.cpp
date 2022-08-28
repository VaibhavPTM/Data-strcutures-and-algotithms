// Link : https://cses.fi/problemset/task/1629
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
    vector<pair<int,int>> ar;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        ar.push_back({b,a});
    }
    sort(ar.begin(),ar.end());
    int i = 0, t = 0, res = 0;
    while(i < n) {
        if(t <= ar[i].second) {
            res++;
            t = ar[i].first;
            i++;
        }
        else i++;
    }
    cout << res;

    return 0;
}