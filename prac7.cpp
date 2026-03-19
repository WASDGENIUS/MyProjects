#include <iostream>
using namespace std;
// void swal(float& a, float& b)
// {
//     a += b;
//     b = a - b;
//     a = a - b;

// }

// int main()
// {
//     float a, b;
//     cin >> a >> b;
//     swal(a, b);
//     cout << a << " " << b << endl;
//     return 0;

// }



// float f1(float x);
// float f2(float x);
// float f3(float x);
// void print(float x, float (*y)(float));

// int main()
// {
//     float x = 0.6f, y = 0.3f, z = 0.1f;
//     cout << "f1=";
//     print(x, f1);
//     cout << "f2=" ;
//     print(y, f2);
//     cout << "f3=" ;
//     print(z, f3);
//     float r = f1(x) + f2(y) * f3(f2(z));
//     cout << r << endl;

//     return 0;
// }

// float f1(float x)
// {
//     return sin(x) / x;
// }

// float f2(float x)
// {
//     return x * x + 2 * pow(x, 1.5);
// }

// float f3(float x)
// {
//     return (x+2) * (x+1) * x;
// }

// void print(float x, float (*y)(float))
// {
//     cout << y(x) << endl;
// }


// float max(float a, float b){
//     return a>b ? a:b;
// }

// float min(float a, float b){
//     return a<b ? a:b;
// }

// float max(float* array, int k){
//     float m = array[0];
//     for(int i=1; i<k; i++){
//         m = max(m, array[i]);
//     }
//     return m;
// }

// float min(float* array, int k){
//     float m = array[0];
//     for(int i=1; i<k; i++){
//         m = min(m, array[i]);
//     }
//     return m;
// }

// int main(){
//     const int k1 = 3, k2 = 5;
//     float array1[3] = {1.0f, 2.0f, 3.0f};
//     float array2[5] = {4.0f, 5.0f, -3.0f, 0.0f, 0.1f};
//     printf("%f\n", min(array1, k1 ) * min(array2, k2));
//     printf("%f\n", sqrt(max(array1, k1) * max(array2, k2)));
//     return 0;
// }


