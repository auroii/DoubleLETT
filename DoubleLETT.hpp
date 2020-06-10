#include <vector>

 using std::vector;


class DoubleLETT {
private:
    vector<int> height, euler, first;
    vector<bool> seen;
    void eulerTour(vector<vector<int>> &g, int node, int h = 0);




public:
    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>> &g);


};