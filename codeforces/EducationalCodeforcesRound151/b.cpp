#include <iostream>
#include <array>


typedef long long int lli;

int main()
{

    lli test_size;
    
    std::cin >> test_size;

    std::array<std::pair<lli,lli>,3> map ;

    for ( lli i = 0 ; i < test_size ; i++ ) {
        lli f_x=0,f_y=0, s_x=0, s_y=0, itinary = 1, delta_x = 0, delta_y = 0;
        for(lli j = 0 ; j < 3 ; j++) {
            std::cin >> map[j].first >> map[j].second;
        }
        
        f_y = ( map[1].second - map[0].second );
        f_x = ( map[1].first - map[0].first );
        s_x= (map[2].first - map[0].first);
        s_y= (map[2].second - map[0].second);

        if ( f_y < 0 && s_y < 0 || f_y > 0 && s_y > 0 ) {
            delta_y = std::min( std::abs(f_y), std::abs(s_y) );
        } 
        if ( f_x < 0 && s_x < 0 || f_x > 0 && s_x > 0 ) {
            delta_x = std::min( std::abs(f_x), std::abs(s_x) );
        } 
        
        itinary += delta_x + delta_y; 
        std::cout << itinary << std::endl; 
    }



    return 0;
}