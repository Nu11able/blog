在安装过程中遇到无法找到sqlite3的问题，不过问题是我已经执行过apt install sqlite3安装了sqlite3了，但还是报错。
网上搜索了结果说要安装sqlite-devel 但是我可能是由于我是阿里还是其他的原因导致无法找到sqlite-devel，最后安装了
libsqlite3-dev解决问题


```
apt install pkg-config
apt install libxml-dev
apt install sqlite3
apt install libsqlite3-dev
```