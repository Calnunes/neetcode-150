#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool is_alphanum(char c){
        return isalpha(c) || isdigit(c);
    }

    bool isPalindrome(string s) {
        string check = "";
        for(char c: s){
            if(is_alphanum(c)){
                check += tolower(c);
            }
        }

        int i = 0, j = check.length() - 1;
        while(i<j){
            if(check[i] != check[j]){
                // cout << check[i] << " " << check[j] << endl;
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main(){
    Solution obj;
    // string str = "abcdedcba";
    string str = "ab!cd:e;dc'bak";
    cout << obj.isPalindrome(str);
    return 0;
}


/*

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/