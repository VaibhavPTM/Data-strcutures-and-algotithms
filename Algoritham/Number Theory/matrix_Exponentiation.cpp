/* problrm is from SPOJ and the name is matrix exponentioation and the time comlexity of below code is
O(N ^ 3(log(n)))
*/
#include<iostream>
using namespace std;
#define N 101
int arr[N][N] , I[N][N];
void mul(int A[][N],int B[][N],int dim){
    int res[dim+1][dim+1];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k <= dim; k++)
            {
                res[i][j] +=A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = res[i][j];
        }
    }
} 
void power(int A[][N], int dim, int n){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if(i == j)I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
    while (n)
    {
        if (n % 2)
        {
            mul(I,A,dim),n--;
        }
        else
        {
            mul(I,A,dim), n/=2;
        }
    }
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}
void printMat(int A[][N] , int dim){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
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
                cout<<"Enter ["<<i<<"]"<<"["<<j<<"] : ";
                cin>>arr[i][j];
            }   
        }
        power(arr,dim,n);
        printMat(arr,dim);
        
    }
    
    
    return 0;
}