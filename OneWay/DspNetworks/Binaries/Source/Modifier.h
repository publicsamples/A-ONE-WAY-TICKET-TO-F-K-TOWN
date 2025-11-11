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

namespace Modifier_impl
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
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain12_t<NV>, 
                                 chain14_t<NV>, 
                                 chain15_t<NV>>;

template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                control::tempo_sync<NV>>;
namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);
		;
	}
};
}

namespace custom
{

struct expr4
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 8.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

DECLARE_PARAMETER_RANGE_SKEW(pma_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma_mod = parameter::from0To1<core::gain<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
DECLARE_PARAMETER_RANGE_INV(pma4_mod_0Range, 
                            5.55112e-17, 
                            1.);

template <int NV>
using pma4_mod_0 = parameter::from0To1_inv<pma_t<NV>, 
                                           2, 
                                           pma4_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma4_mod_1Range, 
                        -1., 
                        1.);

template <int NV>
using pma4_mod_1 = parameter::from0To1<pma_t<NV>, 
                                       1, 
                                       pma4_mod_1Range>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  pma4_mod_1<NV>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
namespace custom
{

struct expr10
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr12
{
	static float op(float input, float value)
	{
		return (1 - value) * input + value * Math.sqr(Math.PI * 1.0 * value * input);
		;
	}
};
}

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 8.0 * value * input) * (2 - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.abs(Math.PI * 2.0 * value * input);
		;
	}
};
}

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<math::clip<NV>, 0>>;
DECLARE_PARAMETER_RANGE_STEP(pma9_mod_0Range, 
                             1., 
                             256., 
                             1.);

template <int NV>
using pma9_mod_0 = parameter::from0To1<fx::sampleandhold<NV>, 
                                       0, 
                                       pma9_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma9_mod_1Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma9_mod_1 = parameter::from0To1<tempo_sync2_t<NV>, 
                                       0, 
                                       pma9_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma9_mod_2Range, 
                             2., 
                             16., 
                             0.1);

template <int NV>
using pma9_mod_2 = parameter::from0To1<fx::bitcrush<NV>, 
                                       0, 
                                       pma9_mod_2Range>;

template <int NV> using pma9_mod_3 = pma9_mod_2<NV>;

DECLARE_PARAMETER_RANGE(pma9_mod_5Range, 
                        0.1, 
                        1.);

template <int NV>
using pma9_mod_5 = parameter::from0To1<math::expr<NV, custom::expr4>, 
                                       0, 
                                       pma9_mod_5Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma9_mod_7Range, 
                             0.08, 
                             1., 
                             0.408479);

template <int NV>
using pma9_mod_7 = parameter::from0To1<math::expr<NV, custom::expr10>, 
                                       0, 
                                       pma9_mod_7Range>;

DECLARE_PARAMETER_RANGE(pma9_mod_8Range, 
                        0.23, 
                        1.);

template <int NV>
using pma9_mod_8 = parameter::from0To1<math::expr<NV, custom::expr12>, 
                                       0, 
                                       pma9_mod_8Range>;

DECLARE_PARAMETER_RANGE(pma9_mod_9Range, 
                        0.08, 
                        1.);

template <int NV>
using pma9_mod_9 = parameter::from0To1<math::expr<NV, custom::expr9>, 
                                       0, 
                                       pma9_mod_9Range>;

template <int NV>
using pma9_mod = parameter::chain<ranges::Identity, 
                                  pma9_mod_0<NV>, 
                                  pma9_mod_1<NV>, 
                                  pma9_mod_2<NV>, 
                                  pma9_mod_3<NV>, 
                                  parameter::plain<math::expr<NV, custom::expr>, 0>, 
                                  pma9_mod_5<NV>, 
                                  parameter::plain<pma4_t<NV>, 0>, 
                                  pma9_mod_7<NV>, 
                                  pma9_mod_8<NV>, 
                                  pma9_mod_9<NV>, 
                                  parameter::plain<math::expr<NV, custom::expr3>, 0>, 
                                  parameter::plain<math::tanh<NV>, 0>, 
                                  parameter::plain<minmax_t<NV>, 0>>;

template <int NV>
using pma9_t = control::pma<NV, pma9_mod<NV>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank_t<NV>>, 
                                   split_t<NV>, 
                                   peak_t<NV>, 
                                   pma9_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain10_t<NV>>>;

template <int NV> using pma15_t = pma5_t<NV>;
template <int NV>
using sliderbank1_c0 = parameter::from0To1<pma15_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma16_t = pma5_t<NV>;
template <int NV>
using sliderbank1_c1 = parameter::from0To1<pma16_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank1_c2 = parameter::from0To1<control::pma<NV, parameter::empty>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma18_t = pma5_t<NV>;
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
using global_cable12_t_index = global_cable3_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<pma15_t<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   pma15_t<NV>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable4_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<pma16_t<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   pma16_t<NV>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable5_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<control::pma<NV, parameter::empty>, 0>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   control::pma<NV, parameter::empty>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable6_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<pma18_t<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   pma18_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain20_t<NV>>, 
                                  chain26_t<NV>, 
                                  chain29_t<NV>, 
                                  chain31_t<NV>>;

template <int NV> using xfader7_c0 = pma_mod<NV>;

template <int NV> using xfader7_c1 = pma_mod<NV>;

template <int NV>
using xfader7_multimod = parameter::list<xfader7_c0<NV>, xfader7_c1<NV>>;

template <int NV>
using xfader7_t = control::xfader<xfader7_multimod<NV>, faders::linear>;
template <int NV>
using pma19_t = control::pma<NV, 
                             parameter::plain<xfader7_t<NV>, 0>>;
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

using global_cable16_t_index = global_cable3_t_index;

template <int NV> using pma20_t = pma5_t<NV>;
template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<pma20_t<NV>, 0>>;
template <int NV>
using sliderbank2_c0_1 = parameter::from0To1<pma20_t<NV>, 
                                             1, 
                                             sliderbank_c0Range>;

template <int NV>
using sliderbank2_c0 = parameter::chain<ranges::Identity, 
                                        parameter::plain<global_cable16_t<NV>, 0>, 
                                        sliderbank2_c0_1<NV>>;

template <int NV> using pma21_t = pma5_t<NV>;
template <int NV>
using sliderbank2_c1 = parameter::from0To1<pma21_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma22_t = pma5_t<NV>;
template <int NV>
using sliderbank2_c2 = parameter::from0To1<pma22_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma23_t = pma5_t<NV>;
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

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   pma20_t<NV>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable4_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<pma21_t<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   pma21_t<NV>, 
                                   math::add<NV>>;
using global_cable18_t_index = global_cable5_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<pma22_t<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   pma22_t<NV>, 
                                   math::add<NV>>;
using global_cable19_t_index = global_cable6_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<pma23_t<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   pma23_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain32_t<NV>>, 
                                   chain33_t<NV>, 
                                   chain34_t<NV>, 
                                   chain35_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma24_modRange, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma24_mod = parameter::from0To1<project::pitch<NV>, 
                                      0, 
                                      pma24_modRange>;

template <int NV>
using pma24_t = control::pma<NV, pma24_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma24_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank2_t<NV>>, 
                                   split11_t<NV>, 
                                   peak4_t<NV>, 
                                   pma24_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain36_t<NV>>>;

template <int NV> using pma25_t = pma5_t<NV>;
template <int NV>
using sliderbank3_c0 = parameter::from0To1<pma25_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma26_t = pma5_t<NV>;
template <int NV>
using sliderbank3_c1 = parameter::from0To1<pma26_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma27_t = pma5_t<NV>;
template <int NV>
using sliderbank3_c2 = parameter::from0To1<pma27_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma28_t = pma5_t<NV>;
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
using global_cable20_t_index = global_cable3_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<pma25_t<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   pma25_t<NV>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable4_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<pma26_t<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   pma26_t<NV>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable5_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<pma27_t<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   pma27_t<NV>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable6_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<pma28_t<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   pma28_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain37_t<NV>>, 
                                   chain38_t<NV>, 
                                   chain39_t<NV>, 
                                   chain40_t<NV>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<project::pitch<NV>, 1>, 
                               control::tempo_sync<NV>>;
template <int NV>
using pma29_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                      0, 
                                      pma9_mod_1Range>;

template <int NV>
using pma29_t = control::pma<NV, pma29_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma29_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank3_t<NV>>, 
                                   split13_t<NV>, 
                                   peak5_t<NV>, 
                                   pma29_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain41_t<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, split1_t<NV>>, 
                                  split8_t<NV>, 
                                  split10_t<NV>, 
                                  split12_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader7_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fx::sampleandhold<NV>>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, tempo_sync2_t<NV>>, 
                                  fx::sampleandhold<NV>>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, chain1_t<NV>>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, frame2_block1_t<NV>>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fx::bitcrush<NV>>>;

template <int NV> using chain19_t = chain9_t<NV>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::expr<NV, custom::expr>>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr4>>, 
                                   core::gain<NV>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, peak1_t<NV>>, 
                                         pma4_t<NV>, 
                                         pma_t<NV>, 
                                         core::gain<NV>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, frame2_block_t<NV>>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr10>>, 
                                   core::gain<NV>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr12>>, 
                                   core::gain<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr9>>, 
                                   core::gain<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::tanh<NV>>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax_t<NV>>, 
                                   math::clip<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr3>>, 
                                   core::gain<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain4_t<NV>>, 
                                    chain22_t<NV>, 
                                    chain9_t<NV>, 
                                    chain19_t<NV>, 
                                    chain7_t<NV>, 
                                    chain21_t<NV>, 
                                    chain24_t<NV>, 
                                    chain28_t<NV>, 
                                    chain30_t<NV>, 
                                    chain27_t<NV>, 
                                    chain23_t<NV>, 
                                    chain42_t<NV>, 
                                    chain13_t<NV>>;

using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::empty>>;

using sb1_t = bypass::smoothed<20, sb1_t_>;
using switcher_c0 = parameter::bypass<sb1_t>;

template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<project::pitch<NV>, 2>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, tempo_sync_t<NV>>, 
                                  tempo_sync1_t<NV>, 
                                  project::pitch<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain3_t<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0, switcher_c1<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t>, 
                                        sb2_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, switcher_t<NV>>, 
                                  sb_container_t<NV>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   core::gain<NV>, 
                                   chain2_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain25_t<NV>>, 
                                  chain67_t<NV>>;

namespace Modifier_t_parameters
{
// Parameter list for Modifier_impl::Modifier_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(mode_InputRange, 
                             1., 
                             13., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(mode_0Range, 
                             0., 
                             12., 
                             1.);

template <int NV>
using mode_0 = parameter::from0To1<Modifier_impl::branch1_t<NV>, 
                                   0, 
                                   mode_0Range>;

template <int NV>
using mode = parameter::chain<mode_InputRange, mode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PITCH_InputRange, 
                             -12., 
                             12., 
                             0.1);
template <int NV>
using PITCH_0 = parameter::from0To1<Modifier_impl::pma24_t<NV>, 
                                    2, 
                                    Modifier_impl::sliderbank_c0Range>;

template <int NV>
using PITCH = parameter::chain<PITCH_InputRange, PITCH_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(WIN_InputRange, 
                             0., 
                             18., 
                             1.);
template <int NV>
using WIN_0 = parameter::from0To1<Modifier_impl::pma29_t<NV>, 
                                  2, 
                                  Modifier_impl::sliderbank_c0Range>;

template <int NV>
using WIN = parameter::chain<WIN_InputRange, WIN_0<NV>>;

template <int NV>
using DIV = parameter::chain<ranges::Identity, 
                             parameter::plain<Modifier_impl::tempo_sync_t<NV>, 1>, 
                             parameter::plain<Modifier_impl::tempo_sync1_t<NV>, 1>>;

template <int NV>
using mix = parameter::plain<Modifier_impl::pma19_t<NV>, 
                             2>;
template <int NV>
using FX = parameter::plain<Modifier_impl::pma9_t<NV>, 
                            2>;
template <int NV>
using MixMod = parameter::plain<Modifier_impl::pma19_t<NV>, 
                                1>;
template <int NV>
using DriveMod = parameter::plain<Modifier_impl::pma9_t<NV>, 
                                  1>;
template <int NV>
using PostFxGain = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using PITCHSHIFT = parameter::plain<Modifier_impl::switcher_t<NV>, 
                                    0>;
template <int NV>
using XF = parameter::plain<Modifier_impl::tempo_sync1_t<NV>, 
                            0>;
template <int NV>
using PitchMod = parameter::plain<Modifier_impl::pma24_t<NV>, 
                                  1>;
template <int NV>
using WinMod = parameter::plain<Modifier_impl::pma29_t<NV>, 
                                1>;
template <int NV>
using Modifier_t_plist = parameter::list<mix<NV>, 
                                         mode<NV>, 
                                         FX<NV>, 
                                         MixMod<NV>, 
                                         DriveMod<NV>, 
                                         PostFxGain<NV>, 
                                         PITCHSHIFT<NV>, 
                                         PITCH<NV>, 
                                         WIN<NV>, 
                                         XF<NV>, 
                                         DIV<NV>, 
                                         PitchMod<NV>, 
                                         WinMod<NV>>;
}

template <int NV>
using Modifier_t_ = container::chain<Modifier_t_parameters::Modifier_t_plist<NV>, 
                                     wrap::fix<2, modchain1_t<NV>>, 
                                     split6_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Modifier_impl::Modifier_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Modifier);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(206)
		{
			0x005B, 0x0000, 0x6D00, 0x7869, 0x0000, 0x8000, 0x0024, 0x8000, 
            0x003F, 0x8000, 0x0024, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6F6D, 0x6564, 0x0000, 0x8000, 0x003F, 0x5000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0002, 0x0000, 
            0x5846, 0x0000, 0x8000, 0x0024, 0x8000, 0xC83F, 0x7E42, 0x003D, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x694D, 0x4D78, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x593F, 0x02C8, 0x003C, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x7244, 0x7669, 
            0x4D65, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6F50, 
            0x7473, 0x7846, 0x6147, 0x6E69, 0x0000, 0xC800, 0x00C2, 0x0000, 
            0x3200, 0x7B33, 0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0006, 
            0x0000, 0x4950, 0x4354, 0x5348, 0x4948, 0x5446, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0007, 0x0000, 0x4950, 0x4354, 0x0048, 0x0000, 0xC140, 
            0x0000, 0x4140, 0x0000, 0x4140, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 
            0x085B, 0x0000, 0x5700, 0x4E49, 0x0000, 0x0000, 0x0000, 0x9000, 
            0x0041, 0x5000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0009, 
            0x0000, 0x4658, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000A, 0x0000, 0x4944, 
            0x0056, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4170, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0B5B, 0x0000, 0x5000, 0x7469, 0x6863, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 0x5700, 0x6E69, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                                      // Modifier_impl::modchain1_t<NV>
		auto& split5 = this->getT(0).getT(0);                                                 // Modifier_impl::split5_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0);                                         // Modifier_impl::split1_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0);                                // Modifier_impl::chain10_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                     // Modifier_impl::sliderbank_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(0).getT(1);                          // Modifier_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                  // Modifier_impl::chain_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);  // Modifier_impl::global_cable3_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);           // Modifier_impl::pma5_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);            // math::add<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                // Modifier_impl::chain12_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);  // Modifier_impl::global_cable4_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);           // Modifier_impl::pma6_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                // Modifier_impl::chain14_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);  // Modifier_impl::global_cable5_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);           // Modifier_impl::pma7_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                // Modifier_impl::chain15_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);  // Modifier_impl::global_cable6_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);           // Modifier_impl::pma8_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(2);                           // Modifier_impl::peak_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                           // Modifier_impl::pma9_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(1);                                         // Modifier_impl::split8_t<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(0);                                // Modifier_impl::chain18_t<NV>
		auto& sliderbank1 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                    // Modifier_impl::sliderbank1_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                         // Modifier_impl::split9_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                // Modifier_impl::chain20_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0); // Modifier_impl::global_cable12_t<NV>
		auto& pma15 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);          // Modifier_impl::pma15_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);          // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);                // Modifier_impl::chain26_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0); // Modifier_impl::global_cable13_t<NV>
		auto& pma16 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);          // Modifier_impl::pma16_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(2);          // math::add<NV>
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2);                // Modifier_impl::chain29_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0); // Modifier_impl::global_cable14_t<NV>
		auto& pma17 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);          // control::pma<NV, parameter::empty>
		auto& add14 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain31 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3);                // Modifier_impl::chain31_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0); // Modifier_impl::global_cable15_t<NV>
		auto& pma18 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(1);          // Modifier_impl::pma18_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak3 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                          // Modifier_impl::peak3_t<NV>
		auto& pma19 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                          // Modifier_impl::pma19_t<NV>
		auto& split10 = this->getT(0).getT(0).getT(2);                                        // Modifier_impl::split10_t<NV>
		auto& chain36 = this->getT(0).getT(0).getT(2).getT(0);                                // Modifier_impl::chain36_t<NV>
		auto& sliderbank2 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                    // Modifier_impl::sliderbank2_t<NV>
		auto& split11 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                        // Modifier_impl::split11_t<NV>
		auto& chain32 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);                // Modifier_impl::chain32_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0); // Modifier_impl::global_cable16_t<NV>
		auto& pma20 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(1);          // Modifier_impl::pma20_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(2);          // math::add<NV>
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);                // Modifier_impl::chain33_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0); // Modifier_impl::global_cable17_t<NV>
		auto& pma21 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(1);          // Modifier_impl::pma21_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(2);          // math::add<NV>
		auto& chain34 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2);                // Modifier_impl::chain34_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0); // Modifier_impl::global_cable18_t<NV>
		auto& pma22 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(1);          // Modifier_impl::pma22_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain35 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3);                // Modifier_impl::chain35_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0); // Modifier_impl::global_cable19_t<NV>
		auto& pma23 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(1);          // Modifier_impl::pma23_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak4 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                          // Modifier_impl::peak4_t<NV>
		auto& pma24 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                          // Modifier_impl::pma24_t<NV>
		auto& split12 = this->getT(0).getT(0).getT(3);                                        // Modifier_impl::split12_t<NV>
		auto& chain41 = this->getT(0).getT(0).getT(3).getT(0);                                // Modifier_impl::chain41_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                    // Modifier_impl::sliderbank3_t<NV>
		auto& split13 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                        // Modifier_impl::split13_t<NV>
		auto& chain37 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);                // Modifier_impl::chain37_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(0); // Modifier_impl::global_cable20_t<NV>
		auto& pma25 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(1);          // Modifier_impl::pma25_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(2);          // math::add<NV>
		auto& chain38 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);                // Modifier_impl::chain38_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(0); // Modifier_impl::global_cable21_t<NV>
		auto& pma26 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(1);          // Modifier_impl::pma26_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(2);          // math::add<NV>
		auto& chain39 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2);                // Modifier_impl::chain39_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0); // Modifier_impl::global_cable22_t<NV>
		auto& pma27 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(1);          // Modifier_impl::pma27_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain40 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3);                // Modifier_impl::chain40_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(0); // Modifier_impl::global_cable23_t<NV>
		auto& pma28 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(1);          // Modifier_impl::pma28_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(3).getT(0).getT(2);                          // Modifier_impl::peak5_t<NV>
		auto& pma29 = this->getT(0).getT(0).getT(3).getT(0).getT(3);                          // Modifier_impl::pma29_t<NV>
		auto& split6 = this->getT(1);                                                         // Modifier_impl::split6_t<NV>
		auto& chain25 = this->getT(1).getT(0);                                                // Modifier_impl::chain25_t<NV>
		auto& xfader7 = this->getT(1).getT(0).getT(0);                                        // Modifier_impl::xfader7_t<NV>
		auto& gain18 = this->getT(1).getT(0).getT(1);                                         // core::gain<NV>
		auto& chain67 = this->getT(1).getT(1);                                                // Modifier_impl::chain67_t<NV>
		auto& branch1 = this->getT(1).getT(1).getT(0);                                        // Modifier_impl::branch1_t<NV>
		auto& chain4 = this->getT(1).getT(1).getT(0).getT(0);                                 // Modifier_impl::chain4_t<NV>
		auto& sampleandhold = this->getT(1).getT(1).getT(0).getT(0).getT(0);                  // fx::sampleandhold<NV>
		auto& chain22 = this->getT(1).getT(1).getT(0).getT(1);                                // Modifier_impl::chain22_t<NV>
		auto& frame2_block1 = this->getT(1).getT(1).getT(0).getT(1).getT(0);                  // Modifier_impl::frame2_block1_t<NV>
		auto& chain1 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);                 // Modifier_impl::chain1_t<NV>
		auto& tempo_sync2 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0).getT(0);    // Modifier_impl::tempo_sync2_t<NV>
		auto& sampleandhold1 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0).getT(1); // fx::sampleandhold<NV>
		auto& chain9 = this->getT(1).getT(1).getT(0).getT(2);                                 // Modifier_impl::chain9_t<NV>
		auto& bitcrush = this->getT(1).getT(1).getT(0).getT(2).getT(0);                       // fx::bitcrush<NV>
		auto& chain19 = this->getT(1).getT(1).getT(0).getT(3);                                // Modifier_impl::chain19_t<NV>
		auto& bitcrush1 = this->getT(1).getT(1).getT(0).getT(3).getT(0);                      // fx::bitcrush<NV>
		auto& chain7 = this->getT(1).getT(1).getT(0).getT(4);                                 // Modifier_impl::chain7_t<NV>
		auto& expr = this->getT(1).getT(1).getT(0).getT(4).getT(0);                           // math::expr<NV, custom::expr>
		auto& chain21 = this->getT(1).getT(1).getT(0).getT(5);                                // Modifier_impl::chain21_t<NV>
		auto& expr4 = this->getT(1).getT(1).getT(0).getT(5).getT(0);                          // math::expr<NV, custom::expr4>
		auto& gain2 = this->getT(1).getT(1).getT(0).getT(5).getT(1);                          // core::gain<NV>
		auto& chain24 = this->getT(1).getT(1).getT(0).getT(6);                                // Modifier_impl::chain24_t<NV>
		auto& frame2_block = this->getT(1).getT(1).getT(0).getT(6).getT(0);                   // Modifier_impl::frame2_block_t<NV>
		auto& peak1 = this->getT(1).getT(1).getT(0).getT(6).getT(0).getT(0);                  // Modifier_impl::peak1_t<NV>
		auto& pma4 = this->getT(1).getT(1).getT(0).getT(6).getT(0).getT(1);                   // Modifier_impl::pma4_t<NV>
		auto& pma = this->getT(1).getT(1).getT(0).getT(6).getT(0).getT(2);                    // Modifier_impl::pma_t<NV>
		auto& gain1 = this->getT(1).getT(1).getT(0).getT(6).getT(0).getT(3);                  // core::gain<NV>
		auto& chain28 = this->getT(1).getT(1).getT(0).getT(7);                                // Modifier_impl::chain28_t<NV>
		auto& expr10 = this->getT(1).getT(1).getT(0).getT(7).getT(0);                         // math::expr<NV, custom::expr10>
		auto& gain6 = this->getT(1).getT(1).getT(0).getT(7).getT(1);                          // core::gain<NV>
		auto& chain30 = this->getT(1).getT(1).getT(0).getT(8);                                // Modifier_impl::chain30_t<NV>
		auto& expr12 = this->getT(1).getT(1).getT(0).getT(8).getT(0);                         // math::expr<NV, custom::expr12>
		auto& gain3 = this->getT(1).getT(1).getT(0).getT(8).getT(1);                          // core::gain<NV>
		auto& chain27 = this->getT(1).getT(1).getT(0).getT(9);                                // Modifier_impl::chain27_t<NV>
		auto& expr9 = this->getT(1).getT(1).getT(0).getT(9).getT(0);                          // math::expr<NV, custom::expr9>
		auto& gain4 = this->getT(1).getT(1).getT(0).getT(9).getT(1);                          // core::gain<NV>
		auto& chain23 = this->getT(1).getT(1).getT(0).getT(10);                               // Modifier_impl::chain23_t<NV>
		auto& tanh = this->getT(1).getT(1).getT(0).getT(10).getT(0);                          // math::tanh<NV>
		auto& chain42 = this->getT(1).getT(1).getT(0).getT(11);                               // Modifier_impl::chain42_t<NV>
		auto& minmax = this->getT(1).getT(1).getT(0).getT(11).getT(0);                        // Modifier_impl::minmax_t<NV>
		auto& clip = this->getT(1).getT(1).getT(0).getT(11).getT(1);                          // math::clip<NV>
		auto& chain13 = this->getT(1).getT(1).getT(0).getT(12);                               // Modifier_impl::chain13_t<NV>
		auto& expr3 = this->getT(1).getT(1).getT(0).getT(12).getT(0);                         // math::expr<NV, custom::expr3>
		auto& gain5 = this->getT(1).getT(1).getT(0).getT(12).getT(1);                         // core::gain<NV>
		auto& gain = this->getT(1).getT(1).getT(1);                                           // core::gain<NV>
		auto& chain2 = this->getT(1).getT(1).getT(2);                                         // Modifier_impl::chain2_t<NV>
		auto& switcher = this->getT(1).getT(1).getT(2).getT(0);                               // Modifier_impl::switcher_t<NV>
		auto& sb_container = this->getT(1).getT(1).getT(2).getT(1);                           // Modifier_impl::sb_container_t<NV>
		auto& sb1 = this->getT(1).getT(1).getT(2).getT(1).getT(0);                            // Modifier_impl::sb1_t
		auto& sb2 = this->getT(1).getT(1).getT(2).getT(1).getT(1);                            // Modifier_impl::sb2_t<NV>
		auto& chain3 = this->getT(1).getT(1).getT(2).getT(1).getT(1).getT(0);                 // Modifier_impl::chain3_t<NV>
		auto& tempo_sync = this->getT(1).getT(1).getT(2).getT(1).getT(1).getT(0).getT(0);     // Modifier_impl::tempo_sync_t<NV>
		auto& tempo_sync1 = this->getT(1).getT(1).getT(2).getT(1).getT(1).getT(0).getT(1);    // Modifier_impl::tempo_sync1_t<NV>
		auto& faust = this->getT(1).getT(1).getT(2).getT(1).getT(1).getT(0).getT(2);          // project::pitch<NV>
		auto& gain19 = this->getT(1).getT(1).getT(3);                                         // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma19); // mix -> pma19::Add
		
		this->getParameterT(1).connectT(0, branch1); // mode -> branch1::Index
		
		this->getParameterT(2).connectT(0, pma9); // FX -> pma9::Add
		
		this->getParameterT(3).connectT(0, pma19); // MixMod -> pma19::Multiply
		
		this->getParameterT(4).connectT(0, pma9); // DriveMod -> pma9::Multiply
		
		this->getParameterT(5).connectT(0, gain); // PostFxGain -> gain::Gain
		
		this->getParameterT(6).connectT(0, switcher); // PITCHSHIFT -> switcher::Value
		
		this->getParameterT(7).connectT(0, pma24); // PITCH -> pma24::Add
		
		this->getParameterT(8).connectT(0, pma29); // WIN -> pma29::Add
		
		this->getParameterT(9).connectT(0, tempo_sync1); // XF -> tempo_sync1::Tempo
		
		auto& DIV_p = this->getParameterT(10);
		DIV_p.connectT(0, tempo_sync);  // DIV -> tempo_sync::Multiplier
		DIV_p.connectT(1, tempo_sync1); // DIV -> tempo_sync1::Multiplier
		
		this->getParameterT(11).connectT(0, pma24); // PitchMod -> pma24::Multiply
		
		this->getParameterT(12).connectT(0, pma29); // WinMod -> pma29::Multiply
		
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
		tempo_sync2.getParameter().connectT(0, sampleandhold1);            // tempo_sync2 -> sampleandhold1::Counter
		pma.getWrappedObject().getParameter().connectT(0, gain1);          // pma -> gain1::Gain
		pma4.getWrappedObject().getParameter().connectT(0, pma);           // pma4 -> pma::Add
		pma4.getWrappedObject().getParameter().connectT(1, pma);           // pma4 -> pma::Multiply
		minmax.getWrappedObject().getParameter().connectT(0, clip);        // minmax -> clip::Value
		pma9.getWrappedObject().getParameter().connectT(0, sampleandhold); // pma9 -> sampleandhold::Counter
		pma9.getWrappedObject().getParameter().connectT(1, tempo_sync2);   // pma9 -> tempo_sync2::Tempo
		pma9.getWrappedObject().getParameter().connectT(2, bitcrush);      // pma9 -> bitcrush::BitDepth
		pma9.getWrappedObject().getParameter().connectT(3, bitcrush1);     // pma9 -> bitcrush1::BitDepth
		pma9.getWrappedObject().getParameter().connectT(4, expr);          // pma9 -> expr::Value
		pma9.getWrappedObject().getParameter().connectT(5, expr4);         // pma9 -> expr4::Value
		pma9.getWrappedObject().getParameter().connectT(6, pma4);          // pma9 -> pma4::Value
		pma9.getWrappedObject().getParameter().connectT(7, expr10);        // pma9 -> expr10::Value
		pma9.getWrappedObject().getParameter().connectT(8, expr12);        // pma9 -> expr12::Value
		pma9.getWrappedObject().getParameter().connectT(9, expr9);         // pma9 -> expr9::Value
		pma9.getWrappedObject().getParameter().connectT(10, expr3);        // pma9 -> expr3::Value
		pma9.getWrappedObject().getParameter().connectT(11, tanh);         // pma9 -> tanh::Value
		pma9.getWrappedObject().getParameter().connectT(12, minmax);       // pma9 -> minmax::Value
		peak.getParameter().connectT(0, pma9);                             // peak -> pma9::Value
		pma15.getWrappedObject().getParameter().connectT(0, add12);        // pma15 -> add12::Value
		pma16.getWrappedObject().getParameter().connectT(0, add13);        // pma16 -> add13::Value
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
		auto& xfader7_p = xfader7.getWrappedObject().getParameter();
		xfader7_p.getParameterT(0).connectT(0, gain18);                      // xfader7 -> gain18::Gain
		xfader7_p.getParameterT(1).connectT(0, gain19);                      // xfader7 -> gain19::Gain
		pma19.getWrappedObject().getParameter().connectT(0, xfader7);        // pma19 -> xfader7::Value
		peak3.getParameter().connectT(0, pma19);                             // peak3 -> pma19::Value
		pma20.getWrappedObject().getParameter().connectT(0, add16);          // pma20 -> add16::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, pma20); // global_cable16 -> pma20::Value
		pma21.getWrappedObject().getParameter().connectT(0, add17);          // pma21 -> add17::Value
		pma22.getWrappedObject().getParameter().connectT(0, add18);          // pma22 -> add18::Value
		pma23.getWrappedObject().getParameter().connectT(0, add19);          // pma23 -> add19::Value
		auto& sliderbank2_p = sliderbank2.getWrappedObject().getParameter();
		sliderbank2_p.getParameterT(0).connectT(0, global_cable16);          // sliderbank2 -> global_cable16::Value
		sliderbank2_p.getParameterT(0).connectT(1, pma20);                   // sliderbank2 -> pma20::Multiply
		sliderbank2_p.getParameterT(1).connectT(0, pma21);                   // sliderbank2 -> pma21::Multiply
		sliderbank2_p.getParameterT(2).connectT(0, pma22);                   // sliderbank2 -> pma22::Multiply
		sliderbank2_p.getParameterT(3).connectT(0, pma23);                   // sliderbank2 -> pma23::Multiply
		global_cable17.getWrappedObject().getParameter().connectT(0, pma21); // global_cable17 -> pma21::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, pma22); // global_cable18 -> pma22::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, pma23); // global_cable19 -> pma23::Value
		pma24.getWrappedObject().getParameter().connectT(0, faust);          // pma24 -> faust::shiftsemitones
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
		tempo_sync.getParameter().connectT(0, faust);                        // tempo_sync -> faust::windowsamples
		pma29.getWrappedObject().getParameter().connectT(0, tempo_sync);     // pma29 -> tempo_sync::Tempo
		peak5.getParameter().connectT(0, pma29);                             // peak5 -> pma29::Value
		peak1.getParameter().connectT(0, pma);                               // peak1 -> pma::Value
		tempo_sync1.getParameter().connectT(0, faust);                       // tempo_sync1 -> faust::xfadesamples
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2); // switcher -> sb2::Bypassed
		
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
		
		add14.setParameterT(0, 0.); // math::add::Value
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma18::Value is automated
		;                           // pma18::Multiply is automated
		pma18.setParameterT(2, 0.); // control::pma::Add
		
		; // add15::Value is automated
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		sliderbank2.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // global_cable16::Value is automated
		
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
		
		; // xfader7::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		; // sampleandhold::Counter is automated
		
		;                                   // tempo_sync2::Tempo is automated
		tempo_sync2.setParameterT(1, 16.);  // control::tempo_sync::Multiplier
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // sampleandhold1::Counter is automated
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 0.); // fx::bitcrush::Mode
		
		;                               // bitcrush1::BitDepth is automated
		bitcrush1.setParameterT(1, 1.); // fx::bitcrush::Mode
		
		; // expr::Value is automated
		
		; // expr4::Value is automated
		
		gain2.setParameterT(0, -12.); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                          // pma4::Value is automated
		pma4.setParameterT(1, 1.); // control::pma::Multiply
		pma4.setParameterT(2, 0.); // control::pma::Add
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // expr10::Value is automated
		
		gain6.setParameterT(0, -12.); // core::gain::Gain
		gain6.setParameterT(1, 20.);  // core::gain::Smoothing
		gain6.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // expr12::Value is automated
		
		gain3.setParameterT(0, -12.); // core::gain::Gain
		gain3.setParameterT(1, 20.);  // core::gain::Smoothing
		gain3.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // expr9::Value is automated
		
		gain4.setParameterT(0, -12.); // core::gain::Gain
		gain4.setParameterT(1, 20.);  // core::gain::Smoothing
		gain4.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // tanh::Value is automated
		
		;                                 // minmax::Value is automated
		minmax.setParameterT(1, 0.10175); // control::minmax::Minimum
		minmax.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax.setParameterT(3, 1.);      // control::minmax::Skew
		minmax.setParameterT(4, 0.);      // control::minmax::Step
		minmax.setParameterT(5, 1.);      // control::minmax::Polarity
		
		; // clip::Value is automated
		
		; // expr3::Value is automated
		
		gain5.setParameterT(0, -12.); // core::gain::Gain
		gain5.setParameterT(1, 20.);  // core::gain::Smoothing
		gain5.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // switcher::Value is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 5.55112e-17);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.0620754);
		this->setParameterT(3, 0.00798234);
		this->setParameterT(4, 0.);
		this->setParameterT(5, -15.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 12.);
		this->setParameterT(8, 13.);
		this->setParameterT(9, 16.);
		this->setParameterT(10, 15.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable22_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Modifier_impl::global_cable23_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);         // Modifier_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);         // Modifier_impl::peak_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);         // Modifier_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index);         // Modifier_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index);         // Modifier_impl::sliderbank2_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).setExternalData(b, index);         // Modifier_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index);         // Modifier_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(2).setExternalData(b, index);         // Modifier_impl::peak5_t<NV>
		this->getT(1).getT(1).getT(0).getT(6).getT(0).getT(0).setExternalData(b, index); // Modifier_impl::peak1_t<NV>
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
using Modifier = wrap::node<Modifier_impl::instance<NV>>;
}


