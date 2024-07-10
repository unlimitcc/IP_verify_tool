from z3 import *
import numpy as np

#variables
W = []
Gi = []
Gi_next = []
Gi_out = []
Gi_out_next = []
VER_W = Array('VER_W', IntSort(), RealSort())
VER_Gi = Array('VER_Gi', IntSort(), RealSort())
VER_Gi_next = Array('VER_Gi_next', IntSort(), RealSort())
VER_Gi_out = Array('VER_Gi_out', IntSort(), RealSort())
VER_Gi_out_next = Array('VER_Gi_out_next', IntSort(), RealSort())
ctlPeriod =Real('ctlPeriod')
ctlPeriod_next =Real('ctlPeriod_next')
def max(a, b):
    m = If(a>=b, a, b)
    return m
def min(a, b):
    m = If(a>=b, b, a)
    return m
def abs(a):
    m = If(a>=0, a, -a)
    return m
def Array_length(a):
	temp = np.array(a)
	return temp.size
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
#contract

