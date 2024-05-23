from z3 import *
import numpy as np

#variables
gf = Real('gf')
wt0 = Real('wt0')
wt0_next = Real('wt0_next')
dtime = Real('dtime')
glwd1 = Int('glwd1')
glwd2 = Int('glwd2')
dlwd = Int('dlwd')
status = Int('status')
pRecvbuf = []
VER_pRecvbuf = Array('VER_pRecvbuf',IntSort(),IntSort())
def Array_length(a):
	temp = np.array(a)
	return temp.size
def Array_Size(a): 
	temp = np.array(a)
	return temp.shape
def List2Array(lst, idx=()):
    if isinstance(lst[0], list):
        size = len(lst)
        z3_array = Array('array_' + '_'.join(map(str, idx)), IntSort(), ArraySort(IntSort(), IntSort()))
        constraints = []
        for i in range(size):
            sub_array, sub_constraints = List2Array(lst[i], idx + (i,))
            constraints.extend(sub_constraints)
            constraints.append(z3_array[i] == sub_array)
        return z3_array, constraints
    else:
        size = len(lst)
        z3_array = Array('array_' + '_'.join(map(str, idx)), IntSort(), IntSort())
        constraints = [z3_array[i] == lst[i] for i in range(size)]
        return z3_array, constraints
s = Solver()
########

