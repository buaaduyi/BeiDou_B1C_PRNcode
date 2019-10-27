//
//  main.cpp
//  B1C
//
//  Created by 杜毅 on 2019/10/27.
//  Copyright © 2019 杜毅. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;


const double w[63] = {2678, 4802, 958, 859, 3843, 2232, 124, 4352, 1816, 1126, 1860, 4800, 2267, 424, 4192, 4333, 2656, 4148, 243, 1330, 1593, 1470, 882, 3202, 5095, 2546, 1733, 4795, 4577, 1627, 3638, 2553, 3646, 1087, 1843, 216, 2245, 726, 1966, 670, 4130, 53 , 4830, 182, 2181, 2006, 1080, 2288, 2027, 271, 915, 497, 139, 3693, 2054, 4342, 3342, 2592, 1007, 310, 4203, 455, 4318};

const double p[63] = {699, 694, 7318, 2127, 715, 6682, 7850, 5495, 1162,  7682, 6792, 9973, 6596,2092 , 19, 10151, 6297, 5766,2359 , 7136, 1706, 2128,6827 , 693 , 9729, 1620, 6805, 534, 712, 1929, 5355, 6139, 6339, 1470, 6867, 7851 , 1162, 7659, 1156, 2672, 6043, 2862, 180, 2663, 6940, 1645, 1582, 951, 6878, 7701, 1823, 2391, 2606, 822, 6403, 239, 442, 6769, 2560, 2502, 5072, 7268, 341};
const int N = 10243;
const int n = 10230;


int main(){
    
    int prn;
    cout<<"Please input PRN: ";
    cin>>prn;
    if(prn>0&&prn<=63){
        
    }
    else{
        cout<<"Please input the correct PRN!"<<endl;
        return 0;
    }
    vector<int> L(N,0);
    vector<int> CB1C_data(n,0);
    
    for(int i = 0;i<N;i++){
       int t = (i*i)%N;
        L[t] = 1;
    }
    
    for(int i = 0;i<n;i++){
        int k1 = i+p[prn-1]-1;
        int k2 = k1+w[prn-1];
        int tamp1 = L[k1%N];
        int tamp2 = L[k2%N];
        if(tamp1 == tamp2){
            CB1C_data[i] = 0;
        }
        else{
            CB1C_data[i] = 1;
        }
    }
    
    cout<<"HEAD 24 bite: ";
    for(int i = 0;i<24;i++){
        cout<<CB1C_data[i];
    }
    cout<<endl;
    
    cout<<"TAIL 24 bite: ";
    for(int i = n-24;i<n;i++){
        cout<<CB1C_data[i];
    }
    cout<<endl;
    
    
    return 0;
    
    
    
}
