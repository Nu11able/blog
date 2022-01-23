# 第16章 网络IPC:套接字

使用到的头文件：
```c
#include <sys/cdefs.h>
# if !defined __cplusplus && __GNUC_PREREQ (3, 3)
#  define __THROW   __attribute__ ((__nothrow__ __LEAF))
#  define __THROWNL __attribute__ ((__nothrow__))
#  define __NTH(fct)    __attribute__ ((__nothrow__ __LEAF)) fct
#  define __NTHNL(fct)  __attribute__ ((__nothrow__)) fct
# else
#  if defined __cplusplus && __GNUC_PREREQ (2,8)
#   define __THROW  throw ()
#   define __THROWNL    throw ()
#   define __NTH(fct)   __LEAF_ATTR fct throw ()
#   define __NTHNL(fct) fct throw ()
#  else
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)   fct
#   define __NTHNL(fct) fct
#  endif


#include <sys/socket.h>
extern int socket (int __domain, int __type, int __protocol) __THROW;
extern int socketpair (int __domain, int __type, int __protocol, int __fds[2]) __THROW;
extern int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len) __THROW;
extern int getsockname (int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __len) __THROW;
extern int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
extern int getpeername (int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __len) __THROW;
extern ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto (int __fd, const void *__buf, size_t __n, int __flags, __CONST_SOCKADDR_ARG __addr, socklen_t __addr_len);
extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n, int __flags, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len);
extern ssize_t sendmsg (int __fd, const struct msghdr *__message, int __flags);
extern int sendmmsg (int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags);
extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags);
extern int recvmmsg (int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags, struct timespec *__tmo);
extern int getsockopt (int __fd, int __level, int __optname, void *__restrict __optval, socklen_t *__restrict __optlen) __THROW;
extern int setsockopt (int __fd, int __level, int __optname, const void *__optval, socklen_t __optlen) __THROW;
extern int listen (int __fd, int __n) __THROW;
extern int accept (int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len);
extern int accept4 (int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int __flags);
extern int shutdown (int __fd, int __how) __THROW;
extern int sockatmark (int __fd) __THROW;
extern int isfdtype (int __fd, int __fdtype) __THROW;



#include <arpa/inet.h>
#include <stdint.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/wait.h>


#include <pthread.h>
extern int pthread_create (pthread_t *__restrict __newthread, const pthread_attr_t *__restrict __attr, void *(*__start_routine) (void *), void *__restrict __arg) __THROWNL __nonnull ((1, 3));

``` 