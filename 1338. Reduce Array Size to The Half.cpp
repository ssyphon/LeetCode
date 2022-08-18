/*
You are given an integer array arr. You can choose a set of integers and remove all 
the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
*/

/*
I decided to go for speed and ended up achieving 85ms, better than 100% of submissions for this problem on
LeetCode. Although the approach isn't ideal for real life, (better to use std::vector etc.) I wanted to
showcase this.
*/

class Solution {
public:
    //save space and allocation time because only one instance of Solution is ever being called and minSetSize isn't run in parallel
    inline static int counts[100001];
    int minSetSize(vector<int>& arr) {
        memset(counts, 0, sizeof(counts));
        
        for (const int &i: arr) 
            ++counts[i];
        
        //the maximum frequency can be the size of arr
        int freqs[size(arr) + 1];
        memset(freqs, 0, sizeof(freqs));
        
        for (int i = 1; i <= 100000; i++)
            if (counts[i])
                ++freqs[counts[i]];
        
        int n = (size(arr) + 1) / 2;
        int res = 0;
        
        //each occurence in freqs is good enough to remove i elements from arr
        for (int i = size(arr); n > 0; i--)
            while (freqs[i]-- and n > 0)
                n -= i, res++;
        
        return res;
    }
};
