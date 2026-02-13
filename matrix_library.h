// =============================================
// فایل هدر کتابخانه ماتریس و بردار
// نام فایل: matrix_library.h
// =============================================

#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

// ============================================
// توابع مربوط به ماتریس‌ها
// ============================================

// جمع دو ماتریس
void jameMatris(double matris1[][3], double matris2[][3], double natije[][3], int satr, int sotun);

// تفریق دو ماتریس
void tafriqMatris(double matris1[][3], double matris2[][3], double natije[][3], int satr, int sotun);

// ضرب دو ماتریس
void zarbMatris(double matris1[][3], double matris2[][3], double natije[][3], int satr1, int sotun1, int satr2, int sotun2);

// ضرب عدد در ماتریس (اسکالر)
void zarbAdadDarMatris(double matris[][3], double natije[][3], double adad, int satr, int sotun);

// ترانهاده ماتریس
// ترانهاده یعنی سطرها رو ستون کنیم و ستون‌ها رو سطر
void taranahadeMatris(double matris[][3], double natije[][3], int satr, int sotun);

// محاسبه دترمینان ماتریس
// دترمینان فقط برای ماتریس‌های مربعی (2x2 یا 3x3) محاسبه میشه
double hesabDeterminan(double matris[][3], int andaze);

// محاسبه معکوس ماتریس
// معکوس فقط برای ماتریس‌های مربعی که دترمینانشون صفر نباشه
void hesabMakoos(double matris[][3], double natije[][3], int andaze);


// ============================================
// توابع مربوط به بردارها
// ============================================

// جمع دو بردار
void jameBordar(double bordar1[], double bordar2[], double natije[], int andaze);

// تفریق دو بردار
void tafriqBordar(double bordar1[], double bordar2[], double natije[], int andaze);

// ضرب عدد در بردار (اسکالر)
void zarbAdadDarBordar(double bordar[], double natije[], double adad, int andaze);

// ضرب داخلی دو بردار
// ضرب داخلی یه عدد برمیگردونه
double zarbDakheli(double bordar1[], double bordar2[], int andaze);

// ضرب خارجی دو بردار (فقط برای بردارهای 3 تایی)
void zarbKhareji(double bordar1[], double bordar2[], double natije[]);

// اندازه بردار (طول بردار)
double andazeBordar(double bordar[], int andaze);

// نرمال کردن بردار
// نرمال کردن یعنی اندازه‌اش رو 1 کنیم
void normalKardanBordar(double bordar[], double natije[], int andaze);


// ============================================
// توابع کمکی برای نمایش
// ============================================

// چاپ ماتریس روی صفحه
void chapMatris(double matris[][3], int satr, int sotun);

// چاپ بردار روی صفحه
void chapBordar(double bordar[], int andaze);

#endif
