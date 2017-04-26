//
//  main.cpp
//  运算符重载
//
//  Created by 董依萌 on 2017/3/20.
//  Copyright © 2017年 董依萌. All rights reserved.
//

#include <iostream>
using namespace std;
class time1{
    int h_;
    int m_;
public:
    time1();
    time1(int h, int m);      //const 不能改变t的值
    time1 operator+(const time1 & t)const;
    time1 operator*(int n)const;
    // 不是成员函数 不能用 const 修饰词
    // 函数的第一个参数 不是类的对象 就要使用友元函数
    // c=a+b == c=a.operator(b) 隐式调用a,显式调用b
    // c=a+b 左侧的操作数是调用对象
    // 所以 d=2*c 就要用友元函数解决
    friend time1 operator*(int n,const time1 & t);
    friend ostream & operator <<(ostream & os,const time1 & t);
    void show();
};
time1::time1(){
    h_=0;
    m_=0;
}
time1::time1(int h,int m){
    h_=h;
    m_=m;
}
time1 time1::operator+(const time1 & t)const{
    time1 sum;
    sum.m_=m_+t.m_;
    sum.h_=h_+t.h_+sum.m_/60;
    sum.m_%=60;
    return sum;
}
time1 time1::operator*(int n)const {
    time1 t1;
    int totle1=h_*n*60+m_*n;
    t1.h_=totle1/60;
    t1.m_=totle1%60;
    return t1;
}
time1 operator*(int n,const time1 & t){
    return t*n;
}
ostream & operator<<(ostream & os,const time1 & t){
    os<<t.h_<<" <hours "<<t.m_<<" <minutes"<<endl;
    return os;
}
void time1::show(){
    cout<<h_<<" hours "<<m_<<" minutes"<<endl;
}


int main() {
    time1 a(1,44);
    time1 b(5,56);
    time1 ab=a+b;      //在a对象里 执行+ b
    ab.show();
    time1 c(2,40);
    c.show();
    int n=2;
    time1 d=c*n;   // d=n*c和前面不一样
    d.show();
    cout<<a<<b<<c<<d;       // 输出<< 的重载
    
    return 0;
}
