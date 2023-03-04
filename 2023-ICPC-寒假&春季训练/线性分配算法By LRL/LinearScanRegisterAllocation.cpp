/*
Author: 2021090906016 刘芮利
Date: 23 Feb 15th ~ 16th
这是一个用C++实现的线性分配算法
利用std::multiset作为平衡树，该算法的时间复杂度为O(nlogR), n为活跃区间数量，R为寄存器的数量
该算法相比原始算法有如下改进：
    1. 任意时刻寄存器空出来了都会尝试重新分配，算法尽可能让寄存器得到最充分的利用
    2. 同一个变量可以输入多个活跃区间，以获得更精细的分配策略（原始算法仅仅是找一个最小的活跃区间覆盖所有活跃信息）
    3. 使用STL的容器，将时间复杂度由O(nR)降低为O(nlogR)（尽管大多数情况下寄存器比较少，在实际中可能提升不大）
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct Interval {
    int startpoint, endpoint;
    mutable int reg_id; //临时分配的寄存器id，但不是最终结果
    string variable_name;
    //以endpoint为关键字重载<运算，方便扔进multiset里面
    friend bool operator<(const Interval &t1, const Interval &t2) {
        return t1.endpoint < t2.endpoint;
    }
};

//返回一个vector作为结果，vector里存放每一次寄存器分配可能发生改变后的分配结果，pair的第一维存放变量名，第二维存放分配的时间点
vector<pair<vector<string>, int> >& LinearScanRegisterAllocation(vector<Interval> &interval, int R) {
    using tiii = tuple<int, int, int>;
    vector<tiii> order;
    size_t n = interval.size();
    for(int i = 0; i < n; ++i) {
        auto &[startpoint,  endpoint, reg_id, variable_name] = interval[i];
        order.emplace_back(startpoint, 1, i); //起始端点需要处理
        order.emplace_back(endpoint + 1, 0, i); //结束端点+1也需要处理
    }
    sort(order.begin(), order.end()); //按照端点从小到大排序处理
    auto &ret = *(new vector<pair<vector<string>, int> >);
    //active是存放分配了寄存器的活跃区间集合，inactive是存放因寄存器不够而未分配寄存器的活跃区间集合
    multiset<Interval> active, inactive;
    queue<int> q; //队列里放还可用的寄存器编号
    for(int i = 0; i < R; ++i) q.push(i); //初始所有寄存器可用
    for(size_t p = 0; p < order.size(); ++p) {
        auto &[point, type, i] = order[p];
        auto &[startpoint,  endpoint, reg_id, variable_name] = interval[i];
        if(type == 0) { //type=0表示当前这个活跃区间刚好过期了
            auto it = active.find(interval[i]);
            if(it == active.end()) goto SAVE;
            q.push(it->reg_id); //回收寄存器
            active.erase(it); //把它从已分配集合中删除
            //下面尝试从未分配的集合中找一个endpoint最近的加入
            while(inactive.size() > 0 && inactive.begin()->endpoint <= endpoint) inactive.erase(inactive.begin());
            while(active.size() < R && inactive.size() > 0) {
                it = inactive.begin();
                it->reg_id = q.front(); //分配寄存器，下同理
                q.pop();
                active.insert(*it); //添加到已分配集合中
                inactive.erase(it); //从未分配集合中删除
            }
        } else {
            if(active.size() == R) { //寄存器已经分配完了
                auto it = prev(active.end());
                auto spill = it->endpoint; 
                if(spill > endpoint) { //从已分配集合中删除endpoint最长的
                    q.push(it->reg_id);
                    inactive.insert(*it);
                    active.erase(it);
                    active.insert({startpoint,  endpoint, q.front(), variable_name});
                    q.pop();
                } else {
                    inactive.insert(interval[i]);
                }
            } else { //未分配完直接分配
                active.insert({startpoint,  endpoint, q.front(), variable_name});
                q.pop();
            }
        }
        //在一个时间点处理完所有的操作后，保存结果
        SAVE:
        if(p + 1 == order.size() || get<0>(order[p + 1]) != point) {
            vector<string> state(R);
            for(auto it : active) {
                state[it.reg_id] = it.variable_name;
            }
            ret.emplace_back(move(state), point);
        }
    }
    return ret;
}

int main() {
    // freopen("data.in", "r", stdin);
    //输入n, R，分别代表活跃区间数量，和可分配的寄存器的数量
    int n, R;
    cin >> n >> R;
    vector<Interval> interval(n);
    for(int i = 0; i < n; ++i) //输入每个活跃区间
        cin >> interval[i].variable_name >> interval[i].startpoint >> interval[i].endpoint;
    auto &result = LinearScanRegisterAllocation(interval, R);
    
    //输出结果（把每一个时间点的分配结果都输出了）
    cout << "\t";
    for(int i = 0; i < R; ++i)
        cout << "R" << i + 1 << "\t\n"[i + 1 == R];
    auto last_names = result[0];
    for(auto &names : result) {
        //对于两次分配的时间点间隔的部分，分配方案不变，继承上一次的分配方案
        for(int i = 1; i <= names.second - last_names.second - 1; ++i) {
            cout << last_names.second + i << "\t";
            for(size_t j = 0; j < last_names.first.size(); ++j) {
                cout << last_names.first[j] << "\t\n"[j + 1 == last_names.first.size()];
            }
        }
        cout << names.second << "\t";
        for(size_t j = 0; j < names.first.size(); ++j) {
            cout << names.first[j] << "\t\n"[j + 1 == names.first.size()];
        }
        last_names = names;
    }
    delete &result;
    return 0;
}