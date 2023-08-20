#include <stdio.h>
#include <stdio.h>
int weekday(int year);
int main()
{

  int year, month,week_day=0;

  printf("Enter The Year ");
  scanf("%d", &year);

  char *months[] = {"Jun", "Feb", "Mar", "Apl", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nev", "Dec"};
  char monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    monthDay[2] = 29;
  }

  int staringDay = weekday(year);
  for (month = 1; month <= 12; month++)
  {
    int monthInDay = monthDay[month];
    printf("\n\n---------%s---------\n", months[month]);
    printf("   Sun  Mon  Tus  Wed  Thu  Fri  Sat\n\n");

    for(week_day=0; week_day < staringDay; week_day++){
      printf("    ");
    }
    for (int day = 1; day <= monthInDay; day++)
    {
      printf("%5d", day);
      if (++week_day > 6)
      {
        printf("\n");
        week_day =0;
      }
      staringDay = week_day; 
    }
  }
}

int weekday(int year)
{
    int d = (((year - 1) + 365) + (year - 1) / 4 - ((year - 1) / 100) + (year / 400) + 1) % 7;
    return d;
}
