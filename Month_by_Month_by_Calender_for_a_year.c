#include <stdio.h>

int main() {
    int year, month, day, startDay, i;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter year: ");
    if (scanf("%d", &year) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Adjust February for leap years */
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    /* Calculate starting day of the week for Jan 1 (0 = Sun, 1 = Mon, ..., 6 = Sat) */
    startDay = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
    if (startDay < 0) {
        startDay += 7;
    }

    printf("\n==================== Calendar - %d ====================\n", year);

    for (month = 0; month < 12; month++) {
        printf("\n------------ %s %d ------------\n", months[month], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        /* Indent the first day of the month */
        for (i = 0; i < startDay; i++) {
            printf("    ");
        }

        /* Print all dates of the current month */
        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%4d", day);
            if ((startDay + day) % 7 == 0) {
                printf("\n");
            }
        }

        /* Move to a new line if the last week didn't end on Saturday */
        if ((startDay + daysInMonth[month]) % 7 != 0) {
            printf("\n");
        }

        /* Carry over the starting weekday to the next month */
        startDay = (startDay + daysInMonth[month]) % 7;
    }

    return 0;
}
