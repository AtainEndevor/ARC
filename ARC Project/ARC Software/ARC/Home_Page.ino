void drawHomePage() {
  page = 0;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  lightingButton = inputButtons.addButton( 0,  31, 100, 34, "LIGHTING");
  dosingButton   = inputButtons.addButton( 0,  67, 100, 34, "QUALITY");
  devicesButton  = inputButtons.addButton( 0, 103, 100, 34, "DEVICES");
  logButton      = inputButtons.addButton( 0, 139, 100, 34, "LOG BOOK");
  aboutButton    = inputButtons.addButton( 0, 175, 100, 34, "ABOUT");
  
  drawToolbar();
}
