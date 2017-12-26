//
// Created by luozhen on 2017/8/25.
//

#ifndef CODEFORCES_DP_MONEY_H
#define CODEFORCES_DP_MONEY_H

#endif //CODEFORCES_DP_MONEY_H
#include <iostream>
using namespace std;
const int max_count = 100;

int dp_money(int array[], int n, int m){
    sort(array, array[n - 1]);
}

int dp_money_main(){
    int array[max_count] = {0};
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << dp_money(array, n, m) << endl;
    return 0;
}