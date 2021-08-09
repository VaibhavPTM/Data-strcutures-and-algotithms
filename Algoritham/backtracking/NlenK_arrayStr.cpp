#include<iostream>
using namespace std;

char arr[1000];
string s;

void bitStr(int n,char k){
    if(n < 1){
        cout<<arr<<" ";
    }
    else{
        for (int i = '0'; i < k; i++){
            arr[n-1] = i;
            bitStr(n-1,'2');
        }
    }
}

int main(){
    bitStr(4,'2');
    return 0;
}