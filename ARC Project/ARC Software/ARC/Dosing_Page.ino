void drawDosingPage() {
  page = 2;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.print("Coming Soon", CENTER, 110);
  
  drawToolbar();
}
