namespace TableLookAndFeel
{
	

const var table_laf = Content.createLocalLookAndFeel();



const var modComponentList = {};

for(t in matrix.getTargetList())
{
	modComponentList[t] = Content.getComponent(matrix.getComponentId(t));
}


table_laf.registerFunction("drawTableCell", function(g, obj)
{
	var isMatrixRow = obj.area[2] == 130;
	
	
	
	
	
	 g.setFont("Arial", 13.0);
	 
	 var c = MOD_COLOURS[obj.text];
	 
	 if(!isDefined(c))
	 	c = 0x99FFFFFF;
	 
	 c = Colours.mix(c, Colours.black, 1);
	 
	 g.setColour(c);
	 
	 if(isMatrixRow)
 	{
 		var modValue = matrix.getModValue(matrix.getComponentId(obj.text));
 		var componentValue = modComponentList[obj.text].getValueNormalized();
 		
 		
 		var r = Rect.removeFromBottom(obj.area, 7);
 		
 		
 		
 		g.drawRect(r, 1.0);
 		
 		g.fillRect([r[2] * componentValue - 2, r[1], 4, r[3]]);
 		
 		g.fillRect([r[2] * modValue - 2, r[1], 4, r[3]]);
 		
 		
 		//g.fillRect(Rect.removeFromLeft(r, r[2] * modValue));
 		
 	}
	 
	 

	 g.drawAlignedText(obj.text, obj.area, "left");
});

table_laf.registerFunction("drawToggleButton", function(g, obj)
{
	 var alpha = 0.5;
	 
	 if(obj.over)
	 	alpha += 0.1;
	 
	 g.setColour(Colours.withAlpha(Colours.black, alpha));
	 
	 if(obj.text == "Delete")
	 {
		 var cp = Content.createPath();
		 cp.startNewSubPath(0.0, 0.0);
		 cp.lineTo(1.0, 1.0);
		 cp.startNewSubPath(1.0, 0.0);
		 cp.lineTo(0.0, 1.0);
		 
		 g.drawPath(cp, Rect.withSizeKeepingCentre(obj.area, 15, 15), 3);
		 
		 return;
	 }
	 
	 
	 g.drawRect(Rect.withSizeKeepingCentre(obj.area, 12, 12), 1);
	 
	 if(obj.value)
	 {
		 g.fillRect(Rect.withSizeKeepingCentre(obj.area, 8, 8));
	 }
	 
});

table_laf.registerFunction("drawComboBox", function(g, obj)
{
	g.setColour(Colours.withAlpha(Colours.black, obj.hover ? 1.0 : 0.9));
	g.setFont("Lato Bold", 13.0);


	
	g.drawAlignedText(obj.text, obj.area, "left");
	

	

	
});

table_laf.registerFunction("drawRotarySlider", function(g, obj)
{
	var isPitch = obj.min == -12.0;
	var isPan = obj.min == -100.0;

	g.setColour(0x11FFFFFF);


	
	
	g.drawRect(obj.area, 1);

	g.setFont("Arial", 13.0);
	

	

	
	
	if(obj.min < 0)
	{
		if(obj.valueNormalized < 0.5)
		{


		}
		else
		{

			valueRect = Rect.removeFromLeft(valueRect, obj.area[2] * (obj.valueNormalized - 0.5));
		}
	}
	else
	{

	}
	
	
	var alpha = 0.2;
	
	if(obj.value != 0.0)
		alpha += 0.6;
		
	if(obj.hover)
		alpha += 0.1;
	
	g.setColour(Colours.withAlpha(Colours.black, alpha));

	

	

});




Content.getComponent("Viewport1").setLocalLookAndFeel(table_laf);

}