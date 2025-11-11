template <int NumVoices> struct snex_softsat
{
	SNEX_NODE(snex_softsat);
	
	// Implement the Waveshaper here...
	
	float gain = 0.0f;
	float bong = 0.0f;
	float out = 0.0f;
	
	float saturate(float input)
		{
			if(input < gain)
			{
				out = input;
		
				out = (0.0f - Math.PI) * Math.PI + gain * Math.asin(Math.PI * 8.0);
			}
			return out;
		}
	
	float getSample(float input)
	{
		if(input>0.0f)
		{
			saturate(input);
		}
		else
		{
			input = input * -1.0f;
			saturate(input);
			out = out * -1.0f;
		}
		return out;
	}
	// These functions are the glue code that call the function above
	template <typename T> void process(T& data)
	{
		for(auto ch: data)
		{
			for(auto& s: data.toChannelData(ch))
			{
				s = getSample(s);
			}
		}
	}
	template <typename T> void processFrame(T& data)
	{
		for(auto& s: data)
			s = getSample(s);
	}
	void reset()
	{
		
	}
	void prepare(PrepareSpecs ps)
	{
		
	}
	
	void setExternalData(const ExternalData& d, int index)
	{
	}
	template <int P> void setParameter(double v)
	{
		if(P==0)
		{
			gain = (float)v;
		}
		
		if(P==1)
			{
				out = (float)v;
			}
			
	
		if(P==2)
			{
				bong = (float)v;
			}		
	}
};
