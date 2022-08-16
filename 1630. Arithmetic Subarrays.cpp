/*
A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference
between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if 
s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:

1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range
queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if 
the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, 
and false otherwise.
*/

/*
My solution here avoids resorting subvectors on each call by using the knowledge that an arithmetic subvector
will have certain properties of each number that can be checked without arranging the elements.
*/

//With optimizations such as reserve and efficient data structures this solution ran in 19ms, which was clear 1st on LeetCode. (average of 110ms)
//O(n * min(n, m)) time where n is nums.size() and m is l.size(). O(n) space worst case

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        int m = size(l);
        res.reserve(m);
        
        for (int i = 0; i < m; i++) {
            //minmax is a quick and neat way of finding min/max elements in a subvector with a single line
            auto [p_min, p_max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);
            int mn = *p_min;
            int mx = *p_max;
            //if my and max are equal, then our subvector is arithmetic with a difference of 0
            if (mx == mn) { res.push_back(true); continue; }
            
            int len = r[i] - l[i];
            //the range must be able to be evenly divided, so avoid a rigorous check with this line
            if ((mx - mn) % len) { res.push_back(false); continue; }
            
            int diff = (mx - mn) / len;
            
            //using a simple int array to store which values have been found
            int check[len + 1];
            memset(check, 0, sizeof(check));
            
            int j;
            
            //check every element in range to ensure that it not only has a place in the sequence, but that place in unique
            for (j = l[i]; j <= r[i]; j++) {
                int dist = nums[j] - mn;
                if (dist % diff or check[dist / diff])
                    break;
                check[dist / diff] = 1;
            }

            res.push_back(j > r[i]);
        }
        return res;
    }
};
