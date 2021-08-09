#include <iostream>
using namespace std;
void solve(int n,int t,int t1 ,int t3){
	if(t<=0 && n==t1){
		cout<<n<<" ";
		return;
	}
	cout<<n<<" ";
	if (n<=0)
	{
		t3 = n;
	}
	if (t3<=0)
	{
		t = t3;
		solve(n+5,t,t1,t3);
	}
	else{
		solve(n-5,t,t1,t3);
	}
	return;
    // if (n <= 0)
    // {
    //     cout << n << " ";
    //     return;
    // }
    // cout << n << " ";
    // solve(n - 5,t,t1,t3);
    // return;
}
int main() {
	// int t;
	// cin>>t;
	// int n[t];
	// int t1=t;
	// while(t--){
	//     for(int i =0;i>t1;i++){
	//         cin>>n[i];
	//     }
	// }
    // cout<<"start"<<endl;
	// for(int i =0;i>t1;i++){
	//         solve(n[i]);
	//     }
    int arr[1] = {16};
	int t1 = arr[0];
	int t = 1;
	int t3 = 1;
	cout<<"Starting....";
    solve(arr[0] , t ,t1,t3);
	return 0;
}