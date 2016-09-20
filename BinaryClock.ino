/**
 * Code for a binary clock including minutes and hours
 * Two buttons ( pin 14, and 15 ) used to set the time 
 * 
 * Jacob Potter 2013
 */

int second = 0, minute = 0, hour = 0;
int minunit = 0, hourunit = 0; // The ones place for the minutes and hours
int valminute = 0, valhour = 0; // The 10s place for minutes and hours

void setup(){
  for(int j = 1; j<=13; j++){
    pinMode(j, OUTPUT);
  }
  pinMode(14, INPUT);
  pinMode(15, INPUT);
}
void loop(){
  digitalWrite(0, HIGH);
  
  static unsigned long lastTick = 0;
  
  if(millis()-lastTick>= 1000){ // counts seconds
    lastTick = millis();
    second++;
  }  
  if(second >=60){
    minute++;
    second = 0;  
  }
  if(minute >= 60){
    hour++;
    minute = 0; 
  }
  if(hour >=24){
    hour = 0;
    minute = 0; 
  }
  minunit = minute%10; // Gets the ones digits for minutes
  hourunit = hour%10;  // Gets the ones digits for hours
  //--------------------------------------------- MINUTES
  if(minunit == 1 || minunit == 3 || minunit == 5 || minunit == 7 || minunit == 9) {  digitalWrite(13, LOW);} else {  digitalWrite(13, HIGH);}
  if(minunit == 2 || minunit == 3 || minunit == 6 || minunit == 7) {digitalWrite(12, LOW);} else {digitalWrite(12,HIGH);}
  if(minunit == 4 || minunit == 5 || minunit == 6 || minunit == 7) {digitalWrite(11, LOW);} else {digitalWrite(11,HIGH);}
  if(minunit == 8 || minunit == 9) {digitalWrite(10, LOW);} else {digitalWrite(10,HIGH);}
  //==
  if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60))  {digitalWrite(9, LOW);} else {digitalWrite(9,HIGH);}
  if(minute >= 20 && minute < 40)  {digitalWrite(8, LOW);} else {digitalWrite(8,HIGH);}
  if(minute >= 40 && minute < 60) {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}
  //==HOURS
  if(hourunit == 1 || hourunit == 3 || hourunit == 5 || hourunit == 7 || hourunit == 9) {digitalWrite(6, LOW);} else {digitalWrite(6,HIGH);}
  if(hourunit == 2 || hourunit == 3 || hourunit == 6 || hourunit == 7) {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}
  if(hourunit == 4 || hourunit == 5 || hourunit == 6 || hourunit == 7) {digitalWrite(4, LOW);} else {digitalWrite(4,HIGH);}
  if(hourunit == 8 || hourunit == 9) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  //==
  if(hour >= 10 && hour < 20)  {digitalWrite(2, LOW);} else {digitalWrite(2,HIGH);}
  if(hour >= 20 && hour < 24)  {digitalWrite(1, LOW);} else {digitalWrite(1,HIGH);}
  //-----------------------------------------------
  valminute = digitalRead(14); //Sets the Minutes
  if(valminute == HIGH){
    minute++;
    second = 0;
    delay(250);   
  }
  valhour = digitalRead(15); // Sets the hours
  if(valhour == HIGH){
    hour++;
    second = 0;
    delay(250); 
  } 
}
