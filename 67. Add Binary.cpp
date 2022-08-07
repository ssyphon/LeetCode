/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        //swap for simplicity of code to just use a as return value
        if (a.size() < b.size()) a.swap(b);
        int n = a.size() - 1, m = b.size() - 1, carry = 0;
        
        //add the b to a and maintain carry
        while (m >= 0) {
            int new_val = (a[n] - '0') + (b[m] - '0') + carry;
            a[n] = '0' + new_val % 2;
            carry = new_val / 2;
            m--, n--;
        }
        
        //if carry then keep carrying it, otherwise a is good to return
        while (n >= 0 and carry) {
            int new_val = (a[n] - '0') + carry;
            a[n] = '0' + new_val % 2;
            carry = new_val / 2;
            n--;
        }
        
        //if a needs to have its size increased it means that we kept carry after iterating through all of a, append 1 to front if so
        if (carry) a.insert(0, 1, '1');
        
        return a;
    }
};
