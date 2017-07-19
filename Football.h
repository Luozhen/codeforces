//
// Created by luozhen on 2017/7/19.
//

#ifndef CODEFORCES_FOOTBALL_H
#define CODEFORCES_FOOTBALL_H

#endif //CODEFORCES_FOOTBALL_H
#include <iostream>
#include <string>
using namespace std;
//Petya loves football very much. One day, as he was watching a football match, he was writing the players' current
// positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones.
// A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7
// players of some team standing one after another, then the situation is considered dangerous. For example,
// the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation.
// Determine whether it is dangerous or not.
//
//Input
//        The first input line contains a non-empty string consisting of characters "0" and "1", which represents
// players. The length of the string does not exceed 100 characters. There's at least one player from each team present
// on the field.
//
//Output
//        Print "YES" if the situation is dangerous. Otherwise, print "NO".
//
//Examples
//        input
//001001
//output
//        NO
//input
//1000000001
//output
//        YES
int football_solution() {
    string str;
    cin >> str;
    int len = str.length(), count = 0, start_loc, end_loc;
    bool flag = false;
    if (len <= 7) flag = false;
    for (int i = 0; i < len; ++i) {
        if (i == 0 || str[i] != str[i - 1]) {
            start_loc = i - 1;
            count = 1;
        } else if (str[i] == str[i - 1]) {
            end_loc = i;
            count++;
        }
        if (start_loc >= 0 && count == 7 || count >= 7 && end_loc < len - 1) {
            flag = true;
            break;
        }
    }
    string res = flag ? "YES" : "NO";
    cout << res;
    return 0;
//    char str[101];
//    gets(str);
//    int count = 0;
//    bool serialZero = false;
//    for(int i = 0; i < strlen(str); i++)
//    {
//        if(!serialZero && str[i] == '0')
//        {
//            serialZero = true;
//            count = 0;
//        }
//        else if(serialZero && str[i] == '1')
//        {
//            serialZero = false;
//            count = 0;
//        }
//        count++;
//        if(count == 7)
//        {
//            cout << "YES";
//            return 0;
//        }
//    }
//    cout << "NO";
//    return 0;
}