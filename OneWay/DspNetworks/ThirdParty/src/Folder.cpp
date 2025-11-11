/* ------------------------------------------------------------
author: "Jean-Louis Paquelin"
copyright: "Copyright (C) 2022 Jean-Louis Paquelin <jlp@studionex.com>"
license: "GNU General Public License v3 or later"
name: "Granola"
version: "2022.3.2"
Code generated with Faust 2.81.2 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _Folder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___Folder_H__
#define  ___Folder_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _Folder
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

struct _FolderSIG0 {
	
	int getNumInputs_FolderSIG0() {
		return 0;
	}
	int getNumOutputs_FolderSIG0() {
		return 1;
	}
	
	void instanceInit_FolderSIG0(int sample_rate) {
	}
	
	void fill_FolderSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = 0.0f;
		}
	}

};

static _FolderSIG0* new_FolderSIG0() { return (_FolderSIG0*)new _FolderSIG0(); }
static void delete_FolderSIG0(_FolderSIG0* dsp) { delete dsp; }


struct _Folder final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	int iVec0[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst4;
	float fRec7[2];
	int iRec8[2];
	int iVec2[2];
	int iVec3[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec11[2];
	float fRec10[2];
	float fRec9[2];
	FAUSTFLOAT fCheckbox0;
	int iRec12[2];
	int iRec6[2];
	float fRec5[2];
	int iVec4[2];
	int iVec5[2];
	float fRec16[2];
	float fRec15[2];
	int iRec17[2];
	int iRec14[2];
	float fRec13[2];
	int iVec6[2];
	int iVec7[2];
	float fRec21[2];
	float fRec20[2];
	int iRec22[2];
	int iRec19[2];
	float fRec18[2];
	int iVec8[2];
	int iVec9[2];
	float fRec26[2];
	float fRec25[2];
	int iRec27[2];
	int iRec24[2];
	float fRec23[2];
	int iVec10[2];
	int iVec11[2];
	float fRec31[2];
	float fRec30[2];
	int iRec32[2];
	int iRec29[2];
	float fRec28[2];
	int iVec12[2];
	int iVec13[2];
	float fRec36[2];
	float fRec35[2];
	int iRec37[2];
	int iRec34[2];
	float fRec33[2];
	int iVec14[2];
	int iVec15[2];
	float fRec41[2];
	float fRec40[2];
	int iRec42[2];
	int iRec39[2];
	float fRec38[2];
	int iVec16[2];
	int iVec17[2];
	float fRec46[2];
	float fRec45[2];
	int iRec47[2];
	int iRec44[2];
	float fRec43[2];
	int iVec18[2];
	int iVec19[2];
	float fRec51[2];
	float fRec50[2];
	int iRec52[2];
	int iRec49[2];
	float fRec48[2];
	int iVec20[2];
	int iVec21[2];
	float fRec56[2];
	float fRec55[2];
	int iRec57[2];
	int iRec54[2];
	float fRec53[2];
	int iVec22[2];
	int iVec23[2];
	float fRec61[2];
	float fRec60[2];
	int iRec62[2];
	int iRec59[2];
	float fRec58[2];
	int iVec24[2];
	int iVec25[2];
	float fRec66[2];
	float fRec65[2];
	int iRec67[2];
	int iRec64[2];
	float fRec63[2];
	int iVec26[2];
	int iVec27[2];
	float fRec71[2];
	float fRec70[2];
	int iRec72[2];
	int iRec69[2];
	float fRec68[2];
	int iVec28[2];
	int iVec29[2];
	float fRec76[2];
	float fRec75[2];
	int iRec77[2];
	int iRec74[2];
	float fRec73[2];
	int iVec30[2];
	int iVec31[2];
	float fRec81[2];
	float fRec80[2];
	int iRec82[2];
	int iRec79[2];
	float fRec78[2];
	int iRec3[2];
	float ftbl0[240000];
	FAUSTFLOAT fCheckbox1;
	float fRec83[2];
	FAUSTFLOAT fHbargraph0;
	FAUSTFLOAT fVslider0;
	float fRec84[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fRec86[2];
	float fRec85[2];
	FAUSTFLOAT fVslider1;
	float fRec87[2];
	FAUSTFLOAT fHslider3;
	float fRec89[2];
	float fRec90[2];
	float fRec88[2];
	FAUSTFLOAT fHslider4;
	float fRec92[2];
	float fRec93[2];
	int iVec32[2];
	int iRec91[2];
	int iRec94[2];
	float fRec95[2];
	float fRec97[2];
	float fRec98[2];
	int iVec33[2];
	int iRec96[2];
	int iRec99[2];
	float fRec100[2];
	float fRec102[2];
	float fRec103[2];
	int iVec34[2];
	int iRec101[2];
	int iRec104[2];
	float fRec105[2];
	float fRec107[2];
	float fRec108[2];
	int iVec35[2];
	int iRec106[2];
	int iRec109[2];
	float fRec110[2];
	float fRec112[2];
	float fRec113[2];
	int iVec36[2];
	int iRec111[2];
	int iRec114[2];
	float fRec115[2];
	float fRec117[2];
	float fRec118[2];
	int iVec37[2];
	int iRec116[2];
	int iRec119[2];
	float fRec120[2];
	float fRec122[2];
	float fRec123[2];
	int iVec38[2];
	int iRec121[2];
	int iRec124[2];
	float fRec125[2];
	float fRec127[2];
	float fRec128[2];
	int iVec39[2];
	int iRec126[2];
	int iRec129[2];
	float fRec130[2];
	float fRec132[2];
	float fRec133[2];
	int iVec40[2];
	int iRec131[2];
	int iRec134[2];
	float fRec135[2];
	float fRec137[2];
	float fRec138[2];
	int iVec41[2];
	int iRec136[2];
	int iRec139[2];
	float fRec140[2];
	float fRec142[2];
	float fRec143[2];
	int iVec42[2];
	int iRec141[2];
	int iRec144[2];
	float fRec145[2];
	float fRec147[2];
	float fRec148[2];
	int iVec43[2];
	int iRec146[2];
	int iRec149[2];
	float fRec150[2];
	float fRec152[2];
	float fRec153[2];
	int iVec44[2];
	int iRec151[2];
	int iRec154[2];
	float fRec155[2];
	float fRec157[2];
	float fRec158[2];
	int iVec45[2];
	int iRec156[2];
	int iRec159[2];
	float fRec160[2];
	float fRec162[2];
	float fRec163[2];
	int iVec46[2];
	int iRec161[2];
	int iRec164[2];
	float fRec4[2];
	float fConst9;
	float fRec2[2];
	float fRec0[2];
	FAUSTFLOAT fVslider2;
	float fRec165[2];
	FAUSTFLOAT fVslider3;
	float fRec166[2];
	int iVec47[2];
	int iVec48[2];
	float fRec175[2];
	float fRec174[2];
	int iRec176[2];
	int iRec173[2];
	float fRec172[2];
	int iVec49[2];
	int iVec50[2];
	float fRec180[2];
	float fRec179[2];
	int iRec181[2];
	int iRec178[2];
	float fRec177[2];
	int iVec51[2];
	int iVec52[2];
	float fRec185[2];
	float fRec184[2];
	int iRec186[2];
	int iRec183[2];
	float fRec182[2];
	int iVec53[2];
	int iVec54[2];
	float fRec190[2];
	float fRec189[2];
	int iRec191[2];
	int iRec188[2];
	float fRec187[2];
	int iVec55[2];
	int iVec56[2];
	float fRec195[2];
	float fRec194[2];
	int iRec196[2];
	int iRec193[2];
	float fRec192[2];
	int iVec57[2];
	int iVec58[2];
	float fRec200[2];
	float fRec199[2];
	int iRec201[2];
	int iRec198[2];
	float fRec197[2];
	int iVec59[2];
	int iVec60[2];
	float fRec205[2];
	float fRec204[2];
	int iRec206[2];
	int iRec203[2];
	float fRec202[2];
	int iVec61[2];
	int iVec62[2];
	float fRec210[2];
	float fRec209[2];
	int iRec211[2];
	int iRec208[2];
	float fRec207[2];
	int iVec63[2];
	int iVec64[2];
	float fRec215[2];
	float fRec214[2];
	int iRec216[2];
	int iRec213[2];
	float fRec212[2];
	int iVec65[2];
	int iVec66[2];
	float fRec220[2];
	float fRec219[2];
	int iRec221[2];
	int iRec218[2];
	float fRec217[2];
	int iVec67[2];
	int iVec68[2];
	float fRec225[2];
	float fRec224[2];
	int iRec226[2];
	int iRec223[2];
	float fRec222[2];
	int iVec69[2];
	int iVec70[2];
	float fRec230[2];
	float fRec229[2];
	int iRec231[2];
	int iRec228[2];
	float fRec227[2];
	int iVec71[2];
	int iVec72[2];
	float fRec235[2];
	float fRec234[2];
	int iRec236[2];
	int iRec233[2];
	float fRec232[2];
	int iVec73[2];
	int iVec74[2];
	float fRec240[2];
	float fRec239[2];
	int iRec241[2];
	int iRec238[2];
	float fRec237[2];
	int iVec75[2];
	int iVec76[2];
	float fRec245[2];
	float fRec244[2];
	int iRec246[2];
	int iRec243[2];
	float fRec242[2];
	int iRec170[2];
	float ftbl1[240000];
	float fRec248[2];
	float fRec247[2];
	float fRec249[2];
	float fRec251[2];
	float fRec252[2];
	int iVec77[2];
	int iRec250[2];
	int iRec253[2];
	float fRec254[2];
	float fRec256[2];
	float fRec257[2];
	int iVec78[2];
	int iRec255[2];
	int iRec258[2];
	float fRec259[2];
	float fRec261[2];
	float fRec262[2];
	int iVec79[2];
	int iRec260[2];
	int iRec263[2];
	float fRec264[2];
	float fRec266[2];
	float fRec267[2];
	int iVec80[2];
	int iRec265[2];
	int iRec268[2];
	float fRec269[2];
	float fRec271[2];
	float fRec272[2];
	int iVec81[2];
	int iRec270[2];
	int iRec273[2];
	float fRec274[2];
	float fRec276[2];
	float fRec277[2];
	int iVec82[2];
	int iRec275[2];
	int iRec278[2];
	float fRec279[2];
	float fRec281[2];
	float fRec282[2];
	int iVec83[2];
	int iRec280[2];
	int iRec283[2];
	float fRec284[2];
	float fRec286[2];
	float fRec287[2];
	int iVec84[2];
	int iRec285[2];
	int iRec288[2];
	float fRec289[2];
	float fRec291[2];
	float fRec292[2];
	int iVec85[2];
	int iRec290[2];
	int iRec293[2];
	float fRec294[2];
	float fRec296[2];
	float fRec297[2];
	int iVec86[2];
	int iRec295[2];
	int iRec298[2];
	float fRec299[2];
	float fRec301[2];
	float fRec302[2];
	int iVec87[2];
	int iRec300[2];
	int iRec303[2];
	float fRec304[2];
	float fRec306[2];
	float fRec307[2];
	int iVec88[2];
	int iRec305[2];
	int iRec308[2];
	float fRec309[2];
	float fRec311[2];
	float fRec312[2];
	int iVec89[2];
	int iRec310[2];
	int iRec313[2];
	float fRec314[2];
	float fRec316[2];
	float fRec317[2];
	int iVec90[2];
	int iRec315[2];
	int iRec318[2];
	float fRec319[2];
	float fRec321[2];
	float fRec322[2];
	int iVec91[2];
	int iRec320[2];
	int iRec323[2];
	float fRec171[2];
	float fRec169[2];
	float fRec167[2];
	
	_Folder() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("author", "Jean-Louis Paquelin");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/parallelMax:author", "Bart Brouns");
		m->declare("basics.lib/parallelMax:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelMax:licence", "GPL-3.0");
		m->declare("basics.lib/parallelOp:author", "Bart Brouns");
		m->declare("basics.lib/parallelOp:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelOp:licence", "GPL-3.0");
		m->declare("basics.lib/version", "1.21.0");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _Folder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/limiter_1176_R4_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/limiter_1176_R4_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/limiter_1176_R4_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("copyright", "Copyright (C) 2022 Jean-Louis Paquelin <jlp@studionex.com>");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "Folder.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("license", "GNU General Public License v3 or later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "Granola");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("version", "2022.3.2");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 50.265484f / fConst0;
		fConst2 = 1.0f / (fConst1 + 1.0f);
		fConst3 = 44.1f / fConst0;
		fConst4 = 1.0f - fConst3;
		_FolderSIG0* sig0 = new_FolderSIG0();
		sig0->instanceInit_FolderSIG0(sample_rate);
		sig0->fill_FolderSIG0(240000, ftbl0);
		fConst5 = std::exp(-(2.5e+03f / fConst0));
		fConst6 = 0.75f * (1.0f - fConst5);
		fConst7 = std::exp(-(2.0f / fConst0));
		fConst8 = std::exp(-(1.25e+03f / fConst0));
		fConst9 = 1.0f - fConst1;
		sig0->instanceInit_FolderSIG0(sample_rate);
		sig0->fill_FolderSIG0(240000, ftbl1);
		delete_FolderSIG0(sig0);
	}
	
	void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fVslider2 = FAUSTFLOAT(0.5f);
		fVslider3 = FAUSTFLOAT(0.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec7[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec8[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iVec3[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec11[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec10[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec12[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec6[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec5[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			iVec4[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iVec5[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec16[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec15[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec17[l16] = 0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec14[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iVec6[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iVec7[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iRec22[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec19[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec18[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iVec8[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			iVec9[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec26[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec25[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iRec27[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec24[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec23[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			iVec10[l33] = 0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iVec11[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec31[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec30[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			iRec32[l37] = 0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			iRec29[l38] = 0;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec28[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			iVec12[l40] = 0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			iVec13[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec36[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec35[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			iRec37[l44] = 0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			iRec34[l45] = 0;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec33[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			iVec14[l47] = 0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			iVec15[l48] = 0;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec41[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec40[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			iRec42[l51] = 0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			iRec39[l52] = 0;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec38[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			iVec16[l54] = 0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iVec17[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec46[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec45[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			iRec47[l58] = 0;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			iRec44[l59] = 0;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec43[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			iVec18[l61] = 0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			iVec19[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec51[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec50[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			iRec52[l65] = 0;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			iRec49[l66] = 0;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec48[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			iVec20[l68] = 0;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			iVec21[l69] = 0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec56[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec55[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			iRec57[l72] = 0;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			iRec54[l73] = 0;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec53[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			iVec22[l75] = 0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			iVec23[l76] = 0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec61[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec60[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			iRec62[l79] = 0;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			iRec59[l80] = 0;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			fRec58[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			iVec24[l82] = 0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			iVec25[l83] = 0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec66[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fRec65[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			iRec67[l86] = 0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			iRec64[l87] = 0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec63[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			iVec26[l89] = 0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			iVec27[l90] = 0;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec71[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec70[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			iRec72[l93] = 0;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			iRec69[l94] = 0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fRec68[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			iVec28[l96] = 0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			iVec29[l97] = 0;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fRec76[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec75[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			iRec77[l100] = 0;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			iRec74[l101] = 0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec73[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			iVec30[l103] = 0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			iVec31[l104] = 0;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec81[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec80[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			iRec82[l107] = 0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			iRec79[l108] = 0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec78[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			iRec3[l110] = 0;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec83[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec84[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec86[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			fRec85[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec87[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec89[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec90[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec88[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			fRec92[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fRec93[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			iVec32[l121] = 0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			iRec91[l122] = 0;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			iRec94[l123] = 0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec95[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec97[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec98[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			iVec33[l127] = 0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			iRec96[l128] = 0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			iRec99[l129] = 0;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			fRec100[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec102[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec103[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			iVec34[l133] = 0;
		}
		for (int l134 = 0; l134 < 2; l134 = l134 + 1) {
			iRec101[l134] = 0;
		}
		for (int l135 = 0; l135 < 2; l135 = l135 + 1) {
			iRec104[l135] = 0;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			fRec105[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fRec107[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fRec108[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			iVec35[l139] = 0;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			iRec106[l140] = 0;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			iRec109[l141] = 0;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fRec110[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fRec112[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			fRec113[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 2; l145 = l145 + 1) {
			iVec36[l145] = 0;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			iRec111[l146] = 0;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			iRec114[l147] = 0;
		}
		for (int l148 = 0; l148 < 2; l148 = l148 + 1) {
			fRec115[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fRec117[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec118[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			iVec37[l151] = 0;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			iRec116[l152] = 0;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			iRec119[l153] = 0;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fRec120[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 2; l155 = l155 + 1) {
			fRec122[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fRec123[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			iVec38[l157] = 0;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			iRec121[l158] = 0;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			iRec124[l159] = 0;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec125[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fRec127[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec128[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			iVec39[l163] = 0;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			iRec126[l164] = 0;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			iRec129[l165] = 0;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec130[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec132[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 2; l168 = l168 + 1) {
			fRec133[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			iVec40[l169] = 0;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			iRec131[l170] = 0;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			iRec134[l171] = 0;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fRec135[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fRec137[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fRec138[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			iVec41[l175] = 0;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			iRec136[l176] = 0;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			iRec139[l177] = 0;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec140[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec142[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fRec143[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 2; l181 = l181 + 1) {
			iVec42[l181] = 0;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			iRec141[l182] = 0;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			iRec144[l183] = 0;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec145[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fRec147[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 2; l186 = l186 + 1) {
			fRec148[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			iVec43[l187] = 0;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			iRec146[l188] = 0;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			iRec149[l189] = 0;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec150[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec152[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 2; l192 = l192 + 1) {
			fRec153[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			iVec44[l193] = 0;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			iRec151[l194] = 0;
		}
		for (int l195 = 0; l195 < 2; l195 = l195 + 1) {
			iRec154[l195] = 0;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			fRec155[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 2; l197 = l197 + 1) {
			fRec157[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			fRec158[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			iVec45[l199] = 0;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			iRec156[l200] = 0;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			iRec159[l201] = 0;
		}
		for (int l202 = 0; l202 < 2; l202 = l202 + 1) {
			fRec160[l202] = 0.0f;
		}
		for (int l203 = 0; l203 < 2; l203 = l203 + 1) {
			fRec162[l203] = 0.0f;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fRec163[l204] = 0.0f;
		}
		for (int l205 = 0; l205 < 2; l205 = l205 + 1) {
			iVec46[l205] = 0;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			iRec161[l206] = 0;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			iRec164[l207] = 0;
		}
		for (int l208 = 0; l208 < 2; l208 = l208 + 1) {
			fRec4[l208] = 0.0f;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			fRec2[l209] = 0.0f;
		}
		for (int l210 = 0; l210 < 2; l210 = l210 + 1) {
			fRec0[l210] = 0.0f;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			fRec165[l211] = 0.0f;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fRec166[l212] = 0.0f;
		}
		for (int l213 = 0; l213 < 2; l213 = l213 + 1) {
			iVec47[l213] = 0;
		}
		for (int l214 = 0; l214 < 2; l214 = l214 + 1) {
			iVec48[l214] = 0;
		}
		for (int l215 = 0; l215 < 2; l215 = l215 + 1) {
			fRec175[l215] = 0.0f;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			fRec174[l216] = 0.0f;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			iRec176[l217] = 0;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			iRec173[l218] = 0;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			fRec172[l219] = 0.0f;
		}
		for (int l220 = 0; l220 < 2; l220 = l220 + 1) {
			iVec49[l220] = 0;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			iVec50[l221] = 0;
		}
		for (int l222 = 0; l222 < 2; l222 = l222 + 1) {
			fRec180[l222] = 0.0f;
		}
		for (int l223 = 0; l223 < 2; l223 = l223 + 1) {
			fRec179[l223] = 0.0f;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			iRec181[l224] = 0;
		}
		for (int l225 = 0; l225 < 2; l225 = l225 + 1) {
			iRec178[l225] = 0;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			fRec177[l226] = 0.0f;
		}
		for (int l227 = 0; l227 < 2; l227 = l227 + 1) {
			iVec51[l227] = 0;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			iVec52[l228] = 0;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			fRec185[l229] = 0.0f;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			fRec184[l230] = 0.0f;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			iRec186[l231] = 0;
		}
		for (int l232 = 0; l232 < 2; l232 = l232 + 1) {
			iRec183[l232] = 0;
		}
		for (int l233 = 0; l233 < 2; l233 = l233 + 1) {
			fRec182[l233] = 0.0f;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			iVec53[l234] = 0;
		}
		for (int l235 = 0; l235 < 2; l235 = l235 + 1) {
			iVec54[l235] = 0;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fRec190[l236] = 0.0f;
		}
		for (int l237 = 0; l237 < 2; l237 = l237 + 1) {
			fRec189[l237] = 0.0f;
		}
		for (int l238 = 0; l238 < 2; l238 = l238 + 1) {
			iRec191[l238] = 0;
		}
		for (int l239 = 0; l239 < 2; l239 = l239 + 1) {
			iRec188[l239] = 0;
		}
		for (int l240 = 0; l240 < 2; l240 = l240 + 1) {
			fRec187[l240] = 0.0f;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			iVec55[l241] = 0;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			iVec56[l242] = 0;
		}
		for (int l243 = 0; l243 < 2; l243 = l243 + 1) {
			fRec195[l243] = 0.0f;
		}
		for (int l244 = 0; l244 < 2; l244 = l244 + 1) {
			fRec194[l244] = 0.0f;
		}
		for (int l245 = 0; l245 < 2; l245 = l245 + 1) {
			iRec196[l245] = 0;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			iRec193[l246] = 0;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			fRec192[l247] = 0.0f;
		}
		for (int l248 = 0; l248 < 2; l248 = l248 + 1) {
			iVec57[l248] = 0;
		}
		for (int l249 = 0; l249 < 2; l249 = l249 + 1) {
			iVec58[l249] = 0;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			fRec200[l250] = 0.0f;
		}
		for (int l251 = 0; l251 < 2; l251 = l251 + 1) {
			fRec199[l251] = 0.0f;
		}
		for (int l252 = 0; l252 < 2; l252 = l252 + 1) {
			iRec201[l252] = 0;
		}
		for (int l253 = 0; l253 < 2; l253 = l253 + 1) {
			iRec198[l253] = 0;
		}
		for (int l254 = 0; l254 < 2; l254 = l254 + 1) {
			fRec197[l254] = 0.0f;
		}
		for (int l255 = 0; l255 < 2; l255 = l255 + 1) {
			iVec59[l255] = 0;
		}
		for (int l256 = 0; l256 < 2; l256 = l256 + 1) {
			iVec60[l256] = 0;
		}
		for (int l257 = 0; l257 < 2; l257 = l257 + 1) {
			fRec205[l257] = 0.0f;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec204[l258] = 0.0f;
		}
		for (int l259 = 0; l259 < 2; l259 = l259 + 1) {
			iRec206[l259] = 0;
		}
		for (int l260 = 0; l260 < 2; l260 = l260 + 1) {
			iRec203[l260] = 0;
		}
		for (int l261 = 0; l261 < 2; l261 = l261 + 1) {
			fRec202[l261] = 0.0f;
		}
		for (int l262 = 0; l262 < 2; l262 = l262 + 1) {
			iVec61[l262] = 0;
		}
		for (int l263 = 0; l263 < 2; l263 = l263 + 1) {
			iVec62[l263] = 0;
		}
		for (int l264 = 0; l264 < 2; l264 = l264 + 1) {
			fRec210[l264] = 0.0f;
		}
		for (int l265 = 0; l265 < 2; l265 = l265 + 1) {
			fRec209[l265] = 0.0f;
		}
		for (int l266 = 0; l266 < 2; l266 = l266 + 1) {
			iRec211[l266] = 0;
		}
		for (int l267 = 0; l267 < 2; l267 = l267 + 1) {
			iRec208[l267] = 0;
		}
		for (int l268 = 0; l268 < 2; l268 = l268 + 1) {
			fRec207[l268] = 0.0f;
		}
		for (int l269 = 0; l269 < 2; l269 = l269 + 1) {
			iVec63[l269] = 0;
		}
		for (int l270 = 0; l270 < 2; l270 = l270 + 1) {
			iVec64[l270] = 0;
		}
		for (int l271 = 0; l271 < 2; l271 = l271 + 1) {
			fRec215[l271] = 0.0f;
		}
		for (int l272 = 0; l272 < 2; l272 = l272 + 1) {
			fRec214[l272] = 0.0f;
		}
		for (int l273 = 0; l273 < 2; l273 = l273 + 1) {
			iRec216[l273] = 0;
		}
		for (int l274 = 0; l274 < 2; l274 = l274 + 1) {
			iRec213[l274] = 0;
		}
		for (int l275 = 0; l275 < 2; l275 = l275 + 1) {
			fRec212[l275] = 0.0f;
		}
		for (int l276 = 0; l276 < 2; l276 = l276 + 1) {
			iVec65[l276] = 0;
		}
		for (int l277 = 0; l277 < 2; l277 = l277 + 1) {
			iVec66[l277] = 0;
		}
		for (int l278 = 0; l278 < 2; l278 = l278 + 1) {
			fRec220[l278] = 0.0f;
		}
		for (int l279 = 0; l279 < 2; l279 = l279 + 1) {
			fRec219[l279] = 0.0f;
		}
		for (int l280 = 0; l280 < 2; l280 = l280 + 1) {
			iRec221[l280] = 0;
		}
		for (int l281 = 0; l281 < 2; l281 = l281 + 1) {
			iRec218[l281] = 0;
		}
		for (int l282 = 0; l282 < 2; l282 = l282 + 1) {
			fRec217[l282] = 0.0f;
		}
		for (int l283 = 0; l283 < 2; l283 = l283 + 1) {
			iVec67[l283] = 0;
		}
		for (int l284 = 0; l284 < 2; l284 = l284 + 1) {
			iVec68[l284] = 0;
		}
		for (int l285 = 0; l285 < 2; l285 = l285 + 1) {
			fRec225[l285] = 0.0f;
		}
		for (int l286 = 0; l286 < 2; l286 = l286 + 1) {
			fRec224[l286] = 0.0f;
		}
		for (int l287 = 0; l287 < 2; l287 = l287 + 1) {
			iRec226[l287] = 0;
		}
		for (int l288 = 0; l288 < 2; l288 = l288 + 1) {
			iRec223[l288] = 0;
		}
		for (int l289 = 0; l289 < 2; l289 = l289 + 1) {
			fRec222[l289] = 0.0f;
		}
		for (int l290 = 0; l290 < 2; l290 = l290 + 1) {
			iVec69[l290] = 0;
		}
		for (int l291 = 0; l291 < 2; l291 = l291 + 1) {
			iVec70[l291] = 0;
		}
		for (int l292 = 0; l292 < 2; l292 = l292 + 1) {
			fRec230[l292] = 0.0f;
		}
		for (int l293 = 0; l293 < 2; l293 = l293 + 1) {
			fRec229[l293] = 0.0f;
		}
		for (int l294 = 0; l294 < 2; l294 = l294 + 1) {
			iRec231[l294] = 0;
		}
		for (int l295 = 0; l295 < 2; l295 = l295 + 1) {
			iRec228[l295] = 0;
		}
		for (int l296 = 0; l296 < 2; l296 = l296 + 1) {
			fRec227[l296] = 0.0f;
		}
		for (int l297 = 0; l297 < 2; l297 = l297 + 1) {
			iVec71[l297] = 0;
		}
		for (int l298 = 0; l298 < 2; l298 = l298 + 1) {
			iVec72[l298] = 0;
		}
		for (int l299 = 0; l299 < 2; l299 = l299 + 1) {
			fRec235[l299] = 0.0f;
		}
		for (int l300 = 0; l300 < 2; l300 = l300 + 1) {
			fRec234[l300] = 0.0f;
		}
		for (int l301 = 0; l301 < 2; l301 = l301 + 1) {
			iRec236[l301] = 0;
		}
		for (int l302 = 0; l302 < 2; l302 = l302 + 1) {
			iRec233[l302] = 0;
		}
		for (int l303 = 0; l303 < 2; l303 = l303 + 1) {
			fRec232[l303] = 0.0f;
		}
		for (int l304 = 0; l304 < 2; l304 = l304 + 1) {
			iVec73[l304] = 0;
		}
		for (int l305 = 0; l305 < 2; l305 = l305 + 1) {
			iVec74[l305] = 0;
		}
		for (int l306 = 0; l306 < 2; l306 = l306 + 1) {
			fRec240[l306] = 0.0f;
		}
		for (int l307 = 0; l307 < 2; l307 = l307 + 1) {
			fRec239[l307] = 0.0f;
		}
		for (int l308 = 0; l308 < 2; l308 = l308 + 1) {
			iRec241[l308] = 0;
		}
		for (int l309 = 0; l309 < 2; l309 = l309 + 1) {
			iRec238[l309] = 0;
		}
		for (int l310 = 0; l310 < 2; l310 = l310 + 1) {
			fRec237[l310] = 0.0f;
		}
		for (int l311 = 0; l311 < 2; l311 = l311 + 1) {
			iVec75[l311] = 0;
		}
		for (int l312 = 0; l312 < 2; l312 = l312 + 1) {
			iVec76[l312] = 0;
		}
		for (int l313 = 0; l313 < 2; l313 = l313 + 1) {
			fRec245[l313] = 0.0f;
		}
		for (int l314 = 0; l314 < 2; l314 = l314 + 1) {
			fRec244[l314] = 0.0f;
		}
		for (int l315 = 0; l315 < 2; l315 = l315 + 1) {
			iRec246[l315] = 0;
		}
		for (int l316 = 0; l316 < 2; l316 = l316 + 1) {
			iRec243[l316] = 0;
		}
		for (int l317 = 0; l317 < 2; l317 = l317 + 1) {
			fRec242[l317] = 0.0f;
		}
		for (int l318 = 0; l318 < 2; l318 = l318 + 1) {
			iRec170[l318] = 0;
		}
		for (int l319 = 0; l319 < 2; l319 = l319 + 1) {
			fRec248[l319] = 0.0f;
		}
		for (int l320 = 0; l320 < 2; l320 = l320 + 1) {
			fRec247[l320] = 0.0f;
		}
		for (int l321 = 0; l321 < 2; l321 = l321 + 1) {
			fRec249[l321] = 0.0f;
		}
		for (int l322 = 0; l322 < 2; l322 = l322 + 1) {
			fRec251[l322] = 0.0f;
		}
		for (int l323 = 0; l323 < 2; l323 = l323 + 1) {
			fRec252[l323] = 0.0f;
		}
		for (int l324 = 0; l324 < 2; l324 = l324 + 1) {
			iVec77[l324] = 0;
		}
		for (int l325 = 0; l325 < 2; l325 = l325 + 1) {
			iRec250[l325] = 0;
		}
		for (int l326 = 0; l326 < 2; l326 = l326 + 1) {
			iRec253[l326] = 0;
		}
		for (int l327 = 0; l327 < 2; l327 = l327 + 1) {
			fRec254[l327] = 0.0f;
		}
		for (int l328 = 0; l328 < 2; l328 = l328 + 1) {
			fRec256[l328] = 0.0f;
		}
		for (int l329 = 0; l329 < 2; l329 = l329 + 1) {
			fRec257[l329] = 0.0f;
		}
		for (int l330 = 0; l330 < 2; l330 = l330 + 1) {
			iVec78[l330] = 0;
		}
		for (int l331 = 0; l331 < 2; l331 = l331 + 1) {
			iRec255[l331] = 0;
		}
		for (int l332 = 0; l332 < 2; l332 = l332 + 1) {
			iRec258[l332] = 0;
		}
		for (int l333 = 0; l333 < 2; l333 = l333 + 1) {
			fRec259[l333] = 0.0f;
		}
		for (int l334 = 0; l334 < 2; l334 = l334 + 1) {
			fRec261[l334] = 0.0f;
		}
		for (int l335 = 0; l335 < 2; l335 = l335 + 1) {
			fRec262[l335] = 0.0f;
		}
		for (int l336 = 0; l336 < 2; l336 = l336 + 1) {
			iVec79[l336] = 0;
		}
		for (int l337 = 0; l337 < 2; l337 = l337 + 1) {
			iRec260[l337] = 0;
		}
		for (int l338 = 0; l338 < 2; l338 = l338 + 1) {
			iRec263[l338] = 0;
		}
		for (int l339 = 0; l339 < 2; l339 = l339 + 1) {
			fRec264[l339] = 0.0f;
		}
		for (int l340 = 0; l340 < 2; l340 = l340 + 1) {
			fRec266[l340] = 0.0f;
		}
		for (int l341 = 0; l341 < 2; l341 = l341 + 1) {
			fRec267[l341] = 0.0f;
		}
		for (int l342 = 0; l342 < 2; l342 = l342 + 1) {
			iVec80[l342] = 0;
		}
		for (int l343 = 0; l343 < 2; l343 = l343 + 1) {
			iRec265[l343] = 0;
		}
		for (int l344 = 0; l344 < 2; l344 = l344 + 1) {
			iRec268[l344] = 0;
		}
		for (int l345 = 0; l345 < 2; l345 = l345 + 1) {
			fRec269[l345] = 0.0f;
		}
		for (int l346 = 0; l346 < 2; l346 = l346 + 1) {
			fRec271[l346] = 0.0f;
		}
		for (int l347 = 0; l347 < 2; l347 = l347 + 1) {
			fRec272[l347] = 0.0f;
		}
		for (int l348 = 0; l348 < 2; l348 = l348 + 1) {
			iVec81[l348] = 0;
		}
		for (int l349 = 0; l349 < 2; l349 = l349 + 1) {
			iRec270[l349] = 0;
		}
		for (int l350 = 0; l350 < 2; l350 = l350 + 1) {
			iRec273[l350] = 0;
		}
		for (int l351 = 0; l351 < 2; l351 = l351 + 1) {
			fRec274[l351] = 0.0f;
		}
		for (int l352 = 0; l352 < 2; l352 = l352 + 1) {
			fRec276[l352] = 0.0f;
		}
		for (int l353 = 0; l353 < 2; l353 = l353 + 1) {
			fRec277[l353] = 0.0f;
		}
		for (int l354 = 0; l354 < 2; l354 = l354 + 1) {
			iVec82[l354] = 0;
		}
		for (int l355 = 0; l355 < 2; l355 = l355 + 1) {
			iRec275[l355] = 0;
		}
		for (int l356 = 0; l356 < 2; l356 = l356 + 1) {
			iRec278[l356] = 0;
		}
		for (int l357 = 0; l357 < 2; l357 = l357 + 1) {
			fRec279[l357] = 0.0f;
		}
		for (int l358 = 0; l358 < 2; l358 = l358 + 1) {
			fRec281[l358] = 0.0f;
		}
		for (int l359 = 0; l359 < 2; l359 = l359 + 1) {
			fRec282[l359] = 0.0f;
		}
		for (int l360 = 0; l360 < 2; l360 = l360 + 1) {
			iVec83[l360] = 0;
		}
		for (int l361 = 0; l361 < 2; l361 = l361 + 1) {
			iRec280[l361] = 0;
		}
		for (int l362 = 0; l362 < 2; l362 = l362 + 1) {
			iRec283[l362] = 0;
		}
		for (int l363 = 0; l363 < 2; l363 = l363 + 1) {
			fRec284[l363] = 0.0f;
		}
		for (int l364 = 0; l364 < 2; l364 = l364 + 1) {
			fRec286[l364] = 0.0f;
		}
		for (int l365 = 0; l365 < 2; l365 = l365 + 1) {
			fRec287[l365] = 0.0f;
		}
		for (int l366 = 0; l366 < 2; l366 = l366 + 1) {
			iVec84[l366] = 0;
		}
		for (int l367 = 0; l367 < 2; l367 = l367 + 1) {
			iRec285[l367] = 0;
		}
		for (int l368 = 0; l368 < 2; l368 = l368 + 1) {
			iRec288[l368] = 0;
		}
		for (int l369 = 0; l369 < 2; l369 = l369 + 1) {
			fRec289[l369] = 0.0f;
		}
		for (int l370 = 0; l370 < 2; l370 = l370 + 1) {
			fRec291[l370] = 0.0f;
		}
		for (int l371 = 0; l371 < 2; l371 = l371 + 1) {
			fRec292[l371] = 0.0f;
		}
		for (int l372 = 0; l372 < 2; l372 = l372 + 1) {
			iVec85[l372] = 0;
		}
		for (int l373 = 0; l373 < 2; l373 = l373 + 1) {
			iRec290[l373] = 0;
		}
		for (int l374 = 0; l374 < 2; l374 = l374 + 1) {
			iRec293[l374] = 0;
		}
		for (int l375 = 0; l375 < 2; l375 = l375 + 1) {
			fRec294[l375] = 0.0f;
		}
		for (int l376 = 0; l376 < 2; l376 = l376 + 1) {
			fRec296[l376] = 0.0f;
		}
		for (int l377 = 0; l377 < 2; l377 = l377 + 1) {
			fRec297[l377] = 0.0f;
		}
		for (int l378 = 0; l378 < 2; l378 = l378 + 1) {
			iVec86[l378] = 0;
		}
		for (int l379 = 0; l379 < 2; l379 = l379 + 1) {
			iRec295[l379] = 0;
		}
		for (int l380 = 0; l380 < 2; l380 = l380 + 1) {
			iRec298[l380] = 0;
		}
		for (int l381 = 0; l381 < 2; l381 = l381 + 1) {
			fRec299[l381] = 0.0f;
		}
		for (int l382 = 0; l382 < 2; l382 = l382 + 1) {
			fRec301[l382] = 0.0f;
		}
		for (int l383 = 0; l383 < 2; l383 = l383 + 1) {
			fRec302[l383] = 0.0f;
		}
		for (int l384 = 0; l384 < 2; l384 = l384 + 1) {
			iVec87[l384] = 0;
		}
		for (int l385 = 0; l385 < 2; l385 = l385 + 1) {
			iRec300[l385] = 0;
		}
		for (int l386 = 0; l386 < 2; l386 = l386 + 1) {
			iRec303[l386] = 0;
		}
		for (int l387 = 0; l387 < 2; l387 = l387 + 1) {
			fRec304[l387] = 0.0f;
		}
		for (int l388 = 0; l388 < 2; l388 = l388 + 1) {
			fRec306[l388] = 0.0f;
		}
		for (int l389 = 0; l389 < 2; l389 = l389 + 1) {
			fRec307[l389] = 0.0f;
		}
		for (int l390 = 0; l390 < 2; l390 = l390 + 1) {
			iVec88[l390] = 0;
		}
		for (int l391 = 0; l391 < 2; l391 = l391 + 1) {
			iRec305[l391] = 0;
		}
		for (int l392 = 0; l392 < 2; l392 = l392 + 1) {
			iRec308[l392] = 0;
		}
		for (int l393 = 0; l393 < 2; l393 = l393 + 1) {
			fRec309[l393] = 0.0f;
		}
		for (int l394 = 0; l394 < 2; l394 = l394 + 1) {
			fRec311[l394] = 0.0f;
		}
		for (int l395 = 0; l395 < 2; l395 = l395 + 1) {
			fRec312[l395] = 0.0f;
		}
		for (int l396 = 0; l396 < 2; l396 = l396 + 1) {
			iVec89[l396] = 0;
		}
		for (int l397 = 0; l397 < 2; l397 = l397 + 1) {
			iRec310[l397] = 0;
		}
		for (int l398 = 0; l398 < 2; l398 = l398 + 1) {
			iRec313[l398] = 0;
		}
		for (int l399 = 0; l399 < 2; l399 = l399 + 1) {
			fRec314[l399] = 0.0f;
		}
		for (int l400 = 0; l400 < 2; l400 = l400 + 1) {
			fRec316[l400] = 0.0f;
		}
		for (int l401 = 0; l401 < 2; l401 = l401 + 1) {
			fRec317[l401] = 0.0f;
		}
		for (int l402 = 0; l402 < 2; l402 = l402 + 1) {
			iVec90[l402] = 0;
		}
		for (int l403 = 0; l403 < 2; l403 = l403 + 1) {
			iRec315[l403] = 0;
		}
		for (int l404 = 0; l404 < 2; l404 = l404 + 1) {
			iRec318[l404] = 0;
		}
		for (int l405 = 0; l405 < 2; l405 = l405 + 1) {
			fRec319[l405] = 0.0f;
		}
		for (int l406 = 0; l406 < 2; l406 = l406 + 1) {
			fRec321[l406] = 0.0f;
		}
		for (int l407 = 0; l407 < 2; l407 = l407 + 1) {
			fRec322[l407] = 0.0f;
		}
		for (int l408 = 0; l408 < 2; l408 = l408 + 1) {
			iVec91[l408] = 0;
		}
		for (int l409 = 0; l409 < 2; l409 = l409 + 1) {
			iRec320[l409] = 0;
		}
		for (int l410 = 0; l410 < 2; l410 = l410 + 1) {
			iRec323[l410] = 0;
		}
		for (int l411 = 0; l411 < 2; l411 = l411 + 1) {
			fRec171[l411] = 0.0f;
		}
		for (int l412 = 0; l412 < 2; l412 = l412 + 1) {
			fRec169[l412] = 0.0f;
		}
		for (int l413 = 0; l413 < 2; l413 = l413 + 1) {
			fRec167[l413] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_Folder* clone() {
		return new _Folder();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("granola 0");
		ui_interface->openVerticalBox("global");
		ui_interface->openVerticalBox("index");
		ui_interface->declare(&fHbargraph0, "0", "");
		ui_interface->addHorizontalBargraph("writeIndex", &fHbargraph0, FAUSTFLOAT(0.0f), FAUSTFLOAT(239999.0f));
		ui_interface->declare(&fCheckbox1, "1", "");
		ui_interface->addCheckButton("Freeze", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("volumes");
		ui_interface->openHorizontalBox("input");
		ui_interface->declare(&fVslider1, "0", "");
		ui_interface->addVerticalSlider("gain", &fVslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.5f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider0, "1", "");
		ui_interface->addVerticalSlider("feedback", &fVslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("output");
		ui_interface->declare(&fVslider2, "0", "");
		ui_interface->declare(&fVslider2, "tooltip", "0:dry, 1:wet");
		ui_interface->addVerticalSlider("dry/wet", &fVslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->addVerticalSlider("gain", &fVslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("grains");
		ui_interface->addButton("SEED", &fButton0);
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("density", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->addHorizontalSlider("time", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "s");
		ui_interface->addHorizontalSlider("size", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.03f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->declare(&fHslider1, "unit", "semi");
		ui_interface->addHorizontalSlider("pitch", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fCheckbox0, "6", "");
		ui_interface->addCheckButton("REVERSE", &fCheckbox0);
		ui_interface->declare(&fHslider4, "7", "");
		ui_interface->addHorizontalSlider("shape", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fButton0);
		float fSlow1 = fConst3 * std::max<float>(0.01f, std::min<float>(1e+03f, float(fHslider0)));
		float fSlow2 = 1.0f / std::pow(2.0f, 0.083333336f * std::max<float>(-24.0f, std::min<float>(24.0f, float(fHslider1))));
		float fSlow3 = fConst3 * std::max<float>(0.03f, std::min<float>(5.0f, float(fHslider2)));
		int iSlow4 = ((int(float(fCheckbox0))) ? -1 : 1);
		float fSlow5 = float(fCheckbox1);
		float fSlow6 = fConst3 * std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider0)));
		float fSlow7 = 1.0f - fSlow5;
		float fSlow8 = fConst3 * std::max<float>(-1.5f, std::min<float>(1.0f, float(fVslider1)));
		float fSlow9 = fConst3 * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider3)));
		float fSlow10 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider4)));
		float fSlow11 = 1.0f - std::min<float>(3.0f * fSlow10, 1.0f);
		float fSlow12 = std::max<float>(1.5f * fSlow10 + -0.5f, 0.0f);
		float fSlow13 = fConst3 * std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider2)));
		float fSlow14 = fConst3 * std::max<float>(-1.0f, std::min<float>(1.0f, float(fVslider3)));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fVec1[0] = fSlow0;
			float fTemp0 = fSlow0 - fVec1[1];
			fRec7[0] = fSlow1 + fConst4 * fRec7[1];
			iRec8[0] = (iVec0[1] + iRec8[1]) % int(fConst0 / std::max<float>(fRec7[0], 0.01f));
			float fTemp1 = fTemp0 * float(fTemp0 > 0.0f) + float((fRec7[0] >= 0.01f) * (iRec8[0] <= iRec8[1]));
			float fTemp2 = float(iRec3[1]) * fTemp1;
			int iTemp3 = 1.0f == fTemp2;
			iVec2[0] = iTemp3;
			int iTemp4 = iTemp3 & (fRec5[1] == 0.0f);
			iVec3[0] = iTemp4;
			int iTemp5 = (iVec2[1] <= 0) & (iTemp3 > 0);
			int iTemp6 = 1 - iTemp5;
			float fTemp7 = float(iTemp6);
			float fTemp8 = float(iTemp5);
			fRec11[0] = fSlow3 + fConst4 * fRec11[1];
			fRec10[0] = fTemp7 * fRec10[1] + fRec11[0] * fTemp8;
			int iTemp9 = int(fConst0 * fRec10[0]);
			fRec9[0] = fRec9[1] * fTemp7 + fSlow2 * fTemp8 * float(iTemp9);
			int iTemp10 = int(fRec9[0]);
			int iTemp11 = std::max<int>(1, iTemp10 + -1);
			iRec12[0] = iTemp6 * iRec12[1] + iSlow4 * iTemp5;
			int iTemp12 = iTemp9 + -1;
			int iTemp13 = iRec12[0] * iTemp12;
			int iTemp14 = iTemp13 >= 0;
			iRec6[0] = ((iTemp4 > iVec3[1]) ? ((iTemp14) ? 0 : iTemp11) : std::min<int>(iTemp11, std::max<int>(0, iRec6[1] + ((iTemp14) ? 1 : -1))));
			fRec5[0] = float(iRec6[0] * (iRec6[0] != iRec6[1])) * float(std::abs(iTemp13)) / float(iTemp11);
			int iTemp15 = fRec5[0] > 0.0f;
			int iTemp16 = 2.0f == fTemp2;
			iVec4[0] = iTemp16;
			int iTemp17 = iTemp16 & (fRec13[1] == 0.0f);
			iVec5[0] = iTemp17;
			int iTemp18 = (iVec4[1] <= 0) & (iTemp16 > 0);
			int iTemp19 = 1 - iTemp18;
			float fTemp20 = float(iTemp19);
			float fTemp21 = float(iTemp18);
			fRec16[0] = fTemp20 * fRec16[1] + fRec11[0] * fTemp21;
			int iTemp22 = int(fConst0 * fRec16[0]);
			fRec15[0] = fRec15[1] * fTemp20 + fSlow2 * fTemp21 * float(iTemp22);
			int iTemp23 = int(fRec15[0]);
			int iTemp24 = std::max<int>(1, iTemp23 + -1);
			iRec17[0] = iTemp19 * iRec17[1] + iSlow4 * iTemp18;
			int iTemp25 = iTemp22 + -1;
			int iTemp26 = iRec17[0] * iTemp25;
			int iTemp27 = iTemp26 >= 0;
			iRec14[0] = ((iTemp17 > iVec5[1]) ? ((iTemp27) ? 0 : iTemp24) : std::min<int>(iTemp24, std::max<int>(0, iRec14[1] + ((iTemp27) ? 1 : -1))));
			fRec13[0] = float(iRec14[0] * (iRec14[0] != iRec14[1])) * float(std::abs(iTemp26)) / float(iTemp24);
			int iTemp28 = fRec13[0] > 0.0f;
			int iTemp29 = 3.0f == fTemp2;
			iVec6[0] = iTemp29;
			int iTemp30 = iTemp29 & (fRec18[1] == 0.0f);
			iVec7[0] = iTemp30;
			int iTemp31 = (iVec6[1] <= 0) & (iTemp29 > 0);
			int iTemp32 = 1 - iTemp31;
			float fTemp33 = float(iTemp32);
			float fTemp34 = float(iTemp31);
			fRec21[0] = fTemp33 * fRec21[1] + fRec11[0] * fTemp34;
			int iTemp35 = int(fConst0 * fRec21[0]);
			fRec20[0] = fRec20[1] * fTemp33 + fSlow2 * fTemp34 * float(iTemp35);
			int iTemp36 = int(fRec20[0]);
			int iTemp37 = std::max<int>(1, iTemp36 + -1);
			iRec22[0] = iTemp32 * iRec22[1] + iSlow4 * iTemp31;
			int iTemp38 = iTemp35 + -1;
			int iTemp39 = iRec22[0] * iTemp38;
			int iTemp40 = iTemp39 >= 0;
			iRec19[0] = ((iTemp30 > iVec7[1]) ? ((iTemp40) ? 0 : iTemp37) : std::min<int>(iTemp37, std::max<int>(0, iRec19[1] + ((iTemp40) ? 1 : -1))));
			fRec18[0] = float(iRec19[0] * (iRec19[0] != iRec19[1])) * float(std::abs(iTemp39)) / float(iTemp37);
			int iTemp41 = fRec18[0] > 0.0f;
			int iTemp42 = 4.0f == fTemp2;
			iVec8[0] = iTemp42;
			int iTemp43 = iTemp42 & (fRec23[1] == 0.0f);
			iVec9[0] = iTemp43;
			int iTemp44 = (iVec8[1] <= 0) & (iTemp42 > 0);
			int iTemp45 = 1 - iTemp44;
			float fTemp46 = float(iTemp45);
			float fTemp47 = float(iTemp44);
			fRec26[0] = fTemp46 * fRec26[1] + fRec11[0] * fTemp47;
			int iTemp48 = int(fConst0 * fRec26[0]);
			fRec25[0] = fRec25[1] * fTemp46 + fSlow2 * fTemp47 * float(iTemp48);
			int iTemp49 = int(fRec25[0]);
			int iTemp50 = std::max<int>(1, iTemp49 + -1);
			iRec27[0] = iTemp45 * iRec27[1] + iSlow4 * iTemp44;
			int iTemp51 = iTemp48 + -1;
			int iTemp52 = iRec27[0] * iTemp51;
			int iTemp53 = iTemp52 >= 0;
			iRec24[0] = ((iTemp43 > iVec9[1]) ? ((iTemp53) ? 0 : iTemp50) : std::min<int>(iTemp50, std::max<int>(0, iRec24[1] + ((iTemp53) ? 1 : -1))));
			fRec23[0] = float(iRec24[0] * (iRec24[0] != iRec24[1])) * float(std::abs(iTemp52)) / float(iTemp50);
			int iTemp54 = fRec23[0] > 0.0f;
			int iTemp55 = 5.0f == fTemp2;
			iVec10[0] = iTemp55;
			int iTemp56 = iTemp55 & (fRec28[1] == 0.0f);
			iVec11[0] = iTemp56;
			int iTemp57 = (iVec10[1] <= 0) & (iTemp55 > 0);
			int iTemp58 = 1 - iTemp57;
			float fTemp59 = float(iTemp58);
			float fTemp60 = float(iTemp57);
			fRec31[0] = fTemp59 * fRec31[1] + fRec11[0] * fTemp60;
			int iTemp61 = int(fConst0 * fRec31[0]);
			fRec30[0] = fRec30[1] * fTemp59 + fSlow2 * fTemp60 * float(iTemp61);
			int iTemp62 = int(fRec30[0]);
			int iTemp63 = std::max<int>(1, iTemp62 + -1);
			iRec32[0] = iTemp58 * iRec32[1] + iSlow4 * iTemp57;
			int iTemp64 = iTemp61 + -1;
			int iTemp65 = iRec32[0] * iTemp64;
			int iTemp66 = iTemp65 >= 0;
			iRec29[0] = ((iTemp56 > iVec11[1]) ? ((iTemp66) ? 0 : iTemp63) : std::min<int>(iTemp63, std::max<int>(0, iRec29[1] + ((iTemp66) ? 1 : -1))));
			fRec28[0] = float(iRec29[0] * (iRec29[0] != iRec29[1])) * float(std::abs(iTemp65)) / float(iTemp63);
			int iTemp67 = fRec28[0] > 0.0f;
			int iTemp68 = 6.0f == fTemp2;
			iVec12[0] = iTemp68;
			int iTemp69 = iTemp68 & (fRec33[1] == 0.0f);
			iVec13[0] = iTemp69;
			int iTemp70 = (iVec12[1] <= 0) & (iTemp68 > 0);
			int iTemp71 = 1 - iTemp70;
			float fTemp72 = float(iTemp71);
			float fTemp73 = float(iTemp70);
			fRec36[0] = fTemp72 * fRec36[1] + fRec11[0] * fTemp73;
			int iTemp74 = int(fConst0 * fRec36[0]);
			fRec35[0] = fRec35[1] * fTemp72 + fSlow2 * fTemp73 * float(iTemp74);
			int iTemp75 = int(fRec35[0]);
			int iTemp76 = std::max<int>(1, iTemp75 + -1);
			iRec37[0] = iTemp71 * iRec37[1] + iSlow4 * iTemp70;
			int iTemp77 = iTemp74 + -1;
			int iTemp78 = iRec37[0] * iTemp77;
			int iTemp79 = iTemp78 >= 0;
			iRec34[0] = ((iTemp69 > iVec13[1]) ? ((iTemp79) ? 0 : iTemp76) : std::min<int>(iTemp76, std::max<int>(0, iRec34[1] + ((iTemp79) ? 1 : -1))));
			fRec33[0] = float(iRec34[0] * (iRec34[0] != iRec34[1])) * float(std::abs(iTemp78)) / float(iTemp76);
			int iTemp80 = fRec33[0] > 0.0f;
			int iTemp81 = 7.0f == fTemp2;
			iVec14[0] = iTemp81;
			int iTemp82 = iTemp81 & (fRec38[1] == 0.0f);
			iVec15[0] = iTemp82;
			int iTemp83 = (iVec14[1] <= 0) & (iTemp81 > 0);
			int iTemp84 = 1 - iTemp83;
			float fTemp85 = float(iTemp84);
			float fTemp86 = float(iTemp83);
			fRec41[0] = fTemp85 * fRec41[1] + fRec11[0] * fTemp86;
			int iTemp87 = int(fConst0 * fRec41[0]);
			fRec40[0] = fRec40[1] * fTemp85 + fSlow2 * fTemp86 * float(iTemp87);
			int iTemp88 = int(fRec40[0]);
			int iTemp89 = std::max<int>(1, iTemp88 + -1);
			iRec42[0] = iTemp84 * iRec42[1] + iSlow4 * iTemp83;
			int iTemp90 = iTemp87 + -1;
			int iTemp91 = iRec42[0] * iTemp90;
			int iTemp92 = iTemp91 >= 0;
			iRec39[0] = ((iTemp82 > iVec15[1]) ? ((iTemp92) ? 0 : iTemp89) : std::min<int>(iTemp89, std::max<int>(0, iRec39[1] + ((iTemp92) ? 1 : -1))));
			fRec38[0] = float(iRec39[0] * (iRec39[0] != iRec39[1])) * float(std::abs(iTemp91)) / float(iTemp89);
			int iTemp93 = fRec38[0] > 0.0f;
			int iTemp94 = 8.0f == fTemp2;
			iVec16[0] = iTemp94;
			int iTemp95 = iTemp94 & (fRec43[1] == 0.0f);
			iVec17[0] = iTemp95;
			int iTemp96 = (iVec16[1] <= 0) & (iTemp94 > 0);
			int iTemp97 = 1 - iTemp96;
			float fTemp98 = float(iTemp97);
			float fTemp99 = float(iTemp96);
			fRec46[0] = fTemp98 * fRec46[1] + fRec11[0] * fTemp99;
			int iTemp100 = int(fConst0 * fRec46[0]);
			fRec45[0] = fRec45[1] * fTemp98 + fSlow2 * fTemp99 * float(iTemp100);
			int iTemp101 = int(fRec45[0]);
			int iTemp102 = std::max<int>(1, iTemp101 + -1);
			iRec47[0] = iTemp97 * iRec47[1] + iSlow4 * iTemp96;
			int iTemp103 = iTemp100 + -1;
			int iTemp104 = iRec47[0] * iTemp103;
			int iTemp105 = iTemp104 >= 0;
			iRec44[0] = ((iTemp95 > iVec17[1]) ? ((iTemp105) ? 0 : iTemp102) : std::min<int>(iTemp102, std::max<int>(0, iRec44[1] + ((iTemp105) ? 1 : -1))));
			fRec43[0] = float(iRec44[0] * (iRec44[0] != iRec44[1])) * float(std::abs(iTemp104)) / float(iTemp102);
			int iTemp106 = fRec43[0] > 0.0f;
			int iTemp107 = 9.0f == fTemp2;
			iVec18[0] = iTemp107;
			int iTemp108 = iTemp107 & (fRec48[1] == 0.0f);
			iVec19[0] = iTemp108;
			int iTemp109 = (iVec18[1] <= 0) & (iTemp107 > 0);
			int iTemp110 = 1 - iTemp109;
			float fTemp111 = float(iTemp110);
			float fTemp112 = float(iTemp109);
			fRec51[0] = fTemp111 * fRec51[1] + fRec11[0] * fTemp112;
			int iTemp113 = int(fConst0 * fRec51[0]);
			fRec50[0] = fRec50[1] * fTemp111 + fSlow2 * fTemp112 * float(iTemp113);
			int iTemp114 = int(fRec50[0]);
			int iTemp115 = std::max<int>(1, iTemp114 + -1);
			iRec52[0] = iTemp110 * iRec52[1] + iSlow4 * iTemp109;
			int iTemp116 = iTemp113 + -1;
			int iTemp117 = iRec52[0] * iTemp116;
			int iTemp118 = iTemp117 >= 0;
			iRec49[0] = ((iTemp108 > iVec19[1]) ? ((iTemp118) ? 0 : iTemp115) : std::min<int>(iTemp115, std::max<int>(0, iRec49[1] + ((iTemp118) ? 1 : -1))));
			fRec48[0] = float(iRec49[0] * (iRec49[0] != iRec49[1])) * float(std::abs(iTemp117)) / float(iTemp115);
			int iTemp119 = fRec48[0] > 0.0f;
			int iTemp120 = 1e+01f == fTemp2;
			iVec20[0] = iTemp120;
			int iTemp121 = iTemp120 & (fRec53[1] == 0.0f);
			iVec21[0] = iTemp121;
			int iTemp122 = (iVec20[1] <= 0) & (iTemp120 > 0);
			int iTemp123 = 1 - iTemp122;
			float fTemp124 = float(iTemp123);
			float fTemp125 = float(iTemp122);
			fRec56[0] = fTemp124 * fRec56[1] + fRec11[0] * fTemp125;
			int iTemp126 = int(fConst0 * fRec56[0]);
			fRec55[0] = fRec55[1] * fTemp124 + fSlow2 * fTemp125 * float(iTemp126);
			int iTemp127 = int(fRec55[0]);
			int iTemp128 = std::max<int>(1, iTemp127 + -1);
			iRec57[0] = iTemp123 * iRec57[1] + iSlow4 * iTemp122;
			int iTemp129 = iTemp126 + -1;
			int iTemp130 = iRec57[0] * iTemp129;
			int iTemp131 = iTemp130 >= 0;
			iRec54[0] = ((iTemp121 > iVec21[1]) ? ((iTemp131) ? 0 : iTemp128) : std::min<int>(iTemp128, std::max<int>(0, iRec54[1] + ((iTemp131) ? 1 : -1))));
			fRec53[0] = float(iRec54[0] * (iRec54[0] != iRec54[1])) * float(std::abs(iTemp130)) / float(iTemp128);
			int iTemp132 = fRec53[0] > 0.0f;
			int iTemp133 = 11.0f == fTemp2;
			iVec22[0] = iTemp133;
			int iTemp134 = iTemp133 & (fRec58[1] == 0.0f);
			iVec23[0] = iTemp134;
			int iTemp135 = (iVec22[1] <= 0) & (iTemp133 > 0);
			int iTemp136 = 1 - iTemp135;
			float fTemp137 = float(iTemp136);
			float fTemp138 = float(iTemp135);
			fRec61[0] = fTemp137 * fRec61[1] + fRec11[0] * fTemp138;
			int iTemp139 = int(fConst0 * fRec61[0]);
			fRec60[0] = fRec60[1] * fTemp137 + fSlow2 * fTemp138 * float(iTemp139);
			int iTemp140 = int(fRec60[0]);
			int iTemp141 = std::max<int>(1, iTemp140 + -1);
			iRec62[0] = iTemp136 * iRec62[1] + iSlow4 * iTemp135;
			int iTemp142 = iTemp139 + -1;
			int iTemp143 = iRec62[0] * iTemp142;
			int iTemp144 = iTemp143 >= 0;
			iRec59[0] = ((iTemp134 > iVec23[1]) ? ((iTemp144) ? 0 : iTemp141) : std::min<int>(iTemp141, std::max<int>(0, iRec59[1] + ((iTemp144) ? 1 : -1))));
			fRec58[0] = float(iRec59[0] * (iRec59[0] != iRec59[1])) * float(std::abs(iTemp143)) / float(iTemp141);
			int iTemp145 = fRec58[0] > 0.0f;
			int iTemp146 = 12.0f == fTemp2;
			iVec24[0] = iTemp146;
			int iTemp147 = iTemp146 & (fRec63[1] == 0.0f);
			iVec25[0] = iTemp147;
			int iTemp148 = (iVec24[1] <= 0) & (iTemp146 > 0);
			int iTemp149 = 1 - iTemp148;
			float fTemp150 = float(iTemp149);
			float fTemp151 = float(iTemp148);
			fRec66[0] = fTemp150 * fRec66[1] + fRec11[0] * fTemp151;
			int iTemp152 = int(fConst0 * fRec66[0]);
			fRec65[0] = fRec65[1] * fTemp150 + fSlow2 * fTemp151 * float(iTemp152);
			int iTemp153 = int(fRec65[0]);
			int iTemp154 = std::max<int>(1, iTemp153 + -1);
			iRec67[0] = iTemp149 * iRec67[1] + iSlow4 * iTemp148;
			int iTemp155 = iTemp152 + -1;
			int iTemp156 = iRec67[0] * iTemp155;
			int iTemp157 = iTemp156 >= 0;
			iRec64[0] = ((iTemp147 > iVec25[1]) ? ((iTemp157) ? 0 : iTemp154) : std::min<int>(iTemp154, std::max<int>(0, iRec64[1] + ((iTemp157) ? 1 : -1))));
			fRec63[0] = float(iRec64[0] * (iRec64[0] != iRec64[1])) * float(std::abs(iTemp156)) / float(iTemp154);
			int iTemp158 = fRec63[0] > 0.0f;
			int iTemp159 = 13.0f == fTemp2;
			iVec26[0] = iTemp159;
			int iTemp160 = iTemp159 & (fRec68[1] == 0.0f);
			iVec27[0] = iTemp160;
			int iTemp161 = (iVec26[1] <= 0) & (iTemp159 > 0);
			int iTemp162 = 1 - iTemp161;
			float fTemp163 = float(iTemp162);
			float fTemp164 = float(iTemp161);
			fRec71[0] = fTemp163 * fRec71[1] + fRec11[0] * fTemp164;
			int iTemp165 = int(fConst0 * fRec71[0]);
			fRec70[0] = fRec70[1] * fTemp163 + fSlow2 * fTemp164 * float(iTemp165);
			int iTemp166 = int(fRec70[0]);
			int iTemp167 = std::max<int>(1, iTemp166 + -1);
			iRec72[0] = iTemp162 * iRec72[1] + iSlow4 * iTemp161;
			int iTemp168 = iTemp165 + -1;
			int iTemp169 = iRec72[0] * iTemp168;
			int iTemp170 = iTemp169 >= 0;
			iRec69[0] = ((iTemp160 > iVec27[1]) ? ((iTemp170) ? 0 : iTemp167) : std::min<int>(iTemp167, std::max<int>(0, iRec69[1] + ((iTemp170) ? 1 : -1))));
			fRec68[0] = float(iRec69[0] * (iRec69[0] != iRec69[1])) * float(std::abs(iTemp169)) / float(iTemp167);
			int iTemp171 = fRec68[0] > 0.0f;
			int iTemp172 = 14.0f == fTemp2;
			iVec28[0] = iTemp172;
			int iTemp173 = iTemp172 & (fRec73[1] == 0.0f);
			iVec29[0] = iTemp173;
			int iTemp174 = (iVec28[1] <= 0) & (iTemp172 > 0);
			int iTemp175 = 1 - iTemp174;
			float fTemp176 = float(iTemp175);
			float fTemp177 = float(iTemp174);
			fRec76[0] = fTemp176 * fRec76[1] + fRec11[0] * fTemp177;
			int iTemp178 = int(fConst0 * fRec76[0]);
			fRec75[0] = fRec75[1] * fTemp176 + fSlow2 * fTemp177 * float(iTemp178);
			int iTemp179 = int(fRec75[0]);
			int iTemp180 = std::max<int>(1, iTemp179 + -1);
			iRec77[0] = iTemp175 * iRec77[1] + iSlow4 * iTemp174;
			int iTemp181 = iTemp178 + -1;
			int iTemp182 = iRec77[0] * iTemp181;
			int iTemp183 = iTemp182 >= 0;
			iRec74[0] = ((iTemp173 > iVec29[1]) ? ((iTemp183) ? 0 : iTemp180) : std::min<int>(iTemp180, std::max<int>(0, iRec74[1] + ((iTemp183) ? 1 : -1))));
			fRec73[0] = float(iRec74[0] * (iRec74[0] != iRec74[1])) * float(std::abs(iTemp182)) / float(iTemp180);
			int iTemp184 = fRec73[0] > 0.0f;
			int iTemp185 = 15.0f == fTemp2;
			iVec30[0] = iTemp185;
			int iTemp186 = iTemp185 & (fRec78[1] == 0.0f);
			iVec31[0] = iTemp186;
			int iTemp187 = (iVec30[1] <= 0) & (iTemp185 > 0);
			int iTemp188 = 1 - iTemp187;
			float fTemp189 = float(iTemp188);
			float fTemp190 = float(iTemp187);
			fRec81[0] = fTemp189 * fRec81[1] + fRec11[0] * fTemp190;
			int iTemp191 = int(fConst0 * fRec81[0]);
			fRec80[0] = fRec80[1] * fTemp189 + fSlow2 * fTemp190 * float(iTemp191);
			int iTemp192 = int(fRec80[0]);
			int iTemp193 = std::max<int>(1, iTemp192 + -1);
			iRec82[0] = iTemp188 * iRec82[1] + iSlow4 * iTemp187;
			int iTemp194 = iTemp191 + -1;
			int iTemp195 = iRec82[0] * iTemp194;
			int iTemp196 = iTemp195 >= 0;
			iRec79[0] = ((iTemp186 > iVec31[1]) ? ((iTemp196) ? 0 : iTemp193) : std::min<int>(iTemp193, std::max<int>(0, iRec79[1] + ((iTemp196) ? 1 : -1))));
			fRec78[0] = float(iRec79[0] * (iRec79[0] != iRec79[1])) * float(std::abs(iTemp195)) / float(iTemp193);
			int iTemp197 = fRec78[0] > 0.0f;
			iRec3[0] = std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(1 - iTemp15, 2 * (1 - iTemp28)), 3 * (1 - iTemp41)), 4 * (1 - iTemp54)), 5 * (1 - iTemp67)), 6 * (1 - iTemp80)), 7 * (1 - iTemp93)), 8 * (1 - iTemp106)), 9 * (1 - iTemp119)), 10 * (1 - iTemp132)), 11 * (1 - iTemp145)), 12 * (1 - iTemp158)), 13 * (1 - iTemp171)), 14 * (1 - iTemp184)), 15 * (1 - iTemp197));
			fRec83[0] = std::fmod(fRec83[1] + 1.0f - fSlow5, 2.4e+05f);
			int iTemp198 = int(fRec83[0]);
			fHbargraph0 = FAUSTFLOAT(float(iTemp198));
			int iTemp199 = iTemp198;
			int iTemp200 = std::max<int>(0, std::min<int>(iTemp199, 239999));
			fRec84[0] = fSlow6 + fConst4 * fRec84[1];
			float fTemp201 = fRec84[0] * fRec0[1];
			float fTemp202 = std::fabs(fTemp201);
			float fTemp203 = ((fTemp202 > fRec86[1]) ? fConst8 : fConst7);
			fRec86[0] = fTemp202 * (1.0f - fTemp203) + fRec86[1] * fTemp203;
			fRec85[0] = fConst5 * fRec85[1] - fConst6 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec86[0])) + 6.0f, 0.0f);
			fRec87[0] = fSlow8 + fConst4 * fRec87[1];
			float fTemp204 = std::exp(4.6051702f * fRec87[0]);
			float fTemp205 = fTemp201 * std::pow(1e+01f, 0.05f * fRec85[0]) + fSlow7 * float(input0[i0]) * fTemp204;
			ftbl0[iTemp200] = fTemp205;
			fRec89[0] = fSlow9 + fConst4 * fRec89[1];
			fRec90[0] = std::fmod(fTemp1 + fRec90[1], 15.0f);
			float fTemp206 = float(iTemp199) + 1.6e+04f * fRec89[0] * (fRec90[0] + 1.0f);
			fRec88[0] = fTemp7 * fRec88[1] + fTemp8 * fTemp206;
			fRec92[0] = fTemp7 * fRec92[1] + fSlow11 * fTemp8;
			fRec93[0] = fTemp7 * fRec93[1] + fSlow12 * (1.0f - fRec92[0]) * fTemp8;
			float fTemp207 = fRec92[0] + fRec93[0];
			float fTemp208 = float(iTemp12);
			float fTemp209 = 1.0f - fTemp207;
			int iTemp210 = iTemp15 & ((iRec12[0] < 0) ? fRec5[0] > (fTemp208 * fTemp209) : fRec5[0] < (fTemp207 * fTemp208));
			iVec32[0] = iTemp210;
			iRec91[0] = iTemp210 + iRec91[1] * (iVec32[1] >= iTemp210);
			float fTemp211 = float(iTemp10);
			iRec94[0] = (iRec94[1] + 1) * (iTemp210 == 0);
			fRec95[0] = fTemp20 * fRec95[1] + fTemp21 * fTemp206;
			fRec97[0] = fTemp20 * fRec97[1] + fSlow11 * fTemp21;
			fRec98[0] = fTemp20 * fRec98[1] + fSlow12 * (1.0f - fRec97[0]) * fTemp21;
			float fTemp212 = fRec97[0] + fRec98[0];
			float fTemp213 = float(iTemp25);
			float fTemp214 = 1.0f - fTemp212;
			int iTemp215 = iTemp28 & ((iRec17[0] < 0) ? fRec13[0] > (fTemp213 * fTemp214) : fRec13[0] < (fTemp212 * fTemp213));
			iVec33[0] = iTemp215;
			iRec96[0] = iTemp215 + iRec96[1] * (iVec33[1] >= iTemp215);
			float fTemp216 = float(iTemp23);
			iRec99[0] = (iRec99[1] + 1) * (iTemp215 == 0);
			fRec100[0] = fTemp33 * fRec100[1] + fTemp34 * fTemp206;
			fRec102[0] = fTemp33 * fRec102[1] + fSlow11 * fTemp34;
			fRec103[0] = fTemp33 * fRec103[1] + fSlow12 * (1.0f - fRec102[0]) * fTemp34;
			float fTemp217 = fRec102[0] + fRec103[0];
			float fTemp218 = float(iTemp38);
			float fTemp219 = 1.0f - fTemp217;
			int iTemp220 = iTemp41 & ((iRec22[0] < 0) ? fRec18[0] > (fTemp218 * fTemp219) : fRec18[0] < (fTemp217 * fTemp218));
			iVec34[0] = iTemp220;
			iRec101[0] = iTemp220 + iRec101[1] * (iVec34[1] >= iTemp220);
			float fTemp221 = float(iTemp36);
			iRec104[0] = (iRec104[1] + 1) * (iTemp220 == 0);
			fRec105[0] = fTemp46 * fRec105[1] + fTemp47 * fTemp206;
			fRec107[0] = fTemp46 * fRec107[1] + fSlow11 * fTemp47;
			fRec108[0] = fTemp46 * fRec108[1] + fSlow12 * (1.0f - fRec107[0]) * fTemp47;
			float fTemp222 = fRec107[0] + fRec108[0];
			float fTemp223 = float(iTemp51);
			float fTemp224 = 1.0f - fTemp222;
			int iTemp225 = iTemp54 & ((iRec27[0] < 0) ? fRec23[0] > (fTemp223 * fTemp224) : fRec23[0] < (fTemp222 * fTemp223));
			iVec35[0] = iTemp225;
			iRec106[0] = iTemp225 + iRec106[1] * (iVec35[1] >= iTemp225);
			float fTemp226 = float(iTemp49);
			iRec109[0] = (iRec109[1] + 1) * (iTemp225 == 0);
			fRec110[0] = fTemp59 * fRec110[1] + fTemp60 * fTemp206;
			fRec112[0] = fTemp59 * fRec112[1] + fSlow11 * fTemp60;
			fRec113[0] = fTemp59 * fRec113[1] + fSlow12 * (1.0f - fRec112[0]) * fTemp60;
			float fTemp227 = fRec112[0] + fRec113[0];
			float fTemp228 = float(iTemp64);
			float fTemp229 = 1.0f - fTemp227;
			int iTemp230 = iTemp67 & ((iRec32[0] < 0) ? fRec28[0] > (fTemp228 * fTemp229) : fRec28[0] < (fTemp227 * fTemp228));
			iVec36[0] = iTemp230;
			iRec111[0] = iTemp230 + iRec111[1] * (iVec36[1] >= iTemp230);
			float fTemp231 = float(iTemp62);
			iRec114[0] = (iRec114[1] + 1) * (iTemp230 == 0);
			fRec115[0] = fTemp72 * fRec115[1] + fTemp73 * fTemp206;
			fRec117[0] = fTemp72 * fRec117[1] + fSlow11 * fTemp73;
			fRec118[0] = fTemp72 * fRec118[1] + fSlow12 * (1.0f - fRec117[0]) * fTemp73;
			float fTemp232 = fRec117[0] + fRec118[0];
			float fTemp233 = float(iTemp77);
			float fTemp234 = 1.0f - fTemp232;
			int iTemp235 = iTemp80 & ((iRec37[0] < 0) ? fRec33[0] > (fTemp233 * fTemp234) : fRec33[0] < (fTemp232 * fTemp233));
			iVec37[0] = iTemp235;
			iRec116[0] = iTemp235 + iRec116[1] * (iVec37[1] >= iTemp235);
			float fTemp236 = float(iTemp75);
			iRec119[0] = (iRec119[1] + 1) * (iTemp235 == 0);
			fRec120[0] = fTemp85 * fRec120[1] + fTemp86 * fTemp206;
			fRec122[0] = fTemp85 * fRec122[1] + fSlow11 * fTemp86;
			fRec123[0] = fTemp85 * fRec123[1] + fSlow12 * (1.0f - fRec122[0]) * fTemp86;
			float fTemp237 = fRec122[0] + fRec123[0];
			float fTemp238 = float(iTemp90);
			float fTemp239 = 1.0f - fTemp237;
			int iTemp240 = iTemp93 & ((iRec42[0] < 0) ? fRec38[0] > (fTemp238 * fTemp239) : fRec38[0] < (fTemp237 * fTemp238));
			iVec38[0] = iTemp240;
			iRec121[0] = iTemp240 + iRec121[1] * (iVec38[1] >= iTemp240);
			float fTemp241 = float(iTemp88);
			iRec124[0] = (iRec124[1] + 1) * (iTemp240 == 0);
			fRec125[0] = fTemp98 * fRec125[1] + fTemp99 * fTemp206;
			fRec127[0] = fTemp98 * fRec127[1] + fSlow11 * fTemp99;
			fRec128[0] = fTemp98 * fRec128[1] + fSlow12 * (1.0f - fRec127[0]) * fTemp99;
			float fTemp242 = fRec127[0] + fRec128[0];
			float fTemp243 = float(iTemp103);
			float fTemp244 = 1.0f - fTemp242;
			int iTemp245 = iTemp106 & ((iRec47[0] < 0) ? fRec43[0] > (fTemp243 * fTemp244) : fRec43[0] < (fTemp242 * fTemp243));
			iVec39[0] = iTemp245;
			iRec126[0] = iTemp245 + iRec126[1] * (iVec39[1] >= iTemp245);
			float fTemp246 = float(iTemp101);
			iRec129[0] = (iRec129[1] + 1) * (iTemp245 == 0);
			fRec130[0] = fTemp111 * fRec130[1] + fTemp112 * fTemp206;
			fRec132[0] = fTemp111 * fRec132[1] + fSlow11 * fTemp112;
			fRec133[0] = fTemp111 * fRec133[1] + fSlow12 * (1.0f - fRec132[0]) * fTemp112;
			float fTemp247 = fRec132[0] + fRec133[0];
			float fTemp248 = float(iTemp116);
			float fTemp249 = 1.0f - fTemp247;
			int iTemp250 = iTemp119 & ((iRec52[0] < 0) ? fRec48[0] > (fTemp248 * fTemp249) : fRec48[0] < (fTemp247 * fTemp248));
			iVec40[0] = iTemp250;
			iRec131[0] = iTemp250 + iRec131[1] * (iVec40[1] >= iTemp250);
			float fTemp251 = float(iTemp114);
			iRec134[0] = (iRec134[1] + 1) * (iTemp250 == 0);
			fRec135[0] = fTemp124 * fRec135[1] + fTemp125 * fTemp206;
			fRec137[0] = fTemp124 * fRec137[1] + fSlow11 * fTemp125;
			fRec138[0] = fTemp124 * fRec138[1] + fSlow12 * (1.0f - fRec137[0]) * fTemp125;
			float fTemp252 = fRec137[0] + fRec138[0];
			float fTemp253 = float(iTemp129);
			float fTemp254 = 1.0f - fTemp252;
			int iTemp255 = iTemp132 & ((iRec57[0] < 0) ? fRec53[0] > (fTemp253 * fTemp254) : fRec53[0] < (fTemp252 * fTemp253));
			iVec41[0] = iTemp255;
			iRec136[0] = iTemp255 + iRec136[1] * (iVec41[1] >= iTemp255);
			float fTemp256 = float(iTemp127);
			iRec139[0] = (iRec139[1] + 1) * (iTemp255 == 0);
			fRec140[0] = fTemp137 * fRec140[1] + fTemp138 * fTemp206;
			fRec142[0] = fTemp137 * fRec142[1] + fSlow11 * fTemp138;
			fRec143[0] = fTemp137 * fRec143[1] + fSlow12 * (1.0f - fRec142[0]) * fTemp138;
			float fTemp257 = fRec142[0] + fRec143[0];
			float fTemp258 = float(iTemp142);
			float fTemp259 = 1.0f - fTemp257;
			int iTemp260 = iTemp145 & ((iRec62[0] < 0) ? fRec58[0] > (fTemp258 * fTemp259) : fRec58[0] < (fTemp257 * fTemp258));
			iVec42[0] = iTemp260;
			iRec141[0] = iTemp260 + iRec141[1] * (iVec42[1] >= iTemp260);
			float fTemp261 = float(iTemp140);
			iRec144[0] = (iRec144[1] + 1) * (iTemp260 == 0);
			fRec145[0] = fTemp150 * fRec145[1] + fTemp151 * fTemp206;
			fRec147[0] = fTemp150 * fRec147[1] + fSlow11 * fTemp151;
			fRec148[0] = fTemp150 * fRec148[1] + fSlow12 * (1.0f - fRec147[0]) * fTemp151;
			float fTemp262 = fRec147[0] + fRec148[0];
			float fTemp263 = float(iTemp155);
			float fTemp264 = 1.0f - fTemp262;
			int iTemp265 = iTemp158 & ((iRec67[0] < 0) ? fRec63[0] > (fTemp263 * fTemp264) : fRec63[0] < (fTemp262 * fTemp263));
			iVec43[0] = iTemp265;
			iRec146[0] = iTemp265 + iRec146[1] * (iVec43[1] >= iTemp265);
			float fTemp266 = float(iTemp153);
			iRec149[0] = (iRec149[1] + 1) * (iTemp265 == 0);
			fRec150[0] = fTemp163 * fRec150[1] + fTemp164 * fTemp206;
			fRec152[0] = fTemp163 * fRec152[1] + fSlow11 * fTemp164;
			fRec153[0] = fTemp163 * fRec153[1] + fSlow12 * (1.0f - fRec152[0]) * fTemp164;
			float fTemp267 = fRec152[0] + fRec153[0];
			float fTemp268 = float(iTemp168);
			float fTemp269 = 1.0f - fTemp267;
			int iTemp270 = iTemp171 & ((iRec72[0] < 0) ? fRec68[0] > (fTemp268 * fTemp269) : fRec68[0] < (fTemp267 * fTemp268));
			iVec44[0] = iTemp270;
			iRec151[0] = iTemp270 + iRec151[1] * (iVec44[1] >= iTemp270);
			float fTemp271 = float(iTemp166);
			iRec154[0] = (iRec154[1] + 1) * (iTemp270 == 0);
			fRec155[0] = fTemp176 * fRec155[1] + fTemp177 * fTemp206;
			fRec157[0] = fTemp176 * fRec157[1] + fSlow11 * fTemp177;
			fRec158[0] = fTemp176 * fRec158[1] + fSlow12 * (1.0f - fRec157[0]) * fTemp177;
			float fTemp272 = fRec157[0] + fRec158[0];
			float fTemp273 = float(iTemp181);
			float fTemp274 = 1.0f - fTemp272;
			int iTemp275 = iTemp184 & ((iRec77[0] < 0) ? fRec73[0] > (fTemp273 * fTemp274) : fRec73[0] < (fTemp272 * fTemp273));
			iVec45[0] = iTemp275;
			iRec156[0] = iTemp275 + iRec156[1] * (iVec45[1] >= iTemp275);
			float fTemp276 = float(iTemp179);
			iRec159[0] = (iRec159[1] + 1) * (iTemp275 == 0);
			fRec160[0] = fTemp189 * fRec160[1] + fTemp190 * fTemp206;
			fRec162[0] = fTemp189 * fRec162[1] + fSlow11 * fTemp190;
			fRec163[0] = fTemp189 * fRec163[1] + fSlow12 * (1.0f - fRec162[0]) * fTemp190;
			float fTemp277 = fRec162[0] + fRec163[0];
			float fTemp278 = float(iTemp194);
			float fTemp279 = 1.0f - fTemp277;
			int iTemp280 = iTemp197 & ((iRec82[0] < 0) ? fRec78[0] > (fTemp278 * fTemp279) : fRec78[0] < (fTemp277 * fTemp278));
			iVec46[0] = iTemp280;
			iRec161[0] = iTemp280 + iRec161[1] * (iVec46[1] >= iTemp280);
			float fTemp281 = float(iTemp192);
			iRec164[0] = (iRec164[1] + 1) * (iTemp280 == 0);
			fRec4[0] = float(iTemp15) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec5[0] + float(int(fRec88[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec91[0]) / std::max<float>(1.0f, fRec93[0] * fTemp211), 1.0f) - float(iRec94[0]) / std::max<float>(1.0f, fTemp211 * fTemp209)) + float(iTemp28) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec13[0] + float(int(fRec95[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec96[0]) / std::max<float>(1.0f, fRec98[0] * fTemp216), 1.0f) - float(iRec99[0]) / std::max<float>(1.0f, fTemp216 * fTemp214)) + float(iTemp41) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec18[0] + float(int(fRec100[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec101[0]) / std::max<float>(1.0f, fRec103[0] * fTemp221), 1.0f) - float(iRec104[0]) / std::max<float>(1.0f, fTemp221 * fTemp219)) + float(iTemp54) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec23[0] + float(int(fRec105[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec106[0]) / std::max<float>(1.0f, fRec108[0] * fTemp226), 1.0f) - float(iRec109[0]) / std::max<float>(1.0f, fTemp226 * fTemp224)) + float(iTemp67) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec28[0] + float(int(fRec110[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec111[0]) / std::max<float>(1.0f, fRec113[0] * fTemp231), 1.0f) - float(iRec114[0]) / std::max<float>(1.0f, fTemp231 * fTemp229)) + float(iTemp80) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec33[0] + float(int(fRec115[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec116[0]) / std::max<float>(1.0f, fRec118[0] * fTemp236), 1.0f) - float(iRec119[0]) / std::max<float>(1.0f, fTemp236 * fTemp234)) + float(iTemp93) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec38[0] + float(int(fRec120[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec121[0]) / std::max<float>(1.0f, fRec123[0] * fTemp241), 1.0f) - float(iRec124[0]) / std::max<float>(1.0f, fTemp241 * fTemp239)) + float(iTemp106) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec43[0] + float(int(fRec125[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec126[0]) / std::max<float>(1.0f, fRec128[0] * fTemp246), 1.0f) - float(iRec129[0]) / std::max<float>(1.0f, fTemp246 * fTemp244)) + float(iTemp119) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec48[0] + float(int(fRec130[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec131[0]) / std::max<float>(1.0f, fRec133[0] * fTemp251), 1.0f) - float(iRec134[0]) / std::max<float>(1.0f, fTemp251 * fTemp249)) + float(iTemp132) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec53[0] + float(int(fRec135[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec136[0]) / std::max<float>(1.0f, fRec138[0] * fTemp256), 1.0f) - float(iRec139[0]) / std::max<float>(1.0f, fTemp256 * fTemp254)) + float(iTemp145) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec58[0] + float(int(fRec140[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec141[0]) / std::max<float>(1.0f, fRec143[0] * fTemp261), 1.0f) - float(iRec144[0]) / std::max<float>(1.0f, fTemp261 * fTemp259)) + float(iTemp158) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec63[0] + float(int(fRec145[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec146[0]) / std::max<float>(1.0f, fRec148[0] * fTemp266), 1.0f) - float(iRec149[0]) / std::max<float>(1.0f, fTemp266 * fTemp264)) + float(iTemp171) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec68[0] + float(int(fRec150[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec151[0]) / std::max<float>(1.0f, fRec153[0] * fTemp271), 1.0f) - float(iRec154[0]) / std::max<float>(1.0f, fTemp271 * fTemp269)) + float(iTemp184) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec73[0] + float(int(fRec155[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec156[0]) / std::max<float>(1.0f, fRec158[0] * fTemp276), 1.0f) - float(iRec159[0]) / std::max<float>(1.0f, fTemp276 * fTemp274)) + float(iTemp197) * ftbl0[std::max<int>(0, std::min<int>(int(std::fmod(fRec78[0] + float(int(fRec160[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec161[0]) / std::max<float>(1.0f, fRec163[0] * fTemp281), 1.0f) - float(iRec164[0]) / std::max<float>(1.0f, fTemp281 * fTemp279));
			fRec2[0] = fConst2 * (fRec4[0] - fRec4[1] + fConst9 * fRec2[1]);
			fRec0[0] = fRec2[0];
			float fRec1 = fTemp205;
			fRec165[0] = fSlow13 + fConst4 * fRec165[1];
			float fTemp282 = 1.0f - fRec165[0];
			fRec166[0] = fSlow14 + fConst4 * fRec166[1];
			float fTemp283 = std::exp(4.6051702f * fRec166[0]);
			output0[i0] = FAUSTFLOAT((fRec0[0] * fRec165[0] + fRec1 * fTemp282) * fTemp283);
			float fTemp284 = fTemp1 * float(iRec170[1]);
			int iTemp285 = 1.0f == fTemp284;
			iVec47[0] = iTemp285;
			int iTemp286 = iTemp285 & (fRec172[1] == 0.0f);
			iVec48[0] = iTemp286;
			int iTemp287 = (iVec47[1] <= 0) & (iTemp285 > 0);
			int iTemp288 = 1 - iTemp287;
			float fTemp289 = float(iTemp288);
			float fTemp290 = float(iTemp287);
			fRec175[0] = fTemp289 * fRec175[1] + fRec11[0] * fTemp290;
			int iTemp291 = int(fConst0 * fRec175[0]);
			fRec174[0] = fRec174[1] * fTemp289 + fSlow2 * fTemp290 * float(iTemp291);
			int iTemp292 = int(fRec174[0]);
			int iTemp293 = std::max<int>(1, iTemp292 + -1);
			iRec176[0] = iTemp288 * iRec176[1] + iSlow4 * iTemp287;
			int iTemp294 = iTemp291 + -1;
			int iTemp295 = iRec176[0] * iTemp294;
			int iTemp296 = iTemp295 >= 0;
			iRec173[0] = ((iTemp286 > iVec48[1]) ? ((iTemp296) ? 0 : iTemp293) : std::min<int>(iTemp293, std::max<int>(0, iRec173[1] + ((iTemp296) ? 1 : -1))));
			fRec172[0] = float(iRec173[0] * (iRec173[0] != iRec173[1])) * float(std::abs(iTemp295)) / float(iTemp293);
			int iTemp297 = fRec172[0] > 0.0f;
			int iTemp298 = 2.0f == fTemp284;
			iVec49[0] = iTemp298;
			int iTemp299 = iTemp298 & (fRec177[1] == 0.0f);
			iVec50[0] = iTemp299;
			int iTemp300 = (iVec49[1] <= 0) & (iTemp298 > 0);
			int iTemp301 = 1 - iTemp300;
			float fTemp302 = float(iTemp301);
			float fTemp303 = float(iTemp300);
			fRec180[0] = fTemp302 * fRec180[1] + fRec11[0] * fTemp303;
			int iTemp304 = int(fConst0 * fRec180[0]);
			fRec179[0] = fRec179[1] * fTemp302 + fSlow2 * fTemp303 * float(iTemp304);
			int iTemp305 = int(fRec179[0]);
			int iTemp306 = std::max<int>(1, iTemp305 + -1);
			iRec181[0] = iTemp301 * iRec181[1] + iSlow4 * iTemp300;
			int iTemp307 = iTemp304 + -1;
			int iTemp308 = iRec181[0] * iTemp307;
			int iTemp309 = iTemp308 >= 0;
			iRec178[0] = ((iTemp299 > iVec50[1]) ? ((iTemp309) ? 0 : iTemp306) : std::min<int>(iTemp306, std::max<int>(0, iRec178[1] + ((iTemp309) ? 1 : -1))));
			fRec177[0] = float(iRec178[0] * (iRec178[0] != iRec178[1])) * float(std::abs(iTemp308)) / float(iTemp306);
			int iTemp310 = fRec177[0] > 0.0f;
			int iTemp311 = 3.0f == fTemp284;
			iVec51[0] = iTemp311;
			int iTemp312 = iTemp311 & (fRec182[1] == 0.0f);
			iVec52[0] = iTemp312;
			int iTemp313 = (iVec51[1] <= 0) & (iTemp311 > 0);
			int iTemp314 = 1 - iTemp313;
			float fTemp315 = float(iTemp314);
			float fTemp316 = float(iTemp313);
			fRec185[0] = fTemp315 * fRec185[1] + fRec11[0] * fTemp316;
			int iTemp317 = int(fConst0 * fRec185[0]);
			fRec184[0] = fRec184[1] * fTemp315 + fSlow2 * fTemp316 * float(iTemp317);
			int iTemp318 = int(fRec184[0]);
			int iTemp319 = std::max<int>(1, iTemp318 + -1);
			iRec186[0] = iTemp314 * iRec186[1] + iSlow4 * iTemp313;
			int iTemp320 = iTemp317 + -1;
			int iTemp321 = iRec186[0] * iTemp320;
			int iTemp322 = iTemp321 >= 0;
			iRec183[0] = ((iTemp312 > iVec52[1]) ? ((iTemp322) ? 0 : iTemp319) : std::min<int>(iTemp319, std::max<int>(0, iRec183[1] + ((iTemp322) ? 1 : -1))));
			fRec182[0] = float(iRec183[0] * (iRec183[0] != iRec183[1])) * float(std::abs(iTemp321)) / float(iTemp319);
			int iTemp323 = fRec182[0] > 0.0f;
			int iTemp324 = 4.0f == fTemp284;
			iVec53[0] = iTemp324;
			int iTemp325 = iTemp324 & (fRec187[1] == 0.0f);
			iVec54[0] = iTemp325;
			int iTemp326 = (iVec53[1] <= 0) & (iTemp324 > 0);
			int iTemp327 = 1 - iTemp326;
			float fTemp328 = float(iTemp327);
			float fTemp329 = float(iTemp326);
			fRec190[0] = fTemp328 * fRec190[1] + fRec11[0] * fTemp329;
			int iTemp330 = int(fConst0 * fRec190[0]);
			fRec189[0] = fRec189[1] * fTemp328 + fSlow2 * fTemp329 * float(iTemp330);
			int iTemp331 = int(fRec189[0]);
			int iTemp332 = std::max<int>(1, iTemp331 + -1);
			iRec191[0] = iTemp327 * iRec191[1] + iSlow4 * iTemp326;
			int iTemp333 = iTemp330 + -1;
			int iTemp334 = iRec191[0] * iTemp333;
			int iTemp335 = iTemp334 >= 0;
			iRec188[0] = ((iTemp325 > iVec54[1]) ? ((iTemp335) ? 0 : iTemp332) : std::min<int>(iTemp332, std::max<int>(0, iRec188[1] + ((iTemp335) ? 1 : -1))));
			fRec187[0] = float(iRec188[0] * (iRec188[0] != iRec188[1])) * float(std::abs(iTemp334)) / float(iTemp332);
			int iTemp336 = fRec187[0] > 0.0f;
			int iTemp337 = 5.0f == fTemp284;
			iVec55[0] = iTemp337;
			int iTemp338 = iTemp337 & (fRec192[1] == 0.0f);
			iVec56[0] = iTemp338;
			int iTemp339 = (iVec55[1] <= 0) & (iTemp337 > 0);
			int iTemp340 = 1 - iTemp339;
			float fTemp341 = float(iTemp340);
			float fTemp342 = float(iTemp339);
			fRec195[0] = fTemp341 * fRec195[1] + fRec11[0] * fTemp342;
			int iTemp343 = int(fConst0 * fRec195[0]);
			fRec194[0] = fRec194[1] * fTemp341 + fSlow2 * fTemp342 * float(iTemp343);
			int iTemp344 = int(fRec194[0]);
			int iTemp345 = std::max<int>(1, iTemp344 + -1);
			iRec196[0] = iTemp340 * iRec196[1] + iSlow4 * iTemp339;
			int iTemp346 = iTemp343 + -1;
			int iTemp347 = iRec196[0] * iTemp346;
			int iTemp348 = iTemp347 >= 0;
			iRec193[0] = ((iTemp338 > iVec56[1]) ? ((iTemp348) ? 0 : iTemp345) : std::min<int>(iTemp345, std::max<int>(0, iRec193[1] + ((iTemp348) ? 1 : -1))));
			fRec192[0] = float(iRec193[0] * (iRec193[0] != iRec193[1])) * float(std::abs(iTemp347)) / float(iTemp345);
			int iTemp349 = fRec192[0] > 0.0f;
			int iTemp350 = 6.0f == fTemp284;
			iVec57[0] = iTemp350;
			int iTemp351 = iTemp350 & (fRec197[1] == 0.0f);
			iVec58[0] = iTemp351;
			int iTemp352 = (iVec57[1] <= 0) & (iTemp350 > 0);
			int iTemp353 = 1 - iTemp352;
			float fTemp354 = float(iTemp353);
			float fTemp355 = float(iTemp352);
			fRec200[0] = fTemp354 * fRec200[1] + fRec11[0] * fTemp355;
			int iTemp356 = int(fConst0 * fRec200[0]);
			fRec199[0] = fRec199[1] * fTemp354 + fSlow2 * fTemp355 * float(iTemp356);
			int iTemp357 = int(fRec199[0]);
			int iTemp358 = std::max<int>(1, iTemp357 + -1);
			iRec201[0] = iTemp353 * iRec201[1] + iSlow4 * iTemp352;
			int iTemp359 = iTemp356 + -1;
			int iTemp360 = iRec201[0] * iTemp359;
			int iTemp361 = iTemp360 >= 0;
			iRec198[0] = ((iTemp351 > iVec58[1]) ? ((iTemp361) ? 0 : iTemp358) : std::min<int>(iTemp358, std::max<int>(0, iRec198[1] + ((iTemp361) ? 1 : -1))));
			fRec197[0] = float(iRec198[0] * (iRec198[0] != iRec198[1])) * float(std::abs(iTemp360)) / float(iTemp358);
			int iTemp362 = fRec197[0] > 0.0f;
			int iTemp363 = 7.0f == fTemp284;
			iVec59[0] = iTemp363;
			int iTemp364 = iTemp363 & (fRec202[1] == 0.0f);
			iVec60[0] = iTemp364;
			int iTemp365 = (iVec59[1] <= 0) & (iTemp363 > 0);
			int iTemp366 = 1 - iTemp365;
			float fTemp367 = float(iTemp366);
			float fTemp368 = float(iTemp365);
			fRec205[0] = fTemp367 * fRec205[1] + fRec11[0] * fTemp368;
			int iTemp369 = int(fConst0 * fRec205[0]);
			fRec204[0] = fRec204[1] * fTemp367 + fSlow2 * fTemp368 * float(iTemp369);
			int iTemp370 = int(fRec204[0]);
			int iTemp371 = std::max<int>(1, iTemp370 + -1);
			iRec206[0] = iTemp366 * iRec206[1] + iSlow4 * iTemp365;
			int iTemp372 = iTemp369 + -1;
			int iTemp373 = iRec206[0] * iTemp372;
			int iTemp374 = iTemp373 >= 0;
			iRec203[0] = ((iTemp364 > iVec60[1]) ? ((iTemp374) ? 0 : iTemp371) : std::min<int>(iTemp371, std::max<int>(0, iRec203[1] + ((iTemp374) ? 1 : -1))));
			fRec202[0] = float(iRec203[0] * (iRec203[0] != iRec203[1])) * float(std::abs(iTemp373)) / float(iTemp371);
			int iTemp375 = fRec202[0] > 0.0f;
			int iTemp376 = 8.0f == fTemp284;
			iVec61[0] = iTemp376;
			int iTemp377 = iTemp376 & (fRec207[1] == 0.0f);
			iVec62[0] = iTemp377;
			int iTemp378 = (iVec61[1] <= 0) & (iTemp376 > 0);
			int iTemp379 = 1 - iTemp378;
			float fTemp380 = float(iTemp379);
			float fTemp381 = float(iTemp378);
			fRec210[0] = fTemp380 * fRec210[1] + fRec11[0] * fTemp381;
			int iTemp382 = int(fConst0 * fRec210[0]);
			fRec209[0] = fRec209[1] * fTemp380 + fSlow2 * fTemp381 * float(iTemp382);
			int iTemp383 = int(fRec209[0]);
			int iTemp384 = std::max<int>(1, iTemp383 + -1);
			iRec211[0] = iTemp379 * iRec211[1] + iSlow4 * iTemp378;
			int iTemp385 = iTemp382 + -1;
			int iTemp386 = iRec211[0] * iTemp385;
			int iTemp387 = iTemp386 >= 0;
			iRec208[0] = ((iTemp377 > iVec62[1]) ? ((iTemp387) ? 0 : iTemp384) : std::min<int>(iTemp384, std::max<int>(0, iRec208[1] + ((iTemp387) ? 1 : -1))));
			fRec207[0] = float(iRec208[0] * (iRec208[0] != iRec208[1])) * float(std::abs(iTemp386)) / float(iTemp384);
			int iTemp388 = fRec207[0] > 0.0f;
			int iTemp389 = 9.0f == fTemp284;
			iVec63[0] = iTemp389;
			int iTemp390 = iTemp389 & (fRec212[1] == 0.0f);
			iVec64[0] = iTemp390;
			int iTemp391 = (iVec63[1] <= 0) & (iTemp389 > 0);
			int iTemp392 = 1 - iTemp391;
			float fTemp393 = float(iTemp392);
			float fTemp394 = float(iTemp391);
			fRec215[0] = fTemp393 * fRec215[1] + fRec11[0] * fTemp394;
			int iTemp395 = int(fConst0 * fRec215[0]);
			fRec214[0] = fRec214[1] * fTemp393 + fSlow2 * fTemp394 * float(iTemp395);
			int iTemp396 = int(fRec214[0]);
			int iTemp397 = std::max<int>(1, iTemp396 + -1);
			iRec216[0] = iTemp392 * iRec216[1] + iSlow4 * iTemp391;
			int iTemp398 = iTemp395 + -1;
			int iTemp399 = iRec216[0] * iTemp398;
			int iTemp400 = iTemp399 >= 0;
			iRec213[0] = ((iTemp390 > iVec64[1]) ? ((iTemp400) ? 0 : iTemp397) : std::min<int>(iTemp397, std::max<int>(0, iRec213[1] + ((iTemp400) ? 1 : -1))));
			fRec212[0] = float(iRec213[0] * (iRec213[0] != iRec213[1])) * float(std::abs(iTemp399)) / float(iTemp397);
			int iTemp401 = fRec212[0] > 0.0f;
			int iTemp402 = 1e+01f == fTemp284;
			iVec65[0] = iTemp402;
			int iTemp403 = iTemp402 & (fRec217[1] == 0.0f);
			iVec66[0] = iTemp403;
			int iTemp404 = (iVec65[1] <= 0) & (iTemp402 > 0);
			int iTemp405 = 1 - iTemp404;
			float fTemp406 = float(iTemp405);
			float fTemp407 = float(iTemp404);
			fRec220[0] = fTemp406 * fRec220[1] + fRec11[0] * fTemp407;
			int iTemp408 = int(fConst0 * fRec220[0]);
			fRec219[0] = fRec219[1] * fTemp406 + fSlow2 * fTemp407 * float(iTemp408);
			int iTemp409 = int(fRec219[0]);
			int iTemp410 = std::max<int>(1, iTemp409 + -1);
			iRec221[0] = iTemp405 * iRec221[1] + iSlow4 * iTemp404;
			int iTemp411 = iTemp408 + -1;
			int iTemp412 = iRec221[0] * iTemp411;
			int iTemp413 = iTemp412 >= 0;
			iRec218[0] = ((iTemp403 > iVec66[1]) ? ((iTemp413) ? 0 : iTemp410) : std::min<int>(iTemp410, std::max<int>(0, iRec218[1] + ((iTemp413) ? 1 : -1))));
			fRec217[0] = float(iRec218[0] * (iRec218[0] != iRec218[1])) * float(std::abs(iTemp412)) / float(iTemp410);
			int iTemp414 = fRec217[0] > 0.0f;
			int iTemp415 = 11.0f == fTemp284;
			iVec67[0] = iTemp415;
			int iTemp416 = iTemp415 & (fRec222[1] == 0.0f);
			iVec68[0] = iTemp416;
			int iTemp417 = (iVec67[1] <= 0) & (iTemp415 > 0);
			int iTemp418 = 1 - iTemp417;
			float fTemp419 = float(iTemp418);
			float fTemp420 = float(iTemp417);
			fRec225[0] = fTemp419 * fRec225[1] + fRec11[0] * fTemp420;
			int iTemp421 = int(fConst0 * fRec225[0]);
			fRec224[0] = fRec224[1] * fTemp419 + fSlow2 * fTemp420 * float(iTemp421);
			int iTemp422 = int(fRec224[0]);
			int iTemp423 = std::max<int>(1, iTemp422 + -1);
			iRec226[0] = iTemp418 * iRec226[1] + iSlow4 * iTemp417;
			int iTemp424 = iTemp421 + -1;
			int iTemp425 = iRec226[0] * iTemp424;
			int iTemp426 = iTemp425 >= 0;
			iRec223[0] = ((iTemp416 > iVec68[1]) ? ((iTemp426) ? 0 : iTemp423) : std::min<int>(iTemp423, std::max<int>(0, iRec223[1] + ((iTemp426) ? 1 : -1))));
			fRec222[0] = float(iRec223[0] * (iRec223[0] != iRec223[1])) * float(std::abs(iTemp425)) / float(iTemp423);
			int iTemp427 = fRec222[0] > 0.0f;
			int iTemp428 = 12.0f == fTemp284;
			iVec69[0] = iTemp428;
			int iTemp429 = iTemp428 & (fRec227[1] == 0.0f);
			iVec70[0] = iTemp429;
			int iTemp430 = (iVec69[1] <= 0) & (iTemp428 > 0);
			int iTemp431 = 1 - iTemp430;
			float fTemp432 = float(iTemp431);
			float fTemp433 = float(iTemp430);
			fRec230[0] = fTemp432 * fRec230[1] + fRec11[0] * fTemp433;
			int iTemp434 = int(fConst0 * fRec230[0]);
			fRec229[0] = fRec229[1] * fTemp432 + fSlow2 * fTemp433 * float(iTemp434);
			int iTemp435 = int(fRec229[0]);
			int iTemp436 = std::max<int>(1, iTemp435 + -1);
			iRec231[0] = iTemp431 * iRec231[1] + iSlow4 * iTemp430;
			int iTemp437 = iTemp434 + -1;
			int iTemp438 = iRec231[0] * iTemp437;
			int iTemp439 = iTemp438 >= 0;
			iRec228[0] = ((iTemp429 > iVec70[1]) ? ((iTemp439) ? 0 : iTemp436) : std::min<int>(iTemp436, std::max<int>(0, iRec228[1] + ((iTemp439) ? 1 : -1))));
			fRec227[0] = float(iRec228[0] * (iRec228[0] != iRec228[1])) * float(std::abs(iTemp438)) / float(iTemp436);
			int iTemp440 = fRec227[0] > 0.0f;
			int iTemp441 = 13.0f == fTemp284;
			iVec71[0] = iTemp441;
			int iTemp442 = iTemp441 & (fRec232[1] == 0.0f);
			iVec72[0] = iTemp442;
			int iTemp443 = (iVec71[1] <= 0) & (iTemp441 > 0);
			int iTemp444 = 1 - iTemp443;
			float fTemp445 = float(iTemp444);
			float fTemp446 = float(iTemp443);
			fRec235[0] = fTemp445 * fRec235[1] + fRec11[0] * fTemp446;
			int iTemp447 = int(fConst0 * fRec235[0]);
			fRec234[0] = fRec234[1] * fTemp445 + fSlow2 * fTemp446 * float(iTemp447);
			int iTemp448 = int(fRec234[0]);
			int iTemp449 = std::max<int>(1, iTemp448 + -1);
			iRec236[0] = iTemp444 * iRec236[1] + iSlow4 * iTemp443;
			int iTemp450 = iTemp447 + -1;
			int iTemp451 = iRec236[0] * iTemp450;
			int iTemp452 = iTemp451 >= 0;
			iRec233[0] = ((iTemp442 > iVec72[1]) ? ((iTemp452) ? 0 : iTemp449) : std::min<int>(iTemp449, std::max<int>(0, iRec233[1] + ((iTemp452) ? 1 : -1))));
			fRec232[0] = float(iRec233[0] * (iRec233[0] != iRec233[1])) * float(std::abs(iTemp451)) / float(iTemp449);
			int iTemp453 = fRec232[0] > 0.0f;
			int iTemp454 = 14.0f == fTemp284;
			iVec73[0] = iTemp454;
			int iTemp455 = iTemp454 & (fRec237[1] == 0.0f);
			iVec74[0] = iTemp455;
			int iTemp456 = (iVec73[1] <= 0) & (iTemp454 > 0);
			int iTemp457 = 1 - iTemp456;
			float fTemp458 = float(iTemp457);
			float fTemp459 = float(iTemp456);
			fRec240[0] = fTemp458 * fRec240[1] + fRec11[0] * fTemp459;
			int iTemp460 = int(fConst0 * fRec240[0]);
			fRec239[0] = fRec239[1] * fTemp458 + fSlow2 * fTemp459 * float(iTemp460);
			int iTemp461 = int(fRec239[0]);
			int iTemp462 = std::max<int>(1, iTemp461 + -1);
			iRec241[0] = iTemp457 * iRec241[1] + iSlow4 * iTemp456;
			int iTemp463 = iTemp460 + -1;
			int iTemp464 = iRec241[0] * iTemp463;
			int iTemp465 = iTemp464 >= 0;
			iRec238[0] = ((iTemp455 > iVec74[1]) ? ((iTemp465) ? 0 : iTemp462) : std::min<int>(iTemp462, std::max<int>(0, iRec238[1] + ((iTemp465) ? 1 : -1))));
			fRec237[0] = float(iRec238[0] * (iRec238[0] != iRec238[1])) * float(std::abs(iTemp464)) / float(iTemp462);
			int iTemp466 = fRec237[0] > 0.0f;
			int iTemp467 = 15.0f == fTemp284;
			iVec75[0] = iTemp467;
			int iTemp468 = iTemp467 & (fRec242[1] == 0.0f);
			iVec76[0] = iTemp468;
			int iTemp469 = (iVec75[1] <= 0) & (iTemp467 > 0);
			int iTemp470 = 1 - iTemp469;
			float fTemp471 = float(iTemp470);
			float fTemp472 = float(iTemp469);
			fRec245[0] = fTemp471 * fRec245[1] + fRec11[0] * fTemp472;
			int iTemp473 = int(fConst0 * fRec245[0]);
			fRec244[0] = fRec244[1] * fTemp471 + fSlow2 * fTemp472 * float(iTemp473);
			int iTemp474 = int(fRec244[0]);
			int iTemp475 = std::max<int>(1, iTemp474 + -1);
			iRec246[0] = iTemp470 * iRec246[1] + iSlow4 * iTemp469;
			int iTemp476 = iTemp473 + -1;
			int iTemp477 = iRec246[0] * iTemp476;
			int iTemp478 = iTemp477 >= 0;
			iRec243[0] = ((iTemp468 > iVec76[1]) ? ((iTemp478) ? 0 : iTemp475) : std::min<int>(iTemp475, std::max<int>(0, iRec243[1] + ((iTemp478) ? 1 : -1))));
			fRec242[0] = float(iRec243[0] * (iRec243[0] != iRec243[1])) * float(std::abs(iTemp477)) / float(iTemp475);
			int iTemp479 = fRec242[0] > 0.0f;
			iRec170[0] = std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(std::max<int>(1 - iTemp297, 2 * (1 - iTemp310)), 3 * (1 - iTemp323)), 4 * (1 - iTemp336)), 5 * (1 - iTemp349)), 6 * (1 - iTemp362)), 7 * (1 - iTemp375)), 8 * (1 - iTemp388)), 9 * (1 - iTemp401)), 10 * (1 - iTemp414)), 11 * (1 - iTemp427)), 12 * (1 - iTemp440)), 13 * (1 - iTemp453)), 14 * (1 - iTemp466)), 15 * (1 - iTemp479));
			float fTemp480 = fRec84[0] * fRec167[1];
			float fTemp481 = std::fabs(fTemp480);
			float fTemp482 = ((fTemp481 > fRec248[1]) ? fConst8 : fConst7);
			fRec248[0] = fTemp481 * (1.0f - fTemp482) + fRec248[1] * fTemp482;
			fRec247[0] = fConst5 * fRec247[1] - fConst6 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec248[0])) + 6.0f, 0.0f);
			float fTemp483 = fTemp480 * std::pow(1e+01f, 0.05f * fRec247[0]) + fSlow7 * float(input1[i0]) * fTemp204;
			ftbl1[iTemp200] = fTemp483;
			fRec249[0] = fTemp289 * fRec249[1] + fTemp206 * fTemp290;
			fRec251[0] = fTemp289 * fRec251[1] + fSlow11 * fTemp290;
			fRec252[0] = fTemp289 * fRec252[1] + fSlow12 * (1.0f - fRec251[0]) * fTemp290;
			float fTemp484 = fRec251[0] + fRec252[0];
			float fTemp485 = float(iTemp294);
			float fTemp486 = 1.0f - fTemp484;
			int iTemp487 = iTemp297 & ((iRec176[0] < 0) ? fRec172[0] > (fTemp485 * fTemp486) : fRec172[0] < (fTemp484 * fTemp485));
			iVec77[0] = iTemp487;
			iRec250[0] = iTemp487 + iRec250[1] * (iVec77[1] >= iTemp487);
			float fTemp488 = float(iTemp292);
			iRec253[0] = (iRec253[1] + 1) * (iTemp487 == 0);
			fRec254[0] = fTemp302 * fRec254[1] + fTemp206 * fTemp303;
			fRec256[0] = fTemp302 * fRec256[1] + fSlow11 * fTemp303;
			fRec257[0] = fTemp302 * fRec257[1] + fSlow12 * (1.0f - fRec256[0]) * fTemp303;
			float fTemp489 = fRec256[0] + fRec257[0];
			float fTemp490 = float(iTemp307);
			float fTemp491 = 1.0f - fTemp489;
			int iTemp492 = iTemp310 & ((iRec181[0] < 0) ? fRec177[0] > (fTemp490 * fTemp491) : fRec177[0] < (fTemp489 * fTemp490));
			iVec78[0] = iTemp492;
			iRec255[0] = iTemp492 + iRec255[1] * (iVec78[1] >= iTemp492);
			float fTemp493 = float(iTemp305);
			iRec258[0] = (iRec258[1] + 1) * (iTemp492 == 0);
			fRec259[0] = fTemp315 * fRec259[1] + fTemp206 * fTemp316;
			fRec261[0] = fTemp315 * fRec261[1] + fSlow11 * fTemp316;
			fRec262[0] = fTemp315 * fRec262[1] + fSlow12 * (1.0f - fRec261[0]) * fTemp316;
			float fTemp494 = fRec261[0] + fRec262[0];
			float fTemp495 = float(iTemp320);
			float fTemp496 = 1.0f - fTemp494;
			int iTemp497 = iTemp323 & ((iRec186[0] < 0) ? fRec182[0] > (fTemp495 * fTemp496) : fRec182[0] < (fTemp494 * fTemp495));
			iVec79[0] = iTemp497;
			iRec260[0] = iTemp497 + iRec260[1] * (iVec79[1] >= iTemp497);
			float fTemp498 = float(iTemp318);
			iRec263[0] = (iRec263[1] + 1) * (iTemp497 == 0);
			fRec264[0] = fTemp328 * fRec264[1] + fTemp206 * fTemp329;
			fRec266[0] = fTemp328 * fRec266[1] + fSlow11 * fTemp329;
			fRec267[0] = fTemp328 * fRec267[1] + fSlow12 * (1.0f - fRec266[0]) * fTemp329;
			float fTemp499 = fRec266[0] + fRec267[0];
			float fTemp500 = float(iTemp333);
			float fTemp501 = 1.0f - fTemp499;
			int iTemp502 = iTemp336 & ((iRec191[0] < 0) ? fRec187[0] > (fTemp500 * fTemp501) : fRec187[0] < (fTemp499 * fTemp500));
			iVec80[0] = iTemp502;
			iRec265[0] = iTemp502 + iRec265[1] * (iVec80[1] >= iTemp502);
			float fTemp503 = float(iTemp331);
			iRec268[0] = (iRec268[1] + 1) * (iTemp502 == 0);
			fRec269[0] = fTemp341 * fRec269[1] + fTemp206 * fTemp342;
			fRec271[0] = fTemp341 * fRec271[1] + fSlow11 * fTemp342;
			fRec272[0] = fTemp341 * fRec272[1] + fSlow12 * (1.0f - fRec271[0]) * fTemp342;
			float fTemp504 = fRec271[0] + fRec272[0];
			float fTemp505 = float(iTemp346);
			float fTemp506 = 1.0f - fTemp504;
			int iTemp507 = iTemp349 & ((iRec196[0] < 0) ? fRec192[0] > (fTemp505 * fTemp506) : fRec192[0] < (fTemp504 * fTemp505));
			iVec81[0] = iTemp507;
			iRec270[0] = iTemp507 + iRec270[1] * (iVec81[1] >= iTemp507);
			float fTemp508 = float(iTemp344);
			iRec273[0] = (iRec273[1] + 1) * (iTemp507 == 0);
			fRec274[0] = fTemp354 * fRec274[1] + fTemp206 * fTemp355;
			fRec276[0] = fTemp354 * fRec276[1] + fSlow11 * fTemp355;
			fRec277[0] = fTemp354 * fRec277[1] + fSlow12 * (1.0f - fRec276[0]) * fTemp355;
			float fTemp509 = fRec276[0] + fRec277[0];
			float fTemp510 = float(iTemp359);
			float fTemp511 = 1.0f - fTemp509;
			int iTemp512 = iTemp362 & ((iRec201[0] < 0) ? fRec197[0] > (fTemp510 * fTemp511) : fRec197[0] < (fTemp509 * fTemp510));
			iVec82[0] = iTemp512;
			iRec275[0] = iTemp512 + iRec275[1] * (iVec82[1] >= iTemp512);
			float fTemp513 = float(iTemp357);
			iRec278[0] = (iRec278[1] + 1) * (iTemp512 == 0);
			fRec279[0] = fTemp367 * fRec279[1] + fTemp206 * fTemp368;
			fRec281[0] = fTemp367 * fRec281[1] + fSlow11 * fTemp368;
			fRec282[0] = fTemp367 * fRec282[1] + fSlow12 * (1.0f - fRec281[0]) * fTemp368;
			float fTemp514 = fRec281[0] + fRec282[0];
			float fTemp515 = float(iTemp372);
			float fTemp516 = 1.0f - fTemp514;
			int iTemp517 = iTemp375 & ((iRec206[0] < 0) ? fRec202[0] > (fTemp515 * fTemp516) : fRec202[0] < (fTemp514 * fTemp515));
			iVec83[0] = iTemp517;
			iRec280[0] = iTemp517 + iRec280[1] * (iVec83[1] >= iTemp517);
			float fTemp518 = float(iTemp370);
			iRec283[0] = (iRec283[1] + 1) * (iTemp517 == 0);
			fRec284[0] = fTemp380 * fRec284[1] + fTemp206 * fTemp381;
			fRec286[0] = fTemp380 * fRec286[1] + fSlow11 * fTemp381;
			fRec287[0] = fTemp380 * fRec287[1] + fSlow12 * (1.0f - fRec286[0]) * fTemp381;
			float fTemp519 = fRec286[0] + fRec287[0];
			float fTemp520 = float(iTemp385);
			float fTemp521 = 1.0f - fTemp519;
			int iTemp522 = iTemp388 & ((iRec211[0] < 0) ? fRec207[0] > (fTemp520 * fTemp521) : fRec207[0] < (fTemp519 * fTemp520));
			iVec84[0] = iTemp522;
			iRec285[0] = iTemp522 + iRec285[1] * (iVec84[1] >= iTemp522);
			float fTemp523 = float(iTemp383);
			iRec288[0] = (iRec288[1] + 1) * (iTemp522 == 0);
			fRec289[0] = fTemp393 * fRec289[1] + fTemp206 * fTemp394;
			fRec291[0] = fTemp393 * fRec291[1] + fSlow11 * fTemp394;
			fRec292[0] = fTemp393 * fRec292[1] + fSlow12 * (1.0f - fRec291[0]) * fTemp394;
			float fTemp524 = fRec291[0] + fRec292[0];
			float fTemp525 = float(iTemp398);
			float fTemp526 = 1.0f - fTemp524;
			int iTemp527 = iTemp401 & ((iRec216[0] < 0) ? fRec212[0] > (fTemp525 * fTemp526) : fRec212[0] < (fTemp524 * fTemp525));
			iVec85[0] = iTemp527;
			iRec290[0] = iTemp527 + iRec290[1] * (iVec85[1] >= iTemp527);
			float fTemp528 = float(iTemp396);
			iRec293[0] = (iRec293[1] + 1) * (iTemp527 == 0);
			fRec294[0] = fTemp406 * fRec294[1] + fTemp206 * fTemp407;
			fRec296[0] = fTemp406 * fRec296[1] + fSlow11 * fTemp407;
			fRec297[0] = fTemp406 * fRec297[1] + fSlow12 * (1.0f - fRec296[0]) * fTemp407;
			float fTemp529 = fRec296[0] + fRec297[0];
			float fTemp530 = float(iTemp411);
			float fTemp531 = 1.0f - fTemp529;
			int iTemp532 = iTemp414 & ((iRec221[0] < 0) ? fRec217[0] > (fTemp530 * fTemp531) : fRec217[0] < (fTemp529 * fTemp530));
			iVec86[0] = iTemp532;
			iRec295[0] = iTemp532 + iRec295[1] * (iVec86[1] >= iTemp532);
			float fTemp533 = float(iTemp409);
			iRec298[0] = (iRec298[1] + 1) * (iTemp532 == 0);
			fRec299[0] = fTemp419 * fRec299[1] + fTemp206 * fTemp420;
			fRec301[0] = fTemp419 * fRec301[1] + fSlow11 * fTemp420;
			fRec302[0] = fTemp419 * fRec302[1] + fSlow12 * (1.0f - fRec301[0]) * fTemp420;
			float fTemp534 = fRec301[0] + fRec302[0];
			float fTemp535 = float(iTemp424);
			float fTemp536 = 1.0f - fTemp534;
			int iTemp537 = iTemp427 & ((iRec226[0] < 0) ? fRec222[0] > (fTemp535 * fTemp536) : fRec222[0] < (fTemp534 * fTemp535));
			iVec87[0] = iTemp537;
			iRec300[0] = iTemp537 + iRec300[1] * (iVec87[1] >= iTemp537);
			float fTemp538 = float(iTemp422);
			iRec303[0] = (iRec303[1] + 1) * (iTemp537 == 0);
			fRec304[0] = fTemp432 * fRec304[1] + fTemp206 * fTemp433;
			fRec306[0] = fTemp432 * fRec306[1] + fSlow11 * fTemp433;
			fRec307[0] = fTemp432 * fRec307[1] + fSlow12 * (1.0f - fRec306[0]) * fTemp433;
			float fTemp539 = fRec306[0] + fRec307[0];
			float fTemp540 = float(iTemp437);
			float fTemp541 = 1.0f - fTemp539;
			int iTemp542 = iTemp440 & ((iRec231[0] < 0) ? fRec227[0] > (fTemp540 * fTemp541) : fRec227[0] < (fTemp539 * fTemp540));
			iVec88[0] = iTemp542;
			iRec305[0] = iTemp542 + iRec305[1] * (iVec88[1] >= iTemp542);
			float fTemp543 = float(iTemp435);
			iRec308[0] = (iRec308[1] + 1) * (iTemp542 == 0);
			fRec309[0] = fTemp445 * fRec309[1] + fTemp206 * fTemp446;
			fRec311[0] = fTemp445 * fRec311[1] + fSlow11 * fTemp446;
			fRec312[0] = fTemp445 * fRec312[1] + fSlow12 * (1.0f - fRec311[0]) * fTemp446;
			float fTemp544 = fRec311[0] + fRec312[0];
			float fTemp545 = float(iTemp450);
			float fTemp546 = 1.0f - fTemp544;
			int iTemp547 = iTemp453 & ((iRec236[0] < 0) ? fRec232[0] > (fTemp545 * fTemp546) : fRec232[0] < (fTemp544 * fTemp545));
			iVec89[0] = iTemp547;
			iRec310[0] = iTemp547 + iRec310[1] * (iVec89[1] >= iTemp547);
			float fTemp548 = float(iTemp448);
			iRec313[0] = (iRec313[1] + 1) * (iTemp547 == 0);
			fRec314[0] = fTemp458 * fRec314[1] + fTemp206 * fTemp459;
			fRec316[0] = fTemp458 * fRec316[1] + fSlow11 * fTemp459;
			fRec317[0] = fTemp458 * fRec317[1] + fSlow12 * (1.0f - fRec316[0]) * fTemp459;
			float fTemp549 = fRec316[0] + fRec317[0];
			float fTemp550 = float(iTemp463);
			float fTemp551 = 1.0f - fTemp549;
			int iTemp552 = iTemp466 & ((iRec241[0] < 0) ? fRec237[0] > (fTemp550 * fTemp551) : fRec237[0] < (fTemp549 * fTemp550));
			iVec90[0] = iTemp552;
			iRec315[0] = iTemp552 + iRec315[1] * (iVec90[1] >= iTemp552);
			float fTemp553 = float(iTemp461);
			iRec318[0] = (iRec318[1] + 1) * (iTemp552 == 0);
			fRec319[0] = fTemp471 * fRec319[1] + fTemp206 * fTemp472;
			fRec321[0] = fTemp471 * fRec321[1] + fSlow11 * fTemp472;
			fRec322[0] = fTemp471 * fRec322[1] + fSlow12 * (1.0f - fRec321[0]) * fTemp472;
			float fTemp554 = fRec321[0] + fRec322[0];
			float fTemp555 = float(iTemp476);
			float fTemp556 = 1.0f - fTemp554;
			int iTemp557 = iTemp479 & ((iRec246[0] < 0) ? fRec242[0] > (fTemp555 * fTemp556) : fRec242[0] < (fTemp554 * fTemp555));
			iVec91[0] = iTemp557;
			iRec320[0] = iTemp557 + iRec320[1] * (iVec91[1] >= iTemp557);
			float fTemp558 = float(iTemp474);
			iRec323[0] = (iRec323[1] + 1) * (iTemp557 == 0);
			fRec171[0] = float(iTemp297) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec172[0] + float(int(fRec249[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec250[0]) / std::max<float>(1.0f, fRec252[0] * fTemp488), 1.0f) - float(iRec253[0]) / std::max<float>(1.0f, fTemp488 * fTemp486)) + float(iTemp310) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec177[0] + float(int(fRec254[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec255[0]) / std::max<float>(1.0f, fRec257[0] * fTemp493), 1.0f) - float(iRec258[0]) / std::max<float>(1.0f, fTemp493 * fTemp491)) + float(iTemp323) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec182[0] + float(int(fRec259[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec260[0]) / std::max<float>(1.0f, fRec262[0] * fTemp498), 1.0f) - float(iRec263[0]) / std::max<float>(1.0f, fTemp498 * fTemp496)) + float(iTemp336) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec187[0] + float(int(fRec264[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec265[0]) / std::max<float>(1.0f, fRec267[0] * fTemp503), 1.0f) - float(iRec268[0]) / std::max<float>(1.0f, fTemp503 * fTemp501)) + float(iTemp349) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec192[0] + float(int(fRec269[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec270[0]) / std::max<float>(1.0f, fRec272[0] * fTemp508), 1.0f) - float(iRec273[0]) / std::max<float>(1.0f, fTemp508 * fTemp506)) + float(iTemp362) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec197[0] + float(int(fRec274[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec275[0]) / std::max<float>(1.0f, fRec277[0] * fTemp513), 1.0f) - float(iRec278[0]) / std::max<float>(1.0f, fTemp513 * fTemp511)) + float(iTemp375) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec202[0] + float(int(fRec279[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec280[0]) / std::max<float>(1.0f, fRec282[0] * fTemp518), 1.0f) - float(iRec283[0]) / std::max<float>(1.0f, fTemp518 * fTemp516)) + float(iTemp388) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec207[0] + float(int(fRec284[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec285[0]) / std::max<float>(1.0f, fRec287[0] * fTemp523), 1.0f) - float(iRec288[0]) / std::max<float>(1.0f, fTemp523 * fTemp521)) + float(iTemp401) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec212[0] + float(int(fRec289[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec290[0]) / std::max<float>(1.0f, fRec292[0] * fTemp528), 1.0f) - float(iRec293[0]) / std::max<float>(1.0f, fTemp528 * fTemp526)) + float(iTemp414) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec217[0] + float(int(fRec294[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec295[0]) / std::max<float>(1.0f, fRec297[0] * fTemp533), 1.0f) - float(iRec298[0]) / std::max<float>(1.0f, fTemp533 * fTemp531)) + float(iTemp427) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec222[0] + float(int(fRec299[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec300[0]) / std::max<float>(1.0f, fRec302[0] * fTemp538), 1.0f) - float(iRec303[0]) / std::max<float>(1.0f, fTemp538 * fTemp536)) + float(iTemp440) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec227[0] + float(int(fRec304[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec305[0]) / std::max<float>(1.0f, fRec307[0] * fTemp543), 1.0f) - float(iRec308[0]) / std::max<float>(1.0f, fTemp543 * fTemp541)) + float(iTemp453) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec232[0] + float(int(fRec309[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec310[0]) / std::max<float>(1.0f, fRec312[0] * fTemp548), 1.0f) - float(iRec313[0]) / std::max<float>(1.0f, fTemp548 * fTemp546)) + float(iTemp466) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec237[0] + float(int(fRec314[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec315[0]) / std::max<float>(1.0f, fRec317[0] * fTemp553), 1.0f) - float(iRec318[0]) / std::max<float>(1.0f, fTemp553 * fTemp551)) + float(iTemp479) * ftbl1[std::max<int>(0, std::min<int>(int(std::fmod(fRec242[0] + float(int(fRec319[0])), 2.4e+05f)), 239999))] * std::max<float>(0.0f, std::min<float>(float(iRec320[0]) / std::max<float>(1.0f, fRec322[0] * fTemp558), 1.0f) - float(iRec323[0]) / std::max<float>(1.0f, fTemp558 * fTemp556));
			fRec169[0] = fConst2 * (fRec171[0] - fRec171[1] + fConst9 * fRec169[1]);
			fRec167[0] = fRec169[0];
			float fRec168 = fTemp483;
			output1[i0] = FAUSTFLOAT(fTemp283 * (fRec168 * fTemp282 + fRec165[0] * fRec167[0]));
			iVec0[1] = iVec0[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			iVec2[1] = iVec2[0];
			iVec3[1] = iVec3[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			iRec12[1] = iRec12[0];
			iRec6[1] = iRec6[0];
			fRec5[1] = fRec5[0];
			iVec4[1] = iVec4[0];
			iVec5[1] = iVec5[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			iRec17[1] = iRec17[0];
			iRec14[1] = iRec14[0];
			fRec13[1] = fRec13[0];
			iVec6[1] = iVec6[0];
			iVec7[1] = iVec7[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			iRec22[1] = iRec22[0];
			iRec19[1] = iRec19[0];
			fRec18[1] = fRec18[0];
			iVec8[1] = iVec8[0];
			iVec9[1] = iVec9[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			iRec27[1] = iRec27[0];
			iRec24[1] = iRec24[0];
			fRec23[1] = fRec23[0];
			iVec10[1] = iVec10[0];
			iVec11[1] = iVec11[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			iRec32[1] = iRec32[0];
			iRec29[1] = iRec29[0];
			fRec28[1] = fRec28[0];
			iVec12[1] = iVec12[0];
			iVec13[1] = iVec13[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			iRec37[1] = iRec37[0];
			iRec34[1] = iRec34[0];
			fRec33[1] = fRec33[0];
			iVec14[1] = iVec14[0];
			iVec15[1] = iVec15[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			iRec42[1] = iRec42[0];
			iRec39[1] = iRec39[0];
			fRec38[1] = fRec38[0];
			iVec16[1] = iVec16[0];
			iVec17[1] = iVec17[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			iRec47[1] = iRec47[0];
			iRec44[1] = iRec44[0];
			fRec43[1] = fRec43[0];
			iVec18[1] = iVec18[0];
			iVec19[1] = iVec19[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			iRec52[1] = iRec52[0];
			iRec49[1] = iRec49[0];
			fRec48[1] = fRec48[0];
			iVec20[1] = iVec20[0];
			iVec21[1] = iVec21[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			iRec57[1] = iRec57[0];
			iRec54[1] = iRec54[0];
			fRec53[1] = fRec53[0];
			iVec22[1] = iVec22[0];
			iVec23[1] = iVec23[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			iRec62[1] = iRec62[0];
			iRec59[1] = iRec59[0];
			fRec58[1] = fRec58[0];
			iVec24[1] = iVec24[0];
			iVec25[1] = iVec25[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			iRec67[1] = iRec67[0];
			iRec64[1] = iRec64[0];
			fRec63[1] = fRec63[0];
			iVec26[1] = iVec26[0];
			iVec27[1] = iVec27[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			iRec72[1] = iRec72[0];
			iRec69[1] = iRec69[0];
			fRec68[1] = fRec68[0];
			iVec28[1] = iVec28[0];
			iVec29[1] = iVec29[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			iRec77[1] = iRec77[0];
			iRec74[1] = iRec74[0];
			fRec73[1] = fRec73[0];
			iVec30[1] = iVec30[0];
			iVec31[1] = iVec31[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			iRec82[1] = iRec82[0];
			iRec79[1] = iRec79[0];
			fRec78[1] = fRec78[0];
			iRec3[1] = iRec3[0];
			fRec83[1] = fRec83[0];
			fRec84[1] = fRec84[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec87[1] = fRec87[0];
			fRec89[1] = fRec89[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec92[1] = fRec92[0];
			fRec93[1] = fRec93[0];
			iVec32[1] = iVec32[0];
			iRec91[1] = iRec91[0];
			iRec94[1] = iRec94[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			fRec98[1] = fRec98[0];
			iVec33[1] = iVec33[0];
			iRec96[1] = iRec96[0];
			iRec99[1] = iRec99[0];
			fRec100[1] = fRec100[0];
			fRec102[1] = fRec102[0];
			fRec103[1] = fRec103[0];
			iVec34[1] = iVec34[0];
			iRec101[1] = iRec101[0];
			iRec104[1] = iRec104[0];
			fRec105[1] = fRec105[0];
			fRec107[1] = fRec107[0];
			fRec108[1] = fRec108[0];
			iVec35[1] = iVec35[0];
			iRec106[1] = iRec106[0];
			iRec109[1] = iRec109[0];
			fRec110[1] = fRec110[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			iVec36[1] = iVec36[0];
			iRec111[1] = iRec111[0];
			iRec114[1] = iRec114[0];
			fRec115[1] = fRec115[0];
			fRec117[1] = fRec117[0];
			fRec118[1] = fRec118[0];
			iVec37[1] = iVec37[0];
			iRec116[1] = iRec116[0];
			iRec119[1] = iRec119[0];
			fRec120[1] = fRec120[0];
			fRec122[1] = fRec122[0];
			fRec123[1] = fRec123[0];
			iVec38[1] = iVec38[0];
			iRec121[1] = iRec121[0];
			iRec124[1] = iRec124[0];
			fRec125[1] = fRec125[0];
			fRec127[1] = fRec127[0];
			fRec128[1] = fRec128[0];
			iVec39[1] = iVec39[0];
			iRec126[1] = iRec126[0];
			iRec129[1] = iRec129[0];
			fRec130[1] = fRec130[0];
			fRec132[1] = fRec132[0];
			fRec133[1] = fRec133[0];
			iVec40[1] = iVec40[0];
			iRec131[1] = iRec131[0];
			iRec134[1] = iRec134[0];
			fRec135[1] = fRec135[0];
			fRec137[1] = fRec137[0];
			fRec138[1] = fRec138[0];
			iVec41[1] = iVec41[0];
			iRec136[1] = iRec136[0];
			iRec139[1] = iRec139[0];
			fRec140[1] = fRec140[0];
			fRec142[1] = fRec142[0];
			fRec143[1] = fRec143[0];
			iVec42[1] = iVec42[0];
			iRec141[1] = iRec141[0];
			iRec144[1] = iRec144[0];
			fRec145[1] = fRec145[0];
			fRec147[1] = fRec147[0];
			fRec148[1] = fRec148[0];
			iVec43[1] = iVec43[0];
			iRec146[1] = iRec146[0];
			iRec149[1] = iRec149[0];
			fRec150[1] = fRec150[0];
			fRec152[1] = fRec152[0];
			fRec153[1] = fRec153[0];
			iVec44[1] = iVec44[0];
			iRec151[1] = iRec151[0];
			iRec154[1] = iRec154[0];
			fRec155[1] = fRec155[0];
			fRec157[1] = fRec157[0];
			fRec158[1] = fRec158[0];
			iVec45[1] = iVec45[0];
			iRec156[1] = iRec156[0];
			iRec159[1] = iRec159[0];
			fRec160[1] = fRec160[0];
			fRec162[1] = fRec162[0];
			fRec163[1] = fRec163[0];
			iVec46[1] = iVec46[0];
			iRec161[1] = iRec161[0];
			iRec164[1] = iRec164[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec165[1] = fRec165[0];
			fRec166[1] = fRec166[0];
			iVec47[1] = iVec47[0];
			iVec48[1] = iVec48[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			iRec176[1] = iRec176[0];
			iRec173[1] = iRec173[0];
			fRec172[1] = fRec172[0];
			iVec49[1] = iVec49[0];
			iVec50[1] = iVec50[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			iRec181[1] = iRec181[0];
			iRec178[1] = iRec178[0];
			fRec177[1] = fRec177[0];
			iVec51[1] = iVec51[0];
			iVec52[1] = iVec52[0];
			fRec185[1] = fRec185[0];
			fRec184[1] = fRec184[0];
			iRec186[1] = iRec186[0];
			iRec183[1] = iRec183[0];
			fRec182[1] = fRec182[0];
			iVec53[1] = iVec53[0];
			iVec54[1] = iVec54[0];
			fRec190[1] = fRec190[0];
			fRec189[1] = fRec189[0];
			iRec191[1] = iRec191[0];
			iRec188[1] = iRec188[0];
			fRec187[1] = fRec187[0];
			iVec55[1] = iVec55[0];
			iVec56[1] = iVec56[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			iRec196[1] = iRec196[0];
			iRec193[1] = iRec193[0];
			fRec192[1] = fRec192[0];
			iVec57[1] = iVec57[0];
			iVec58[1] = iVec58[0];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			iRec201[1] = iRec201[0];
			iRec198[1] = iRec198[0];
			fRec197[1] = fRec197[0];
			iVec59[1] = iVec59[0];
			iVec60[1] = iVec60[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			iRec206[1] = iRec206[0];
			iRec203[1] = iRec203[0];
			fRec202[1] = fRec202[0];
			iVec61[1] = iVec61[0];
			iVec62[1] = iVec62[0];
			fRec210[1] = fRec210[0];
			fRec209[1] = fRec209[0];
			iRec211[1] = iRec211[0];
			iRec208[1] = iRec208[0];
			fRec207[1] = fRec207[0];
			iVec63[1] = iVec63[0];
			iVec64[1] = iVec64[0];
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			iRec216[1] = iRec216[0];
			iRec213[1] = iRec213[0];
			fRec212[1] = fRec212[0];
			iVec65[1] = iVec65[0];
			iVec66[1] = iVec66[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			iRec221[1] = iRec221[0];
			iRec218[1] = iRec218[0];
			fRec217[1] = fRec217[0];
			iVec67[1] = iVec67[0];
			iVec68[1] = iVec68[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			iRec226[1] = iRec226[0];
			iRec223[1] = iRec223[0];
			fRec222[1] = fRec222[0];
			iVec69[1] = iVec69[0];
			iVec70[1] = iVec70[0];
			fRec230[1] = fRec230[0];
			fRec229[1] = fRec229[0];
			iRec231[1] = iRec231[0];
			iRec228[1] = iRec228[0];
			fRec227[1] = fRec227[0];
			iVec71[1] = iVec71[0];
			iVec72[1] = iVec72[0];
			fRec235[1] = fRec235[0];
			fRec234[1] = fRec234[0];
			iRec236[1] = iRec236[0];
			iRec233[1] = iRec233[0];
			fRec232[1] = fRec232[0];
			iVec73[1] = iVec73[0];
			iVec74[1] = iVec74[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			iRec241[1] = iRec241[0];
			iRec238[1] = iRec238[0];
			fRec237[1] = fRec237[0];
			iVec75[1] = iVec75[0];
			iVec76[1] = iVec76[0];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			iRec246[1] = iRec246[0];
			iRec243[1] = iRec243[0];
			fRec242[1] = fRec242[0];
			iRec170[1] = iRec170[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec249[1] = fRec249[0];
			fRec251[1] = fRec251[0];
			fRec252[1] = fRec252[0];
			iVec77[1] = iVec77[0];
			iRec250[1] = iRec250[0];
			iRec253[1] = iRec253[0];
			fRec254[1] = fRec254[0];
			fRec256[1] = fRec256[0];
			fRec257[1] = fRec257[0];
			iVec78[1] = iVec78[0];
			iRec255[1] = iRec255[0];
			iRec258[1] = iRec258[0];
			fRec259[1] = fRec259[0];
			fRec261[1] = fRec261[0];
			fRec262[1] = fRec262[0];
			iVec79[1] = iVec79[0];
			iRec260[1] = iRec260[0];
			iRec263[1] = iRec263[0];
			fRec264[1] = fRec264[0];
			fRec266[1] = fRec266[0];
			fRec267[1] = fRec267[0];
			iVec80[1] = iVec80[0];
			iRec265[1] = iRec265[0];
			iRec268[1] = iRec268[0];
			fRec269[1] = fRec269[0];
			fRec271[1] = fRec271[0];
			fRec272[1] = fRec272[0];
			iVec81[1] = iVec81[0];
			iRec270[1] = iRec270[0];
			iRec273[1] = iRec273[0];
			fRec274[1] = fRec274[0];
			fRec276[1] = fRec276[0];
			fRec277[1] = fRec277[0];
			iVec82[1] = iVec82[0];
			iRec275[1] = iRec275[0];
			iRec278[1] = iRec278[0];
			fRec279[1] = fRec279[0];
			fRec281[1] = fRec281[0];
			fRec282[1] = fRec282[0];
			iVec83[1] = iVec83[0];
			iRec280[1] = iRec280[0];
			iRec283[1] = iRec283[0];
			fRec284[1] = fRec284[0];
			fRec286[1] = fRec286[0];
			fRec287[1] = fRec287[0];
			iVec84[1] = iVec84[0];
			iRec285[1] = iRec285[0];
			iRec288[1] = iRec288[0];
			fRec289[1] = fRec289[0];
			fRec291[1] = fRec291[0];
			fRec292[1] = fRec292[0];
			iVec85[1] = iVec85[0];
			iRec290[1] = iRec290[0];
			iRec293[1] = iRec293[0];
			fRec294[1] = fRec294[0];
			fRec296[1] = fRec296[0];
			fRec297[1] = fRec297[0];
			iVec86[1] = iVec86[0];
			iRec295[1] = iRec295[0];
			iRec298[1] = iRec298[0];
			fRec299[1] = fRec299[0];
			fRec301[1] = fRec301[0];
			fRec302[1] = fRec302[0];
			iVec87[1] = iVec87[0];
			iRec300[1] = iRec300[0];
			iRec303[1] = iRec303[0];
			fRec304[1] = fRec304[0];
			fRec306[1] = fRec306[0];
			fRec307[1] = fRec307[0];
			iVec88[1] = iVec88[0];
			iRec305[1] = iRec305[0];
			iRec308[1] = iRec308[0];
			fRec309[1] = fRec309[0];
			fRec311[1] = fRec311[0];
			fRec312[1] = fRec312[0];
			iVec89[1] = iVec89[0];
			iRec310[1] = iRec310[0];
			iRec313[1] = iRec313[0];
			fRec314[1] = fRec314[0];
			fRec316[1] = fRec316[0];
			fRec317[1] = fRec317[0];
			iVec90[1] = iVec90[0];
			iRec315[1] = iRec315[0];
			iRec318[1] = iRec318[0];
			fRec319[1] = fRec319[0];
			fRec321[1] = fRec321[0];
			fRec322[1] = fRec322[0];
			iVec91[1] = iVec91[0];
			iRec320[1] = iRec320[0];
			iRec323[1] = iRec323[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec167[1] = fRec167[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "Folder.dsp"
	#define FAUST_CLASS_NAME "_Folder"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _Folder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 12
	#define FAUST_PASSIVES 1

	FAUST_ADDHORIZONTALBARGRAPH("granola 0/global/index/writeIndex", fHbargraph0, 0.0f, 239999.0f);
	FAUST_ADDCHECKBOX("granola 0/global/index/Freeze", fCheckbox1);
	FAUST_ADDVERTICALSLIDER("granola 0/global/volumes/input/gain", fVslider1, 0.0f, -1.5f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("granola 0/global/volumes/input/feedback", fVslider0, 0.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("granola 0/global/volumes/output/dry/wet", fVslider2, 0.5f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("granola 0/global/volumes/output/gain", fVslider3, 0.0f, -1.0f, 1.0f, 0.01f);
	FAUST_ADDBUTTON("granola 0/grains/SEED", fButton0);
	FAUST_ADDHORIZONTALSLIDER("granola 0/grains/density", fHslider0, 1.0f, 0.01f, 1e+03f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("granola 0/grains/time", fHslider3, 0.0f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("granola 0/grains/size", fHslider2, 0.5f, 0.03f, 5.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("granola 0/grains/pitch", fHslider1, 0.0f, -24.0f, 24.0f, 0.5f);
	FAUST_ADDCHECKBOX("granola 0/grains/REVERSE", fCheckbox0);
	FAUST_ADDHORIZONTALSLIDER("granola 0/grains/shape", fHslider4, 0.0f, 0.0f, 1.0f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(CHECKBOX, Freeze, "granola 0/global/index/Freeze", fCheckbox1, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(VERTICALSLIDER, gain, "granola 0/global/volumes/input/gain", fVslider1, 0.0f, -1.5f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, feedback, "granola 0/global/volumes/input/feedback", fVslider0, 0.0f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, dry/wet, "granola 0/global/volumes/output/dry/wet", fVslider2, 0.5f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, gain, "granola 0/global/volumes/output/gain", fVslider3, 0.0f, -1.0f, 1.0f, 0.01f) \
		p(BUTTON, SEED, "granola 0/grains/SEED", fButton0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, density, "granola 0/grains/density", fHslider0, 1.0f, 0.01f, 1e+03f, 0.01f) \
		p(HORIZONTALSLIDER, time, "granola 0/grains/time", fHslider3, 0.0f, 0.0f, 1.0f, 0.001f) \
		p(HORIZONTALSLIDER, size, "granola 0/grains/size", fHslider2, 0.5f, 0.03f, 5.0f, 0.01f) \
		p(HORIZONTALSLIDER, pitch, "granola 0/grains/pitch", fHslider1, 0.0f, -24.0f, 24.0f, 0.5f) \
		p(CHECKBOX, REVERSE, "granola 0/grains/REVERSE", fCheckbox0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, shape, "granola 0/grains/shape", fHslider4, 0.0f, 0.0f, 1.0f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \
		p(HORIZONTALBARGRAPH, writeIndex, "granola 0/global/index/writeIndex", fHbargraph0, 0.0, 0.0f, 239999.0f, 0.0) \

#endif

#endif
