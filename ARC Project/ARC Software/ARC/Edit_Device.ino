void editDevice(int num) {
  page = 31;
  mainDisplay.clrScr();
  inputButtons.deleteAllButtons();
  curDevEdit = num;
  
  mainDisplay.setFont(BigFont);
  
  switch(deviceOptions[curDevEdit-1][0]) {
    case 1:
      mainDisplay.setColor(VGA_WHITE);
      mainDisplay.print("Sec(s)", RIGHT, 76);
      mainDisplay.printNumI(deviceOptions[curDevEdit-1][1], CENTER, 76);
      mainDisplay.setColor(VGA_GRAY);
      mainDisplay.print("Time", RIGHT, 112);
      mainDisplay.printNumI(deviceOptions[curDevEdit-1][2], CENTER, 112);
      switch(deviceOptions[curDevEdit-1][3]) {
        case 1: mainDisplay.print("Sun", CENTER, 148); break;
        case 2: mainDisplay.print("Mon", CENTER, 148); break;
        case 3: mainDisplay.print("Tue", CENTER, 148); break;
        case 4: mainDisplay.print("Wed", CENTER, 148); break;
        case 5: mainDisplay.print("Thur", CENTER, 148); break;
        case 6: mainDisplay.print("Fri", CENTER, 148); break;
        case 7: mainDisplay.print("Sat", CENTER, 148); break;}
      mainDisplay.printNumI(deviceOptions[curDevEdit-1][4], RIGHT, 148);
    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
    break;
  }
  
  
  
  if(deviceStatus[num-1]) {
    timerButton   = inputButtons.addButton(   0,  31, 100, 34, "ON");
    freqButton    = inputButtons.addButton(   0,  67, 100, 34, "Frequency");
    dailyButton   = inputButtons.addButton(   0, 103, 100, 34, "Daily");
    weeklyButton  = inputButtons.addButton(   0, 139, 100, 34, "Weekly");
    monthlyButton = inputButtons.addButton(   0, 175, 100, 34, "Monthly");
    addFreqButton = inputButtons.addButton( 102,  67,  26, 34, "<");
    addTimeButton = inputButtons.addButton( 102, 103,  26, 34, "<");
    addDayButton  = inputButtons.addButton( 102, 139,  26, 34, "<");
    addDateButton = inputButtons.addButton( 102, 175,  26, 34, "<");
    subFreqButton = inputButtons.addButton( 177,  67,  26, 34, ">");
    subTimeButton = inputButtons.addButton( 177, 103,  26, 34, ">");
    subDayButton  = inputButtons.addButton( 177, 139,  26, 34, ">");
    subDateButton = inputButtons.addButton( 177, 175,  26, 34, ">");
    
    //subFreqButton, addTimeButton, subTimeButton, addDayButton, subDayButton,
    //addDTimeButton, subDTimeButton, addDateButton, subDateButton, addMTimeButton, subMTimeButton;
    
  } else {
    timerButton   = inputButtons.addButton(   0,  31, 100, 34, "OFF");
    freqButton    = inputButtons.addButton(   0,  67, 100, 34, "Frequency", BUTTON_DISABLED);
    dailyButton   = inputButtons.addButton(   0, 103, 100, 34, "Daily", BUTTON_DISABLED);
    weeklyButton  = inputButtons.addButton(   0, 139, 100, 34, "Weekly", BUTTON_DISABLED);
    monthlyButton = inputButtons.addButton(   0, 175, 100, 34, "Monthly", BUTTON_DISABLED);
    addFreqButton = inputButtons.addButton( 102,  67,  26, 34, "<", BUTTON_DISABLED);
    addTimeButton = inputButtons.addButton( 102, 103,  26, 34, "<", BUTTON_DISABLED);
    addDayButton  = inputButtons.addButton( 102, 139,  26, 34, "<", BUTTON_DISABLED);
    addDateButton = inputButtons.addButton( 102, 175,  26, 34, "<", BUTTON_DISABLED);
    subFreqButton = inputButtons.addButton( 192,  67,  26, 34, ">", BUTTON_DISABLED);
    subTimeButton = inputButtons.addButton( 192, 103,  26, 34, ">", BUTTON_DISABLED);
    subDayButton  = inputButtons.addButton( 192, 139,  26, 34, ">", BUTTON_DISABLED);
    subDateButton = inputButtons.addButton( 192, 175,  26, 34, ">", BUTTON_DISABLED);
  }
  
  drawToolbar();
}
