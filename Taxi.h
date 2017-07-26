//
// Created by luozhen on 2017/7/21.
//

#ifndef CODEFORCES_TAXI_H
#define CODEFORCES_TAXI_H

#endif //CODEFORCES_TAXI_H
#include <iostream>
#include <algorithm>
using namespace std;
const int max_len_taxi = 100;
//After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday.
// We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together.
// They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the
// children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?
//
//Input
//        The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line
// contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the
// number of children in the i-th group.
//
//Output
//        Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.
//
//Examples
//        input
//5
//1 2 4 3 3
//output
//4
//input
//8
//2 3 4 4 2 1 3 1
//output
//5
//Note
//        In the first test we can sort the children into four cars like this:
//
//the third group (consisting of four children),
//the fourth group (consisting of three children),
//the fifth group (consisting of three children),
//the first and the second group (consisting of one and two children, correspondingly).
//There are other ways to sort the groups into four cars.

int taxi_solution(){
    int n, capacity = 4, count = 0;
    cin >> n;
    int sum[max_len_taxi] = {n};
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sum[temp]++;
    }
    for (int j = capacity; j > 1; --j) {
        int add;
        if(sum[j] && sum[capacity - j]){
            if((j == 2) && sum[j]){
                add = sum[j] / 2;
                sum[j] -= add * 2;
                //cout << "two two:" << add << endl;
            }
            else {
                add = min(sum[j], sum[capacity - j]);
                sum[j] -= add;
                sum[capacity - j] -= add;
            }
            count += add;
        }
        if(sum[j] && (sum[1] >= capacity - j)){
            int c1 = sum[j], c2 = sum[1] / (capacity - j);
            add = min(c1, c2);
            //cout << "two and one:" << add << endl;
            sum[j] -= add;
            sum[1] -= add * j;
            count += add;
        }
    }
    for (int k = capacity - 1; k > 0; --k) {
        if((k == 3) && sum[k]){
            count += sum[k];
        }
        else if(((k == 2) && sum[k]) || (k == 2 ) && sum[2] && sum[1]){
            //cout << "outer:" << sum[k] << endl;
            count += sum[k];
            sum[k] = 0;
            if(sum[1]) sum[1] = 0;
        }
        else if((k == 1) && sum[k])
            count += (sum[1] % capacity) ? (sum[1] / capacity + 1) : (sum[1] / 4);
    }
// A[1]=std::max(A[1]-A[3],0);std::cout<<A[3]+A[4]+(A[1]+2*A[2]+3)/4;}
    cout << count << endl;
    return 0;
}