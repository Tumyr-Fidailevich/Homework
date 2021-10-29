#include "iostream"
#include <fstream>
#include <vector>

using namespace std;

float get_coord_x(ifstream &file){
    string coord1;
    float x;
    file >> coord1;
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

float height(float x, float h_0, float v0x, float v0y, float trig){
    float y = h_0 + x * trig * v0y / v0x - (9.81 / 2) * x * x / (v0x * v0x);
    return y;
}

int main(int agrc, char** argv) {
    float y, h, vx, vy, direction = 1;
    vector<float*> coord;
    int i = 0;
    string s;
    if (argc == 2){
        cout << "1st argument: " << argv[1] << endl;
    }else{
        ifstream file("in.txt");

        h = get_coord_x(file);
        getline(file, s);
        vx = get_coord_x(file);
        vy = get_coord_y(file);
        while(getline(file, s)) {
            float arr[2];
            arr[0] = get_coord_x(file);
            arr[1] = get_coord_y(file);
            coord.push_back(arr);
        }
        while(true){
            y = height(coord[i][0], h, vx, vy, direction);
            if (y > coord[i][1]){
                ++i;
            }else if(y < 0 or i == coord.size()){
                break;
            }else{
                direction = -1.0f * direction;
                --i;
            }
        }
    }
    cout << i << endl;
    return 0;
}


