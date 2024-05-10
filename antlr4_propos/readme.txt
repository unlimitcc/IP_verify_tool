#####
该文件夹包含从提取IP contract中提取命题的antlr4语法分析器源码，语法和词法都定义在contract.g4中，使用antlr4的Listener实现命题提取的功能。
编译contract.g4的命令：
$ antlr4 -Dlanguage=Cpp contract.g4
$ g++ ./*.cpp -lantlr4-runtime
