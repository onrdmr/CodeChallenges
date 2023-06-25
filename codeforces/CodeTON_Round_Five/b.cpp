#include <iostream>
#include <vector>
#include <deque>

typedef long long lli;

int main(int argc, char ** argv)
{
    lli size;
    std::cin >> size;

    lli bookShelfSize = 3;

    lli book_sz, fav_num, i, k, j;
    
    for ( i = 0 ; i < size ; i++ )
    {
        std::cin >> book_sz >> fav_num;

        std::vector<std::deque<lli>> stack_list;
        for ( k = 0 ; k < bookShelfSize ; k++) {
            std::deque<lli> books_stack;
            for ( j = 0 ; j < book_sz ; j++ )
            {
                lli item;
                std::cin >> item;

                books_stack.push_back(item);
            }
            stack_list.push_back(books_stack);

        }
        
        
        lli target = 0;
        bool isEval = false;
        bool breaking = true;
        bool isTargetPeeked = false;

        for( k = 0; k < book_sz && breaking ; k++ )
        {
            for ( j = 0 ; j < bookShelfSize ; j++ )
            {
                lli item;
                if(stack_list[j].empty()){
                    continue;
                }
                item = stack_list[j].front();

                if ( (fav_num | item) == fav_num ) {
                    stack_list[j].pop_front();
                    target = target | item;
                    isTargetPeeked = true;
                    if(target == fav_num) {
                        isEval = true;
                        breaking = false;
                        break;
                    }
                }

            }

            if(isTargetPeeked == false) {
                break;
            }
            isTargetPeeked = false;
        }

        if (isEval == true)
        {
            std::cout << "YES" << std::endl;
        } else {
            if(fav_num == 0 ) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }


    }


    return 0;
}