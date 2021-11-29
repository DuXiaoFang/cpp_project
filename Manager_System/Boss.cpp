#include"Boss.h"

boss::boss(int id,string name,int dId){
    this->Id=id;
    this->Name =name;
    this->DeptId=dId;
}
void boss::showinfo(){
    cout<<this->Id
        <<"\t"<<this->Name
        <<"\t"<<this->DeptId;

}
string boss::getDeptname(){
    return string("laoban");
}