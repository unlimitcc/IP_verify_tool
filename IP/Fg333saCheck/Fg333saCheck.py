from z3 import *
import numpy as np
#variables
pbuff = []
VER_pbuff = Array('VER_pbuff', IntSort(), IntSort())
rdLen = Int('rdLen')
bComSuc = Int('bComSuc')
bComSuc_next = Int('bComSuc_next')
cntLenRdS = Int('cntLenRdS')
cntLenRdS_next = Int('cntLenRdS_next')
totalLenRdS = Int('totalLenRdS')
totalLenRdS_next = Int('totalLenRdS_next')
cntLenRdO = Int('cntLenRdO')
cntLenRdO_next = Int('cntLenRdO_next')
totalLenRdO = Int('totalLenRdO')
totalLenRdO_next = Int('totalLenRdO_next')
frm = Int('frm')
frm_next = Int('frm_next')
cntCheckO = Int('cntCheckO')
cntCheckO_next = Int('cntCheckO_next')
cntCheckS = Int('cntCheckS')
cntCheckS_next = Int('cntCheckS_next')
cntHeadO = Int('cntHeadO')
cntHeadO_next = Int('cntHeadO_next')
cntHeadS = Int('cntHeadS')
cntHeadS_next = Int('cntHeadS_next')
cntUpdataO = Int('cntUpdataO')
cntUpdataO_next = Int('cntUpdataO_next')
cntUpdataS = Int('cntUpdataS')
cntUpdataS_next = Int('cntUpdataS_next')
totalCheckO = Int('totalCheckO')
totalCheckO_next = Int('totalCheckO_next')
totalCheckS = Int('totalCheckS')
totalCheckS_next = Int('totalCheckS_next')
totalHeadO = Int('totalHeadO')
totalHeadO_next = Int('totalHeadO_next')
totalHeadS = Int('totalHeadS')
totalHeadS_next = Int('totalHeadS_next')
totalUpdataO = Int('totalUpdataO')
totalUpdataO_next = Int('totalUpdataO_next')
totalUpdataS = Int('totalUpdataS')
totalUpdataS_next = Int('totalUpdataS_next')
def Array_Sum(a,k):
	temp = 0
	for i in range(k):
		temp += a[i]
	return temp
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
