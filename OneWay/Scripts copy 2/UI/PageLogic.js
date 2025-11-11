namespace PageLogic
{
	const var Panel2 = Content.getComponent("Panel2");
	
	
	
	const var menuButtonLaf = Content.createLocalLookAndFeel();
	

	const var menuButtons = [Content.getComponent("Button1"), 
	                         Content.getComponent("Button2"), 
	                         Content.getComponent("Button3")];
	
	inline function onMenuButton(component, value)
	{
		if(!value)
			return;
		
		local idx = menuButtons.indexOf(component);
		
		if(idx == 0)
			Engine.undo();
		else if(idx == 1)
			Engine.redo();
		else if(idx == 2)
			matrix.clearAllConnections();
	}
	
	for(c in menuButtons)
	{
		c.set("isMomentary", true);
		c.setLocalLookAndFeel(menuButtonLaf);
		c.set("saveInPreset", false);
		c.setControlCallback(onMenuButton);
	}
	    
	

	


}