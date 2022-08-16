/*
You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n).

In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 
to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. 
It is guaranteed that all the elements of the array can be made equal using some operations.

Given an integer n, the length of the array, return the minimum number of operations needed to make all the elements of arr equal.
*/

/*
What I noticed was that the result was taking the smallest and largest values and operating on them n - 1 times. 
Then the next step was n - 3 operations until the middle element was reached (n goes to 0/1), or just outside the 
middle when n is even. This mean that the result is either the formula for the sum of the first n / 2 odd intergers 
or first n / 2 even integers.

1 3 5 7
4 3 5 4 (3 operations or n - 1)
4 4 4 4 (1 operation or n - 3)

1 3 5
3 3 3 (2 operations or n - 1)

Notice that the total steps is n / 2;

The sum for even is (n + 1) * n and odd is simply n^2. However, when our n is odd, the operations per step is even and vice versa. 
So I came up with the following code.
*/

class Solution {
public:
    int minOperations(int n) {
        return ((n >> 1) + (n & 1)) * (n >> 1);
    }
};
