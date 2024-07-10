from z3 import *
import numpy as np

#variables in program
JoinTotal = Int('JoinTotal')
gyroStatus0 = Int('gyroStatus0')
gyroStatus1 = Int('gyroStatus1')
gyroStatus0_next = Int('gyroStatus0_next')
gyroStatus1_next = Int('gyroStatus1_next')
flgGyroCalc = Int('flgGyroCalc')
flgGyroCalc_next = Int('flgGyroCalc_next')
i, j = Ints('i j')
VG = []
VG_next = []
Rtemp = []
Rtemp_next = []
SignFlag = []
TEMP_Rgtemp = []
TEMP_rank = Int('TEMP_rank')
#验证所添加的临时变量，命名格式VER_VAR NAME
VER_VG = Array('VER_VG',IntSort(),ArraySort(IntSort(), RealSort()))
VER_VG_next = Array('VER_VG_next',IntSort(),ArraySort(IntSort(), RealSort()))
VER_Rtemp = Array('VER_Rtemp',IntSort(),ArraySort(IntSort(), RealSort()))
VER_Rtemp_next = Array('VER_Rtemp_next',IntSort(),ArraySort(IntSort(), RealSort()))
VER_Rgtemp = Array('VER_Rgtemp',IntSort(),ArraySort(IntSort(), RealSort()))
VER_SignFlag = Array('VER_SignFlag', IntSort(), IntSort())
def min(x,y):
    return If(x>=y,y,x)
def Array_length(a):
	temp = np.array(a)
	return temp.size
def Array_Size(a): 
	temp = np.array(a)
	return temp.shape
def List2Array(lst, idx=()):
    if isinstance(lst[0], list):
        size = len(lst)
        z3_array = Array('array_' + '_'.join(map(str, idx)), IntSort(), ArraySort(IntSort(), RealSort()))
        constraints = []
        for i in range(size):
            sub_array, sub_constraints = List2Array(lst[i], idx + (i,))
            constraints.extend(sub_constraints)
            constraints.append(z3_array[i] == sub_array)
        return z3_array, constraints
    else:
        size = len(lst)
        z3_array = Array('array_' + '_'.join(map(str, idx)), IntSort(), RealSort())
        constraints = [z3_array[i] == lst[i] for i in range(size)]
        return z3_array, constraints
s = Solver()
##########

