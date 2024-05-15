from z3 import *

#variables
IWI = Int('IWI')
IGiI = Int('IGiI')
IGiI_next = Int('IGiI_next')
IGi_outI = Int('IGi_outI')
IGi_outI_next = Int('IGi_outI_next')
W = Array('W', IntSort(), RealSort())
Gi = Array('Gi', IntSort(), RealSort())
Gi_next = Array('Gi_next', IntSort(), RealSort())
Gi_out = Array('Gi_out', IntSort(), RealSort())
Gi_out_next = Array('Gi_out_next', IntSort(), RealSort())
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
s = Solver()
#contract
Assumption = And(IWI>=IGiI, IGiI==3)
Guarantee1 = And(IGiI==3)
Guarantee2 = abs(Gi_next[0]-max(-180, min(180, Gi[0]+W[0]*ctlPeriod)))<0.0001
Guarantee3 = abs(Gi_next[1]-max(-180, min(180, Gi[1]+W[1]*ctlPeriod)))<0.0001
Guarantee4 = abs(Gi_next[2]-max(-90, min(90, Gi[2]+W[2]*ctlPeriod)))<0.0001
Guarantee5 = And(ctlPeriod_next==ctlPeriod)
Guarantee = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4, Guarantee5)
s.add(And(Assumption, Implies(Assumption, Guarantee)))
#####

