#include"Worker.h"

class boss:public worker{
public:
    boss(int id,string name,int dId);
    void showinfo();
    string getDeptname();
};