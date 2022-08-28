#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

void sortAcd(vector<int> &v){
    for(int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}
void sortDec(vector<int> &v){
    for(int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] < key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}
/*
10
10 9 8 7 6 5 4 3 2 1
*/
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    // sortAcd(v);
    sortDec(v);
    for(int &i : v) {
        cout << i << " ";
    }
    return 0;
}