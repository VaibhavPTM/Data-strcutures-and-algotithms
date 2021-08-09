#include <iostream>
#include <vector>
using namespace std;
vector <int> v1;
bool arr[90000001];

void sieve(){
	int maxn = 90000000;
	arr[0] = arr[1] = true;
	
	for(int i = 2; i * i <= maxn; i++){
		if(!arr[i]){
			for(int j = i * i; j <= maxn; j+=i){
				arr[j] = true;
			}
		}
	}
	for(int i = 0; i<maxn; i++){
		if(arr[i] == false){
			v1.push_back(i);
		}
	}
}
int main() {
	
	int n,k;
	cin>>n;
	sieve();
	while(n--){
		cin>>k;
	    cout<<v1[k-1];
		cout<<endl;
	}
	return 0;
}