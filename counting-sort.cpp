#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> CountingSort(vector<int>& A, int min, int max)
{
    vector<int>B(A.size(), 0);
    vector<int>C(max-min+1, 0);
    
    for(int i = 0; i < A.size(); i++)
    {
        C[A[i] - min]++;
    }
    
    
    for(int i = 1; i < C.size(); i++)
    {
        C[i] = C[i - 1] + C[i];
    }
    
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        int val = A[i] - min;
        B[C[val] - 1] = A[i];
        C[val]--;
    }
    return B;
}

int main()
{
    srand(time(0));
    
    int size;
    cout<<"The size ";
    cin>>size;
    
    vector<int> nums;
    int min, max;
    for(int i = 0; i < size; i++)
    {
        int val = rand()%10;
        nums.push_back(val);
        if(i == 0)
        {
            min = val;
            max = val;
        }
        else
        {
            if(min > val)
            {
                min = val;
            }
            if(max < val)
            {
                max = val;
            }
        }
    }
    
    for(auto c: nums)
        cout<<c<<" ";
    cout<<endl<<endl;
    
    vector<int> result = CountingSort(nums, min, max);
    
    for(auto c: result)
        cout<<c<<" ";
    cout<<endl;
    
    return 0;
}
