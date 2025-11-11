#pragma once

#include "FileShape.h"
#include "Modifier.h"
#include "MultiFilter.h"
#include "PostFilter.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Arrange_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable4_t_index = runtime_target::indexers::fix_hash<2164996>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<2164997>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain6_t<NV>>, 
                                    chain7_t<NV>, 
                                    chain8_t<NV>, 
                                    chain9_t<NV>>;

struct FileShape1_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 7;
	static const int NumAudioFiles = 1;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][7] =
	{
		{ -1, -1, -1, -1, -1, -1, -1 },   // 
		{ 0, 1, 2, 3, 1000, 1001, 1002 }, //  | 0->0 | 1->1 | 2->2 | 3->3 | 4->e[0] | 5->e[1] | 6->e[2]
		{ 0, -1, -1, -1, -1, -1, -1 }     //  | 0->0
	};
	
private:
	
	span<float, 16> d0 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d1 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d2 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 3> embeddedData = { d0, d1, d2 };
};

template <int NV>
using FileShape1_t = wrap::data<project::FileShape<NV>, 
                                data::matrix<FileShape1_t_matrix>>;

struct Modifier2_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 7;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][7] =
	{
		{ -1, -1, -1, -1, -1, -1, -1 },   // 
		{ 0, 1, 2, 3, 1000, 1001, 1002 }, //  | 0->0 | 1->1 | 2->2 | 3->3 | 4->e[0] | 5->e[1] | 6->e[2]
		{ -1, -1, -1, -1, -1, -1, -1 }    // 
	};
	
private:
	
	span<float, 16> d0 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d1 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d2 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 3> embeddedData = { d0, d1, d2 };
};

template <int NV>
using Modifier2_t = wrap::data<project::Modifier<NV>, 
                               data::matrix<Modifier2_t_matrix>>;

struct PostFilter1_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 7;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][7] =
	{
		{ -1, -1, -1, -1, -1, -1, -1 },   // 
		{ 0, 2, 1, 3, 1000, 1001, 1002 }, //  | 0->0 | 1->2 | 2->1 | 3->3 | 4->e[0] | 5->e[1] | 6->e[2]
		{ -1, -1, -1, -1, -1, -1, -1 }    // 
	};
	
private:
	
	span<float, 16> d0 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d1 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d2 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 3> embeddedData = { d0, d1, d2 };
};

template <int NV>
using PostFilter1_t = wrap::data<project::PostFilter<NV>, 
                                 data::matrix<PostFilter1_t_matrix>>;

struct MultiFilter1_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 7;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][7] =
	{
		{ -1, -1, -1, -1, -1, -1, -1 }, // 
		{ 0, 1, 2, 3, 4, 1000, 1001 },  //  | 0->0 | 1->1 | 2->2 | 3->3 | 4->4 | 5->e[0] | 6->e[1]
		{ -1, -1, -1, -1, -1, -1, -1 }  // 
	};
	
private:
	
	span<float, 16> d0 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d1 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 2> embeddedData = { d0, d1 };
};

template <int NV>
using MultiFilter1_t = wrap::data<project::MultiFilter<NV>, 
                                  data::matrix<MultiFilter1_t_matrix>>;
DECLARE_PARAMETER_RANGE(pma1_mod_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using pma1_mod_0 = parameter::from0To1<FileShape1_t<NV>, 
                                       1, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod_1 = parameter::from0To1<Modifier2_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>, 
                                  parameter::plain<PostFilter1_t<NV>, 0>, 
                                  parameter::plain<MultiFilter1_t<NV>, 3>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch2_t<NV>>, 
                                  peak1_t<NV>, 
                                  pma1_t<NV>>;
using global_cable8_t_index = global_cable4_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = global_cable5_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = global_cable6_t_index;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = global_cable7_t_index;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain11_t<NV>>, 
                                    chain12_t<NV>, 
                                    chain13_t<NV>, 
                                    chain14_t<NV>>;

template <int NV>
using pma2_mod_0 = parameter::from0To1<Modifier2_t<NV>, 
                                       2, 
                                       pma1_mod_0Range>;

template <int NV>
using pma2_mod_1 = parameter::from0To1<FileShape1_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  pma2_mod_0<NV>, 
                                  pma2_mod_1<NV>, 
                                  parameter::plain<MultiFilter1_t<NV>, 0>, 
                                  parameter::plain<PostFilter1_t<NV>, 1>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak2_t<NV>, 
                                   pma2_t<NV>>;
using global_cable12_t_index = global_cable4_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable5_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable6_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable7_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain16_t<NV>>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>, 
                                    chain19_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_mod_0Range, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using pma3_mod_0 = parameter::from0To1<FileShape1_t<NV>, 
                                       3, 
                                       pma3_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma3_mod_1Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma3_mod_1 = parameter::from0To1<Modifier2_t<NV>, 
                                       7, 
                                       pma3_mod_1Range>;

template <int NV>
using pma3_mod_3 = parameter::from0To1<PostFilter1_t<NV>, 
                                       2, 
                                       pma1_mod_0Range>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  pma3_mod_0<NV>, 
                                  pma3_mod_1<NV>, 
                                  parameter::plain<MultiFilter1_t<NV>, 1>, 
                                  pma3_mod_3<NV>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak3_t<NV>, 
                                   pma3_t<NV>>;
using global_cable16_t_index = global_cable4_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable5_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = global_cable6_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = global_cable7_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain21_t<NV>>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma4_mod_0 = parameter::from0To1<Modifier2_t<NV>, 
                                       8, 
                                       pma4_mod_0Range>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  parameter::plain<FileShape1_t<NV>, 8>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak4_t<NV>, 
                                   pma4_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain10_t<NV>, 
                                  chain15_t<NV>, 
                                  chain20_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split1_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, FileShape1_t<NV>>, 
                                   Modifier2_t<NV>, 
                                   MultiFilter1_t<NV>, 
                                   PostFilter1_t<NV>>;

namespace Arrange_t_parameters
{
// Parameter list for Arrange_impl::Arrange_t ------------------------------------------------------

template <int NV>
using Mix = parameter::from0To1<Arrange_impl::pma1_t<NV>, 
                                2, 
                                Arrange_impl::pma1_mod_0Range>;

template <int NV>
using A = parameter::from0To1<Arrange_impl::pma2_t<NV>, 
                              2, 
                              Arrange_impl::pma1_mod_0Range>;

template <int NV>
using B = parameter::from0To1<Arrange_impl::pma3_t<NV>, 
                              2, 
                              Arrange_impl::pma1_mod_0Range>;

template <int NV>
using C = parameter::from0To1<Arrange_impl::pma4_t<NV>, 
                              2, 
                              Arrange_impl::pma1_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(ModuleSelect_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ModuleSelect_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using ModuleSelect_0 = parameter::from0To1<Arrange_impl::branch_t<NV>, 
                                           0, 
                                           ModuleSelect_0Range>;

template <int NV>
using ModuleSelect = parameter::chain<ModuleSelect_InputRange, 
                                      ModuleSelect_0<NV>>;

DECLARE_PARAMETER_RANGE(MixSrc_InputRange, 
                        1., 
                        4.);
template <int NV>
using MixSrc_0 = parameter::from0To1<Arrange_impl::branch2_t<NV>, 
                                     0, 
                                     ModuleSelect_0Range>;

template <int NV>
using MixSrc = parameter::chain<MixSrc_InputRange, MixSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(AmodSrc_InputRange, 
                        1., 
                        4.);
template <int NV>
using AmodSrc_0 = parameter::from0To1<Arrange_impl::branch3_t<NV>, 
                                      0, 
                                      ModuleSelect_0Range>;

template <int NV>
using AmodSrc = parameter::chain<AmodSrc_InputRange, AmodSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Bmodsrc_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using Bmodsrc_0 = parameter::from0To1<Arrange_impl::branch4_t<NV>, 
                                      0, 
                                      ModuleSelect_0Range>;

template <int NV>
using Bmodsrc = parameter::chain<Bmodsrc_InputRange, Bmodsrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Cmodsrc_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using Cmodsrc_0 = parameter::from0To1<Arrange_impl::branch5_t<NV>, 
                                      0, 
                                      ModuleSelect_0Range>;

template <int NV>
using Cmodsrc = parameter::chain<Cmodsrc_InputRange, Cmodsrc_0<NV>>;

template <int NV>
using PitchShif = parameter::plain<Arrange_impl::Modifier2_t<NV>, 
                                   6>;
template <int NV>
using F2Gain = parameter::plain<Arrange_impl::PostFilter1_t<NV>, 
                                4>;
template <int NV>
using F1mode = parameter::plain<Arrange_impl::MultiFilter1_t<NV>, 
                                2>;
template <int NV>
using F2mode = parameter::plain<Arrange_impl::PostFilter1_t<NV>, 
                                3>;
template <int NV>
using ModMod = parameter::plain<Arrange_impl::Modifier2_t<NV>, 
                                1>;
template <int NV>
using ModXf = parameter::plain<Arrange_impl::Modifier2_t<NV>, 
                               9>;
template <int NV>
using ModDiv = parameter::plain<Arrange_impl::Modifier2_t<NV>, 
                                10>;
template <int NV>
using MixMod = parameter::plain<Arrange_impl::pma1_t<NV>, 
                                1>;
template <int NV>
using Amod = parameter::plain<Arrange_impl::pma2_t<NV>, 
                              1>;
template <int NV>
using Bmod = parameter::plain<Arrange_impl::pma3_t<NV>, 
                              1>;
template <int NV>
using Cmod = parameter::plain<Arrange_impl::pma4_t<NV>, 
                              1>;
template <int NV>
using Arrange_t_plist = parameter::list<Mix<NV>, 
                                        A<NV>, 
                                        B<NV>, 
                                        C<NV>, 
                                        PitchShif<NV>, 
                                        F2Gain<NV>, 
                                        F1mode<NV>, 
                                        F2mode<NV>, 
                                        ModMod<NV>, 
                                        ModXf<NV>, 
                                        ModDiv<NV>, 
                                        ModuleSelect<NV>, 
                                        MixMod<NV>, 
                                        MixSrc<NV>, 
                                        Amod<NV>, 
                                        AmodSrc<NV>, 
                                        Bmod<NV>, 
                                        Bmodsrc<NV>, 
                                        Cmod<NV>, 
                                        Cmodsrc<NV>>;
}

template <int NV>
using Arrange_t_ = container::chain<Arrange_t_parameters::Arrange_t_plist<NV>, 
                                    wrap::fix<2, modchain1_t<NV>>, 
                                    branch_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Arrange_impl::Arrange_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 5;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Arrange);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(314)
		{
			0x005B, 0x0000, 0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xF63F, 0x67B8, 0x003D, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x0041, 0x0000, 0x0000, 0x0000, 0x3F80, 0x6020, 0x3F12, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x4200, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0003, 0x0000, 0x0043, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x5000, 0x7469, 0x6863, 0x6853, 0x6669, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0005, 0x0000, 0x3246, 0x6147, 0x6E69, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0006, 0x0000, 0x3146, 0x6F6D, 0x6564, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0007, 0x0000, 0x3246, 0x6F6D, 0x6564, 0x0000, 0x8000, 
            0x003F, 0x4000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0008, 0x0000, 0x6F4D, 0x4D64, 0x646F, 0x0000, 0x8000, 
            0x003F, 0x5000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0009, 0x0000, 0x6F4D, 0x5864, 0x0066, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0A5B, 0x0000, 0x4D00, 0x646F, 0x6944, 0x0076, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0B5B, 0x0000, 0x4D00, 0x646F, 0x6C75, 0x5365, 0x6C65, 0x6365, 
            0x0074, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0C5B, 0x0000, 0x4D00, 0x7869, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x9917, 0xBD19, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x4D00, 0x7869, 0x7253, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x4100, 0x6F6D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0F5B, 0x0000, 0x4100, 0x6F6D, 0x5364, 0x6372, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 0x6D42, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0011, 0x0000, 0x6D42, 0x646F, 0x7273, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x125B, 0x0000, 0x4300, 0x6F6D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xB5C3, 0x3BAC, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x135B, 0x0000, 0x4300, 0x6F6D, 0x7364, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                              // Arrange_impl::modchain1_t<NV>
		auto& split1 = this->getT(0).getT(0);                                         // Arrange_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0);                                 // Arrange_impl::chain5_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(0).getT(0);                        // Arrange_impl::branch2_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                 // Arrange_impl::chain6_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);  // Arrange_impl::global_cable4_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                 // Arrange_impl::chain7_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);  // Arrange_impl::global_cable5_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                 // Arrange_impl::chain8_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);  // Arrange_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                 // Arrange_impl::chain9_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);  // Arrange_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(1);                          // Arrange_impl::peak1_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(2);                           // Arrange_impl::pma1_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1);                                // Arrange_impl::chain10_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(0);                        // Arrange_impl::branch3_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                // Arrange_impl::chain11_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);  // Arrange_impl::global_cable8_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain12 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                // Arrange_impl::chain12_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);  // Arrange_impl::global_cable9_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                // Arrange_impl::chain13_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(0).getT(2).getT(0); // Arrange_impl::global_cable10_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(1).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                // Arrange_impl::chain14_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0); // Arrange_impl::global_cable11_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(1);                          // Arrange_impl::peak2_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(1).getT(2);                           // Arrange_impl::pma2_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(2);                                // Arrange_impl::chain15_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(2).getT(0);                        // Arrange_impl::branch4_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                // Arrange_impl::chain16_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0); // Arrange_impl::global_cable12_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);          // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                // Arrange_impl::chain17_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0); // Arrange_impl::global_cable13_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                // Arrange_impl::chain18_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0); // Arrange_impl::global_cable14_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                // Arrange_impl::chain19_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0); // Arrange_impl::global_cable15_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2).getT(1);                          // Arrange_impl::peak3_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(2).getT(2);                           // Arrange_impl::pma3_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(3);                                // Arrange_impl::chain20_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(3).getT(0);                        // Arrange_impl::branch5_t<NV>
		auto& chain21 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                // Arrange_impl::chain21_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0); // Arrange_impl::global_cable16_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                // Arrange_impl::chain22_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0); // Arrange_impl::global_cable17_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(3).getT(0).getT(2);                // Arrange_impl::chain23_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(3).getT(0).getT(2).getT(0); // Arrange_impl::global_cable18_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(3).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(3).getT(0).getT(3);                // Arrange_impl::chain24_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(0); // Arrange_impl::global_cable19_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& peak4 = this->getT(0).getT(0).getT(3).getT(1);                          // Arrange_impl::peak4_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(3).getT(2);                           // Arrange_impl::pma4_t<NV>
		auto& branch = this->getT(1);                                                 // Arrange_impl::branch_t<NV>
		auto& FileShape1 = this->getT(1).getT(0);                                     // Arrange_impl::FileShape1_t<NV>
		auto& Modifier2 = this->getT(1).getT(1);                                      // Arrange_impl::Modifier2_t<NV>
		auto& MultiFilter1 = this->getT(1).getT(2);                                   // Arrange_impl::MultiFilter1_t<NV>
		auto& PostFilter1 = this->getT(1).getT(3);                                    // Arrange_impl::PostFilter1_t<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Mix -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma2); // A -> pma2::Add
		
		this->getParameterT(2).connectT(0, pma3); // B -> pma3::Add
		
		this->getParameterT(3).connectT(0, pma4); // C -> pma4::Add
		
		this->getParameterT(4).connectT(0, Modifier2); // PitchShif -> Modifier2::PITCHSHIFT
		
		this->getParameterT(5).connectT(0, PostFilter1); // F2Gain -> PostFilter1::Gain
		
		this->getParameterT(6).connectT(0, MultiFilter1); // F1mode -> MultiFilter1::Mode
		
		this->getParameterT(7).connectT(0, PostFilter1); // F2mode -> PostFilter1::Mode
		
		this->getParameterT(8).connectT(0, Modifier2); // ModMod -> Modifier2::mode
		
		this->getParameterT(9).connectT(0, Modifier2); // ModXf -> Modifier2::XF
		
		this->getParameterT(10).connectT(0, Modifier2); // ModDiv -> Modifier2::DIV
		
		this->getParameterT(11).connectT(0, branch); // ModuleSelect -> branch::Index
		
		this->getParameterT(12).connectT(0, pma1); // MixMod -> pma1::Multiply
		
		this->getParameterT(13).connectT(0, branch2); // MixSrc -> branch2::Index
		
		this->getParameterT(14).connectT(0, pma2); // Amod -> pma2::Multiply
		
		this->getParameterT(15).connectT(0, branch3); // AmodSrc -> branch3::Index
		
		this->getParameterT(16).connectT(0, pma3); // Bmod -> pma3::Multiply
		
		this->getParameterT(17).connectT(0, branch4); // Bmodsrc -> branch4::Index
		
		this->getParameterT(18).connectT(0, pma4); // Cmod -> pma4::Multiply
		
		this->getParameterT(19).connectT(0, branch5); // Cmodsrc -> branch5::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);   // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);   // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);   // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);   // global_cable7 -> add7::Value
		pma1.getWrappedObject().getParameter().connectT(0, FileShape1);      // pma1 -> FileShape1::FileMix
		pma1.getWrappedObject().getParameter().connectT(1, Modifier2);       // pma1 -> Modifier2::mix
		pma1.getWrappedObject().getParameter().connectT(2, PostFilter1);     // pma1 -> PostFilter1::Mix
		pma1.getWrappedObject().getParameter().connectT(3, MultiFilter1);    // pma1 -> MultiFilter1::Mix
		peak1.getParameter().connectT(0, pma1);                              // peak1 -> pma1::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);   // global_cable8 -> add8::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add9);   // global_cable9 -> add9::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add10); // global_cable10 -> add10::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add11); // global_cable11 -> add11::Value
		pma2.getWrappedObject().getParameter().connectT(0, Modifier2);       // pma2 -> Modifier2::FX
		pma2.getWrappedObject().getParameter().connectT(1, FileShape1);      // pma2 -> FileShape1::Drive1
		pma2.getWrappedObject().getParameter().connectT(2, MultiFilter1);    // pma2 -> MultiFilter1::CutOffset
		pma2.getWrappedObject().getParameter().connectT(3, PostFilter1);     // pma2 -> PostFilter1::Cut
		peak2.getParameter().connectT(0, pma2);                              // peak2 -> pma2::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add12); // global_cable12 -> add12::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add13); // global_cable13 -> add13::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add14); // global_cable14 -> add14::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add15); // global_cable15 -> add15::Value
		pma3.getWrappedObject().getParameter().connectT(0, FileShape1);      // pma3 -> FileShape1::Smooth
		pma3.getWrappedObject().getParameter().connectT(1, Modifier2);       // pma3 -> Modifier2::PITCH
		pma3.getWrappedObject().getParameter().connectT(2, MultiFilter1);    // pma3 -> MultiFilter1::Res
		pma3.getWrappedObject().getParameter().connectT(3, PostFilter1);     // pma3 -> PostFilter1::Res
		peak3.getParameter().connectT(0, pma3);                              // peak3 -> pma3::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add16); // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17); // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18); // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19); // global_cable19 -> add19::Value
		pma4.getWrappedObject().getParameter().connectT(0, Modifier2);       // pma4 -> Modifier2::WIN
		pma4.getWrappedObject().getParameter().connectT(1, FileShape1);      // pma4 -> FileShape1::Hp
		peak4.getParameter().connectT(0, pma4);                              // peak4 -> pma4::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch2::Index is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // branch3::Index is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // branch4::Index is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // branch5::Index is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		; // branch::Index is automated
		
		;                                // FileShape1::Drive1 is automated
		;                                // FileShape1::FileMix is automated
		FileShape1.setParameterT(2, -4); // project::FileShape::PostGain
		;                                // FileShape1::Smooth is automated
		FileShape1.setParameterT(4, 0.); // project::FileShape::DriveMod
		FileShape1.setParameterT(5, 0.); // project::FileShape::MixMod
		FileShape1.setParameterT(6, 0.); // project::FileShape::SmoothMod
		FileShape1.setParameterT(7, 0.); // project::FileShape::HpMod
		;                                // FileShape1::Hp is automated
		
		;                                 // Modifier2::mix is automated
		;                                 // Modifier2::mode is automated
		;                                 // Modifier2::FX is automated
		Modifier2.setParameterT(3, 0.);   // project::Modifier::MixMod
		Modifier2.setParameterT(4, 0.);   // project::Modifier::DriveMod
		Modifier2.setParameterT(5, -4.1); // project::Modifier::PostFxGain
		;                                 // Modifier2::PITCHSHIFT is automated
		;                                 // Modifier2::PITCH is automated
		;                                 // Modifier2::WIN is automated
		;                                 // Modifier2::XF is automated
		;                                 // Modifier2::DIV is automated
		Modifier2.setParameterT(11, 0.);  // project::Modifier::PitchMod
		Modifier2.setParameterT(12, 0.);  // project::Modifier::WinMod
		
		;                                        // MultiFilter1::CutOffset is automated
		;                                        // MultiFilter1::Res is automated
		;                                        // MultiFilter1::Mode is automated
		;                                        // MultiFilter1::Mix is automated
		MultiFilter1.setParameterT(4, 0.697891); // project::MultiFilter::MultiGain
		MultiFilter1.setParameterT(5, 0.);       // project::MultiFilter::CutMod
		MultiFilter1.setParameterT(6, 0.);       // project::MultiFilter::MixMod
		MultiFilter1.setParameterT(7, 0.);       // project::MultiFilter::ResMod
		
		;                                 // PostFilter1::Mix is automated
		;                                 // PostFilter1::Cut is automated
		;                                 // PostFilter1::Res is automated
		;                                 // PostFilter1::Mode is automated
		;                                 // PostFilter1::Gain is automated
		PostFilter1.setParameterT(5, 0.); // project::PostFilter::CutMod
		PostFilter1.setParameterT(6, 0.); // project::PostFilter::MixMod
		PostFilter1.setParameterT(7, 0.); // project::PostFilter::Qmod
		PostFilter1.setParameterT(8, 0.); // project::PostFilter::PitchMod
		
		this->setParameterT(0, 0.0565729);
		this->setParameterT(1, 0.571779);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, -0.0374995);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.00527069);
		this->setParameterT(19, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Arrange_impl::global_cable19_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // Arrange_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // Arrange_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).setExternalData(b, index); // Arrange_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).setExternalData(b, index); // Arrange_impl::peak4_t<NV>
		this->getT(1).getT(0).setExternalData(b, index);                 // Arrange_impl::FileShape1_t<NV>
		this->getT(1).getT(1).setExternalData(b, index);                 // Arrange_impl::Modifier2_t<NV>
		this->getT(1).getT(2).setExternalData(b, index);                 // Arrange_impl::MultiFilter1_t<NV>
		this->getT(1).getT(3).setExternalData(b, index);                 // Arrange_impl::PostFilter1_t<NV>
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
using Arrange = wrap::node<Arrange_impl::instance<NV>>;
}


