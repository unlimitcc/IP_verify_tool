G1 = And(Array_length(u)==3, Array_Size(mController_next)==(3,3))
G2 = Implies(Or(workMode==0, workMode==51), And(destRate_next[0]==0,destRate_next[1]==0,destRate_next[2]==destRate[2]))
G3 = Implies(workMode==17, And(destRate_next[0]==0,destRate_next[1]==-0.5,destRate_next[2]==destRate[2]))
G4 = Implies(workMode==34, And(destRate_next[0]==0.5,destRate_next[1]==0,destRate_next[2]==destRate[2]))
G5 = Implies(And(workMode!=0,workMode!=17,workMode!=34,workMode!=51), And(destRate_next==destRate))
G6 = (And(mController_next[0][0]==max(-8,min(pAngle[0],8)),
         mController_next[0][1]-max(-1.2,min(pRate[0]-destRate_next[0],1.2))<0.00001,
         mController_next[0][2]-(mController_next[0][0]*CTRL_PARAM_SAM[0][0]+mController_next[0][1]*CTRL_PARAM_SAM[0][1])<0.00001))

G7 = (And(mController_next[1][0]==max(-8,min(pAngle[1],8)),
         mController_next[1][1]-max(-1.2,min(pRate[1]-destRate_next[1],1.2))<0.000001, 
         mController_next[1][2]-(mController_next[1][0]*CTRL_PARAM_SAM[1][0]+mController_next[1][1]*CTRL_PARAM_SAM[1][1])<0.00001))

G8 = (And(mController_next[2][0]==0,
         mController_next[2][1]-max(-1.2,min(pRate[2],1.2))<0.000001, 
         mController_next[2][2]-mController_next[2][1]*CTRL_PARAM_SAM[2][1]<0.000001))
G9 = ForAll(i, Implies(And(i>=0, i<3), VER_u_next[i]==max(-1.3, min(VER_mController_next[i][2],1.3))))
G10 = (CTRL_PARAM_SAM_next == CTRL_PARAM_SAM)
s.add(And(G1,G2,G3,G4,G5,G6,G7,G8,G9,G10))
