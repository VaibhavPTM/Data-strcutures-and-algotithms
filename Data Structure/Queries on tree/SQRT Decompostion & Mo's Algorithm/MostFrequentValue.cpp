// Link : https://www.spoj.com/problems/FREQ2/
// Topic : SQRT decompostion , Mo's algorithem
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
const int MAX = 100001;
const int sqrtsize = 555;
typedef struct query {
    int l, r, i;
}node;
node Q[MAX];
int arr[MAX], ans[MAX], frq[MAX], frqOfFrq[MAX];
int mxFrq;

bool cmp(node a, node b) {
    if(a.l / sqrtsize != b.l / sqrtsize) return a.l / sqrtsize < b.l / sqrtsize;
    return a.r < b.r;
}
void add(int i) {
    int prevFrq = frq[arr[i]];
    int currFrq = ++frq[arr[i]];

    frqOfFrq[prevFrq]--;
    frqOfFrq[currFrq]++;

    mxFrq = max(mxFrq, currFrq);
}
void remove(int i) {
    int prevFrq = frq[arr[i]];
    int currFrq = --frq[arr[i]];

    frqOfFrq[prevFrq]--;
    frqOfFrq[currFrq]++;

    if(currFrq < mxFrq) {
        while(frqOfFrq[mxFrq] == 0) {
            mxFrq--;
        }
    }
}
void getval(int q) {
    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++) {
        int l = Q[i].l;
        int r = Q[i].r;
        
        // extanding range
        while(ML > l) {
            ML--;
            add(ML);
        }
        while(MR < r) {
            MR++;
            add(MR);
        }

        // resuding range
        while(ML < l) {
            remove(ML);
            ML++;
        }
        while(MR > r) {
            remove(MR);
            MR--;
        }

        ans[Q[i].i] = mxFrq;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
    }
    sort(Q, Q + q, cmp);
    getval(q);
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
} 