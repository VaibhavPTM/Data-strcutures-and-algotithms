// Link : https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/
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

bool arr[1000001];
int ppn[1000001];
void prime() {
    int mx = 1000001;
    for(int i = 0; i <= mx; i++) {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;
    for(lli i = 2; i * i <= mx; i++) {
        if(arr[i]) {
            for(lli j = i * i; j <= mx; j+=i) {
                arr[j] = false;
            } 
        }
    }

    int cnt = 0;
    for(int i = 0; i <= mx; i++) {
        if(arr[i] == true) cnt++;

        if(arr[cnt] == true) ppn[i] = 1;
        else ppn[i] = 0;
    }
    for(int i= 1; i < mx; i++) {
        ppn[i] = ppn[i] + ppn[i-1];
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    prime();
    while(q--) {
        int l, r, res = 0;
        cin >> l >> r;
        res = ppn[r] - ppn[max(0,l-1)];
        cout << res << endl;
    }
    return 0;
}