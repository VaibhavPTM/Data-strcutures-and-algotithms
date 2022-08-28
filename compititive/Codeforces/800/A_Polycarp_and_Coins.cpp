// Link : https://codeforces.com/problemset/problem/1551/A
// Topic : math, greedy
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
        int n;
        cin >> n;
        int t = n / 3;
        int t2 = n % 3;
        if(t2 == 0) {
            cout << t << " " << t << endl;
        }
        else if (t2 == 1) {
            cout << t + 1 << " " << t << endl;
        }
        else {
            cout << t << " " << t + 1 << endl;
        }
    }
    return 0;
}