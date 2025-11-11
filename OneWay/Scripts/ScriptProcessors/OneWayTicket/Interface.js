Content.makeFrontInterface(720, 540);
 
 
//Matrix Connections

//Slot1


  
const var FileShaper1 = Content.getComponent("FileShaper1");
const var MODIFIER1 = Content.getComponent("MODIFIER1");
const var MULTIFILTER1 = Content.getComponent("MULTIFILTER1");
const var FILTER1 = Content.getComponent("FILTER1");

const var SlotChide1 = [Content.getComponent("MixMod7"),
                        Content.getComponent("ModSlot4"),
                        Content.getComponent("Slot1C1")];





const var Slot1 = Synth.getEffect("Slot1");

inline function onSlotMode1Control(component, value)
{
	Slot1.setAttribute(Slot1.ModuleSelect, value);

	if(value == 1)
	    	{
	FileShaper1.showControl(1);
	MODIFIER1.showControl(0);
	MULTIFILTER1.showControl(0);
	FILTER1.showControl(0);

	for(s in SlotChide1)
		         s.showControl(1);
		         
	}
	
	if(value == 2)
		    	{
		FileShaper1.showControl(0);
		MODIFIER1.showControl(1);
		MULTIFILTER1.showControl(0);
		FILTER1.showControl(0);
		
		for(s in SlotChide1)
			         s.showControl(1);
			         
		}
	if(value == 3)
		    	{
		FileShaper1.showControl(0);
		MODIFIER1.showControl(0);
		MULTIFILTER1.showControl(1);
		FILTER1.showControl(0);
		
		for(s in SlotChide1)
			         s.showControl(0);
		}	
	if(value == 4)
		    	{
		FileShaper1.showControl(0);
		MODIFIER1.showControl(0);
		MULTIFILTER1.showControl(0);
		FILTER1.showControl(1);
		
		for(s in SlotChide1)
			         s.showControl(0);
		}
};

Content.getComponent("SlotMode1").setControlCallback(onSlotMode1Control);

const var SlotMods1 = Content.getComponent("SlotMods1");


 //Slot2
 
 const var FileShaper2 = Content.getComponent("FileShaper2");
 const var MODIFIER2 = Content.getComponent("MODIFIER2");
 const var MULTIFILTER2 = Content.getComponent("MULTIFILTER2");
 const var FILTER2 = Content.getComponent("FILTER2");
 
const var SlotChide2 = [Content.getComponent("MixMod10"),
                        Content.getComponent("ModSlot8"),
                        Content.getComponent("Slot1C2")];

 
 
 const var Slot2 = Synth.getEffect("Slot2");
 
 inline function onSlotMode2Control(component, value)
 {
 	Slot2.setAttribute(Slot2.ModuleSelect, value);
 
 	if(value == 1)
 	    	{
 	FileShaper2.showControl(1);
 	MODIFIER2.showControl(0);
 	MULTIFILTER2.showControl(0);
 	FILTER2.showControl(0);
 
 	for(s in SlotChide2)
 		         s.showControl(1);
 		         
 	}
 	
 	if(value == 2)
 		    	{
 		FileShaper2.showControl(0);
 		MODIFIER2.showControl(1);
 		MULTIFILTER2.showControl(0);
 		FILTER2.showControl(0);
 		
 		for(s in SlotChide2)
 			         s.showControl(1);
 			         
 		}
 	if(value == 3)
 		    	{
 		FileShaper2.showControl(0);
 		MODIFIER2.showControl(0);
 		MULTIFILTER2.showControl(1);
 		FILTER2.showControl(0);
 		
 		for(s in SlotChide2)
 			         s.showControl(0);
 		}	
 	if(value == 4)
 		    	{
 		FileShaper2.showControl(0);
 		MODIFIER2.showControl(0);
 		MULTIFILTER2.showControl(0);
 		FILTER2.showControl(1);
 		
 		for(s in SlotChide2)
 			         s.showControl(0);
 		}
 };
 
 Content.getComponent("SlotMode2").setControlCallback(onSlotMode2Control);
 
 //Slot3 
   
 const var FileShaper3 = Content.getComponent("FileShaper3");
 const var MODIFIER3 = Content.getComponent("MODIFIER3");
 const var MULTIFILTER3 = Content.getComponent("MULTIFILTER3");
 const var FILTER3 = Content.getComponent("FILTER3");
 
const var SlotChide3 = [Content.getComponent("Slot1C3"),
                        Content.getComponent("ModSlot12"),
                        Content.getComponent("MixMod13")];
 
 
 const var Slot3 = Synth.getEffect("Slot3");
 
 inline function onSlotMode3Control(component, value)
 {
 	Slot3.setAttribute(Slot3.ModuleSelect, value);
 
 	if(value == 1)
 	    	{
 	FileShaper3.showControl(1);
 	MODIFIER3.showControl(0);
 	MULTIFILTER3.showControl(0);
 	FILTER3.showControl(0);
 
 	for(s in SlotChide3)
 		         s.showControl(1);
 		         
 	}
 	
 	if(value == 2)
 		    	{
 		FileShaper3.showControl(0);
 		MODIFIER3.showControl(1);
 		MULTIFILTER3.showControl(0);
 		FILTER3.showControl(0);
 		
 		for(s in SlotChide3)
 			         s.showControl(1);
 			         
 		}
 	if(value == 3)
 		    	{
 		FileShaper3.showControl(0);
 		MODIFIER3.showControl(0);
 		MULTIFILTER3.showControl(1);
 		FILTER3.showControl(0);
 		
 		for(s in SlotChide3)
 			         s.showControl(0);
 		}	
 	if(value == 4)
 		    	{
 		FileShaper3.showControl(0);
 		MODIFIER3.showControl(0);
 		MULTIFILTER3.showControl(0);
 		FILTER3.showControl(1);
 		
 		for(s in SlotChide3)
 			         s.showControl(0);
 		}
 };
 
 Content.getComponent("SlotMode3").setControlCallback(onSlotMode3Control);
 
 
 //Slot4 
   
 const var FileShaper4 = Content.getComponent("FileShaper4");
 const var MODIFIER4 = Content.getComponent("MODIFIER4");
 const var MULTIFILTER4 = Content.getComponent("MULTIFILTER4");
 const var FILTER4 = Content.getComponent("FILTER4");
 
const var SlotChide4 = [Content.getComponent("Slot1C4"),
                        Content.getComponent("ModSlot16"),
                        Content.getComponent("MixMod16")];

 
 
 const var Slot4 = Synth.getEffect("Slot4");
 
 inline function onSlotMode4Control(component, value)
 {
 	Slot4.setAttribute(Slot4.ModuleSelect, value);
 
 	if(value == 1)
 	    	{
 	FileShaper4.showControl(1);
 	MODIFIER4.showControl(0);
 	MULTIFILTER4.showControl(0);
 	FILTER4.showControl(0);
 
 	for(s in SlotChide4)
 		         s.showControl(1);
 		         
 	}
 	
 	if(value == 2)
 		    	{
 		FileShaper4.showControl(0);
 		MODIFIER4.showControl(1);
 		MULTIFILTER4.showControl(0);
 		FILTER4.showControl(0);
 		
 		for(s in SlotChide4)
 			         s.showControl(1);
 			         
 		}
 	if(value == 3)
 		    	{
 		FileShaper4.showControl(0);
 		MODIFIER4.showControl(0);
 		MULTIFILTER4.showControl(1);
 		FILTER4.showControl(0);
 		
 		for(s in SlotChide4)
 			         s.showControl(0);
 		}	
 	if(value == 4)
 		    	{
 		FileShaper4.showControl(0);
 		MODIFIER4.showControl(0);
 		MULTIFILTER4.showControl(0);
 		FILTER4.showControl(1);
 		
 		for(s in SlotChide4)
 			         s.showControl(0);
 		}
 };
 
 Content.getComponent("SlotMode4").setControlCallback(onSlotMode4Control);
 
 
   
 
 
         

const var Presets = Content.getComponent("Presets");


inline function onPanelSwitch2Control(component, value)
{
	Presets.showControl(value);
};

Content.getComponent("PanelSwitch2").setControlCallback(onPanelSwitch2Control);


const var Env1Free = [Content.getComponent("EnvRelFree1"),
                      Content.getComponent("EnvAtkFree1")];
      
const var Env1Clk = [Content.getComponent("EnvAtkClk1"),
                     Content.getComponent("EnvRelClk1"),
                     Content.getComponent("EnvDiv1"),
                     Content.getComponent("Label60")];
 
 const var Env1 = Synth.getModulator("Env1");
 
 inline function onButton8Control(component, value)
 {
	Env1.setAttribute(Env1.EnvSync, value);

	 for(s in Env1Free)
	     s.showControl(value-1);
	     
	     for(s in Env1Clk)
	         s.showControl(value);
 };
 
 Content.getComponent("Button8").setControlCallback(onButton8Control);
 
const var EnvFree2 = [Content.getComponent("EnvAtkFree2"),
                      Content.getComponent("EnvRelFree2")];

const var EnvClk2 = [Content.getComponent("EnvAtkClk2"),
                     Content.getComponent("EnvRelClk2"),
                     Content.getComponent("EnvDiv2"),
                     Content.getComponent("Label90")];
        
const var Env2 = Synth.getModulator("Env2");             

inline function onButton39Control(component, value)
{
		Env2.setAttribute(Env2.EnvSync, value);

	 for(s in EnvFree2)
	     s.showControl(value-1);
	     
	     for(s in EnvClk2)
	         s.showControl(value);
};

Content.getComponent("Button39").setControlCallback(onButton39Control);

const var Speed1 = Content.getComponent("Speed1");

const var Lfo1Clk = [Content.getComponent("Tempo"),
                     Content.getComponent("Div1"),
                     Content.getComponent("Label62")];

const var LFO1 = Synth.getModulator("LFO1");
                     

inline function onLfoSync1Control(component, value)
{
	
	LFO1.setAttribute(LFO1.LFOSyncMode, value);

	if(value == 1)
	    	{
	for(s in Lfo1Clk)
		         s.showControl(0);
		         
	Speed1.showControl(1);        
	}
	
	if(value == 2)
	    	{
	for(s in Lfo1Clk)
		         s.showControl(1);
		         
	Speed1.showControl(0);        
	}
	
	if(value == 3)
	    	{
	for(s in Lfo1Clk)
		         s.showControl(1);
		         
	Speed1.showControl(0);        
	}
};

Content.getComponent("LfoSync1").setControlCallback(onLfoSync1Control);

const var Speed2 = Content.getComponent("Speed2");

const var LfoClk2 = [Content.getComponent("Div2"),
                     Content.getComponent("Tempo1"),
                     Content.getComponent("Label93")];

const var LFO2 = Synth.getModulator("LFO2");


inline function onLfoSync2Control(component, value)
{
	LFO2.setAttribute(LFO2.LFOSyncMode, value);

	if(value == 1)
	    	{
	for(s in LfoClk2)
		         s.showControl(0);
		         
	Speed2.showControl(1);        
	}
	
	if(value == 2)
	    	{
	for(s in LfoClk2)
		         s.showControl(1);
		         
	Speed2.showControl(0);        
	}
	
	if(value == 3)
	    	{
	for(s in LfoClk2)
		         s.showControl(1);
		         
	Speed2.showControl(0);        
	}
	
};

Content.getComponent("LfoSync2").setControlCallback(onLfoSync2Control);

//Slot4 
  

  function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 