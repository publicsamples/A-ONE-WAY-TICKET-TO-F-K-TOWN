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

namespace Comp_impl
{
// =============================| Node & Parameter type declarations |=============================

DECLARE_PARAMETER_RANGE_SKEW(xfader6_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader6_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader6_c0Range>;

template <int NV> using xfader6_c1 = xfader6_c0<NV>;

template <int NV>
using xfader6_multimod = parameter::list<xfader6_c0<NV>, xfader6_c1<NV>>;

template <int NV>
using xfader6_t = control::xfader<xfader6_multimod<NV>, faders::linear>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader6_t<NV>>, 
                                   core::gain<NV>>;
using comp_t = wrap::no_data<dynamics::comp>;

using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

using chain56_t = chain55_t;

using chain57_t = chain55_t;

using chain59_t = chain55_t;

using chain58_t = chain55_t;

using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain56_t>, 
                                   chain57_t, 
                                   chain59_t, 
                                   chain58_t>;

using chain68_t = chain55_t;

using chain69_t = chain55_t;

using chain70_t = chain55_t;

using chain71_t = chain55_t;

using split14_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain68_t>, 
                                   chain69_t, 
                                   chain70_t, 
                                   chain71_t>;
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain55_t>, 
                                     split10_t, 
                                     split14_t>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<2, comp_t>, 
                                   branch10_t, 
                                   core::gain<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain53_t<NV>>, 
                                  chain54_t<NV>>;

namespace Comp_t_parameters
{
// Parameter list for Comp_impl::Comp_t ----------------------------------------------------------

template <int NV>
using CompMix = parameter::plain<Comp_impl::xfader6_t<NV>, 
                                 0>;
using Threshold = parameter::plain<Comp_impl::comp_t, 0>;
using Attack = parameter::plain<Comp_impl::comp_t, 1>;
using release = parameter::plain<Comp_impl::comp_t, 2>;
using Ratio = parameter::plain<Comp_impl::comp_t, 3>;
using Boost = parameter::plain<Comp_impl::branch10_t, 0>;
template <int NV>
using Comp_t_plist = parameter::list<CompMix<NV>, 
                                     Threshold, 
                                     Attack, 
                                     release, 
                                     Ratio, 
                                     Boost>;
}

template <int NV>
using Comp_t_ = container::chain<Comp_t_parameters::Comp_t_plist<NV>, 
                                 wrap::fix<2, split9_t<NV>>>;

// ================================| Root node initialiser class |================================

template <int NV> struct instance: public Comp_impl::Comp_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Comp);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(98)
		{
			0x005B, 0x0000, 0x4300, 0x6D6F, 0x4D70, 0x7869, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0001, 0x0000, 0x6854, 0x6572, 0x6873, 0x6C6F, 0x0064, 
            0x0000, 0xC2C8, 0x0000, 0x0000, 0x999A, 0xC2C5, 0x833E, 0x40AD, 
            0xCCCD, 0x3DCC, 0x025B, 0x0000, 0x4100, 0x7474, 0x6361, 0x006B, 
            0x0000, 0x0000, 0x0000, 0x437A, 0x0000, 0x0000, 0x81A3, 0x3EDC, 
            0xCCCD, 0x3DCC, 0x035B, 0x0000, 0x7200, 0x6C65, 0x6165, 0x6573, 
            0x0000, 0x0000, 0x0000, 0x7A00, 0x0043, 0x8000, 0xA33F, 0xDC81, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x0004, 0x0000, 0x6152, 0x6974, 0x006F, 
            0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0xF69D, 0x3E97, 
            0xCCCD, 0x3DCC, 0x055B, 0x0000, 0x4200, 0x6F6F, 0x7473, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -----------------------------------------------------------------------
		
		auto& split9 = this->getT(0);                                  // Comp_impl::split9_t<NV>
		auto& chain53 = this->getT(0).getT(0);                         // Comp_impl::chain53_t<NV>
		auto& xfader6 = this->getT(0).getT(0).getT(0);                 // Comp_impl::xfader6_t<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1);                  // core::gain<NV>
		auto& chain54 = this->getT(0).getT(1);                         // Comp_impl::chain54_t<NV>
		auto& comp = this->getT(0).getT(1).getT(0);                    // Comp_impl::comp_t
		auto& branch10 = this->getT(0).getT(1).getT(1);                // Comp_impl::branch10_t
		auto& chain55 = this->getT(0).getT(1).getT(1).getT(0);         // Comp_impl::chain55_t
		auto& split10 = this->getT(0).getT(1).getT(1).getT(1);         // Comp_impl::split10_t
		auto& chain56 = this->getT(0).getT(1).getT(1).getT(1).getT(0); // Comp_impl::chain56_t
		auto& chain57 = this->getT(0).getT(1).getT(1).getT(1).getT(1); // Comp_impl::chain57_t
		auto& chain59 = this->getT(0).getT(1).getT(1).getT(1).getT(2); // Comp_impl::chain59_t
		auto& chain58 = this->getT(0).getT(1).getT(1).getT(1).getT(3); // Comp_impl::chain58_t
		auto& split14 = this->getT(0).getT(1).getT(1).getT(2);         // Comp_impl::split14_t
		auto& chain68 = this->getT(0).getT(1).getT(1).getT(2).getT(0); // Comp_impl::chain68_t
		auto& chain69 = this->getT(0).getT(1).getT(1).getT(2).getT(1); // Comp_impl::chain69_t
		auto& chain70 = this->getT(0).getT(1).getT(1).getT(2).getT(2); // Comp_impl::chain70_t
		auto& chain71 = this->getT(0).getT(1).getT(1).getT(2).getT(3); // Comp_impl::chain71_t
		auto& gain17 = this->getT(0).getT(1).getT(2);                  // core::gain<NV>
		
		// Parameter Connections -----------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader6); // CompMix -> xfader6::Value
		
		this->getParameterT(1).connectT(0, comp); // Threshold -> comp::Threshhold
		
		this->getParameterT(2).connectT(0, comp); // Attack -> comp::Attack
		
		this->getParameterT(3).connectT(0, comp); // release -> comp::Release
		
		this->getParameterT(4).connectT(0, comp); // Ratio -> comp::Ratio
		
		this->getParameterT(5).connectT(0, branch10); // Boost -> branch10::Index
		
		// Modulation Connections ----------------------------------------------------------------
		
		auto& xfader6_p = xfader6.getWrappedObject().getParameter();
		xfader6_p.getParameterT(0).connectT(0, gain16); // xfader6 -> gain16::Gain
		xfader6_p.getParameterT(1).connectT(0, gain17); // xfader6 -> gain17::Gain
		
		// Default Values ------------------------------------------------------------------------
		
		; // xfader6::Value is automated
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                          // comp::Threshhold is automated
		;                          // comp::Attack is automated
		;                          // comp::Release is automated
		;                          // comp::Ratio is automated
		comp.setParameterT(4, 0.); // dynamics::comp::Sidechain
		
		; // branch10::Index is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, -98.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1);
		this->setParameterT(4, 1);
		this->setParameterT(5, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references ------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections -------------------------------------------------------------
		
		this->getT(0).getT(1).getT(0).setExternalData(b, index); // Comp_impl::comp_t
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =====================================| Public Definition |=====================================

namespace project
{
// polyphonic template declaration

template <int NV>
using Comp = wrap::node<Comp_impl::instance<NV>>;
}


