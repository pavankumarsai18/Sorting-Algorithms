/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int lchild(int i, int endIndex)
{
  int result = 2*i + 1;
  if(result > endIndex)
    return -1;
  return result;
}


int rchild(int i, int endIndex)
{
  int result = 2*i + 2;
  if(result > endIndex)
    return -1;
  return result;
}

int parent(int i)
{
  if(i == 0)
    return -1;
  return (i - 1)/2;
}

void percolateDown(vector<int>& nums, int ind, int size)
{
  if(ind < size)
  {
     int p = nums[ind];
     int l_ind = lchild(ind, size - 1);
     int r_ind = rchild(ind, size - 1);
     
     if(l_ind != -1 && r_ind != -1)
     {
       int l = nums[l_ind];
       int r = nums[r_ind];
       int m = (l < r)? r: l;
       if(p < m)
       {
          if(m == l){
            swap(nums[ind], nums[l_ind]);
            percolateDown(nums, l_ind, size);
          }
          else
          {
            swap(nums[ind], nums[r_ind]);
            percolateDown(nums, r_ind, size);
          }
       }     
     }
     else if(l_ind != -1 && r_ind == -1)
     {
        int p = nums[ind];
        int l = nums[l_ind];
        
        if(l > p)
        {
          swap(nums[ind], nums[l_ind]);
          percolateDown(nums, l_ind, size);
        }
     }
     else
     {
        return;
     }
  }
  return;
}
void BuildHeap(vector<int>& nums)
{
  int ind = static_cast<int>(nums.size())/2;
  
  for(; ind >= 0; ind--)
  {
    percolateDown(nums, ind, static_cast<int>(nums.size()));
  }
}

void extractMax(vector<int>& nums, int size)
{
  if(size > 0)
  {
    swap(nums[0], nums[size - 1]);
    // return nums[size - 1];
  }
}

void HeapSort(vector<int>& nums)
{
   BuildHeap(nums);
   
   int size = nums.size();
   
   while(size > 0)
   {
      extractMax(nums, size);
      size--;
      percolateDown(nums, 0, size);
   }
}

int main()
{
  srand(time(0));
  int size;
  cout<<"Enter the size ";
  cin>> size;
  
  
  vector<int> nums;
  for(int i = 0; i < size; i++)
  {
    nums.push_back(rand()%10);
  }
  
    for(auto c: nums)
        cout<<c<<" ";
    cout<<endl;
  HeapSort(nums);
  
    for(auto c: nums)
        cout<<c<<" ";
    cout<<endl;
  return 0;
}
