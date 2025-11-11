namespace Rect
{
	inline function reduced(area, amount)
	{
		return [ area[0] + amount, 
				 area[1] + amount, 
				 area[2] - 2 * amount, 
				 area[3] - 2 * amount];
	}
	

	


	
	inline function withSizeKeepingCentre(area, width, height)
	{
		return [ area[0] + (area[2] - width) / 2, 
				 area[1] + (area[3] - height) / 2, 
				 width, 
				 height];
	}
	
	inline function removeFromLeft(area, amount)
	{
		area[0] += amount;
		area[2] -= amount;
		return [area[0] - amount, area[1], amount, area[3]];
	}
	
	inline function removeFromRight(area, amount)
	{
		area[2] -= amount;
		return [area[0] + area[2], area[1], amount, area[3]];
	}
	
	inline function removeFromTop(area, amount)
	{
		area[1] += amount;
		area[3] -= amount;
		return [area[0], area[1] - amount, area[2], amount];
	}
	
	inline function scale(area, scaleFactor)
	{
		local newArea = [];
		newArea.reserve(4);
		
		for(a in area)
			newArea.push(a * scaleFactor);
			
		return newArea;
	}
	
	inline function removeFromBottom(area, amount)
	{
		
	

		area[3] -= amount;

		return [area[0], area[1] + area[3], area[2], amount];
	
	}
	

	

	}
}