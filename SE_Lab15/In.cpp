#include"stdafx.h"
#include"in.h"
#include"error.h"

namespace In
{
    IN getin(wchar_t infile[])
    {
        ifstream in;
        in.open(infile);
        if (!in.is_open())
        {
            throw ERROR_THROW(110); // Ошибка при открытии файла
        }

        IN indata;
        indata.lines = 0;  // Убедимся, что счётчик строк инициализирован с нуля
        string data, result;

        while (getline(in, data))
        {
            indata.lines++;  // Увеличиваем счётчик строк (считаем с 1)
            int position_in_line = 0;  // Счётчик позиции внутри строки

            for (unsigned char symbol : data)
            {
                position_in_line++;  // Увеличиваем позицию в строке
                indata.size++;  // Увеличиваем общий счётчик символов

                if (indata.code[(int)symbol] == indata.T)
                {
                    result += symbol;
                }
                if (indata.code[(int)symbol] == indata.I)
                {
                    indata.ignore++;
                }
                if (indata.code[(int)symbol] == indata.F)
                {
                    // Правильно передаем номер строки и позицию в строке
                    throw ERROR_THROW_IN(111, indata.lines, position_in_line);
                }
                if (indata.code[(int)symbol] >= 0 && indata.code[(int)symbol] <= 255)
                {
                    result += (char)indata.code[(int)symbol];
                }
            }
            result += INT_CODE_ENDL;  // Добавляем конец строки
        }

        char* tmp = _strdup(result.c_str());
        indata.text = (unsigned char*)tmp;
        return indata;
    }


}