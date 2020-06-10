#include <vector>
#include <iostream>

using std::vector;


class DoubleLETT {
private:
    vector<int> height, euler, first;
    vector<bool> seen;
    vector<int> level2;
    void eulerTour(vector<vector<int>> &g, int node, int h = 0);
    void sqrtDecomposition();

public:
    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>> &g);


};