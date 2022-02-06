# linux命令使用记录

- 统计目标文件夹下的代码文本行数
```bash
find src/ -name "*.*" | xargs cat | wc -l
```