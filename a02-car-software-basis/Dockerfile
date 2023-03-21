FROM ubuntu:18.04

LABEL org.opencontainers.image.authors="lucas"

USER root

VOLUME /root

# docker can not use https, http instead.
RUN cd /etc/apt && mv sources.list sources.list.bk && echo " deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic main restricted universe multiverse\n deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-updates main restricted universe multiverse\n deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-backports main restricted universe multiverse\n  deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-security main restricted universe multiverse" > sources.list

RUN apt update && apt install -y sudo

RUN apt install -y vim \
    && apt install -y git \
    && apt install -y gcc \
    && apt install -y g++ \
    && apt install -y cmake

# RUN apt install -y libpcl-dev \
#     && echo -e "\n6\n\n" | apt install -y libopencv-dev \
#     && apt install -y libeigen3-dev \
#     && apt install -y libboost-all-dev

# Frequently modified or time-consuming instructions put back.
COPY --chown=root nlopt-2.7.1/ /usr/local/nlopt/

WORKDIR /usr/local/nlopt/

RUN mkdir build && cd build && cmake .. && make && make install

WORKDIR /root
