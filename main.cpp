#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    // FIXME
    return {};
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
}

int main() {
  TestLargestTriangleArea();
  std::cout << "Ok!" << std::endl;
  return 0;
}
