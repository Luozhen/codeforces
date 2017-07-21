//
// Created by luozhen on 2017/7/19.
//

#ifndef CODEFORCES_PETYA_AND_STRINGS_H
#define CODEFORCES_PETYA_AND_STRINGS_H

#endif //CODEFORCES_PETYA_AND_STRINGS_H
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of
// uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters'
// case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter.
// Help Petya perform the comparison.
//
//Input
//        Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It
// is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.
//
//Output
//        If the first string is less than the second one, print "-1". If the second string is less than the first one,
// print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the
// strings are compared.
//
//Examples
//input
//        aaaa
//        aaaA
//output
//0
//input
//        abs
//        Abz
//output
//-1
//input
//        abcdefg
//        AbCdEfF
//output
//1
//Note
//        If you want more formal information about the lexicographical order (also known as the "dictionary order" or
// "alphabetical order"), you can visit the following site:
//
//http://en.wikipedia.org/wiki/Lexicographical_order

int pas_solution(){
    string str1, str2;
    cin >> str1 >> str2;
    int len = str1.length();
    for (int i = 0; i < len; ++i) {
        char temp1 = str1[i] >= 'a' ? str1[i] : str1[i] + 32, temp2 = str2[i] >= 'a' ? str2[i] : str2[i] + 32;
        if(temp1 == temp2)
            continue;
        else if(temp1 < temp2){
            cout << -1 << endl;
            return 0;
        }
        else{
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
