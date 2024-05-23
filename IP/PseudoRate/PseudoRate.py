from z3 import *
import numpy as np
#variables
pu = []
r = []
r = []
h1 = []
h1_next = []
Yp = []
Yp_next = []
Yn = []
Yn_next = []
i = Int('i')
VER_pu = Array('VER_pu', IntSort(),RealSort())
VER_Yp = Array('VER_Yp', IntSort(),IntSort())
VER_Yp_next = Array('VER_Yp_next', IntSort(),IntSort())
VER_Yn = Array('VER_Yn', IntSort(),IntSort())
VER_Yn_next = Array('VER_Yn_next', IntSort(),IntSort())
VER_r = Array('VER_r', IntSort(), RealSort())
VER_r_next = Array('VER_r_next', IntSort(), RealSort())
VER_h1 = Array('VER_h1', IntSort(), RealSort())
VER_h1_next = Array('VER_h1_next', IntSort(), RealSort())
def Array_length(a):
	temp = np.array(a)
	return temp.size
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
#####
