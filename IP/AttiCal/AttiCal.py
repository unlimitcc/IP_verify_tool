from z3 import *
import numpy as np
#variables
Gi=[]
Gi_next=[]
W=[]
angle=[]
angle_next=[]
rate=[]
rate_next=[]
VER_Gi=Array('VER_Gi',IntSort(),RealSort())
VER_Gi_next=Array('VER_Gi_next',IntSort(),RealSort())
VER_W=Array('VER_W',IntSort(),RealSort())
VER_W_next=Array('VER_W_next',IntSort(),RealSort())
VER_angle=Array('VER_angle',IntSort(),RealSort())
VER_angle_next=Array('VER_angle_next',IntSort(),RealSort())
VER_rate=Array('VER_rate',IntSort(),RealSort())
VER_rate_next=Array('VER_rate_next',IntSort(),RealSort())
workmode=Int('workmode')
flgSP=Int('flgSP')
piyaw=Int('piyaw')
royaw=Int('royaw')
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
#Contract
