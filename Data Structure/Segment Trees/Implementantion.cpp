// Link : https://www.spoj.com/problems/RMQSQ/
// Name : Range Minimum Query
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int st[400001];

void BulidTree(int si,int ss,int se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    BulidTree(si * 2, ss, mid);
    BulidTree(si * 2 + 1, mid + 1, se);
    st[si] = min(st[si * 2], st[si * 2 + 1]);
}
int query(int si, int ss, int se, int qs, int qe) {
    if(qs > se || qe < ss) {
        return INT_MAX;
    }
    if(qs <= ss && qe >= se) {
        return st[si];
    }
    int mid = (ss + se) / 2;
    int l = query(si * 2, ss, mid, qs, qe);
    int r = query(si * 2 + 1, mid + 1, se, qs, qe);
    return min(l, r);
}
int main()
{
    int n, q, a, b;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    BulidTree(1, 1, n);
    cin >> q;
    while(q--) {
        cin >> a >> b;
        cout << query(1, 1, n, a + 1, b + 1) << endl;
    }
    
    return 0;
}
