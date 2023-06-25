#include <iostream>

typedef long long lli;

int main(int argc, char ** argv)
{
    lli size;

    std::cin >> size;

    for ( lli i = 0 ; i < size ; i++)
    {
        lli tenzing_s, tsondu_s, tenzing_pt=0, tsondu_pt=0;
        std::cin >> tenzing_s >> tsondu_s;

        for ( lli j = 0 ; j < tenzing_s ; j++) {
            lli tz_p ;
            std::cin >> tz_p;
            tenzing_pt += tz_p; 
        }

        for ( lli j = 0 ; j < tsondu_s ; j++) {
            lli ts_p ;
            std::cin >> ts_p;
            tsondu_pt += ts_p; 
        }

        if(tenzing_pt > tsondu_pt) {
            std::cout << "Tsondu" << std::endl;
        }
        else if(tsondu_pt > tenzing_pt) {
            std::cout << "Tenzing" << std::endl;
        } else 
        {
            std::cout << "Draw" << std::endl;
        }

    }

    return 0;
}