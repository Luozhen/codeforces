//
// Created by luozhen on 2017/8/6.
//

#ifndef CODEFORCES_XIAOXIN_H
#define CODEFORCES_XIAOXIN_H

#endif //CODEFORCES_XIAOXIN_H
//小明春节期间的相亲不幸以失败告终，体贴的主管安排了和另一个部门的联谊。根据每个人的“相亲意愿指数”，小明的部门派出m位男同学，
// 另一个部门派出n位女同学。原计划将每对男女组成一个小组进行游戏，但由于各部门情况不一样，不能做到m和n完全相等，所以允许出现1对多的分组
// （1男多女或1女多男），甚至允许某个（可以不止1个）同学参与到最多2个不同的小组。同时分组也需要参考相亲意愿指数，以男同学为例，
// 若男同学A比男同学B指数更高，则与A成组的任意一个女同学的指数都不能低于与B成组的任意一个女同学，反之亦然。此外，根据我们的大数据分析，
// 可以计算出任意一对男女同学的匹配度。请你根据这些信息，对参加活动的男女同学进行分组，当然不能有任何一个人落单哦。要求在满足规则的前提下，
// 最大化所有分组匹配度的和。（若1男和1女成组，该分组匹配度即该男女同学的匹配度；若1男和2女成组，则该分组的匹配度为该男同学和2位女同学匹配度的和）
// 顶点、边的编号均从 0 开始
// 邻接表储存
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int __maxNodes = 100;
struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};

vector<int> G[__maxNodes]; /* G[i] 存储顶点 i 出发的边的编号 */
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_nodes;
int num_left;
int num_right;
int num_edges;
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];

bool dfs(int u)
{
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { // 对 u 的每个邻接点
        int v = edges[*i].to;
        if (!check[v]) {     // 要求不在交替路中
            check[v] = true; // 放入交替路
            if (matching[v] == -1 || dfs(matching[v])) {
                // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // 不存在增广路，返回失败
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}
queue<int> Q;
int prev[__maxNodes];
int Hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    memset(check, -1, sizeof(check));
    for (int i=0; i<num_left; ++i) {
        if (matching[i] == -1) {
            while (!Q.empty()) Q.pop();
            Q.push(i);
            prev[i] = -1; // 设 i 为路径起点
            bool flag = false; // 尚未找到增广路
            while (!Q.empty() && !flag) {
                int u = Q.front();
                for (iterator_t ix = G[u].begin(); ix != G[u].end() && !flag; ++ix) {
                    int v = edges[*ix].to;
                    if (check[v] != i) {
                        check[v] = i;
                        Q.push(matching[v]);
                        if (matching[v] >= 0) { // 此点为匹配点
                            prev[matching[v]] = u;
                        } else { // 找到未匹配点，交替路变为增广路
                            flag = true;
                            int d=u, e=v;
                            while (d != -1) {
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if (matching[i] != -1) ++ans;
        }
    }
    return ans;
}