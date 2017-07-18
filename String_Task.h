//
// Created by luozhen on 2017/7/18.
//

#ifndef CODEFORCES_STRING_TASK_H
#define CODEFORCES_STRING_TASK_H

#endif //CODEFORCES_STRING_TASK_H
#include <iostream>
#include <string>
#include <set>
#include <typeinfo>
using namespace std;
//Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program
// was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:
//
//deletes all the vowels,
//        inserts a character "." before each consonant,
//replaces all uppercase consonants with corresponding lowercase ones.
//Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one
// string, it should return the output as a single string, resulting after the program's processing the initial string.
//
//Help Petya cope with this easy task.
//
//Input
//        The first line represents input string of Petya's program. This string only consists of uppercase and
// lowercase Latin letters and its length is from 1 to 100, inclusive.
//
//Output
//        Print the resulting string. It is guaranteed that this string is not empty.
//
//Examples
//        input
//tour
//        output
//.t.r
//        input
//Codeforces
//        output
//.c.d.f.r.c.s
//        input
//aBAcAba
//        output
//.b.c.b
string st_solution(){
    string str, set = "aeiouyAEIOUY", res;
    cin >> str;
    for(int i = 0, j = 0; i < str.length(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y') continue;
        else{
            res.insert(j++, 1, '.');
            res.insert(j++, 1, str[i] < 'a' ? str[i] + 32 : str[i]);
        }
    }
    return res;

//    char s;
//    while(cin >> s){
//        if(strchr("aeiouyAEIOUY", s)) continue;
//        cout << '.' << (char)tolower(s);
//    }
//    return 0;
}