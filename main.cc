#include<iostream>
#include"login.hpp"
using namespace std;

int main() {
    Users user("localhost",6379);
    user.regist("zbchi","12345");
    user.regist("xyz","gaoyixiang123");
    user.regist("nailong","issb");

    cout<<user.login("zbchi","12345");
    cout<<user.login("zchi","12345");
    return 0;
}