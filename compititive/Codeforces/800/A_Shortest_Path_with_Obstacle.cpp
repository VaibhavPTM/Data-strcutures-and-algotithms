// Link : https://codeforces.com/problemset/problem/1547/A
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int> , greater<int> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x1,y1,x2,y2,o1,o2;
        cin >> x1 >> y1 >> x2 >> y2 >> o1 >> o2;
        int res;
        if(x1 != x2 && y1 != y2) {
            res = abs(x2 - x1) + abs(y2 - y1);
        }
        else if(x1 == x2) {
            if(x1 == o1 && o2 > min(y1,y2) && o2 < max(y1, y2)) {
                res = abs(y2 - y1) + 2;
            }
            else {
                res = abs(y2 - y1);
            }
        }
        else {
            if(y1 == o2 && o1 > min(x1,x2) && o1 < max(x1, x2)) {
                res = abs(x2 - x1) + 2;
            }
            else {
                res = abs(x2 - x1);
            }
        }
        cout << res << endl;
    }
    return 0;
}