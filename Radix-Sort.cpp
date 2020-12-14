#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

#define BASE 10
using namespace std;


void CountingSort(vector<int>& A, vector<int>&B, int power)
{
    vector<int>C(BASE, 0);
  
    for(int i = 0; i < A.size(); i++)
    {
        int num = A[i];
        int digit = (A[i]/power)%BASE;
        C[digit]++;
    }
    

    
    for(int i = 1; i < C.size() ; i++)
    {
        C[i] = C[i - 1] + C[i];
    }
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        int ind = (A[i]/power)%BASE;
        B[C[ind] - 1] = A[i];
        C[ind]--;
    }
    
    
}

void RadixSort(vector<int>&A)
{
    // Create a variable called max
    int max = A[0]; // Initialize it to the first element
  
    // Loop through the elements to find the maximum element
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    
    // We loop though bits and perform counting sort on the bits the loop will terminate when the power is greater than maximum element in the vector
    for(int power = 1; max/power > 0; power*=BASE)  // Initially the power is set to 1 then BASE then BASE^2 them BASE^3 and so on
    {
        // Initialize the vector B to have the same size as A
        vector<int> B = vector<int>(A.size(), 0);
        
        // Perform counting sort
        CountingSort(A, B, power);
        
        // Store B in A using move semantics
        A = B;
    }
    
}


int main()
{
    // Seed the random number generator
    srand(time(0));
    
    // Create a variable called size
    int size;
  
    // Get input from user
    cout<<"The size ";
    cin>>size;
    
    // Create a vector called numbers
    vector<int> numbers;
    
    // Populate the vector by taking input from user
    for(int i = 0; i < size; i++)
    {
        int val;
        cout<<i + 1<<"th val ";
        cin>>val;
        numbers.push_back(val);
    }
    
    // Print the contents of vector
    for(auto number: numbers)
    {
      cout<<number<<" ";
    }
    cout<<endl;
    
    // Perform radix sort
    RadixSort(numbers);
    
    // Print the contens of vector numbers
    for(auto number: numbers){
        cout<<number<<" ";
    }
    
     cout<<endl;
    
    return 0;  
} 
