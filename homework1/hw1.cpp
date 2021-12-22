#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float dist(float xn, float yn, float x1, float y1) {
    return fabs((xn * y1 - yn * x1) / (sqrt(xn * xn + yn * yn)));
}

float angle_sign(float xn, float yn, float x1, float y1) {
    return xn * y1 - x1 * yn;
}

float get_coord_x(ifstream &input_file){
    string coord1;
    float x;
    input_file >> coord1;
    x = stof(coord1);
    return x;
}

float get_coord_y(ifstream &file){
    string coord2;
    float y;
    file >> ws >> coord2;
    y = stof(coord2);
    return y;
}

int main() {
    float lmx = 0;
    float lmy = 0;
    float rmx = 0;
    float rmy = 0;
    float main_x;
    float main_y;
    float x = 0;
    float y = 0;
    string s;

    ifstream file("in.txt");

    main_x = get_coord_x(file);
    main_y = get_coord_y(file);
    while(getline(file, s)){
        x = get_coord_x(file);
        y = get_coord_y(file);
        if(angle_sign(main_x, main_y, x, y) > 0) {
            if (dist(main_x, main_y, lmx, lmy) < dist(main_x, main_y, x, y)){
                lmx = x;
                lmy = y;
            }
        } else if(angle_sign(main_x, main_y, x, y) < 0){
            if(dist(main_x, main_y, rmx, rmy) < dist(main_x, main_y, x, y)){
                rmx = x;
                rmy = y;
            }
        }
    }

    cout << "Leftmost: " << lmx << ' ' << lmy << endl;
    cout << "Rightmost: " << rmx << ' ' << rmy << endl;
    file.close();
    return 0;
}

