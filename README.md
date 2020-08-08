# Files Recursive Collector
This repository contains C++ based code implementation that searches recursively for certain file extension in an input directory and collect all these files into an output directory.
## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. **Please be noted that this code is tested on Ubuntu OS only**.
### Prerequisites
- Aptitude Dependencies
```bash
$ sudo apt update
$ sudo apt -y install git curl wget cmake build-essential lsb-core unzip
```
- Boost
```bash
$ wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.gz
$ tar -xzvf boost_1_62_0.tar.gz
$ cd boost_1_62_0
$ mkdir build
$ ./bootstrap.sh --with-libraries=filesystem --with-libraries=program_options
$ sudo ./b2 install -j$(nproc)
```
### Installation
You can skip this step and use the already built executable in github actions.
```bash
$ git clone https://github.com/ahmedfawzyelaraby/files-recursive-collector.git
$ cd files-recursive-collector
$ mkdir build
$ cd build
$ cmake ..
$ make -j
```
### Usage
```bash
$ ./files-recursive-collector -h # this command will get you the instructions you need to run the code.
