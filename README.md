# Calendar-Generation-in-C



# Assignment 10: Calendar Generation in C

## Problem Statement
Write a C program to print the month-by-month calendar for a given year.

## Objective
To implement date and time functions in C programming.

## Theory

### 1. What are the essential header files used in this program, and what are their roles?
- **`stdio.h`** – Provides input and output functions such as `printf()` and `scanf()`.
- **`time.h`** – Provides date and time-related types and functions, including `struct tm` and `mktime()`.

The `struct tm` structure stores calendar information such as the year, month, day, and weekday. The `mktime()` function converts a broken-down calendar time into a `time_t` value and normalizes the structure.

### 2. How does the program determine if a year is a leap year?
A year is a leap year if:
- It is divisible by 400, or
- It is divisible by 4 but not by 100.

For example, 2024 and 2000 are leap years, while 1900 and 2025 are not.

### 3. What are the Gregorian calendar rules for determining a leap year?
According to the Gregorian calendar:
- Years divisible by 4 are generally leap years.
- Years divisible by 100 are not leap years unless they are also divisible by 400.

A leap year has 366 days, while a normal year has 365 days.

## Algorithm
1. Start the program.
2. Accept the year from the user.
3. Define the names of all 12 months and the number of days in each month.
4. Check whether the year is a leap year.
5. If it is a leap year, set February to 29 days; otherwise, set it to 28 days.
6. For each month, determine the weekday of its first day using `mktime()`.
7. Print the month name and weekday headings.
8. Print the dates in the correct positions according to the first weekday.
9. Repeat for all 12 months.
10. Stop the program.

## C Program
```c
#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    char *monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    char *weekDays[] = {
        "Sun", "Mon", "Tue", "Wed",
        "Thu", "Fri", "Sat"
    };

    struct tm date = {0};

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1)
    {
        printf("Invalid year.\n");
        return 1;
    }

    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        daysInMonth[1] = 29;
    }

    for (month = 0; month < 12; month++)
    {
        date = (struct tm){0};
        date.tm_year = year - 1900;
        date.tm_mon = month;
        date.tm_mday = 1;
        date.tm_isdst = -1;

        if (mktime(&date) == (time_t)-1)
        {
            printf("Unable to calculate calendar.\n");
            return 1;
        }

        printf("\n\n       %s %d\n", monthNames[month], year);

        for (int i = 0; i < 7; i++)
        {
            printf("%4s", weekDays[i]);
        }
        printf("\n");

        for (int i = 0; i < date.tm_wday; i++)
        {
            printf("    ");
        }

        for (day = 1; day <= daysInMonth[month]; day++)
        {
            printf("%4d", day);

            if ((date.tm_wday + day) % 7 == 0)
            {
                printf("\n");
            }
        }

        if ((date.tm_wday + daysInMonth[month]) % 7 != 0)
        {
            printf("\n");
        }
    }

    return 0;
}
```

## Sample Input
```text
Enter year: 2024
```

## Sample Output
The program displays all 12 months of 2024 in a formatted calendar. The beginning of the output will look like this:

```text
       January 2024
 Sun Mon Tue Wed Thu Fri Sat
   1   2   3   4   5   6
   7   8   9  10  11  12  13
  14  15  16  17  18  19  20
  21  22  23  24  25  26  27
  28  29  30  31
```

The program continues by displaying February through December. February contains 29 days in 2024 because 2024 is a leap year.

## Platform
Linux

## FAQ's

### 1. How does the program calculate the number of days in each month?
The program stores the number of days in each month in an array. January, March, May, July, August, October, and December have 31 days. April, June, September, and November have 30 days. February has 28 days in a normal year and 29 days in a leap year.

### 2. What is the significance of leap year conditions in a calendar program?
Leap year conditions ensure that February has the correct number of days and that the calendar accurately represents the given year.

### 3. How can the program determine the first day of the year?
The program can initialize a `struct tm` structure for the first day of January and use `mktime()` to determine its weekday through the `tm_wday` member. In this program, the same method is used to determine the first weekday of every month.

## Conclusion
Thus, generating a formatted month-by-month calendar for a given year was implemented successfully using C programming and date and time functions.
