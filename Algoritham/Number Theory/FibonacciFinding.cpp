// hear we have two number is input and we have to start fibboaci series from that number like f(3) = f(3-1)+f(3 -2)
// hear we can use mareix exponentiantion and recurrence relation to simplphy the problem
#include<iostream>
#define mod 1000000007
#define lli long long int
using namespace std;

lli arr[3];
lli T[3][3] , I[3][3];
void mul(lli A[3][3],lli B[3][3],int dim){
    int res[dim+1][dim+1];
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                lli x = A[i][k] * B[k][j] % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            A[i][j] = res[i][j];
        }
    }
} 
lli getfib(int n){
    if(n <= 2)return arr[n];
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;
    n = n-1;
    while (n)
    {
        if (n%2)
        {
            mul(I , T , 2),n--;
        }
        else{
            mul(T , T , 2), n/= 2;
        }
    }
    lli fn = (arr[1] * I[1][1] + arr[2] * I[2][1]) % mod;
    return fn;
}
int main(){
    int T , n;
    cin>>T;
    while (T--)
    {
        cin>>arr[1]>>arr[2]>>n, n++;
        cout<<getfib(n)<<endl;
    }
    return 0;
} 