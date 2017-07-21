//
// Created by luozhen on 2017/7/21.
//

#ifndef CODEFORCES_HELPFUL_MATHS_H
#define CODEFORCES_HELPFUL_MATHS_H

#endif //CODEFORCES_HELPFUL_MATHS_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//Xenia the beginner mathematician is a third year student at elementary school. She is now learning the addition operation.
//
//The teacher has written down the sum of multiple numbers. Pupils should calculate the sum. To make the calculation easier,
// the sum only contains numbers 1, 2 and 3. Still, that isn't enough for Xenia. She is only beginning to count, so she
// can calculate a sum only if the summands follow in non-decreasing order. For example, she can't calculate sum 1+3+2+1
// but she can calculate sums 1+1+2 and 3+3.
//
//You've got the sum that was written on the board. Rearrange the summans and print the sum in such a way that Xenia can
// calculate the sum.
//
//Input
//        The first line contains a non-empty string s — the sum Xenia needs to count. String s contains no spaces.
// It only contains digits and characters "+". Besides, string s is a correct sum of numbers 1, 2 and 3. String s is
// at most 100 characters long.
//
//Output
//        Print the new sum that Xenia can count.
//
//Examples
//        input
//3+2+1
//output
//1+2+3
//input
//1+1+3+1+3
//output
//1+1+1+3+3
//input
//2
//output
//2
void sort(int *array, int n){
    int i = 0, j = 0, k = 1;
    while(i < n){
        for (int l = i; l < n; ++l) {
            if(array[l] == k){
                int temp = array[j];
                array[j] = array[l];
                array[l] = temp;
                j++;
            }
        }
        i = j;
        k++;
    }
}

int hm_solution(){
    string sum;
    cin >> sum;
    int len = sum.length();
    if(len <= 1){
        cout << sum << endl;
        return 0;
    }
    int array[100] = {0}, j = 0;
    for (int i = 0; i < len; ++i) {
        if(sum[i] != '+'){
            array[j++] = sum[i] - '0';
        }
    }
    sort(array, j);
    int h = 0;
    for (int k = 0; k < len; ++k) {
        if(sum[k] != '+'){
            sum[k] = '0' + array[h++];
        }
    }
    cout << sum << endl;
    return 0;
}
