//#include <Wire.h>
#include <SPI.h>
#include <Ds1302.h>
#include <U8g2lib.h>

#define LEFT_BUTTON 15
#define MIDDLE_BUTTON 14
#define RIGHT_BUTTON 13

#define LIGHT_BAR 11
#define USB_1 5
#define USB_2 28

#define RTC_RESET 8
#define RTC_CLK 6
#define RTC_DATA 7

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

U8G2_SSD1327_WS_128X128_F_4W_SW_SPI display(U8G2_R0, /* clock=*/ 18, /* data=*/ 19, /* cs=*/ 16, /* dc=*/ 17, /* reset=*/ 20);

Ds1302 rtc(RTC_RESET, RTC_CLK, RTC_DATA);

const static char* WeekDays[] =
{
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

uint8_t last_second = 0;

bool guidelines = false;
uint8_t guidelineWidth = 16;

bool lightBarStatus = false;
bool usb1Status = false;
bool usb2Status = false;

void setup() 
{
  pinMode(LEFT_BUTTON, INPUT);
  pinMode(MIDDLE_BUTTON, INPUT);
  pinMode(RIGHT_BUTTON, INPUT);

  pinMode(LIGHT_BAR, OUTPUT);
  pinMode(USB_1, OUTPUT);
  pinMode(USB_2, OUTPUT);

  digitalWrite(LIGHT_BAR, LOW);
  digitalWrite(USB_1, LOW);
  digitalWrite(USB_2, LOW);

  //Wire.begin();
  rtc.init();
  display.begin();


  // Ds1302::DateTime dt = {
  //     .year = 23,
  //     .month = Ds1302::MONTH_OCT,
  //     .day = 27,
  //     .hour = 18,
  //     .minute = 32,
  //     .second = 0,
  //     .dow = Ds1302::DOW_FRI
  // };

  // rtc.setDateTime(&dt);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() 
{
  manageInputs();
  manageOutputs();

  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  if (last_second != now.second)
  {
    last_second = now.second;

    display.clearBuffer();  
    
    if(guidelines)
    {
      for(int i = 0; i <= SCREEN_WIDTH; i += guidelineWidth)
      {
        display.drawLine(i, 0, i, SCREEN_WIDTH);
        display.drawLine(0, i, SCREEN_HEIGHT, i);
      }
    }

    display.setFontMode(1);
    display.setFont(u8g2_font_helvR08_tf);	

    display.setCursor(40,25);
    display.print(WeekDays[now.dow - 1]); // 1-7

    display.setCursor(38,104);
    if (now.day < 10) display.print('0');
    display.print(now.day);     // 01-31
    display.print('/');
    if (now.month < 10) display.print('0');
    display.print(now.month);   // 01-12
    display.print('/');
    display.print("20");
    display.print(now.year);    // 00-99
    
    display.setCursor(2,75);
    display.setFont(u8g2_font_fur35_tn);
    if (now.hour < 10) display.print('0');
    display.print(now.hour);    // 00-23
    display.print(':');
    if (now.minute < 10) display.print('0');
    display.print(now.minute);  // 00-59
    //display.print(':');
    //if (now.second < 10) display.print('0');
    //display.print(now.second);  // 00-59

    display.sendBuffer();
  }

  //delay(100);
}

void manageInputs()
{
  if(digitalRead(LEFT_BUTTON) == HIGH)
  {
    Serial.println("LEFT");
    usb2Status = !usb2Status;
    while(digitalRead(LEFT_BUTTON) == HIGH){}
  }

  if(digitalRead(MIDDLE_BUTTON) == HIGH)
  {
    Serial.println("MIDDLE");
    usb1Status = !usb1Status;
    while(digitalRead(MIDDLE_BUTTON) == HIGH){}
  }

  if(digitalRead(RIGHT_BUTTON) == HIGH)
  {
    Serial.println("RIGHT");
    lightBarStatus = !lightBarStatus;
    while(digitalRead(RIGHT_BUTTON) == HIGH){}
  }
}

void manageOutputs()
{
  if(usb2Status)
  {
    digitalWrite(USB_2, HIGH);
  }
  else
  {
    digitalWrite(USB_2, LOW);
  }

  if(usb1Status)
  {
    digitalWrite(USB_1, HIGH);
  }
  else
  {
    digitalWrite(USB_1, LOW);
  }

  if(lightBarStatus)
  {
    digitalWrite(LIGHT_BAR, HIGH);
  }
  else
  {
    digitalWrite(LIGHT_BAR, LOW);
  }
}