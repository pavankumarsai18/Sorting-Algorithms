/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

void CountingSort(vector<int>& A, vector<int>&B, int power)
{
    vector<int>C(10, 0);
  
    for(int i = 0; i < A.size(); i++)
    {
        int num = A[i];
        int digit = (A[i]/power)%10;
        C[digit]++;
    }
    

    
    for(int i = 1; i < C.size() ; i++)
    {
        C[i] = C[i - 1] + C[i];
    }
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        int ind = (A[i]/power)%10;
        B[C[ind] - 1] = A[i];
        C[ind]--;
    }
    
    
}

void RadixSort(vector<int>&A)
{
    int max = A[0];
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    
    for(int i = 1; max/i > 0; i*=10)
    {
        vector<int> B = vector<int>(A.size(), 0);
        CountingSort(A, B, i);
        A = B;
    }
    
}


int main()
{
    srand(time(0));
    int size;
    cout<<"The size ";
    cin>>size;

    
    vector<int> nums;
    for(int i = 0; i < size; i++)
    {
        int val;
        cout<<i + 1<<"th val ";
        cin>>val;
        nums.push_back(val);
    }
    
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    RadixSort(nums);
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    
    return 0;  
} 
