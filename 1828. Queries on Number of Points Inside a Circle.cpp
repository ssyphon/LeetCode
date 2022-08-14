/*
You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. 
Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

Return an array answer, where answer[j] is the answer to the jth query.
*/

/*
Using sort we can decrease the range of searched points substantially.
Custom sort, lower_bound, upper_bound, count_if calls were implemented using lambdas.
Althought the algorithm is technically O(n^2) worst case scenario, this function
performs 4 times faster than a brute force solution on the data given for testing.
*/

class Solution {
public:
    
    inline bool in_circle(int &x, int &y, int &r_squared, vector<int> &point) {
        return pow(x - point[0], 2) + pow(y - point[1], 2) <= r_squared;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //sort the points based on x value using lambda
        sort(begin(points), end(points), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        //reserve size for efficient push_back operations
        vector<int> res;
        res.reserve(queries.size());
        int curr = 0;
        
        for (vector<int> & q: queries) {
            int x = q[0];
            int y = q[1];
            int r = q[2];
            int r_squared = r * r;
            
            vector<int> low = {x - r, 0}, high = {x + r, 0};
            
            //get the lower and upper bounds for valid points
            //upper bound is first point greater than x + r, lower bound is first point equal to or greater than x - r
            auto low_bound = lower_bound(begin(points), end(points), low, [] (const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            });
            
            auto high_bound = lower_bound(begin(points), end(points), high, [] (const vector<int> &a, const vector<int> &b) {
                return a[0] <= b[0];
            });
            
            //count all points in between bounds that are in circle specified by query using in_circle
            int count = count_if(low_bound, high_bound, [&](vector<int> &point) {
                return in_circle(x, y, r_squared, point);
            });
            
            res.push_back(count);
        }
        
        return res;
    }
};
