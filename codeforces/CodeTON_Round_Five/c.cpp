#include <iostream>
#include <vector>
#include <map>

typedef long long int lli;

// dp(i-1) + 1 | min(d(j+1) ) 2 - 4 
// şimdi i = 4, j = 2, 
int main(int argc, char ** argv)
{

    int testCase ;
    std::cin >> testCase;


    for ( lli i = 0 ; i < testCase ; i++ ) {
        int ballCount;
        std::cin >> ballCount;



        std::vector<lli> balls;
        std::map<lli,std::pair<lli,lli>> max_interval_map;
        std::vector<lli> dp_max_interval{0};

        for ( lli i = 0 ; i < dp_max_interval.size() ; i++ ) {
            std::cout << i << std::endl;
        }

        for ( lli j = 0 ; j < ballCount ; j++ )
        {
            lli item;
            std::cin >> item;
            balls.push_back(item);
        }


        for ( lli j = 0 ; j < ballCount ; j++ )
        {

            if ( max_interval_map.find(balls[j]) == max_interval_map.end() ) {
                max_interval_map[balls[j]] = max_interval_map[]
            } else {

            }



        }





    }


    
    



    return 0;
} 