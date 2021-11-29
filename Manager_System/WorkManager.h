#pragma once//防止头文件重复包含

#include<string>
#include<iostream>
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
using namespace std;

#define FILENAME "data_person.txt"

class workmanager{
public:
    workmanager();
    void show_menu();
    void exit_menu();

    void add_person();
    void save();

    int get_pernum();
    void init_person();

    void show_person();

    int isExist(int id);
    void del_person();

    void mod_person();

    void find_person();
    
    void sort_person();

    void clean_file();
    int m_num;
    worker** m_array;
    bool m_fileempty;
    ~workmanager();
};