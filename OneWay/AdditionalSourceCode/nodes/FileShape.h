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

namespace FileShape_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<math::add<NV>, 0>>;
DECLARE_PARAMETER_RANGE(sliderbank_c0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using sliderbank_c0 = parameter::from0To1<pma_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma2_t = pma_t<NV>;
template <int NV>
using sliderbank_c1 = parameter::from0To1<pma2_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma3_t = pma_t<NV>;
template <int NV>
using sliderbank_c2 = parameter::from0To1<pma3_t<NV>, 
                                          1, 
                                          sliderbank_c0Range>;

template <int NV> using pma4_t = pma_t<NV>;
template <int NV>
using sliderbank_c3 = parameter::from0To1<pma4_t<NV>, 
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
using global_cable_t_index = runtime_target::indexers::fix_hash<2164996>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<pma_t<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable_t<NV>>, 
                                 pma_t<NV>, 
                                 math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<2164997>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<pma2_t<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  pma2_t<NV>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<pma3_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  pma3_t<NV>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<pma4_t<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  pma4_t<NV>, 
                                  math::add<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain4_t<NV>, 
                                 chain6_t<NV>, 
                                 chain7_t<NV>>;

DECLARE_PARAMETER_RANGE_INV(minmax_modRange, 
                            0.1, 
                            1.);

template <int NV>
using minmax_mod = parameter::from0To1_inv<math::div<NV>, 
                                           0, 
                                           minmax_modRange>;

template <int NV>
using minmax_t = control::minmax<NV, minmax_mod<NV>>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<minmax_t<NV>, 0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, sliderbank_t<NV>>, 
                                  split_t<NV>, 
                                  peak_t<NV>, 
                                  pma1_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain1_t<NV>>>;

template <int NV> using pma15_t = pma_t<NV>;
template <int NV>
using sliderbank1_c0 = parameter::from0To1<pma15_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma16_t = pma_t<NV>;
template <int NV>
using sliderbank1_c1 = parameter::from0To1<pma16_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma17_t = pma_t<NV>;
template <int NV>
using sliderbank1_c2 = parameter::from0To1<pma17_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma18_t = pma_t<NV>;
template <int NV>
using sliderbank1_c3 = parameter::from0To1<pma18_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank1_multimod = parameter::list<sliderbank1_c0<NV>, 
                                             sliderbank1_c1<NV>, 
                                             sliderbank1_c2<NV>, 
                                             sliderbank1_c3<NV>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable12_t_index = global_cable_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<pma15_t<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   pma15_t<NV>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable1_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<pma16_t<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   pma16_t<NV>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable2_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<pma17_t<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   pma17_t<NV>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable3_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<pma18_t<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   pma18_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain19_t<NV>>, 
                                  chain20_t<NV>, 
                                  chain22_t<NV>, 
                                  chain23_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader2_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader2_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader2_c0Range>;

template <int NV> using xfader2_c1 = xfader2_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::linear>;
template <int NV>
using pma19_t = control::pma<NV, 
                             parameter::plain<xfader2_t<NV>, 0>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank1_t<NV>>, 
                                   split9_t<NV>, 
                                   peak3_t<NV>, 
                                   pma19_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain18_t<NV>>>;

template <int NV> using pma20_t = pma_t<NV>;
template <int NV>
using sliderbank2_c0 = parameter::from0To1<pma20_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma21_t = pma_t<NV>;
template <int NV>
using sliderbank2_c1 = parameter::from0To1<pma21_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma22_t = pma_t<NV>;
template <int NV>
using sliderbank2_c2 = parameter::from0To1<pma22_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma23_t = pma_t<NV>;
template <int NV>
using sliderbank2_c3 = parameter::from0To1<pma23_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank2_multimod = parameter::list<sliderbank2_c0<NV>, 
                                             sliderbank2_c1<NV>, 
                                             sliderbank2_c2<NV>, 
                                             sliderbank2_c3<NV>>;

template <int NV>
using sliderbank2_t = wrap::data<control::sliderbank<sliderbank2_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable16_t_index = global_cable_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<pma20_t<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   pma20_t<NV>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable1_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<pma21_t<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   pma21_t<NV>, 
                                   math::add<NV>>;
using global_cable18_t_index = global_cable2_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<pma22_t<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   pma22_t<NV>, 
                                   math::add<NV>>;
using global_cable19_t_index = global_cable3_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<pma23_t<NV>, 0>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   pma23_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain25_t<NV>>, 
                                   chain26_t<NV>, 
                                   chain28_t<NV>, 
                                   chain29_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma24_modRange, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using pma24_mod = parameter::from0To1<core::smoother<NV>, 
                                      0, 
                                      pma24_modRange>;

template <int NV>
using pma24_t = control::pma<NV, pma24_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma24_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank2_t<NV>>, 
                                   split11_t<NV>, 
                                   peak4_t<NV>, 
                                   pma24_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain24_t<NV>>>;

template <int NV> using pma25_t = pma_t<NV>;
template <int NV>
using sliderbank3_c0 = parameter::from0To1<pma25_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma26_t = pma_t<NV>;
template <int NV>
using sliderbank3_c1 = parameter::from0To1<pma26_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma27_t = pma_t<NV>;
template <int NV>
using sliderbank3_c2 = parameter::from0To1<pma27_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma28_t = pma_t<NV>;
template <int NV>
using sliderbank3_c3 = parameter::from0To1<pma28_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank3_multimod = parameter::list<sliderbank3_c0<NV>, 
                                             sliderbank3_c1<NV>, 
                                             sliderbank3_c2<NV>, 
                                             sliderbank3_c3<NV>>;

template <int NV>
using sliderbank3_t = wrap::data<control::sliderbank<sliderbank3_multimod<NV>>, 
                                 data::external::sliderpack<3>>;
using global_cable20_t_index = global_cable_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<pma25_t<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   pma25_t<NV>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable1_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<pma26_t<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   pma26_t<NV>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable2_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<pma27_t<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   pma27_t<NV>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable3_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<pma28_t<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   pma28_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain31_t<NV>>, 
                                   chain32_t<NV>, 
                                   chain33_t<NV>, 
                                   chain34_t<NV>>;

template <int NV> using pma29_t = pma_t<NV>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma29_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank3_t<NV>>, 
                                   split13_t<NV>, 
                                   peak5_t<NV>, 
                                   pma29_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain30_t<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, split1_t<NV>>, 
                                  split8_t<NV>, 
                                  split10_t<NV>, 
                                  split12_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader2_t<NV>>, 
                                   core::gain<NV>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax_t<NV>>, 
                                   math::div<NV>, 
                                   math::add<NV>, 
                                   core::smoother<NV>, 
                                   file_player_t<NV>, 
                                   core::gain<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain21_t<NV>>, 
                                  chain46_t<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split4_t<NV>>>;

namespace FileShape_t_parameters
{
// Parameter list for FileShape_impl::FileShape_t --------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(Smooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);
template <int NV>
using Smooth_0 = parameter::from0To1<FileShape_impl::pma24_t<NV>, 
                                     2, 
                                     FileShape_impl::sliderbank_c0Range>;

template <int NV>
using Smooth = parameter::chain<Smooth_InputRange, Smooth_0<NV>>;

template <int NV>
using Hp = parameter::from0To1<FileShape_impl::pma29_t<NV>, 
                               2, 
                               FileShape_impl::sliderbank_c0Range>;

template <int NV>
using Drive1 = parameter::plain<FileShape_impl::pma1_t<NV>, 
                                2>;
template <int NV>
using FileMix = parameter::plain<FileShape_impl::pma19_t<NV>, 
                                 2>;
template <int NV>
using PostGain = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using DriveMod = parameter::plain<FileShape_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using MixMod = parameter::plain<FileShape_impl::pma19_t<NV>, 
                                1>;
template <int NV>
using SmoothMod = parameter::plain<FileShape_impl::pma24_t<NV>, 
                                   1>;
template <int NV>
using HpMod = parameter::plain<FileShape_impl::pma29_t<NV>, 
                               1>;
template <int NV>
using FileShape_t_plist = parameter::list<Drive1<NV>, 
                                          FileMix<NV>, 
                                          PostGain<NV>, 
                                          Smooth<NV>, 
                                          DriveMod<NV>, 
                                          MixMod<NV>, 
                                          SmoothMod<NV>, 
                                          HpMod<NV>, 
                                          Hp<NV>>;
}

template <int NV>
using FileShape_t_ = container::chain<FileShape_t_parameters::FileShape_t_plist<NV>, 
                                      wrap::fix<2, fix8_block_t<NV>>, 
                                      chain27_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public FileShape_impl::FileShape_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FileShape);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(146)
		{
			0x005B, 0x0000, 0x4400, 0x6972, 0x6576, 0x0031, 0x0000, 0x2480, 
            0x0000, 0x3F80, 0xB216, 0x3F24, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x4600, 0x6C69, 0x4D65, 0x7869, 0x0000, 0x8000, 
            0x0024, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0002, 0x0000, 0x6F50, 0x7473, 0x6147, 0x6E69, 0x0000, 
            0xC800, 0x00C2, 0x0000, 0x6300, 0xD666, 0x3EC0, 0xAD83, 0xCD40, 
            0xCCCC, 0x5B3D, 0x0003, 0x0000, 0x6D53, 0x6F6F, 0x6874, 0x0000, 
            0x0000, 0x0000, 0xFA00, 0x0044, 0x0000, 0x6900, 0x6CEE, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0004, 0x0000, 0x7244, 0x7669, 0x4D65, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x694D, 0x4D78, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6D53, 0x6F6F, 0x6874, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x642D, 0x3DE1, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4800, 0x4D70, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x7048, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                              // FileShape_impl::fix8_block_t<NV>
		auto& modchain = this->getT(0).getT(0);                                        // FileShape_impl::modchain_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0);                                  // FileShape_impl::split5_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(0);                          // FileShape_impl::split1_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                  // FileShape_impl::chain1_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);      // FileShape_impl::sliderbank_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);           // FileShape_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);   // FileShape_impl::chain_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).                    // FileShape_impl::global_cable_t<NV>
                             getT(0).getT(1).getT(0).getT(0);
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).                             // FileShape_impl::pma_t<NV>
                    getT(0).getT(1).getT(0).getT(1);
		auto& add = this->getT(0).getT(0).getT(0).getT(0).                             // math::add<NV>
                    getT(0).getT(1).getT(0).getT(2);
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);  // FileShape_impl::chain4_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).                   // FileShape_impl::global_cable1_t<NV>
                              getT(0).getT(1).getT(1).getT(0);
		auto& pma2 = this->getT(0).getT(0).getT(0).getT(0).                            // FileShape_impl::pma2_t<NV>
                     getT(0).getT(1).getT(1).getT(1);
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                     getT(0).getT(1).getT(1).getT(2);
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);  // FileShape_impl::chain6_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(0).                   // FileShape_impl::global_cable2_t<NV>
                              getT(0).getT(1).getT(2).getT(0);
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(0).                            // FileShape_impl::pma3_t<NV>
                     getT(0).getT(1).getT(2).getT(1);
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                     getT(0).getT(1).getT(2).getT(2);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);  // FileShape_impl::chain7_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).                   // FileShape_impl::global_cable3_t<NV>
                              getT(0).getT(1).getT(3).getT(0);
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(0).                            // FileShape_impl::pma4_t<NV>
                     getT(0).getT(1).getT(3).getT(1);
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                     getT(0).getT(1).getT(3).getT(2);
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);            // FileShape_impl::peak_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);            // FileShape_impl::pma1_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(0).getT(1);                          // FileShape_impl::split8_t<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                 // FileShape_impl::chain18_t<NV>
		auto& sliderbank1 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);     // FileShape_impl::sliderbank1_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);          // FileShape_impl::split9_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0); // FileShape_impl::chain19_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(0).getT(1).                  // FileShape_impl::global_cable12_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& pma15 = this->getT(0).getT(0).getT(0).getT(1).                           // FileShape_impl::pma15_t<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& add12 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2);
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(1); // FileShape_impl::chain20_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(0).getT(1).                  // FileShape_impl::global_cable13_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& pma16 = this->getT(0).getT(0).getT(0).getT(1).                           // FileShape_impl::pma16_t<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& add13 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2);
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(2); // FileShape_impl::chain22_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(0).getT(1).                  // FileShape_impl::global_cable14_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& pma17 = this->getT(0).getT(0).getT(0).getT(1).                           // FileShape_impl::pma17_t<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& add14 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(2);
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(3); // FileShape_impl::chain23_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(0).getT(1).                  // FileShape_impl::global_cable15_t<NV>
                               getT(0).getT(1).getT(3).getT(0);
		auto& pma18 = this->getT(0).getT(0).getT(0).getT(1).                           // FileShape_impl::pma18_t<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& add15 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(3).getT(2);
		auto& peak3 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);           // FileShape_impl::peak3_t<NV>
		auto& pma19 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3);           // FileShape_impl::pma19_t<NV>
		auto& split10 = this->getT(0).getT(0).getT(0).getT(2);                         // FileShape_impl::split10_t<NV>
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                 // FileShape_impl::chain24_t<NV>
		auto& sliderbank2 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);     // FileShape_impl::sliderbank2_t<NV>
		auto& split11 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);         // FileShape_impl::split11_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(0); // FileShape_impl::chain25_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(2).                  // FileShape_impl::global_cable16_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& pma20 = this->getT(0).getT(0).getT(0).getT(2).                           // FileShape_impl::pma20_t<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& add16 = this->getT(0).getT(0).getT(0).getT(2).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2);
		auto& chain26 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(1); // FileShape_impl::chain26_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(2).                  // FileShape_impl::global_cable17_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& pma21 = this->getT(0).getT(0).getT(0).getT(2).                           // FileShape_impl::pma21_t<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& add17 = this->getT(0).getT(0).getT(0).getT(2).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2);
		auto& chain28 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(2); // FileShape_impl::chain28_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(0).getT(2).                  // FileShape_impl::global_cable18_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& pma22 = this->getT(0).getT(0).getT(0).getT(2).                           // FileShape_impl::pma22_t<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& add18 = this->getT(0).getT(0).getT(0).getT(2).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(2);
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(3); // FileShape_impl::chain29_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(0).getT(2).                  // FileShape_impl::global_cable19_t<NV>
                               getT(0).getT(1).getT(3).getT(0);
		auto& pma23 = this->getT(0).getT(0).getT(0).getT(2).                           // FileShape_impl::pma23_t<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& add19 = this->getT(0).getT(0).getT(0).getT(2).                           // math::add<NV>
                      getT(0).getT(1).getT(3).getT(2);
		auto& peak4 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);           // FileShape_impl::peak4_t<NV>
		auto& pma24 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3);           // FileShape_impl::pma24_t<NV>
		auto& split12 = this->getT(0).getT(0).getT(0).getT(3);                         // FileShape_impl::split12_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                 // FileShape_impl::chain30_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);     // FileShape_impl::sliderbank3_t<NV>
		auto& split13 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);         // FileShape_impl::split13_t<NV>
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(0); // FileShape_impl::chain31_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(0).getT(3).                  // FileShape_impl::global_cable20_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& pma25 = this->getT(0).getT(0).getT(0).getT(3).                           // FileShape_impl::pma25_t<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& add20 = this->getT(0).getT(0).getT(0).getT(3).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2);
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(1); // FileShape_impl::chain32_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(0).getT(3).                  // FileShape_impl::global_cable21_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& pma26 = this->getT(0).getT(0).getT(0).getT(3).                           // FileShape_impl::pma26_t<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& add21 = this->getT(0).getT(0).getT(0).getT(3).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2);
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(2); // FileShape_impl::chain33_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(0).getT(3).                  // FileShape_impl::global_cable22_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& pma27 = this->getT(0).getT(0).getT(0).getT(3).                           // FileShape_impl::pma27_t<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& add22 = this->getT(0).getT(0).getT(0).getT(3).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(2);
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(3); // FileShape_impl::chain34_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(0).getT(3).                  // FileShape_impl::global_cable23_t<NV>
                               getT(0).getT(1).getT(3).getT(0);
		auto& pma28 = this->getT(0).getT(0).getT(0).getT(3).                 // FileShape_impl::pma28_t<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& add23 = this->getT(0).getT(0).getT(0).getT(3).                 // math::add<NV>
                      getT(0).getT(1).getT(3).getT(2);
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2); // FileShape_impl::peak5_t<NV>
		auto& pma29 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3); // FileShape_impl::pma29_t<NV>
		auto& chain27 = this->getT(1);                                       // FileShape_impl::chain27_t<NV>
		auto& split4 = this->getT(1).getT(0);                                // FileShape_impl::split4_t<NV>
		auto& chain21 = this->getT(1).getT(0).getT(0);                       // FileShape_impl::chain21_t<NV>
		auto& xfader2 = this->getT(1).getT(0).getT(0).getT(0);               // FileShape_impl::xfader2_t<NV>
		auto& gain8 = this->getT(1).getT(0).getT(0).getT(1);                 // core::gain<NV>
		auto& chain46 = this->getT(1).getT(0).getT(1);                       // FileShape_impl::chain46_t<NV>
		auto& minmax = this->getT(1).getT(0).getT(1).getT(0);                // FileShape_impl::minmax_t<NV>
		auto& div = this->getT(1).getT(0).getT(1).getT(1);                   // math::div<NV>
		auto& add4 = this->getT(1).getT(0).getT(1).getT(2);                  // math::add<NV>
		auto& smoother = this->getT(1).getT(0).getT(1).getT(3);              // core::smoother<NV>
		auto& file_player = this->getT(1).getT(0).getT(1).getT(4);           // FileShape_impl::file_player_t<NV>
		auto& gain = this->getT(1).getT(0).getT(1).getT(5);                  // core::gain<NV>
		auto& gain9 = this->getT(1).getT(0).getT(1).getT(6);                 // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Drive1 -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma19); // FileMix -> pma19::Add
		
		this->getParameterT(2).connectT(0, gain); // PostGain -> gain::Gain
		
		this->getParameterT(3).connectT(0, pma24); // Smooth -> pma24::Add
		
		this->getParameterT(4).connectT(0, pma1); // DriveMod -> pma1::Multiply
		
		this->getParameterT(5).connectT(0, pma19); // MixMod -> pma19::Multiply
		
		this->getParameterT(6).connectT(0, pma24); // SmoothMod -> pma24::Multiply
		
		this->getParameterT(7).connectT(0, pma29); // HpMod -> pma29::Multiply
		
		this->getParameterT(8).connectT(0, pma29); // Hp -> pma29::Add
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma.getWrappedObject().getParameter().connectT(0, add);   // pma -> add::Value
		pma2.getWrappedObject().getParameter().connectT(0, add1); // pma2 -> add1::Value
		pma3.getWrappedObject().getParameter().connectT(0, add3); // pma3 -> add3::Value
		pma4.getWrappedObject().getParameter().connectT(0, add2); // pma4 -> add2::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, pma);                    // sliderbank -> pma::Multiply
		sliderbank_p.getParameterT(1).connectT(0, pma2);                   // sliderbank -> pma2::Multiply
		sliderbank_p.getParameterT(2).connectT(0, pma3);                   // sliderbank -> pma3::Multiply
		sliderbank_p.getParameterT(3).connectT(0, pma4);                   // sliderbank -> pma4::Multiply
		global_cable.getWrappedObject().getParameter().connectT(0, pma);   // global_cable -> pma::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, pma2); // global_cable1 -> pma2::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, pma3); // global_cable2 -> pma3::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, pma4); // global_cable3 -> pma4::Value
		minmax.getWrappedObject().getParameter().connectT(0, div);         // minmax -> div::Value
		pma1.getWrappedObject().getParameter().connectT(0, minmax);        // pma1 -> minmax::Value
		peak.getParameter().connectT(0, pma1);                             // peak -> pma1::Value
		pma15.getWrappedObject().getParameter().connectT(0, add12);        // pma15 -> add12::Value
		pma16.getWrappedObject().getParameter().connectT(0, add13);        // pma16 -> add13::Value
		pma17.getWrappedObject().getParameter().connectT(0, add14);        // pma17 -> add14::Value
		pma18.getWrappedObject().getParameter().connectT(0, add15);        // pma18 -> add15::Value
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, pma15);                   // sliderbank1 -> pma15::Multiply
		sliderbank1_p.getParameterT(1).connectT(0, pma16);                   // sliderbank1 -> pma16::Multiply
		sliderbank1_p.getParameterT(2).connectT(0, pma17);                   // sliderbank1 -> pma17::Multiply
		sliderbank1_p.getParameterT(3).connectT(0, pma18);                   // sliderbank1 -> pma18::Multiply
		global_cable12.getWrappedObject().getParameter().connectT(0, pma15); // global_cable12 -> pma15::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, pma16); // global_cable13 -> pma16::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, pma17); // global_cable14 -> pma17::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, pma18); // global_cable15 -> pma18::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain8);                // xfader2 -> gain8::Gain
		xfader2_p.getParameterT(1).connectT(0, gain9);                // xfader2 -> gain9::Gain
		pma19.getWrappedObject().getParameter().connectT(0, xfader2); // pma19 -> xfader2::Value
		peak3.getParameter().connectT(0, pma19);                      // peak3 -> pma19::Value
		pma20.getWrappedObject().getParameter().connectT(0, add16);   // pma20 -> add16::Value
		pma21.getWrappedObject().getParameter().connectT(0, add17);   // pma21 -> add17::Value
		pma22.getWrappedObject().getParameter().connectT(0, add18);   // pma22 -> add18::Value
		pma23.getWrappedObject().getParameter().connectT(0, add19);   // pma23 -> add19::Value
		auto& sliderbank2_p = sliderbank2.getWrappedObject().getParameter();
		sliderbank2_p.getParameterT(0).connectT(0, pma20);                   // sliderbank2 -> pma20::Multiply
		sliderbank2_p.getParameterT(1).connectT(0, pma21);                   // sliderbank2 -> pma21::Multiply
		sliderbank2_p.getParameterT(2).connectT(0, pma22);                   // sliderbank2 -> pma22::Multiply
		sliderbank2_p.getParameterT(3).connectT(0, pma23);                   // sliderbank2 -> pma23::Multiply
		global_cable16.getWrappedObject().getParameter().connectT(0, pma20); // global_cable16 -> pma20::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, pma21); // global_cable17 -> pma21::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, pma22); // global_cable18 -> pma22::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, pma23); // global_cable19 -> pma23::Value
		pma24.getWrappedObject().getParameter().connectT(0, smoother);       // pma24 -> smoother::SmoothingTime
		peak4.getParameter().connectT(0, pma24);                             // peak4 -> pma24::Value
		pma25.getWrappedObject().getParameter().connectT(0, add20);          // pma25 -> add20::Value
		pma26.getWrappedObject().getParameter().connectT(0, add21);          // pma26 -> add21::Value
		pma27.getWrappedObject().getParameter().connectT(0, add22);          // pma27 -> add22::Value
		pma28.getWrappedObject().getParameter().connectT(0, add23);          // pma28 -> add23::Value
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, pma25);                   // sliderbank3 -> pma25::Multiply
		sliderbank3_p.getParameterT(1).connectT(0, pma26);                   // sliderbank3 -> pma26::Multiply
		sliderbank3_p.getParameterT(2).connectT(0, pma27);                   // sliderbank3 -> pma27::Multiply
		sliderbank3_p.getParameterT(3).connectT(0, pma28);                   // sliderbank3 -> pma28::Multiply
		global_cable20.getWrappedObject().getParameter().connectT(0, pma25); // global_cable20 -> pma25::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, pma26); // global_cable21 -> pma26::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, pma27); // global_cable22 -> pma27::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, pma28); // global_cable23 -> pma28::Value
		pma29.getWrappedObject().getParameter().connectT(0, add4);           // pma29 -> add4::Value
		peak5.getParameter().connectT(0, pma29);                             // peak5 -> pma29::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                         // pma::Value is automated
		;                         // pma::Multiply is automated
		pma.setParameterT(2, 0.); // control::pma::Add
		
		; // add::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma2::Value is automated
		;                          // pma2::Multiply is automated
		pma2.setParameterT(2, 0.); // control::pma::Add
		
		; // add1::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma3::Value is automated
		;                          // pma3::Multiply is automated
		pma3.setParameterT(2, 0.); // control::pma::Add
		
		; // add3::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                          // pma4::Value is automated
		;                          // pma4::Multiply is automated
		pma4.setParameterT(2, 0.); // control::pma::Add
		
		; // add2::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		sliderbank1.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma15::Value is automated
		;                           // pma15::Multiply is automated
		pma15.setParameterT(2, 0.); // control::pma::Add
		
		; // add12::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma16::Value is automated
		;                           // pma16::Multiply is automated
		pma16.setParameterT(2, 0.); // control::pma::Add
		
		; // add13::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma17::Value is automated
		;                           // pma17::Multiply is automated
		pma17.setParameterT(2, 0.); // control::pma::Add
		
		; // add14::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma18::Value is automated
		;                           // pma18::Multiply is automated
		pma18.setParameterT(2, 0.); // control::pma::Add
		
		; // add15::Value is automated
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		sliderbank2.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma20::Value is automated
		;                           // pma20::Multiply is automated
		pma20.setParameterT(2, 0.); // control::pma::Add
		
		; // add16::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma21::Value is automated
		;                           // pma21::Multiply is automated
		pma21.setParameterT(2, 0.); // control::pma::Add
		
		; // add17::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma22::Value is automated
		;                           // pma22::Multiply is automated
		pma22.setParameterT(2, 0.); // control::pma::Add
		
		; // add18::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma23::Value is automated
		;                           // pma23::Multiply is automated
		pma23.setParameterT(2, 0.); // control::pma::Add
		
		; // add19::Value is automated
		
		; // pma24::Value is automated
		; // pma24::Multiply is automated
		; // pma24::Add is automated
		
		sliderbank3.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma25::Value is automated
		;                           // pma25::Multiply is automated
		pma25.setParameterT(2, 0.); // control::pma::Add
		
		; // add20::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma26::Value is automated
		;                           // pma26::Multiply is automated
		pma26.setParameterT(2, 0.); // control::pma::Add
		
		; // add21::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma27::Value is automated
		;                           // pma27::Multiply is automated
		pma27.setParameterT(2, 0.); // control::pma::Add
		
		; // add22::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma28::Value is automated
		;                           // pma28::Multiply is automated
		pma28.setParameterT(2, 0.); // control::pma::Add
		
		; // add23::Value is automated
		
		; // pma29::Value is automated
		; // pma29::Multiply is automated
		; // pma29::Add is automated
		
		; // xfader2::Value is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.1);      // control::minmax::Minimum
		minmax.setParameterT(2, 0.990236); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);       // control::minmax::Skew
		minmax.setParameterT(4, 0.);       // control::minmax::Step
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // div::Value is automated
		
		; // add4::Value is automated
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		file_player.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player.setParameterT(3, 1.);   // core::file_player::FreqRatio
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // gain9::Gain is automated
		gain9.setParameterT(1, 0.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.643342);
		this->setParameterT(1, 1.);
		this->setParameterT(2, -6.7);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.110054);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).  // FileShape_impl::global_cable_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // FileShape_impl::global_cable1_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // FileShape_impl::global_cable2_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // FileShape_impl::global_cable3_t<NV>
        getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // FileShape_impl::global_cable12_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // FileShape_impl::global_cable13_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // FileShape_impl::global_cable14_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // FileShape_impl::global_cable15_t<NV>
        getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(2).  // FileShape_impl::global_cable16_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(2).  // FileShape_impl::global_cable17_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(2).  // FileShape_impl::global_cable18_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(2).  // FileShape_impl::global_cable19_t<NV>
        getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).  // FileShape_impl::global_cable20_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).  // FileShape_impl::global_cable21_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).  // FileShape_impl::global_cable22_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).  // FileShape_impl::global_cable23_t<NV>
        getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // FileShape_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // FileShape_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // FileShape_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index); // FileShape_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index); // FileShape_impl::sliderbank2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).setExternalData(b, index); // FileShape_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index); // FileShape_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).setExternalData(b, index); // FileShape_impl::peak5_t<NV>
		this->getT(1).getT(0).getT(1).getT(4).setExternalData(b, index);                 // FileShape_impl::file_player_t<NV>
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
using FileShape = wrap::node<FileShape_impl::instance<NV>>;
}


