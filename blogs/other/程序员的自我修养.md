---
title: 《程序员的自我修养》阅读记录
tags:
 - other
categories:
 - other
---

# 工具
名字|作用
-|-
gcc|
objdump|
objcopy|
size|
readelf|


# gcc 扩展

## 指定变量所处的段

```c
__attribute__((section("FOO"))) int global = 42;//将global放到指定的段中(FOO)

//__attribute__((section("name"))) 将数据放到name段中
```