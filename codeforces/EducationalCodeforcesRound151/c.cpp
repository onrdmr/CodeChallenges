#include <iostream>
#include <map>
#include <string>
#include <deque>
 
typedef long long int lli;
 
int main() {
 
    lli ts, p=0, pw_size;
    std::cin >> ts;
    std::string s, pw1, pw2;
    bool found = false;
 
 
    for ( lli i = 0 ; i < ts ; i++ )
    {
        std::cin >> s;
        std::cin >> pw_size;
        std::cin >> pw1;
        std::cin >> pw2;
        p = 0;
 
        std::map<int, std::deque<lli>> map;
 
        found = true;
 
        for ( lli j = 0 ; j < s.size() ; j++ )
        {
            map[s[j] - '0'].push_back(j);
        }
 
        int max = 0;
        for( lli j = 0 ; j < pw_size ; j++ )
        {
            
            lli lw = pw1.at(j) - '0';
            lli hg = pw2.at(j) - '0';
 
            int n_max = 0;
            for ( lli k = lw ; k <= hg ; k++ )
            {   
                if( map.find(k) == map.end() )
                {
                    found = false;
                    goto check;
                }
                bool stop = true;
                bool bs_found = false;
                int rm_idx = map[k].size() - 1;
                int lm_idx = 0;
                int m_idx ;

                while( stop ) {
                    m_idx = lm_idx + (rm_idx - lm_idx ) / 2 ;

                    if ( map[k].size() == 0 ) 
                    {
                        stop = false;
                        continue;
                    } 
                    else if ( m_idx >= 1 && map[k][m_idx] >= max && map[k][m_idx-1] <= max ) {
                        stop = false;
                        bs_found = true;
                    }
                    else if ( map[k][m_idx] >= max ) {
                        // m_idx = lm_idx + (rm_idx - lm_idx)  / 2;
                        rm_idx = m_idx;
                        if ( m_idx == 0 )
                        {
                            bs_found = true;
                        }
                    } else {
                        lm_idx = m_idx+1; 
                    }
                    if( m_idx == 0 || m_idx == map[k].size() -1 )
                    {
                        stop = false;
                    }
                }
                if ( bs_found ) {
                    if(map[k][m_idx] > n_max)
                    {
                        n_max = map[k][m_idx];

                    }
                } else {
                    found = false;
                    goto check;
                }
                map[k].pop_front();
            }
            
            if ( n_max >= max ) {
                max = n_max;
            }
            else {
                found = false;
                goto check;
            }
        }
        
        check:
        if ( found == true )
        {
            std::cout << "NO" << std::endl;
        }
        else {
            std::cout << "YES" << std::endl;
        }
 
        found = true;
    }
 
 
    return 0;
}