void updateLights() {
  
  updatePhase();
  
  switch(phase) {
    case 0:
      //beginDawn();
      break;
    case 1:
      //beginSunrise();
      break;
    case 2:
      //beginMorning();
      break;
    case 3:
      //beginMidday();
      break;
    case 4:
      //beginAfternoon();
      break;
    case 5:
      //beginEvening();
      break;
    case 6:
      //beginSunset();
      break;
    case 7:
      //beginDusk();
      break;
    case 8:
      //beginMidnight();
      break;
    case 9:
      //beginDarkness();
      break;
  }
}

unsigned long N, C, Y, B, G, A, R, U;

boolean LEDsAnimating() {
  if(WWLED->isAnimating() ||
     CYLED->isAnimating() ||
     CWLED->isAnimating() ||
     BLLED->isAnimating() ||
     DRLED->isAnimating() ||
     RBLED->isAnimating() ||
     GRLED->isAnimating() ||
     UVLED->isAnimating())
     return true;
   else
     return false;
}

void updateLEDs() {
  WWLED->update();
  CYLED->update();
  CWLED->update();
  BLLED->update();
  DRLED->update();
  RBLED->update();
  GRLED->update();
  UVLED->update();
}

void updatePhase() {
  for(int n=0 ; n<=9 ; n++) {
    if(hour() == TIMING[n][0] && minute() == TIMING[n][1])
      phase = n;
  }
}
