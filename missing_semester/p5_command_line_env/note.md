# Job Control

软件的控制是通过信号量（SIGINT）实现的。逻辑是读取到某个信号量则执行某种操作，都是可以定义的。

## 后台进程
* nohup
* &
* jobs
* bg %1
* fg %1
* kill %1

这些都很熟悉了，跳过。

# Terminal Multilexer(主要是tmux)

看完视频，可以参考阮一峰老师的[Tmux 使用教程](http://www.ruanyifeng.com/blog/2019/10/tmux.html)系统学习。

为什么有了终端，还要再“多此一举”有个tmux呢？重点就是Multilexer(复用器)。

引用阮一峰老师教程里的话：

> 命令行的典型使用方式是，打开一个终端窗口（terminal window，以下简称"窗口"），在里面输入命令。用户与计算机的这种临时的交互，称为一次"会话"（session） 。
会话的一个重要特点是，窗口与其中启动的进程是连在一起的。打开窗口，会话开始；关闭窗口，会话结束，会话内部的进程也会随之终止，不管有没有运行完。
一个典型的例子就是，SSH 登录远程计算机，打开一个远程窗口执行命令。这时，网络突然断线，再次登录的时候，是找不回上一次执行的命令的。因为上一次 SSH 会话已经终止了，里面的进程也随之消失了。
为了解决这个问题，会话与窗口可以"解绑"：窗口关闭时，会话并不终止，而是继续运行，等到以后需要的时候，再让会话"绑定"其他窗口。

# Dotfiles
可以理解为各种软件的配置文件。
~/.bashrc
~/.zshrc
~/.vimrc
~/.tmux.conf

Github上有人集成了所有常见的[dotfiles](https://github.com/mathiasbynens/dotfiles)。

这里老师又提供了一个很好的思路。这些配置文件，都只会在主目录下才会生效。那么如果想同时存在多个版本的配置文件，怎么做才是最优雅的呢？git？每次手动修改覆盖？替换文件？

**最优雅的解决方案**：符号链接。把配置文件集中放在一个文件夹里，然后主目录下的配置文件作为一个链接文件，链接到实际的文件。

# Remote Machine
* ssh user@ip/domain
* ssh-keygen
* scp(ssh copy)
* rsync(better than scp)

## ~/.ssh/config

配置密钥连接，避免每次都输密码。

配置示例：
```conf
Host vm
1 User jjgo
2 HostName 192.168.246.142
3 IdentityFile ~/.ssh/id_ed25519
4 RemoteForward 9999 localhost:8888
```

## ssh 配合 tmux 使用

tmux 可以保存工作状态。 