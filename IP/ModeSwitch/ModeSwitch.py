from z3 import *
import numpy as np

#variables
IpGyroRateI = Int('pGyroRate')
countMode = Int('countMode')
m_workMode = Int('m_workMode')
m_workMode_next = Int('m_workMode_next')
m_countMode = Int('m_countMode')
m_countMode_next = Int('m_countMode_next')
m_countPublic = Int('m_countPublic')
m_countPublic_next = Int('m_countPublic_next')
time_D2P = Int('time_D2P')
time_D2P_overtime = Int('time_D2P_overtime')
flgSP = Int('flgSP')
piyaw = Real('piyaw')
royaw = Real('royaw')
workMode_temp = Int('workMode_temp')
countMode_temp = Int('countMode_temp')
countPublic_temp = Int('countPublic_temp')
pGyroRate = []
VER_pGyroRate = Array('VER_pGyroRate', IntSort(), RealSort())
def MAX(x, y):
    return If(x>=y, x, y)
def TripleFabsMax(x,y,z):
    re = If(abs(x)>=MAX(abs(y),abs(z)), abs(x), MAX(abs(y),abs(z)))
    return re
def abs(x):
    return If(x>=0, x, -1*x)
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
