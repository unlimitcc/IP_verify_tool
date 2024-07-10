from z3 import *
import numpy as np

#variables
i,j = Ints('i j')
JoinTotal = Int('JoinTotal')
SignFlag = []
W = []
W_next = []
wa = []
TEMP_tmpwa = []
TEMP_tmpwa_next = []
Rtemp = []
TEMP_W = []
TEMP_W_next = []
########
VER_SignFlag = Array('VER_SignFlag', IntSort(), IntSort())
VER_W = Array('VER_W', IntSort(), RealSort())
VER_W_next = Array('VER_W_next', IntSort(), RealSort())
VER_wa = Array('VER_wa', IntSort(), RealSort())
VER_TEMP_tmpwa = Array('VER_TEMP_tmpwa', IntSort(), RealSort())
VER_TEMP_tmpwa_next = Array('VER_TEMP_tmpwa_next', IntSort(), RealSort())
VER_Rtemp = Array('VER_Rtemp', IntSort(), ArraySort(IntSort(), RealSort()))
VER_TEMP_W_next = Array('VER_TEMP_W_next', IntSort(), RealSort())
########
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
#####