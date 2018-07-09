//
// Created by luozhen on 2018/5/4.
//

#ifndef CODEFORCES_BUBBLE_H
#define CODEFORCES_BUBBLE_H

#endif //CODEFORCES_BUBBLE_H

#include <vector>
#include <string>
#define MaxSize 100

void showVector(vector<int> arr) {
    for (int j = 0; j < arr.size(); ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

class BubbleSort{
public:
//    virtual int test() = 0;
    virtual vector<int> sort(vector<int> arr) {
        std::cout << "parent: bubbler sort" << std::endl;
        int len = arr.size();
        for (int j = 0; j < len; ++j) {
            for (int k = 0; k < len - j - 1; ++k) {
                if(arr[k] > arr[k + 1]){
                    int tmp = arr[k];
                    arr[k] = arr[k + 1];
                    arr[k + 1] = tmp;
                }
            }
        }
        return arr;
    }
    
    vector<int> sort_1(vector<int> arr) {
        std::cout << "parent: bubbler sort_1" << std::endl;
        int n = arr.size();
        for (bool is_sorted = false; is_sorted = !is_sorted; n--) {
            for (int i = 0; i < n - 1; ++i) {
                if(arr[i] > arr[i + 1]) {
                    int tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
//                    swap(arr[i], arr[j]);
                    is_sorted = false;
                }
            }
        }
        return arr;
    }
    
    void max2(vector<int> arr, int lo, int hi, int &sub_max, int &max) {
        sub_max = max = lo;
        for (int j = 0; j < arr.size(); ++j) {
            if(arr[j] > arr[sub_max]) {
                sub_max = j;
                if(arr[max] < arr[sub_max]) {
                    int tmp = sub_max;
                    sub_max = max;
                    max = tmp;
                }
//                if(arr[j] > arr[max]) {
//                    sub_max = max;
//                    max = j;
//                }
//                else {
//                    sub_max = j;
//                }
            }
        }
    }
    
    long long fabnaci(int n){
        if (n == 0 || n == 1) {
            return n;
        }
        long long i = 0, j = 1;
        for (int k = 2; k <= n; ++k) {
            j = i + j;
            i = j - i;
        }
        return j;
    }
    
    void lcs(string a, string b) {
        int a_len = a.size(), b_len = b.size();
        int tb[MaxSize][MaxSize];
        for (int i = 0; i < a_len; i++) {
            for(int j = 0 ; j < b_len; j++) {
                std::cout << "i(" << i << "), j(" << j << "), val is " << tb[i][j] << std::endl;
            }
        }
    }
};

class BubbleSort_1 : public BubbleSort{
    public:
    vector<int> sort(vector<int> arr){
        std::cout << "child: bubbler sort" << std::endl;
        return vector<int>();
    }
};


void bubble_test(){
    vector<int> arr = {3, 1, 5, 2, 4, 6};
    BubbleSort* b = new BubbleSort();
    vector<int> res = b->sort_1(arr);
    showVector(res);
    
    int sub_max, max;
    b->max2(arr, 0, arr.size(), sub_max, max);
    std::cout << "sub_max idx:" << sub_max << ", val:" << arr[sub_max]
              << ", max idx:" << max << ", val:" << arr[max] << std::endl;
    
    int n = 0;
    std::cin >> n;
    std::cout << "fabnaci: " << n << ", val is:" << b->fabnaci(n) << std::endl;
    
    
    string a_str("1234567"), b_str("23456789");
    b->lcs(a_str, b_str);
    
//    std::cout << "\n\n lalalla" << std::endl;
//    vector<int> arr_child = {3, 1, 5, 2, 4, 6};
//    BubbleSort_1* b1 = new BubbleSort_1();
//    res = b1->sort(arr_child);
////    showVector(res);
//
//
//    BubbleSort* b_2 = new BubbleSort_1();
//    b_2->test();
}