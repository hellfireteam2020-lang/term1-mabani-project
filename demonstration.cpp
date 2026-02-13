// =============================================
// برنامه اصلی - نمایش کتابخانه
// نام فایل: demonstration.cpp
// =============================================

#include <iostream>
#include "matrix_library.h"
using namespace std;


// =============================================
// تابع نمایش منوی اصلی
// =============================================
void namayeshMenu() {
    cout << "\n";
    cout << "============================================\n";
    cout << "   matrix and bordar library - term1 project\n";
    cout << "============================================\n";
    cout << "\n--- matrix opporations ---\n";
    cout << "1.  sum matrixes\n";
    cout << "2.  tafrigh matrixes\n";
    cout << "3.  zarb matrixes\n";
    cout << "4.  zarb yek adad dar matrix\n";
    cout << "5.  taranhadeh matrix\n";
    cout << "6.  determinan matrix\n";
    cout << "7.  reverse matrix\n";
    cout << "\n--- bordari opporations ---\n";
    cout << "8.  sum bordars\n";
    cout << "9.  tafrigh bordar ha\n";
    cout << "10. zarb folan adad dar bordar\n";
    cout << "11. zarb dakheli bordar\n";
    cout << "12. zarb khareji bordar\n";
    cout << "13. andaze bordar\n";
    cout << "14. normalise bordar\n";
    cout << "\n0.  exit\n";
    cout << "============================================\n";
    cout << "choose: ";
}


// =============================================
// توابع مربوط به گرفتن ورودی
// =============================================

// تابع برای گرفتن مقادیر یک ماتریس از کاربر
void voroodiMatris(double matris[][3], int satr, int sotun) {
    cout << "maghadir matrix " << satr << "x" << sotun << " ro vared konid:\n";

    for(int i = 0; i < satr; i++) {
        for(int j = 0; j < sotun; j++) {
            cout << "khoone [" << i+1 << "][" << j+1 << "]: ";
            cin >> matris[i][j];
        }
    }
}

// تابع برای گرفتن مقادیر یک بردار از کاربر
void voroodiBordar(double bordar[], int andaze) {
    cout << "maghadir bordar " << andaze << " tayi ro vared kon:\n";

    for(int i = 0; i < andaze; i++) {
        cout << "onsor " << i+1 << ": ";
        cin >> bordar[i];
    }
}


// =============================================
// عملیات ماتریسی
// =============================================

void amalJameMatris() {
    cout << "\n=== sum matrixes ===\n";

    int satr, sotun;
    cout << "tedad satr ha: ";
    cin >> satr;
    cout << "tedad sotoon ha: ";
    cin >> sotun;

    // تعریف ماتریس‌ها
    double matris1[3][3];
    double matris2[3][3];
    double natije[3][3];

    // گرفتن ورودی
    cout << "\n first matrix:\n";
    voroodiMatris(matris1, satr, sotun);

    cout << "\n second matrix:\n";
    voroodiMatris(matris2, satr, sotun);

    // انجام عملیات
    jameMatris(matris1, matris2, natije, satr, sotun);

    // نمایش نتیجه
    cout << "\n first matrix:";
    chapMatris(matris1, satr, sotun);

    cout << "\n second matrix:";
    chapMatris(matris2, satr, sotun);

    cout << "\n first matrix + second matrix):";
    chapMatris(natije, satr, sotun);
}

void amalTafriqMatris() {
    cout << "\n=== tafrigh matrixes ===\n";

    int satr, sotun;
    cout << "tedad satr ha: ";
    cin >> satr;
    cout << "tedad sotoon ha: ";
    cin >> sotun;

    double matris1[3][3];
    double matris2[3][3];
    double natije[3][3];

    cout << "\n first matrix:\n";
    voroodiMatris(matris1, satr, sotun);

    cout << "\n second matrix:\n";
    voroodiMatris(matris2, satr, sotun);

    tafriqMatris(matris1, matris2, natije, satr, sotun);

    cout << "\n first matrix:";
    chapMatris(matris1, satr, sotun);

    cout << "\n second matrix:";
    chapMatris(matris2, satr, sotun);

    cout << "\n (first matrix - second matrix) natijeh:";
    chapMatris(natije, satr, sotun);
}

void amalZarbMatris() {
    cout << "\n=== zarb 2 matrix ===\n";

    int satr1, sotun1, satr2, sotun2;

    cout << "first matrix:\n";
    cout << "  tedad satr ha: ";
    cin >> satr1;
    cout << "  tedad soton ha: ";
    cin >> sotun1;

    cout << "second matrix:\n";
    cout << "  tedad satr ha: ";
    cin >> satr2;
    cout << "  tedad soton ha: ";
    cin >> sotun2;

    // بررسی امکان ضرب
    if(sotun1 != satr2) {
        cout << "\n error: nemishe in matrix ha ro zarb kard!\n";
        cout << "baraye zarb bayad tedad satr haye matrix aval barabar ba tedad soton haye matrix dovom bashe.\n";
        return;
    }

    double matris1[3][3];
    double matris2[3][3];
    double natije[3][3];

    cout << "\n first matrix:\n";
    voroodiMatris(matris1, satr1, sotun1);

    cout << "\n second matrix:\n";
    voroodiMatris(matris2, satr2, sotun2);

    zarbMatris(matris1, matris2, natije, satr1, sotun1, satr2, sotun2);

    cout << "\n first matrix:";
    chapMatris(matris1, satr1, sotun1);

    cout << "\n second matrix:";
    chapMatris(matris2, satr2, sotun2);

    cout << "\n (first matrix * second matrix)natijeh:";
    chapMatris(natije, satr1, sotun2);
}

void amalZarbAdadDarMatris() {
    cout << "\n=== zarb adad dar matrix ===\n";

    int satr, sotun;
    double adad;

    cout << "tedad satr ha: ";
    cin >> satr;
    cout << "tedad soton ha: ";
    cin >> sotun;

    double matris[3][3];
    double natije[3][3];

    cout << "\n matrix:\n";
    voroodiMatris(matris, satr, sotun);

    cout << "\n adad mored nazar khod ra vared konid: ";
    cin >> adad;

    zarbAdadDarMatris(matris, natije, adad, satr, sotun);

    cout << "\n matrixe asli:";
    chapMatris(matris, satr, sotun);

    cout << "\n natije (" << adad << " × matrix):";
    chapMatris(natije, satr, sotun);
}

void amalTaranahade() {
    cout << "\n=== taranhadeh matrix ===\n";

    int satr, sotun;
    cout << "tedad satr ha: ";
    cin >> satr;
    cout << "tedad sotoon ha: ";
    cin >> sotun;

    double matris[3][3];
    double natije[3][3];

    cout << "\n matrix:\n";
    voroodiMatris(matris, satr, sotun);

    taranahadeMatris(matris, natije, satr, sotun);

    cout << "\n matrixe asli (" << satr << "x" << sotun << "):";
    chapMatris(matris, satr, sotun);

    cout << "\n taranhade (" << sotun << "x" << satr << "):";
    chapMatris(natije, sotun, satr);
}

void amalDeterminan() {
    cout << "\n=== mohasebe determinan ===\n";

    int andaze;
    cout << "andaze matrixe morabaei (2 or 3): ";
    cin >> andaze;

    if(andaze != 2 && andaze != 3) {
        cout << "\n error : faghat matrixe 2 dar 2 ya 3 dar 3 vared konnn!!!!!\n";
        return;
    }

    double matris[3][3];

    cout << "\n matrix:\n";
    voroodiMatris(matris, andaze, andaze);

    double det = hesabDeterminan(matris, andaze);

    cout << "\n matrix:";
    chapMatris(matris, andaze, andaze);

    cout << "\n determinan = " << det << endl;
}

void amalMakoos() {
    cout << "\n=== mohasebe reverse matrix ===\n";

    int andaze;
    cout << "andaze matrixe morabaei (2 or 3): ";
    cin >> andaze;

    if(andaze != 2 && andaze != 3) {
        cout << "\n error : faghat matrixe 2 dar 2 ya 3 dar 3 vared konnn!!!!!\n";
        return;
    }

    double matris[3][3];
    double natije[3][3];

    cout << "\n matrix:\n";
    voroodiMatris(matris, andaze, andaze);

    cout << "\n matrixe asli:";
    chapMatris(matris, andaze, andaze);

    // محاسبه دترمینان برای بررسی
    double det = hesabDeterminan(matris, andaze);
    cout << "\n determinan = " << det << endl;

    if(det == 0) {
        cout << "\n in matrix reverse nadare!\n";
        return;
    }

    hesabMakoos(matris, natije, andaze);

    cout << "\n reverse matrix:";
    chapMatris(natije, andaze, andaze);
}


// =============================================
// عملیات برداری
// =============================================

void amalJameBordar() {
    cout << "\n=== sum 2 bordar ===\n";

    int andaze;
    cout << "andazeh bordar ha (2 or 3): ";
    cin >> andaze;

    double bordar1[3];
    double bordar2[3];
    double natije[3];

    cout << "\n first bordar:\n";
    voroodiBordar(bordar1, andaze);

    cout << "\n second bordar:\n";
    voroodiBordar(bordar2, andaze);

    jameBordar(bordar1, bordar2, natije, andaze);

    cout << "\n first bordar: ";
    chapBordar(bordar1, andaze);

    cout << "second bordar: ";
    chapBordar(bordar2, andaze);

    cout << "natijeh: ";
    chapBordar(natije, andaze);
}

void amalTafriqBordar() {
    cout << "\n=== tafrigh 2 bordar ===\n";

    int andaze;
    cout << "andazeh bordar ha (2 or 3): ";
    cin >> andaze;

    double bordar1[3];
    double bordar2[3];
    double natije[3];

    cout << "\n first bordar:\n";
    voroodiBordar(bordar1, andaze);

    cout << "\n second bordar:\n";
    voroodiBordar(bordar2, andaze);

    tafriqBordar(bordar1, bordar2, natije, andaze);

    cout << "\n first bordar: ";
    chapBordar(bordar1, andaze);

    cout << "second bordar: ";
    chapBordar(bordar2, andaze);

    cout << "natijeh: ";
    chapBordar(natije, andaze);
}

void amalZarbAdadDarBordar() {
    cout << "\n=== zarb adad dar bordar ===\n";

    int andaze;
    double adad;

    cout << "andazeh bordar ha (2 or 3): ";
    cin >> andaze;

    double bordar[3];
    double natije[3];

    cout << "\n bordar:\n";
    voroodiBordar(bordar, andaze);

    cout << "\n adade morede nazar: ";
    cin >> adad;

    zarbAdadDarBordar(bordar, natije, adad, andaze);

    cout << "\n bordare asli: ";
    chapBordar(bordar, andaze);

    cout << "natije (" << adad << " × bordar): ";
    chapBordar(natije, andaze);
}

void amalZarbDakheli() {
    cout << "\n=== zarb dakheli 2 bordar ===\n";

    int andaze;
    cout << "andazeh bordar ha (2 or 3): ";
    cin >> andaze;

    double bordar1[3];
    double bordar2[3];

    cout << "\n first bordar:\n";
    voroodiBordar(bordar1, andaze);

    cout << "\n second bordar:\n";
    voroodiBordar(bordar2, andaze);

    double natije = zarbDakheli(bordar1, bordar2, andaze);

    cout << "\n first bordar: ";
    chapBordar(bordar1, andaze);

    cout << "second bordar: ";
    chapBordar(bordar2, andaze);

    cout << "\n zarb dakheli = " << natije << endl;
}

void amalZarbKhareji() {
    cout << "\n=== zarb kharejie 2 bordar ===\n";
    cout << "(faghat baraye bordar haye 3 tayi)\n";

    double bordar1[3];
    double bordar2[3];
    double natije[3];

    cout << "\n first bordar:\n";
    voroodiBordar(bordar1, 3);

    cout << "\n second bordar:\n";
    voroodiBordar(bordar2, 3);

    zarbKhareji(bordar1, bordar2, natije);

    cout << "\n first bordar: ";
    chapBordar(bordar1, 3);

    cout << "second bordar: ";
    chapBordar(bordar2, 3);

    cout << "natijeh(first*second): ";
    chapBordar(natije, 3);
}

void amalAndazeBordar() {
    cout << "\n=== mohasebe andaze bordar ===\n";

    int andaze;
    cout << "andazeh bordar (2 or 3): ";
    cin >> andaze;

    double bordar[3];

    cout << "\n bordar:\n";
    voroodiBordar(bordar, andaze);

    double andaze_bordar = andazeBordar(bordar, andaze);

    cout << "\n bordar: ";
    chapBordar(bordar, andaze);

    cout << "andazeh = " << andaze_bordar << endl;
}

void amalNormalKardan() {
    cout << "\n=== normalize bordar ===\n";

    int andaze;
    cout << "andazeh bordar (2 or 3): ";
    cin >> andaze;

    double bordar[3];
    double natije[3];

    cout << "\n bordar:\n";
    voroodiBordar(bordar, andaze);

    normalKardanBordar(bordar, natije, andaze);

    cout << "\n bordare asli: ";
    chapBordar(bordar, andaze);

    cout << "nomalized bordar: ";
    chapBordar(natije, andaze);

    double andaze_jadid = andazeBordar(natije, andaze);
    cout << "andazeh bordareh normal = " << andaze_jadid << " (bayad taghriba 1 basheh)" << endl;
}


// =============================================
// تابع اصلی برنامه
// =============================================
int main() {

    int entekhab;

    cout << "welcome!\n";

    // حلقه اصلی برنامه
    do {
        namayeshMenu();
        cin >> entekhab;

        // اجرای عملیات انتخاب شده
        switch(entekhab) {
            case 1:
                amalJameMatris();
                break;
            case 2:
                amalTafriqMatris();
                break;
            case 3:
                amalZarbMatris();
                break;
            case 4:
                amalZarbAdadDarMatris();
                break;
            case 5:
                amalTaranahade();
                break;
            case 6:
                amalDeterminan();
                break;
            case 7:
                amalMakoos();
                break;
            case 8:
                amalJameBordar();
                break;
            case 9:
                amalTafriqBordar();
                break;
            case 10:
                amalZarbAdadDarBordar();
                break;
            case 11:
                amalZarbDakheli();
                break;
            case 12:
                amalZarbKhareji();
                break;
            case 13:
                amalAndazeBordar();
                break;
            case 14:
                amalNormalKardan();
                break;
            case 0:
                cout << "\n khooroj az barname...good luck\n";
                break;
            default:
                cout << "\n error: wrong number...try again.\n";
        }

    } while(entekhab != 0);

    return 0;
}
