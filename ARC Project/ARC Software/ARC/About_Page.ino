void drawAboutPage() {
  page = 5;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(BigFont);
  mainDisplay.print("Created by:", CENTER, 60);
  mainDisplay.print("AlsipainReefs",CENTER,80);
  mainDisplay.print("Software Version:", CENTER, 110);
  mainDisplay.print("1.0",CENTER,130);
  mainDisplay.print("AlsipianReefs.com",CENTER, 160);
  
  drawToolbar();
}
