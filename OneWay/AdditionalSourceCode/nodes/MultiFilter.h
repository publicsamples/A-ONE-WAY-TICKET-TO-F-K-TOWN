#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace MultiFilter_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using pma5_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;
DECLARE_PARAMETER_RANGE(sliderbank_c0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using sliderbank_c0 = parameter::from0To1<pma5_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma6_t = pma5_t<NV>;
template <int NV>
using sliderbank_c1 = parameter::from0To1<pma6_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma7_t = pma5_t<NV>;
template <int NV>
using sliderbank_c2 = parameter::from0To1<pma7_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma8_t = pma5_t<NV>;
template <int NV>
using sliderbank_c3 = parameter::from0To1<pma8_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<2164996>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<pma5_t<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable3_t<NV>>, 
                                 pma5_t<NV>, 
                                 math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<2164997>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<pma6_t<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   pma6_t<NV>, 
                                   math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<pma7_t<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   pma7_t<NV>, 
                                   math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<pma8_t<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   pma8_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain_t<NV>>, 
                                  chain12_t<NV>, 
                                  chain14_t<NV>, 
                                  chain15_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using clone_pack_0 = parameter::from0To1<filters::svf<NV>, 
                                         0, 
                                         clone_pack_0Range>;

template <int NV> using clone_pack_1 = clone_pack_0<NV>;

template <int NV> using clone_pack_2 = clone_pack_0<NV>;

template <int NV> using clone_pack_3 = clone_pack_0<NV>;

template <int NV>
using clone_pack_4 = parameter::from0To1<filters::allpass<NV>, 
                                         0, 
                                         clone_pack_0Range>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack_5Range, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using clone_pack_5 = parameter::from0To1<project::Comb<NV>, 
                                         1, 
                                         clone_pack_5Range>;

template <int NV>
using clone_pack_cc = parameter::clonechain<parameter::cloned<clone_pack_0<NV>>, 
                                            parameter::cloned<clone_pack_1<NV>>, 
                                            parameter::cloned<clone_pack_2<NV>>, 
                                            parameter::cloned<clone_pack_3<NV>>, 
                                            parameter::cloned<clone_pack_4<NV>>, 
                                            parameter::cloned<clone_pack_5<NV>>, 
                                            parameter::cloned<parameter::plain<project::klp<NV>, 1>>, 
                                            parameter::cloned<parameter::plain<project::khp<NV>, 1>>>;
template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<clone_pack_cc<NV>>, 
                                data::external::sliderpack<4>>;
template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<clone_pack_t<NV>, 1>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank_t<NV>>, 
                                   split3_t<NV>, 
                                   peak_t<NV>, 
                                   pma9_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain10_t<NV>>>;

template <int NV> using pma10_t = pma5_t<NV>;
template <int NV>
using sliderbank4_c0 = parameter::from0To1<pma10_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma11_t = pma5_t<NV>;
template <int NV>
using sliderbank4_c1 = parameter::from0To1<pma11_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma12_t = pma5_t<NV>;
template <int NV>
using sliderbank4_c2 = parameter::from0To1<pma12_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma13_t = pma5_t<NV>;
template <int NV>
using sliderbank4_c3 = parameter::from0To1<pma13_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank4_multimod = parameter::list<sliderbank4_c0<NV>, 
                                             sliderbank4_c1<NV>, 
                                             sliderbank4_c2<NV>, 
                                             sliderbank4_c3<NV>>;

template <int NV>
using sliderbank4_t = wrap::data<control::sliderbank<sliderbank4_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable7_t_index = global_cable3_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<pma10_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  pma10_t<NV>, 
                                  math::add<NV>>;
using global_cable8_t_index = global_cable4_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   pma11_t<NV>, 
                                   math::add<NV>>;
using global_cable9_t_index = global_cable5_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<pma12_t<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   pma12_t<NV>, 
                                   math::add<NV>>;
using global_cable10_t_index = global_cable6_t_index;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<pma13_t<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   pma13_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain6_t<NV>>, 
                                  chain13_t<NV>, 
                                  chain16_t<NV>, 
                                  chain17_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma14_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma14_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank4_t<NV>>, 
                                   split6_t<NV>, 
                                   peak1_t<NV>, 
                                   pma14_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain11_t<NV>>>;

template <int NV> using pma30_t = pma5_t<NV>;
template <int NV>
using sliderbank5_c0 = parameter::from0To1<pma30_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma31_t = pma5_t<NV>;
template <int NV>
using sliderbank5_c1 = parameter::from0To1<pma31_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma32_t = pma5_t<NV>;
template <int NV>
using sliderbank5_c2 = parameter::from0To1<pma32_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma33_t = pma5_t<NV>;
template <int NV>
using sliderbank5_c3 = parameter::from0To1<pma33_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank5_multimod = parameter::list<sliderbank5_c0<NV>, 
                                             sliderbank5_c1<NV>, 
                                             sliderbank5_c2<NV>, 
                                             sliderbank5_c3<NV>>;

template <int NV>
using sliderbank5_t = wrap::data<control::sliderbank<sliderbank5_multimod<NV>>, 
                                 data::external::sliderpack<3>>;
using global_cable11_t_index = global_cable3_t_index;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<pma30_t<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable11_t<NV>>, 
                                  pma30_t<NV>, 
                                  math::add<NV>>;
using global_cable24_t_index = global_cable4_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<pma31_t<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   pma31_t<NV>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable5_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<pma32_t<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   pma32_t<NV>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable6_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<pma33_t<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   pma33_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain7_t<NV>>, 
                                   chain21_t<NV>, 
                                   chain22_t<NV>, 
                                   chain23_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using clone_cable_0 = parameter::from0To1<filters::allpass<NV>, 
                                          1, 
                                          clone_cable_0Range>;

template <int NV>
using clone_cable_1 = parameter::from0To1<filters::svf<NV>, 
                                          1, 
                                          clone_cable_0Range>;

template <int NV> using clone_cable_2 = clone_cable_1<NV>;

template <int NV> using clone_cable_3 = clone_cable_1<NV>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable_5Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using clone_cable_5 = parameter::from0To1<project::klp<NV>, 
                                          0, 
                                          clone_cable_5Range>;

template <int NV>
using clone_cable_6 = parameter::from0To1<project::khp<NV>, 
                                          0, 
                                          clone_cable_5Range>;

template <int NV> using clone_cable_7 = clone_cable_1<NV>;

template <int NV>
using clone_cable_cc = parameter::clonechain<parameter::cloned<clone_cable_0<NV>>, 
                                             parameter::cloned<clone_cable_1<NV>>, 
                                             parameter::cloned<clone_cable_2<NV>>, 
                                             parameter::cloned<clone_cable_3<NV>>, 
                                             parameter::cloned<parameter::plain<project::Comb<NV>, 0>>, 
                                             parameter::cloned<clone_cable_5<NV>>, 
                                             parameter::cloned<clone_cable_6<NV>>, 
                                             parameter::cloned<clone_cable_7<NV>>>;
template <int NV>
using clone_cable_t = control::clone_cable<clone_cable_cc<NV>, duplilogic::fixed>;
template <int NV>
using pma34_t = control::pma<NV, 
                             parameter::plain<clone_cable_t<NV>, 1>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma34_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank5_t<NV>>, 
                                   split14_t<NV>, 
                                   peak2_t<NV>, 
                                   pma34_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain19_t<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, split2_t<NV>>, 
                                  split4_t<NV>, 
                                  split7_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>, 
                                   filters::svf<NV>, 
                                   filters::svf<NV>, 
                                   filters::svf<NV>, 
                                   project::klp<NV>, 
                                   project::khp<NV>, 
                                   filters::allpass<NV>, 
                                   project::Comb<NV>>;
DECLARE_PARAMETER_RANGE_STEP(clone_cable3_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using clone_cable3_mod = parameter::from0To1<branch_t<NV>, 
                                             0, 
                                             clone_cable3_modRange>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<clone_cable3_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack_t<NV>>, 
                                  clone_cable_t<NV>, 
                                  clone_cable3_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split1_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, branch_t<NV>>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_t<NV>>, 
                                  core::gain<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

namespace MultiFilter_t_parameters
{
// Parameter list for MultiFilter_impl::MultiFilter_t ----------------------------------------------

template <int NV>
using CutOffset = parameter::from0To1<MultiFilter_impl::pma9_t<NV>, 
                                      2, 
                                      MultiFilter_impl::sliderbank_c0Range>;

template <int NV>
using Res = parameter::from0To1<MultiFilter_impl::pma34_t<NV>, 
                                2, 
                                MultiFilter_impl::sliderbank_c0Range>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             8., 
                             1.);

template <int NV>
using Mode = parameter::chain<Mode_InputRange, 
                              parameter::plain<MultiFilter_impl::clone_cable3_t<NV>, 1>>;

template <int NV>
using Mix = parameter::from0To1<MultiFilter_impl::pma14_t<NV>, 
                                2, 
                                MultiFilter_impl::sliderbank_c0Range>;

template <int NV>
using MultiGain = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      MultiFilter_impl::xfader_c0Range>;

template <int NV>
using CutMod = parameter::plain<MultiFilter_impl::pma9_t<NV>, 
                                1>;
template <int NV>
using MixMod = parameter::plain<MultiFilter_impl::pma14_t<NV>, 
                                1>;
template <int NV>
using ResMod = parameter::plain<MultiFilter_impl::pma34_t<NV>, 
                                1>;
template <int NV>
using MultiFilter_t_plist = parameter::list<CutOffset<NV>, 
                                            Res<NV>, 
                                            Mode<NV>, 
                                            Mix<NV>, 
                                            MultiGain<NV>, 
                                            CutMod<NV>, 
                                            MixMod<NV>, 
                                            ResMod<NV>>;
}

template <int NV>
using MultiFilter_t_ = container::chain<MultiFilter_t_parameters::MultiFilter_t_plist<NV>, 
                                        wrap::fix<2, modchain1_t<NV>>, 
                                        modchain_t<NV>, 
                                        xfader_t<NV>, 
                                        split_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public MultiFilter_impl::MultiFilter_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 5;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(MultiFilter);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(128)
		{
			0x005B, 0x0000, 0x4300, 0x7475, 0x664F, 0x7366, 0x7465, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0001, 0x0000, 0x6552, 0x0073, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x8591, 0x3EA3, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x025B, 0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 
            0x0000, 0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 
            0x754D, 0x746C, 0x4769, 0x6961, 0x006E, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x4859, 0x3F15, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 
            0x0000, 0x4300, 0x7475, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xE9BD, 0x3EA5, 0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 
            0x0000, 0x4D00, 0x7869, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 
            0x0000, 0x5200, 0x7365, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                                      // MultiFilter_impl::modchain1_t<NV>
		auto& split5 = this->getT(0).getT(0);                                                 // MultiFilter_impl::split5_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0);                                         // MultiFilter_impl::split2_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0);                                // MultiFilter_impl::chain10_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                     // MultiFilter_impl::sliderbank_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                         // MultiFilter_impl::split3_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                  // MultiFilter_impl::chain_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);  // MultiFilter_impl::global_cable3_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);           // MultiFilter_impl::pma5_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);            // math::add<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                // MultiFilter_impl::chain12_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);  // MultiFilter_impl::global_cable4_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);           // MultiFilter_impl::pma6_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                // MultiFilter_impl::chain14_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);  // MultiFilter_impl::global_cable5_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);           // MultiFilter_impl::pma7_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                // MultiFilter_impl::chain15_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);  // MultiFilter_impl::global_cable6_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);           // MultiFilter_impl::pma8_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(2);                           // MultiFilter_impl::peak_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                           // MultiFilter_impl::pma9_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(1);                                         // MultiFilter_impl::split4_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(0);                                // MultiFilter_impl::chain11_t<NV>
		auto& sliderbank4 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                    // MultiFilter_impl::sliderbank4_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                         // MultiFilter_impl::split6_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                 // MultiFilter_impl::chain6_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);  // MultiFilter_impl::global_cable7_t<NV>
		auto& pma10 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);          // MultiFilter_impl::pma10_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);           // math::add<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);                // MultiFilter_impl::chain13_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);  // MultiFilter_impl::global_cable8_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);          // MultiFilter_impl::pma11_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain16 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2);                // MultiFilter_impl::chain16_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0);  // MultiFilter_impl::global_cable9_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);          // MultiFilter_impl::pma12_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(2);           // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3);                // MultiFilter_impl::chain17_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0); // MultiFilter_impl::global_cable10_t<NV>
		auto& pma13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(1);          // MultiFilter_impl::pma13_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(2);           // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                          // MultiFilter_impl::peak1_t<NV>
		auto& pma14 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                          // MultiFilter_impl::pma14_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(2);                                         // MultiFilter_impl::split7_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(2).getT(0);                                // MultiFilter_impl::chain19_t<NV>
		auto& sliderbank5 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                    // MultiFilter_impl::sliderbank5_t<NV>
		auto& split14 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                        // MultiFilter_impl::split14_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);                 // MultiFilter_impl::chain7_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0); // MultiFilter_impl::global_cable11_t<NV>
		auto& pma30 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(1);          // MultiFilter_impl::pma30_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(2);           // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);                // MultiFilter_impl::chain21_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0); // MultiFilter_impl::global_cable24_t<NV>
		auto& pma31 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(1);          // MultiFilter_impl::pma31_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2);                // MultiFilter_impl::chain22_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0); // MultiFilter_impl::global_cable25_t<NV>
		auto& pma32 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(1);          // MultiFilter_impl::pma32_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3);                // MultiFilter_impl::chain23_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0); // MultiFilter_impl::global_cable26_t<NV>
		auto& pma33 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(1);          // MultiFilter_impl::pma33_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                          // MultiFilter_impl::peak2_t<NV>
		auto& pma34 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                          // MultiFilter_impl::pma34_t<NV>
		auto& modchain = this->getT(1);                                                       // MultiFilter_impl::modchain_t<NV>
		auto& split1 = this->getT(1).getT(0);                                                 // MultiFilter_impl::split1_t<NV>
		auto& clone_pack = this->getT(1).getT(0).getT(0);                                     // MultiFilter_impl::clone_pack_t<NV>
		auto& clone_cable = this->getT(1).getT(0).getT(1);                                    // MultiFilter_impl::clone_cable_t<NV>
		auto& clone_cable3 = this->getT(1).getT(0).getT(2);                                   // MultiFilter_impl::clone_cable3_t<NV>
		auto& xfader = this->getT(2);                                                         // MultiFilter_impl::xfader_t<NV>
		auto& split = this->getT(3);                                                          // MultiFilter_impl::split_t<NV>
		auto& chain1 = this->getT(3).getT(0);                                                 // MultiFilter_impl::chain1_t<NV>
		auto& gain1 = this->getT(3).getT(0).getT(0);                                          // core::gain<NV>
		auto& chain2 = this->getT(3).getT(1);                                                 // MultiFilter_impl::chain2_t<NV>
		auto& clone = this->getT(3).getT(1).getT(0);                                          // MultiFilter_impl::clone_t<NV>                                          // MultiFilter_impl::clone_child_t<NV>
		auto branch = this->getT(3).getT(1).getT(0).getT(0);                                  // MultiFilter_impl::branch_t<NV>
		auto svf = this->getT(3).getT(1).getT(0).getT(0).getT(0);                             // filters::svf<NV>
		auto svf1 = this->getT(3).getT(1).getT(0).getT(0).getT(1);                            // filters::svf<NV>
		auto svf2 = this->getT(3).getT(1).getT(0).getT(0).getT(2);                            // filters::svf<NV>
		auto svf3 = this->getT(3).getT(1).getT(0).getT(0).getT(3);                            // filters::svf<NV>
		auto faust1 = this->getT(3).getT(1).getT(0).getT(0).getT(4);                          // project::klp<NV>
		auto faust2 = this->getT(3).getT(1).getT(0).getT(0).getT(5);                          // project::khp<NV>
		auto allpass = this->getT(3).getT(1).getT(0).getT(0).getT(6);                         // filters::allpass<NV>
		auto faust = this->getT(3).getT(1).getT(0).getT(0).getT(7);                           // project::Comb<NV>
		auto& gain2 = this->getT(3).getT(1).getT(1);                                          // core::gain<NV>
		auto& gain = this->getT(3).getT(1).getT(2);                                           // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma9); // CutOffset -> pma9::Add
		
		this->getParameterT(1).connectT(0, pma34); // Res -> pma34::Add
		
		this->getParameterT(2).connectT(0, clone_cable3); // Mode -> clone_cable3::Value
		
		this->getParameterT(3).connectT(0, pma14); // Mix -> pma14::Add
		
		this->getParameterT(4).connectT(0, gain2); // MultiGain -> gain2::Gain
		
		this->getParameterT(5).connectT(0, pma9); // CutMod -> pma9::Multiply
		
		this->getParameterT(6).connectT(0, pma14); // MixMod -> pma14::Multiply
		
		this->getParameterT(7).connectT(0, pma34); // ResMod -> pma34::Multiply
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma5.getWrappedObject().getParameter().connectT(0, add);  // pma5 -> add::Value
		pma6.getWrappedObject().getParameter().connectT(0, add1); // pma6 -> add1::Value
		pma7.getWrappedObject().getParameter().connectT(0, add3); // pma7 -> add3::Value
		pma8.getWrappedObject().getParameter().connectT(0, add2); // pma8 -> add2::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, pma5);                   // sliderbank -> pma5::Multiply
		sliderbank_p.getParameterT(1).connectT(0, pma6);                   // sliderbank -> pma6::Multiply
		sliderbank_p.getParameterT(2).connectT(0, pma7);                   // sliderbank -> pma7::Multiply
		sliderbank_p.getParameterT(3).connectT(0, pma8);                   // sliderbank -> pma8::Multiply
		global_cable3.getWrappedObject().getParameter().connectT(0, pma5); // global_cable3 -> pma5::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, pma6); // global_cable4 -> pma6::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, pma7); // global_cable5 -> pma7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, pma8); // global_cable6 -> pma8::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, svf);     // clone_pack -> svf::Frequency
		clone_pack.getWrappedObject().getParameter().connectT(1, svf1);    // clone_pack -> svf1::Frequency
		clone_pack.getWrappedObject().getParameter().connectT(2, svf2);    // clone_pack -> svf2::Frequency
		clone_pack.getWrappedObject().getParameter().connectT(3, svf3);    // clone_pack -> svf3::Frequency
		clone_pack.getWrappedObject().getParameter().connectT(4, allpass); // clone_pack -> allpass::Frequency
		clone_pack.getWrappedObject().getParameter().connectT(5, faust);   // clone_pack -> faust::del
		clone_pack.getWrappedObject().getParameter().connectT(6, faust1);  // clone_pack -> faust1::freq
		clone_pack.getWrappedObject().getParameter().connectT(7, faust2);  // clone_pack -> faust2::freq
		pma9.getWrappedObject().getParameter().connectT(0, clone_pack);    // pma9 -> clone_pack::Value
		peak.getParameter().connectT(0, pma9);                             // peak -> pma9::Value
		pma10.getWrappedObject().getParameter().connectT(0, add4);         // pma10 -> add4::Value
		pma11.getWrappedObject().getParameter().connectT(0, add5);         // pma11 -> add5::Value
		pma12.getWrappedObject().getParameter().connectT(0, add6);         // pma12 -> add6::Value
		pma13.getWrappedObject().getParameter().connectT(0, add7);         // pma13 -> add7::Value
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, pma10);                   // sliderbank4 -> pma10::Multiply
		sliderbank4_p.getParameterT(1).connectT(0, pma11);                   // sliderbank4 -> pma11::Multiply
		sliderbank4_p.getParameterT(2).connectT(0, pma12);                   // sliderbank4 -> pma12::Multiply
		sliderbank4_p.getParameterT(3).connectT(0, pma13);                   // sliderbank4 -> pma13::Multiply
		global_cable7.getWrappedObject().getParameter().connectT(0, pma10);  // global_cable7 -> pma10::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, pma11);  // global_cable8 -> pma11::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, pma12);  // global_cable9 -> pma12::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, pma13); // global_cable10 -> pma13::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain);                 // xfader -> gain::Gain
		pma14.getWrappedObject().getParameter().connectT(0, xfader); // pma14 -> xfader::Value
		peak1.getParameter().connectT(0, pma14);                     // peak1 -> pma14::Value
		pma30.getWrappedObject().getParameter().connectT(0, add8);   // pma30 -> add8::Value
		pma31.getWrappedObject().getParameter().connectT(0, add9);   // pma31 -> add9::Value
		pma32.getWrappedObject().getParameter().connectT(0, add10);  // pma32 -> add10::Value
		pma33.getWrappedObject().getParameter().connectT(0, add11);  // pma33 -> add11::Value
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, pma30);                   // sliderbank5 -> pma30::Multiply
		sliderbank5_p.getParameterT(1).connectT(0, pma31);                   // sliderbank5 -> pma31::Multiply
		sliderbank5_p.getParameterT(2).connectT(0, pma32);                   // sliderbank5 -> pma32::Multiply
		sliderbank5_p.getParameterT(3).connectT(0, pma33);                   // sliderbank5 -> pma33::Multiply
		global_cable11.getWrappedObject().getParameter().connectT(0, pma30); // global_cable11 -> pma30::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, pma31); // global_cable24 -> pma31::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, pma32); // global_cable25 -> pma32::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, pma33); // global_cable26 -> pma33::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, allpass);  // clone_cable -> allpass::Q
		clone_cable.getWrappedObject().getParameter().connectT(1, svf3);     // clone_cable -> svf3::Q
		clone_cable.getWrappedObject().getParameter().connectT(2, svf2);     // clone_cable -> svf2::Q
		clone_cable.getWrappedObject().getParameter().connectT(3, svf1);     // clone_cable -> svf1::Q
		clone_cable.getWrappedObject().getParameter().connectT(4, faust);    // clone_cable -> faust::aN
		clone_cable.getWrappedObject().getParameter().connectT(5, faust1);   // clone_cable -> faust1::Q
		clone_cable.getWrappedObject().getParameter().connectT(6, faust2);   // clone_cable -> faust2::Q
		clone_cable.getWrappedObject().getParameter().connectT(7, svf);      // clone_cable -> svf::Q
		pma34.getWrappedObject().getParameter().connectT(0, clone_cable);    // pma34 -> clone_cable::Value
		peak2.getParameter().connectT(0, pma34);                             // peak2 -> pma34::Value
		clone_cable3.getWrappedObject().getParameter().connectT(0, branch);  // clone_cable3 -> branch::Index
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma5::Value is automated
		;                          // pma5::Multiply is automated
		pma5.setParameterT(2, 0.); // control::pma::Add
		
		; // add::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma6::Value is automated
		;                          // pma6::Multiply is automated
		pma6.setParameterT(2, 0.); // control::pma::Add
		
		; // add1::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma7::Value is automated
		;                          // pma7::Multiply is automated
		pma7.setParameterT(2, 0.); // control::pma::Add
		
		; // add3::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma8::Value is automated
		;                          // pma8::Multiply is automated
		pma8.setParameterT(2, 0.); // control::pma::Add
		
		; // add2::Value is automated
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma10::Value is automated
		;                           // pma10::Multiply is automated
		pma10.setParameterT(2, 0.); // control::pma::Add
		
		; // add4::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma11::Value is automated
		;                           // pma11::Multiply is automated
		pma11.setParameterT(2, 0.); // control::pma::Add
		
		; // add5::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma12::Value is automated
		;                           // pma12::Multiply is automated
		pma12.setParameterT(2, 0.); // control::pma::Add
		
		; // add6::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma13::Value is automated
		;                           // pma13::Multiply is automated
		pma13.setParameterT(2, 0.); // control::pma::Add
		
		; // add7::Value is automated
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		sliderbank5.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma30::Value is automated
		;                           // pma30::Multiply is automated
		pma30.setParameterT(2, 0.); // control::pma::Add
		
		; // add8::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma31::Value is automated
		;                           // pma31::Multiply is automated
		pma31.setParameterT(2, 0.); // control::pma::Add
		
		; // add9::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma32::Value is automated
		;                           // pma32::Multiply is automated
		pma32.setParameterT(2, 0.); // control::pma::Add
		
		; // add10::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma33::Value is automated
		;                           // pma33::Multiply is automated
		pma33.setParameterT(2, 0.); // control::pma::Add
		
		; // add11::Value is automated
		
		; // pma34::Value is automated
		; // pma34::Multiply is automated
		; // pma34::Add is automated
		
		clone_pack.setParameterT(0, 8.); // control::clone_pack::NumClones
		;                                // clone_pack::Value is automated
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable3::NumClones is deactivated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // xfader::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		; // branch::Index is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 2.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // svf3::Frequency is automated
		;                                // svf3::Q is automated
		svf3.setParameterT(2, 0.798785); // filters::svf::Gain
		svf3.setParameterT(3, 0.01);     // filters::svf::Smoothing
		svf3.setParameterT(4, 3.);       // filters::svf::Mode
		svf3.setParameterT(5, 1.);       // filters::svf::Enabled
		
		; // faust1::Q is automated
		; // faust1::freq is automated
		
		; // faust2::Q is automated
		; // faust2::freq is automated
		
		;                                    // allpass::Frequency is automated
		;                                    // allpass::Q is automated
		allpass.setParameterT(2, -0.777155); // filters::allpass::Gain
		allpass.setParameterT(3, 0.01);      // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);        // filters::allpass::Mode
		allpass.setParameterT(5, 1.);        // filters::allpass::Enabled
		
		; // faust::aN is automated
		; // faust::del is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.319378);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.583135);
		this->setParameterT(5, 0.324049);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MultiFilter_impl::global_cable26_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // MultiFilter_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // MultiFilter_impl::peak_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // MultiFilter_impl::sliderbank4_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index); // MultiFilter_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index); // MultiFilter_impl::sliderbank5_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).setExternalData(b, index); // MultiFilter_impl::peak2_t<NV>
		this->getT(1).getT(0).getT(0).setExternalData(b, index);                 // MultiFilter_impl::clone_pack_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using MultiFilter = wrap::node<MultiFilter_impl::instance<NV>>;
}


