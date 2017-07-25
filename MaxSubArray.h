//
// Created by luozhen on 2017/7/24.
//

#ifndef CODEFORCES_MAXSUBARRAY_H
#define CODEFORCES_MAXSUBARRAY_H

#endif //CODEFORCES_MAXSUBARRAY_H
#include <iostream>
using namespace std;
const int max_len_msa = 100;
int find_mid_max(int array[], int start, int mid, int end){
    if(start >= end) return array[start] < 0 ? 0 : array[start];
    int left_sum, right_sum, max_left, max_rigth;
    left_sum = right_sum = max_left = max_rigth = 0;
    for (int i = mid; i >= start; --i) {
        left_sum += array[i];
        if(left_sum > max_left) max_left = left_sum;
    }
    for (int j = mid + 1; j <= end; ++j) {
        right_sum += array[j];
        if(right_sum > max_rigth) max_rigth = right_sum;
    }
    return max_left + max_rigth;
}

int st1(int array[], int start, int end){
    if(start >= end)
        return array[start] < 0 ? 0 : array[start];
    int mid = (start + end) / 2;
    int mid_max = find_mid_max(array, start, mid, end);
    int left_max = st1(array, start, mid);
    int right_max = st1(array, mid + 1, end);
    return max(mid_max, max(left_max, right_max));
}

int st2(int array[], int n){
    int max_value = 0, sub_max = 0;
    for (int i = 0; i < n; ++i) {
        sub_max = max(array[i], sub_max + array[i]);
        if(sub_max > max_value) max_value = sub_max;
    }
    return max_value;
}

int Kadane(const int array[], size_t length, unsigned int& left, unsigned int& right)
{
    unsigned int i, cur_left, cur_right;
    int cur_max, max;

    cur_max = max = left = right = cur_left = cur_right = 0;

    for(i = 0; i < length; ++i)
    {
        cur_max += array[i];
        if(cur_max > 0)
        {
            cur_right = i;
            if(max < cur_max)
            {
                max = cur_max;
                left = cur_left;
                right = cur_right;
            }
        }
        else
        {
            cur_max = 0;
            cur_left = cur_right = i + 1;
        }
    }

    return max;
}

int MSA_solution(){
    int n, array[max_len_msa] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << st1(array, 0, n - 1) << endl;
    cout << st2(array, n) << endl;
    unsigned int left = 0, right = 0;
    cout << "max value:" << Kadane(array, n, left, right) << " in (" << left << "," << right << ")";
    return 0;
}