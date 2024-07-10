from z3 import *
import numpy as np


#variables
wa = []
wal = []
wal_next = []
wa_out = []
wa_out_next = []
countPick = []
countPick_next = []
VER_wa = Array('VER_wa', IntSort(), RealSort())
VER_wal = Array('VER_wal', IntSort(), RealSort())
VER_wal_next = Array('VER_wal_next', IntSort(), RealSort())
VER_wa_out = Array('VER_wa_out', IntSort(), RealSort())
VER_wa_out_next = Array('VER_wa_out_next', IntSort(), RealSort())
VER_countPick = Array('VER_countPick', IntSort(), IntSort())
VER_countPick_next = Array('VER_countPick_next', IntSort(), IntSort())
waThr = Real('waThr')
pickThr = Int('pickThr')
waThr_next = Real('waThr_next')
pickThr_next = Int('pickThr_next')
i = Int('i')
j = Ints('j')
def abs(a):
    return If(a>=0, a, -1*a)
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
#######



