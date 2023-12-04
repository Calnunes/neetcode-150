#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1), suffix(n,1);

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        cout << "nums: ";
        for(int i : nums){
            cout << i << " ";
        }
        cout << endl << endl;      

        cout << "pre_prod: ";
        for(int i : prefix){
            cout << i << " ";
        }
        cout << endl << endl;

        cout << "post_prod: ";
        for(int i : suffix){
            cout << i << " ";
        }
        cout << endl << endl;

        for(int i =0; i<n; i++){
            prefix[i] *= suffix[i];
        }

        return prefix;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,3,4,5,6};
    vector<int> output = obj.productExceptSelf(nums);

    cout << "output: ";
    for(int i : output){
        cout << i << " ";
    }
    cout<<endl<<endl;
}



/*
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/