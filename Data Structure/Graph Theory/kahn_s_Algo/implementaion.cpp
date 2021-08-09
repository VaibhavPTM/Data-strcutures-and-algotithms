#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

vi arr[100001],ans;
int inD[100001];

bool kahnS(int n) // n = total vertices
{
    queue<int> q;
    for(int i = 0;i < n; i++){
        if(inD[i] == 0)
        q.push(i);
    }
    while(!q.empty()){
        int crr_node = q.front();
        q.pop();
        ans.push_back(crr_node);
        for (int i : arr[crr_node])
        {
            inD[i]--;
            if(inD[i] == 0){
                q.push(i);
            }
        }
    }
    return n == ans.size();
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while(e--){
        cin>>a>>b;
        arr[a].push_back(b);
        inD[b]++;
    }
    if(!kahnS(v)){
        cout<<"Found a cycle"<<endl;
    }
    else{
        for(int i : ans){
            cout<<i<<" ";
        }    
    }
    return 0;
}