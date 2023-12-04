#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return nums.size();
    }
};

int main(){
    Solution obj;
    vector<int> nums {100, 4, 200, 1,3,2};

    cout << obj.longestConsecutive(nums);
    return 0;
}
