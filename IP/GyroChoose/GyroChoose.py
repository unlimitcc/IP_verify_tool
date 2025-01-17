from z3 import *
import numpy as np

#variables
JoinTotal = Int('JoinTotal')
JoinTotal_next = Int('JoinTotal_next')
gyroStatus0 = Int('gyroStatus0')
gyroStatus0_next = Int('gyroStatus0_next')
sum_temp = Function('sum_temp', IntSort(), IntSort())
i,j = Ints('i j')
k,k1 = Ints('k k1')
tempFlag = []
tempFlag_next = []
StateFlag = []
SignFlag = []
SignFlag_next = []
VER_tempFlag = Array('VER_tempFlag', IntSort(), IntSort())
VER_tempFlag_next = Array('VER_tempFlag_next', IntSort(), IntSort())
VER_StateFlag = Array('VER_StateFlag', IntSort(), IntSort())
VER_SignFlag = Array('VER_SignFlag', IntSort(), IntSort())
VER_SignFlag_next = Array('VER_SignFlag_next', IntSort(), IntSort())
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
def Array_Sum(a,k):
	a_sum = 0
	for i in range(k):
		a_sum += a[i]
	return a_sum
def Array_Sum_1(a,k):
	a_sum = 0
	for i in range(k):
		a_sum += a[i]*(2**i)
	return a_sum
s = Solver()      
#####



