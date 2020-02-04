void drawLightingPage() {
  page = 1;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();

  drawSliders();
  
  if(fineTune)
    fineTuneButton = inputButtons.addButton(1, 31, 32, 32, "FT");
  else
    fineTuneButton = inputButtons.addButton(1, 31, 32, 32, "GT");
  
  if(lock)
    lockButton = inputButtons.addButton(1, 177, 32, 32, "Y", BUTTON_SYMBOL);
  else
    lockButton = inputButtons.addButton(1, 177, 32, 32, "Z", BUTTON_SYMBOL);
    
  drawToolbar();
}
