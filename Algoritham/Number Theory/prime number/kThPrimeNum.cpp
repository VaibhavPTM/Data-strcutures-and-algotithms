// Link : https://www.spoj.com/submit/TDKPRIME/
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

bool arr[90000001];
vector<int> v;
void prime() {
    int mx = 90000001;
    arr[0] = arr[1] = 1;

    for(int i = 2; i  * i <= mx; i++) {
        if(!arr[i]) {
            for(int j = i * i; j <= mx; j +=i) {
                arr[j] = 1;
            }
        }
    }
    for(int i = 2; i < mx; i++) {
        if(arr[i] == 0) v.pb(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    prime();
    while(q--) {
        int n;
        cin >> n;
        cout << v[n-1] << endl;        
    }
    return 0;
}