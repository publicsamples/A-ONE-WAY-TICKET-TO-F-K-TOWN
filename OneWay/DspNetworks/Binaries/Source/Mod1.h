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

namespace Mod1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable1_t_index = runtime_target::indexers::fix_hash<-1580057706>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<-1059347311>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain3_t<NV>>, 
                                   chain4_t<NV>>;

template <int NV>
using envelope_follower_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                      wrap::no_data<dynamics::envelope_follower<NV>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<envelope_follower_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<envelope_follower_t<NV>, 1>, 
                                control::tempo_sync<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, tempo_sync_t<NV>>, 
                                  tempo_sync1_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch_t<NV>>, 
                                  split2_t<NV>, 
                                  envelope_follower_t<NV>, 
                                  math::clear<NV>, 
                                  math::add<NV>>;
template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;

template <int NV> using ramp1_t = ramp_t<NV>;

template <int NV>
using tempo_sync2_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<ramp1_t<NV>, 0>, 
                                         parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync2_t = wrap::mod<tempo_sync2_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync2_t<NV>>, 
                                   ramp1_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(clock_ramp_modRange, 
                             1., 
                             1000., 
                             1.);

template <int NV>
using clock_ramp_mod = parameter::from0To1<fx::sampleandhold<NV>, 
                                           0, 
                                           clock_ramp_modRange>;

template <int NV>
using clock_ramp_t = wrap::mod<clock_ramp_mod<NV>, 
                               wrap::no_data<core::clock_ramp<NV, false>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, ramp_t<NV>>, 
                                    chain10_t<NV>, 
                                    clock_ramp_t<NV>>;

using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::pi<NV>>, 
                                  math::sin<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::pi<NV>>, 
                                  math::rect<NV>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, fx::sampleandhold<NV>>, 
                                    fx::sampleandhold<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, oscillator_t<NV>>, 
                                  branch4_t<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain6_t>, 
                                    chain7_t<NV>, 
                                    chain8_t<NV>, 
                                    chain9_t<NV>>;
using peak_t = wrap::no_data<core::peak>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch2_t<NV>>, 
                                  branch3_t<NV>, 
                                  peak_t>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain2_t<NV>>, 
                                    chain5_t<NV>>;

namespace Mod1_t_parameters
{
// Parameter list for Mod1_impl::Mod1_t ------------------------------------------------------------

template <int NV>
using EnvSync = parameter::chain<ranges::Identity, 
                                 parameter::plain<Mod1_impl::tempo_sync_t<NV>, 2>, 
                                 parameter::plain<Mod1_impl::tempo_sync1_t<NV>, 2>>;

template <int NV>
using EnvMul = parameter::chain<ranges::Identity, 
                                parameter::plain<Mod1_impl::tempo_sync_t<NV>, 1>, 
                                parameter::plain<Mod1_impl::tempo_sync1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(LFOSyncMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(LFOSyncMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using LFOSyncMode_0 = parameter::from0To1<Mod1_impl::branch2_t<NV>, 
                                          0, 
                                          LFOSyncMode_0Range>;

template <int NV>
using LFOSyncMode = parameter::chain<LFOSyncMode_InputRange, 
                                     LFOSyncMode_0<NV>, 
                                     parameter::plain<Mod1_impl::branch4_t<NV>, 0>>;

template <int NV>
using Tempo = parameter::chain<ranges::Identity, 
                               parameter::plain<Mod1_impl::tempo_sync2_t<NV>, 0>, 
                               parameter::plain<Mod1_impl::clock_ramp_t<NV>, 0>>;

template <int NV>
using Div = parameter::chain<ranges::Identity, 
                             parameter::plain<Mod1_impl::tempo_sync2_t<NV>, 1>, 
                             parameter::plain<Mod1_impl::clock_ramp_t<NV>, 1>>;

template <int NV>
using Mode = parameter::plain<Mod1_impl::branch1_t<NV>, 
                              0>;
template <int NV>
using EnvInput = parameter::plain<Mod1_impl::branch_t<NV>, 
                                  0>;
template <int NV>
using EnvAtk = parameter::plain<Mod1_impl::tempo_sync_t<NV>, 
                                3>;
template <int NV>
using EnvRel = parameter::plain<Mod1_impl::tempo_sync1_t<NV>, 
                                3>;
template <int NV>
using EnvAtkSync = parameter::plain<Mod1_impl::tempo_sync_t<NV>, 
                                    0>;
template <int NV>
using EnvRelSync = parameter::plain<Mod1_impl::tempo_sync1_t<NV>, 
                                    0>;
template <int NV>
using Free = parameter::plain<Mod1_impl::ramp_t<NV>, 0>;
template <int NV>
using LFOType = parameter::plain<Mod1_impl::branch3_t<NV>, 
                                 0>;
template <int NV>
using Mod1_t_plist = parameter::list<Mode<NV>, 
                                     EnvInput<NV>, 
                                     EnvAtk<NV>, 
                                     EnvRel<NV>, 
                                     EnvSync<NV>, 
                                     EnvMul<NV>, 
                                     EnvAtkSync<NV>, 
                                     EnvRelSync<NV>, 
                                     LFOSyncMode<NV>, 
                                     Free<NV>, 
                                     Tempo<NV>, 
                                     Div<NV>, 
                                     LFOType<NV>>;
}

template <int NV>
using Mod1_t_ = container::chain<Mod1_t_parameters::Mod1_t_plist<NV>, 
                                 wrap::fix<1, branch1_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Mod1_impl::Mod1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Mod1);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(214)
		{
			0x005B, 0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 
            0x0000, 0x4500, 0x766E, 0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x025B, 0x0000, 0x4500, 0x766E, 0x7441, 0x006B, 0x0000, 0x0000, 
            0x0000, 0x447A, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 
            0x035B, 0x0000, 0x4500, 0x766E, 0x6552, 0x006C, 0x0000, 0x0000, 
            0x0000, 0x447A, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 
            0x045B, 0x0000, 0x4500, 0x766E, 0x7953, 0x636E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0005, 0x0000, 0x6E45, 0x4D76, 0x6C75, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0006, 0x0000, 0x6E45, 0x4176, 0x6B74, 0x7953, 0x636E, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0007, 0x0000, 0x6E45, 0x5276, 0x6C65, 
            0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 0x0000, 0x464C, 
            0x534F, 0x6E79, 0x4D63, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x095B, 
            0x0000, 0x4600, 0x6572, 0x0065, 0xCCCD, 0x3DCC, 0x0000, 0x457A, 
            0xB667, 0x44C7, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x0A5B, 0x0000, 
            0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000B, 0x0000, 
            0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0C5B, 0x0000, 0x4C00, 0x4F46, 
            0x7954, 0x6570, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& branch1 = this->getT(0);                                                // Mod1_impl::branch1_t<NV>
		auto& chain2 = this->getT(0).getT(0);                                         // Mod1_impl::chain2_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0);                                 // Mod1_impl::branch_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0);                         // Mod1_impl::chain3_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(0);          // Mod1_impl::global_cable1_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1);                    // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(1);                         // Mod1_impl::chain4_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(1).getT(0);          // Mod1_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                   // math::add<NV>
		auto& split2 = this->getT(0).getT(0).getT(1);                                 // Mod1_impl::split2_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(1).getT(0);                     // Mod1_impl::tempo_sync_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(0).getT(1).getT(1);                    // Mod1_impl::tempo_sync1_t<NV>
		auto& envelope_follower = this->getT(0).getT(0).getT(2);                      // Mod1_impl::envelope_follower_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(3);                                 // math::clear<NV>
		auto& add1 = this->getT(0).getT(0).getT(4);                                   // math::add<NV>
		auto& chain5 = this->getT(0).getT(1);                                         // Mod1_impl::chain5_t<NV>
		auto& branch2 = this->getT(0).getT(1).getT(0);                                // Mod1_impl::branch2_t<NV>
		auto& ramp = this->getT(0).getT(1).getT(0).getT(0);                           // Mod1_impl::ramp_t<NV>
		auto& chain10 = this->getT(0).getT(1).getT(0).getT(1);                        // Mod1_impl::chain10_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(1).getT(0).getT(1).getT(0);            // Mod1_impl::tempo_sync2_t<NV>
		auto& ramp1 = this->getT(0).getT(1).getT(0).getT(1).getT(1);                  // Mod1_impl::ramp1_t<NV>
		auto& clock_ramp = this->getT(0).getT(1).getT(0).getT(2);                     // Mod1_impl::clock_ramp_t<NV>
		auto& branch3 = this->getT(0).getT(1).getT(1);                                // Mod1_impl::branch3_t<NV>
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(0);                         // Mod1_impl::chain6_t
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(1);                         // Mod1_impl::chain7_t<NV>
		auto& pi = this->getT(0).getT(1).getT(1).getT(1).getT(0);                     // math::pi<NV>
		auto& sin = this->getT(0).getT(1).getT(1).getT(1).getT(1);                    // math::sin<NV>
		auto& chain8 = this->getT(0).getT(1).getT(1).getT(2);                         // Mod1_impl::chain8_t<NV>
		auto& pi1 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                    // math::pi<NV>
		auto& rect = this->getT(0).getT(1).getT(1).getT(2).getT(1);                   // math::rect<NV>
		auto& chain9 = this->getT(0).getT(1).getT(1).getT(3);                         // Mod1_impl::chain9_t<NV>
		auto& oscillator = this->getT(0).getT(1).getT(1).getT(3).getT(0);             // Mod1_impl::oscillator_t<NV>
		auto& branch4 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                // Mod1_impl::branch4_t<NV>
		auto& sampleandhold = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);  // fx::sampleandhold<NV>
		auto& sampleandhold1 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(1); // fx::sampleandhold<NV>
		auto& peak = this->getT(0).getT(1).getT(2);                                   // Mod1_impl::peak_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch1); // Mode -> branch1::Index
		
		this->getParameterT(1).connectT(0, branch); // EnvInput -> branch::Index
		
		this->getParameterT(2).connectT(0, tempo_sync); // EnvAtk -> tempo_sync::UnsyncedTime
		
		this->getParameterT(3).connectT(0, tempo_sync1); // EnvRel -> tempo_sync1::UnsyncedTime
		
		auto& EnvSync_p = this->getParameterT(4);
		EnvSync_p.connectT(0, tempo_sync);  // EnvSync -> tempo_sync::Enabled
		EnvSync_p.connectT(1, tempo_sync1); // EnvSync -> tempo_sync1::Enabled
		
		auto& EnvMul_p = this->getParameterT(5);
		EnvMul_p.connectT(0, tempo_sync);  // EnvMul -> tempo_sync::Multiplier
		EnvMul_p.connectT(1, tempo_sync1); // EnvMul -> tempo_sync1::Multiplier
		
		this->getParameterT(6).connectT(0, tempo_sync); // EnvAtkSync -> tempo_sync::Tempo
		
		this->getParameterT(7).connectT(0, tempo_sync1); // EnvRelSync -> tempo_sync1::Tempo
		
		auto& LFOSyncMode_p = this->getParameterT(8);
		LFOSyncMode_p.connectT(0, branch2); // LFOSyncMode -> branch2::Index
		LFOSyncMode_p.connectT(1, branch4); // LFOSyncMode -> branch4::Index
		
		this->getParameterT(9).connectT(0, ramp); // Free -> ramp::PeriodTime
		
		auto& Tempo_p = this->getParameterT(10);
		Tempo_p.connectT(0, tempo_sync2); // Tempo -> tempo_sync2::Tempo
		Tempo_p.connectT(1, clock_ramp);  // Tempo -> clock_ramp::Tempo
		
		auto& Div_p = this->getParameterT(11);
		Div_p.connectT(0, tempo_sync2); // Div -> tempo_sync2::Multiplier
		Div_p.connectT(1, clock_ramp);  // Div -> clock_ramp::Multiplier
		
		this->getParameterT(12).connectT(0, branch3); // LFOType -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable1.getWrappedObject().getParameter().connectT(0, add);  // global_cable1 -> add::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2); // global_cable2 -> add2::Value
		envelope_follower.getParameter().connectT(0, add1);                // envelope_follower -> add1::Value
		tempo_sync.getParameter().connectT(0, envelope_follower);          // tempo_sync -> envelope_follower::Attack
		tempo_sync1.getParameter().connectT(0, envelope_follower);         // tempo_sync1 -> envelope_follower::Release
		tempo_sync2.getParameter().connectT(0, ramp1);                     // tempo_sync2 -> ramp1::PeriodTime
		tempo_sync2.getParameter().connectT(1, sampleandhold);             // tempo_sync2 -> sampleandhold::Counter
		clock_ramp.getParameter().connectT(0, sampleandhold1);             // clock_ramp -> sampleandhold1::Counter
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch1::Index is automated
		
		; // branch::Index is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // tempo_sync1::Tempo is automated
		; // tempo_sync1::Multiplier is automated
		; // tempo_sync1::Enabled is automated
		; // tempo_sync1::UnsyncedTime is automated
		
		;                                       // envelope_follower::Attack is automated
		;                                       // envelope_follower::Release is automated
		envelope_follower.setParameterT(2, 0.); // dynamics::envelope_follower::ProcessSignal
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add1::Value is automated
		
		; // branch2::Index is automated
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp1::PeriodTime is automated
		ramp1.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		;                                // clock_ramp::Tempo is automated
		;                                // clock_ramp::Multiplier is automated
		clock_ramp.setParameterT(2, 1.); // core::clock_ramp::AddToSignal
		clock_ramp.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // branch3::Index is automated
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		sin.setParameterT(0, 1.); // math::sin::Value
		
		pi1.setParameterT(0, 1.); // math::pi::Value
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // branch4::Index is automated
		
		; // sampleandhold::Counter is automated
		
		; // sampleandhold1::Counter is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 4.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 2.);
		this->setParameterT(9, 1597.7);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 2.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Mod1_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Mod1_impl::global_cable2_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                 // Mod1_impl::envelope_follower_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);         // Mod1_impl::ramp_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(1).setExternalData(b, index); // Mod1_impl::ramp1_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).setExternalData(b, index);         // Mod1_impl::clock_ramp_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(0).setExternalData(b, index); // Mod1_impl::oscillator_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                 // Mod1_impl::peak_t
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
using Mod1 = wrap::node<Mod1_impl::instance<NV>>;
}


