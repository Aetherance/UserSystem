#include<iostream>
#include<memory.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int sock = -1;

string create_http_header(int status_code, const string& content_type, size_t content_length) {
    return "HTTP/1.1 " + std::to_string(status_code) + " OK\r\n"
           "Content-Type: " + content_type + "\r\n"
           "Content-Length: " + std::to_string(content_length) + "\r\n"
           "Connection: keep-alive\r\n\r\n";
}

void pushIndex() {
    int index_fd = open("/home/user/CODE/login/web/index.html",O_RDONLY);
    char buff[102400] = {};
    read(index_fd,buff,102400);
    string index(buff);
    string http_info = create_http_header(200,"text/html",index.size());
    string response = http_info + index;
    send(sock,response.c_str(),response.size(),0);
}

void parsePost() {
    while (true) {
        char buff[1024];
        cout<<recv(sock,buff,1024,0);
        cout<<buff;
    }
}

int main() {
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in sin;
    memset(&sin,0,sizeof(sockaddr_in));

    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8080);

    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if(bind(lfd,(sockaddr*)&sin,sizeof(sockaddr_in)) == -1) {
        perror("bind");
    };

    listen(lfd,3);
    sockaddr_in c_sin;
    socklen_t len;
    sock = accept(lfd,(sockaddr*)&c_sin,&len);
    
    pushIndex();

    parsePost();

    return 0;
}