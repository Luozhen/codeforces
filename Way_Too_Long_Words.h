//
// Created by luozhen on 2017/7/18.
//

#ifndef CODEFORCES_WAY_TOO_LONG_WORDS_H
#define CODEFORCES_WAY_TOO_LONG_WORDS_H

#endif //CODEFORCES_WAY_TOO_LONG_WORDS_H

#include <iostream>
using namespace std;
//Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one
// text is quite tiresome.
//
//Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be
// replaced with a special abbreviation.
//
//This abbreviation is made like this: we write down the first and the last letter of a word and between them we write
// the number of letters between the first and the last letters. That number is in decimal system and doesn't contain
// any leading zeroes.
//
//Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".
//
//You are suggested to automatize the process of changing the words with abbreviations. At that all too long words
// should be replaced by the abbreviation and the words that are not too long should not undergo any changes.
//
//Input
//        The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word. All the
// words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.
//
//Output
//        Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.
//
//Examples
//input
//          4
//          word
//          localization
//          internationalization
//          pneumonoultramicroscopicsilicovolcanoconiosis
//output
//          word
//          l10n
//          i18n
//          p43s
void wtlw_solution(){
    int n, i = 0;
    cin >> n;
    string s;
    while(cin >> s){
        int len = s.length();
        if(len <= 10) cout << s << endl;
        else{
            cout << s[0] << len - 2 << s[len - 1] << endl;
        }
    }
}