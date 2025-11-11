Content.makeFrontInterface(880, 620);

const var ShapeModes1 = [];

ShapeModes1[0] = Content.getComponent("Table1");
ShapeModes1[1] = Content.getComponent("ScriptSliderPack1");
ShapeModes1[2] = Content.getComponent("ScriptAudioWaveform1");

const var Stages1 = Content.getComponent("Stages1");
const var Stages2 = Content.getComponent("Stages2");

const var Crusher = Synth.getEffect("Crusher");

inline function onShapeMode1Control(component, value)
{
	Crusher.setAttribute(Crusher.ShaperMode1, value-1);

 for (i = 0; i < ShapeModes1.length; i++)
        ShapeModes1[i].showControl(value - 1 == i);
        
        if(value == 2)
        {
	Stages1.showControl(1);
	}
	
else if (value)
	{
		Stages1.showControl(0);
	}


};

Content.getComponent("ShapeMode1").setControlCallback(onShapeMode1Control);

const var ShapeModes2 = [];

ShapeModes2[0] = Content.getComponent("Table2");
ShapeModes2[1] = Content.getComponent("ScriptSliderPack2");
ShapeModes2[2] = Content.getComponent("ScriptAudioWaveform2");

inline function onShapeMode2Control(component, value)
{
	Crusher.setAttribute(Crusher.ShaperMode2, value-1);

 for (i = 0; i < ShapeModes2.length; i++)
        ShapeModes2[i].showControl(value - 1 == i);
        
        if(value == 2)
             {
        	Stages2.showControl(1);
        	}
        	
        else if (value)
        	{
        		Stages2.showControl(0);
        	}
        
};

Content.getComponent("ShapeMode2").setControlCallback(onShapeMode2Control);

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
 