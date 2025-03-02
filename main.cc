#include<iostream>
#include"login.hpp"
using namespace std;

int main() {
    Users user("localhost",6379);
    // user.regist("zbchi","12345");
    // cout<<user.login("zbchi","12345")<<endl;
    // user.cancle("zbchi");
    // cout<<user.login("zbchi","12345")<<endl;
    user.vCodeGenerate();

    return 0;
}