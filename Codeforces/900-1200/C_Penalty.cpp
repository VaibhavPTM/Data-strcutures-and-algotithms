// Link : https://codeforces.com/problemset/problem/1553/C
// Topic : bitmasks, brute force, dp, greedy
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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int res1 = 10, res2 = 10;
        int x = 0, y = 0;
        for(int i = 0; i < 10; i++) {
            int remaning = (10 - i + 1) / 2;
            if(x > y + remaning) {
                res1 = i;
                break;
            }
            if((i & 1) == 0) {
                if(s[i] != '0')
                    x++;
            }
            else if(s[i] == '1')y++;
        }
        x = y = 0;
        for(int i = 0; i < 10; i++) {
            int remaning = (10 - i) / 2;
            if(y > x + remaning) {
                res2 = i;
                break;
            }
            if((i & 1) == 1) {
                if(s[i] != '0')
                    y++;
            }
            else if(s[i] == '1')x++;
        }
        cout << min(res1, res2) << endl;
    }  
    return 0;
}