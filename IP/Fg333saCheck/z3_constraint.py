Check4 = And(Implies(Array_Sum(pbuff,18)%255==pbuff[18], And(cntCheckO_next==0, cntCheckS_next==0, bComSuc_next==3952088175)), Implies(Array_Sum(pbuff,18)%255!=pbuff[18], And(cntCheckO_next==cntCheckO+1, cntCheckS_next==cntCheckS+1, totalCheckO_next==totalCheckO+1, totalCheckS_next==totalCheckS+1)))
Check3 = And(Implies(And(pbuff[0]==235, pbuff[1]==144), And(cntHeadO_next==0, cntHeadS_next==0, Check4)), Implies(Or(pbuff[0]!=235, pbuff[1]!=144), And(cntHeadO_next==cntHeadO+1, cntHeadS_next==cntHeadS+1, totalHeadO_next==totalHeadO+1, totalHeadS_next==totalHeadS+1)))
Check2 = And(Implies(pbuff[17]!=frm, And(cntUpdataO_next==0, cntUpdataS_next==0, frm_next==pbuff[17], Check3)), Implies(pbuff[17]==frm, And(cntUpdataS_next==cntUpdataS+1, cntUpdataO_next==cntUpdataO+1, totalUpdataO_next==totalUpdataO+1, totalUpdataS_next==totalUpdataS+1)))
Check1 = And(Implies(rdLen==19, And(cntLenRdS_next==0, Check2)), Implies(rdLen!=19, And(cntLenRdS_next==cntLenRdS+1, totalLenRdS_next==totalLenRdS+1, cntLenRdO_next==cntLenRdO+1, totalLenRdO_next==totalLenRdO+1)))
Assumptions = Implies(rdLen==19, Array_length(pbuff)>=19)
Guarantees = And(bComSuc==0, Check1)
s.add(Implies(Assumptions, Guarantees))
s.add(Assumptions)
###
