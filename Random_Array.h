//
// Created by luozhen on 2017/7/19.
//

#ifndef CODEFORCES_RANDOM_ARRAY_H
#define CODEFORCES_RANDOM_ARRAY_H

#endif //CODEFORCES_RANDOM_ARRAY_H
#include <iostream>
#include <cstdlib>
using namespace std;
const int max_len = 100
// 随机生成不重复的数据数组

// 方法一，利用两个数组辅助完成
int* func_1(int n){
    int hashtable[max_len] = {0}, output[max_len] = {0};
    for (int i = 0; i < n; ++i) {
        int tmp = rand() * n;
        while(!hashtable[tmp]){
            tmp = rand() * n;
        }
        hashtable[tmp] = 1;
        output[i] = tmp;
    }
    return output;
}

// 方法二，一个数组，每次生成后将生成的数从数组中移除
int* func_2(int n){
    int output[max_len] = {0}, helptable[max_len] = {0}, j;
    for (j = 0; j < n; ++j) {
        helptable[j] = j;
    }
    while(j > 0){
        int tmp = rand() * j;
        output[n - j] = helptable[tmp];
        for (int k = tmp + 1; k < j; --k) {
            helptable[k - 1] = helptable[k];
        }
        j--;
    }
    return output;
}

// 方法三，同方法二，只是不是将生成的数移除，而是与可见数组最后元素交换
int* func_3(int n){
    int output[max_len] = {0}, helptable[max_len] = {0}, i;
    for (i = 0; i < n; ++i) {
        helptable[i] = i;
    }
    while(i > 0){
        int tmp = rand() * i;
        output[n - i] = helptable[tmp];
        // swap two element
        helptable[tmp] = helptable[i - 1];
        i--;
    }
    return output;
}

// 方法四，同方法三，但不再使用两个数组
int* func_4(int n){
    int output[max_len] = {0}, i;
    for (i = 0; i < n; ++i) {
        output[i] = i;
    }
    while(i > 0){
        int tmp = rand() * i;
        int cache = output[tmp];
        output[tmp] = output[i - 1];
        output[i - 1] = cache;
        i--;
    }
    return output;
}