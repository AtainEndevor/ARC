void updateGUI() {
  if (inputTouch.dataAvailable() == true)
  {
    
    switch(page) {

      case 0: //Home Page
        pressedButton = inputButtons.checkButtons();
        if(pressedButton == lightingButton)
          drawLightingPage();
        if(pressedButton == dosingButton)
          drawDosingPage();
        if(pressedButton == devicesButton)
          drawDevicesPage();
        if(pressedButton == logButton)
          drawLogPage();
        if(pressedButton == aboutButton)
          drawAboutPage();
      break;
      
      
      
      
      case 1:
        inputTouch.read();
          if((inputTouch.getY() >= 30) && (inputTouch.getY() <= 208) && !lock) {
            if((inputTouch.getX() >=  22) && (inputTouch.getX() <=  54)){
              if(fineTune) {
                fineTuneColor(0);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][0] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >=  60) && (inputTouch.getX() <=  92)){
              if(fineTune) {
                fineTuneColor(1);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][1] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >=  98) && (inputTouch.getX() <= 130)){
              if(fineTune) {
                fineTuneColor(2);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][2] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >= 136) && (inputTouch.getX() <= 168)){
              if(fineTune) {
                fineTuneColor(3);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][3] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >= 174) && (inputTouch.getX() <= 206)){
              if(fineTune) {
                fineTuneColor(4);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][4] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >= 212) && (inputTouch.getX() <= 244)){
              if(fineTune) {
                fineTuneColor(5);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][5] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >= 250) && (inputTouch.getX() <= 282)){
              if(fineTune) {
                fineTuneColor(6);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][6] = (((inputTouch.getY()-208) * 51) / -35);
            }
            if((inputTouch.getX() >= 288) && (inputTouch.getX() <= 320)){
              if(fineTune) {
                fineTuneColor(7);
                page = 11;
                break;
              } else
                LEDLIMS[displayPhase][7] = (((inputTouch.getY()-208) * 51) / -35);
            }
          }
          
          pressedButton = inputButtons.checkButtons();
          
          if(pressedButton == fineTuneButton) {
            fineTune = !fineTune;
            if(fineTune)
              inputButtons.relabelButton(fineTuneButton, "FT", true);
            else
              inputButtons.relabelButton(fineTuneButton, "GT", true);
          }
          
          if(pressedButton == lockButton) {
            lock = !lock;
            if(lock)
              inputButtons.relabelButton(lockButton, "Y", true);
            else
              inputButtons.relabelButton(lockButton, "Z", true);
          }
          
          if(pressedButton == nextButton) {
            displayPhase ++;
            if(displayPhase == 10)
              displayPhase = 0;
            relabelPhaseButton();
          }
          
          if(pressedButton == phaseButton) {
            drawPhasePage();
            break;
          }
          
          if(pressedButton == backButton) {
            displayPhase --;
            if(displayPhase == -1)
              displayPhase = 9;
            relabelPhaseButton();
          }
          
          if(page = 1)
            drawSliders();
          
      break;
      
      
      
      
      case 11:
      pressedButton = inputButtons.checkButtons();
      
        if(pressedButton == addOneButton) {
          LEDLIMS[displayPhase][selectedColor] ++;
          if(LEDLIMS[displayPhase][selectedColor] == 256)
            LEDLIMS[displayPhase][selectedColor] = 0;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(LEDLIMS[displayPhase][selectedColor], CENTER, 122);
        }
        
        if(pressedButton == subOneButton) {
          LEDLIMS[displayPhase][selectedColor] --;
          if(LEDLIMS[displayPhase][selectedColor] == -1)
            LEDLIMS[displayPhase][selectedColor] = 255;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(LEDLIMS[displayPhase][selectedColor], CENTER, 122);
        }
        
        if(pressedButton == addTenButton) {
          LEDLIMS[displayPhase][selectedColor] = LEDLIMS[displayPhase][selectedColor] + 10;
          if(LEDLIMS[displayPhase][selectedColor] >= 256)
            LEDLIMS[displayPhase][selectedColor] = 0;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(LEDLIMS[displayPhase][selectedColor], CENTER, 122);
        }
        
        if(pressedButton == subTenButton) {
          LEDLIMS[displayPhase][selectedColor] = LEDLIMS[displayPhase][selectedColor] - 10;
          if(LEDLIMS[displayPhase][selectedColor] <= -1)
            LEDLIMS[displayPhase][selectedColor] = 255;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(LEDLIMS[displayPhase][selectedColor], CENTER, 122);
        }
        
        if(pressedButton == addOneOffButton) {
          LEDOFFSETS[displayPhase][selectedColor] ++;
          if(LEDOFFSETS[displayPhase][selectedColor] >= 26)
            LEDOFFSETS[displayPhase][selectedColor] = 0;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 178);
          mainDisplay.printNumI(LEDOFFSETS[displayPhase][selectedColor], CENTER, 178);
        }
        
        if(pressedButton == subOneOffButton) {
          LEDOFFSETS[displayPhase][selectedColor] --;
          if(LEDOFFSETS[displayPhase][selectedColor] <= -1)
            LEDOFFSETS[displayPhase][selectedColor] = 25;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 178);
          mainDisplay.printNumI(LEDOFFSETS[displayPhase][selectedColor], CENTER, 178);
        }
        
        if(pressedButton == returnButton) {
          drawLightingPage();
          page = 1;
          break;
        }
        
      break;
      
      
      
      
      
      case 12:
      
        pressedButton = inputButtons.checkButtons();
      
        if(pressedButton == returnButton) {
          drawLightingPage();
          page = 1;
          break;
        }
        
        if(pressedButton == addOneHourButton) {
          TIMING[displayPhase][0] ++;
          if(TIMING[displayPhase][0] == 24)
            TIMING[displayPhase][0] = 0;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(TIMING[displayPhase][0], CENTER, 122);
        }
        
        if(pressedButton == subOneHourButton) {
          TIMING[displayPhase][0] --;
          if(TIMING[displayPhase][0] == -1)
            TIMING[displayPhase][0] = 23;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 122);
          mainDisplay.printNumI(TIMING[displayPhase][0], CENTER, 122);
        }
        
        if(pressedButton == addOneMinButton) {
          TIMING[displayPhase][1] ++;
          if(TIMING[displayPhase][1] == 60)
            TIMING[displayPhase][1] = 0;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 178);
          mainDisplay.printNumI(TIMING[displayPhase][1], CENTER, 178);
        }
        
        if(pressedButton == subOneMinButton) {
          TIMING[displayPhase][1] --;
          if(TIMING[displayPhase][1] == -1)
            TIMING[displayPhase][1] = 59;
          mainDisplay.setColor(VGA_WHITE);
          mainDisplay.setBackColor(VGA_BLACK);
          mainDisplay.setFont(BigFont);
          mainDisplay.print("   ", CENTER, 178);
          mainDisplay.printNumI(TIMING[displayPhase][1], CENTER, 178);
        }
      
      break;
      
      
      
      
      
      case 2:
      pressedButton = inputButtons.checkButtons(); 
      break;
      
      
      
      
      case 3:
      pressedButton = inputButtons.checkButtons();
      
      if(pressedButton == D1){
        editDevice(1);
        break;
      }
      if(pressedButton == D2){
        editDevice(2);
        break;
      }
      if(pressedButton == D3){
        editDevice(3);
        break;
      }
      if(pressedButton == D4){
        editDevice(4);
        break;
      }
      if(pressedButton == D5){
        editDevice(5);
        break;
      }
      if(pressedButton == D6){
        editDevice(6);
        break;
      }
      if(pressedButton == D7){
        editDevice(7);
        break;
      }
      if(pressedButton == D8){
        editDevice(8);
        break;
      }
      break;
      
      
      
      
      case 31:
      pressedButton = inputButtons.checkButtons();
      
      if(pressedButton == timerButton){
        deviceStatus[curDevEdit-1] = !deviceStatus[curDevEdit-1];
        editDevice(curDevEdit);
      }
        
      break;
      
      
      
      
      case 4:
      pressedButton = inputButtons.checkButtons();
      break;
      
      
      
      
      case 5:
      pressedButton = inputButtons.checkButtons();
      break;
    }
    
    if(pressedButton == homeButton)
      drawHomePage();
//    if(pressedButton == settingsButton)
//      drawSettingsPage();
//    if(pressedButton == alertButton)
//      drawAlertPage();
//    if(pressedButton == powerButton)
//      //Power function here.
//    if(pressedButton == timeButton)
//      //Time function here.
    
  }
}

void drawSliders() {
  for (int i=1; i<9; i++) {
    switch(i) {
      case 1: mainDisplay.setColor(255, 0, 255);   break;
      case 2: mainDisplay.setColor(0, 0, 128);     break;
      case 3: mainDisplay.setColor(0, 0, 255);     break;
      case 4: mainDisplay.setColor(0, 255, 255);   break;
      case 5: mainDisplay.setColor(0, 255, 0);     break;
      case 6: mainDisplay.setColor(255, 0, 0);     break;
      case 7: mainDisplay.setColor(255, 255, 255); break;
      case 8: mainDisplay.setColor(255, 220, 148); break;
    }
    mainDisplay.fillRect((i*36), ((-35*(LEDLIMS[displayPhase][i-1]))/51) + 208, (i*36) + 31, 208);
    mainDisplay.setColor(VGA_BLACK);
    mainDisplay.fillRect((i*36), 30, (i*36) + 31, ((-35*(LEDLIMS[displayPhase][i-1]))/51) + 208);
  }
}

void setPhaseButton() {
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(SmallFont);
  switch(displayPhase) {
    case 0: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Dawn"); break;
    case 1: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Sunrise"); break;
    case 2: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Morning"); break;
    case 3: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Midday"); break;
    case 4: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Afternoon"); break;
    case 5: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Evening"); break;
    case 6: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Sunset"); break;
    case 7: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Dusk"); break;
    case 8: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Midnight"); break;
    case 9: phaseButton  = inputButtons.addButton(  27,   1, 79, 26, "Darkness"); break;
  }   
}

void relabelPhaseButton() {
  
  mainDisplay.setColor(VGA_WHITE);
  mainDisplay.setBackColor(VGA_BLACK);
  mainDisplay.setFont(SmallFont);
  switch(displayPhase) {
    case 0: inputButtons.relabelButton(phaseButton, "Dawn", true); break;
    case 1: inputButtons.relabelButton(phaseButton, "Sunrise", true); break;
    case 2: inputButtons.relabelButton(phaseButton, "Morning", true); break;
    case 3: inputButtons.relabelButton(phaseButton, "Midday", true); break;
    case 4: inputButtons.relabelButton(phaseButton, "Afternoon", true); break;
    case 5: inputButtons.relabelButton(phaseButton, "Evening", true); break;
    case 6: inputButtons.relabelButton(phaseButton, "Sunset", true); break;
    case 7: inputButtons.relabelButton(phaseButton, "Dusk", true); break;
    case 8: inputButtons.relabelButton(phaseButton, "Midnight", true); break;
    case 9: inputButtons.relabelButton(phaseButton, "Darkness", true); break;
  }
}
