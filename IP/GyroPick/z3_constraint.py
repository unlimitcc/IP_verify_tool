#Contract
Assumptions = And(Array_length(wa)>=9, Array_length(wal)==9, Array_length(countPick)==9)
Guarantee1 = And(Array_length(wa_out_next)>=9, Array_length(wal_next)==9, Array_length(countPick_next)==9)
Guarantee2 = (ForAll(i, Implies(And(i>=0, i<9), Implies(And(abs(VER_wa[i]-VER_wal[i])>waThr, VER_countPick[i]+1<pickThr), And(VER_wa_out_next[i]==VER_wal[i], VER_wal_next[i]==VER_wal[i], VER_countPick_next[i]==VER_countPick[i]+1)))))
Guarantee3 = (ForAll(i, Implies(And(i>=0, i<9), Implies(Or(abs(VER_wa[i]-VER_wal[i])<=waThr, VER_countPick[i]+1>=pickThr), And(VER_wa_out_next[i]==VER_wa[i], VER_wal_next[i]==VER_wa[i], VER_countPick_next[i]==0)))))
Guarantee4 = And(waThr_next==waThr, pickThr_next==pickThr)
Guarantee0 = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4)

