#include"Tuile.hpp"
#include<iostream>
#include<vector>


int main(){

    int h[3] = {0,2,3}, d[3] = {1,1,4}, b[3] = {4,0,2}, g[3] = {3,0,0};
    Tuile t{h,d,b,g};

    t.tourner();
    cout<<t<<endl;
    
    return EXIT_SUCCESS;
}