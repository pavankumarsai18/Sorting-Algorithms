#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort(vector<int>& nums)
{
    int ind = 1;
    for(; ind < nums.size(); ind++)
    {
        int currentIndex = ind - 1;
        int key = nums[ind];

        while(currentIndex >= 0 && nums[currentIndex] > key)
        {
            nums[currentIndex + 1] = nums[currentIndex];
            currentIndex--;
        }

        nums[currentIndex + 1] = key;
    }

    return;
}

int main()
{
    int size;
    cout<<"Enter the size of the array ";
    cin>>size;

    int min;
    cout<<"Enter the min val ";
    cin>>min;

    int max;
    cout<<"Enter the max val (should be > min) ";
    cin>>max;

    srand(time(0));
    vector<int> nums;
    for(int i = 0; i < size; i++)
    {
        nums.push_back(rand()%(max - min + 1) - min);
    }

    insertionSort(nums);
    
    

    return 0;
}
