#include<iostream>
using namespace std;
int gcd(int a,int b, int & x, int & y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int res = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return res;
}

int main(){
    int a,b,x,y,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<gcd(a,b,x,y)<<endl;
        cout << x << " " << y << endl;
    }
    return 0;
}