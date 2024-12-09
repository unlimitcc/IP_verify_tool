# IP_verify_tool
基于TRACE的IP验证工具安装说明文档
1. 操作系统：Ubuntu20.04
2. ANTLR4  
    1.ANTLR4版本：4.13.1  
    2.安装依赖：java，版本号17.0.10  
    `$ sudo apt install openjdk-17-jdk`  
    3.安装ANTLR4:  
    (1):下载ANTLR4  
    ```  
    $ wget https://www.antlr.org/download/antlr-4.13.1-complete.jar      
    $ sudo cp antlr-4.13.1-complete.jar /usr/local/lib/ 
    ```   
    (2):安装ANTLR4-runtime(运行时库)  
    ```  
    $ wget https://www.antlr.org/download/antlr4-cpp-runtime-4.13.1-source.zip  
    $ unzip antlr4-cpp-runtime-4.13.1-source.zip -d antlr4-cpp-runtime-4.13.1  
    ```  
    (3):配置环境变量  
    ```
    $ export CLASSPATH=".:/usr/local/lib/antlr-4.13.1-complete.jar:$CLASSPATH"
    $ alias antlr4='java -jar /usr/local/lib/antlr-4.13.1-complete.jar'
    $ alias grun='java org.antlr.v4.gui.TestRig'
    ```
3. KLEE  
    1.KLEE版本：2.3  
    2.安装KLEE依赖：  
    (1):基本库安装：  
    `
    $ sudo apt-get install build-essential curl libcap-dev git cmake libncurses5-dev python-minimal python-pip unzip libtcmalloc-minimal4 libgoogle-perftools-dev libsqlite3-dev doxygen  
    `  
    (2):Ubuntu运行环境配置  
    `$ sudo apt-get install python3 python3-pip gcc-multilib g++-multilib`  
    (3):wllvm安装  
    `$ pip3 install lit tabulate wllvm`  
    (4):LLVM-9安装  
    `$ sudo apt-get install clang-9 llvm-9 llvm-9-dev llvm-9-tools`  
    (5):约束求解器Z3Prover安装  
    `$ pip install z3-solver`  
    (6):下载谷歌测试集(可选)
    ```  
    $ curl -OL https://github.com/google/googletest/archive/release-1.7.0.zip
    $ unzip release-1.7.0.zip  
    ```  
    (7):klee内置库uclibc安装
    ```  
    $ git clone https://github.com/klee/klee-uclibc.git  
    $ cd klee-uclibc  
    $ ./configure --make-llvm-lib --with-llvm-config /usr/bin/llvm-config-9
    $ make -j2  
    $ cd ..   
    ```  
    (8):klee源码安装：  
    `$ git clone https://github.com/jywhy6/klee`  
    (9):构建libc++：
    ```  
    $ cd klee
    $ LLVM_VERSION=9 SANITIZER_BUILD= BASE=<LIBCXX_DIR> REQUIRES_RTTI=1 DISABLE_ASSERTIONS=1 ENABLE_DEBUG=0 ENABLE_OPTIMIZED=1 ./scripts/build/build.sh libcxx  
    ```  
    其中<LIBCXX_DIR>是klee-uclibc的绝对路径  
    (10):构建klee  
    其中<***-***>命令的文件夹需修改为用户平台所安装对应依赖的文件夹的绝对路径
    ```  
    $ mkdir build
      cd build
      cmake \
        -DENABLE_POSIX_RUNTIME=ON \
        -DENABLE_SOLVER_STP=OFF \
        -DENABLE_SOLVER_Z3=ON \
        -DENABLE_KLEE_UCLIBC=ON \
        -DENABLE_KLEE_LIBCXX=ON \
        -DKLEE_LIBCXX_DIR=<LIBCXX_SRC_DIR> \
        -DKLEE_LIBCXX_INCLUDE_DIR=<LIBCXX_INCLUDE_DIR> \
        -DENABLE_KLEE_EH_CXX=ON \
        -DKLEE_LIBCXXABI_SRC_DIR=<LIBCXXABI_SRC_DIR> \
        -DKLEE_UCLIBC_PATH=<KLEE_UCLIBC_SRC_DIR> \
        -DENABLE_UNIT_TESTS=ON \
        -DENABLE_SYSTEM_TESTS=ON \
        -DGTEST_SRC_DIR=<GTEST_SRC_DIR> \
        -DLLVM_CONFIG_BINARY=<LLVM_CONFIG_PATH> \
        -DLLVMCC=<CLANG_PATH> \
        -DLLVMCXX=<CLANGXX_PATH> \
        -DCMAKE_C_COMPILER=clang-9  \
        -DCMAKE_CXX_COMPILER=clang++-9  \
        ..
    $ make  
    $ sudo make install
    ```
4. 运行  
    ```
    $ cd build  
    $ cmake ..
    $ make
    $ cd ..
    $ ./main
    ```
    (1)命题提取结果显示在主文件夹  
    (2)测试用例txt文件生成在 testcase/ 以及 klee-out-n/ 文件夹下  
    (3)程序执行路径生成在 GDB_trace/ 文件夹下  
    (4)TRACE模型生成在 TRACE/ 文件夹下

 


