#contract
Assumptions = And(Array_length(pu)>=3, Array_length(r)==3, Array_length(h1)==3)
Guarantee1 = And(Array_length(Yp_next)==3, Array_length(Yn_next)==3, Array_length(r_next)==3, Array_length(h1_next)==3)
Guarantee2 = ForAll(i, Implies(And(i>=0, i<3), Implies(VER_pu[i]-VER_r[i]>VER_h1[i], And(VER_Yp_next[i]==0, VER_Yp_next[i]==15, abs(VER_r_next[i]-(0.9231*VER_r[i]+0.07688))<1e-7))))
Guarantee3 = ForAll(i, Implies(And(i>=0, i<3), Implies(VER_pu[i]-VER_r[i]<VER_h1[i], And(VER_Yp_next[i]==15, VER_Yp_next[i]==0, abs(VER_r_next[i]-(0.9231*VER_r[i]-0.07688))<1e-7))))
Guarantee4 = ForAll(i, Implies(And(i>=0, i<3), 
                               Implies(Or(VER_pu[i]-VER_r[i]<=VER_h1[i],VER_pu[i]-VER_r[i]>=VER_h1[i],), And(VER_Yp_next[i]==0, VER_Yp_next[i]==0, abs(VER_r_next[i]-0.9231*VER_r[i])<1e-7))))
Guarantee5 = And(h1_next[0]==h1[0], h1_next[1]==h1[1], h1_next[2]==h1[2])
Guarantee0 = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4, Guarantee5)
