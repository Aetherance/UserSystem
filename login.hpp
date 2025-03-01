#include<jsoncpp/json/json.h>
#include<cpp_redis/cpp_redis>
#include<string>
using namespace Json;
using namespace std;

class Users
{
public:
    Users(string,unsigned int);
    ~Users();
    void regist(string,string);
    bool login(string,string);

private:
    cpp_redis::client database;
    string base_all_users = "all_users";
};