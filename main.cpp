#include <iostream>
#include <cmath>
#include <string>

int main()
{
    int lenA, lenB;
    std::string A = "Personal Computer";
    std::string B = "ro";
    lenA = A.length();
    lenB = B.length();
    for (int c = 0; c < lenB; c++){
        for (int i = 0; i < lenA; i++){
            if( B[c] == A[i] ){
               A.erase(i, 1);

            }
        }
    }
    std::cout << A << std::endl;
    return 0;
}

