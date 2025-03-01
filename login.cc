#include"login.hpp"

Users::Users(string ip,unsigned int port) {
    database.connect(ip,port);
}

void Users::regist(string user_name,string passwd) {
    Value new_user;
    new_user["user_name"] = user_name;
    new_user["passwd"] = passwd;
    StreamWriterBuilder writer;
    string new_user_str = writeString(writer,new_user);

    database.hset(base_all_users,user_name,new_user_str);
    database.sync_commit();
}

bool Users::login(string user_name,string passwd) {
    auto isExist = database.hexists(base_all_users,user_name);
    database.sync_commit();
    auto isExist_reply = isExist.get();
    if(!isExist_reply.is_integer() || !isExist_reply.as_integer()) {
        return false;
    }
    auto future = database.hget(base_all_users,user_name);
    database.sync_commit();
    cpp_redis::reply reply = future.get();
    Value json_str;
    CharReaderBuilder reader;
    istringstream iss(reply.as_string());
    parseFromStream(reader,iss,&json_str,nullptr);   
    string user_pswd = json_str["passwd"].asString();
    if(user_pswd == passwd) {
        return true;
    } else {
        return false;
    }
}

Users::~Users() {

}