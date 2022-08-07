/*
A binary watch has 4 LEDs on the top to represent the hours (0-11), 
and 6 LEDs on the bottom to represent the minutes (0-59). Each LED 
represents a zero or one, with the least significant bit on the right.

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), 
return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must be consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        //check each combination of hour and minute with hour shifted left by 6 to match watch described.
        //use builtin_popcount to check if set bits is equal to number of LEDs turned on and add to result if so
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (__builtin_popcount(h << 6 | m) == num)
                    res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return res;
    }
};
