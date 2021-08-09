// here you have a b  and c and you have to find x and y such that ax + by = c;
#include<iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(int a, int b, int c, int &x, int &y){
    int x0,y0;
    int g = gcd(abs(a), abs(b), x0, y0);
    if(c % g){
        return false;
    }

    x = x0 * c / g;
    y = y0 * c / g;

    if(a < 0) x = -x;
    if(y < 0) y = -y;
    return true;
}
int main(){
    int a,b,c,x,y,t;
    cin>>t;
    while(t--){
        cout<<"a : ",cin>>a;
        cout<<"b : ",cin>>b;
        cout<<"c : ",cin>>c;
        if(find_any_solution(a,b,c,x,y) == false){
            cout<<"no solution found"<<endl;
        }
        else{
            cout<<"x : "<<x<<endl<<"y : "<<y<<endl<<endl;
        }
    }

    return 0;
}