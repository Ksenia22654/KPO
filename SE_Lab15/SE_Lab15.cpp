#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include <tchar.h>

#include "Error.h"   // обработка ошибок
#include "Parm.h"    // обработка параметров
#include "Log.h"     // работа с протоколом
#include "In.h"      // ввод исходного файла
#include"Out.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    std::cout << "---- тест Error::geterror ---" << std::endl << std::endl;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        wcout << L"-in:" << parm.in << L", -out:" << parm.out << L", -log:" << parm.log << endl << endl;
    }
    //try { throw ERROR_THROW(100);}

    //catch (Error::ERROR e)
    //{
    //    std::cout << "Oun6xa " << e.id << ": " << e.message << std::endl << std::endl;
    //};
    catch (Error::ERROR e)
    {
        cout << "Ошибка" << e.id << ":" << e.message << endl;
    };

    std::cout << "---- тест Error::geterrorin ---" << std::endl << std::endl;
    //try { throw ERROR_THROW_IN(111,7,7);}

    //catch (Error::ERROR e)
    //{
    //    std::cout << "Oшибка " << e.id << ": " << e.message << std::endl << std::endl;
    //};
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        In::IN in = In::getin(parm.in);
        cout << in.text << endl;
        cout << "Всего символов: " << in.size << endl;
        cout << "Всего строк: " << in.lines << endl;
        cout << "Пропущено: " << in.ignore << endl;
        Out::writeOut(parm.out, in);
    }
    catch (Error::ERROR e)
    {
        cout << "Ошибка " << e.id << ":" << e.message <<
            " строка " << e.inext.line << " позиция " << e.inext.col << endl << endl;
    };

    Log::LOG log = Log::INITLOG;
    Out::OUT out{};
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        log = Log::getlog(parm.log);
        out = Out::getout(parm.out);
        Log::WriteLine(log, (char*)"Тест:", (char*)"без ошибок \n", "");
        Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L"без ошибок \n", L"");
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm.in);
        Log::WriteIn(log, in);
        Log::Close(log);
        Out::writeOut(parm.out, in);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
        Out::writeOutError(out, e);
    };


    system("pause");
    return 0;
}