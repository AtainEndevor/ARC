void drawToolbar() {
  
  //Top Bar
  mainDisplay.setColor(VGA_GRAY);
  mainDisplay.fillRoundRect(0,0,319,28);
  
  homeButton     = inputButtons.addButton(   1, 212,  80, 26, "9", BUTTON_SYMBOL);
  settingsButton = inputButtons.addButton(  81, 212,  79, 26, "w", BUTTON_SYMBOL);
  alertButton    = inputButtons.addButton( 160, 212,  79, 26, "W", BUTTON_SYMBOL);
  powerButton    = inputButtons.addButton( 239, 212,  80, 26, "4", BUTTON_SYMBOL);
  
  if(page == 0)
    inputButtons.disableButton(homeButton);

  if(page == 1){
    backButton	 = inputButtons.addButton(   1,   1,  26, 26, "<");
    mainDisplay.setColor(VGA_WHITE);
    mainDisplay.setBackColor(VGA_BLACK);
    mainDisplay.setFont(SmallFont);
    setPhaseButton();
    nextButton   = inputButtons.addButton( 106,   1,  26, 26, ">");
  }
  
  char t [17];
  int j = sprintf (t, "%02u/%02u/%u %02u:%02u:%02u", month(), day(), year(), hour(), minute(), second());
  
  timeButton     = inputButtons.addButton( 160,   1, 158, 26, t);

  inputButtons.drawButtons();
}

