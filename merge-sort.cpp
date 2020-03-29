#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void MergeSort(vector<int>& nums, int startIndex, int endIndex)
{
    if(endIndex > startIndex)
    {
        int midIndex = (startIndex + endIndex)/2;
        
        MergeSort(nums, startIndex, midIndex);
        MergeSort(nums, midIndex + 1, endIndex);
        
        Merge(nums, startIndex, midIndex, endIndex);
    
    }
}

void Merge(vector<int>& nums, int startIndex, int midIndex, int endIndex)
{
    if(endIndex - startIndex == 1)
    {
        if(nums[startIndex] > nums[endIndex])
        {
            swap(nums[startIndex], nums[endIndex]);
        }
        return;
    }
    
    int arr1Index = startIndex;
    int arr2Index = midIndex + 1;
    
    vector<int> result;
    while(arr1Index < midIndex + 1 && arr2Index < endIndex + 1)
    {
        if(nums[arr1Index] <= nums[arr2Index])
        {
            result.push_back(nums[arr1Index]);
            arr1Index++;
        }
        else
        {
            result.push_back(nums[arr2Index]);
            arr2Index++;
        }
    }
    
    while(arr1Index < midIndex + 1)
    {
        result.push_back(nums[arr1Index]);
        arr1Index++;
    }
    
    while(arr2Index < endIndex + 1)
    {
        result.push_back(nums[arr2Index]);
        arr2Index++;
    }
    
    
    for(int i = startIndex; i < endIndex + 1; i++)
    {
        nums[i] = result[i - startIndex];
    }

    return;
}

int main()
{
    cout<<"The size: ";
    int size;
    cin>> size;

    srand(time(0));
    
    vector<int> nums;
    for(int i = 0; i < size; i++)
        nums.push_back(rand());
    
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    
    MergeSort(nums, 0, static_cast<int>(nums.size() - 1));
    
    for(auto n: nums)
        cout<<n<<" ";
    cout<<endl;
    return 0;
}
