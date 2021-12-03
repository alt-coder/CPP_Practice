/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.

*/
#include <bits/stdc++.h>
using namespace std;
// A solution that uses hashing with time complexity O(n^2) and space complexity O(n)
bool find3Numbers(int A[], int n, int X)
{
    unordered_set<int> setA;
    for(int i = 0; i < n ; i++) setA.insert(A[i]);
    for(int i =0; i < n; i++){
        for(int j =0; j< n; j++){

            if(i != j && setA.find(X-A[i]-A[j]) != setA.end()) return true;
        }
    }
    return false;
    //Your Code Here
}

// A more efficient Solution that uses two pointer Apprach and have a time comlexity of 
// O(n^2) but has Space Complexity of O(1)
bool find3NumberTwoPointer(int A[], int n, int X){
    // sort the array 
    sort(A,A+n);
    
    for(int i = 0; i < n-2 ; i++){
        //Step 1 Traverse the array 
        int l = i+1, r = n-1; // create l and right pointer
        int target = X-A[i]; // create a two sum target
        while(l < r){        // loop till left pointer is less than right pointer
            int t = A[l]+A[r];      // sum of left pointer and right pointer
            if(t == target) return 1;   // if the sum mactches the target accept the answer
            if(t < target) l++;     // sum is less than target increament the left pointer
            else r--;       // else decrement the right pointer
        }
        
    }
    return false;       // if not found return false

}

int main(){
    int arr[] = {1,3,6,5,11};
    cout << find3Numbers(arr, 5,18);
    cout << find3NumberTwoPointer(arr, 5,18);
}
