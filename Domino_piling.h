//
// Created by luozhen on 2017/7/18.
//

#ifndef CODEFORCES_DOMINO_PILING_H
#define CODEFORCES_DOMINO_PILING_H

#endif //CODEFORCES_DOMINO_PILING_H
#include <iostream>
using namespace std;
//You are given a rectangular board of M × N squares. Also you are given an unlimited number of standard domino pieces
// of 2 × 1 squares. You are allowed to rotate the pieces. You are asked to place as many dominoes as possible on the
// board so as to meet the following conditions:
//
//1. Each domino completely covers two squares.
//
//2. No two dominoes overlap.
//
//3. Each domino lies entirely inside the board. It is allowed to touch the edges of the board.
//
//Find the maximum number of dominoes, which can be placed under these restrictions.
//
//Input
//        In a single line you are given two integers M and N — board sizes in squares (1 ≤ M ≤ N ≤ 16).
//
//Output
//        Output one number — the maximal number of dominoes, which can be placed.
//
//Examples
//        input
//2 4
//output
//4
//input
//3 3
//output
//4
int dp_solution() {
    int m, n;
    cin >> m >> n;
    // return m * n / 2;
    if ((m * n) % 2) return (m / 2) * n + n / 2;
    else {
        if (m % 2 == 0)
            return m / 2 * n;
        else if (n % 2 == 0)
            return n / 2 * m;
    }
}