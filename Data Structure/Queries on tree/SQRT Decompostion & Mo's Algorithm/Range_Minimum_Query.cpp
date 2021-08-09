// Link : https://www.spoj.com/problems/RMQSQ/
// Topic : Tree, SQRT decompostion
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
#define endl "\n"

int arr[100001];
vector<int> sqrtarr;
int getSqrtSize(int n) {
    int t = sqrt(n);
    int t2 = n / t;
    if(t2 * t < n) return t2 + 1;
    else return t2;
}
void bulidtree(int sqetSize, int arrsize, int n) {
    for (int i = 0; i < n; i++) {
        sqrtarr[i/sqetSize] = min(sqrtarr[i/sqetSize],arr[i]);
    }
}
int getmin(int l, int r, int sqrtsize) {
    int sqrtl = l / sqrtsize;
    int sqrtr = r / sqrtsize;
    int mn = INT_MAX;
    if(sqrtl == sqrtr) {
        for (int i = l; i <= r; i++) {
            mn = min(mn, arr[i]);
        }
    }
    else {
        for (int i = l; i < sqrtsize * (sqrtl+1); i++) {
            mn = min(mn, arr[i]);
        }
        for (int i = sqrtl + 1; i < sqrtr; i++) {
            mn = min(mn, sqrtarr[i]);
        }
        for(int i = sqrtr * sqrtsize; i <= r; i++) {
            mn = min(mn,arr[i]);
        }
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sqrtsize = getSqrtSize(n);
    sqrtarr.resize(sqrtsize, INT_MAX);
    bulidtree(sqrt(n), sqrtsize, n);
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << getmin(a, b, sqrt(n)) << endl;
    }
    return 0;
}