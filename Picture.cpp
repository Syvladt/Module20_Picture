#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Программа создаёт файл внутри прямоугольник из 0 и 1. Малевич бы обзавидовался.

int main()
{
	int height, width, count = 0;
	std::ofstream out("pic.txt");
	if (out.is_open())
	{
		std::cout << "Enter the height of the picture: ";
		std::cin >> height;
		if (height >= 0 && height <= 40)
		{
			std::cout << "Enter the width of the picture: ";
			std::cin >> width;
			if (width >= 0 && width <= 100)
			{
				for (int row = 0; row < height; row++)
				{
					for (int column = 0; column < width; column++)
					{
						srand(time(nullptr));
						Sleep(1000);                  // Пауза в секунду делает rand более случайным.
						out << rand() % 2;
						std::cout << "\x1B[2J\x1B[H"; // Очистка консоли, что бы инфа не забила весь экран.
						// Так как у нас стоит пауза в циклах, то выводится информация о примерном окончании
						// процесса создания НЕПОВТОРИМОГО шедевра.
						std::cout << "Please wait " << height * width - count << " seconds.\n";
						count++;
					}
					out << std::endl;
				}
			}
			else
				std::cerr << "Incorrect input for width.\n";
		}
		else
			std::cerr << "Incorrect input for height.\n";
		out.close();
	}
	else
		std::cerr << "File is not opened.\n";
	std::cout << "Program is finished.\n";
}