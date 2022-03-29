#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  struct Point {
    int x;
    int y;

    double distanceTo(const Point& p) const {
      const int dx = x - p.x;
      const int dy = y - p.y;
      return sqrt(dx * dx + dy * dy);
    }
  };

  struct Line {
    Line(Point p1, Point p2) {
      const int dx = p2.x - p1.x;
      const int dy = p2.y - p1.y;
      a = dy;
      b = -dx;
      c = dx * p1.y - dy * p1.x;
      dist_div = sqrt(a * a + b * b);
    }

    double distanceTo(const Point& p) const {
      return abs(a * p.x + b * p.y + c) / dist_div;
    }

    int a;
    int b;
    int c;
    double dist_div;
  };

 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double max_area = 0;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1;  j < points.size(); ++j) {
        const Point p1{points[i][0], points[i][1]};
        const Point p2{points[j][0], points[j][1]};
        const Line line{p1, p2};
        double max_h = 0;
        for (int k = j + 1; k < points.size(); ++k) {
          const Point p3{points[k][0], points[k][1]};
          max_h = max(max_h, line.distanceTo(p3));
        }
        max_area = max(max_area, 0.5 * p1.distanceTo(p2) * max_h);
      }
    }

    return max_area;
  }
};

#define ASSERT_DOUBLE_EQ(x, y) assert((x - y) < 1e-6)

void TestLargestTriangleArea() {
  Solution s;
  {
    vector<vector<int>> points{{0,0},{0,1},{1,0},{0,2},{2,0}};
    ASSERT_DOUBLE_EQ(2.0, s.largestTriangleArea(points));
  }
  {
    vector<vector<int>> points{{1,0},{0,0},{0,1}};
    ASSERT_DOUBLE_EQ(0.5, s.largestTriangleArea(points));
  }
  {
    vector<vector<int>> points{{4,6},{6,5},{3,1}};
    ASSERT_DOUBLE_EQ(5.5, s.largestTriangleArea(points));
  }
}

int main() {
  TestLargestTriangleArea();
  std::cout << "Ok!" << std::endl;
  return 0;
}
