#include"WorkManager.h"

workmanager::workmanager(){

    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<< "文件不存在"<< endl;
        this->m_num=0;
        this->m_array=NULL;     
        this->m_fileempty=true;   
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout<< "文件空"<< endl;
        this->m_num=0;
        this->m_array=NULL;     
        this->m_fileempty=true;   
        ifs.close();
        return;      
    }
    int num =this->get_pernum();
    cout<<"职员"<< num<<"人"<< endl;
    this->m_num = num;
    
    //开辟空间！！！
    this->m_array = new worker*[this->m_num];
    this->init_person();


    //测试代码
    // for(int i=0;this->m_num;i++){
    //     cout<<"职工编号"<<this->m_array[i]->Id
    //         <<"姓名"<<this->m_array[i]->Name
    //         <<"部门"<<this->m_array[i]->DeptId;
    // }
   
}

void workmanager::show_menu(){
    cout<< "职工管理系统"<< endl;
}

void workmanager::exit_menu(){
    cout<< "欢迎再来"<< endl;
    system("pause");
    exit(0);
}

void workmanager::add_person(){
    cout<< ""<< endl;
    int addnum;
    cin>>addnum;
    if(addnum>0){
        int newsize = this->m_num+addnum;
        worker** newspace= new worker*[newsize];
        if(this->m_num!=NULL){
            for(int i =0;i< this->m_num;i++){
                newspace[i]= this->m_array[i];
            }
            for(int i=0;i<addnum;i++){
                int id;
                string name;
                int dId;
                cout<<"添加地"<< i<<"位"<< endl;
                cin>>id>>name>>dId;
                worker * person =NULL;
                switch(dId){
                    case 1:
                        person = new employee(id,name,dId);
                        break;
                    case 2:
                        person = new manager(id,name,dId);
                        break;
                    case 3:
                        person = new boss(id,name,dId);
                        break;
                    default:
                        break;                        
                }
                newspace[this->m_num+i] = person;
            }

            delete[] this->m_array;

            this->m_array = newspace;
            this->m_num = newsize;
            this->m_fileempty = false;

            cout<< "添加成功" << addnum<< endl;
            this->save();
        }
    }
    else{
        cout<< "false"<< endl;
    }
    system("pause");
    system("cls");
}

void workmanager::save(){
    ofstream ofs;

    ofs.open(FILENAME,ios::out);
    
    for(int i=0;i<this->m_num;i++){
        ofs <<this->m_array[i]->Id<<" "
            <<this->m_array[i]->Name<<" "
            <<this->m_array[i]->DeptId<<endl;
    }

    ofs.close();
}

int workmanager::get_pernum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num =0;

    while(ifs>>id && ifs>>name && ifs>>dId){
        num++;
    }
    return num;
}

void workmanager::init_person(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int index;
    while(ifs>>id && ifs>>name && ifs>>dId){
        worker* person =NULL;
        if(dId == 1){
            person = new employee(id,name,dId);
        }
        else if(dId==2){
            person = new manager(id,name,dId);
        }
        else{
            person = new boss(id,name,dId);
        }
        this->m_array[index] = person;
        index ++;
    }
}

void workmanager::show_person(){

    if(this->m_fileempty){
        cout<<"文件不存在"<<endl;
    }
    else{
        for(int i=0;i<this->m_num;i++){
            this->m_array[i]->showinfo();
        }
    }
    system("pause");
    system("cls");
}

int workmanager::isExist(int id){
    int index =-1;

    for(int i=0;i<this->m_num;i++){
        if(this->m_array[i]->Id==id){
            index=i;
            break;
        }
    }
    return index;
}

void workmanager::del_person(){
    if(this->m_fileempty){
        cout<<"文件为空"<< endl;
    }
    else{
        cout<<"输入像删除的编号"<< endl;
        int id;
        cin>>id;
        int index = this->isExist(id);

        if(index!=-1){
            for(int i=index;i<this->m_num-1;i++){
                this->m_array[i]=this->m_array[i+1];
            }
            this->m_num--;
            this->save();
            cout<< "删除成功"<< endl;
        }
        else{
            cout<<"无此成员"<< endl;
        }
    }

    system("pause");
    system("cls");

}


void workmanager::mod_person(){
    if(this->m_fileempty){
        cout<<"文件为空"<< endl;
    }
    else{
        cout<<"输入想更改的编号"<< endl;
        int id;
        cin>>id;
        int index = this->isExist(id);

        if(index!=-1){

            cout<<"更改的内容"<< endl
                <<"1:id"<< endl
                <<"2.name"<< endl
                <<"3.dId"<< endl;
            int indicate;
            cin>>indicate; 
            while(true){       
                switch(indicate){
                    case 1:
                        {   
                            int newid;
                            cout<< "new name"<< endl;
                            cin>>newid;
                            this->m_array[index]->Id = newid;
                        }
                        break;
                    case 2:
                        {   
                            string newname;
                            cout<< "new name"<< endl;
                            cin>>newname;
                            this->m_array[index]->Name = newname;
                        }
                        break;
                    case 3:
                        {
                            int id = this->m_array[index]->Id;
                            string name = this->m_array[index]->Name;
                            delete this->m_array[index];
                            int newdId;
                            cin>>newdId;

                            worker* person = NULL;

                            switch(newdId){
                                case 1:
                                    person = new employee(id,name,newdId);
                                    break;
                                case 2:
                                    person = new manager(id,name,newdId);
                                    break;
                                case 3:
                                    person = new boss(id,name,newdId);
                                    break;
                            }
                            this->m_array[index] = person;
                            this->save();
                        }
                        break;
                    default:
                        break;
                }
                
            }

        }
        else{
            cout<<"此人不存在"<<endl;
        }

    }
    system("pause");
    system("cls");
}

void workmanager::find_person(){
    if(this->m_fileempty){
        cout<< "文件空"<< endl;
    }
    else{
        int select =0;
        cin>>select;
        if(select==1){
            int id =0;
            cout<<"输入职工编号"<< endl;
            cin>>id;

            int index = isExist(id);
            if(index!=-1){
                this->m_array[index]->showinfo();
            }
            else{
                cout<<"没找到"<< endl;
            }
        }
        else if(select==2){
            string name ;
            cout<<"输入职工姓名"<< endl;
            cin>>name;
            bool flag= false;
            for(int i=0;i<this->m_num;i++){
                if(name ==this->m_array[i]->Name){
                    cout<<"chenggong"<< endl;
                    this->m_array[i]->showinfo();
                    flag = true;
                }
            }
            if(flag==false){
                cout<<"没找到"<< endl;
            }
        }
        else{
            cout<<"输入选项错误"<< endl;
        }
    }
    system("pause");
    system("cls");
}

void workmanager::sort_person(){

    cout<<"选择排序方式"<< endl;
    int select =0;
    cin>> select;
    //挖坑  

}

void workmanager::clean_file(){
    cout<< "are you sure to clean data file"<< endl;
    string select;
    cin>>select;
    if(select=="sure"){
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();

        if(this->m_array !=NULL){ 
            for(int i=0;i<this->m_num;i++){
                delete this->m_array[i];
                this->m_array[i] = NULL;
            }
            delete[] this->m_array;
            this->m_array = NULL;
            this->m_num=0;
            this->m_fileempty = true;
        }
        cout<< "success to clean"<< endl;

    }
    system("pause");
    system("cls");
}


workmanager::~workmanager(){
    if(this->m_array !=NULL){ 
        for(int i=0;i<this->m_num;i++){
            delete this->m_array[i];
            this->m_array[i] = NULL;

        }
        delete[] this->m_array;
        this->m_array = NULL;
    }
}
