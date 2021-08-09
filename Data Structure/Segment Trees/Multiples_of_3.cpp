// Link : https://www.codechef.com/problems/MULTQ3
// Topic : segment tree + lazy lazy prapogation
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define print(x) for(auto it:x) cout<<it<<" ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
#define MAX 100001

typedef struct treenode
{
    int ar[3];
}node;


node tree[MAX * 4];
int lazy[MAX * 4];

void bulidtree(int si, int ss, int se) {
    if(ss == se) {
        tree[si].ar[0] = 1;
        tree[si].ar[1] = 0;
        tree[si].ar[2] = 0;
        return;
    }
    int mid = ss + (se - ss) / 2;
    bulidtree(si * 2, ss, mid);
    bulidtree(si * 2 + 1, mid + 1, se);
    tree[si].ar[0] = tree[si * 2].ar[0] + tree[si * 2 + 1].ar[0];
    tree[si].ar[1] = tree[si * 2].ar[1] + tree[si * 2 + 1].ar[1];
    tree[si].ar[2] = tree[si * 2].ar[2] + tree[si * 2 + 1].ar[2];
}

void shif(int si) {
    int a = tree[si].ar[2];
    tree[si].ar[2] = tree[si].ar[1];
    tree[si].ar[1] = tree[si].ar[0];
    tree[si].ar[0] = a;
}
void update(int si, int ss, int se, int qs, int qe) {
    if(lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        if(ss != se) {
            lazy[si * 2] += dx;
            lazy[si * 2 + 1] += dx;
        }
        dx %= 3;
        for(int i = 0; i < dx; i++) {
            shif(si);
        }
    }
    if(qe < ss || qs > se) return;
    if(qs <= ss && qe >= se) {
        shif(si);
        if(ss != se) {
            lazy[si * 2]++;
            lazy[si * 2 + 1]++;
        }
        return;
    }
    int mid = ss + (se - ss) / 2;
    update(si * 2, ss, mid, qs, qe);
    update(si * 2 + 1, mid + 1, se, qs, qe);
    tree[si].ar[0] = tree[si * 2].ar[0] + tree[si * 2 + 1].ar[0];
    tree[si].ar[1] = tree[si * 2].ar[1] + tree[si * 2 + 1].ar[1];
    tree[si].ar[2] = tree[si * 2].ar[2] + tree[si * 2 + 1].ar[2];
}

int query(int si, int ss, int se, int qs, int qe) {
    if(lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        if(ss != se) {
            lazy[si * 2] += dx;
            lazy[si * 2 + 1] += dx;
        }
        dx %= 3;
        for(int i = 0; i < dx; i++) {
            shif(si);
        }
    }
    if(qe < ss || qs > se) return 0;
    if(qs <= ss && qe >= se) {
        return tree[si].ar[0];
    }
    int mid = ss + (se - ss) / 2;
    return query(si * 2, ss, mid, qs, qe) + query(si * 2 + 1, mid + 1, se, qs, qe);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    bulidtree(1, 1, n);
    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0) { 
            update(1, 1, n, b + 1, c + 1);
        }
        else {
            cout << query(1, 1, n, b + 1, c + 1) << endl;
        }
    }
    return 0;
}