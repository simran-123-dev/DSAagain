/* 
   PROBLEM: 274. H-Index (LeetCode)
   TOPIC: Arrays / Sorting
   PATTERN: Bucket Sort (O(N) Optimal)
   
   THEORY:
   - Task: Maximize 'h' where 'h' papers have at least 'h' citations.
   - Approach: Create buckets up to size 'n'. Count citations, capping at 'n'.
     Traverse from right to left to find the first index where cumulative papers >= index.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);

        for (int c : citations) {
            if (c >= n) buckets[n]++;
            else buckets[c]++;
        }

        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += buckets[i];
            if (count >= i) return i;
        }
        return 0;
    }
};
