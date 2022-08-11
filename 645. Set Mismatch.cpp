/*
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number 
in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/

/*
Here I came up with two solutions. 

The first solves the problem in a single loop due to the fact that the
xor sum of a range only has 4 results. Thus when this sum is xor'd with the array we get sum = a ^ b,
the two numbers which are missing or doubled. For each int i in nums, we can set each a nums[i] to -nums[i].
If we ever find that nums[i] is negative, then i is our repeated number. And sum ^ i gets the missing number.

The second solution does something similar. However, we find the right most bit set of sum and we know that only one
of our numbers will have that bitset. So we find a second xor sum of all numbers between 1 and n as well as in the array
with that bit set. Now our second xor sum is equal to one of our numbers. We just have to check which is present to return
the correct order.
*/

inline int rangeXOR(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a = rangeXOR(nums.size()), b;
        
        //For each int i in nums, we can set each a nums[i] to -nums[i]. If we ever find that nums[i] is negative, then b = i is our repeated number.
        for (int i: nums) {
            a ^= abs(i);
            if (nums[abs(i) - 1] < 0) b = abs(i);
            else nums[abs(i) - 1] *= -1;
        }
        // and then a ^ b gets the missing number
        return {b, b ^ a};
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), a = rangeXOR(n), b = 0;
        
        for (int i: nums) 
            a ^= i;
        
        int r = a & ~(a - 1); //rightmost bit
        
        //we find a second xor sum of all numbers between 1 and n + numbers in the array
        //that have r set of a (the xor of our answers). Now our second xor sum is equal to one of our numbers
        for (int i: nums) 
            if (r & i) b ^= i;
        
        for (int i = 1; i <= n; i++) 
            if (r & i) b ^= i;
        
        return find(begin(nums), end(nums), b) == end(nums) ? vector<int>{a ^ b, b} : vector<int>{b, a ^ b};
    }
};


