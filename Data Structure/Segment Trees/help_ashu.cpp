// Link : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
// Topic : 
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int arr[MAX];
   // odd, even
pair<int,int> st[4 * MAX];

void bulidTree(int si, int ss, int se) {
    if(ss == se) {
        if(arr[ss] % 2 == 1) {
            st[si] = {1, 0};
        }
        else {
            st[si] = {0, 1};
        }
        return;
    }
    int mid = (ss + se) / 2;
    bulidTree(si * 2, ss, mid);
    bulidTree(si * 2 + 1, mid + 1, se);
    st[si].first = st[si * 2].first + st[si * 2 + 1].first;
    st[si].second = st[si * 2].second + st[si * 2 + 1].second;
}

void update(int si, int ss, int se, int qi, int val) {
    if(ss == se) {
        if(arr[ss] % 2 == 1) {
            st[si] = {0, 1};
        }
        else {
            st[si] = {1, 0};
        }
        arr[ss] = val;
        return;
    }
    int mid = (ss + se) / 2;

    if(qi <= mid) update(si * 2, ss, mid, qi, val);
    else update(si * 2 + 1, mid + 1, se, qi, val);
    st[si].first = st[si * 2].first + st[si * 2 + 1].first;
    st[si].second = st[si * 2].second + st[si * 2 + 1].second;
}
int geteven(int si, int ss, int se, int qs, int qe) {
    if(qs > se || qe < ss) return 0;
    if(qs <= ss && qe >= se) return st[si].second;
    int mid = (ss + se) / 2;
    int a = geteven(si * 2, ss, mid, qs, qe);
    int b = geteven(si * 2 + 1, mid + 1, se, qs, qe);
    return a + b;
}
int getodd(int si, int ss, int se, int qs, int qe) {
    if(qs > se || qe < ss) return 0;
    if(qs <= ss && qe >= se) return st[si].first;
    int mid = (ss + se) / 2;
    int a = getodd(si * 2, ss, mid, qs, qe);
    int b = getodd(si * 2 + 1, mid + 1, se, qs, qe);
    return a + b;
}
int main() {
    int n, q, a, b, c;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    bulidTree(1, 1, n);
    
    cin >> q;
    while(q--) {
        cin >> a;
        if(a == 0){
            cin >> b >> c;
            if ((arr[b] % 2) == (c % 2)) continue;
            update(1, 1, n, b, c);
        }
        else if(a == 1){
            cin >> b >> c;
            cout << geteven(1, 1, n, b, c) << endl;
        }
        else if(a == 2){
            cin >> b >> c;
            cout << getodd(1, 1, n, b, c) << endl;
        }
    }
    return 0;
}