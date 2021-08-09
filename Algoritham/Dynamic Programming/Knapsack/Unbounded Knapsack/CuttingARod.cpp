#include<bits/stdc++.h>
using namespace std;
//static int fastio = [](){
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(0);
//    return 0;
//}();


// Recursiv way
//int help(int price[], int n){
//    if(n <= 0) return 0;
//    int maxVale = INT_MIN;
//    for(int i = 0; i < n; i++){
//        maxVale = max(maxVale, price[i] + help(price, n - i - 1));
//    }
//    return maxVale;
//}

// dp
int help2(int len[], int n){
	int dp[n+1][n+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			else if(i <= j){
				dp[i][j] = max(dp[i-1][j],len[i-1] + dp[i][j - i]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}	
	return dp[n][n];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
    	cin>>arr[i];
	}
//    cout<<"Max Value : "<<help(arr,n)<<endl;
    cout<<"Max Value : "<<help2(arr,n);
    return 0;
}
