namespace DragPanel
{
//	const var Panel1 = Content.getComponent("DragPanel");
	
//	Panel1.data.sources = matrix.getSourceList();
	
	
	
	const var dragPath = Content.createPath();
	dragPath.loadFromData("228.t0FDlHBQvpTkCwFDlHBQ..abCwFVRnAQ..abCwFd+YBQPE.PCwFZrKCQ..abCwF4XqBQ..abCwF4XqBQvpTkCwFzQjCQvpTkCwFzQjCQ.RRgCwF..VDQ..fmCwFzQjCQfcssCwFzQjCQvDqoCwF4XqBQvDqoCwF4XqBQXOxvCwFZrKCQXOxvCwFd+YBQn8+1CwFVRnAQXOxvCwFDlHBQXOxvCwFDlHBQvDqoCwF7rOAQvDqoCwF7rOAQfcssCwF..d.Q..fmCwF7rOAQ.RRgCwF7rOAQvpTkCwFDlHBQvpTkCMVY");
	
	inline function paintSnapShot(g, obj)
	{
		local c = Rect.reduced(obj.area, obj.valid ? 2 : 3);
		
		g.setColour(0x99111111);
		g.fillRoundedRectangle(c, c[3]/2);
		g.setColour(obj.valid ? Colours.white : 0xaaffffff);
		g.drawRoundedRectangle(c, c[3]/2, 1);
		g.setFont("Lato Bold", 12.0);
		
		Rect.removeFromLeft(obj.area, obj.area[3]/2 - 3);
		
		local t = isDefined(obj.sourceMod) ? obj.sourceMod : this.data.source;
		
		t = TableLogic.SHORT_NAMES[t];	
		
		g.drawAlignedText(t, obj.area, "left");	
			
		local pathArea = Rect.removeFromRight(obj.area, obj.area[3]);
		pathArea = Rect.withSizeKeepingCentre(pathArea, 14, 14);
			
		g.fillPath(dragPath, pathArea);
		
	}
	
	
	
	
	inline function isValidDrag(target)
	{
		local v = matrix.canConnect(this.data.source, matrix.getTargetId(target));
		return v;
	};
	
	inline function onModulationDrag(valid, target)
	{
		if(valid)
		{
			local targetId = matrix.getTargetId(target);
				
			if(targetId.length > 0)
			{
				local source = matrix.getSourceList()[this.data.dragIndex];
				matrix.connect(source, targetId, true);
			}
		}
	
		this.setMouseCursor("PointingHandCursor", Colours.white, [0, 0]);
	}
	

}