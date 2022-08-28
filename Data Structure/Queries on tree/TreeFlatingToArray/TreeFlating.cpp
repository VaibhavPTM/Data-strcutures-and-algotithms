#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"


vector<int> arr[101];
int inT[101], ouT[101], timeNode[202];
int timer = 1;

void dfs(int node, int par) {
    inT[node] = timer;
    timeNode[timer] = node;
    timer++;

    for(auto &x : arr[node]) {
        if(x != par) {
            dfs(x, node);
        }
    }
    ouT[node] = timer;
    timeNode[timer] = node;
    timer++;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int edge = n - 1;
    while(edge--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1,-1);

    cout << "in T - { ";
    for(int i = 1; i <= n; i++) {
        cout << inT[i] << " ";
    }
    cout << " }\n";

    cout << "out T - { ";
    for(int i = 1; i <= n; i++) {
        cout << ouT[i] << " ";
    }
    cout << " }\n";

    cout << "timer node list - { ";
    for(int i = 1; i <= n * 2; i++) {
        cout << timeNode[i] << " ";
    }
    cout << " }\n";
    return 0;
}