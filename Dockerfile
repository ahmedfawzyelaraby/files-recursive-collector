From ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt -qq update && apt -y -qq install git curl wget cmake build-essential lsb-core unzip && apt clean

WORKDIR /
RUN wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.gz && \
    tar -xzvf boost_1_62_0.tar.gz && cd boost_1_62_0 && mkdir build && \
    ./bootstrap.sh --with-libraries=filesystem --with-libraries=program_options && \
    ./b2 install -j$(nproc) && cd ../ && \rm -rf boost_1_62_0 && rm -rf boost_1_62_0.tar.gz
    
WORKDIR /files-recursive-collector
COPY . .