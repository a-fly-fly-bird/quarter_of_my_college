# debug
debug的方法：
* 打印
* 日志
* gdb等工具

日志的优势是可以分级以及持久化等。

日志放置位置：`/var/log`

## 查看日志

命令：`log show`

## 工具
* ipython
* [gdb](https://blog.csdn.net/chen1415886044/article/details/105094688)

# profiling
## 记录程序运行时间

eg. ` time tree &> /dev/null` 

`&>file`  意思是把标准输出 和 标准错误输出 都重定向到文件file中。

输出：

`tree > /dev/null  0.12s user 0.55s system 58% cpu 1.151 total`

其它工具太多了，用到再说吧。