/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), 
or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
*/

/*
Using bit manipulation I created this simple program which ran in 42ms, beating 99.5% of submissions.
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //a domino of ints a,b where a, b < 10 could be at most 0b11000000 or 384 when storing each number as a bit
        int a[385] = {0};
        
        //OR the result of left shift by each num - 1 on domino to create a unique num corresponding to each domino, increment
        for_each(begin(dominoes), end(dominoes), [&](vector<int> &d) { 
          a[(1 << (d[0] - 1)) | (1 << (d[1] - 1))]++;
        });
        
        //accumulate all pairs found, add d choose 2, n!/(k!*(n - k)!) -> p!/(2*(p - 2)!) -> p * (p - 1) / 2
        return accumulate(a, a + 385, 0, [](int &res, int &p) { 
          return res += (p * (p - 1) >> 1);
        });
    }
};
