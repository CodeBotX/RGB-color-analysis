#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TCS3200.h>

// Khai báo địa chỉ của LCD I2C
#define I2C_ADDR 0x27 

// Khai báo số cột và số hàng của LCD
#define LCD_COLS 16 
#define LCD_ROWS 2 

// Khai báo biến sử dụng cho LCD
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

// Khai báo biến sử dụng cho cảm biến màu TCS3200
#define S0 27
#define S1 26
#define S2 14
#define S3 12
#define Out 5

int frequency=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Out,INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  // Khởi tạo LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("R");
  lcd.setCursor(7,0);
  lcd.print("G");
  lcd.setCursor(13,0);
  lcd.print("B");


}

void loop() {
  // Đọc giá trị màu từ cảm biến TCS3200
  //red
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(Out, LOW);
  // Hiển thị giá trị màu lên LCD
  lcd.setCursor(0, 1);
  lcd.print(frequency);
  delay(1000);

// green
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(Out, LOW);
  lcd.setCursor(6, 1);
  lcd.print(frequency);
  delay(1000);

// blue
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(Out, LOW);
  lcd.setCursor(12, 1);
  lcd.print(frequency);
  delay(1000);

}