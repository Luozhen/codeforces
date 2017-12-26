//
// Created by luozhen on 2017/7/24.
//

#ifndef CODEFORCES_M_N_ARRAY_H
#define CODEFORCES_M_N_ARRAY_H

#endif //CODEFORCES_M_N_ARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int max_len_mn = 100;
int MN_solution(){
    int n, m, array[max_len_mn] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

}

// --------------------------全组合--------------------------


// --------------------------全排列--------------------------
// 全排列 edition 1
void pailie_recur(set<string>& res, string array, int start, int end){
    if((end - start) == 1){
        res.insert(array);
        swap(array[start], array[end]);
        res.insert(array);
        return ;
    }
    else{
        for (int i = end ; i >= 0; --i) {
            swap(array[i], array[end]);
            pailie_recur(res, array, start, end - 1);
            //swap(array[i], array[end]);
        }
    }
}

int luozhen_main(){
    set<string> res;
    string array = "1234";
    int len = array.length();
    if(len <= 1){
        res.insert(array);
        return 0;
    }
    pailie_recur(res, array, 0, len - 1);
    set<string>::iterator i;
    for (i = res.begin(); i != res.end(); ++i) {
        cout << *i << endl;
    }
}

// 别人家的全排列
//递归全排列，start 为全排列开始的下标， length 为str数组的长度
//交换两个字符
void Swap(char *a ,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void AllRange(char* str,int start,int length)
{
    if(start == length-1)
    {
        printf("%s\n",str);
    }
    else
    {
        for(int i=start;i<=length-1;i++)
        {	//从下标为start的数开始，分别与它后面的数字交换
            Swap(&str[start],&str[i]);
            AllRange(str,start+1,length);
            Swap(&str[start],&str[i]);
        }
    }
}
void Permutation(char* str)
{
    if(str == NULL)
        return;
    AllRange(str,0,strlen(str));
}
void bierenjia_main()
{
    char str[] = "1234";
    Permutation(str);
}

// ******************************组合***************************************
// luozhen 组合
int comp(char a, char b){
    return a > b;
}
void luozhen_comb(vector<string> & res, int choose, int from){
    string wk = string(choose, '1') + string(from - choose, '0');
    res.push_back(wk);
    size_t num = string::npos;
    while((num = wk.find('10')) != string::npos){
        wk[num] ^= wk[num + 1];
        wk[num + 1] ^= wk[num];
        wk[num] ^= wk[num + 1];
        sort(wk.begin(), wk.begin() + num, comp);
        res.push_back(wk);
    }
}


// 别人家的组合

bool compare (const char& lhs, const char& rhs) {
    return lhs > rhs;
}

vector<string>& combination
        (vector<string>& res, const size_t& choose, const size_t& from) {
    string wk = string (choose, '1') + string (from - choose, '0');
    res.push_back (wk);
    size_t found = string::npos;
    while ((found = wk.find("10")) != string::npos) {
        // 1. swap found
        wk[found] ^= wk[found + 1];
        wk[found + 1] ^= wk[found];
        wk[found] ^= wk[found + 1];
        // 2. sort before
        sort (wk.begin(), wk.begin() + found, compare);
        res.push_back (wk);
    }
    return res;
}

int MN() {
    vector<string> res;
    const size_t choose = 3, from = 5;
    combination (res, choose, from);
    for (size_t i = 0; i != res.size(); ++i) {
        cout << res[i] << '\t';
        for (size_t j = 0; j != from; ++j) {
            if (res[i][j] == '1') {
                cout << j + 1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}