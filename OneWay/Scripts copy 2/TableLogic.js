namespace TableLogic
{
	
const var ModTable = Content.getComponent("Viewport1");

ModTable.setTableMode({
	"MultiColumnMode": false,
	"HeaderHeight": 32,
	"RowHeight": 32,
	"ScrollOnDrag": false
});

ModTable.setTableColumns([
{
	"ID": "Source",
	"Type": "Text",
	"MinWidth": 50
},
{
	"ID": "Target",
	"Type": "Text",
	"MinWidth": 50
},
{
	"ID": "Intensity",
	"Type": "Slider",
	"MinWidth": 80
},
{
	"ID": "Mode",
	"Type": "ComboBox",
	"MinWidth": 60,
	"Toggle": true,
	"Text": "Default",
	"ValueMode": "Text"
},


]);

ModTable.setTableCallback(function(obj)
{
	if(obj.Type == "ComboBox" && obj.columnID == "Mode")
	{
		var rowData = currentTableData[obj.rowIndex];
		matrix.updateValueMode(rowData.Source, rowData.Target, obj.value);
		ModTable.sendRepaintMessage();
		return;
	}
	

	if(obj.Type == "Button" && obj.columnID.substring(0, 4) == "Show")
	{
		if(obj.value)
			return;
		
		if(obj.columnID == "ShowSource")
		{
			Console.print("Goto Source " + trace(currentTableData[obj.rowIndex].Source));
		}
		if(obj.columnID == "ShowTarget")
		{
			Console.print("Goto Target " + trace(currentTableData[obj.rowIndex].Target));
		}

		return;
	}

	if((obj.columnID == "Delete" && obj.value))
		return;
	
	if((obj.columnID == "Delete" && !obj.value) || obj.Type == "DeleteRow")
	{

		var rowData = currentTableData[obj.rowIndex];
		matrix.connect(rowData.Source, rowData.Target, false);
		return;
	}

	if(obj.Type == "Slider")
	{
		var rowData = currentTableData[obj.rowIndex];
		matrix.updateIntensity(rowData.Source, rowData.Target, obj.value);
		return;
	}
	if(obj.Type == "Button" && obj.columnID == "Inverted")
	{
		
		var rowData = currentTableData[obj.rowIndex];
		rowData[obj.columnID] = obj.value;
		rowData.Intensity = rowData.Intensity.Value;
		
		matrix.updateConnectionData(rowData);
	}
});

reg currentTableData = [];

inline function onMatrixRestore(component, value)
{
	if(value.length == 1)
	{
		matrix.fromBase64(value[0]);
	}
}



ModTable.setControlCallback(onMatrixRestore);



inline function matrixRowCallback(obj)
{
	local target = matrix.getTargetList()[obj.rowIndex];
	local source = obj.columnID;
	
	local active = Math.abs(obj.value) > 0.01;

	if(matrix.connect(source, target, active))
	{
		matrix.updateIntensity(source, target, obj.value);
	}
	else
	{
		matrix.fromBase64(matrix.toBase64());
	}	
}

const var SHORT_NAMES = {
	"Velocity": "Velo",
	"Notenumber": "Note",
	"Random": "Random",
	"LFO 1": "LFO 1",
	"LFO 2": "LFO 2",
	"AHDSR 1": "AHDSR 1",
	"AHDSR 2": "AHDSR 2",
	"CC": "CC",
	"Pitchwheel": "Pitch"
};


	
	

	


const var matrixBroadcaster = Engine.createBroadcaster({
	"id": "matrixBroadcaster",
	"args": ["source", "target", "eventType"],
});

matrixBroadcaster.setEnableQueue(true);


matrix.setConnectionCallback(matrixBroadcaster);



matrixBroadcaster.addListener(ModTable, "rebuild table", function(u1, u2, eventType)
{
	currentTableData = matrix.getConnectionData("");
			
	for(s in currentTableData)
	{
		s.Delete = false;
		s.ShowSource = false;
		s.ShowTarget = false;
		s.Intensity = matrix.getIntensitySliderData(s.Source, s.Target);
		s.Intensity.style = "Knob";
		
		s.Mode = matrix.getValueModeData(s.Source, s.Target);
		
		s.Bipolar = s.Mode == matrix.Bipolar;
	}
	
	//Console.print(trace(currentTableData));
	
		
	this.setTableRowData(currentTableData);
});

matrixBroadcaster.addListener(ModTable, "store data", function(u1, u2, eventType)
{
	if(eventType == matrix.Rebuild)
		return;

	if(eventType == matrix.Update)
		this.sendRepaintMessage();

	this.setValue([matrix.toBase64()]);
});


	

}