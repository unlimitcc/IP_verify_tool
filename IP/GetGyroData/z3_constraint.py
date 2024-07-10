s.add(mask==4095, offset==2048, pa1==4080, pa2==15)
Assumptions = And(Array_length(chnl)==9, Array_length(type)==9)
Guarantee1 = ForAll(i, Implies(And(i>=0, i<9), Implies(VER_type[i]==0, 
     (VER_wa_next[i]-If(((cal_wd(hi8,lo4) & mask)-offset)<0, -1*BV2Int(65536-((cal_wd(hi8,lo4) & mask)-offset))*0.00162760417, BV2Int((cal_wd(hi8,lo4) & mask)-offset)*0.00162760417))<1e-7)))
Guarantee2 = ForAll(i, Implies(And(i>=0, i<9), Implies(VER_type[i]!=0, 
     (VER_wa_next[i]-If(((cal_wd(hi8,lo4) & mask)-offset)<0, -1*BV2Int(65536-((cal_wd(hi8,lo4) & mask)-offset))*0.0009765625, BV2Int((cal_wd(hi8,lo4) & mask)-offset)*0.00162760417))<1e-7)))
Guarantee3 = And(ADDR_AD_START_next==ADDR_AD_START, AD_GYRO_LO4_next==AD_GYRO_LO4, AD_GYRO_HI8_next==AD_GYRO_HI8)
Guarantee4 = (ForAll(i, Implies(And(i>=0, i<9), VER_chnl_next[i]==VER_chnl[i])))
Guarantee5 = (ForAll(i, Implies(And(i>=0, i<9), VER_type_next[i]==VER_type[i])))
Guarantee0 = And(Guarantee1, Guarantee2, Guarantee3, Guarantee4, Guarantee5)

