//
// Created by luozhen on 2017/7/18.
//

#ifndef CODEFORCES_THEATRESQUARE_H
#define CODEFORCES_THEATRESQUARE_H

#endif //CODEFORCES_THEATRESQUARE_H

#include <iostream>
using namespace std;
// Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of
// the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of
// the size a × a.
//
// What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the
// Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones
// should be parallel to the sides of the Square.
//
// Input
// The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).
//
// Output
// Write the needed number of flagstones.
//
// Examples
// input
// 6 6 4
// output
// 4

long long ts_solution(){
    int n, m, a;
    cin >> n >> m >> a;
    if(!a) return 0;
    return 1LL * ((n + a - 1) / a) * ((m + a - 1) / a);
}