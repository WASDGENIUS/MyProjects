#include <iostream>
#include "math.h"
int main() {

    // int n;
    // double u=0;
    // for (n = 1; n <= 27 ; n = n + 1) {
    //     double s = pow(-1,n) / (n*(n+1)*(n+2));
    //     u=u+s;
    // }
    // printf("%.4f", u);
    


    // double max = -99999.0;
    // int n = 0;
    // for (int i=1 ; i<=25 ; i++){
    //     double u = 5 * sqrt(i) * cos(0.9 * i);
    //     if (u > max){
    //         max = u;
    //         n = i;
    //     }
    // }
    // printf("%.4f, %i", max, n);




    // double x=2;
    // double sum=0;
    // double i=0;
    
    // double u=1;
    // double px=x;
    // double fact=1;

    // while (u > 0.0001) {
    //     if (i > 0) {
    //         fact = fact * (i + 1);
    //     }

    //     u = px / ((2*i+1) * fact);
        
    //     i++;
        
    //     sum=sum+u;

    //     px = px * (x * x);

    // }
    // printf("%f\n", sum);
    // printf("%.0f", i);





    // double x = 2;
    // double sum = 0;
    // double i = 1;
    // double u = x; 
    // sum = x; 
    // while (u > 0.0001) {
    //     u = u * ((x*x*(2*i-1)) / ((2*i+1)*(i+1)));
    //     sum = sum + u;
    //     i++;
    // }

    // printf("%.4f", sum);



    double ap=0;
    double ac=1;
    double an;
    int n=1;
    do
    {
        an=sin(ac)+ap;
        n++;
        ap=ac;
        ac=an;

    } while (ac<=5);
    printf("%i",n);


}