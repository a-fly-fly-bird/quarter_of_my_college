#!/bin/bash

echo "内核版本："
cat /proc/version
echo -e "\n"
echo "发行版本："
cat /etc/issue
echo -e "\n"
echo "底层架构:"
dpkg --print-architecture
echo -e "\n"

echo -e "\n\n\n-------------------- change source -------------------------"
RESULT=$(cat /etc/issue | grep "18.04")
ARCH=$(dpkg --print-architecture)
if [ "$RESULT" != "" -a "$ARCH" == "arm64" ]
then
    if [ ! -f "/etc/apt/sources.list.bk" ]
    then
        echo "Start change source."
        cd /etc/apt/
        mv sources.list sources.list.bk
        echo -e "deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic main restricted universe multiverse\n deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-updates main restricted universe multiverse\n deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-backports main restricted universe multiverse\n  deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-security main restricted universe multiverse" > sources.list
    else
        echo "You have change app source, so skip."
    fi
else
    echo "你的电脑是另外的架构，自己更换源。"
fi

# ooops, After about two hours, I suddenly realized that the default interpreter for Ubuntu in Docker is sh, not bash. F**k.Type bash habitually.
cd /etc/apt

# update source list
apt update

checkIfInstalled(){
    # -v 的含义是不执行命令，但搜索命令和打印不执行命令
    if ! [ -x "$(command -v $1)" ]
    then
        echo "$1 没有安装" >&2
        apt install -y $1
    else
        echo "已安装 $1"
    fi
}

# set timezone
if ! [ -x "$(command -v crontab)" ]
then
    echo "crontab 没有安装" >&2
    apt install -y cron
    service cron start
    # set timezone
    ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
    if ! crontab -l |grep ntpdate &>/dev/null ; then
        (echo "* 1 * * * ntpdate ntp1.aliyun.com >/dev/null 2>&1";hwclock -w;crontab -l) |crontab 
    fi
    echo "时区已设置"
else
    echo "时区已设置"
fi

checkIfInstalled sudo
checkIfInstalled vim
checkIfInstalled git
checkIfInstalled gcc
checkIfInstalled g++
checkIfInstalled cmake
checkIfInstalled wget

cd /root
# Compiling and installing Software
if [ ! -d "/root/nlopt" ]
then
    wget http://github.com/stevengj/nlopt/archive/v2.7.1.tar.gz -O /root/nlopt.tar.gz
    mkdir ./nlopt
    tar -zxvf ./nlopt.tar.gz -C ./nlopt --strip-components 1 && rm -rf ./nlopt.tar.gz
    cd nlopt
    echo "\n\n\n -------- 开始编译nlopt ---------"
    mkdir build && cd build && cmake .. && make && make install
else
    echo "Nlopt has been installed."
fi

echo "-------------------------- start install libpcl-dev  -------------------------\n\n"
apt install -y libpcl-dev
echo "-------------------------- start install libpcl-dev  -------------------------\n\n"
apt install -y libopencv-dev
echo "-------------------------- start install libpcl-dev  -------------------------\n\n"
apt install -y libeigen3-dev
echo "-------------------------- start install libpcl-dev  -------------------------\n\n"
apt install -y libboost-all-dev
echo -e "\n\n\n-------------------------- Install Successfully! ------------------------------\n"
