---
title: linux命令使用记录
tags:
 - linux
categories:
 - system
---

# linux命令使用记录

- 统计目标文件夹下的代码文本行数
```bash
find src/ -name "*.*" | xargs cat | wc -l
```


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
## 基本命令
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

