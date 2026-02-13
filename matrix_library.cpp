// =============================================
// فایل پیاده‌سازی توابع کتابخانه
// نام فایل: matrix_library.cpp
// =============================================

#include <iostream>
#include <cmath>      // برای استفاده از sqrt و pow
#include "matrix_library.h"
using namespace std;


// =============================================
// توابع کمکی برای نمایش
// =============================================

// تابع چاپ ماتریس
void chapMatris(double matris[][3], int satr, int sotun) {
    cout << "\n";
    // حلقه برای چاپ هر سطر
    for(int i = 0; i < satr; i++) {
        cout << "[ ";
        // حلقه برای چاپ هر ستون در اون سطر
        for(int j = 0; j < sotun; j++) {
            cout << matris[i][j];
            if(j < sotun - 1) {
                cout << "\t";  // فاصله بین اعداد
            }
        }
        cout << " ]" << endl;
    }
}

// تابع چاپ بردار
void chapBordar(double bordar[], int andaze) {
    cout << "< ";
    for(int i = 0; i < andaze; i++) {
        cout << bordar[i];
        if(i < andaze - 1) {
            cout << ", ";
        }
    }
    cout << " >" << endl;
}


// =============================================
// توابع ماتریسی
// =============================================

// تابع جمع دو ماتریس
void jameMatris(double matris1[][3], double matris2[][3], double natije[][3], int satr, int sotun) {
    // برای جمع، باید هر خونه از ماتریس اول رو با همون خونه از ماتریس دوم جمع کنیم

    for(int i = 0; i < satr; i++) {
        for(int j = 0; j < sotun; j++) {
            natije[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
}

// تابع تفریق دو ماتریس
void tafriqMatris(double matris1[][3], double matris2[][3], double natije[][3], int satr, int sotun) {
    // برای تفریق، باید هر خونه از ماتریس دوم رو از ماتریس اول کم کنیم

    for(int i = 0; i < satr; i++) {
        for(int j = 0; j < sotun; j++) {
            natije[i][j] = matris1[i][j] - matris2[i][j];
        }
    }
}

// تابع ضرب دو ماتریس
void zarbMatris(double matris1[][3], double matris2[][3], double natije[][3],
                int satr1, int sotun1, int satr2, int sotun2) {

    // اول همه جاهای ماتریس نتیجه رو صفر می‌کنیم
    for(int i = 0; i < satr1; i++) {
        for(int j = 0; j < sotun2; j++) {
            natije[i][j] = 0;
        }
    }

    // حالا ضرب ماتریسی رو انجام میدیم
    // فرمول: natije[i][j] = مجموع (matris1[i][k] * matris2[k][j])

    for(int i = 0; i < satr1; i++) {
        for(int j = 0; j < sotun2; j++) {
            for(int k = 0; k < sotun1; k++) {
                natije[i][j] = natije[i][j] + (matris1[i][k] * matris2[k][j]);
            }
        }
    }
}

// تابع ضرب عدد در ماتریس
void zarbAdadDarMatris(double matris[][3], double natije[][3], double adad, int satr, int sotun) {
    // هر خونه از ماتریس رو در عدد ضرب می‌کنیم

    for(int i = 0; i < satr; i++) {
        for(int j = 0; j < sotun; j++) {
            natije[i][j] = matris[i][j] * adad;
        }
    }
}

// تابع ترانهاده ماتریس
void taranahadeMatris(double matris[][3], double natije[][3], int satr, int sotun) {
    // ترانهاده یعنی سطرها رو ستون کنیم
    // یعنی matris[i][j] میشه natije[j][i]

    for(int i = 0; i < satr; i++) {
        for(int j = 0; j < sotun; j++) {
            natije[j][i] = matris[i][j];
        }
    }
}

// تابع محاسبه دترمینان
double hesabDeterminan(double matris[][3], int andaze) {
    double det = 0;  // متغیر دترمینان

    if(andaze == 2) {
        // فرمول دترمینان ماتریس 2x2:
        // det = (a*d) - (b*c)
        // برای ماتریس: [a b]
        //               [c d]

        det = (matris[0][0] * matris[1][1]) - (matris[0][1] * matris[1][0]);
    }
    else if(andaze == 3) {
        // فرمول دترمینان ماتریس 3x3 (روش سارس):
        // جمع قطرهای راست - جمع قطرهای چپ

        // قطرهای راست (مثبت)
        det = det + (matris[0][0] * matris[1][1] * matris[2][2]);
        det = det + (matris[0][1] * matris[1][2] * matris[2][0]);
        det = det + (matris[0][2] * matris[1][0] * matris[2][1]);

        // قطرهای چپ (منفی)
        det = det - (matris[0][2] * matris[1][1] * matris[2][0]);
        det = det - (matris[0][1] * matris[1][0] * matris[2][2]);
        det = det - (matris[0][0] * matris[1][2] * matris[2][1]);
    }

    return det;
}

// تابع محاسبه معکوس ماتریس
void hesabMakoos(double matris[][3], double natije[][3], int andaze) {
    // اول دترمینان رو حساب می‌کنیم
    double det = hesabDeterminan(matris, andaze);

    // اگه دترمینان صفر باشه، معکوس نداره
    if(det == 0) {
        cout << "\n error : in matrix reverse nadarad...aval riyazi bekhoon:)" << endl;
        return;
    }

    if(andaze == 2) {
        // فرمول معکوس ماتریس 2x2:
        // اگه ماتریس [a b] باشه
        //           [c d]
        // معکوسش میشه: (1/det) * [ d  -b]
        //                          [-c   a]

        natije[0][0] = matris[1][1] / det;
        natije[0][1] = -matris[0][1] / det;
        natije[1][0] = -matris[1][0] / det;
        natije[1][1] = matris[0][0] / det;
    }
    else if(andaze == 3) {
        // برای ماتریس 3x3 از فرمول کامل استفاده می‌کنیم
        // این فرمول‌ها از کتاب ریاضی گرفته شده

        // سطر اول
        natije[0][0] = (matris[1][1] * matris[2][2] - matris[1][2] * matris[2][1]) / det;
        natije[0][1] = (matris[0][2] * matris[2][1] - matris[0][1] * matris[2][2]) / det;
        natije[0][2] = (matris[0][1] * matris[1][2] - matris[0][2] * matris[1][1]) / det;

        // سطر دوم
        natije[1][0] = (matris[1][2] * matris[2][0] - matris[1][0] * matris[2][2]) / det;
        natije[1][1] = (matris[0][0] * matris[2][2] - matris[0][2] * matris[2][0]) / det;
        natije[1][2] = (matris[0][2] * matris[1][0] - matris[0][0] * matris[1][2]) / det;

        // سطر سوم
        natije[2][0] = (matris[1][0] * matris[2][1] - matris[1][1] * matris[2][0]) / det;
        natije[2][1] = (matris[0][1] * matris[2][0] - matris[0][0] * matris[2][1]) / det;
        natije[2][2] = (matris[0][0] * matris[1][1] - matris[0][1] * matris[1][0]) / det;
    }
}


// =============================================
// توابع برداری
// =============================================

// تابع جمع دو بردار
void jameBordar(double bordar1[], double bordar2[], double natije[], int andaze) {
    // هر خونه از بردار اول رو با همون خونه از بردار دوم جمع می‌کنیم

    for(int i = 0; i < andaze; i++) {
        natije[i] = bordar1[i] + bordar2[i];
    }
}

// تابع تفریق دو بردار
void tafriqBordar(double bordar1[], double bordar2[], double natije[], int andaze) {
    // هر خونه از بردار دوم رو از بردار اول کم می‌کنیم

    for(int i = 0; i < andaze; i++) {
        natije[i] = bordar1[i] - bordar2[i];
    }
}

// تابع ضرب عدد در بردار
void zarbAdadDarBordar(double bordar[], double natije[], double adad, int andaze) {
    // هر خونه از بردار رو در عدد ضرب می‌کنیم

    for(int i = 0; i < andaze; i++) {
        natije[i] = bordar[i] * adad;
    }
}

// تابع ضرب داخلی دو بردار
double zarbDakheli(double bordar1[], double bordar2[], int andaze) {
    // ضرب داخلی = مجموع (هر خونه از بردار اول * همون خونه از بردار دوم)
    // نتیجه یه عدد هست، نه بردار

    double natije = 0;

    for(int i = 0; i < andaze; i++) {
        natije = natije + (bordar1[i] * bordar2[i]);
    }

    return natije;
}

// تابع ضرب خارجی دو بردار
void zarbKhareji(double bordar1[], double bordar2[], double natije[]) {
    // ضرب خارجی فقط برای بردارهای 3 تایی کار می‌کنه
    // فرمول:
    // اگه بردار اول = <a1, a2, a3>
    // و بردار دوم = <b1, b2, b3>
    // نتیجه = <a2*b3 - a3*b2, a3*b1 - a1*b3, a1*b2 - a2*b1>

    natije[0] = bordar1[1] * bordar2[2] - bordar1[2] * bordar2[1];
    natije[1] = bordar1[2] * bordar2[0] - bordar1[0] * bordar2[2];
    natije[2] = bordar1[0] * bordar2[1] - bordar1[1] * bordar2[0];
}

// تابع اندازه بردار
double andazeBordar(double bordar[], int andaze) {
    // فرمول اندازه بردار: جذر مجموع مربعات
    // مثلا برای بردار <3, 4>:
    // اندازه = sqrt(3*3 + 4*4) = sqrt(9 + 16) = sqrt(25) = 5

    double majmooMorabaat = 0;  // مجموع مربعات

    // اول مربع هر عدد رو جمع می‌کنیم
    for(int i = 0; i < andaze; i++) {
        majmooMorabaat = majmooMorabaat + (bordar[i] * bordar[i]);
    }

    // بعد جذر می‌گیریم
    double andaze_bordar = sqrt(majmooMorabaat);

    return andaze_bordar;
}

// تابع نرمال کردن بردار
void normalKardanBordar(double bordar[], double natije[], int andaze) {
    // نرمال کردن یعنی اندازه بردار رو 1 کنیم
    // روش: هر عدد رو تقسیم بر اندازه بردار می‌کنیم

    // اول اندازه بردار رو حساب می‌کنیم
    double andaze_bordar = andazeBordar(bordar, andaze);

    // اگه اندازه صفر باشه، نمیشه نرمال کرد
    if(andaze_bordar == 0) {
        cout << "\n error : nemishe bordar sefr ro normal kard!" << endl;
        return;
    }

    // هر عدد رو تقسیم بر اندازه می‌کنیم
    for(int i = 0; i < andaze; i++) {
        natije[i] = bordar[i] / andaze_bordar;
    }
}
