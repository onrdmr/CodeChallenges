#include <iostream>
#include <map>


typedef  long long int lli;

int main()
{
    lli test_size, n, k, x;

    std::cin >> test_size;
        

    for( lli i = 0 ; i < test_size ; i++) {
        std::cin >> n >> k >> x;

        if(k == 1 && x == 1) {
            std::cout << "NO" << std::endl;
        }

        else if(x != 1) {
            std::cout << "YES" << std::endl;
            std::cout << n << std::endl;
            for(lli j = 0 ; j < n ; j++) {
                std::cout << 1 << " ";
            }
            std::cout << std::endl;
        }
        else {
            lli num = n;
            while(num>0){
                num -= 2;
            }
            if(num == 0) {
                std::cout << "YES" << std::endl;
                std::cout << n/2 << std::endl;
                for(lli j = 0 ; j < n/2 ; j++) {
                    std::cout << 2 << " ";
                }
                std::cout << std::endl;
            }
            else if (num == -1 && k >= 3) {
                std::cout << "YES" << std::endl;
                std::cout << n/2 << std::endl;
                for(lli j = 0 ; j < n/2-1 ; j++) {
                    std::cout << 2 << " ";
                }
                std::cout << 3 << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }

    }

    return 0;
}