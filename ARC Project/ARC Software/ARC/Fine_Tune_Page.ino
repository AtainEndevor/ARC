void fineTuneColor(int value) {
  page = 11;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  selectedColor = value;
  switch(value) {
    case 0: mainDisplay.setColor(255, 0, 255);   break;
    case 1: mainDisplay.setColor(0, 0, 128);     break;
    case 2: mainDisplay.setColor(0, 0, 255);     break;
    case 3: mainDisplay.setColor(0, 255, 255);   break;
    case 4: mainDisplay.setColor(0, 255, 0);     break;
    case 5: mainDisplay.setColor(255, 0, 0);     break;
    case 6: mainDisplay.setColor(255, 255, 255); break;
    case 7: mainDisplay.setColor(255, 220, 148); break;
  }
    
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(BigFont);
  mainDisplay.print(colors[value], CENTER, 34);
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.printNumI(LEDLIMS[displayPhase][value], CENTER, 122);
  mainDisplay.printNumI(LEDOFFSETS [displayPhase][value], CENTER, 178);
  mainDisplay.print("Value", CENTER, 96);
  mainDisplay.print("Offset", CENTER, 152);
  
  addOneButton = inputButtons.addButton( 186, 118,  32, 26, ">");
  addTenButton = inputButtons.addButton( 220, 118,  32, 26, "+10");
  subOneButton = inputButtons.addButton( 100, 118,  32, 26, "<");
  subTenButton = inputButtons.addButton(  66, 118,  32, 26, "-10");
  
  addOneOffButton = inputButtons.addButton( 186, 172,  32, 26, ">");
  subOneOffButton = inputButtons.addButton( 100, 172,  32, 26, "<");
  
  returnButton = inputButtons.addButton( 126, 58, 65, 32, "Back");
  
  drawToolbar();
}
