/*
#include <iostream> 
using namespace std; 

int josephus(int n, int k) 
{ 
	if (n == 1) 
		return 1; 
	else
		/* The position returned by josephus(n - 1, k) 
		is adjusted because the recursive call 
		josephus(n - 1, k) considers the 
		original position k % n + 1 as position 1 
		return (josephus(n - 1, k) + k-1) % n + 1; 
} 

// Driver Program to test above function 
int main() 
{ 
	int n = 40; 
	int k = 7; 
	cout << "The chosen place is " << josephus(n, k); 
	return 0; 
} 
// This code is contributed by shubhamsingh10 
*/

#include <iostream>
#include <vector>
using namespace std;
void solve(int k, int index, vector<int> v, int &answer)
{
    if (v.size() == 1)
    {
        answer = v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin()+index);
    solve(k,index,v,answer);
}
int main()
{
    vector<int> v;
    int index = 0;
    int answer = -1;
    int k, n;
    cout << "Enter the number of pepole : ";
    cin >> n;
    cout << "Enter the number of K : ";
    cin >> k;
    k = k - 1;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    solve(k, index, v, answer);
    cout<<"Answer is : "<<answer;

    return 0;
}