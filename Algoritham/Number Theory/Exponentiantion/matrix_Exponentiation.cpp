/* problrm is from SPOJ and the name is matrix exponentioation and the time comlexity of below code is
O(N ^ 3 * (log(n)))
problem - https://www.spoj.com/problems/MPOW/
*/
#include<iostream>
using namespace std;
#define N 52
#define lli long long int
const int mod = 1e9+7;
lli arr[N][N] , I[N][N];
void printMat(lli A[][N] , int dim){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void mul(lli A[][N],lli B[][N],int dim){
    lli res[dim+1][dim+1];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % mod)) % mod;
            }
        }
    }
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            A[i][j] = res[i][j];
        }
    }
} 
void power(lli A[][N], int dim, int n){
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(i == j)I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
    while (n)
    {
        if (n % 2) {
            mul(I,A,dim),n--;
        }
        else {
            mul(A,A,dim), n/=2;
        }
    }
    // for (int i = 0; i < dim; i++) {
    //     for (int j = 0; j < dim; j++) {
    //         A[i][j] = I[i][j];
    //     }
    // }
    printMat(I,dim);
}

int main()
{
    int t, dim , n;
    cin>>t;
    while (t--)
    {
        cin>>dim>>n;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cin>>arr[i][j];
            }   
        }
        power(arr,dim,n);
        // printMat(arr,dim);
        
    }
    
    
    return 0;
}