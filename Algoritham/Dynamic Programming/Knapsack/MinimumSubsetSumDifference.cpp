// Link : https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

#include<bits/stdc++.h>
using namespace std;
//static int fastio = [](){
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(0);
//    return 0;
//}();

int getsum(int arr[],int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	return sum;
}

int help(int arr[], int n){
	int sum = getsum(arr,n);
	bool dp[n+1][sum+1];
	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	for(int i = 1; i <= sum; i++){
		dp[0][i] = false;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];	
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= sum; j++){
    //         if(dp[i][j]){
    //             cout<<"T"<<" ";
    //         }
    //         else cout<<"F"<<" ";
    //     }
    //     cout<<endl;
    // }

	int minDiff = INT_MAX;
	for(int i = sum/2; i >= 0; i--){
		if(dp[n][i] == true){
			minDiff = sum - i*2;
			break;
		}
	}
	return minDiff;
	
	
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
    	cin>>arr[i];
	}
	cout<<help(arr,n);
    return 0;
}

