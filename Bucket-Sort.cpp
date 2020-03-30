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
#include <algorithm>
using namespace std;



void BucketSort(vector<double>&A)
{
    vector<vector<double>> Buckets;
    
    for(int i = 0; i < A.size(); i++)
    {
        auto L = vector<double>();
        Buckets.push_back(L);
    }
    
    for(auto d: A)
    {
        int hashIndex = static_cast<int>(A.size())*d;
        Buckets[hashIndex].push_back(d);
    }
    
    for(auto b:Buckets)
    {
        sort(b.begin(), b.end());
    }
    
    int ind = 0; 
    for(auto b: Buckets)
    {
        for(auto num:b)
        {
            A[ind] = num;
            ind++;
        }
    }
    
    
    
}


int main()
{
    srand(time(0));
    int size;
    cout<<"The size ";
    cin>>size;

    
    vector<double> nums;
    for(int i = 0; i < size; i++)
    {
        double val = double(rand()*1.00/2147483647);
        nums.push_back(val);
    }
    
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    
    BucketSort(nums);
    
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    
    return 0;  
} 
