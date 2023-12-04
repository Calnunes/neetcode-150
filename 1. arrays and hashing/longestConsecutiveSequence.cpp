#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            s.insert(i);
        }

        int maxlen = 0;
        for(int num: nums){
            if(s.find(num - 1) != s.end()){
                int currlen = 1;
                int currnum = num;

                while(s.find(++currnum) != s.end()){
                    currlen++;
                }

                maxlen = max(maxlen, currlen);
            }
        }

        return maxlen;

    }
};

int main(){
    Solution obj;
    vector<int> nums {100, 4, 200, 1,3,2};

    cout << obj.longestConsecutive(nums);
    return 0;
}


/*
128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/