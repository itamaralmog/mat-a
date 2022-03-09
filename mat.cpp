
#include "mat.hpp"

#include <iostream>

#include <string>

#include <vector>
using namespace std;

namespace ariel
{
    string mat(int width , int hight , char fillout, char fillin){

        if(hight < 1 || width <1){
            throw std::out_of_range{"Mat size is always positive and odd"};
        }
        if(hight % 2 != 1 || width % 2 !=1){
            throw std::out_of_range{"Mat size is always odd"};
        }
        string mat_string;
        vector<vector<char>> mat;

        for(int i = 0 ; i < hight ; i++){
            vector<char> v;
            v.assign(width, fillin); // clang++ overload.cpp -o overload 
            mat.push_back(v);
        }

        for(int line = 0 ; line <= hight/2 + 1; line +=2){
            for(int j = line ; j < width - line ; j++){
                mat[line][j]= fillout;
                mat[hight -line-1][j] = fillout;
            }
        }
        for(int line = 0 ; line <= width/2 +1 ; line +=2){
            for(int j = line ; j < hight - line ; j++){
                mat[j][line]= fillout;
                mat[j][width -line-1] = fillout;
            }
        }
        
        for(int i = 0 ; i < hight ; ++i){
            for(int j = 0; j < width ; j++){
                mat_string += mat[i][j];
            }
        }  
        return mat_string;

    }
}
