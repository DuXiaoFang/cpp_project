#pragma once
#include<iostream>
#include<string>
using namespace std;


class worker{
public:
    virtual void showinfo()=0;//显示个人信息

    virtual string getDeptname()=0;//岗位名称

    int Id;//职工编号
    string Name;
    int DeptId;//部门编号
};