# Unix网络编程基础篇

## 一个简单的echo client/server
```c++
// server.cpp

// 单进程
#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#include<string>
using namespace std;

void output(const string &str, int size) {
    for (int i = 0; i < size; ++i)
        cout << str[i];
}

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in ser_addr, clnt_addr;
    unsigned addr_len = sizeof(struct sockaddr_in), clnt_addr_len;

    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(65535);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(sock_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));

    listen(sock_fd, 10);

    for (;;) {
        int client_fd = accept(sock_fd, (struct sockaddr*)&clnt_addr, &addr_len);
        string client_tag(100, 0);
        inet_ntop(AF_INET, &clnt_addr.sin_addr.s_addr, &client_tag[0], client_tag.capacity());
        client_tag += to_string(ntohs(clnt_addr.sin_port));
        cout << "connected from " << client_tag << endl;

        client_tag.push_back('>');
        int n;
        string recv_buf(1024, 0);
        while ((n = read(client_fd, &recv_buf[0], recv_buf.capacity()))) {
            cout << client_tag;
            output(recv_buf, n);
            cout << endl;

            n = write(client_fd, &recv_buf[0], n);
        }
        close(client_fd);
    }

    close(sock_fd);
    return 0;
}

```

```c++
// client.cpp
#include<iostream>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string>
#include<strings.h>

using namespace std;

void output(const string &str, int size) {
    for (int i = 0; i < size; ++i)
        cout << str[i];
}

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv, clnt;
    bzero(&serv, sizeof(serv));
    serv.sin_family = AF_INET,
    serv.sin_port = htons(65535);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);

    connect(sock_fd, (struct sockaddr*)&serv, sizeof(serv));

    string buffer(1024, 0);
    cin >> buffer;
    int n;
    while (buffer != "exit") {
        write(sock_fd, &buffer[0], buffer.length());
        n = read(sock_fd, &buffer[0], buffer.capacity());
        cout << "server>";
        output(buffer, n);
        cout << endl;
        cin >> buffer;
    }
    close(sock_fd);

    return 0;
}
```

## 一个简单的多进程echo服务器
`注意点：使用fork创建子进程后要在主进程中要记得调用wait等函来等待子进程`
> 当子进程走完了自己的生命周期后,它会执行exit()系统调用,内核释放该进程所有的资源,包括打开的文件,
> 占用的内存等。但是仍然为其保留一定的信息(包括进程号the process ID,退出码exit code,退出状态the terminationstatus of the process,
> 运行时间the amount of CPU time taken by the process等),这些数据会一直保留到系统将它传递给它的父进程为止,
> 直到父进程通过wait / waitpid来取时才释放。

```c++
#include<iostream>
#include<unistd.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#include<sys/wait.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void output(const string &str, int size) {
    for (int i = 0; i < size; ++i)
        cout << str[i];
}

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in ser_addr, clnt_addr;
    unsigned addr_len = sizeof(struct sockaddr_in), clnt_addr_len;

    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(65535);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(sock_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));

    listen(sock_fd, 10);

    vector<int> children;
    for (;;) {
        int client_fd = accept(sock_fd, (struct sockaddr*)&clnt_addr, &addr_len);
        string client_tag(100, 0);
        inet_ntop(AF_INET, &clnt_addr.sin_addr.s_addr, &client_tag[0], client_tag.capacity());
        client_tag += to_string(ntohs(clnt_addr.sin_port));
        cout << "connected from " << client_tag << endl;

        int pid = fork();
        if (pid == 0) {
            client_tag.push_back('>');
            int n;
            string recv_buf(1024, 0);
            while ((n = read(client_fd, &recv_buf[0], recv_buf.capacity()))) {
                cout << client_tag;
                output(recv_buf, n);
                cout << endl;

                n = write(client_fd, &recv_buf[0], n);
            }
            close(client_fd);
            exit(0);
        }
        children.push_back(pid);

        cout << client_tag << " is working on child process " << pid << endl;
        close(client_fd);
    }
    close(sock_fd);

    while (!children.empty()) {
        int status;
        int pid = wait(&status);
        
        children.erase(find(children.begin(), children.end(), pid));
        if (WIFEXITED(status)) {
            cout << "child " << pid << " terminated normally" << endl;
        } else {
            cout << "child " << pid << " terminated with " << WEXITSTATUS(status) << endl;
        }
    }

    cout << "server exit" << endl;
    return 0;
}
```



## 参考资料
[Linux中的defunct进程(僵尸进程)](https://blog.csdn.net/weixin_30919571/article/details/95053976)