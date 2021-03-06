/*
  Sophia Zhang, Fall 2020
  This is the payr0ll program
 */
float wSalCalc(float payrate, int weeks);
float hSalCalc(float payrate, int hours);
float hSalInterCalc(float payrate, int hours);
float cSalCalc(int hours);
float cSalInterCalc(int hours);

#include <stdio.h>
int main(void){
  char inputW, inputH, inputC, input;
  int wTotalEmp, hTotalEmp, cTotalEmp, wFemEmp, hFemEmp, cFemEmp, wMaleEmp, hMaleEmp, cMaleEmp, wInterEmp, hInterEmp, cInterEmp, wDomEmp, hDomEmp, cDomEmp, weeks, hours, count;
  float wPay, hPay, avgFemSal, avgMaleSal, avgInterSal, avgDomSal, avgWSal, avgHSal, avgTotalSal, avgCSal;

  while(input != 'Q'){
    do{
      printf("\nMENU\nEnter the following employee totals for weekly, hourly, and commission workers in the format of 'W# H# C#': ");
      scanf("\n%c%i %c%i %c%i", &inputW, &wTotalEmp, &inputH, &hTotalEmp,&inputC, &cTotalEmp);
      printf("\n%c%i %c%i %c%i", inputW, wTotalEmp, inputH, hTotalEmp, inputC, cTotalEmp);
    }while((inputW != 'W' || inputH != 'H'|| inputC !='C') && inputW != 'Q' );
    //printf("\n%c%i %c%i %c%i", inputW, wTotalEmp, inputH, hTotalEmp, inputC, cTotalEmp);

    if(inputW == 'W' && inputH == 'H' && inputC == 'C'){
      input = 'E';
    }else{
      input = 'Q';
    }
    //printf("\n%c", input);
    
    switch(input){
    case 'Q':
      printf("\nQuit");
      break;
    case 'E':
      printf("\nEnter the male, female, international, and domestic employees and the weekly fixed rate in the format M# F# I# D# R#: ");
      scanf("\nM%i F%i I%i D%i R%f", &wMaleEmp, &wFemEmp, &wInterEmp, &wDomEmp, &wPay);
      printf("\nWeekly: M%i F%i I%i D%i R%.2f", wMaleEmp, wFemEmp, wInterEmp, wDomEmp, wPay);
      printf("\nEnter the male, female, international, and domestic employees and the hourly fixed rate in the format M# F# I# D# R#: ");
      scanf("\nM%i F%i I%i D%i R%f", &hMaleEmp, &hFemEmp, &hInterEmp, &hDomEmp, &hPay);
      printf("\nHourly: M%i F%i I%i D%i R%.2f", hMaleEmp, hFemEmp, hInterEmp, hDomEmp, hPay);
      printf("\nEnter the male, female, international, and domestic employees for commissioned workers in the format M# F# I# D#: ");
      scanf("\nM%i F%i I%i D%i", &cMaleEmp, &cFemEmp, &cInterEmp, &cDomEmp);
      printf("\nCommission: M%i F%i I%i D%i", cMaleEmp, cFemEmp, cInterEmp, cDomEmp);
      
      printf("\nFemale Weekly Employees: ");
      for(count = 1; count <= wFemEmp; ++count){
	printf("\nHow many weeks did #%i emp work: ", count);
	scanf("\n%i", &weeks);
	printf("\nWeeks: %i", weeks);
	avgWSal += wSalCalc(wPay, weeks);
	avgFemSal += wSalCalc(wPay, weeks);
      }
      printf("\nFemale Hourly Employees: ");
      for(count = 1; count <= hFemEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
	printf("\nHours: %i", hours);
        avgHSal += hSalCalc(hPay, hours);
        avgFemSal += hSalCalc(hPay, hours);
      }
      printf("\nFemale Commissioned Employees: ");
      for(count = 1; count <= cFemEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
	printf("\nHours: %i", hours);
        avgCSal += cSalCalc(hours);
        avgFemSal += cSalCalc(hours);
      }
      
      printf("\nMale Weekly Employees: ");
      for(count = 1; count <= wMaleEmp; ++count){
        printf("\nHow many weeks did #%i emp work: ", count);
        scanf("\n%i", &weeks);
        printf("\nWeeks: %i", weeks);
        avgWSal += wSalCalc(wPay, weeks);
        avgMaleSal += wSalCalc(wPay, weeks);
      }
      printf("\nMale Hourly Employees: ");
      for(count = 1; count <= hMaleEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgHSal += hSalCalc(hPay, hours);
        avgMaleSal += hSalCalc(hPay, hours);
      }
      printf("\nMale Commissioned Employees: ");
      for(count = 1; count <= cMaleEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgCSal += cSalCalc(hours);
        avgMaleSal += cSalCalc(hours);
      }

      printf("\nInternational Weekly Employees: ");
      for(count = 1; count <= wInterEmp; ++count){
        printf("\nHow many weeks did #%i emp work: ", count);
        scanf("\n%i", &weeks);
        printf("\nWeeks: %i", weeks);
        avgWSal += wSalCalc(wPay, weeks);
        avgInterSal += wSalCalc(wPay, weeks);
      }
      printf("\nInternational Hourly Employees: ");
      for(count = 1; count <= hInterEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgHSal += hSalInterCalc(hPay, hours);
        avgInterSal += hSalInterCalc(hPay, hours);
      }
      printf("\nInternational Commissioned Employees: ");
      for(count = 1; count <= cInterEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgCSal += cSalInterCalc(hours);
        avgInterSal += cSalInterCalc(hours);
      }

      printf("\nDomestic Weekly Employees: ");
      for(count = 1; count <= wDomEmp; ++count){
        printf("\nHow many weeks did #%i emp work: ", count);
	scanf("\n%i", &weeks);
        printf("\nWeeks: %i", weeks);
	avgWSal += wSalCalc(wPay, weeks);
        avgDomSal += wSalCalc(wPay, weeks);
      }
      printf("\nDomestic Hourly Employees: ");
      for(count = 1; count <= hDomEmp; ++count){
	printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgHSal += hSalCalc(hPay, hours);
        avgDomSal += hSalCalc(hPay, hours);
      }
      printf("\nDomestic Commissioned Employees: ");
      for(count = 1; count <= cDomEmp; ++count){
        printf("\nHow many hours did #%i emp work: ", count);
        scanf("\n%i", &hours);
        printf("\nHours: %i", hours);
        avgCSal += cSalCalc(hours);
        avgDomSal += cSalCalc(hours);
      }

      avgTotalSal = (avgCSal + avgHSal + avgWSal)/ (cTotalEmp + hTotalEmp +wTotalEmp);
      avgCSal =avgCSal/cTotalEmp;
      avgHSal =avgHSal/hTotalEmp;
      avgWSal =avgWSal/wTotalEmp;
      avgFemSal = avgFemSal/ (wFemEmp +hFemEmp + cFemEmp);
      avgMaleSal= avgMaleSal/ (wMaleEmp +hMaleEmp + cMaleEmp);
      avgInterSal = avgInterSal/ (wInterEmp + hInterEmp + cInterEmp);
      avgDomSal = avgDomSal/ (wDomEmp + hDomEmp + cDomEmp);

      printf("\nStatistics: ");
      printf("\nMen v Women");
      printf("\nWeekly| Men: %i Women: %i Total: %i", wMaleEmp, wFemEmp, wTotalEmp);
      printf("\nHourly| Men: %i Women: %i Total: %i", hMaleEmp, hFemEmp, hTotalEmp);      
      printf("\nCommission| Men: %i Women: %i Total: %i", cMaleEmp, cFemEmp, cTotalEmp);
      printf("\nInternational v. Domestic");
      printf("\nWeekly| International: %i Domestic: %i Total: %i", wInterEmp, wDomEmp, wTotalEmp);
      printf("\nHourly| International: %i Domestic: %i Total: %i", hInterEmp, hDomEmp, hTotalEmp);
      printf("\nCommission| International: %i Domestic: %i Total: %i", cInterEmp, cDomEmp, cTotalEmp);
      printf("\nAvg salaries");
      printf("\nAvg Male Salary: %.2f Avg Female Salary: %.2f", avgMaleSal, avgFemSal);
      printf("\nAvg International Salary: %.2f Avg Domestic Salary: %.2f", avgInterSal, avgDomSal);
      printf("\nAvg Weekly Salary: %.2f Avg Hourly Salary: %.2f Avg Commisionary Salary: %.2f", avgWSal, avgHSal, avgCSal);
      printf("\nAvg total salary: %.2f", avgTotalSal);
      break;
      
    }
    
  }
    return 0;
}

float wSalCalc(float payrate, int  weeks){
  float sal = payrate * weeks;
  return sal;
}

float hSalCalc(float payrate, int hours){
  float sal;
  if(hours > 10){
    sal = 10 * payrate + (1.5 * payrate * (hours - 10));
  }
  else{
    sal = hours * payrate;
  }
  return sal;
}

float cSalCalc(int hours){
  float sal = 250 + 7.1*hours;
  return sal;
}
float hSalInterCalc(float payrate, int hours){
  float sal;
  if(hours >= 20){
    sal = 10 * payrate + (1.5 * payrate * 10);
  }else if(hours < 20 && hours > 10){
    sal = 10 * payrate + (1.5 * payrate * (hours - 10));
  }else if(hours <= 10){
    sal = hours * payrate;
  }
  return sal;
}
float cSalInterCalc(int hours){
  float sal;
  if(hours >= 20){
    sal = 20 * 7.1 + 250;
  }
  else if (hours < 20){
    sal = hours*7.1 + 250;
  }
  return sal;
}
