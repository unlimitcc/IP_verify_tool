from z3 import *
import numpy as np

#variables
chnl = []
chnl_next = []
type = []
type_next = []
wa = []
wa_next = []
ADDR_AD_START = Int('ADDR_AD_START')
ADDR_AD_START_next = Int('ADDR_AD_START_next')
AD_GYRO_LO4 = Int('AD_SS_LO4')
AD_GYRO_LO4_next = Int('AD_SS_LO4_next')
AD_GYRO_HI8 = Int('AD_SS_HI8')
AD_GYRO_HI8_next = Int('AD_SS_HI8_next')
VER_chnl = Array('VER_chnl', IntSort(), IntSort())
VER_chnl_next = Array('VER_chnl_next', IntSort(), IntSort())
VER_type = Array('VER_type', IntSort(), IntSort())
VER_type_next = Array('VER_type_next', IntSort(), IntSort())
VER_wa = Array('VER_wa', IntSort(), RealSort())
VER_wa_next = Array('VER_wa_next',IntSort(), RealSort())
i = Int('i')
######
hi8 = BitVec('hi8', 16)
lo4 = BitVec('lo4', 16)
mask = BitVec('mask', 16)
offset = BitVec('offset', 16)
pa1 = BitVec('p1', 16)
pa2 = BitVec('p2', 16)
wd = BitVec('wd', 16)
def cal_wd(hi8, lo4):
    wd = ((hi8<<4)&pa1) | ((lo4>>4)&pa2)
    return wd
def abs(x):
    return If(x>=0, x, -1*x)
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
