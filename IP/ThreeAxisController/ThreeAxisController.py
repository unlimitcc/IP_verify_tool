from z3 import *
import numpy as np

VER_mController = Array('VER_SController', IntSort(), ArraySort(IntSort(), RealSort()))
VER_mController_next = Array('VER_SController_next', IntSort(), ArraySort(IntSort(), RealSort()))
#mController
#mController[i][0] = Up mController[i][1] = Ud  mController[i][2] = fy    
VER_CTRL_PARAM_SAM = Array('VER_SControllerParam', IntSort(), ArraySort(IntSort(), RealSort()))
#CTRL_PARAM_SAM
#CTRL_PARAM_SAM[i][0] = Kp CTRL_PARAM_SAM[i][1] = Kd    
workMode = Int('workMode')
i = Int('i')
VER_u = Array('VER_u', IntSort(), RealSort())
VER_u_next = Array('VER_u_next', IntSort(), RealSort())
mController = []
mController_next = []
CTRL_PARAM_SAM = []
CTRL_PARAM_SAM_next = []
u = []
u_next = []
pAngle = []
pRate = []
destRate = []
destRate_next = []
######
def max(x,y):
    return If(x<y,y,x)
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
######
