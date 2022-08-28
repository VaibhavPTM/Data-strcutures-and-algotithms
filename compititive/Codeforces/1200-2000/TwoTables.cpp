// Link : https://codeforces.com/problemset/problem/1555/B
// Topic : brute force - 1300
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

int main()
{
    int t, w, h, x1, y1, x2, y2, th1, tw1;
    cin>>t;
    while(t--) {
        cin >> w >> h;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> tw1 >> th1;
        int th2 = y2 - y1;
        int tw2 = x2 - x1;
        int ans = INT_MAX;
        if (th1 + th2 > h && tw1 + tw2 > w)
        {
            cout << -1 << endl;
            continue;
        }
        if (tw1 + tw2 <= w)
            ans = min(ans, min(tw1 - x1, x2 - w + tw1));
        if (th1 + th2 <= h)
            ans = min(ans, min(th1 - y1, y2 - h + th1));
        cout << max(0, ans) << endl;
    }
    
    return 0;
}