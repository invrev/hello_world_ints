#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool Comp(const Interval &a, const Interval &b){
    return a.start < b.start;
};

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    int len = intervals.size();
    //sort first
    if (len > 0 ) {
        sort(intervals.begin(),intervals.end(),Comp);
        int p_start = intervals[0].start;
        int p_end = intervals[0].end; 
        for (int i=1;i<len;i++) {
            //cout << "min_= " << intervals[i].start << " max_ = " << intervals[i].end << endl;
            if (p_end >= intervals[i].start) {
                //overlapping
                p_end = max(intervals[i].end,p_end);
            } else {
                result.push_back (Interval(p_start,p_end));
                p_start = intervals[i].start;
                p_end = intervals[i].end;
            }
        }
        result.push_back (Interval(p_start,p_end));
    }
    return result;
}

int main () {
    vector<Interval> interval_vec;
    //interval_vec.push_back (Interval(1,3));
    //interval_vec.push_back (Interval(2,6));
    //interval_vec.push_back (Interval(8,10));
    //interval_vec.push_back (Interval(15,18));
    interval_vec.push_back (Interval(1,4));
    interval_vec.push_back (Interval(2,3));
    vector<Interval> result_ =  merge(interval_vec);
    int len = result_.size();
    for (int i=0;i<len;i++) {
        cout << " ( " << result_[i].start << "," << result_[i].end << " ) ";
    }
    cout << endl;

}
