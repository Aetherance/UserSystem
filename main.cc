#include<iostream>
#include"login.hpp"
using namespace std;
#include<unistd.h>
int main() {
    Users user("localhost",6379);
    // user.regist("zbchi","12345");
    // cout<<user.login("zbchi","12345")<<endl;
    // user.cancle("zbchi");
    // cout<<user.login("zbchi","12345")<<endl;
    user.CodetoDatabase("121212","2085163736@qq.com");

    sleep(15);

    return 0;
}