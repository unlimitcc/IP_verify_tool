Assumptions = And(Array_length(Gi)==3, Array_length(Gi)<=Array_length(W))
Guarantee1 = And(Array_length(Gi_next)==3)
Guarantee2 = abs(Gi_next[0]-max(-180, min(180, Gi[0]+W[0]*ctlPeriod)))<1e-7
Guarantee3 = abs(Gi_next[1]-max(-180, min(180, Gi[1]+W[1]*ctlPeriod)))<1e-7
Guarantee4 = abs(Gi_next[2]-max(-90, min(90, Gi[2]+W[2]*ctlPeriod)))<1e-7
Guarantee5 = And(ctlPeriod_next==ctlPeriod)
Guarantee0 = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4, Guarantee5)
