//
// Created by luozhen on 2017/12/21.
//

#ifndef CODEFORCES_A266_H
#define CODEFORCES_A266_H

#endif //CODEFORCES_A266_H

//Stones on the Table
//There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no other stones between them.
//
//Input
//The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.
//
//The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.
//
//Output
//Print a single integer — the answer to the problem.
//
//Examples
//input
//3
//RRG
//output
//1
//input
//5
//RRRRR
//output
//4
//input
//4
//BRBG
//output
//0

void stone_on_the_table() {
    int n;
    std::cin >> n;
    string str;
    cin >> str;
    int i, j, cnt;
    i = j = cnt = 0;
    while(j < n) {
        if(j > 0) {
            if(str[i] != str[j]) {
                i = j;
                j++;
                continue;
            }else {
                j++;
                cnt++;
                continue;
            }
        }
        j++;
    }
    cout << cnt;
}