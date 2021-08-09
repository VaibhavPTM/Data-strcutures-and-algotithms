// Link : https://www.spoj.com/problems/DQUERY/
// Topic : Mo's algorithem
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

int arr[30001];
int res[200001];
int fre[1000001];
const int sqrtsize = 555;
vector<pair<pair<int,int>,int>> query;
int cnt = 0;
void add(int pos)
{
	fre[arr[pos]]++;
	if(fre[arr[pos]] == 1)
	cnt++;
}
 
void remove(int pos)
{
	fre[arr[pos]]--;
	if(fre[arr[pos]] == 0)
	cnt--;
}
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    if((a.ff.ff / sqrtsize) != (b.ff.ff / sqrtsize)) {
        return (a.ff.ff / sqrtsize) < (b.ff.ff / sqrtsize);
    }
    else return a.ff.ss < b.ff.ss;
}

void findans(int q) {
    // unordered_set<int> s;
    int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = query[i].ff.ff;
		int R = query[i].ff.ss;
//      extending the range
		while(ML > L) ML--, add(ML); 
        while(MR < R) MR++, add(MR);
 
//      redusing the range
		while(ML < L)remove(ML), ML++; 
        while(MR > R) remove(MR), MR--;
 
		res[query[i].ss] = cnt;
	}
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        query.pb({{a-1,b-1},i});
    }
    sort(query.begin(), query.end(),cmp);
    findans(q);
    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}