//
//  main.cpp
//  c_plus_plus
//
//  Created by whnarthur on 17/4/26.
//  Copyright © 2017年  All rights reserved.
//  用于测试将'const xxx'作为'xxx'的'this'实参时丢弃了类型限定的错误

#include <cctype>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class A
{
public:
    string m_str;
    A(string str){m_str = str;}
    string ToString() {return m_str;}
    string ToString() const  {return m_str;}  //加上此行后就不报错了
    bool operator<(const A &rhs) const {return true;} //为了能使用set
};

void output(const string &str)
{
    cout<<str<<endl;
}

int main()
{
    A a("dfsfsd");
    output(a.ToString());
    set<A> strset;
    strset.insert(a);
    output(strset.begin()->ToString());
    return 0;
}