

# RFID Erişim Kontrol Sistemi (Servo ve Buzzer ile)

Bu proje, MFRC522 RFID modülü, bir servo motor ve bir buzzer kullanarak basit bir RFID tabanlı erişim kontrol sistemi oluşturmayı göstermektedir. Sistem, bir RFID kartının kimliğini okur ve kart yetkilendirilmişse, kapıyı açmak için servo motoru döndürür. Kart yetkisizse, buzzer bir uyarı sesi çalar.

## Gereken Bileşenler

- **MFRC522 RFID Modülü**
- **Servo Motor**
- **Buzzer**
- **Arduino Kartı (örneğin, Uno, Nano vb.)**
- **Jumper Kablolar**
- **Breadboard (isteğe bağlı)**

## Devre Bağlantıları

| Bileşen          | Pin Bağlantısı        |
|------------------|-----------------------|
| MFRC522 RFID     |                       |
| - SDA (SS Pin)   | Pin 10                |
| - SCK (Clock)    | Pin 13                |
| - MOSI (Data)    | Pin 11                |
| - MISO (Data Out)| Pin 12                |
| - RST (Reset)    | Pin 9                 |
| Servo Motor      | Pin 8                 |
| Buzzer           | Pin 7                 |

## Kod Genel Bakış

Bu kod, RFID modülü için **SPI** ve **MFRC522** kütüphanelerini ve servo motoru kontrol etmek için **Servo** kütüphanesini kullanmaktadır. Sistem, RFID kartının kimliğini kontrol ederek çalışır. Eğer kartın kimliği yetkilendirilmiş kimlikle eşleşirse, kapıyı açmak için servo motoru hareket ettirir. Eğer kart yetkisizse, buzzer farklı bir tonla uyarı verir.

### Ana Fonksiyonlar:

- **`isAuthorized()`**: Tarayıcı tarafından okunan RFID kartının kimliğinin yetkilendirilmiş kartla eşleşip eşleşmediğini kontrol eder.
- **`printCardID()`**: Okunan RFID kartının kimliğini Seri Monitör'e yazdırır.
- **`buzzerCal()`**: Buzzer'ı belirtilen frekans ve süre ile çalar.
- **`setup()`**: Sistemi başlatır, pinleri ayarlar ve seri iletişimi başlatır.
- **`loop()`**: Sürekli olarak yeni RFID kartlarını kontrol eder.

### Yetkilendirilmiş Kart Kimliği

Bu sistemde, yalnızca belirli bir RFID kartı yetkilendirilmiştir. Yetkilendirilmiş kartın kimliği, şu şekilde `authorizedID` dizisi içinde tanımlanmıştır:

```cpp
byte authorizedID[4] = {179, 250, 108, 9};  // Yetkilendirilmiş kartın kimliği
```

Bu kartın kimliği okunduğunda, kapı açılır. Eğer kart yetkilendirilmemişse, buzzer uyarı sesi çalar.

## Kullanım Adımları

1. **Donanımı Bağlayın**: Arduino'yu, MFRC522 RFID modülünü, servo motoru ve buzzer'ı yukarıdaki bağlantı tablosuna göre bağlayın.
2. **Kodu Yükleyin**: Arduino IDE kullanarak bu kodu Arduino'ya yükleyin.
3. **Seri Monitörü Açın**: Arduino'nun doğru şekilde çalıştığından emin olmak için Seri Monitörü açın.
4. **Kartı Okutun**: Yetkilendirilmiş bir RFID kartını okuyucuya yaklaştırın. Kart doğruysa kapı açılır, yanlışsa buzzer çalar.

## Ekstra Özellikler

- **Kapı Açılma Süresi**: Servo motoru 180 derece döndürebilir ve 3 saniye sonra tekrar sıfır konumuna getirebilirsiniz.
- **Farklı Buzzer Tonları**: Yetkilendirilmiş ve yetkisiz kartlar için farklı tonlar ayarlanmıştır.

---

Bu README dosyası, sistemin işleyişini ve kurulumu hakkında temel bilgileri sağlamaktadır. Projeyi dilediğiniz gibi geliştirebilir ve daha fazla özellik ekleyebilirsiniz.
