//
//  main.c
//  TempUnitConverter
//
//  Created by 최경민 on 2022/09/13.
//

#include <stdio.h>

double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);


int main(int argc, const char * argv[]) {
    double celsius, fahrenheit;
    printf("화씨온도: ");
    scanf("%lf", &fahrenheit);
    celsius = fahrenheitToCelsius(fahrenheit);
    // ⚠️ float by float => float
    printf("섭씨온도: %f\n", celsius);
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * (9.0/5.0) + 32);
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0/9.0);
}
