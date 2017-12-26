//
// Created by luozhen on 2017/12/21.
//

#ifndef CODEFORCES_TEST_WORK_H
#define CODEFORCES_TEST_WORK_H

#endif //CODEFORCES_TEST_WORK_H

int thread_func(int k){
    stringstream ss;
    ss << "thread" << k << ":hello!\n";
    string s;
    ss >> s;
    cout << s << endl;
}


int funcReturnInt(const char* fmt, ...){
    std::cout << "thread start..." << std::endl;
    return 0xabcd;
}

void thread_fuc(int num){
    std::cout << "thread " <<  num << ", start..." << std::endl;
//    std::quick_exit();
}

void thread_read(int *buff) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "read thread:" << *buff << std::endl;
    }
}

void thread_write(int *buff) {
    for (int i = 0; i < 5; ++i) {
        *buff = i;
        std::cout << "write thread:" << *buff << std::endl;
    }
}
void threadRunFunction(){
    std::vector<thread*> thread_vec;
    int buff = 10;
    thread t_r = thread(thread_read, &buff);
    thread t_w = thread(thread_write, &buff);
    t_w.join();
    t_r.join();
//    for(int i=0; i < 5; i++) {
//        thread *t = new thread(thread_fuc, i);
//        thread_vec.push_back(t);
////        t->join();
////        delete t;
//    }
//    for (int j = 0; j < thread_vec.size(); ++j) {
//        thread_vec[j]->join();
//    }
}

struct TreeNode {
    char val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(char val): val(val){};
    TreeNode(): val(NULL){};
};

void print_tree(TreeNode *p) {
    if(p == NULL) {
        return;
    }
    std::cout << "tree:" << p->val << std::endl;
    print_tree(p->lchild);
    print_tree(p->rchild);
}
void createTree(TreeNode *p, std::string pre_order, std::string in_order, int start, int end, std::unordered_map<char, int> in_loc_map) {
    if(start > end) {
        return;
    }
    char tmp_char= pre_order[start];
    p = new TreeNode(tmp_char);
    p->rchild = p->lchild = NULL;
    int loc = in_loc_map[tmp_char];
    if(start < loc) {
        createTree(p->lchild, pre_order, in_order, start + 1, loc - 1, in_loc_map);
    }
    if(loc < end) {
        createTree(p->rchild, pre_order, in_order, loc + 1, end, in_loc_map);
    }
    
}
TreeNode * createTree_pre_in(std::string pre_order, std::string in_order) {
//    std::cout << pre_order[3] << std::endl;
    std::unordered_map<char, int> in_loc_map;
    for (int j = 0; j < in_order.size(); ++j) {
        in_loc_map[in_order[j]] = j;
    }
    TreeNode * root;
    TreeNode * p = root;
    std::cout << "sizeof TreeNode:" << sizeof(root) << ", val:" << root->val << std::endl;
    if(pre_order.size()) {
        createTree(p, pre_order, in_order, 0, pre_order.size() - 1, in_loc_map);
        print_tree(root);
    }
}

TreeNode * createTree_in_post(std::string in_order, std::string post_order) {

}

void in_order(TreeNode * tree) {
    TreeNode * stack[100];
    if(!tree) {
        return;
    }
    TreeNode * p = tree;
    int top = 0;
    stack[top++] = p;
    while(p != NULL || top > 0) {
        while (p) {
            std::cout << p->val << std::endl;
            p = p->lchild;
        }
        if(top >= 0) {
            p = stack[top--]->rchild;
        }
    }
}

class Creator_f {
    private:
    int val;
    public:
    Creator_f(){}
    Creator_f(int val):val(val){
        std::cout << "father create val:" << val << std::endl;
    }
    ~Creator_f(){
        std::cout << "father delete val:" << val << std::endl;
//            delete val;
    }
    static void set_thread_num(int t_num) {
        thread_num = t_num;
        std::cout << "set thread num:" << thread_num << std::endl;
    }
    
    private:
    static int thread_num;
};
int Creator_f::thread_num = 0;
class Creator_c : public Creator_f {
    private:
    int c_val;
    public:
    Creator_c(int val):c_val(val) {
        std::cout << "child create val:" << c_val << std::endl;
    }
    Creator_c(){}
    ~Creator_c(){
        std::cout << "child delete val:" << c_val << std::endl;
    }
};

class Base{
    public:
    virtual void func() {
        std::cout << "base func" << std::endl;
    }
};

class Derive : public Base {
    public:
    void func(float f) {
        std::cout << "device func: float " << f << std::endl;
    }
    
    void func(int num) {
//            func();
        std::cout << "device func: num " << num << std::endl;
    }
};

class NoneClass{
    private:
    int __num;
};

void test_work() {
    NoneClass none_cls = NoneClass();
    NoneClass none_cls_1;
    Base b = Base();
    Base b_1 = Derive();
    Derive d = Derive();
    b.func();
    b_1.func();
//    b_1.func(3);
//    d.func();
    d.func(2.3f);
    d.func(1);


//    cout << "Hello, World!" << std::endl;

//    block_main();
//    thread thds[5];
//    for (int i = 0; i < 5; ++i) {
//        thds[i] = thread(thread_func, i);
//    }
//    cout << "Done spawning threads! Now wait for them to join\n------\n";
//    for (auto& t: thds) {
//        t.join();
//    }
//    cout << "All threads joined.\n";
//    test_struct();
//    std::ostringstream oss;
//    oss.str("");
//    oss << "pb_push_keyword_gids_v1 " << 2400945;
//    std::istringstream iss(oss.str());
//    int32_t kid;
//    string dump;
//    iss >> dump >> kid;
//    std::cout << kid << std::endl;
//    std::cout << dump << std::endl;
//
    unordered_map<char, std::vector<int>> mymap;
    mymap['a'].emplace_back(1);
    mymap['a'].emplace_back(2);
    mymap['b'].emplace_back(3);
//    mymap['b'].emplace_back(4);
    mymap['c'].emplace_back(5);
    mymap['c'].emplace_back(6);
    mymap['d'].emplace_back(1);
    mymap['d'].emplace_back(2);
    mymap['d'].emplace_back(3);
    
    mymap.insert(std::pair<char, std::vector<int>>('e', {10, 11}));
//    for(auto &iter : mymap) {
//        std::cout << iter.first << std::endl;
//    }
    
    
    int count = 0;
    unordered_map<char, int> cursor;
    int dest_num = 13;
    std::vector<int> res;
    std::set<int> hit_num;
    int pre = 0;
    int count_fid = 0;
    while(count < dest_num && count_fid < mymap.size()) {
        for(auto iter : mymap){
            std::cout << "iter:" << iter.first << std::endl;
            auto find_iter = cursor.find(iter.first);
            if(find_iter == cursor.end()){
                cursor[iter.first] = 0;
            }
            else {
                cursor[iter.first] += 1;
            }
            int cur = cursor[iter.first];
            if(cur < iter.second.size() && hit_num.find(iter.second[cur]) == hit_num.end()) {
                int num_tmp = iter.second[cur];
                std::cout << "value:" << iter.second[cur] << ", cursor:" << cursor[iter.first]
                          << std::endl;
                res.emplace_back(iter.second[cur]);
                count += 1;
                if (count >= dest_num) {
                    break;
                }
                hit_num.insert(num_tmp);
            }
            else {
                count_fid += 1;
            }
        }
        typedef int num_type;
        auto comp = [](num_type &a, num_type &b) -> bool {return a > b;};
        std::cout << "start ele:" << *(res.begin() + pre) << std::endl;
        std::sort(res.begin() + pre, res.end(), comp);
        pre = res.size();
    }
//    std::unordered_map<char, std::vector<int>> copy;
//    copy['a'] = {1, 2, 3, 4};
//    copy = mymap;
//    if(copy == mymap) {
//        std::cout << "same!!!" << endl;
//    }
//    for(auto iter: copy) {
//        std::cout << iter.first << "\nelement:" << std::endl;
//        for(auto subiter: iter.second) {
//            std::cout << subiter << std::endl;
//        }
//        std::cout << std::endl;
//    }
    for(auto iter : res) {
        std::cout << iter << std::endl;
    }
//    mymap['a']=std::make_pair<int, int>(2,2);
//    mymap['b']=std::make_pair<int, int>(1,0);
//    mymap['c']=mymap['b'];

//    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//    const auto iter = mymap.find('a');
//    if(iter != mymap.end()){
//        iter->second.second += 1;
//    }
//
//    std::cout << "mymap['a'] is " << mymap['a'].first << " " << mymap['a'].second << '\n';
//    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
//    std::cout << mymap.find(2)->first << '\n';


//
//    struct RecallRsp {
//        std::vector<int> groups;
//        //TODO
//    };
//
//
//    for (const auto& g: groups) {
//        std::cout << "group" << std::endl;
//    }
    std::cout << std::endl;
    unordered_map<int, float> key_map;
    key_map[1] = 1.0;
    key_map[2] = 2.0;
    key_map[3] = 3.0;
    key_map[4] = 4.0;
    key_map[5] = 5.0;
    key_map[6] = 6.0;
    key_map[7] = 7.0;
    key_map[7] += 1.0;
    
    for(auto iter: key_map) {
        std::cout << iter.first << ", " << iter.second << std::endl;
    }
    
    
    int batch_size = 3;
    int cur_index = 0;
    std::vector<int> numbers;
    for(auto iter: key_map) {
        std::cout << "迭代对象:" << iter.first << std::endl;
        if(cur_index % batch_size) {
            numbers.push_back(iter.first);
        }
        else {
            std::cout << "一批元素:" << std::endl;
            for(auto la: numbers) {
                std::cout << la << std::endl;
            }
            numbers.resize(0);
            numbers.push_back(iter.first);
        }
        cur_index += 1;

//        std::cout << "迭代对象:" << iter.first << std::endl;
//        if(cur_index < batch_size) {
//            numbers.push_back(iter.first);
//            cur_index += 1;
//
//        }
//        else {
//            std::cout << "一批元素:" << std::endl;
//            for(auto la: numbers) {
//                std::cout << la << std::endl;
//            }
//            numbers.clear();
//            numbers.push_back(iter.first);
//            cur_index = 1;
//        }
    }
    if(!numbers.empty()){
        std::cout << "一批元素:" << std::endl;
        for(auto la: numbers) {
            std::cout << la << std::endl;
        }
    }
    
    
    std::vector<std::string> keys;
    std::string pre_key = "get_key_";
    std::vector<int> gids = {1, 2, 3, 4};
    std::ostringstream os;
    for(auto iter : gids) {
        
        os.str("");
        os << pre_key << iter;
        keys.push_back(os.str());
    }
    for(auto key_iter: keys) {
        std::cout << "key:" << key_iter << std::endl;
    }
    
    std::pair<int, float> p = std::pair<int, float>(1, 1.34);
    std::cout << "pair first:" << p.first << ", second:" << p.second << std::endl;
    
    std::unordered_map<int, float > gid_score_map;
    gid_score_map[1] = 1.23;
    gid_score_map[1] = 2.56;
    gid_score_map.emplace(3, 5.5);
    gid_score_map.emplace(3, 4.1);
//    gid_score_map.emplace(3, 4.1);
    std::vector<int> lala;
    lala.emplace_back(3);
    for(auto iter: gid_score_map){
        std::cout << iter.first << "," << iter.second << std::endl;
    }
//    std::cout << (lala[0] == gid_score_map.find(3)->first ? 1: 0 ) << std::endl;
//    std::cout << gid_score_map[3] << std::endl;
//    std::vector<int> ls = {3, 2, 1};
//    auto comp = [&key_map](const int &a, const int &b) -> bool {return key_map[a] < key_map[b];};
//    sort(ls.begin(), ls.end(), comp);
//    for(auto iter : ls) {
//        std::cout << iter << std::endl;
//    }
    std::ostringstream oss;
    oss << "lala 1";
    std::istringstream iss(oss.str());
    int i;
    std::string dump;
    iss >> dump >> i;
    std::cout << i << std::endl;
    
    std::cout << "math pow:" << pow(2, 2) << std::endl;
    
    std::set<int> myset = {1, 2, 3};
    myset.insert(23);
    myset.insert(23);
    myset.insert(24);
    myset.insert(25);
    for(auto iter: myset) {
        std::cout << "myset ele:" << iter << std::endl;
    }
    
    int type = 0;
    if(!type){
        std::cout << "5" << std::endl;
    }
    else{
        std::cout << "非零" << std::endl;
    }
    
    std::string pre_order = "abdefgc";
    std::string in_order = "debgfac";
    std::string post_order = "edgfbca";

//    std::cout << pre_order[3] << std::endl;
//    std::unordered_map<char, int> in_loc_map;
//    for (int j = 0; j < in_order.size(); ++j) {
//        in_loc_map[in_order[j]] = j;
//    }
    //createTree_pre_in(pre_order, in_order);


//    std::cout << "*********** thread test ************" << std::endl;
//    threadRunFunction();
    
    Creator_f::set_thread_num(14);
//    std::cout << "static thread_num:" << Creator_f::thread_num << std::endl;
    Creator_f crt = Creator_f(15);
    Creator_f * crt_p = new Creator_f(23);
    std::cout << "main func:" << std::endl;
    crt.set_thread_num(23);
//    std::cout << "crt thread_num:" << crt.thread_num << std::endl;
//    std::cout << "crt pointer thread_num:" << crt_p -> thread_num << std::endl;
    
    
    Creator_c c_c = Creator_c(99);
//    std::cout << "child static thread_num:" << Creator_c::thread_num << std::endl;
    
    float a = 2.0;
    std::cout << "a:" << a << std::endl;
    int b_int = a;
    std::cout << "b:" << b_int << std::endl;
    std::cout << "\n\n" << std::endl;
    
    std::default_random_engine seed(time(NULL));
    std::uniform_int_distribution<float> random(1.0, 3.0);
    for (int j = 0; j < 10; ++j) {
        float res = random(seed);
        std::cout << "float res:" << res << ",floor:" << std::floor(res) << ",ceil:" << std::ceil(res) << std::endl;
        int floor_val = std::floor(res * 10);
        int ceil_val = std::ceil(res * 10);
        std::cout << "floor:" << floor_val % 3 + 1 << std::endl;
        std::cout << "ceil:" << ceil_val % 3 + 1 << std::endl;
        std::cout << "int:" << int(res) << std::endl;
    }
    std::cout << "\n\n" << std::endl;
    
    std::pair<int, int> my_pair = {2, 3};
    std::cout << "first:" << my_pair.first << ", second:" << my_pair.second << std::endl;
    
    std::string str = "12";
    std::vector<std::string> toks;
    boost::algorithm::split(toks, str, boost::algorithm::is_any_of(","));
    for (auto iter : toks) {
        std::cout << "boost split:" << iter << std::endl;
    }
}