//
// Created by luozhen on 2017/7/24.
//

#ifndef CODEFORCES_SASHA_AND_STICKS_H
#define CODEFORCES_SASHA_AND_STICKS_H

#endif //CODEFORCES_SASHA_AND_STICKS_H

#include <iostream>
using namespace std;
//It's one more school day now. Sasha doesn't like classes and is always bored at them. So, each day he invents some game and plays in it alone or with friends.
//
//Today he invented one simple game to play with Lena, with whom he shares a desk. The rules are simple. Sasha draws n sticks in a row. After that the players take turns crossing out exactly k sticks from left or right in each turn. Sasha moves first, because he is the inventor of the game. If there are less than k sticks on the paper before some turn, the game ends. Sasha wins if he makes strictly more moves than Lena. Sasha wants to know the result of the game before playing, you are to help him.
//
//Input
//        The first line contains two integers n and k (1 ≤ n, k ≤ 1018, k ≤ n) — the number of sticks drawn by Sasha and the number k — the number of sticks to be crossed out on each turn.
//
//Output
//        If Sasha wins, print "YES" (without quotes), otherwise print "NO" (without quotes).
//
//You can print each letter in arbitrary case (upper of lower).
//
//Examples
//        input
//1 1
//output
//        YES
//input
//10 4
//output
//        NO
//Note
//        In the first example Sasha crosses out 1 stick, and then there are no sticks. So Lena can't make a move, and Sasha wins.
//
//In the second example Sasha crosses out 4 sticks, then Lena crosses out 4 sticks, and after that there are only 2 sticks left. Sasha can't make a move. The players make equal number of moves, so Sasha doesn't win.
int main(){
    int n, k;
    cin >> n >> k;
    bool flag = (n / k) % 2 ? true : false;
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}