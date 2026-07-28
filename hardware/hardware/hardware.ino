// #include <TinyGPS++.h>
// #include <SPI.h>
// #include <SD.h>


// #define RXD2 16
// #define TXD2 17

// TinyGPSPlus gps;
// const int CS_PIN = 5; 

// void setup() {
//   //Computer serial
//   Serial.begin(115200);
  
//   //GPS Serial, defined on pins 16/17 see defines
//   Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

//   Serial.print("Initializing SD card...");
//   if (!SD.begin(CS_PIN)) {
//     Serial.println(" Card Mount Failed!");
//     return; 
//   }
//   Serial.println(" SD Card Initialized.");
// }

// int last_lat = 0;
// int last_lng = 0;
// int last_alt = 0;
// int last_speed = 0;
// bool started_tracking = false;
// String current_filename = "";
// String b36_lookup_list[36] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// void loop() {
//   // Feed the parser with incoming data from the GPS module
//   while (Serial2.available() > 0) {
//     if (gps.encode(Serial2.read())) {
//       fetch_and_write_info();
//     }
//   }
// }

// void fetch_and_write_info() {
//   // Only print data when a new location update is fully parsed
//   if ((gps.location.isUpdated()) && (gps.altitude.isUpdated()) && (gps.speed.isUpdated())) {
//     String update = "";
//     int lat = gps.location.lat()*(pow(10, 5));
//     int lng = gps.location.lng()*(pow(10, 5));
//     int alt = gps.altitude.meters();
//     int speed = gps.speed.kmph()*pow(10, 2);

//     if (!started_tracking) {
//       started_tracking = true;
//       String filename = "/"+String(gps.date.year())+"-"+String(gps.date.month())+"-"+String(gps.date.day())+"_"+String(gps.time.hour())+"@"+String(gps.time.minute())+"@"+String(gps.time.second());
//       createNewFile(filename, "Hello World!"); //TODO: Add file headers (activity type, etc.)
//       current_filename = filename;
//       update += "#";
//     }

//     update += "!@"+translate_b36(lat)+"$"+translate_b36(lng)+"%"+translate_b36(alt)+"&"+translate_b36(speed);
//     appendToFile(current_filename, update);

//     last_lat = lat;
//     last_lng = lng;
//     last_alt = alt;
//     last_speed = speed;
//   }
// }

// String translate_b36(int number) {
//   int truenum = abs(number);
//   if (truenum == 0) return "0";

//   String num_base = "";
    
//   while (truenum > 0) {
//       int remainder = truenum % 36;          
//       num_base = b36_lookup_list[remainder] + num_base; 
//       truenum /= 36;                            
//   }

//   if (number < 0) {
//     num_base = "-" + num_base;
//   }

//   return num_base;
// }

// bool createNewFile(String filename, String initialData) {
//   File file = SD.open(filename, FILE_WRITE);
//   if (!file) {
//     Serial.println("Error: Could not create file " + filename);
//     return false;
//   }
//   file.print(initialData);
//   file.close();
//   Serial.println("Created new file: " + filename);
//   return true;
// }

// void appendToFile(String filename, String data) {
//   File file = SD.open(filename, FILE_APPEND);
//   if (!file) {
//     Serial.println("Error appending to " + filename);
//     return;
//   }
//   file.print(data);
//   file.close();
// }


// // #include <SPI.h>
// // #include <SD.h>

// // // Define your Chip Select pin
// // const int CS_PIN = 5; 

// // void setup() {
// //   Serial.begin(115200);

// //   // Initialize the SD card
// //   Serial.print("Initializing SD card...");
  
// //   if (!SD.begin(CS_PIN)) {
// //     Serial.println(" Card Mount Failed!");
// //     // Check your wiring and VCC voltage if this happens
// //     return; 
// //   }
  
// //   Serial.println(" SD Card Initialized.");
// // }

// // void loop() {
// //   delay(10);
// // }

#include <LiquidCrystal.h>

const int rs = 14, en = 27, d4 = 26, d5 = 25, d6 = 33, d7 = 32;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Give the LCD controller 100ms to finish its internal hardware reset
  delay(100); 

  // Standard 16x2 initialization (drop the 3rd argument)
  lcd.begin(16, 2);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ESP32 LCD Ready!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis() / 1000);
  lcd.print("s   ");
  delay(1000);
}