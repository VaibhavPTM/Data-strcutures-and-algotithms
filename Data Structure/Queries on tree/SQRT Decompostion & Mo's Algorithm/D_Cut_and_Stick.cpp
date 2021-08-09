// Link : https://codeforces.com/contest/1514/problem/D
// Topic :  binary search    data structures    greedy    implementation    sortings    *2000
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
const int MAX = 300003;
const int sqrtsize = 555;
typedef struct query {
    int l, r, i;
}node;
node Q[MAX];
int arr[MAX], res[MAX], frq[MAX], frqOfFrq[MAX];
int maxF = 0;

bool cmp(node a, node b) {
    if(a.l / sqrtsize != b.l / sqrtsize) {
        return a.l / sqrtsize < b.l / sqrtsize;
    }
    return a.r < b.r;
}
void add(int i) {
    int prevFrq = frq[arr[i]];
    int currFrq = ++frq[arr[i]];

    frqOfFrq[prevFrq]--;
    frqOfFrq[currFrq]++;
    maxF = max(maxF, currFrq);
}
void remove(int i) {
    int prevFrq = frq[arr[i]];
    int currFrq = --frq[arr[i]];

    frqOfFrq[prevFrq]--;
    frqOfFrq[currFrq]++;

    if (currFrq < maxF) {
        while (frqOfFrq[maxF] == 0) {
            maxF--;
        }
        
    }
}
void getval(int q) {

    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++) {
        int l = Q[i].l;
        int r = Q[i].r;
        // extending the range;
        while(ML > l) {
            ML--;
            add(ML);
        }
        while(MR < r) {
            MR++;
            add(MR);
        }
        // resuding the range
        while(ML < l) {
            remove(ML);
            ML++;
        }
        while(MR > r) {
            remove(MR);
            MR--;
        }
        int totalEl = (r - l) + 1;
        int remaingElm = totalEl - maxF;
        int half = (totalEl + 1) / 2;
        if(maxF <= half) res[Q[i].i] = 1;
        else res[Q[i].i] = totalEl - 2*remaingElm;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }
    sort(Q, Q + q, cmp);
    getval(q);
    for(int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    return 0;
}