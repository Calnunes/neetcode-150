#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool elem_exists_in_vec(vector<vector<int>> nums, vector<int> elem){
        for(auto num : nums){
            if(num[0] == elem[0] && num[1] == elem[1] && num[2] == elem[2]){
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        unordered_map<int, bool> mp;

        for(int i : nums){
            mp[i] = true;
        }

        // Input: nums = [-1,0,1,2,-1,-4]
        for(int i =0; i< n; i++){
            mp[nums[i]] = false;
            for(int j = i+1; j< n; j++){
                mp[nums[j]] = false;

                int num_to_check = -1 * (nums[i] + nums[j]);
                if(mp[num_to_check]){
                    vector<int> ans_elem { nums[i], nums[j], -1 * (nums[i] + nums[j])};
                    sort(ans_elem.begin(), ans_elem.end());
                    // cout <<"hello\n";
                    if(!elem_exists_in_vec(result, ans_elem)){
                        // cout << "hey\n";
                        result.push_back(ans_elem);
                    }
                }

                mp[nums[j]] = true;
            }
            mp[nums[i]] = true;
        }

        return result;
    }
};

int main(){
    Solution obj;
    vector<int> nums {-1, 0, 1, 2, -1, -4};

    for(vector<int> num : obj.threeSum(nums)){
        for(int i : num){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}






/*

15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/