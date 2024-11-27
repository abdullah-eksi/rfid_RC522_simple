#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9       
#define SS_PIN 10        
#define SERVO_PIN 8     
#define BUZZER_PIN 7     

Servo motor;
MFRC522 rfid(SS_PIN, RST_PIN);
byte authorizedID[4] = {179, 250, 108, 9}; x

void setup() {
  motor.attach(SERVO_PIN);           
  pinMode(BUZZER_PIN, OUTPUT);       
  Serial.begin(9600);                
  SPI.begin();                       
  rfid.PCD_Init();                   // RC522 modülünü başlat
  Serial.println("Sistem Hazir");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Kart ID'sini kontrol et
  if (isAuthorized()) {
    Serial.println("Kapi Acildi");
    buzzerCal(1000, 200); // Kapı açılma tonu
    motor.write(180);     // Servo motoru 180 dereceye getir
    delay(3000);
    motor.write(0);       // Servo motoru 0 dereceye getir
  } else {
    Serial.println("Yetkisiz Kart!");
    buzzerCal(500, 500);  // Yetkisiz giriş tonu
  }

  printCardID();        
  rfid.PICC_HaltA();       
}


bool isAuthorized() {
  for (int i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != authorizedID[i]) {
      return false;
    }
  }
  return true;
}


void printCardID() {
  Serial.print("ID Numarasi: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void buzzerCal(int frequency, int duration) {
  tone(BUZZER_PIN, frequency, duration);
  delay(duration);                       
  noTone(BUZZER_PIN);                  
}
