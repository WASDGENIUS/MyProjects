#include <iostream>
#include <string>
#include <cstring>


int main(){
    char str[100];
    std::cin >> str;
    int i,j,n;
    int len = strlen(str);
    for (i=0; i < len; i++){
        n=0;
        for (j=0; j < len; j++){
            if (str[i] == str[j]){
                n+=1;
            }
        }
        if (n==1) {
                    std::cout << str[i];
                }
    }





}