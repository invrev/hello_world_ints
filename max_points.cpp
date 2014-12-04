#include<iostream>

using namespace std;


typedef pair<double, double> Line;
namespace std1 {
    template <>
    struct hash < Line > {
        std::size_t operator()(const Line& l) const{
            return hash<double>()(l.first) ^ hash<double>()(l.second);
        }
    };
}

int maxPoints(vector<Point> &points) {
    size_t size = points.size();
    if (size < 3) return size;
    size_t mx = 0;
    for (size_t i = 0; i < size; ++i){
        unordered_map< Line, size_t> hsh;
        size_t extra_points = 0;
        for (int j = i; j < size; ++j){
            double dy = points[j].y - points[i].y;
            double dx = points[j].x - points[i].x;
            if (!dy && !dx)
                extra_points++;
            else {
                double A = dx != 0 ? dy / dx : 0;
                Line line = make_pair(A, points[i].y - points[i].x*A);
                hsh[line]++;
            }
        }
        size_t new_mx = 0;
        for (auto l : hsh)
            new_mx = max(new_mx, l.second);
        new_mx += extra_points;
        mx = max(mx, new_mx);
    }
    return mx;
}

int main () {

}

