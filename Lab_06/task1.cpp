#include <iostream>
#include <cmath>

int main()
{
    float ships[4][3] = {
        {1, 2, 3},
        {23, 44, 65},
        {17, 65, 43},
        {21, 32, 45},
    };
    float a, b, c;
    std::cin >> a >> b >> c;
    float x,y,z;
    int i;
    float mindist = 999999, dist;
    int dangerID = 0;
    float sumX = 0, sumY = 0, sumZ = 0;
    for ( i=1; i<4; i++){
        x = ships[i][0]-a;
        y = ships[i][1]-b;
        z = ships[i][2]-c;
        sumX += ships[i][0];
        sumY += ships[i][1];
        sumZ += ships[i][2];
        dist=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
        if (dist < mindist){
            mindist=dist; 
            dangerID = i;
        }
    }
    float avgX = sumX / 3;
    float avgY = sumY / 3;
    float avgZ = sumZ / 3;
    float targetX = a + (a - avgX);
    float targetY = b + (b - avgY);
    float targetZ = c + (c - avgZ);
    std::cout << " ID самого опасного вражеского кораьля: " << dangerID << "\n" 
    << " Координаты точки подальше от врагов: " << targetX << ' ' << targetY << ' ' << targetZ;

    return 0;
}