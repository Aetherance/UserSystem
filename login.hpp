#ifndef LOGIN_H
#define LOGIN_H

#include<jsoncpp/json/json.h>
#include<cpp_redis/cpp_redis>
#include<string>
#include<time.h>
#include<chrono>

#define VERIFY_CODE_LIFE_TIME 5

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
    codeTimer(cpp_redis::client&,string);
};

inline codeTimer::codeTimer(cpp_redis::client& database,string emall) {
    thread([&database,emall]() {
        this_thread::sleep_for(chrono::minutes(VERIFY_CODE_LIFE_TIME));
        database.hdel(base_verify_code,{emall});
        database.sync_commit();
    }).detach();
}

#endif