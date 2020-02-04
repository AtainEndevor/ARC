void drawPhasePage() {
  page = 12;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(BigFont);
  
  mainDisplay.print("Set start time", CENTER, 34);
  mainDisplay.print("Hour", CENTER, 96);
  mainDisplay.print("Minute", CENTER, 152);
  
  addOneHourButton = inputButtons.addButton( 186, 118,  32, 26, ">");
  mainDisplay.printNumI(TIMING[displayPhase][0], CENTER, 122);
  subOneHourButton = inputButtons.addButton( 100, 118,  32, 26, "<");
  
  addOneMinButton = inputButtons.addButton( 186, 172,  32, 26, ">");
  mainDisplay.printNumI(TIMING[displayPhase][1], CENTER, 178);
  subOneMinButton = inputButtons.addButton( 100, 172,  32, 26, "<");
  
  returnButton = inputButtons.addButton( 126, 58, 65, 32, "Back");
  
  drawToolbar();
}
