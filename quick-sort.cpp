#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>&nums, int startIndex, int endIndex)
{
    int pivotVal = nums[endIndex];
    int i = startIndex - 1;
    int j = startIndex;
    
    for(; j < endIndex; j++)
    {
        if(nums[j] <= pivotVal)
        {
          i++;
          swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[endIndex]);
    return i+1;
}

void QuickSort(vector<int>& nums, int startIndex, int endIndex)
{
  if(startIndex < endIndex)
  {
      int pivotIndex = partition(nums, startIndex, endIndex);
      QuickSort(nums, startIndex, pivotIndex - 1);
      QuickSort(nums, pivotIndex + 1, endIndex);
  }
}

void QuickSort(vector<int>& nums)
{
  QuickSort(nums, 0, static_cast<int>(nums.size()) - 1);
}

int main()
{
  srand(time(0));
  int size;
  cout<<"Enter the size ";
  cin>>size;
  
  vector<int> nums;
  for(int i = 0; i < size; i++)
  {
    nums.push_back(rand()%10);
  }
  
  for(auto n: nums)
  {
    cout<<n<<" ";
  }
  cout<<endl;
  QuickSort(nums);

  for(auto n: nums)
  {
    cout<<n<<" ";
  }

}
