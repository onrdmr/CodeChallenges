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
        lli ballCount;
        std::cin >> ballCount;


        std::vector<lli> balls;
        std::map<lli,std::pair<lli,lli>> max_interval_map;
        std::vector<lli> dp_max_interval(ballCount, 0);
        

        for ( lli j = 0 ; j < ballCount ; j++ )
        {
            lli item;
            std::cin >> item;
            balls.push_back(item);
        }


        if(ballCount == 1) {
            std::cout << "0" << std::endl;
            continue;
        }


        for ( lli j = 0 ; j < ballCount ; j++ )
        {


            if ( max_interval_map.find(balls[j]) == max_interval_map.end() ) {
                max_interval_map[balls[j]] = std::pair(j,j);
            } else {
                // auto interval = max_interval_map[balls[j]];
                // if( dp_max_interval[interval.second] + j - interval.second + 1 > interval.second - interval.first + dp_max_interval[interval.first] + 1) {
                max_interval_map[balls[j]].first = max_interval_map[balls[j]].second;
                max_interval_map[balls[j]].second = j;
                //     max_interval_map[balls[j]].second = j;
                // } else {
                //     max_interval_map[balls[j]].second = j;
                // }
           
            }

            auto interval = max_interval_map[balls[j]];
            dp_max_interval[j] = std::max( 
                [&] -> lli { 
                    if ( interval.second - interval.first != 0  && dp_max_interval[interval.first] == 0 ) {
                        return interval.second - interval.first + dp_max_interval[interval.first] + 1;
                    } else if (dp_max_interval[interval.first-1] == dp_max_interval[interval.first] && interval.second - interval.first != 0) {
                        return interval.second - interval.first + dp_max_interval[interval.first]+1; 
                    } else if (interval.second - interval.first != 0){
                        return interval.second - interval.first + dp_max_interval[interval.first] ;
                    } else {
                        return 0;
                    }
                }(),
                dp_max_interval[std::abs(j-1)]
            );

        }

        std::cout << dp_max_interval[ballCount-1] << std::endl;

    }

    return 0;
}