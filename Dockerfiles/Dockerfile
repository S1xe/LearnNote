FROM ubuntu

RUN apt-get update 
RUN apt-get install -y software-properties-common libatlas-base-dev gfortran nginx python3.6 python3-pip
RUN pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U 
RUN pip3 config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple