#include <iostream>

using namespace std;

// ۱. تعریف پروتوتایپ تابع برای اعلام حضور به کامپایلر
bool isPrime(int n);

int main() {
    int start, end;

    // گرفتن مقادیر شروع و پایان از کاربر
    cout << "Start value: ";
    cin >> start;
    cout << "End value: ";
    cin >> end;

    cout << "\nPrime Number between " << start << " to " << end << endl;
    cout << "==========================================================" << endl;

    // حلقه‌ای برای پیمایش تمام اعداد بین بازه مشخص شده
    for (int i = start; i <= end; i++) {
        // صدا زدن تابع؛ اگر عدد اول بود آن را چاپ کن
        if (isPrime(i)) {
            cout << i << "\t"; // استفاده از \t برای ایجاد فاصله منظم (Tab) بین اعداد
        }
    }

    cout << "\n==========================================================" << endl;

    return 0;
}

// ۲. بدنه اصلی تابع بررسی اول بودن عدد
bool isPrime(int n) {
    // اعداد کمتر یا مساوی ۱ اول نیستند
    if (n <= 1) {
        return false;
    }

    // بررسی اینکه آیا عدد بر رقمی بین ۲ تا قبل از خودش بخش‌پذیر هست یا نه
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // اگر بر هر عددی بخش‌پذیر شد، یعنی اول نیست
        }
    }

    return true; // اگر از حلقه بالا سلامت خارج شد، یعنی اول است
}