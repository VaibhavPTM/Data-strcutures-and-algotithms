// Link : https://codeforces.com/problemset/problem/86/D
// Topic :    data structures    implementation    math    two pointers    *2200
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
// power = f * f * elem;
typedef struct queries {
    int l, r, i;
}node;

node Q[200001];
int arr[200001];
int frq[1000001];
lli res[200001];
const int sqrtsize = 500;
lli cnt = 0;
bool cmp(node a, node b) {
    if((a.l / sqrtsize) != (b.l / sqrtsize)) {
        return a.l/sqrtsize < b.l/sqrtsize;
    }
    return a.r < b.r;
}

void add(int i) {
    lli frqq = frq[arr[i]];
    frq[arr[i]]++;
    cnt -= frqq * frqq * arr[i];
    frqq++;
    cnt += frqq * frqq * arr[i];
}
void remove(int i) {
    lli frqq = frq[arr[i]];
    frq[arr[i]]--;
    cnt -= frqq * frqq * arr[i];
    frqq--;
    cnt += frqq * frqq * arr[i];
}
void getres(int q) {
    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++) {
        int l = Q[i].l;
        int r = Q[i].r;
        // extanding the range
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
        res[Q[i].i] = cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // https://codeforces.com/problemset/submission/86/125213987
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    for(int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q, Q + q, cmp);
    getres(q);
    for(int i = 0;i < q; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}