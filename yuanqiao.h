//
// Created by luozhen on 2017/7/23.
//

#ifndef CODEFORCES_YUANQIAO_H
#define CODEFORCES_YUANQIAO_H

#endif //CODEFORCES_YUANQIAO_H
#include <iostream>
#include <set>
const int max_len = 256;

using namespace std;

int lengthOfLongestSubstring(string str){
    int array[max_len] = {0};
    int len = str.length();
    if(len < 2) return len;
    array[str[0]] = 1;
    int count = 1, max_count = 1;
    for (int i = 1; i < len; ++i) {
        if(str[i] != str[i - 1] && array[str[i]] == 0){
            array[str[i]] = 1;
            count++;
        }
        else{
            if(count > max_count) max_count = count;
            for (int j = 0; j < max_len; ++j) {
                array[j] = 0;
            }
            count = 1;
            array[str[i]] = 1;
        }
    }
    if(count > max_count) max_count = count;
    return max_count;
}