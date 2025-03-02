#ifndef LOGIN_H
#define LOGIN_H

#include<jsoncpp/json/json.h>
#include<cpp_redis/cpp_redis>
#include<string>
#include<time.h>
using namespace Json;
using namespace std;

inline std::string base_all_users = "all_users";
inline std::string base_verify_code = "verifyCode";

class Users
{
public:
    Users(string,unsigned int);
    ~Users();
    void regist(string,string);
    bool login(string,string);
    void cancle(string);
    void verification(string,string,string);
    string vCodeGenerate();
    void CodetoDatabase(string,string);
    void CodetoEmall(string);

private:
    cpp_redis::client database;
    
};

class codeTimer
{
public:
    codeTimer();
    ~codeTimer();
    void removeCode(cpp_redis::client&,string);
private:
};

inline void codeTimer::removeCode(cpp_redis::client& database,string emall) {
    database.hdel(base_verify_code,{emall});
}

#endif