Assumptions = And(Array_length(Gi)==2, Array_length(W)==3)
Guarantee1 = And(Array_length(angle_next)==2, Array_length(Gi_next)==2, Array_length(rate_next)==3)
Guarantee2 = Implies(workmode==51, Implies(flgSP==235, And(angle_next[0]==royaw, angle_next[1]==piyaw, Gi_next[0]==royaw, Gi_next[1]==piyaw)))
Guarantee3 = Implies(workmode==51, Implies(flgSP!=235, And(angle_next[0]==Gi[0], angle_next[1]==Gi[1], Gi_next[0]==Gi[0], Gi_next[1]==Gi[1])))
Guarantee4 = Implies(workmode!=51, And(angle_next[0]==0, angle_next[1]==0, Gi_next[0]==Gi[0], Gi_next[1]==Gi[1]))
Guarantee5 = And(rate_next[0]==W[0], rate_next[1]==W[1], rate_next[2]==W[2])
Guarantee0 = And(Guarantee1,Guarantee2,Guarantee3,Guarantee4,Guarantee5)
########
