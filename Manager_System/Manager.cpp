#include"Manager.h"

manager::manager(int id,string name,int dId){
    this->Id=id;
    this->Name =name;
    this->DeptId=dId;
}
void manager::showinfo(){
    cout<<this->Id
        <<"\t"<<this->Name
        <<"\t"<<this->DeptId;

}
string manager::getDeptname(){
    return string("jingli");
}