from z3 import *

#variables
IwaI = Int('IwaI')
IwalI = Int('IwalI')
IcountPickI = Int('IcountPickI')
Iwa_outI = Int('Iwa_outI')
IwaI_next = Int('IwaI_next')
IwalI_next = Int('IwalI_next')
IcountPickI_next = Int('IcountPickI_next')
Iwa_outI_next = Int('Iwa_outI_next')
wa = Array('wa', IntSort(), RealSort())
wal = Array('wal', IntSort(), RealSort())
wal_next = Array('wal_next', IntSort(), RealSort())
wa_out = Array('wa_out', IntSort(), RealSort())
wa_out_next = Array('wa_out_next', IntSort(), RealSort())
countPick = Array('countPick', IntSort(), IntSort())
countPick_next = Array('countPick_next', IntSort(), IntSort())
waThr = Real('waThr')
pickThr = Int('pickThr')
waThr_next = Real('waThr_next')
pickThr_next = Int('pickThr_next')
abs = Function('abs', RealSort(), RealSort())
i = Int('i')
j = Ints('j')
x = Real('x')

s = Solver()
#s.add(waThr == 0.08)
#s.add(pickThr == 6)
s.add(Implies(x<0, abs(x)==-1*x))
s.add(Implies(x>=0, abs(x)==x))
#Contract
Assumptions = And(IwaI>=9, IwalI==9, IcountPickI==9)
G1 = And(Iwa_outI_next>=9, IwalI_next==9, IcountPickI_next==9)
G2 = (ForAll(i, Implies(And(i>=0, i<1), Implies(And(abs(wa[i]-wal[i])>waThr, countPick[i]+1<pickThr), And(wa_out_next[i]==wal[i], wal_next[i]==wal[i], countPick_next[i]==countPick[i]+1)))))
G3 = (ForAll(i, Implies(And(i>=0, i<1), Implies(Or(abs(wa[i]-wal[i])<=waThr, countPick[i]+1>=pickThr), And(wa_out_next[i]==wa[i], wal_next[i]==wa[i], countPick_next[i]==0)))))
G4 = And(waThr_next==waThr, pickThr_next==pickThr)
Guarantees = And(G1, G2, G3, G4)
s.add(Implies(Assumptions, Guarantees))
s.add(Assumptions)
#######