FROM ubuntu:focal

# ENV TZ=Asia/Shanghai

RUN echo "${TZ}" > /etc/timezone \
    && ln -sf /usr/share/zoneinfo/${TZ} /etc/localtime \
    && apt-get update \
    && apt-get install -y tzdata \
    && rm -rf /var/lib/apt/lists/*

# https://github.com/moby/moby/issues/4032#issuecomment-34597177
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \ 
    && apt-get install wget python3-yaml -y  \
    # 安装melodic
    && echo "chooses:\n" > fish_install.yaml \
    && echo "- {choose: 1, desc: '一键安装:ROS(支持ROS和ROS2,树莓派Jetson)'}\n" >> fish_install.yaml \
    && echo "- {choose: 1, desc: 更换源继续安装}\n" >> fish_install.yaml \
    && echo "- {choose: 2, desc: 清理三方源}\n" >> fish_install.yaml \
    && echo "- {choose: 1, desc: noetic(ROS1)}\n" >> fish_install.yaml \
    && echo "- {choose: 2, desc: noetic(ROS1)基础版(小)}\n" >> fish_install.yaml
RUN wget http://fishros.com/install  -O fishros \
    && apt-get install sudo \
    && chmod u+x ./fishros \
    && /bin/bash ./fishros \
    # 进行最后的清理
    && rm -rf /var/lib/apt/lists/*  /tmp/* /var/tmp/* \
    && apt-get clean && apt-get autoclean \
    && apt-get install -y build-essential
