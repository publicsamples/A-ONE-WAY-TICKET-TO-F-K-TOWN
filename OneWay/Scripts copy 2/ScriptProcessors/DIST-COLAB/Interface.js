Content.makeFrontInterface(720, 650);


include("UI/RectHelpers.js");
 
 
 const var FileShaperDrive = Content.getComponent("FileShaperDrive");
 

 
 Synth.setUseUniformVoiceHandler("DIST-COLAB", true);
 
 const var matrix = Engine.createModulationMatrix("Global Modulator Container1");
 
 matrix.setUseUndoManager(true);
 
 matrix.setEditCallback(function(name)
 {
 	
 });
 
//FIleShaper

 matrix.addParameterTarget({
 	"Target": "FileShape",
 	"Parameter": "Drive1",
 	"ID": "FsDrive",
 	"Component": "FileShaperDrive",
 	"Mode": matrix.Bipolar
 });
 
 matrix.addParameterTarget({
 	"Target": "FileShape",
 	"Parameter": "FileMix",
 	"ID": "FsMix",
 	"Component": "FileShaperMix",
 	"Mode": matrix.Bipolar
 });
 
 
 matrix.addParameterTarget({
 	"Target": "FileShape",
 	"Parameter": "Smooth",
 	"ID": "FsSmooth",
 	"Component": "FileShaperSmooth",
 	"Mode": matrix.Bipolar
 });
 

 //Modifier
 
 matrix.addParameterTarget({
 	"Target": "Modifier",
 	"Parameter": "mix",
 	"ID": "DrvMix",
 	"Component": "DrvMix",
 	"Mode": matrix.Bipolar
 });
 
 
 matrix.addParameterTarget({
 	"Target": "Modifier",
 	"Parameter": "FX",
 	"ID": "DrvFX",
 	"Component": "DrvFX",
 	"Mode": matrix.Bipolar
 });
 

 
 
 
 //Filter
 
 matrix.addParameterTarget({
 	"Target": "Filter",
 	"Parameter": "Mix",
 	"ID": "FilterMix",
 	"Component": "FilterMix",
 	"Mode": matrix.Bipolar
 });
 
 matrix.addParameterTarget({
 	"Target": "Filter",
 	"Parameter": "CutOffset",
 	"ID": "FilterCut",
 	"Component": "FilterCut",
 	"Mode": matrix.Bipolar
 });
 
 matrix.addParameterTarget({
 	"Target": "Filter",
 	"Parameter": "Res",
 	"ID": "FilterRes",
 	"Component": "FilterRes",
 	"Mode": matrix.Bipolar
 });
 
 matrix.addParameterTarget({
 	"Target": "Clip",
 	"Parameter": "Mix",
 	"ID": "ClipMix",
 	"Component": "ClipMix",
 	"Mode": matrix.Bipolar
 });
 
 
 matrix.addParameterTarget({
 "Target": "Clip",
 "Parameter": "Clip",
 "ID": "Clip",
 "Component": "Clip",
 "Mode": matrix.Bipolar
  });
  
  matrix.addParameterTarget({
  "Target": "Filter2",
  "Parameter": "Mix",
  "ID": "Filter2Mix",
  "Component": "Filter2Mix",
  "Mode": matrix.Bipolar
   });
   
   matrix.addParameterTarget({
   "Target": "Filter2",
   "Parameter": "Cut",
   "ID": "Filter2Cut",
   "Component": "Filter2Cut",
   "Mode": matrix.Bipolar
    });
    
    matrix.addParameterTarget({
    "Target": "Filter2",
    "Parameter": "Res",
    "ID": "Filter2Res",
    "Component": "Filter2Res",
    "Mode": matrix.Bipolar
     });
     
     matrix.addParameterTarget({
     "Target": "Simple Gain1",
     "Parameter": "Gain",
     "ID": "InputGain",
     "Component": "InputGain",
     "Mode": matrix.Bipolar
      });
      
  
      
 
 include("TableLogic.js");
include("UI/TableLookAndFeel.js");
//include("UI/KnobLookAndFeel.js");
// include("UI/DragPanel.js");
 include("UI/PageLogic.js");

 
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
 