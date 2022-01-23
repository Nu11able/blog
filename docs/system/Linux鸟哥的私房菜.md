ctrl + alt + [f1 - f6 ] 切换终端

ctrl + alt + f7 图形界面桌面

ctrl + d 键盘输入结束

ctrl + z 停止运行

ctrl + c 终止运行

命令|ls|date|cal|bc
-|-|-|-|-
作用||日期|日历|计算器

## man page 代号说明
代号|内容
-|-
1|用户在shell中可以操作或可执行文件
2|系统内核与函数可调用的工具
3|一些常用的函数(function)与函数库(library),大部分为c的函数库(lib)
4|设备文件说明，通常在/dev下的文件
5|配置文件或某些文件的格式
6|游戏
7|惯例与协议等，linux文件系统、网络协议、ASCII code等说明
8|系统管理员可用的命令
9|跟kernel有关的文件

`/string 向下查询string字符串 ?string 向上查询string字符串`
# 基本命令
命令|作用
-|-
whatis|相当于man -f 需要创建whatis数据库
apropos|相当于man -k 需要创建whatis数据库
makewhatis| 创建whatis数据库
info|与man类似
netstat|查看网络联机状态
sync|同步写入磁盘(关机前将数据写入磁盘)
reboot、halt、poweroff、shutdown|重启、关机
cd|change directory(进入目录)
cp|copy
su|切换身份
free|






工具|作用
-|-
nano|简单文本编辑器
vim|强大的文本编辑器
dump|完整的备份工具

# 文件权限与目录配置

**-rw-r--r-- 1 root root 42304 Sep 4 18:26 install.log**

说明:第一个字符说明是目录文件或链接文件，权限排序是所有者、用户组、其他人，42304为文件大小(默认单位B)、18:26最后修改时间
代号|说明
-|-
c|串行端口设备，例如键盘鼠标
-|文件

## 文件权限相关
r:4 w:2 x:1
命令|作用
-|-
chgrp|改变文件所属用户组
chown|改变文件所有者
chmod|改变文件权限

[Linux目录配置说明](https://www.runoob.com/linux/linux-system-contents.html)

# Linux文件与目录管理
`echo $PATH 执行文件路径的变量(系统会到PATH的路径下去寻找可执行的文件[windows环境变量])`

`文件特殊权限:SUID、SGID、SBIT`

代号|说明
-|-
.|此层目录
..|上一层目录
-|前一个工作目录
~|代表“目前用户身份”所在的主文件夹
~account|代表“account用户身份”所在的主文件夹

命令|作用
-|-
cd|切换目录
pwd|显示当前目录
mkdir|新建一个新的目录
rmdir|删除一个空的目录
touch|创建新文件或修改文件时间
ls|查看文件与目录
cp、rm、mv|复制、删除、移动
cat|由第一行开始显示文件内容
tac|由最后一行开始显示文件内容
nl|显示的时候输出行号
more|一页一页的显示内容
less|与more类似但可以往前翻页
head|只看头几行
tail|只看结尾几行
od|以二进制的方式读取文件内容
umask|文件默认权限
chattr|设置文件隐藏属性
lsattr|显示文件隐藏属性
file|查看文件类型
which|寻找可执行文件
whereis|寻找特定文件 (会使用到数据库)
locate|与whereis类似 (会使用到数据库)
find|更强大的文件查找命令、但查找会相对慢一些


# Linux磁盘与文件系统管理

命令|作用
-|-
mount|挂载文件系统
umount|将设备文件卸载
df|列出文件系统的整体磁盘使用量慢
du|评估文件系统的磁盘使用量
ln|连接 就像windows下的快捷方式
fdisk|磁盘分区
mkfs|磁盘格式化 make file system
fsck、badblocks|磁盘检验

# 文件与文件系统的压缩与打包

后缀|说明
-|-
*.Z|compress压缩的文件
*.gz|gzip压缩的文件
*.bz2|bzip2压缩的文件
*.tar|tar程序打包的数据，并没有压缩过
*.tar.gz|tar程序打包的数据，其中经过bzip的压缩
*.tar.bz2|tar程序打包的数据，其中经过bzip2的压缩

命令|作用
-|-
gzip|压缩文件
zcat|可以读取存文本被压缩后的压缩文件
bzip2|压缩比高于gzip
bzcat|作用类似于zcat
tar|打包命令
dump|完整的备份工具
restore|回复使用dump备份的数据
mkiosfs|新建镜像文件
cdrecord|光盘刻录工具
dd|创建大文件
cpio|
dos2UNIX|文件类型转换
UNIX2dos|文件类型转换




