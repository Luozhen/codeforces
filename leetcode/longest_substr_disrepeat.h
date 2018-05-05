//
// Created by luozhen on 2018/5/5.
//

#ifndef CODEFORCES_LONGEST_SUBSTR_DISREPEAT_H
#define CODEFORCES_LONGEST_SUBSTR_DISREPEAT_H

#endif //CODEFORCES_LONGEST_SUBSTR_DISREPEAT_H

#include <set>
#include <map>

class Non_Repeat_Substr {
    public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
//        cout << "input string length:" << length << endl;
        set<char> non_repeat_set = set<char>();
        map<char, int> my_map = map<char, int>();
        int start_idx = 0, end_idx = 0;
        int max_sub_len = 0;
        for(int i = 0; i < length; i++) {
            if (non_repeat_set.empty() || non_repeat_set.find(s[i]) == non_repeat_set.end()) {
                non_repeat_set.insert(s[i]);
                my_map.insert(make_pair(s[i], i));
                end_idx = i;
            }
            else if (!non_repeat_set.empty() && non_repeat_set.find(s[i]) != non_repeat_set.end()) {
                start_idx = start_idx >= my_map[s[i]] + 1 ? start_idx : my_map[s[i]] + 1;
                my_map[s[i]] = i;
                end_idx = i;
            }
            int tmp_sub_len = end_idx - start_idx + 1;
            if (tmp_sub_len > max_sub_len) {
                max_sub_len = tmp_sub_len;
            }
        }
        return max_sub_len;
    }
};

void test_nrs(){
    Non_Repeat_Substr nrs = Non_Repeat_Substr();
    int max_sub_len = nrs.lengthOfLongestSubstring("abba");
    cout << "max sub length:" << max_sub_len << endl;
}
