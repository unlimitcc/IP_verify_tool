# IP_verify_tool
该工具用于使用运行时验证的方法验证IP实现与contract的一致性。
使用KLEE自动生存覆盖各个IP实现全部分支的testcase，并根据此使用GDB生成对应于某分支的执行路径，在这些执行路径中验证contract在每一步的正确性，并转换为命题形式。最后使用TRACE4CPS工具验证contract的正确性。
注意:TRACE4CPS目前尚未集成到该工具中，之前从KLEE到生成TRACE模型部分已经实现。
下面是工具的来源:
KLEE: https://klee-se.org/
GDB: https://www.sourceware.org/gdb/
Z3-solver: https://github.com/Z3Prover/z3
TRACE4CPS: https://eclipse.dev/trace4cps/
