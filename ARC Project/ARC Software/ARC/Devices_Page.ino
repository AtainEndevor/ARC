void drawDevicesPage() {
  page = 3;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(SmallFont);
  
  
  if(deviceStatus[0])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(2,52,80,67);
  D1 = inputButtons.addButton(  1,  67, 80, 34, "DEVICE 1");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 2, 102);
  
  if(deviceStatus[1])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(82,52,159,67);
  D2 = inputButtons.addButton( 81,  67, 79, 34, "DEVICE 2");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 82, 102);
  
  if(deviceStatus[2])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(161,52,238,67);
  D3 = inputButtons.addButton(160,  67, 79, 34, "DEVICE 3");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 161, 102);
  
  if(deviceStatus[3])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(240,52,318,67);
  D4 = inputButtons.addButton(239,  67, 80, 34, "DEVICE 4");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 240, 102);
  
  
  
  if(deviceStatus[4])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(2,124,80,139);
  D5 = inputButtons.addButton(  1, 139, 80, 34, "DEVICE 5");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 2, 174);
  
  if(deviceStatus[5])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(82,124,159,139);
  D6 = inputButtons.addButton( 81, 139, 79, 34, "DEVICE 6");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 82, 174);
  
  if(deviceStatus[6])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(161,124,238,139);
  D7 = inputButtons.addButton(160, 139, 79, 34, "DEVICE 7");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 161, 174);
  
  if(deviceStatus[7])
    mainDisplay.setColor(VGA_LIME);
  else
    mainDisplay.setColor(VGA_RED);
  mainDisplay.fillRect(240,124,318,139);
  D8 = inputButtons.addButton(239, 139, 80, 34, "DEVICE 8");
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.print(deviceMSG[0], 240, 174);
  
  
  
  drawToolbar();
}
