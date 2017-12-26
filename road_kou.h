//
// Created by luozhen on 2017/8/25.
//

#ifndef CODEFORCES_ROAD_KOU_H
#define CODEFORCES_ROAD_KOU_H

#endif //CODEFORCES_ROAD_KOU_H
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
//现在城市有N个路口，每个路口有自己的编号，从0到N-1，每个路口还有自己的交通控制信号，例如0,3表示0号路口的交通信号每3个时刻变化一次，
// 即0到3时刻0号路口允许通过，3到6时刻不允许通过，而6到9时刻又允许通过；以此类推，所有路口的允许通行都从时刻0开始。
// 同时城市中存在M条道路将这N个路口相连接起来，确保从一个路口到另一个路口都可达，每条路由两个端点加上通行所需要的时间表示。
// 现在给定起始路口和目的路口，从0时刻出发,请问最快能在什么时刻到达？
//输入:
//N路口的个数 N个路口，第一列是路口id，第二列是该路口通行周期 M 路的条数 M条路，第一列路一端的路口，第二列路另一端的路口，
// 第三列通行所需要的时间 S起点，T目标点
//        输出:
//最短时间
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int minTravelTime(int N, vector<vector<int>> intersections, int M, vector < vector < int > > roads, int s, int t) {


}

int main() {
    int res;

    int _N;
    cin >> _N;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _intersections_rows = _N;
    int _intersections_cols = 2;

    vector< vector < int > > _intersections(_intersections_rows);
    for(int _intersections_i=0; _intersections_i<_intersections_rows; _intersections_i++) {
        for(int _intersections_j=0; _intersections_j<_intersections_cols; _intersections_j++) {
            int _intersections_tmp;
            cin >> _intersections_tmp;
            _intersections[_intersections_i].push_back(_intersections_tmp);
        }
    }
    int _M;
    cin >> _M;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _roads_rows = _M;
    int _roads_cols = 3;

    vector< vector < int > > _roads(_roads_rows);
    for(int _roads_i=0; _roads_i<_roads_rows; _roads_i++) {
        for(int _roads_j=0; _roads_j<_roads_cols; _roads_j++) {
            int _roads_tmp;
            cin >> _roads_tmp;
            _roads[_roads_i].push_back(_roads_tmp);
        }
    }
    int _s;
    cin >> _s;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _t;
    cin >> _t;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



    res = minTravelTime(_N, _intersections, _M, _roads, _s, _t);
    cout << res << endl;

    return 0;

}