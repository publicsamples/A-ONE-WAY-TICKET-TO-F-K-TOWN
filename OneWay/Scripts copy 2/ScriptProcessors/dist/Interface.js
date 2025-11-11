Content.makeFrontInterface(540, 350);


const var MetaScreens = [];


MetaScreens[0] = Content.getComponent("TABLE");
MetaScreens[1] = Content.getComponent("ScriptSliderPack1");
MetaScreens[2] = Content.getComponent("AudioWaveform1");
MetaScreens[3] = Content.getComponent("Xmod");

const var crush = Synth.getEffect("crush");

inline function onModesControl(component, value)
{
 crush.setAttribute(crush.ModeSelect, value-1);
 
 for (i = 0; i < MetaScreens.length; i++)
        MetaScreens[i].showControl(value - 1 == i);
	

};

Content.getComponent("Modes").setControlCallback(onModesControl);

const var ScriptFloatingTile1 = Content.getComponent("ScriptFloatingTile1");
const var Panel1 = Content.getComponent("Panel1");




inline function onPresetsControl(component, value)
{
	ScriptFloatingTile1.showControl(value);
	Panel1.showControl(1-value);
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);
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
 