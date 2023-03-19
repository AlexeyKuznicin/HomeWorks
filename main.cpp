#include <iostream>
#include <fstream>
#include <array>
#include <string>

//                        1 задание(2b)
//Реализовать чтение ID3v1 MP3-файла. Будьте внимательны, не все MP3-файлы
//содержат заполненный ID3-тег; b. Исполнитель

//int main()
//{
//    std::fstream file;
//    file.open("1.mp3", std::ios::binary | std::ios::in);

//    if(!file.is_open()){
//        std::cout << "file don't work" << "\n";
//        return - 1;
//    }

//    char ID3_tag[1024];
//    int offset = 48;
//    int size=offset + 10;
//    int i=offset;

//    file.read(ID3_tag, 1024);

//    file.close();
//    for (i; i< size; i++){
//        std::cout << ID3_tag[i];
//    }

//    std::cout << "\n";
//    return 0;
//}

//                        2 задание(3d)
//Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
//считывать из файла in.txt. Результат записывать в текстовый файл out.txt.

//int main()
//{
//    std::fstream file1, file2;
//    file1.open("in.txt", std::ios::out | std::ios::in);

//    file2.open("out.txt", std::ios::out | std::ios::in);

//    if((!file1.is_open()) || (!file1.is_open())){
//        std::cout << "Error" << "\n";
//        return - 1;
//    }


//    float a = 3, d = 7 , y, x, b, c, h, rec;
//   file1 >> x >> b >> c >> h;
//   std::cout << x << ", " << b << ", " << c << ", " << h << "\n";

//    for( x; x < b; x += c){
//        y = (a / (d * x));
//        a += 1;
//        d += 2;
//        rec += y;
//        file2 << x << ", " << rec << "\n";
//    }
//    file1.close();
//    file2.close();

//    std::cout << "\n";
//    return 0;
//}

//                        3 задание(5)
//Пользователь вводит данные о студентах: Фамилия, Средняя оценка, Курс.
//Организовать запись данных из массива структур в файл в следующем формате: 1
//строка Фамилия, 2 строка Средняя оценка, 3 строка Курс. Остальные строки
//повторяют тройками эти данные для других студентов. Организовать переменные
//для хранения информации.

//int main()
//{
//    std::fstream file;

//    file.open("Profiles.txt", std::ios::out | std::ios::in);

//    if((!file.is_open()) || (!file.is_open())){
//        std::cout << "Error" << "\n";
//        return - 1;
//    }

//    struct info{
//      std::string surname[2];
//      float middle[2];
//      int kurse[2];
//    };

//    struct info students[2];
//    for(int v = 0; v < 2; v++){
//     for(int i = 0; i < 2; i++){
//      std::cin >> students[i].surname[v];
//      std::cin >> students[i].middle[v];
//      std::cin >> students[i].kurse[v];
//    }
//  }
//    std::cout << "Ready!";

//    for(int v = 0; v < 2; v++){
//     for(int i = 0; i < 2; i++){
//      file << students[i].surname[v] << "\n" << students[i].middle[v] << "\n" << students[i].kurse[v] << "\n";
//    }
//  }

//    file.close();

//    std::cout << "\n";
//    return 0;
//}
