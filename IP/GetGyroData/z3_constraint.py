Assumption = And(Array_length(chnl)==9, Array_length(type)==9)
G1 = ForAll(i, Implies(And(i>=0, i<9), Implies(VER_type[i]==0, 
     (VER_wa_next[i]-If(((cal_wd(hi8,lo4) & mask)-offset)<0, -1*BV2Int(65536-((cal_wd(hi8,lo4) & mask)-offset))*0.00162760417, BV2Int((cal_wd(hi8,lo4) & mask)-offset)*0.00162760417))<1e-7)))
G2 = ForAll(i, Implies(And(i>=0, i<9), Implies(VER_type[i]!=0, 
     (VER_wa_next[i]-If(((cal_wd(hi8,lo4) & mask)-offset)<0, -1*BV2Int(65536-((cal_wd(hi8,lo4) & mask)-offset))*0.0009765625, BV2Int((cal_wd(hi8,lo4) & mask)-offset)*0.00162760417))<1e-7)))
G3 = And(ADDR_AD_START_next==ADDR_AD_START, AD_GYRO_LO4_next==AD_GYRO_LO4, AD_GYRO_HI8_next==AD_GYRO_HI8)
G4 = (chnl_next==chnl)
G5 = (type_next==type)
Guarantee = And(G1, G2, G3, G4, G5)
s.add(mask==4095, offset==2048, pa1==4080, pa2==15)
s.add(And(Assumption, Implies(Assumption, Guarantee)))
