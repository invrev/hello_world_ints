#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval () : start(0),end(0) {}
    Interval (int start,int end) : start(start),end(end) {}

};

bool Comp(const Interval &a, const Interval &b){
    return a.start < b.start;
};

vector<Interval> insert (vector<Interval>& intervals,Interval newInterval ) { 
    vector<Interval> result;
    int new_start =  newInterval.start;
    int new_end = newInterval.end;
    int len = intervals.size();
    bool isIncluded = false;
    if (len > 0) {
        int p_start = intervals[0].start;
        int p_end = intervals[0].end;
        for (int i=1;i<len;i++) {
            if ( (p_end >= new_start)  && (p_start <= new_start) && !isIncluded) {
                p_end = max(new_end,p_end);
                p_start = min(new_start,p_start);
                isIncluded = true;
            } if (p_end >= intervals[i].start) {
                    //overlapping
                    p_end = max(intervals[i].end,p_end);
            } else {
                result.push_back (Interval(p_start,p_end));
                p_start = intervals[i].start;
                p_end = intervals[i].end;
            }
        }
        //last pair
        result.push_back (Interval(p_start,p_end));
    }
    if (isIncluded == false) {
        result.push_back (Interval(new_start,new_end));
    }

    //sort and returnn
    sort(result.begin(),result.end(),Comp);
    return result;
}

int main () {
    vector<Interval> intervals;
    //intervals.push_back(Interval(1,3));
    //intervals.push_back(Interval(6,9));
    //Interval v (2,5);
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));
    Interval v (4,9);
    //Interval v (3,5);
    vector<Interval> result_ ;
    result_ = insert (intervals,v);
    int len = result_.size();
    for (int i=0;i<len;i++) {
        cout << " ( " << result_[i].start << "," << result_[i].end << " ) ";
    }
    cout << endl;

}
