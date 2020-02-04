#include <UTFT.h>
#include <UTouch.h>
#include <UTFT_Buttons.h>
#include <Time.h>
#include <LED.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Dingbats1_XL[];

int LEDLIMS[10][8]    = {{  1,   1,   3,   4,   1,   1,   2,   1}, //Dawn
		         {100, 120, 135,  75,  90,  60, 120,  50}, //Sunrise
		         {150, 135, 195, 105, 120,  45, 150,  90}, //Morning
		         {255, 255, 255, 150, 175,  45, 200, 130}, //Midday
		         {255, 225, 200, 110,  90, 110, 115, 170}, //Afternoon
		         {175, 120,  75,  60,  75,  90, 100, 115}, //Evening
		         {  5,   3,   1,   1,   0,   3,   2,   0}, //Sunset
		         {  3,   2,   1,   0,   0,   2,   1,   0}, //Dusk
		         {  2,   2,   0,   0,   0,   1,   0,   0}, //Midnight
		         {  0,   0,   0,   0,   0,   0,   0,   0}};//Darkness

int LEDOFFSETS[10][8] = {{  1,   1,   1,   2,   1,   1,   1,   1}, //Dawn
		         { 15,  15,  15,  10,  10,  10,  15,   5}, //Sunrise
		         { 15,  15,  20,  15,  15,   5,  15,   5}, //Morning
		         { 20,  20,  20,  15,  15,   5,  20,  15}, //Midday
		         { 20,  20,  15,  10,   5,  10,  10,  15}, //Afternoon
		         { 15,  15,   5,   5,   5,   5,  10,  10}, //Evening
		         {  2,   1,   1,   1,   1,   1,   1,   0}, //Sunset
		         {  1,   1,   1,   1,   1,   1,   1,   0}, //Dusk
		         {  1,   1,   1,   1,   1,   1,   1,   0}, //Midnight
		         {  0,   0,   0,   0,   0,   0,   0,   0}};//Darkness

int TIMING[10][2]     = {{ 6, 0}, // Dawn Start
                         { 7, 0}, // Sunrise Start
                         { 8, 0}, // Morning Start
                         {11, 0}, // Midday Start
                         {15, 0}, // Afternoon Start
                         {18, 0}, // Evening Start
                         {21, 0}, // Sunset Start
                         {22, 0}, // Dusk Start
                         { 0, 0}, // Midnight Start
                         { 2, 0}};// Darkness Start

int LEDVALS[8] = {255, 128, 0, 255, 128, 64, 32, 16};

String phases[10]   = {"Dawn", "Sunrise", "Morning", "Midday", "Afternoon",
		       "Evening", "Sunset", "Dusk", "Midnight", "Darkness"};

String colors[8]    = {"UltraViolet", "Royal Blue", "Blue", "Cyan",
                       "Green", "Red", "Cool White", "Warm White"};
                     
String devices[8]   = {"Device 1", "Device 2", "Device 3", "Device 4",
                       "Device 5", "Device 6", "Device 7", "Device 8"};
                       
String deviceMSG[9] = {"No Timer", "Freq", "Daily", "Weekly"};

int deviceOptions[8][7] = {{1,  1, 1100, 1, 1130,  1, 1115}, //DEV1
                           {2,  5, 1000, 2, 1030,  3, 1045}, //DEV2
                           {3, 10,  900, 3,  930,  5,  915}, //DEV3
                           {4, 15,  800, 4,  830,  7,  845}, //DEV4
                           {2,  6, 2000, 5, 2030, 10, 2015}, //DEV5
                           {1,  3, 1700, 6, 1730, 12, 1745}, //DEV6
                           {4, 19, 1200, 7, 1230, 14, 1215}, //DEV7
                           {3, 13, 2200, 4, 2230, 16, 2245}};//DEV8

boolean POWER = true;
boolean deviceStatus[8] = {false,true,false,true,false,true,false,true};

char phaseBuf[10];

LED * WWLED = new LED(12, true);
LED * CYLED = new LED(11, true);
LED * CWLED = new LED(10, true);
LED * BLLED = new LED( 9, true);
LED * DRLED = new LED( 8, true);
LED * RBLED = new LED( 7, true);
LED * GRLED = new LED( 6, true);
LED * UVLED = new LED( 5, true);

boolean fineTune = false, lock = true;
int selectedColor = 0, phase, curDevEdit;

int D1, D2, D3, D4, D5, D6, D7, D8;

int addOneHourButton, subOneHourButton, addOneMinButton, subOneMinButton;
int timerButton, freqButton, dailyButton, weeklyButton, monthlyButton;
int addOneButton, subOneButton, addTenButton, subTenButton, addOneOffButton, subOneOffButton,
        returnButton;
int pressedButton, page = 0, curSecond, displayPhase;
int fineTuneButton, lockButton;
int homeButton, settingsButton, alertButton, powerButton, timeButton, backButton,
	nextButton, phaseButton;
int lightingButton, dosingButton, devicesButton, logButton, aboutButton;

int addFreqButton, subFreqButton, addTimeButton, subTimeButton, addDayButton, subDayButton,
    addDTimeButton, subDTimeButton, addDateButton, subDateButton, addMTimeButton, subMTimeButton;

UTFT          mainDisplay(ITDB32S, 38,39,40,41);
UTouch        inputTouch(6,5,4,3,2);
UTFT_Buttons  inputButtons(&mainDisplay, &inputTouch);

void setup() {
  Serial.begin(9600);
  setCurTime(__DATE__, __TIME__);
  
  mainDisplay.InitLCD();
  mainDisplay.clrScr();
  mainDisplay.setFont(SmallFont);
  
  inputTouch.InitTouch();
  inputTouch.setPrecision(PREC_HI);
  
  inputButtons.setTextFont(SmallFont);
  inputButtons.setSymbolFont(Dingbats1_XL);
  inputButtons.setButtonColors(VGA_BLACK, VGA_GRAY, VGA_WHITE, VGA_BLUE, VGA_SILVER);

  mainDisplay.setBrightness(1);

  drawHomePage();
}

void loop() {
  updateTime();
  updateGUI();
  
  updateLights();
}
