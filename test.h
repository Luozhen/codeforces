//
// Created by luozhen on 2017/8/17.
//

#ifndef CODEFORCES_TEST_H
#define CODEFORCES_TEST_H

#endif //CODEFORCES_TEST_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
using namespace std;

int test_main(){

    string str = "lalal" + to_string(1) + "erere";
    time_t t = time(NULL);
    time_t ts = time(NULL);
    time_t t2 = ts-(ts+28800)%86400;


    time_t t1 = t + 9;
    cout << (t - t1) << " " << (t - t1) / 10 << endl;
    cout << "time:" << t << endl;

    struct tm* current_time = localtime(&t2);
    printf("current year is %d;current month is %d;current date of month is %d\r\n",
           1900 + current_time->tm_year,
           1 + current_time->tm_mon/*此month的范围为0-11*/,
           current_time->tm_mday);

    printf("current day of year is %d;current day in week is %d\r\n",
           current_time->tm_yday,/*当前日期是今年的第多少天[0,365] */
           current_time->tm_wday/*days since Sunday - [0,6] */);

    printf("time part %d:%d:%d \r\n",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);

    printf("\t本地时间：%d-%d-%d %d:%d:%d\r\n",
           current_time->tm_year + 1900,
           current_time->tm_mon + 1,
           current_time->tm_mday,
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);

    /*格林威治时间*/
    struct tm* current_gmtime = gmtime(&ts);
    cout << time((time_t *)current_gmtime) << endl;

    printf("格林威治时间：%d-%d-%d %d:%d:%d\r\n",
           current_gmtime->tm_year + 1900,
           current_gmtime->tm_mon + 1,
           current_gmtime->tm_mday,
           current_gmtime->tm_hour,
           current_gmtime->tm_min,
           current_gmtime->tm_sec);


    //system("pause");
    return 0;
}