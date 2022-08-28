// Link : https://codeforces.com/problemset/problem/1534/A
// Topic :  brute force    implementation    *800
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
#define MAX 100001

void solve() {
    int n, m;
    cin >> n >> m;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    vector<vector<char>> mat(n, vector<char> (m));
    queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != '.') pq.push({i,j});
        }
    }
    if(pq.empty()) {
        mat[0][0] = 'R';
        pq.push({0,0});
    }
    while(!pq.empty()) {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        for(int i = 0; i < 4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            // cout << xx << yy << " " << mat[xx][yy] << endl;
            if(xx >= 0 && yy >= 0 && xx < n && yy < m) {
                if(mat[xx][yy] == '.') {
                    mat[xx][yy] = mat[x][y] == 'R' ? 'W' : 'R';
                    pq.push({xx,yy});
                }
                else if(mat[xx][yy] == (mat[x][y] == 'R' ? 'R' : 'W')){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
} 