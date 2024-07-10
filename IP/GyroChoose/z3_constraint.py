s.add(ForAll(i, Implies(And(i>=0, i<9), sum_temp(i)==sum_temp(i-1)+VER_tempFlag_next[i])))
s.add(sum_temp(-1)==0)
Assumptions = (Array_length(StateFlag)>=9)
Guarantee1 = And(Array_length(SignFlag_next)==9, Array_length(tempFlag)==9)
Guarantee2 = (ForAll(i, Implies(And(i>=0, i<9), Implies(VER_StateFlag[i]!=1, VER_tempFlag_next[i]==0))))
Guarantee3 = (ForAll(i, Implies(And(i>=0, i<9), Implies(VER_StateFlag[i]==1, VER_tempFlag_next[i]==1))))
Guarantee4 = (JoinTotal_next == Array_Sum(VER_tempFlag_next,9))
Guarantee5 = (ForAll(i, Implies(And(i>=0, i<JoinTotal_next), 
                        Exists(k, And(VER_SignFlag_next[i]==k, sum_temp(k)==i, Not(Exists(k1, And(k1<k, VER_SignFlag_next[i]==k1, sum_temp(k1)==i))))))))
Guarantee6 = (ForAll(i, Implies(And(i>=JoinTotal_next, i<9), VER_SignFlag_next[i]==0)))
Guarantee7 = (gyroStatus0_next == Array_Sum_1(VER_tempFlag_next,9))
Guarantee0 = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4, Guarantee5, Guarantee6, Guarantee7)

