#include<LiquidCrystal.h>
#include<Wire.h>
#include<TimeLib.h>
#include<DS1307RTC.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int cont = 75;

int soil = A0;
int water = A1;
int relay = 8;

const long lcd_t = 1000;
const long wait_t = 108000000;
const long pump_t = 10000;

long pump_c = NULL;
long wait_c = NULL;

long lcd_p = 0;
long wait_p = 0;
long pump_p = 0;

int stat = 0;
int wait_stat = 0;
int pump_stat = 0;

int hrs = 0;
int mins = 0;
int secs = 0;

void setup() {
  Serial.begin(9600);
  analogWrite(10, cont);
  pinMode(relay, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
  delay(2000);
  lcd.clear();
}

void time_run() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    hrs = tm.Hour;
    mins = tm.Minute;
    secs = tm.Second;
  }
}

void data_trans() {
  if(moist_ck()>50){
    digitalWrite(0, LOW);
  }
  else if(moist_ck()<=50){
    digitalWrite(0, HIGH);
  }
  if(((analogRead(water) / 550) * 100) > 25){
    digitalWrite(1, LOW);
  }
  else if(((analogRead(water) / 550) * 100) < 25){
    digitalWrite(1, HIGH);
  }
  digitalWrite(7, pump_stat);
}

void LCD() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Time: ");
  lcd.print(int(hrs));
  lcd.print(":");
  lcd.print(int(mins));
  lcd.print(":");
  lcd.print(int(secs));
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.println(secs);
  lcd.setCursor(1, 1);
  lcd.print("S:");
  Serial.println(moist_ck());
  lcd.print(moist_ck());
  lcd.print("%");
  lcd.setCursor(9, 1);
  lcd.print("W:");
  Serial.println(water_ck());
  lcd.print(water_ck());
}

int moist_ck() {
  return (((1023 - analogRead(soil)) / 1023.00) * 100);
}

String water_ck() {
  int val = (analogRead(water) / 550) * 100;
  if (val > 75) {
    return ("HIGH");
  }
  else if (val > 25) {
    return ("MID");
  }
  else {
    return ("LOW");
  }
}

void pump(long pump_p) {
  pump_c = millis();
  if (pump_c - pump_p >= pump_t) {
    digitalWrite(relay, LOW);
    stat = 0;
    pump_stat=0;
  }
}

void pump_w(long wait_p) {
  wait_c = millis();
  if (wait_c - wait_p >= wait_t) {
    stat = 0;
    wait_stat = 0;
    cond_ck();
  }
}

void cond_ck() {
  stat += 1;
  if (moist_ck() <= 50.00 && wait_stat == 0) {
    if (stat == 1) {
      pump_p = millis();
    }
    stat += 1;
    digitalWrite(relay, HIGH);
    pump_stat = 1;
    pump(pump_p);
  }
  else {
    if (wait_stat == 0) {
      unsigned long wait_p = millis();
    }
    wait_stat = 1;
    pump_w(wait_p);
  }
}

void loop() {
  unsigned long lcd_c = millis();
  if (lcd_c - lcd_p >= lcd_t) {
    lcd_p = lcd_c;
    time_run();
    LCD();
    if ((hrs == 12 && mins == 5 && secs == 00) && stat == 0) {
      cond_ck();
    }
    if (wait_stat == 1) {
      pump_w(wait_p);
    }
    if (pump_stat == 1) {
      pump(pump_p);
    }
    data_trans();
  }
}
