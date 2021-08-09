#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
int arr[100001];
int tree[400004], lazy[400004];

void buildtree(int idx, int l, int r) {
    if(l > r) return;
    if(l == r) {
        tree[idx] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    buildtree(idx * 2, l, mid);
    buildtree(idx * 2 + 1, mid + 1, r);
    tree[idx] =  tree[idx * 2] + tree[idx * 2 + 1];
}

void update(int idx, int l, int r, int ql, int qr, int val) {
    if(lazy[idx] != 0) {
        int needToBeUpdate = lazy[idx];
        tree[idx] += needToBeUpdate * ((r - l) + 1);
        lazy[idx] = 0;
        if(l != r) {
            lazy[idx * 2] += needToBeUpdate;
            lazy[idx * 2 + 1] += needToBeUpdate;
        }
    }
    if(qr < l || ql > r) return;
    if(ql <= l && qr >= r){
        int needToBeUpdate = val * ((r - l) + 1);
        tree[idx] += needToBeUpdate;
        if(l != r) {
            lazy[idx * 2] += val;
            lazy[idx * 2 + 1] += val;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    update(idx * 2, l, mid, ql,qr, val);
    update(idx * 2 + 1, mid + 1, r, ql, qr, val);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int query(int idx, int l, int r, int ql, int qr) {
    if(l > r) return 0;
    if(lazy[idx] != 0) {
        int needToBeUpdate = lazy[idx];
        tree[idx] += needToBeUpdate * ((r - l) + 1);
        lazy[idx] = 0;
        if(l != r) {
            lazy[idx * 2] += needToBeUpdate;
            lazy[idx * 2 + 1] += needToBeUpdate;
        }
    }
    if(qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return tree[idx];
    int mid = l + (r - l)/2;
    return query(idx * 2, l, mid, ql, qr) + query(idx * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    buildtree(1, 1, n);
    int q;
    cin >> q;
    while(q--) {
        int a, b, c, val;
        cin >> a;
        // for 1 return range sum beetween l and r
        if(a == 1) {
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << endl;
        }
        // for 0 update range l - r with val
        else {
            cin >> b >> c >> val;
            update(1, 1, n, b, c, val);
        }
    }
    return 0;
}