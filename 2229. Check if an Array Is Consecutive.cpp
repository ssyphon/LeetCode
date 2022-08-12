/*
Given an integer array nums, return true if nums is consecutive, otherwise return false.

An array is consecutive if it contains every number in the range [x, x + n - 1] (inclusive), 
where x is the minimum number in the array and n is the length of the array.
*/

/*
I continuously shrink the range of available numbers and use the array itself with [number % size] as a check 
because in a continuous range of size there should be no repeats of number % size. Just make the element negative 
as is commonly used in the 1..n problems.

My solution was the only solution I saw posted that had O(n) time, O(1) space AND 1 pass to solve the problem.
*/

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        //l and h represent the current valid range
        int n = nums.size(), l = nums[0] - n + 1, h = nums[0] + n - 1;
        
        for (int i = 1; i < n; i++) {
            //use the absolute value of current int to check range validity and computer new range
            int a = abs(nums[i]);
            if (a < l or a > h) return false;
            if (nums[a % n] < 0) return false;
            l = max(l, a - n + 1);
            h = min(h, a + n - 1);
            //a simple way to check for duplicates without extra space in an array that should span a range of n
            nums[a % n] *= -1;
        }
        
        return h - l == n - 1;
    }
};
