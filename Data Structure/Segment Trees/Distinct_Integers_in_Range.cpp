// Link : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/
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

int a[100001], b[100001];
bitset<5001> tree1[400004], tree2[400004]; 

void bulidtree(int idx, int l, int r) {
    if(l > r) return ;
    if(l == r) {
        tree1[idx].set(a[l]);
        tree2[idx].set(b[l]);
        return;
    }
    int mid = l + (r - l) / 2;
    bulidtree(idx * 2, l, mid);
    bulidtree(idx * 2 + 1, mid + 1, r);
    tree1[idx] = tree1[idx * 2] | tree1[idx * 2 + 1];
    tree2[idx] = tree2[idx * 2] | tree2[idx * 2 + 1];
}

bitset<5001> query1(int idx, int l, int r, int ql, int qr) {
    if(l > r || qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return tree1[idx];
    int mid = l + (r - l) / 2;
    return query1(idx * 2, l, mid, ql, qr) | query1(idx * 2 + 1, mid + 1, r, ql, qr);
} 
bitset<5001> query2(int idx, int l, int r, int ql, int qr) {
    if(l > r || qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return tree2[idx];
    int mid = l + (r - l) / 2;
    return query2(idx * 2, l, mid, ql, qr) | query2(idx * 2 + 1, mid + 1, r, ql, qr);
} 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    bulidtree(1, 1, n);
    cin >> q;
    while(q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << (query1(1, 1, n, x, y) | query2(1, 1, n, l, r)).count() << endl;
    }
    return 0;
}