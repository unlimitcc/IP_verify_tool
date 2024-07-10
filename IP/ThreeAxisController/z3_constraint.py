Assumptions = And(Array_length(pAngle)>=2, Array_length(pRate)>=3, Array_length(destRate)==3, Array_Size(mController)==(3,3), Array_Size(CTRL_PARAM_SAM)==(3,2))
Guarantee1 = And(Array_length(u)==3, Array_Size(mController_next)==(3,3))
Guarantee2 = Implies(Or(workMode==0, workMode==51), And(destRate_next[0]==0,destRate_next[1]==0,destRate_next[2]==destRate[2]))
Guarantee3 = Implies(workMode==17, And(destRate_next[0]==0,destRate_next[1]==-0.5,destRate_next[2]==destRate[2]))
Guarantee4 = Implies(workMode==34, And(destRate_next[0]==0.5,destRate_next[1]==0,destRate_next[2]==destRate[2]))
Guarantee5 = Implies(And(workMode!=0,workMode!=17,workMode!=34,workMode!=51), And(destRate_next==destRate))
Guarantee6 = (And(mController_next[0][0]==max(-8,min(pAngle[0],8)),
         abs(mController_next[0][1]-max(-1.2,min(pRate[0]-destRate_next[0],1.2)))<1e-7,
         abs(mController_next[0][2]-(mController_next[0][0]*CTRL_PARAM_SAM[0][0]+mController_next[0][1]*CTRL_PARAM_SAM[0][1]))<1e-7))

Guarantee7 = (And(mController_next[1][0]==max(-8,min(pAngle[1],8)),
         abs(mController_next[1][1]-max(-1.2,min(pRate[1]-destRate_next[1],1.2)))<1e-7, 
         abs(mController_next[1][2]-(mController_next[1][0]*CTRL_PARAM_SAM[1][0]+mController_next[1][1]*CTRL_PARAM_SAM[1][1]))<1e-7))

Guarantee8 = (And(mController_next[2][0]==0,
         abs(mController_next[2][1]-max(-1.2,min(pRate[2],1.2)))<1e-7, 
         abs(mController_next[2][2]-mController_next[2][1]*CTRL_PARAM_SAM[2][1])<1e-7))
Guarantee9 = ForAll(i, Implies(And(i>=0, i<3), VER_u_next[i]==max(-1.3, min(VER_mController_next[i][2],1.3))))
Guarantee10 = (CTRL_PARAM_SAM_next == CTRL_PARAM_SAM)
Guarantee0 = And(Guarantee1,Guarantee2,Guarantee3,Guarantee4,Guarantee5,Guarantee6,Guarantee7,Guarantee8,Guarantee9,Guarantee10)
