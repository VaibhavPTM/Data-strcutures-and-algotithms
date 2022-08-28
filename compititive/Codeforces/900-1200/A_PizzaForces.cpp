// Link : https://codeforces.com/problemset/problem/1555/A
// Topic : brute force, math
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

int main() {
    // https://codeforces.com/problemset/submission/1555/124430870
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        if(n <= 6) {
            cout << 15 << endl;
        }
        else if(n % 8 == 0) {
            cout << (n / 8) * 20 << endl;
        }
        else if(n % 10 == 0) {
            cout << (n / 10) * 25 << endl;
        }
        else {
            int t = n % 6;
            // cout << t << endl;
            if(t == 0) cout << (n / 6) * 15 << endl;
            else {
                if(t <= 2) {
                    cout << ((n / 6) - 1) * 15 + 20 << endl;
                }
                else if(t >= 5) cout << ((n / 6) + 1) * 15 << endl;
                else cout << ((n / 6) - 1) * 15 + 25 << endl;
            }
        }
    }
    return 0;
}