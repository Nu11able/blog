# 网络编程模板
```c

struct sockaddr_in{
    as_family_t sin_family;
    uint16_t sin_port;//16位TCP/IP端口
    struct in_addr sin_addr;//32位IP使用
    char sin_zero[8];//不使用 为了和IPv6兼容
}

struct in_addr{
    in_addr_ts_addr;//32位IPv4地址
}

struct sockaddr{
    sa_family_t sin_family;
    char sa_data[14];
}//IPv4 和 IPv6 公用


//server
#include<sys/socket.h>
// 创建套接字
int sock = socket(PF_INET, SOCK_STREAM/*套接字选项*/， 0)
struct sockaddr_in serv_addr,clnt_addr;
//初始化server地址 因为struct sockaddr被IPv4和IPc6公用 而IPv4地址较短 将多余的内存初始化为0
memset(&serv_addr, 0, sizeof(struct sockaddr));
//...

bind(sock, serv_addr);
 
listen(sock, 10);
socklen_t len = sizeof(clnt_addr);
while(1){
    int clnt = accept(sock, (struct sockaddr *)&serv_addr, &len);
    //then do something here
}

//client
#include<sys/socket.h>
// 创建套接字
int sock = socket(PF_INET, SOCK_STREAM， 0); /*套接字选项*/
struct sockaddr_in serv_addr;
//初始化server地址 因为struct sockaddr被IPv4和IPc6公用 而IPv4地址较短 将多余的内存初始化为0
memset(&serv_addr, 0, sizeof(struct sockaddr));
//...

while(1){
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    //then do something here
}

```

**网络字节序统一采用大端序**
```c
//为了在网络字节序和主机的字节序之间转换

//基于字符串的端口初始化
#include<arpa/inet.h>
unsigned short htons(unsigned short);
unsigned short ntohs(unsigned short);
unsigned long htonl(unsigned long);//htonl(INADDR_ANY);可自动获取运行与服务器端的ip地址
unsigned long ntohl(unsigned long);

//基于字符串的IP地址初始化
in_addr_t inet_addr(const char *string);//成功时返回32位大端整数值将字符串形式的ip转换为32位整数，满足网络字节序
int inet_aton(const char *string, struct in_addr *addr);//作用同上，自动将转换后的ip地址信息填入addr
char * inet_ntoa(struct in_addr adr);//作用与上面两个相反，将传入的整数型ip转换为字符串格式并返回




int shutdown(int sock, int howto);//howto:SHUT_RD SHUT_WR SHUT_RDWR  半关闭套接字


#include<netdb.h>
struct hostent * gethostbyname(const char * hostname);//利用域名获取ip地址
struct hostent * gethostbyaddr(const char * addr, socklen_t len, int family);//利用ip地址获取域名
struct hostent{
    char * h_name;
    char **h_aliasse;
    int h_addrtype;
    int h_length;
    char ** h_addr_list;//address list
}

# 设置套接字选项
#include<sys/socket.h>
int getsockopt(int sock, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int sock, int level, int optname, void *optval, socklen_t optlen);
//基于linux的文件操作

#include<unistd.h>
//其中read write close fork等函数都由此头文件提供
              

```

# 函数说明
```c ``



# 进程
#include<unistd.h>
pid_t fork(void); 

#include<wait.h>
pid_t wait(int *statloc); //调用wait函数时，如果没有已终止的子进程，那么程序将阻塞直到有子进程终止为止
pid_t waitpid(pid_t pid, int * statloc, int options);//options:WNOHANG即使没有子进程终止也不会进入阻塞状态
WIFEXITED();//子进程正常终止返回true
WEXITSTATUS();//返回子进程的返回值
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    int status;
    pid_t pid=fork();
    if(pid==0) return 3;
    else{
        printf("Child PID:%d\n", pid);
        pid = fork();
        if(pid == 0) exit(7);
        else{
            printf("Child PID:%d\n", pid);
            wait(&status);
            if(WIFEXITED(status))
                printf("Child send one:%d\n", WEXITSTATUS(status));
            wait(&status);
            if(WIFEXITED(status))
                printf("Child send two:%d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}

/*
Child PID:
CHild PID:
Child send one:3
Child send two:7

*/
```

# 信号处理
void (*signal(int signo, void (*func)(int)))(int);//当发生signo信号时将调用func函数

SIGALEM:已到通过调用alarm函数注册的时间
SIGINT:输入ctrl+c
SIGCHLD:子进程终止
**发生信号时将唤醒由于调用sleep函数而进入阻塞状态的进程**

#include<signal.h>
int sigaction(int signo, const struct sigaction *act, struct sigaction *oldact);
struct sigaction{
    void (*sa_handler)(int);
    sigset_t sa_mask; //sigemptyset(&act.sa_mask)
    int sa_flags;
}

# 进程间通信

