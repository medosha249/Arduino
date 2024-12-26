#include <Wire.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD display with I2C address 0x27
MFRC522 rfid(SS_PIN, RST_PIN);      // RFID instance

void setup() {
  Wire.begin(8);  // Set the slave address to 8
  Wire.onRequest(requestEvent);  // Attach the function to handle data requests
  
  lcd.begin(16, 2);  // Initialize LCD
  lcd.backlight();   // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Ready for RFID");
  
  SPI.begin();  // Start SPI communication
  rfid.PCD_Init();  // Initialize RFID reader
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String tagID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) {
        tagID += "0";  // Add leading zero if necessary
      }
      tagID += String(rfid.uid.uidByte[i], HEX);
    }
    tagID.toUpperCase();  // Convert to uppercase

    // Clear the LCD and move cursor to second line
    lcd.clear();
    lcd.setCursor(0, 0);

    // Display RFID tag on the LCD
    if (tagID == "995AD598") {  // Example RFID Tag ID (Uppercase)
      lcd.print("Object: Box");
      Serial.println("Object: Box");
    } else if (tagID == "E138981B") {  // Another Example RFID Tag ID
      lcd.print("Object: Tool");
      Serial.println("Object: Tool");
    } else {
      lcd.print("Unknown Object");
      Serial.println("Unknown Object");
    }

    delay(2000);  // Display tag for 2 seconds
  }
}

void requestEvent() {
  String tagID = "No Tag";  // Default response if no tag is detected
  Wire.write(tagID.c_str());  // Send the tag ID back to the master
}
