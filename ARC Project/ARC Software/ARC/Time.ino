void updateTime() {
  
  if(curSecond != second()) {
    curSecond = second();
    char t [17];
    int j = sprintf (t, "%02u/%02u/%u %02u:%02u:%02u", month(), day(), year(), hour(), minute(), second());
    inputButtons.relabelButton(timeButton, t, true);
  }
  
}

void setCurTime(char const *date, char const *time) { 
    char s_month[5];
    int month, day, year, hour, minute, second;
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

    sscanf(date, "%s %d %d", s_month, &day, &year);
    sscanf(time, "%d:%d:%d", &hour, &minute, &second);

    month = ((strstr(month_names, s_month)-month_names)/3)+1;

    setTime(hour, minute, second, day, month, year);
}
