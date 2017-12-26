//
// Created by luozhen on 2017/9/20.
//

#ifndef CODEFORCES_TEST_IO_H
#define CODEFORCES_TEST_IO_H

#endif //CODEFORCES_TEST_IO_H

#include <iostream>
#include <ostream>
using namespace std;

class Complex{
public:
    Complex( ){real=0;imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    Complex operator + (Complex &c2);  //运算符“+”重载为成员函数
    friend ostream& operator <<(Complex&, ostream&);  //运算符“<<”重载为友元函数
private:
    double real;
    double imag;
};

struct Student{
    int id;
    float score;
    
    friend ostream& operator <<(ostream&, Student&);
};

ostream& operator<<(Complex &a, ostream &output) {
    (output << a.real) << ", "<< a.imag;
    return output;
}

ostream& operator <<(ostream &output, Student &s){
    output << s.id << ", " << s.score;
    return output;
}

int test_io(){
    Complex a = Complex(1, 2);
    Complex b = Complex(3, 4);
    b << (a << std::cout);
//    std:cout << a;
}

int test_struct(){
    Student std_1 = {1};
    Student std_2 = {1, 92.5};
    std::cout << std_1 << endl;
    std::cout << std_2 << endl;
    return 1;
}