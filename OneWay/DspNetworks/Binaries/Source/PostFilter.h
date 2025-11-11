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

namespace PostFilter_impl
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

DECLARE_PARAMETER_RANGE_SKEW(pma9_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma9_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                       0, 
                                       pma9_mod_0Range>;

template <int NV> using pma9_mod_1 = pma9_mod_0<NV>;

template <int NV>
using pma9_mod_2 = parameter::from0To1<filters::svf<NV>, 
                                       0, 
                                       pma9_mod_0Range>;

template <int NV> using pma9_mod_3 = pma9_mod_2<NV>;

template <int NV> using pma9_mod_4 = pma9_mod_2<NV>;

template <int NV> using pma9_mod_5 = pma9_mod_2<NV>;

template <int NV>
using pma9_mod_6 = parameter::from0To1<filters::ladder<NV>, 
                                       0, 
                                       pma9_mod_0Range>;

template <int NV>
using pma9_mod_7 = parameter::from0To1<filters::biquad<NV>, 
                                       0, 
                                       pma9_mod_0Range>;

template <int NV> using pma9_mod_8 = pma9_mod_7<NV>;

template <int NV> using pma9_mod_9 = pma9_mod_7<NV>;

template <int NV> using pma9_mod_10 = pma9_mod_7<NV>;

template <int NV>
using pma9_mod_11 = parameter::from0To1<filters::allpass<NV>, 
                                        0, 
                                        pma9_mod_0Range>;

template <int NV>
using pma9_mod = parameter::chain<ranges::Identity, 
                                  pma9_mod_0<NV>, 
                                  pma9_mod_1<NV>, 
                                  pma9_mod_2<NV>, 
                                  pma9_mod_3<NV>, 
                                  pma9_mod_4<NV>, 
                                  pma9_mod_5<NV>, 
                                  pma9_mod_6<NV>, 
                                  pma9_mod_7<NV>, 
                                  pma9_mod_8<NV>, 
                                  pma9_mod_9<NV>, 
                                  pma9_mod_10<NV>, 
                                  pma9_mod_11<NV>>;

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
using chain1_t = container::chain<parameter::empty, 
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
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain1_t<NV>>, 
                                  chain13_t<NV>, 
                                  chain16_t<NV>, 
                                  chain17_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader4_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader4_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader4_c0Range>;

template <int NV> using xfader4_c1 = xfader4_c0<NV>;

template <int NV>
using xfader4_multimod = parameter::list<xfader4_c0<NV>, xfader4_c1<NV>>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::linear>;
template <int NV>
using pma14_t = control::pma<NV, 
                             parameter::plain<xfader4_t<NV>, 0>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma14_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank4_t<NV>>, 
                                   split3_t<NV>, 
                                   peak1_t<NV>, 
                                   pma14_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
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
                                 data::external::sliderpack<2>>;
using global_cable11_t_index = global_cable3_t_index;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<pma30_t<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
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
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain4_t<NV>>, 
                                  chain21_t<NV>, 
                                  chain22_t<NV>, 
                                  chain23_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma34_mod_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using pma34_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        pma34_mod_0Range>;

template <int NV> using pma34_mod_1 = pma34_mod_0<NV>;

template <int NV> using pma34_mod_2 = pma34_mod_0<NV>;

template <int NV> using pma34_mod_3 = pma34_mod_0<NV>;

template <int NV>
using pma34_mod_4 = parameter::from0To1<filters::ladder<NV>, 
                                        1, 
                                        pma34_mod_0Range>;

template <int NV>
using pma34_mod_5 = parameter::from0To1<filters::biquad<NV>, 
                                        1, 
                                        pma34_mod_0Range>;

template <int NV> using pma34_mod_6 = pma34_mod_5<NV>;

template <int NV> using pma34_mod_7 = pma34_mod_5<NV>;

template <int NV> using pma34_mod_8 = pma34_mod_5<NV>;

template <int NV>
using pma34_mod_9 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        pma34_mod_0Range>;

template <int NV>
using pma34_mod = parameter::chain<ranges::Identity, 
                                   pma34_mod_0<NV>, 
                                   pma34_mod_1<NV>, 
                                   pma34_mod_2<NV>, 
                                   pma34_mod_3<NV>, 
                                   pma34_mod_4<NV>, 
                                   pma34_mod_5<NV>, 
                                   pma34_mod_6<NV>, 
                                   pma34_mod_7<NV>, 
                                   pma34_mod_8<NV>, 
                                   pma34_mod_9<NV>>;

template <int NV>
using pma34_t = control::pma<NV, pma34_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma34_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank5_t<NV>>, 
                                   split6_t<NV>, 
                                   peak2_t<NV>, 
                                   pma34_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain19_t<NV>>>;

template <int NV> using pma35_t = pma5_t<NV>;
template <int NV>
using sliderbank6_c0 = parameter::from0To1<pma35_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma36_t = pma5_t<NV>;
template <int NV>
using sliderbank6_c1 = parameter::from0To1<pma36_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma37_t = pma5_t<NV>;
template <int NV>
using sliderbank6_c2 = parameter::from0To1<pma37_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV> using pma38_t = pma5_t<NV>;
template <int NV>
using sliderbank6_c3 = parameter::from0To1<pma38_t<NV>, 
                                           1, 
                                           sliderbank_c0Range>;

template <int NV>
using sliderbank6_multimod = parameter::list<sliderbank6_c0<NV>, 
                                             sliderbank6_c1<NV>, 
                                             sliderbank6_c2<NV>, 
                                             sliderbank6_c3<NV>>;

template <int NV>
using sliderbank6_t = wrap::data<control::sliderbank<sliderbank6_multimod<NV>>, 
                                 data::external::sliderpack<3>>;
using global_cable27_t_index = global_cable3_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<pma35_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable27_t<NV>>, 
                                  pma35_t<NV>, 
                                  math::add<NV>>;
using global_cable28_t_index = global_cable4_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<pma36_t<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   pma36_t<NV>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable5_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<pma37_t<NV>, 0>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   pma37_t<NV>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable6_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<pma38_t<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   pma38_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain6_t<NV>>, 
                                   chain25_t<NV>, 
                                   chain27_t<NV>, 
                                   chain28_t<NV>>;

template <int NV>
using peak6_t = wrap::mod<parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank6_t<NV>>, 
                                   split15_t<NV>, 
                                   peak6_t<NV>, 
                                   control::pma<NV, parameter::empty>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain24_t<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, split1_t<NV>>, 
                                  split2_t<NV>, 
                                  split4_t<NV>, 
                                  split14_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader4_t<NV>>, 
                                   core::gain<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, filters::one_pole<NV>>, 
                                    filters::one_pole<NV>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    filters::ladder<NV>, 
                                    filters::biquad<NV>, 
                                    filters::biquad<NV>, 
                                    filters::biquad<NV>, 
                                    filters::biquad<NV>, 
                                    filters::allpass<NV>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch3_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain49_t<NV>>, 
                                  chain50_t<NV>>;

namespace PostFilter_t_parameters
{
// Parameter list for PostFilter_impl::PostFilter_t ------------------------------------------------

template <int NV>
using Mix = parameter::from0To1<PostFilter_impl::pma14_t<NV>, 
                                2, 
                                PostFilter_impl::sliderbank_c0Range>;

template <int NV>
using Cut = parameter::from0To1<PostFilter_impl::pma9_t<NV>, 
                                2, 
                                PostFilter_impl::sliderbank_c0Range>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             11., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<PostFilter_impl::branch3_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

DECLARE_PARAMETER_RANGE(Gain_0Range, 
                        -18., 
                        18.);

template <int NV>
using Gain_0 = parameter::from0To1<filters::biquad<NV>, 
                                   2, 
                                   Gain_0Range>;

template <int NV> using Gain_1 = Gain_0<NV>;

template <int NV> using Gain_2 = Gain_0<NV>;

template <int NV> using Gain_3 = Gain_0<NV>;

template <int NV>
using Gain = parameter::chain<ranges::Identity, 
                              Gain_0<NV>, 
                              Gain_1<NV>, 
                              Gain_2<NV>, 
                              Gain_3<NV>>;

template <int NV>
using Res = parameter::plain<PostFilter_impl::pma34_t<NV>, 
                             2>;
template <int NV>
using CutMod = parameter::plain<PostFilter_impl::pma9_t<NV>, 
                                1>;
template <int NV>
using MixMod = parameter::plain<PostFilter_impl::pma14_t<NV>, 
                                1>;
template <int NV>
using Qmod = parameter::plain<PostFilter_impl::pma34_t<NV>, 
                              1>;
template <int NV>
using PitchMod = parameter::plain<control::pma<NV, parameter::empty>, 
                                  1>;
template <int NV>
using PostFilter_t_plist = parameter::list<Mix<NV>, 
                                           Cut<NV>, 
                                           Res<NV>, 
                                           Mode<NV>, 
                                           Gain<NV>, 
                                           CutMod<NV>, 
                                           MixMod<NV>, 
                                           Qmod<NV>, 
                                           PitchMod<NV>>;
}

template <int NV>
using PostFilter_t_ = container::chain<PostFilter_t_parameters::PostFilter_t_plist<NV>, 
                                       wrap::fix<2, modchain1_t<NV>>, 
                                       split7_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public PostFilter_impl::PostFilter_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(PostFilter);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(138)
		{
			0x005B, 0x0000, 0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x853F, 0x11EB, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0xC1AE, 
            0x3E45, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5200, 
            0x7365, 0x0000, 0x8000, 0x0024, 0x8000, 0x263F, 0x6E6E, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x6F4D, 0x6564, 
            0x0000, 0x8000, 0x003F, 0x4000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0004, 0x0000, 0x6147, 0x6E69, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0005, 0x0000, 0x7543, 0x4D74, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x694D, 0x4D78, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0007, 0x0000, 0x6D51, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0008, 0x0000, 0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                                      // PostFilter_impl::modchain1_t<NV>
		auto& split5 = this->getT(0).getT(0);                                                 // PostFilter_impl::split5_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0);                                         // PostFilter_impl::split1_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0);                                // PostFilter_impl::chain10_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                     // PostFilter_impl::sliderbank_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(0).getT(1);                          // PostFilter_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                  // PostFilter_impl::chain_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);  // PostFilter_impl::global_cable3_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);           // PostFilter_impl::pma5_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);            // math::add<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                // PostFilter_impl::chain12_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);  // PostFilter_impl::global_cable4_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);           // PostFilter_impl::pma6_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                // PostFilter_impl::chain14_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);  // PostFilter_impl::global_cable5_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);           // PostFilter_impl::pma7_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                // PostFilter_impl::chain15_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);  // PostFilter_impl::global_cable6_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);           // PostFilter_impl::pma8_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(2);                           // PostFilter_impl::peak_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                           // PostFilter_impl::pma9_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(1);                                         // PostFilter_impl::split2_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(0);                                // PostFilter_impl::chain11_t<NV>
		auto& sliderbank4 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                    // PostFilter_impl::sliderbank4_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                         // PostFilter_impl::split3_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                 // PostFilter_impl::chain1_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);  // PostFilter_impl::global_cable7_t<NV>
		auto& pma10 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);          // PostFilter_impl::pma10_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);           // math::add<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);                // PostFilter_impl::chain13_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);  // PostFilter_impl::global_cable8_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);          // PostFilter_impl::pma11_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain16 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2);                // PostFilter_impl::chain16_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0);  // PostFilter_impl::global_cable9_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);          // PostFilter_impl::pma12_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(2);           // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3);                // PostFilter_impl::chain17_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0); // PostFilter_impl::global_cable10_t<NV>
		auto& pma13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(1);          // PostFilter_impl::pma13_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(2);           // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                          // PostFilter_impl::peak1_t<NV>
		auto& pma14 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                          // PostFilter_impl::pma14_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(2);                                         // PostFilter_impl::split4_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(2).getT(0);                                // PostFilter_impl::chain19_t<NV>
		auto& sliderbank5 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                    // PostFilter_impl::sliderbank5_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                         // PostFilter_impl::split6_t<NV>
		auto& chain4 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);                 // PostFilter_impl::chain4_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0); // PostFilter_impl::global_cable11_t<NV>
		auto& pma30 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(1);          // PostFilter_impl::pma30_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(2);           // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);                // PostFilter_impl::chain21_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0); // PostFilter_impl::global_cable24_t<NV>
		auto& pma31 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(1);          // PostFilter_impl::pma31_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(2);           // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2);                // PostFilter_impl::chain22_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0); // PostFilter_impl::global_cable25_t<NV>
		auto& pma32 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(1);          // PostFilter_impl::pma32_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3);                // PostFilter_impl::chain23_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0); // PostFilter_impl::global_cable26_t<NV>
		auto& pma33 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(1);          // PostFilter_impl::pma33_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                          // PostFilter_impl::peak2_t<NV>
		auto& pma34 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                          // PostFilter_impl::pma34_t<NV>
		auto& split14 = this->getT(0).getT(0).getT(3);                                        // PostFilter_impl::split14_t<NV>
		auto& chain24 = this->getT(0).getT(0).getT(3).getT(0);                                // PostFilter_impl::chain24_t<NV>
		auto& sliderbank6 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                    // PostFilter_impl::sliderbank6_t<NV>
		auto& split15 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                        // PostFilter_impl::split15_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);                 // PostFilter_impl::chain6_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(0); // PostFilter_impl::global_cable27_t<NV>
		auto& pma35 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(1);          // PostFilter_impl::pma35_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(2);          // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);                // PostFilter_impl::chain25_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(0); // PostFilter_impl::global_cable28_t<NV>
		auto& pma36 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(1);          // PostFilter_impl::pma36_t<NV>
		auto& add25 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(2);          // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2);                // PostFilter_impl::chain27_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0); // PostFilter_impl::global_cable29_t<NV>
		auto& pma37 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(1);          // PostFilter_impl::pma37_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(2);          // math::add<NV>
		auto& chain28 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3);                // PostFilter_impl::chain28_t<NV>
		auto& global_cable30 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(0); // PostFilter_impl::global_cable30_t<NV>
		auto& pma38 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(1);          // PostFilter_impl::pma38_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(2);          // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(3).getT(0).getT(2);                          // PostFilter_impl::peak6_t<NV>
		auto& pma39 = this->getT(0).getT(0).getT(3).getT(0).getT(3);                          // control::pma<NV, parameter::empty>
		auto& split7 = this->getT(1);                                                         // PostFilter_impl::split7_t<NV>
		auto& chain49 = this->getT(1).getT(0);                                                // PostFilter_impl::chain49_t<NV>
		auto& xfader4 = this->getT(1).getT(0).getT(0);                                        // PostFilter_impl::xfader4_t<NV>
		auto& gain12 = this->getT(1).getT(0).getT(1);                                         // core::gain<NV>
		auto& chain50 = this->getT(1).getT(1);                                                // PostFilter_impl::chain50_t<NV>
		auto& branch3 = this->getT(1).getT(1).getT(0);                                        // PostFilter_impl::branch3_t<NV>
		auto& one_pole = this->getT(1).getT(1).getT(0).getT(0);                               // filters::one_pole<NV>
		auto& one_pole1 = this->getT(1).getT(1).getT(0).getT(1);                              // filters::one_pole<NV>
		auto& svf = this->getT(1).getT(1).getT(0).getT(2);                                    // filters::svf<NV>
		auto& svf1 = this->getT(1).getT(1).getT(0).getT(3);                                   // filters::svf<NV>
		auto& svf2 = this->getT(1).getT(1).getT(0).getT(4);                                   // filters::svf<NV>
		auto& svf3 = this->getT(1).getT(1).getT(0).getT(5);                                   // filters::svf<NV>
		auto& ladder = this->getT(1).getT(1).getT(0).getT(6);                                 // filters::ladder<NV>
		auto& biquad = this->getT(1).getT(1).getT(0).getT(7);                                 // filters::biquad<NV>
		auto& biquad1 = this->getT(1).getT(1).getT(0).getT(8);                                // filters::biquad<NV>
		auto& biquad2 = this->getT(1).getT(1).getT(0).getT(9);                                // filters::biquad<NV>
		auto& biquad3 = this->getT(1).getT(1).getT(0).getT(10);                               // filters::biquad<NV>
		auto& allpass = this->getT(1).getT(1).getT(0).getT(11);                               // filters::allpass<NV>
		auto& gain13 = this->getT(1).getT(1).getT(1);                                         // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma14); // Mix -> pma14::Add
		
		this->getParameterT(1).connectT(0, pma9); // Cut -> pma9::Add
		
		this->getParameterT(2).connectT(0, pma34); // Res -> pma34::Add
		
		this->getParameterT(3).connectT(0, branch3); // Mode -> branch3::Index
		
		auto& Gain_p = this->getParameterT(4);
		Gain_p.connectT(0, biquad);  // Gain -> biquad::Gain
		Gain_p.connectT(1, biquad1); // Gain -> biquad1::Gain
		Gain_p.connectT(2, biquad2); // Gain -> biquad2::Gain
		Gain_p.connectT(3, biquad3); // Gain -> biquad3::Gain
		
		this->getParameterT(5).connectT(0, pma9); // CutMod -> pma9::Multiply
		
		this->getParameterT(6).connectT(0, pma14); // MixMod -> pma14::Multiply
		
		this->getParameterT(7).connectT(0, pma34); // Qmod -> pma34::Multiply
		
		this->getParameterT(8).connectT(0, pma39); // PitchMod -> pma39::Multiply
		
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
		pma9.getWrappedObject().getParameter().connectT(0, one_pole);      // pma9 -> one_pole::Frequency
		pma9.getWrappedObject().getParameter().connectT(1, one_pole1);     // pma9 -> one_pole1::Frequency
		pma9.getWrappedObject().getParameter().connectT(2, svf);           // pma9 -> svf::Frequency
		pma9.getWrappedObject().getParameter().connectT(3, svf1);          // pma9 -> svf1::Frequency
		pma9.getWrappedObject().getParameter().connectT(4, svf2);          // pma9 -> svf2::Frequency
		pma9.getWrappedObject().getParameter().connectT(5, svf3);          // pma9 -> svf3::Frequency
		pma9.getWrappedObject().getParameter().connectT(6, ladder);        // pma9 -> ladder::Frequency
		pma9.getWrappedObject().getParameter().connectT(7, biquad);        // pma9 -> biquad::Frequency
		pma9.getWrappedObject().getParameter().connectT(8, biquad1);       // pma9 -> biquad1::Frequency
		pma9.getWrappedObject().getParameter().connectT(9, biquad2);       // pma9 -> biquad2::Frequency
		pma9.getWrappedObject().getParameter().connectT(10, biquad3);      // pma9 -> biquad3::Frequency
		pma9.getWrappedObject().getParameter().connectT(11, allpass);      // pma9 -> allpass::Frequency
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
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, gain12);               // xfader4 -> gain12::Gain
		xfader4_p.getParameterT(1).connectT(0, gain13);               // xfader4 -> gain13::Gain
		pma14.getWrappedObject().getParameter().connectT(0, xfader4); // pma14 -> xfader4::Value
		peak1.getParameter().connectT(0, pma14);                      // peak1 -> pma14::Value
		pma30.getWrappedObject().getParameter().connectT(0, add8);    // pma30 -> add8::Value
		pma31.getWrappedObject().getParameter().connectT(0, add9);    // pma31 -> add9::Value
		pma32.getWrappedObject().getParameter().connectT(0, add10);   // pma32 -> add10::Value
		pma33.getWrappedObject().getParameter().connectT(0, add11);   // pma33 -> add11::Value
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, pma30);                   // sliderbank5 -> pma30::Multiply
		sliderbank5_p.getParameterT(1).connectT(0, pma31);                   // sliderbank5 -> pma31::Multiply
		sliderbank5_p.getParameterT(2).connectT(0, pma32);                   // sliderbank5 -> pma32::Multiply
		sliderbank5_p.getParameterT(3).connectT(0, pma33);                   // sliderbank5 -> pma33::Multiply
		global_cable11.getWrappedObject().getParameter().connectT(0, pma30); // global_cable11 -> pma30::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, pma31); // global_cable24 -> pma31::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, pma32); // global_cable25 -> pma32::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, pma33); // global_cable26 -> pma33::Value
		pma34.getWrappedObject().getParameter().connectT(0, svf);            // pma34 -> svf::Q
		pma34.getWrappedObject().getParameter().connectT(1, svf1);           // pma34 -> svf1::Q
		pma34.getWrappedObject().getParameter().connectT(2, svf2);           // pma34 -> svf2::Q
		pma34.getWrappedObject().getParameter().connectT(3, svf3);           // pma34 -> svf3::Q
		pma34.getWrappedObject().getParameter().connectT(4, ladder);         // pma34 -> ladder::Q
		pma34.getWrappedObject().getParameter().connectT(5, biquad);         // pma34 -> biquad::Q
		pma34.getWrappedObject().getParameter().connectT(6, biquad1);        // pma34 -> biquad1::Q
		pma34.getWrappedObject().getParameter().connectT(7, biquad2);        // pma34 -> biquad2::Q
		pma34.getWrappedObject().getParameter().connectT(8, biquad3);        // pma34 -> biquad3::Q
		pma34.getWrappedObject().getParameter().connectT(9, allpass);        // pma34 -> allpass::Q
		peak2.getParameter().connectT(0, pma34);                             // peak2 -> pma34::Value
		pma35.getWrappedObject().getParameter().connectT(0, add24);          // pma35 -> add24::Value
		pma36.getWrappedObject().getParameter().connectT(0, add25);          // pma36 -> add25::Value
		pma37.getWrappedObject().getParameter().connectT(0, add26);          // pma37 -> add26::Value
		pma38.getWrappedObject().getParameter().connectT(0, add27);          // pma38 -> add27::Value
		auto& sliderbank6_p = sliderbank6.getWrappedObject().getParameter();
		sliderbank6_p.getParameterT(0).connectT(0, pma35);                   // sliderbank6 -> pma35::Multiply
		sliderbank6_p.getParameterT(1).connectT(0, pma36);                   // sliderbank6 -> pma36::Multiply
		sliderbank6_p.getParameterT(2).connectT(0, pma37);                   // sliderbank6 -> pma37::Multiply
		sliderbank6_p.getParameterT(3).connectT(0, pma38);                   // sliderbank6 -> pma38::Multiply
		global_cable27.getWrappedObject().getParameter().connectT(0, pma35); // global_cable27 -> pma35::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, pma36); // global_cable28 -> pma36::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, pma37); // global_cable29 -> pma37::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, pma38); // global_cable30 -> pma38::Value
		peak6.getParameter().connectT(0, pma39);                             // peak6 -> pma39::Value
		
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
		
		sliderbank6.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma35::Value is automated
		;                           // pma35::Multiply is automated
		pma35.setParameterT(2, 0.); // control::pma::Add
		
		; // add24::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma36::Value is automated
		;                           // pma36::Multiply is automated
		pma36.setParameterT(2, 0.); // control::pma::Add
		
		; // add25::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma37::Value is automated
		;                           // pma37::Multiply is automated
		pma37.setParameterT(2, 0.); // control::pma::Add
		
		; // add26::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                           // pma38::Value is automated
		;                           // pma38::Multiply is automated
		pma38.setParameterT(2, 0.); // control::pma::Add
		
		; // add27::Value is automated
		
		;                           // pma39::Value is automated
		;                           // pma39::Multiply is automated
		pma39.setParameterT(2, 0.); // control::pma::Add
		
		; // xfader4::Value is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch3::Index is automated
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 0.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 0.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
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
		
		;                            // svf3::Frequency is automated
		;                            // svf3::Q is automated
		svf3.setParameterT(2, 0.);   // filters::svf::Gain
		svf3.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf3.setParameterT(4, 3.);   // filters::svf::Mode
		svf3.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                   // ladder::Frequency is automated
		;                                   // ladder::Q is automated
		ladder.setParameterT(2, 4.63837);   // filters::ladder::Gain
		ladder.setParameterT(3, 0.01);      // filters::ladder::Smoothing
		ladder.setParameterT(4, 0.0708437); // filters::ladder::Mode
		ladder.setParameterT(5, 1.);        // filters::ladder::Enabled
		
		;                              // biquad::Frequency is automated
		;                              // biquad::Q is automated
		;                              // biquad::Gain is automated
		biquad.setParameterT(3, 0.01); // filters::biquad::Smoothing
		biquad.setParameterT(4, 2.);   // filters::biquad::Mode
		biquad.setParameterT(5, 1.);   // filters::biquad::Enabled
		
		;                               // biquad1::Frequency is automated
		;                               // biquad1::Q is automated
		;                               // biquad1::Gain is automated
		biquad1.setParameterT(3, 0.01); // filters::biquad::Smoothing
		biquad1.setParameterT(4, 3.);   // filters::biquad::Mode
		biquad1.setParameterT(5, 1.);   // filters::biquad::Enabled
		
		;                               // biquad2::Frequency is automated
		;                               // biquad2::Q is automated
		;                               // biquad2::Gain is automated
		biquad2.setParameterT(3, 0.01); // filters::biquad::Smoothing
		biquad2.setParameterT(4, 4.);   // filters::biquad::Mode
		biquad2.setParameterT(5, 1.);   // filters::biquad::Enabled
		
		;                               // biquad3::Frequency is automated
		;                               // biquad3::Q is automated
		;                               // biquad3::Gain is automated
		biquad3.setParameterT(3, 0.01); // filters::biquad::Smoothing
		biquad3.setParameterT(4, 5.);   // filters::biquad::Mode
		biquad3.setParameterT(5, 1.);   // filters::biquad::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.57);
		this->setParameterT(1, 0.193122);
		this->setParameterT(2, 0.931368);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable27_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable28_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable29_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // PostFilter_impl::global_cable30_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // PostFilter_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // PostFilter_impl::peak_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // PostFilter_impl::sliderbank4_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index); // PostFilter_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index); // PostFilter_impl::sliderbank5_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).setExternalData(b, index); // PostFilter_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index); // PostFilter_impl::sliderbank6_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(2).setExternalData(b, index); // PostFilter_impl::peak6_t<NV>
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
using PostFilter = wrap::node<PostFilter_impl::instance<NV>>;
}


