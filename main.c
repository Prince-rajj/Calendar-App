#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // for system("cls")

int getFirstDayOfMonth(int month, int year) {
    // Zeller’s Congruence Formula
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    return (1 + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printCalendar(int month, int year) {
    system("cls"); // clear console (for Windows)

    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) daysInMonth[1] = 29;

    time_t now = time(NULL);
    struct tm *today = localtime(&now);

    int startingDay = getFirstDayOfMonth(month + 1, year);

    printf("\n\n\t   %s %d\n", months[month], year);
    printf("\tSu Mo Tu We Th Fr Sa\n");

    int day;
    for (day = 0; day < startingDay; day++)
        printf("   ");

    for (int date = 1; date <= daysInMonth[month]; date++) {
        // Highlight today's date
        if (date == today->tm_mday && month == today->tm_mon && year == (today->tm_year + 1900))
            printf("\x1b[31m%2d\x1b[0m ", date); // Red for today
        else
            printf("%2d ", date);

        if (++day % 7 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    int month, year;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    month = tm->tm_mon;
    year = tm->tm_year + 1900;

    int choice;
    while (1) {
        printCalendar(month, year);
        printf("\n1. Previous Month\n2. Next Month\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (--month < 0) {
                month = 11;
                year--;
            }
        } else if (choice == 2) {
            if (++month > 11) {
                month = 0;
                year++;
            }
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}
