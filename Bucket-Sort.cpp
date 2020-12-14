#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>
using namespace std;


void BucketSort(vector<double>&A)
{
    // Create a 2D vector called Buckets
    vector<vector<double>> Buckets;
    
    // Initialize each element in Buckets to an empty vector
    for(int i = 0; i < A.size(); i++)
    {
        auto L = vector<double>();
        Buckets.push_back(L);
    }
    
    // We loop through the elements in the vector A
    for(auto item: A)
    {
        // Find the hash value of the item
        int hashIndex = static_cast<int>(A.size())*item;
        // Store the item at the index hashValue
        Buckets[hashIndex].push_back(item);
    }
    
    // We loop through each bucket
    for(auto bucket:Buckets)
    {
        // We sort each bucket
        sort(bucket.begin(), bucket.end());
    }
    
    // Initialize a variable called ind to store the index
    int ind = 0;
    
    // We loop through each bucket
    for(auto bucket: Buckets)
    {
        // loop thorugh the bucket and store the item in original vector A
        for(auto item:bucket)
        {
            A[ind] = item;
            ind++;
        }
    }
    
    
    
}


int main()
{
    // Seed the random number generator
    srand(time(0));
  
    // Create a variable that stores the size
    int size;
  
    // Take user input
    cout<<"The size ";
    cin>>size;

    // Create a vector of double called numbers
    vector<double> numbers;
  
    // Populate the vector
    for(int i = 0; i < size; i++)
    {
        double val = double(rand()*1.00/2147483647);
        numbers.push_back(val);
    }
    
    // Print the items in numbers
    for(auto number: numbers)
        cout<<number<<" ";
    cout<<endl;
    
    // Perform bucket Sort
    BucketSort(numbers);
    
    // Print the contents in numbers
    for(auto number: numbers)
        cout<<number<<" ";
    cout<<endl;
    
    return 0;  
} 
