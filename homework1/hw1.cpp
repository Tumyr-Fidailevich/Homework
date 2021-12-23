#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double dist(double xn, double yn, double x1, double y1) {
    return fabs((xn * y1 - yn * x1) / (sqrt(xn * xn + yn * yn)));
}

double angle_sign(double xn, double yn, double x1, double y1) {
    return xn * y1 - x1 * yn;
}

double get_coord_x(ifstream &input_file){
    string coord1;
    double x;
    input_file >> coord1;
    x = stof(coord1);
    return x;
}

double get_coord_y(ifstream &file){
    string coord2;
    double y;
    file >> ws >> coord2;
    y = stof(coord2);
    return y;
}

int main() {
    double lmx = 0;
    double lmy = 0;
    double rmx = 0;
    double rmy = 0;
    double main_x;
    double main_y;
    double x = 0;
    double y = 0;
    string s;

    ifstream file("in.txt");

    main_x = get_coord_x(file);
    main_y = get_coord_y(file);
    while(getline(file, s)){
        x = get_coord_x(file);
        y = get_coord_y(file);
        if(angle_sign(main_x, main_y, x, y) > 0) {
            if (dist(main_x, main_y, lmx, lmy) <= dist(main_x, main_y, x, y)){
                lmx = x;
                lmy = y;
            }
        } else if(angle_sign(main_x, main_y, x, y) <= 0){
            if(dist(main_x, main_y, rmx, rmy) <= dist(main_x, main_y, x, y)){
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
