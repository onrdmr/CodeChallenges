#include <bits/stdc++.h>
#include <sstream>

#include <limits>

using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


#include <vector>
#include <string>
/*
 * Complete the 'Evaluator' class below with the following method.
 *
 * The method check(string expression) is expected to return a BOOLEAN.
 */
 
 typedef long long int lli;
 
class Evaluator{
  public:
    bool check(string expression){
        //std::vector<char> string;
        std::vector<std::string> str;
        
        
        
        std::string string;
        for(int i = 0 ; i < expression.size() ; i++)
        {
            string+=expression[i];
            if(expression[i] == ' ') {
                string.pop_back();
                str.push_back(std::move(string));
            }
        }
        str.push_back(std::move(string));
        
        lli result = 0;
        if(str.size() == 1)
        {
            std::istringstream iss(str[0]);
            iss >> result;
            // result = std::stoll(str);
            int check = result;
            if(check == result)
            {
                return true;
            } else {
                return false;
            }
        }
        if( str[1][0] == '+'){
            lli op1, op2;
            std::istringstream iss(str[0]);
            std::istringstream iss2(str[2]);
            iss >> op1;
            iss2 >> op2;
            result = op1 + op2;
        }
        if( str[1][0] == '-'){
            lli op1, op2;
            std::istringstream iss(str[0]);
            std::istringstream iss2(str[2]);
            iss >> op1;
            iss2 >> op2;
            result = op1 - op2;
        }
        
        lli operand;
        for(int i = 2 ; i < str.size() ; i++)
        {
            if(str[i][0] == '+') {
                result += operand;
            }
            else if( str[i][0] == '-') {
                result -= operand;
            }
            else {
                std::istringstream iss(str[i]);
                iss >> operand;
            }
        }        
        
        int check = static_cast<int>(result);
        if(check == result)
        {
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    Evaluator evl;
    std::cout << evl.check("398198412981 - 398198412981") << std::endl;
    return 0;
}
