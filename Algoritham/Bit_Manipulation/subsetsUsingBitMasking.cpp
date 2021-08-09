#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void filterchar(string & a, int no){
    int i = 0;
    while (no > 0)
    {
        (no & 1) ? cout<<a[i]:cout<<"";
        i++;
        no = no >> 1;
    }
    cout<<endl;
}
void genratsubsets(string & c){
    int n = c.size();
    int range = (1 << n) - 1;
    for (int i = 1; i <= range; i++)
    {
        filterchar(c , i);
    }
}
int main()
{
    string str;
    cin>>str;
    genratsubsets(str);
    
    return 0;
}