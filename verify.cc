#include"login.hpp"
string Users::vCodeGenerate() {
    string code;
    code.reserve(6);
    srand((size_t)time(NULL));
    for(int i = 0;i<6;i++) {
        code.push_back((rand() % 10) + '0');
    }
    return code;
}

void Users::CodetoDatabase(string code,string emall) {
    database.hset(base_verify_code,emall,code);
    database.sync_commit();
    codeTimer(database,emall);
}

void Users::CodetoEmall(string) {
    
}