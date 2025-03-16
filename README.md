 # Acil Servis Hasta Kayıt Sistemi

Bu proje, bir hastanenin acil servisinde hasta kaydı, öncelik sırasına göre muayene süreci ve reçete numarası oluşturma işlemlerini gerçekleştiren bir C programıdır. Hasta bilgileri HL7 formatında saklanmaktadır.

## Özellikler
- Hasta kaydı oluşturma
- Hastaları öncelik sırasına göre sıralama
- Hastaları muayene edip reçete numarası oluşturma
- Hasta listesini görüntüleme
- Hasta verilerini HL7 formatında kaydetme

## Kurulum

1. **Kodları klonlayın:**
   ```sh
   git clone https://github.com/kullaniciadi/acil-servis.git
   cd acil-servis
   ```

2. **Derleme:**
   ```sh
   gcc acil_servis.c -o acil_servis
   ```

3. **Çalıştırma:**
   ```sh
   ./acil_servis
   ```

## Kullanım

Uygulama çalıştırıldıktan sonra aşağıdaki seçenekler sunulur:

1. Hasta Kaydı: Yeni bir hasta ekler.
2. Muayene: Öncelik sırasına göre hastayı muayene eder ve reçete numarası oluşturur.
3. Hasta Listesi: Mevcut hasta listesini görüntüler.
4. HL7 Kaydet: Hasta bilgilerini HL7 formatında kaydeder.
5. Çıkış: Programı sonlandırır.

## HL7 Formatı
Hasta verileri `patients.hl7` dosyasına aşağıdaki HL7 formatında kaydedilir:
```
PID|<Hasta ID>|<Ad>|<Yaş>|<Şikayet>|<Öncelik>|<Reçete No>
```
Örnek:
```
PID|1|Ali Yilmaz|35|Kalp çarpıntısı|1|1234
```

## Katkıda Bulunma
Projeye katkıda bulunmak için:
1. **Fork** yapın.
2. Kendi dalınızı oluşturun (`git checkout -b yeni-ozellik`).
3. Değişikliklerinizi işleyin (`git commit -m 'Yeni özellik eklendi'`).
4. Dalınıza gönderin (`git push origin yeni-ozellik`).
5. **Pull request** oluşturun.



 
