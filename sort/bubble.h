//
// Created by luozhen on 2018/5/4.
//

#ifndef CODEFORCES_BUBBLE_H
#define CODEFORCES_BUBBLE_H

#endif //CODEFORCES_BUBBLE_H

#define MaxSize 100

class BubbleSort{
public:
    void sort(){
        int y, z;
        int x = y = z = 2;
        int i = (++x, x+y);
        cout << x << y << z << endl;
        cout << i << endl;
        string str = R"(lakldjskdj \sdfsdf)";
        cout << str << MaxSize << "|" << endl;
    }
};


void bubble_test(){
    BubbleSort b = BubbleSort();
    b.sort();
}