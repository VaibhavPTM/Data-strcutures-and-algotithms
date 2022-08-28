#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int findCross(vector<int> &ar, int low, int mid, int hige) {
    int sum = 0, MaxLeft = INT_MIN;
    for(int i = mid; i >= low; i--) {
        sum += ar[i];
        if(sum > MaxLeft) {
            MaxLeft = sum;
        }
    }
    sum = 0;int MaxRight = INT_MIN;
    for(int i = mid+1; i <= hige; i++) {
        sum += ar[i];
        if(sum > MaxRight) {
            MaxRight = sum;
        }
    }
    return (MaxLeft + MaxRight);
}
/*
9
-2 1 -3 4 -1 2 1 -5 4
*/

int D_And_C(vector<int> &ar, int low, int hige) {
    if(low == hige) {
        return ar[low];
    }
    int mid = low + (hige - low) / 2;
    int l = D_And_C(ar,low,mid);
    int r = D_And_C(ar,mid + 1,hige);
    int cross = findCross(ar,low, mid,hige);

    if(l >= r && l >= cross) return l;
    else if(r >= l && r >= cross) return r;
    else return cross;

}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int &i : ar) {
        cin >> i;
    }
    int res = D_And_C(ar,0,n-1);
    cout << res;
    return 0;
}