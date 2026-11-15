# HD Reflection — AML Balanced v2 (integration scaffold)

**Target:** GTA San Andreas Android 2.10 64-bit (`arm64-v8a`)
**Preset:** Balanced
**State:** AML plugin entry point + tested renderer-independent policy. Actual RenderWare reflection pass is not implemented yet.

## Apa yang berubah dari starter v1
- Entry point memakai pola AML yang diverifikasi dari template: `MYMOD(...)` dan `ON_MOD_LOAD()`.
- Build diarahkan ke struktur template AML yang memang menyediakan `mod/` dan `plugin-sdk/`.
- Ditambahkan policy untuk batas kendaraan, jarak, material, cubemap, dan intensitas.
- Fallback tanpa cubemap berarti melewati efek dengan aman (bukan membuat cubemap palsu).
- Tes host untuk policy tersedia di `tests/`.

## Dasar kompatibilitas yang diverifikasi
- AML PSDK menyebut GTA SA v2.10 (64-bit), Android NDK, C++17+: https://github.com/AndroidModLoader/aml-psdk
- Template AML GTA SA menyebut Plugin-SDK dengan RenderWare, target ARM64 untuk v2.00/v2.10, dan skrip build: https://github.com/kudanilll/gtasa-android-plugins-base
- Template memakai `MYMOD(...)`, `ON_MOD_LOAD()`, `mod/amlmod.h`, dan `mod/logger.h` pada `main.cpp`.
- Template utama berlisensi MIT; kode bundel pihak ketiga tetap mengikuti lisensinya masing-masing.

## Siapkan pohon template (perlu koneksi internet dan Git)
Jalankan:
```sh
./prepare_template.sh
```
Script meng-clone template upstream dan menyalin file proyek ini ke folder `HDReflection_AML_Template/`. Ia tidak menyalin ulang kode pihak ketiga atau mengubah lisensinya.

Lalu isi `NDKPath.txt` di folder template dengan path Android NDK, kemudian:
```sh
cd HDReflection_AML_Template
./build.sh
```
Template upstream yang menjadi basis menyediakan build script tersebut. Target `Application.mk` pada overlay ini hanya `arm64-v8a`.

## Status build saat paket ini dibuat
- Tes policy C++ host: dapat dijalankan dengan `./run_policy_tests.sh`.
- Android NDK build: belum dijalankan di lingkungan ini karena Android NDK dan pohon template upstream tidak tersedia secara lokal.
- Tes dalam GTA SA di perangkat: belum dilakukan.
- Refleksi visual RenderWare: belum diaktifkan.

## Batas penting
Source ini **belum membuat refleksi pada mobil**. Untuk implementasi sungguhan, masih perlu memilih dan mengaudit callback/event RenderWare yang tersedia di versi template yang digunakan, lalu membuat pass refleksi yang menggunakan resource GPU valid dan menyimpan/memulihkan seluruh render state. Tidak ada alamat hook, offset, atau struktur internal binary yang ditebak di proyek ini.

## Preset Balanced
- Maksimal 4 kendaraan per pass.
- Jarak maksimum 65 unit.
- Intensitas kendaraan 0.42; kaca 0.55; environment blend 0.38.
- Material yang tidak mendukung environment mapping dilewati.
- Jika cubemap tidak siap, efek dilewati dengan aman.
