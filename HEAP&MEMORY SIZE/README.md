1. GPIO Yapılandırması:

LED'in bağlı olduğu GPIO pini GPIO_NUM_32 olarak tanımlanmıştır.
Bu pin çıkış olarak ayarlanmıştır.

2. Sistem Bilgisi:

Flash bellek boyutu esp_flash_get_size fonksiyonu ile okunur.
Toplam ve kullanılabilir RAM heap_caps_get_total_size ve heap_caps_get_free_size ile elde edilir.

3. LED Blink:

GPIO pini kullanılarak LED bir saniye yanar ve bir saniye söner.
Bu döngü sonsuza kadar devam eder.

4. Loglama Seviyesi:

Loglama için esp_log_level_set fonksiyonu kullanılarak log seviyeleri ayarlanır.
Rastgele Değer Üretimi: Rastgele bir sayı oluşturulup "yakıt seviyesi" olarak loglanır.
