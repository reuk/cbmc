void __builtin_ia32_emms(void);
__gcc_v2si __builtin_ia32_pmaddwd(__gcc_v4hi, __gcc_v4hi);
__gcc_v2si __builtin_ia32_vec_init_v2si(int, int);
__gcc_v4hi __builtin_ia32_vec_init_v4hi(short, short, short, short);
__gcc_v8qi
__builtin_ia32_vec_init_v8qi(char, char, char, char, char, char, char, char);
int __builtin_ia32_vec_ext_v2si(__gcc_v2si, int);
__gcc_v8hi __builtin_ia32_paddusw128(__gcc_v8hi, __gcc_v8hi);
__gcc_v8hi __builtin_ia32_psubusw128(__gcc_v8hi, __gcc_v8hi);
void __builtin_ia32_ldmxcsr(unsigned);
unsigned __builtin_ia32_stmxcsr(void);
__gcc_v8hi __builtin_ia32_paddsw128(__gcc_v8hi, __gcc_v8hi);
__gcc_v8hi __builtin_ia32_psubsw128(__gcc_v8hi, __gcc_v8hi);
__gcc_v16qi __builtin_ia32_paddsb128(__gcc_v16qi, __gcc_v16qi);
__gcc_v16qi __builtin_ia32_psubsb128(__gcc_v16qi, __gcc_v16qi);
__gcc_v16qi __builtin_ia32_paddusb128(__gcc_v16qi, __gcc_v16qi);
__gcc_v16qi __builtin_ia32_psubusb128(__gcc_v16qi, __gcc_v16qi);
__gcc_di __builtin_ia32_cvtss2si64(__gcc_v4sf);
__gcc_di __builtin_ia32_cvttss2si64(__gcc_v4sf);
__gcc_v4sf __builtin_ia32_cvtsi642ss(__gcc_v4sf, __gcc_di);

__gcc_v4hi __builtin_ia32_pshufw(__gcc_v4hi, int);
short __builtin_ia32_vec_ext_v4hi(__gcc_v4hi, int);
short __builtin_ia32_vec_ext_v8hi(__gcc_v8hi, int);
__gcc_v4hi __builtin_ia32_vec_set_v4hi(__gcc_v4hi, short, int);
__gcc_v8hi __builtin_ia32_vec_set_v8hi(__gcc_v8hi, short, int);
__gcc_v4sf __builtin_ia32_vec_set___gcc_v4sf(__gcc_v4sf, float, const int);
__gcc_v16qi __builtin_ia32_vec_set___gcc_v16qi(__gcc_v16qi, int, const int);
__gcc_v4si __builtin_ia32_vec_set___gcc_v4si(__gcc_v4si, int, const int);
__gcc_v2di __builtin_ia32_vec_set___gcc_v2di(__gcc_v2di, __gcc_di, const int);
char __builtin_ia32_vec_ext_v16qi(__gcc_v16qi, int);
__gcc_v16qi __builtin_ia32_vec_set_v16qi(__gcc_v16qi, char, int);
__gcc_v4si __builtin_ia32_vec_set_v4si(__gcc_v4si, int, int);
__gcc_v2di __builtin_ia32_vec_set_v2di(__gcc_v2di, __gcc_di, int);

unsigned long long __builtin_ia32_rdtsc(void);
unsigned long long __builtin_ia32_rdtscp(unsigned *);
void __builtin_ia32_fnstenv(void *);
void __builtin_ia32_fldenv(const void *);
unsigned short __builtin_ia32_fnstsw(void);
void __builtin_ia32_fnclex(void);
void __builtin_ia32_fxsave(void *);
void __builtin_ia32_fxrstor(void *);
void __builtin_ia32_xsave(void *, long long);
void __builtin_ia32_xrstor(void *, long long);
void __builtin_ia32_xsaveopt(void *, long long);
void __builtin_ia32_xsaves(void *, long long);
void __builtin_ia32_xrstors(void *, long long);
void __builtin_ia32_xsavec(void *, long long);
void __builtin_ia32_fxsave64(void *);
void __builtin_ia32_fxrstor64(void *);
void __builtin_ia32_xsave64(void *, long long);
void __builtin_ia32_xrstor64(void *, long long);
void __builtin_ia32_xsaveopt64(void *, long long);
void __builtin_ia32_xsaves64(void *, long long);
void __builtin_ia32_xrstors64(void *, long long);
void __builtin_ia32_xsavec64(void *, long long);
void __builtin_ia32_movntdq256(__gcc_v4di *, __gcc_v4di);
void __builtin_ia32_movntpd256(double *, __gcc_v4df);
void __builtin_ia32_movntps256(float *, __gcc_v8sf);
void __builtin_ia32_compressstoresf512_mask(__gcc_v16sf *, __gcc_v16sf, short);
void __builtin_ia32_compressstoresi512_mask(__gcc_v16si *, __gcc_v16si, short);
void __builtin_ia32_compressstoredf512_mask(__gcc_v8df *, __gcc_v8df, char);
void __builtin_ia32_compressstoredi512_mask(__gcc_v8di *, __gcc_v8di, char);
__gcc_v16sf
__builtin_ia32_expandloadsf512_mask(const __gcc_v16sf *, __gcc_v16sf, short);
__gcc_v16sf
__builtin_ia32_expandloadsf512_maskz(const __gcc_v16sf *, __gcc_v16sf, short);
__gcc_v16si
__builtin_ia32_expandloadsi512_mask(const __gcc_v16si *, __gcc_v16si, short);
__gcc_v16si
__builtin_ia32_expandloadsi512_maskz(const __gcc_v16si *, __gcc_v16si, short);
__gcc_v8df
__builtin_ia32_expandloaddf512_mask(const __gcc_v8df *, __gcc_v8df, char);
__gcc_v8df
__builtin_ia32_expandloaddf512_maskz(const __gcc_v8df *, __gcc_v8df, char);
__gcc_v8di
__builtin_ia32_expandloaddi512_mask(const __gcc_v8di *, __gcc_v8di, char);
__gcc_v8di
__builtin_ia32_expandloaddi512_maskz(const __gcc_v8di *, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_loaddqusi512_mask(const __gcc_v16si *, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_loaddqudi512_mask(const __gcc_v8di *, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_loadupd512_mask(const __gcc_v8df *, __gcc_v8df, char);
__gcc_v16sf
__builtin_ia32_loadups512_mask(const __gcc_v16sf *, __gcc_v16sf, short);
__gcc_v16sf
__builtin_ia32_loadaps512_mask(const __gcc_v16sf *, __gcc_v16sf, short);
__gcc_v16si
__builtin_ia32_movdqa32load512_mask(const __gcc_v16si *, __gcc_v16si, short);
__gcc_v8df __builtin_ia32_loadapd512_mask(const __gcc_v8df *, __gcc_v8df, char);
__gcc_v8di
__builtin_ia32_movdqa64load512_mask(const __gcc_v8di *, __gcc_v8di, char);
void __builtin_ia32_movntps512(float *, __gcc_v16sf);
void __builtin_ia32_movntpd512(double *, __gcc_v8df);
void __builtin_ia32_movntdq512(__gcc_v8di *, __gcc_v8di);
__gcc_v8di __builtin_ia32_movntdqa512(__gcc_v8di *);
void __builtin_ia32_storedqusi512_mask(__gcc_v16si *, __gcc_v16si, short);
void __builtin_ia32_storedqudi512_mask(__gcc_v8di *, __gcc_v8di, char);
void __builtin_ia32_storeupd512_mask(__gcc_v8df *, __gcc_v8df, char);
void __builtin_ia32_pmovusqd512mem_mask(__gcc_v8si *, __gcc_v8di, char);
void __builtin_ia32_pmovsqd512mem_mask(__gcc_v8si *, __gcc_v8di, char);
void __builtin_ia32_pmovqd512mem_mask(__gcc_v8si *, __gcc_v8di, char);
void __builtin_ia32_pmovusqw512mem_mask(__gcc_v8hi *, __gcc_v8di, char);
void __builtin_ia32_pmovsqw512mem_mask(__gcc_v8hi *, __gcc_v8di, char);
void __builtin_ia32_pmovqw512mem_mask(__gcc_v8hi *, __gcc_v8di, char);
void __builtin_ia32_pmovusdw512mem_mask(__gcc_v16hi *, __gcc_v16si, short);
void __builtin_ia32_pmovsdw512mem_mask(__gcc_v16hi *, __gcc_v16si, short);
void __builtin_ia32_pmovdw512mem_mask(__gcc_v16hi *, __gcc_v16si, short);
void __builtin_ia32_pmovqb512mem_mask(__gcc_v16qi *, __gcc_v8di, char);
void __builtin_ia32_pmovusqb512mem_mask(__gcc_v16qi *, __gcc_v8di, char);
void __builtin_ia32_pmovsqb512mem_mask(__gcc_v16qi *, __gcc_v8di, char);
void __builtin_ia32_pmovusdb512mem_mask(__gcc_v16qi *, __gcc_v16si, short);
void __builtin_ia32_pmovsdb512mem_mask(__gcc_v16qi *, __gcc_v16si, short);
void __builtin_ia32_pmovdb512mem_mask(__gcc_v16qi *, __gcc_v16si, short);
void __builtin_ia32_storeups512_mask(__gcc_v16sf *, __gcc_v16sf, short);
void __builtin_ia32_storeaps512_mask(__gcc_v16sf *, __gcc_v16sf, short);
void __builtin_ia32_movdqa32store512_mask(__gcc_v16si *, __gcc_v16si, short);
void __builtin_ia32_storeapd512_mask(__gcc_v8df *, __gcc_v8df, char);
void __builtin_ia32_movdqa64store512_mask(__gcc_v8di *, __gcc_v8di, char);
void __builtin_ia32_llwpcb(void *);
void *__builtin_ia32_slwpcb(void);
void __builtin_ia32_wrfsbase32(unsigned);
void __builtin_ia32_wrfsbase64(unsigned long long);
void __builtin_ia32_wrgsbase32(unsigned);
void __builtin_ia32_wrgsbase64(unsigned long long);
unsigned __builtin_ia32_xbegin(void);
void __builtin_ia32_xend(void);
void __builtin_ia32_xabort(unsigned);
int __builtin_ia32_xtest(void);
int __builtin_ia32_bsrsi(int);
long long __builtin_ia32_bsrdi(long long);
unsigned long long __builtin_ia32_rdpmc(int);
unsigned char __builtin_ia32_rolqi(unsigned char, int);
unsigned short __builtin_ia32_rolhi(unsigned short, int);
unsigned char __builtin_ia32_rorqi(unsigned char, int);
unsigned short __builtin_ia32_rorhi(unsigned short, int);
__gcc_v2si __builtin_ia32_pfrsqit1(__gcc_v2sf, __gcc_v2sf);
__gcc_v4sf __builtin_ia32_sqrtps_nr(__gcc_v4sf);
__gcc_v4sf __builtin_ia32_rsqrtps_nr(__gcc_v4sf);
__gcc_v4sf __builtin_ia32_copysignps(__gcc_v4sf, __gcc_v4sf);
float __builtin_ia32_rsqrtf(float);
__gcc_v2df __builtin_ia32_copysignpd(__gcc_v2df, __gcc_v2df);
__gcc_v4si __builtin_ia32_vec_pack_sfix(__gcc_v2df, __gcc_v2df);
__gcc_v2df __builtin_ia32_floorpd(__gcc_v2df, const int);
__gcc_v2df __builtin_ia32_ceilpd(__gcc_v2df, const int);
__gcc_v2df __builtin_ia32_truncpd(__gcc_v2df, const int);
__gcc_v2df __builtin_ia32_rintpd(__gcc_v2df, const int);
__gcc_v4si
__builtin_ia32_floorpd_vec_pack_sfix(__gcc_v2df, __gcc_v2df, const int);
__gcc_v4si
__builtin_ia32_ceilpd_vec_pack_sfix(__gcc_v2df, __gcc_v2df, const int);
__gcc_v2df __builtin_ia32_roundpd_az(__gcc_v2df);
__gcc_v4si __builtin_ia32_roundpd_az_vec_pack_sfix(__gcc_v2df, __gcc_v2df);
__gcc_v4sf __builtin_ia32_floorps(__gcc_v4sf, const int);
__gcc_v4sf __builtin_ia32_ceilps(__gcc_v4sf, const int);
__gcc_v4sf __builtin_ia32_truncps(__gcc_v4sf, const int);
__gcc_v4sf __builtin_ia32_rintps(__gcc_v4sf, const int);
__gcc_v4si __builtin_ia32_floorps_sfix(__gcc_v4sf, const int);
__gcc_v4si __builtin_ia32_ceilps_sfix(__gcc_v4sf, const int);
__gcc_v4sf __builtin_ia32_roundps_az(__gcc_v4sf);
__gcc_v4si __builtin_ia32_roundps_az_sfix(__gcc_v4sf);
__gcc_v4df __builtin_ia32_floorpd256(__gcc_v4df, const int);
__gcc_v4df __builtin_ia32_ceilpd256(__gcc_v4df, const int);
__gcc_v4df __builtin_ia32_truncpd256(__gcc_v4df, const int);
__gcc_v4df __builtin_ia32_rintpd256(__gcc_v4df, const int);
__gcc_v4df __builtin_ia32_roundpd_az256(__gcc_v4df);
__gcc_v8si __builtin_ia32_roundpd_az_vec_pack_sfix256(__gcc_v4df, __gcc_v4df);
__gcc_v8si
__builtin_ia32_floorpd_vec_pack_sfix256(__gcc_v4df, __gcc_v4df, const int);
__gcc_v8si
__builtin_ia32_ceilpd_vec_pack_sfix256(__gcc_v4df, __gcc_v4df, const int);
__gcc_v8sf __builtin_ia32_floorps256(__gcc_v8sf, const int);
__gcc_v8sf __builtin_ia32_ceilps256(__gcc_v8sf, const int);
__gcc_v8sf __builtin_ia32_truncps256(__gcc_v8sf, const int);
__gcc_v8sf __builtin_ia32_rintps256(__gcc_v8sf, const int);
__gcc_v8si __builtin_ia32_floorps_sfix256(__gcc_v8sf, const int);
__gcc_v8si __builtin_ia32_ceilps_sfix256(__gcc_v8sf, const int);
__gcc_v8sf __builtin_ia32_roundps_az256(__gcc_v8sf);
__gcc_v8si __builtin_ia32_roundps_az_sfix256(__gcc_v8sf);
__gcc_v8sf __builtin_ia32_copysignps256(__gcc_v8sf, __gcc_v8sf);
__gcc_v4df __builtin_ia32_copysignpd256(__gcc_v4df, __gcc_v4df);
__gcc_v4di __builtin_ia32_psllv4di(__gcc_v4di, __gcc_v4di);
__gcc_v2di __builtin_ia32_psllv2di(__gcc_v2di, __gcc_v2di);
__gcc_v8si __builtin_ia32_psllv8si(__gcc_v8si, __gcc_v8si);
__gcc_v4si __builtin_ia32_psllv4si(__gcc_v4si, __gcc_v4si);
__gcc_v8si __builtin_ia32_psrav8si(__gcc_v8si, __gcc_v8si);
__gcc_v4si __builtin_ia32_psrav4si(__gcc_v4si, __gcc_v4si);
__gcc_v4di __builtin_ia32_psrlv4di(__gcc_v4di, __gcc_v4di);
__gcc_v2di __builtin_ia32_psrlv2di(__gcc_v2di, __gcc_v2di);
__gcc_v8si __builtin_ia32_psrlv8si(__gcc_v8si, __gcc_v8si);
__gcc_v4si __builtin_ia32_psrlv4si(__gcc_v4si, __gcc_v4si);
unsigned short __builtin_clzs(unsigned short);
unsigned short __builtin_ctzs(unsigned short);
__gcc_v4sf __builtin_ia32_vcvtph2ps(__gcc_v8hi);
__gcc_v8sf __builtin_ia32_vcvtph2ps256(__gcc_v8hi);
__gcc_v8hi __builtin_ia32_vcvtps2ph(__gcc_v4sf, int);
__gcc_v8hi __builtin_ia32_vcvtps2ph256(__gcc_v8sf, int);
unsigned __builtin_ia32_bzhi_si(unsigned, unsigned);
unsigned long long
__builtin_ia32_bzhi_di(unsigned long long, unsigned long long);
unsigned __builtin_ia32_pdep_si(unsigned, unsigned);
unsigned long long
__builtin_ia32_pdep_di(unsigned long long, unsigned long long);
unsigned __builtin_ia32_pext_si(unsigned, unsigned);
unsigned long long
__builtin_ia32_pext_di(unsigned long long, unsigned long long);
__gcc_v16si __builtin_ia32_alignd512_mask(
  __gcc_v16si,
  __gcc_v16si,
  int,
  __gcc_v16si,
  short);
__gcc_v8di
__builtin_ia32_alignq512_mask(__gcc_v8di, __gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_blendmd_512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8df __builtin_ia32_blendmpd_512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_blendmps_512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v8di __builtin_ia32_blendmq_512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16sf __builtin_ia32_broadcastf32x4_512(__gcc_v4sf, __gcc_v16sf, short);
__gcc_v8df __builtin_ia32_broadcastf64x4_512(__gcc_v4df, __gcc_v8df, char);
__gcc_v16si __builtin_ia32_broadcasti32x4_512(__gcc_v4si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_broadcasti64x4_512(__gcc_v4di, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_broadcastsd512(__gcc_v2df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_broadcastss512(__gcc_v4sf, __gcc_v16sf, short);
short __builtin_ia32_cmpd512_mask(__gcc_v16si, __gcc_v16si, int, short);
char __builtin_ia32_cmpq512_mask(__gcc_v8di, __gcc_v8di, int, char);
__gcc_v8df __builtin_ia32_compressdf512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_compresssf512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v8df __builtin_ia32_cvtdq2pd512_mask(__gcc_v8si, __gcc_v8df, char);
__gcc_v16hi
__builtin_ia32_vcvtps2ph512_mask(__gcc_v16sf, int, __gcc_v16hi, short);
__gcc_v8df __builtin_ia32_cvtudq2pd512_mask(__gcc_v8si, __gcc_v8df, char);
__gcc_v2df __builtin_ia32_cvtusi2sd32(__gcc_v2df, unsigned);
__gcc_v8df __builtin_ia32_expanddf512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v8df __builtin_ia32_expanddf512_maskz(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_expandsf512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v16sf __builtin_ia32_expandsf512_maskz(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v4sf __builtin_ia32_extractf32x4_mask(__gcc_v16sf, int, __gcc_v4sf, char);
__gcc_v4df __builtin_ia32_extractf64x4_mask(__gcc_v8df, int, __gcc_v4df, char);
__gcc_v4si __builtin_ia32_extracti32x4_mask(__gcc_v16si, int, __gcc_v4si, char);
__gcc_v4di __builtin_ia32_extracti64x4_mask(__gcc_v8di, int, __gcc_v4di, char);
__gcc_v16sf __builtin_ia32_insertf32x4_mask(
  __gcc_v16sf,
  __gcc_v4sf,
  int,
  __gcc_v16sf,
  short);
__gcc_v8df
__builtin_ia32_insertf64x4_mask(__gcc_v8df, __gcc_v4df, int, __gcc_v8df, char);
__gcc_v16si __builtin_ia32_inserti32x4_mask(
  __gcc_v16si,
  __gcc_v4si,
  int,
  __gcc_v16si,
  short);
__gcc_v8di
__builtin_ia32_inserti64x4_mask(__gcc_v8di, __gcc_v4di, int, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_movapd512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_movaps512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v8df __builtin_ia32_movddup512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16si __builtin_ia32_movdqa32_512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_movdqa64_512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16sf __builtin_ia32_movshdup512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v16sf __builtin_ia32_movsldup512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v16si __builtin_ia32_pabsd512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_pabsq512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_paddd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_paddq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pandd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v16si
__builtin_ia32_pandnd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pandnq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v8di
__builtin_ia32_pandq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_pbroadcastd512(__gcc_v4si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_pbroadcastd512_gpr_mask(int, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_broadcastmb512(char);
__gcc_v16si __builtin_ia32_broadcastmw512(short);
__gcc_v8di __builtin_ia32_pbroadcastq512(__gcc_v2di, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_pbroadcastq512_gpr_mask(long long, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_pbroadcastq512_mem_mask(long long, __gcc_v8di, char);
short __builtin_ia32_pcmpeqd512_mask(__gcc_v16si, __gcc_v16si, short);
char __builtin_ia32_pcmpeqq512_mask(__gcc_v8di, __gcc_v8di, char);
short __builtin_ia32_pcmpgtd512_mask(__gcc_v16si, __gcc_v16si, short);
char __builtin_ia32_pcmpgtq512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_compresssi512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_compressdi512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_expandsi512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_expandsi512_maskz(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_expanddi512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_expanddi512_maskz(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pmaxsd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pmaxsq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pmaxud512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pmaxuq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pminsd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pminsq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pminud512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pminuq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16qi __builtin_ia32_pmovdb512_mask(__gcc_v16si, __gcc_v16qi, short);
__gcc_v16hi __builtin_ia32_pmovdw512_mask(__gcc_v16si, __gcc_v16hi, short);
__gcc_v16qi __builtin_ia32_pmovqb512_mask(__gcc_v8di, __gcc_v16qi, char);
__gcc_v8si __builtin_ia32_pmovqd512_mask(__gcc_v8di, __gcc_v8si, char);
__gcc_v8hi __builtin_ia32_pmovqw512_mask(__gcc_v8di, __gcc_v8hi, char);
__gcc_v16qi __builtin_ia32_pmovsdb512_mask(__gcc_v16si, __gcc_v16qi, short);
__gcc_v16hi __builtin_ia32_pmovsdw512_mask(__gcc_v16si, __gcc_v16hi, short);
__gcc_v16qi __builtin_ia32_pmovsqb512_mask(__gcc_v8di, __gcc_v16qi, char);
__gcc_v8si __builtin_ia32_pmovsqd512_mask(__gcc_v8di, __gcc_v8si, char);
__gcc_v8hi __builtin_ia32_pmovsqw512_mask(__gcc_v8di, __gcc_v8hi, char);
__gcc_v16si __builtin_ia32_pmovsxbd512_mask(__gcc_v16qi, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_pmovsxbq512_mask(__gcc_v16qi, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_pmovsxdq512_mask(__gcc_v8si, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_pmovsxwd512_mask(__gcc_v16hi, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_pmovsxwq512_mask(__gcc_v8hi, __gcc_v8di, char);
__gcc_v16qi __builtin_ia32_pmovusdb512_mask(__gcc_v16si, __gcc_v16qi, short);
__gcc_v16hi __builtin_ia32_pmovusdw512_mask(__gcc_v16si, __gcc_v16hi, short);
__gcc_v16qi __builtin_ia32_pmovusqb512_mask(__gcc_v8di, __gcc_v16qi, char);
__gcc_v8si __builtin_ia32_pmovusqd512_mask(__gcc_v8di, __gcc_v8si, char);
__gcc_v8hi __builtin_ia32_pmovusqw512_mask(__gcc_v8di, __gcc_v8hi, char);
__gcc_v16si __builtin_ia32_pmovzxbd512_mask(__gcc_v16qi, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_pmovzxbq512_mask(__gcc_v16qi, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_pmovzxdq512_mask(__gcc_v8si, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_pmovzxwd512_mask(__gcc_v16hi, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_pmovzxwq512_mask(__gcc_v8hi, __gcc_v8di, char);
__gcc_v8di
__builtin_ia32_pmuldq512_mask(__gcc_v16si, __gcc_v16si, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pmulld512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pmuludq512_mask(__gcc_v16si, __gcc_v16si, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pord512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_porq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_prold512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_prolq512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_prolvd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_prolvq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_prord512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_prorq512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_prorvd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_prorvq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_pshufd512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v16si
__builtin_ia32_pslld512_mask(__gcc_v16si, __gcc_v4si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_pslldi512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psllq512_mask(__gcc_v8di, __gcc_v2di, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_psllqi512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psllv16si_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psllv8di_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psrad512_mask(__gcc_v16si, __gcc_v4si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_psradi512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psraq512_mask(__gcc_v8di, __gcc_v2di, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_psraqi512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psrav16si_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psrav8di_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psrld512_mask(__gcc_v16si, __gcc_v4si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_psrldi512_mask(__gcc_v16si, int, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psrlq512_mask(__gcc_v8di, __gcc_v2di, __gcc_v8di, char);
__gcc_v8di __builtin_ia32_psrlqi512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psrlv16si_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psrlv8di_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_psubd512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_psubq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
short __builtin_ia32_ptestmd512(__gcc_v16si, __gcc_v16si, short);
char __builtin_ia32_ptestmq512(__gcc_v8di, __gcc_v8di, char);
short __builtin_ia32_ptestnmd512(__gcc_v16si, __gcc_v16si, short);
char __builtin_ia32_ptestnmq512(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_punpckhdq512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_punpckhqdq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_punpckldq512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_punpcklqdq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_pxord512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v8di
__builtin_ia32_pxorq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_rcp14pd512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_rcp14ps512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v2df __builtin_ia32_rcp14sd(__gcc_v2df, __gcc_v2df);
__gcc_v4sf __builtin_ia32_rcp14ss(__gcc_v4sf, __gcc_v4sf);
__gcc_v8df __builtin_ia32_rsqrt14pd512_mask(__gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_rsqrt14ps512_mask(__gcc_v16sf, __gcc_v16sf, short);
__gcc_v2df __builtin_ia32_rsqrt14sd(__gcc_v2df, __gcc_v2df);
__gcc_v4sf __builtin_ia32_rsqrt14ss(__gcc_v4sf, __gcc_v4sf);
__gcc_v8df
__builtin_ia32_shufpd512_mask(__gcc_v8df, __gcc_v8df, int, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_shufps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  int,
  __gcc_v16sf,
  short);
__gcc_v16sf __builtin_ia32_shuf_f32x4_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  int,
  __gcc_v16sf,
  short);
__gcc_v8df
__builtin_ia32_shuf_f64x2_mask(__gcc_v8df, __gcc_v8df, int, __gcc_v8df, char);
__gcc_v16si __builtin_ia32_shuf_i32x4_mask(
  __gcc_v16si,
  __gcc_v16si,
  int,
  __gcc_v16si,
  short);
__gcc_v8di
__builtin_ia32_shuf_i64x2_mask(__gcc_v8di, __gcc_v8di, int, __gcc_v8di, char);
short __builtin_ia32_ucmpd512_mask(__gcc_v16si, __gcc_v16si, int, short);
char __builtin_ia32_ucmpq512_mask(__gcc_v8di, __gcc_v8di, int, char);
__gcc_v8df
__builtin_ia32_unpckhpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char);
__gcc_v16sf
__builtin_ia32_unpckhps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short);
__gcc_v8df
__builtin_ia32_unpcklpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char);
__gcc_v16sf
__builtin_ia32_unpcklps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short);
__gcc_v16si __builtin_ia32_vplzcntd_512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_vplzcntq_512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v16si
__builtin_ia32_vpconflictsi_512_mask(__gcc_v16si, __gcc_v16si, short);
__gcc_v8di __builtin_ia32_vpconflictdi_512_mask(__gcc_v8di, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_permdf512_mask(__gcc_v8df, int, __gcc_v8df, char);
__gcc_v8di __builtin_ia32_permdi512_mask(__gcc_v8di, int, __gcc_v8di, char);
__gcc_v16si __builtin_ia32_vpermi2vard512_mask(
  __gcc_v16si,
  __gcc_v16si,
  __gcc_v16si,
  short);
__gcc_v8df
__builtin_ia32_vpermi2varpd512_mask(__gcc_v8df, __gcc_v8di, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_vpermi2varps512_mask(
  __gcc_v16sf,
  __gcc_v16si,
  __gcc_v16sf,
  short);
__gcc_v8di
__builtin_ia32_vpermi2varq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v8df __builtin_ia32_vpermilpd512_mask(__gcc_v8df, int, __gcc_v8df, char);
__gcc_v16sf
__builtin_ia32_vpermilps512_mask(__gcc_v16sf, int, __gcc_v16sf, short);
__gcc_v8df
__builtin_ia32_vpermilvarpd512_mask(__gcc_v8df, __gcc_v8di, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_vpermilvarps512_mask(
  __gcc_v16sf,
  __gcc_v16si,
  __gcc_v16sf,
  short);
__gcc_v16si __builtin_ia32_vpermt2vard512_mask(
  __gcc_v16si,
  __gcc_v16si,
  __gcc_v16si,
  short);
__gcc_v16si __builtin_ia32_vpermt2vard512_maskz(
  __gcc_v16si,
  __gcc_v16si,
  __gcc_v16si,
  short);
__gcc_v8df
__builtin_ia32_vpermt2varpd512_mask(__gcc_v8di, __gcc_v8df, __gcc_v8df, char);
__gcc_v8df
__builtin_ia32_vpermt2varpd512_maskz(__gcc_v8di, __gcc_v8df, __gcc_v8df, char);
__gcc_v16sf __builtin_ia32_vpermt2varps512_mask(
  __gcc_v16si,
  __gcc_v16sf,
  __gcc_v16sf,
  short);
__gcc_v16sf __builtin_ia32_vpermt2varps512_maskz(
  __gcc_v16si,
  __gcc_v16sf,
  __gcc_v16sf,
  short);
__gcc_v8di
__builtin_ia32_vpermt2varq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v8di
__builtin_ia32_vpermt2varq512_maskz(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v8df
__builtin_ia32_permvardf512_mask(__gcc_v8df, __gcc_v8di, __gcc_v8df, char);
__gcc_v8di
__builtin_ia32_permvardi512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, char);
__gcc_v16sf
__builtin_ia32_permvarsf512_mask(__gcc_v16sf, __gcc_v16si, __gcc_v16sf, short);
__gcc_v16si
__builtin_ia32_permvarsi512_mask(__gcc_v16si, __gcc_v16si, __gcc_v16si, short);
__gcc_v16si __builtin_ia32_pternlogd512_mask(
  __gcc_v16si,
  __gcc_v16si,
  __gcc_v16si,
  int,
  short);
__gcc_v16si __builtin_ia32_pternlogd512_maskz(
  __gcc_v16si,
  __gcc_v16si,
  __gcc_v16si,
  int,
  short);
__gcc_v8di
__builtin_ia32_pternlogq512_mask(__gcc_v8di, __gcc_v8di, __gcc_v8di, int, char);
__gcc_v8di __builtin_ia32_pternlogq512_maskz(
  __gcc_v8di,
  __gcc_v8di,
  __gcc_v8di,
  int,
  char);
__gcc_v16sf __builtin_ia32_copysignps512(__gcc_v16sf, __gcc_v16sf);
__gcc_v8df __builtin_ia32_copysignpd512(__gcc_v8df, __gcc_v8df);
__gcc_v8df __builtin_ia32_sqrtpd512(__gcc_v8df);
__gcc_v16sf __builtin_ia32_sqrtps512(__gcc_v16sf);
__gcc_v16sf __builtin_ia32_exp2ps(__gcc_v16sf);
__gcc_v16si __builtin_ia32_roundpd_az_vec_pack_sfix512(__gcc_v8df, __gcc_v8df);
__gcc_v16si
__builtin_ia32_floorpd_vec_pack_sfix512(__gcc_v8df, __gcc_v8df, const int);
__gcc_v16si
__builtin_ia32_ceilpd_vec_pack_sfix512(__gcc_v8df, __gcc_v8df, const int);
short __builtin_ia32_kandhi(short, short);
short __builtin_ia32_kandnhi(short, short);
short __builtin_ia32_knothi(short);
short __builtin_ia32_korhi(short, short);
short __builtin_ia32_kortestchi(short, short);
short __builtin_ia32_kortestzhi(short, short);
short __builtin_ia32_kunpckhi(short, short);
short __builtin_ia32_kxnorhi(short, short);
short __builtin_ia32_kxorhi(short, short);
short __builtin_ia32_kmov16(short);
__gcc_v8df
__builtin_ia32_addpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_addps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_addsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_addss_round(__gcc_v4sf, __gcc_v4sf, int);
char __builtin_ia32_cmppd512_mask(__gcc_v8df, __gcc_v8df, int, char, int);
short __builtin_ia32_cmpps512_mask(__gcc_v16sf, __gcc_v16sf, int, short, int);
char __builtin_ia32_cmpsd_mask(__gcc_v2df, __gcc_v2df, int, char, int);
char __builtin_ia32_cmpss_mask(__gcc_v4sf, __gcc_v4sf, int, char, int);
int __builtin_ia32_vcomisd(__gcc_v2df, __gcc_v2df, int, int);
int __builtin_ia32_vcomiss(__gcc_v4sf, __gcc_v4sf, int, int);
__gcc_v16sf
__builtin_ia32_cvtdq2ps512_mask(__gcc_v16si, __gcc_v16sf, short, int);
__gcc_v8si __builtin_ia32_cvtpd2dq512_mask(__gcc_v8df, __gcc_v8si, char, int);
__gcc_v8sf __builtin_ia32_cvtpd2ps512_mask(__gcc_v8df, __gcc_v8sf, char, int);
__gcc_v8si __builtin_ia32_cvtpd2udq512_mask(__gcc_v8df, __gcc_v8si, char, int);
__gcc_v16sf
__builtin_ia32_vcvtph2ps512_mask(__gcc_v16hi, __gcc_v16sf, short, int);
__gcc_v16si
__builtin_ia32_cvtps2dq512_mask(__gcc_v16sf, __gcc_v16si, short, int);
__gcc_v8df __builtin_ia32_cvtps2pd512_mask(__gcc_v8sf, __gcc_v8df, char, int);
__gcc_v16si
__builtin_ia32_cvtps2udq512_mask(__gcc_v16sf, __gcc_v16si, short, int);
__gcc_v4sf __builtin_ia32_cvtsd2ss_round(__gcc_v4sf, __gcc_v2df, int);
__gcc_v2df __builtin_ia32_cvtsi2sd64(__gcc_v2df, long long, int);
__gcc_v4sf __builtin_ia32_cvtsi2ss32(__gcc_v4sf, int, int);
__gcc_v4sf __builtin_ia32_cvtsi2ss64(__gcc_v4sf, long long, int);
__gcc_v2df __builtin_ia32_cvtss2sd_round(__gcc_v2df, __gcc_v4sf, int);
__gcc_v8si __builtin_ia32_cvttpd2dq512_mask(__gcc_v8df, __gcc_v8si, char, int);
__gcc_v8si __builtin_ia32_cvttpd2udq512_mask(__gcc_v8df, __gcc_v8si, char, int);
__gcc_v16si
__builtin_ia32_cvttps2dq512_mask(__gcc_v16sf, __gcc_v16si, short, int);
__gcc_v16si
__builtin_ia32_cvttps2udq512_mask(__gcc_v16sf, __gcc_v16si, short, int);
__gcc_v16sf
__builtin_ia32_cvtudq2ps512_mask(__gcc_v16si, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_cvtusi2sd64(__gcc_v2df, unsigned long long, int);
__gcc_v4sf __builtin_ia32_cvtusi2ss32(__gcc_v4sf, unsigned, int);
__gcc_v4sf __builtin_ia32_cvtusi2ss64(__gcc_v4sf, unsigned long long, int);
__gcc_v8df
__builtin_ia32_divpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_divps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_divsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_divss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df __builtin_ia32_fixupimmpd512_mask(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8di,
  int,
  char,
  int);
__gcc_v8df __builtin_ia32_fixupimmpd512_maskz(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8di,
  int,
  char,
  int);
__gcc_v16sf __builtin_ia32_fixupimmps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16si,
  int,
  short,
  int);
__gcc_v16sf __builtin_ia32_fixupimmps512_maskz(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16si,
  int,
  short,
  int);
__gcc_v2df __builtin_ia32_fixupimmsd_mask(
  __gcc_v2df,
  __gcc_v2df,
  __gcc_v2di,
  int,
  char,
  int);
__gcc_v2df __builtin_ia32_fixupimmsd_maskz(
  __gcc_v2df,
  __gcc_v2df,
  __gcc_v2di,
  int,
  char,
  int);
__gcc_v4sf __builtin_ia32_fixupimmss_mask(
  __gcc_v4sf,
  __gcc_v4sf,
  __gcc_v4si,
  int,
  char,
  int);
__gcc_v4sf __builtin_ia32_fixupimmss_maskz(
  __gcc_v4sf,
  __gcc_v4sf,
  __gcc_v4si,
  int,
  char,
  int);
__gcc_v8df __builtin_ia32_getexppd512_mask(__gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_getexpps512_mask(__gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_getexpsd128_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_getexpss128_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df
__builtin_ia32_getmantpd512_mask(__gcc_v8df, int, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_getmantps512_mask(__gcc_v16sf, int, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_getmantsd_round(__gcc_v2df, __gcc_v2df, int, int);
__gcc_v4sf __builtin_ia32_getmantss_round(__gcc_v4sf, __gcc_v4sf, int, int);
__gcc_v8df
__builtin_ia32_maxpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_maxps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_maxsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_maxss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df
__builtin_ia32_minpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_minps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_minsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_minss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df
__builtin_ia32_mulpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_mulps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_mulsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_mulss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df
__builtin_ia32_rndscalepd_mask(__gcc_v8df, int, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_rndscaleps_mask(__gcc_v16sf, int, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_rndscalesd_round(__gcc_v2df, __gcc_v2df, int, int);
__gcc_v4sf __builtin_ia32_rndscaless_round(__gcc_v4sf, __gcc_v4sf, int, int);
__gcc_v8df
__builtin_ia32_scalefpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_scalefps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v2df __builtin_ia32_scalefsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_scalefss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df __builtin_ia32_sqrtpd512_mask(__gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_sqrtps512_mask(__gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_sqrtsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_sqrtss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df
__builtin_ia32_subpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf
__builtin_ia32_subps512_mask(__gcc_v16sf, __gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_subsd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_subss_round(__gcc_v4sf, __gcc_v4sf, int);
int __builtin_ia32_vcvtsd2si32(__gcc_v2df, int);
long long __builtin_ia32_vcvtsd2si64(__gcc_v2df, int);
unsigned __builtin_ia32_vcvtsd2usi32(__gcc_v2df, int);
unsigned long long __builtin_ia32_vcvtsd2usi64(__gcc_v2df, int);
int __builtin_ia32_vcvtss2si32(__gcc_v4sf, int);
long long __builtin_ia32_vcvtss2si64(__gcc_v4sf, int);
unsigned __builtin_ia32_vcvtss2usi32(__gcc_v4sf, int);
unsigned long long __builtin_ia32_vcvtss2usi64(__gcc_v4sf, int);
int __builtin_ia32_vcvttsd2si32(__gcc_v2df, int);
long long __builtin_ia32_vcvttsd2si64(__gcc_v2df, int);
unsigned __builtin_ia32_vcvttsd2usi32(__gcc_v2df, int);
unsigned long long __builtin_ia32_vcvttsd2usi64(__gcc_v2df, int);
int __builtin_ia32_vcvttss2si32(__gcc_v4sf, int);
long long __builtin_ia32_vcvttss2si64(__gcc_v4sf, int);
unsigned __builtin_ia32_vcvttss2usi32(__gcc_v4sf, int);
unsigned long long __builtin_ia32_vcvttss2usi64(__gcc_v4sf, int);
__gcc_v2df __builtin_ia32_vfmaddpd(__gcc_v2df, __gcc_v2df, __gcc_v2df);
__gcc_v2df __builtin_ia32_vfmaddsd3(__gcc_v2df, __gcc_v2df, __gcc_v2df);
__gcc_v4df __builtin_ia32_vfmaddpd256(__gcc_v4df, __gcc_v4df, __gcc_v4df);
__gcc_v4sf __builtin_ia32_vfmaddps(__gcc_v4sf, __gcc_v4sf, __gcc_v4sf);
__gcc_v4sf __builtin_ia32_vfmaddss3(__gcc_v4sf, __gcc_v4sf, __gcc_v4sf);
__gcc_v8sf __builtin_ia32_vfmaddps256(__gcc_v8sf, __gcc_v8sf, __gcc_v8sf);
__gcc_v8df
__builtin_ia32_vfmaddpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v8df
__builtin_ia32_vfmaddpd512_mask3(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v8df
__builtin_ia32_vfmaddpd512_maskz(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_vfmaddps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v16sf __builtin_ia32_vfmaddps512_mask3(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v16sf __builtin_ia32_vfmaddps512_maskz(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v2df
__builtin_ia32_vfmaddsd3_round(__gcc_v2df, __gcc_v2df, __gcc_v2df, int);
__gcc_v4sf
__builtin_ia32_vfmaddss3_round(__gcc_v4sf, __gcc_v4sf, __gcc_v4sf, int);
__gcc_v2df __builtin_ia32_vfmaddsubpd(__gcc_v2df, __gcc_v2df, __gcc_v2df);
__gcc_v4df __builtin_ia32_vfmaddsubpd256(__gcc_v4df, __gcc_v4df, __gcc_v4df);
__gcc_v4sf __builtin_ia32_vfmaddsubps(__gcc_v4sf, __gcc_v4sf, __gcc_v4sf);
__gcc_v8sf __builtin_ia32_vfmaddsubps256(__gcc_v8sf, __gcc_v8sf, __gcc_v8sf);
__gcc_v8df __builtin_ia32_vfmaddsubpd512_mask(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8df,
  char,
  int);
__gcc_v8df __builtin_ia32_vfmaddsubpd512_mask3(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8df,
  char,
  int);
__gcc_v8df __builtin_ia32_vfmaddsubpd512_maskz(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8df,
  char,
  int);
__gcc_v16sf __builtin_ia32_vfmaddsubps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v16sf __builtin_ia32_vfmaddsubps512_mask3(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v16sf __builtin_ia32_vfmaddsubps512_maskz(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v8df __builtin_ia32_vfmsubaddpd512_mask3(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8df,
  char,
  int);
__gcc_v16sf __builtin_ia32_vfmsubaddps512_mask3(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v8df
__builtin_ia32_vfmsubpd512_mask3(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_vfmsubps512_mask3(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v8df
__builtin_ia32_vfnmaddpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_vfnmaddps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v8df
__builtin_ia32_vfnmsubpd512_mask(__gcc_v8df, __gcc_v8df, __gcc_v8df, char, int);
__gcc_v8df __builtin_ia32_vfnmsubpd512_mask3(
  __gcc_v8df,
  __gcc_v8df,
  __gcc_v8df,
  char,
  int);
__gcc_v16sf __builtin_ia32_vfnmsubps512_mask(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v16sf __builtin_ia32_vfnmsubps512_mask3(
  __gcc_v16sf,
  __gcc_v16sf,
  __gcc_v16sf,
  short,
  int);
__gcc_v8df __builtin_ia32_exp2pd_mask(__gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_exp2ps_mask(__gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v8df __builtin_ia32_rcp28pd_mask(__gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_rcp28ps_mask(__gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_rcp28sd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_rcp28ss_round(__gcc_v4sf, __gcc_v4sf, int);
__gcc_v8df __builtin_ia32_rsqrt28pd_mask(__gcc_v8df, __gcc_v8df, char, int);
__gcc_v16sf __builtin_ia32_rsqrt28ps_mask(__gcc_v16sf, __gcc_v16sf, short, int);
__gcc_v2df __builtin_ia32_rsqrt28sd_round(__gcc_v2df, __gcc_v2df, int);
__gcc_v4sf __builtin_ia32_rsqrt28ss_round(__gcc_v4sf, __gcc_v4sf, int);
void __builtin__ITM_WM64(__gcc_v2si *, __gcc_v2si);
void __builtin__ITM_WaRM64(__gcc_v2si *, __gcc_v2si);
void __builtin__ITM_WaWM64(__gcc_v2si *, __gcc_v2si);
__gcc_v2si __builtin__ITM_RM64(const __gcc_v2si *);
__gcc_v2si __builtin__ITM_RaRM64(const __gcc_v2si *);
__gcc_v2si __builtin__ITM_RaWM64(const __gcc_v2si *);
__gcc_v2si __builtin__ITM_RfWM64(const __gcc_v2si *);
void __builtin__ITM_WM128(__gcc_v4sf *, __gcc_v4sf);
void __builtin__ITM_WaRM128(__gcc_v4sf *, __gcc_v4sf);
void __builtin__ITM_WaWM128(__gcc_v4sf *, __gcc_v4sf);
__gcc_v4sf __builtin__ITM_RM128(const __gcc_v4sf *);
__gcc_v4sf __builtin__ITM_RaRM128(const __gcc_v4sf *);
__gcc_v4sf __builtin__ITM_RaWM128(const __gcc_v4sf *);
__gcc_v4sf __builtin__ITM_RfWM128(const __gcc_v4sf *);
void __builtin__ITM_WM256(__gcc_v8sf *, __gcc_v8sf);
void __builtin__ITM_WaRM256(__gcc_v8sf *, __gcc_v8sf);
void __builtin__ITM_WaWM256(__gcc_v8sf *, __gcc_v8sf);
__gcc_v8sf __builtin__ITM_RM256(const __gcc_v8sf *);
__gcc_v8sf __builtin__ITM_RaRM256(const __gcc_v8sf *);
__gcc_v8sf __builtin__ITM_RaWM256(const __gcc_v8sf *);
__gcc_v8sf __builtin__ITM_RfWM256(const __gcc_v8sf *);
void __builtin__ITM_LM64(const void *);
void __builtin__ITM_LM128(const void *);
void __builtin__ITM_LM256(const void *);
__gcc_v4si __builtin_ia32_sha1msg1(__gcc_v4si, __gcc_v4si);
__gcc_v4si __builtin_ia32_sha1msg2(__gcc_v4si, __gcc_v4si);
__gcc_v4si __builtin_ia32_sha1nexte(__gcc_v4si, __gcc_v4si);
__gcc_v4si __builtin_ia32_sha1rnds4(__gcc_v4si, __gcc_v4si, int);
__gcc_v4si __builtin_ia32_sha256msg1(__gcc_v4si, __gcc_v4si);
__gcc_v4si __builtin_ia32_sha256msg2(__gcc_v4si, __gcc_v4si);
__gcc_v4si __builtin_ia32_sha256rnds2(__gcc_v4si, __gcc_v4si, __gcc_v4si);
__gcc_v2df __builtin_ia32_gathersiv2df(
  __gcc_v2df,
  const double *,
  __gcc_v4si,
  __gcc_v2df,
  int);
__gcc_v4df __builtin_ia32_gathersiv4df(
  __gcc_v4df,
  const double *,
  __gcc_v4si,
  __gcc_v4df,
  int);
__gcc_v2df __builtin_ia32_gatherdiv2df(
  __gcc_v2df,
  const double *,
  __gcc_v2di,
  __gcc_v2df,
  int);
__gcc_v4df __builtin_ia32_gatherdiv4df(
  __gcc_v4df,
  const double *,
  __gcc_v4di,
  __gcc_v4df,
  int);
__gcc_v4sf __builtin_ia32_gathersiv4sf(
  __gcc_v4sf,
  const float *,
  __gcc_v4si,
  __gcc_v4sf,
  int);
__gcc_v8sf __builtin_ia32_gathersiv8sf(
  __gcc_v8sf,
  const float *,
  __gcc_v8si,
  __gcc_v8sf,
  int);
__gcc_v4sf __builtin_ia32_gatherdiv4sf(
  __gcc_v4sf,
  const float *,
  __gcc_v2di,
  __gcc_v4sf,
  int);
__gcc_v4sf __builtin_ia32_gatherdiv4sf256(
  __gcc_v4sf,
  const float *,
  __gcc_v4di,
  __gcc_v4sf,
  int);
__gcc_v2di __builtin_ia32_gathersiv2di(
  __gcc_v2di,
  const long *,
  __gcc_v4si,
  __gcc_v2di,
  int);
__gcc_v4di __builtin_ia32_gathersiv4di(
  __gcc_v4di,
  const long *,
  __gcc_v4si,
  __gcc_v4di,
  int);
__gcc_v2di __builtin_ia32_gatherdiv2di(
  __gcc_v2di,
  const long *,
  __gcc_v2di,
  __gcc_v2di,
  int);
__gcc_v4di __builtin_ia32_gatherdiv4di(
  __gcc_v4di,
  const long *,
  __gcc_v4di,
  __gcc_v4di,
  int);
__gcc_v4si __builtin_ia32_gathersiv4si(
  __gcc_v4si,
  const int *,
  __gcc_v4si,
  __gcc_v4si,
  int);
__gcc_v8si __builtin_ia32_gathersiv8si(
  __gcc_v8si,
  const int *,
  __gcc_v8si,
  __gcc_v8si,
  int);
__gcc_v4si __builtin_ia32_gatherdiv4si(
  __gcc_v4si,
  const int *,
  __gcc_v2di,
  __gcc_v4si,
  int);
__gcc_v4si __builtin_ia32_gatherdiv4si256(
  __gcc_v4si,
  const int *,
  __gcc_v4di,
  __gcc_v4si,
  int);
__gcc_v4df __builtin_ia32_gatheraltsiv4df(
  __gcc_v4df,
  const double *,
  __gcc_v8si,
  __gcc_v4df,
  int);
__gcc_v8sf __builtin_ia32_gatheraltdiv4sf256(
  __gcc_v8sf,
  const float *,
  __gcc_v4di,
  __gcc_v8sf,
  int);
__gcc_v4di __builtin_ia32_gatheraltsiv4di(
  __gcc_v4di,
  const long *,
  __gcc_v8si,
  __gcc_v4di,
  int);
__gcc_v8si __builtin_ia32_gatheraltdiv4si256(
  __gcc_v8si,
  const int *,
  __gcc_v4di,
  __gcc_v8si,
  int);
__gcc_v16sf __builtin_ia32_gathersiv16sf(
  __gcc_v16sf,
  const float *,
  __gcc_v16si,
  short,
  int);
__gcc_v8df
__builtin_ia32_gathersiv8df(__gcc_v8df, const double *, __gcc_v8si, char, int);
__gcc_v8sf
__builtin_ia32_gatherdiv16sf(__gcc_v8sf, const float *, __gcc_v8di, char, int);
__gcc_v8df
__builtin_ia32_gatherdiv8df(__gcc_v8df, const double *, __gcc_v8di, char, int);
__gcc_v16si
__builtin_ia32_gathersiv16si(__gcc_v16si, const int *, __gcc_v16si, short, int);
__gcc_v8di
__builtin_ia32_gathersiv8di(__gcc_v8di, const long *, __gcc_v8si, char, int);
__gcc_v8si
__builtin_ia32_gatherdiv16si(__gcc_v8si, const int *, __gcc_v8di, char, int);
__gcc_v8di
__builtin_ia32_gatherdiv8di(__gcc_v8di, const long *, __gcc_v8di, char, int);
__gcc_v8df __builtin_ia32_gatheraltsiv8df(
  __gcc_v8df,
  const double *,
  __gcc_v16si,
  char,
  int);
__gcc_v16sf __builtin_ia32_gatheraltdiv8sf(
  __gcc_v16sf,
  const float *,
  __gcc_v8di,
  short,
  int);
__gcc_v8di __builtin_ia32_gatheraltsiv8di(
  __gcc_v8di,
  const long *,
  __gcc_v16si,
  char,
  int);
__gcc_v16si __builtin_ia32_gatheraltdiv8si(
  __gcc_v16si,
  const int *,
  __gcc_v8di,
  short,
  int);
void __builtin_ia32_scattersiv16sf(
  float *,
  short,
  __gcc_v16si,
  __gcc_v16sf,
  int);
void __builtin_ia32_scattersiv8df(double *, char, __gcc_v8si, __gcc_v8df, int);
void __builtin_ia32_scatterdiv16sf(float *, char, __gcc_v8di, __gcc_v8sf, int);
void __builtin_ia32_scatterdiv8df(double *, char, __gcc_v8di, __gcc_v8df, int);
void __builtin_ia32_scattersiv16si(int *, short, __gcc_v16si, __gcc_v16si, int);
void __builtin_ia32_scattersiv8di(
  long long *,
  char,
  __gcc_v8si,
  __gcc_v8di,
  int);
void __builtin_ia32_scatterdiv16si(int *, char, __gcc_v8di, __gcc_v8si, int);
void __builtin_ia32_scatterdiv8di(
  long long *,
  char,
  __gcc_v8di,
  __gcc_v8di,
  int);
__gcc_v2df
__builtin_ia32_gather3siv2df(__gcc_v2df, const double *, __gcc_v4si, char, int);
__gcc_v4df
__builtin_ia32_gather3siv4df(__gcc_v4df, const double *, __gcc_v4si, char, int);
__gcc_v2df
__builtin_ia32_gather3div2df(__gcc_v2df, const double *, __gcc_v2di, char, int);
__gcc_v4df
__builtin_ia32_gather3div4df(__gcc_v4df, const double *, __gcc_v4di, char, int);
__gcc_v4sf
__builtin_ia32_gather3siv4sf(__gcc_v4sf, const float *, __gcc_v4si, char, int);
__gcc_v8sf
__builtin_ia32_gather3siv8sf(__gcc_v8sf, const float *, __gcc_v8si, char, int);
__gcc_v4sf
__builtin_ia32_gather3div4sf(__gcc_v4sf, const float *, __gcc_v2di, char, int);
__gcc_v4sf
__builtin_ia32_gather3div8sf(__gcc_v4sf, const float *, __gcc_v4di, char, int);
__gcc_v2di
__builtin_ia32_gather3siv2di(__gcc_v2di, const long *, __gcc_v4si, char, int);
__gcc_v4di
__builtin_ia32_gather3siv4di(__gcc_v4di, const long *, __gcc_v4si, char, int);
__gcc_v2di
__builtin_ia32_gather3div2di(__gcc_v2di, const long *, __gcc_v2di, char, int);
__gcc_v4di
__builtin_ia32_gather3div4di(__gcc_v4di, const long *, __gcc_v4di, char, int);
__gcc_v4si
__builtin_ia32_gather3siv4si(__gcc_v4si, const int *, __gcc_v4si, char, int);
__gcc_v8si
__builtin_ia32_gather3siv8si(__gcc_v8si, const int *, __gcc_v8si, char, int);
__gcc_v4si
__builtin_ia32_gather3div4si(__gcc_v4si, const int *, __gcc_v2di, char, int);
__gcc_v4si
__builtin_ia32_gather3div8si(__gcc_v4si, const int *, __gcc_v4di, char, int);
__gcc_v4df __builtin_ia32_gather3altsiv4df(
  __gcc_v4df,
  const double *,
  __gcc_v8si,
  char,
  int);
__gcc_v8sf __builtin_ia32_gather3altdiv8sf(
  __gcc_v8sf,
  const float *,
  __gcc_v4di,
  char,
  int);
__gcc_v4di __builtin_ia32_gather3altsiv4di(
  __gcc_v4di,
  const long *,
  __gcc_v8si,
  char,
  int);
__gcc_v8si
__builtin_ia32_gather3altdiv8si(__gcc_v8si, const int *, __gcc_v4di, char, int);
void __builtin_ia32_scattersiv8sf(float *, char, __gcc_v8si, __gcc_v8sf, int);
void __builtin_ia32_scattersiv4sf(float *, char, __gcc_v4si, __gcc_v4sf, int);
void __builtin_ia32_scattersiv4df(double *, char, __gcc_v4si, __gcc_v4df, int);
void __builtin_ia32_scattersiv2df(double *, char, __gcc_v4si, __gcc_v2df, int);
void __builtin_ia32_scatterdiv8sf(float *, char, __gcc_v4di, __gcc_v4sf, int);
void __builtin_ia32_scatterdiv4sf(float *, char, __gcc_v2di, __gcc_v4sf, int);
void __builtin_ia32_scatterdiv4df(double *, char, __gcc_v4di, __gcc_v4df, int);
void __builtin_ia32_scatterdiv2df(double *, char, __gcc_v2di, __gcc_v2df, int);
void __builtin_ia32_scattersiv8si(int *, char, __gcc_v8si, __gcc_v8si, int);
void __builtin_ia32_scattersiv4si(int *, char, __gcc_v4si, __gcc_v4si, int);
void __builtin_ia32_scattersiv4di(
  long long *,
  char,
  __gcc_v4si,
  __gcc_v4di,
  int);
void __builtin_ia32_scattersiv2di(
  long long *,
  char,
  __gcc_v4si,
  __gcc_v2di,
  int);
void __builtin_ia32_scatterdiv8si(int *, char, __gcc_v4di, __gcc_v4si, int);
void __builtin_ia32_scatterdiv4si(int *, char, __gcc_v2di, __gcc_v4si, int);
void __builtin_ia32_scatterdiv4di(
  long long *,
  char,
  __gcc_v4di,
  __gcc_v4di,
  int);
void __builtin_ia32_scatterdiv2di(
  long long *,
  char,
  __gcc_v2di,
  __gcc_v2di,
  int);
void __builtin_ia32_scatteraltsiv8df(
  double *,
  char,
  __gcc_v16si,
  __gcc_v8df,
  int);
void __builtin_ia32_scatteraltdiv8sf(
  float *,
  short,
  __gcc_v8di,
  __gcc_v16sf,
  int);
void __builtin_ia32_scatteraltsiv8di(
  long long *,
  char,
  __gcc_v16si,
  __gcc_v8di,
  int);
void __builtin_ia32_scatteraltdiv8si(
  int *,
  short,
  __gcc_v8di,
  __gcc_v16si,
  int);
void __builtin_ia32_gatherpfdpd(char, __gcc_v8si, const long *, int, int);
void __builtin_ia32_gatherpfdps(short, __gcc_v16si, const int *, int, int);
void __builtin_ia32_gatherpfqpd(char, __gcc_v8di, const long *, int, int);
void __builtin_ia32_gatherpfqps(char, __gcc_v8di, const int *, int, int);
void __builtin_ia32_scatterpfdpd(char, __gcc_v8si, const long *, int, int);
void __builtin_ia32_scatterpfdps(short, __gcc_v16si, const int *, int, int);
void __builtin_ia32_scatterpfqpd(char, __gcc_v8di, const long *, int, int);
void __builtin_ia32_scatterpfqps(char, __gcc_v8di, const int *, int, int);
