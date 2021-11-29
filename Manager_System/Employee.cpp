#include"Employee.h"

employee::employee(int id,string name,int dId){
    this->Id=id;
    this->Name =name;
    this->DeptId=dId;
}
void employee::showinfo(){
    cout<<this->Id
        <<"\t"<<this->Name
        <<"\t"<<this->DeptId;

}
string employee::getDeptname(){
    return string("yuanyong");
}