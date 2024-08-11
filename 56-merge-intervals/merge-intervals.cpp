class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;

        vector<int> newInterval = intervals[0];
        result.push_back(newInterval);

        for (const auto& interval : intervals) {
            if (interval[0] <= newInterval[1]) {
                // Overlapping intervals,
                // update the end if needed
                newInterval[1] = max(newInterval[1], interval[1]);
                result.back() = newInterval;
            } else {
                // Disjoint intervals,
                // add the new interval to the list
                newInterval = interval;
                result.push_back(newInterval);
            }
        }

        return result;
    }
};