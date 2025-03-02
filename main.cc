#include<iostream>
#include"login.hpp"
using namespace std;
#include<unistd.h>
int main() {
    Users user("localhost",6379);
    user.verification("zbchi","12345","2085163736@qq.com");

    // sleep(15);

    return 0;
}