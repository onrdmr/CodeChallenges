#include <iostream>
#include <map>

typedef long long int lli;

int main() {

    lli ts, p=0, pw_size;
    std::cin >> ts;
    std::string s, pw1, pw2;
    bool found = false;

    std::map<lli, std::pair<lli, lli>>  is;

    for ( lli i = 0 ; i < ts ; i++ )
    {
        std::cin >> s;
        std::cin >> pw_size;
        std::cin >> pw1;
        std::cin >> pw2;
        p = 0;

        found = false;

        for ( lli j = 0 ; j < s.size() ; j++ )
        {
            if(is.find(j) == is.cend()) {
                is[s.at(j)].first = j;
                is[s.at(j)].second = j;
                continue;
            }
            is[s.at(j)].second = j;
        }
        for ( lli j = 0 ; j < s.size() ; j++ )
        {
            
        }

        if ( found == true )
        {
            std::cout << "NO" << std::endl;
        }
        else {
            std::cout << "YES" << std::endl;
        }
    }


    return 0;
}

/*
1
111100001010111001000
7
0000000
0111111

*/