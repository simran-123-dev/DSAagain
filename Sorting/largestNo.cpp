/* 
   PROBLEM: 179. Largest Number (LeetCode)
   TOPIC: Arrays / Sorting / Strings
   PATTERN: Custom Comparator Sorting
   
   THEORY:
   - Task: Arrange a list of non-negative integers such that they form the largest possible number.
   
   - Approach: Custom Comparison Logic
     1. String Conversion: Convert all integers to strings to facilitate concatenation.
     2. Comparison Rule: For any two strings 'a' and 'b', we compare (a + b) with (b + a).
        - If (a + b) > (b + a), then 'a' should come before 'b'.
        - Example: a = "3", b = "30" -> "330" > "303", so "3" comes first.
     3. Sorting: Sort the array of strings using this custom rule.
     4. Edge Case: If the largest number after sorting is "0", the entire result should be "0" (to avoid "000").
     5. Concatenation: Join the sorted strings to form the final result.

   - Time Complexity: O(N log N * K), where K is the average length of the strings (for comparison).
   - Space Complexity: O(N * K) to store the strings.
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Custom comparator to determine the order of concatenation
    static bool cmp(string a, string b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // Step 1: Convert all integers to strings
        for(int x : nums) {
            arr.push_back(to_string(x));
        }

        // Step 2: Sort strings using the custom comparator
        sort(arr.begin(), arr.end(), cmp);

        // Step 3: Handle the edge case where the largest number is zero
        // If the first element is "0", all subsequent elements are "0"
        if(arr[0] == "0") return "0";

        // Step 4: Build the final result string
        string result = "";
        for(string s : arr) {
            result += s;
        }

        return result;
    }
};
