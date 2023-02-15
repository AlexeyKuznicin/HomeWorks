#include <iostream>
#include <cmath>
#include <string>


//// Кузницын Алексей СВятославович. УТС/б - 22 - 2 - о


//// Задание 8
//// Составить алгоритм, исключающий из текста “лишние” пробелы. (В тексте должен быть один пробел для разделения слов).
//int main()
//{
//    int lenA, lenB, Space;
//    std::string A = "g o od mo m en t";
//    std::string B = " ";
//    std::cout << "Specify which character will be followed by a space: ";
//    std::cin >> Space;
//    lenA = A.length();
//    lenB = B.length();
//    for (int c = 0; c < lenB; c++){
//        for (int i = 0; i < lenA; i++){

//            if( i == Space ){
//                  i++;
//            }

//            if( B[c] == A[i] ){
//               A.erase(i, 1);

//            }

//        }
//    }
//    std::cout << std::endl << A << std::endl;
//    return 0;
//}


//// Задание 6
//// Составить алгоритм, подсчитывающий количество слов в тексте.
//int main()
//{
//    int lenA, lenB, S;
//    std::string A = "Beautiful weather. I even want to go for a walk somewhere";
//    std::string B = " ";
//    lenA = A.length();
//    lenB = B.length();
//    for (int c = 0; c < lenB; c++){
//        for (int i = 0; i < lenA; i++){

//            if( B[c] == A[i] ){
//               S++;

//            }

//        }
//      S++;
//    }
//    std::cout << "Number of word:  " << S << std::endl;
//    return 0;
//}


//// Задание 18
//// Дана строка. Удалите k-ый символ в ней.
//int main (){
//    std::string Text, sim, Itog;
//    int t;
//    std::cout << "please, enter number: ";
//    sim = " ";
//    std::cin >> t;
//    Text = "It was raining";
//     Text.erase(t - 1, 1);

//      std::cout << Text;
//}


//// Задание 22
//// Исключить из строки группы символов, расположенные между символами «/*» и «*/» включая границы. Предполагается, что нет вложенных скобок.
int main (){
    std::string Text;
    int t, pos1, pos2;
    Text = "It was raining, but the day /* It was Wednesday *\ was still very beautiful";
    pos1 = Text.find( "/*" );
    pos2 = Text.find( "*\\" );
        t = pos2 - pos1;
     Text.erase(pos1, t);
      std::cout << Text;
}
