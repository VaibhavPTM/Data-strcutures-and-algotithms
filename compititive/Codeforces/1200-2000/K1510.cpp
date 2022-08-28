// Link : https://codeforce s.com/problemset/problem/1510/K
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T>, greater<T>>
#define pb push_back
#define ff first
#define ss second
#define print(x) for (auto it : x) cout << it << " ";
#define mem(n, i) memset(n, i, sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    int ar[n * 2 + 2];
    for (int i = 0; i < n*2; i++)
    {
        cin >> ar[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
                swap(ar[j * 2], ar[j * 2 + 1]);
        }
        else
        {
            for (int j = 0; j < n; j++)
                swap(ar[j], ar[j + n]);
        }
        bool flag=1;
        for (int j=0;j<n*2;j++) flag&=(ar[j]==j+1);
        if (flag){
			if (n%2==1){
				printf("%d\n",min(n*2-i,i));
			} else {
                printf("%d\n",min(4-i,i));
			}
			return ;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}