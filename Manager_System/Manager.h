#include"Worker.h"

class manager:public worker{
public:
    manager(int id,string name,int dId);
    void showinfo();
    string getDeptname();
};