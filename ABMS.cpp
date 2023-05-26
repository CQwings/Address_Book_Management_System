#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct Person
{
    //姓名
    string m_Name;
    //性别
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};
//通讯录结构体
struct AddressBooks
{
    //通讯录保持的联系人数组
    struct Person personArray[MAX];
    //当前记录联系人个数
    int m_Size;
};
//添加函数
void addPerson(AddressBooks * abms){
    //判断是否已满
    if(abms->m_Size==MAX)
    {
        cout<<"ABMS已满，无法添加！"<<endl;
        return;
    }
    else
    {//添加
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abms->personArray[abms->m_Size].m_Name=name;
        int sex=0;
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>sex;
            if (sex==1||sex==2)
            {
                abms->personArray[abms->m_Size].m_Sex = sex;
                break;
            }
            cout<<"输入错误，请重新输入！"<<endl;
            cin.clear();
            cin.sync();
        }
        cout<<"请输入年龄！"<<endl;
        int age=0;
        cin>>age;
        abms->personArray[abms->m_Size].m_Age = age;

        cout<<"请输入联系电话！"<<endl;
        string phone ;
        cin>>phone;
        abms->personArray[abms->m_Size].m_Phone = phone;

        cout<<"请输入家庭住址！"<<endl;
        string address ;
        cin>>address;
        abms->personArray[abms->m_Size].m_Addr = address;

        //更新人数
        abms->m_Size++;
        cout<<"添加成功"<<endl;
    }
}
//显示函数
void showPerson(AddressBooks * abms)
{
    if (abms->m_Size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for (int i = 0; i < abms->m_Size; i++)
        {
            cout<<"姓名："<<abms->personArray[i].m_Name<<"\t";
            cout<<"性别："<<(abms->personArray[i].m_Sex==1?"男":"女")<<"\t";
            cout<<"年龄："<<abms->personArray[i].m_Age<<"\t";
            cout<<"电话："<<abms->personArray[i].m_Phone<<"\t";
            cout<<"住址："<<abms->personArray[i].m_Addr<<endl;
        }
    }

    system("pause");
    system("cls");
}
//检测联系人是否存在
int isExist(AddressBooks * abms,string name)
{
    for (int i = 0; i < abms->m_Size; ++i)
    {
        if (abms->personArray[i].m_Name==name)
        {
            return i;
        }
    }
    return -1;
}

//删除函数
void deletePerson(AddressBooks * abms)
{
    cout<<"请输入删除联系人姓名："<<endl;
    string name;
    cin>>name;
    int ret= isExist(abms,name);
    if (ret==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        for (int i = ret; i < abms->m_Size; ++i)
        {
            abms->personArray[i]=abms->personArray[i+1];
        }
        abms->m_Size--;
        cout<<"删除成功！"<<endl;
    }
    system("pause");
    system("cls");
}
//查找函数
void findPerson(AddressBooks * abms)
{
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin >>name;
    int ret= isExist(abms,name);
    if (ret!=-1)
    {
        cout<<"姓名："<<abms->personArray[ret].m_Name<<"\t";
        cout<<"性别："<<(abms->personArray[ret].m_Sex==1?"男":"女")<<"\t";
        cout<<"年龄："<<abms->personArray[ret].m_Age<<"\t";
        cout<<"电话："<<abms->personArray[ret].m_Phone<<"\t";
        cout<<"住址："<<abms->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }

    system("pause");
    system("cls");
}
//修改
void modifyPerson(AddressBooks * abms)
{
    cout<<"请输入您要修改的联系人"<<endl;
    string name;
    cin >>name;
    int ret= isExist(abms,name);
    if (ret!=-1)
    {
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abms->personArray[ret].m_Name=name;
        int sex=0;
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>sex;
            if (sex==1||sex==2)
            {
                abms->personArray[ret].m_Sex = sex;
                break;
            }
            cout<<"输入错误，请重新输入！"<<endl;
            cin.clear();
            cin.sync();
        }
        cout<<"请输入年龄！"<<endl;
        int age=0;
        cin>>age;
        abms->personArray[ret].m_Age = age;

        cout<<"请输入联系电话！"<<endl;
        string phone ;
        cin>>phone;
        abms->personArray[ret].m_Phone = phone;

        cout<<"请输入家庭住址！"<<endl;
        string address ;
        cin>>address;
        abms->personArray[ret].m_Addr = address;

        cout<<"修改成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }

    system("pause");
    system("cls");
}
//清空
void clearPerson(AddressBooks * abms)
{
    abms->m_Size=0;
    cout<<"通讯录已清空"<<endl;
    system("pause");
    system("cls");
}


//菜单界面
void showMenu()
{
    cout<<"1、 添加联系人"<<endl;
    cout<<"2、 显示联系人"<<endl;
    cout<<"3、 删除联系人"<<endl;
    cout<<"4、 查找联系人"<<endl;
    cout<<"5、 修改联系人"<<endl;
    cout<<"6、 清空联系人"<<endl;
    cout<<"0、 退出ABMS"<<endl;
}
int main()
{
    //创建通讯录结构体变量
    AddressBooks abms;
    //初始化当前人员个数
    abms.m_Size=0;

    int select = 0;//用户输入变量

    while (true){

    //菜单调用
    showMenu();

    cin>>select;
    switch(select)
    {
        case 1://添加
            addPerson(&abms);//地址传递
            break;
        case 2://显示
            showPerson(&abms);
            break;
        case 3://删除
            deletePerson(&abms);
            break;
        case 4://查找
            findPerson(&abms);
            break;
        case 5://修改
            modifyPerson(&abms);
            break;
        case 6://清空
            clearPerson(&abms);
            break;
        case 0:
            cout<<"欢迎下次使用"<<endl;
            return 0;
        default:
            break;
    }
}

    system("pause");
    system("cls");
    return 0;
}
