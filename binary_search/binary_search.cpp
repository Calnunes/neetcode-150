#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, n = nums.size();
        while(low<=high){
            int mid = (low + high) / 2;
            // cout << "nums[" << low << "]=" << nums[low] << " nums[" << high << "]="  << nums[high] << " nums[" << mid << "]=" << nums[mid] << endl;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;

    }
};

int main(){
    Solution obj;
    vector<int> nums {1,4,6,7,8,23,26,27,46,48,60,78,89,101,123};
    int target = 27;

    cout << nums.size() << endl;

    for(int i=0; i<nums.size(); i++){
        cout << obj.binarySearch(nums, nums[i]) << " ";
    }
    return 0;
}
