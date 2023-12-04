#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>


using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        set<int> st;
        unordered_map<int, vector<int> > freq_to_vals;
        vector<int> result;

        for( int i : nums){
            mp[i]++;
        }

        for(auto i : mp){
            st.insert(i.second);
            freq_to_vals[i.second].push_back(i.first);
        }

        int count = 0;
        for(auto iter = st.rbegin(); iter != st.rend(); iter++){
            for(int i : freq_to_vals[*iter]){
                result.push_back(i);
                if(++count >= k)
                    return result;
            }
        }

        return {};
    }
};


int main(){
    Solution obj;
    vector<int> nums = {4,5,1,1,1,2,2,3};
    int k = 2;
    vector<int> output = obj.topKFrequent(nums,k);

    for(int i : output){
        cout << i;
    }
    cout<<endl;
}





/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/