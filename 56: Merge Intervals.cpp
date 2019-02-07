/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
bool compare(Interval elem1, Interval elem2)
{
    return elem1.start < elem2.start;
}
class Solution {
public:
    void printElem(vector<Interval>& intervals)
    {
        cout << "[";
        for(int i = 0; i < intervals.size(); i++)
        {
            cout << "[" << intervals[i].start << "," << intervals[i].end << "]" << ' ';
        }
        cout << endl;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        //return intervals;
        //printElem(intervals);
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(intervals[i].end >= intervals[i + 1].start)
            {
                intervals[i].end = max(intervals[i + 1].end, intervals[i].end);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
            //printElem(intervals);
        }
        return intervals;
    }
};
