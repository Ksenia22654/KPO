#include "stdafx.h"
#include "log.h"
#include "error.h"

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log{};
		log.stream = new ofstream;
		log.stream->open(logfile);
		if (!log.stream->is_open()) throw ERROR_THROW(112);
		wcscpy_s(log.logfile, logfile);
		return log;
	}

	void WriteLine(LOG log, wchar_t* c, ...)
	{
		va_list stringParms;
		va_start(stringParms, c);
		char* data = new char[wcslen(c) + 1];
		wcstombs(data, c, wcslen(c) + 1);
		string buff = data;
		wchar_t* temp;
		delete[] data;
		do
		{
			temp = va_arg(stringParms, wchar_t*);
			char* data = new char[wcslen(temp) + 1];
			wcstombs(data, temp, wcslen(temp) + 1);
			buff += data;
			delete[] data;
		} while (temp != L"");
		va_end(stringParms);
		*(log.stream) << buff;
	}

	void WriteLine(LOG log, char* c, ...)
	{
		va_list stringParms;
		va_start(stringParms, c);
		string buff = c;
		char* temp;
		do
		{
			temp = va_arg(stringParms, char*);
			buff += temp;
		} while (temp != "");
		va_end(stringParms);
		*(log.stream) << buff;
	}

	void WriteLog(LOG log) {
		*(log.stream) << "----Протокол------";
		time_t mytime = time(NULL);
		struct tm* now = localtime(&mytime);
		char date[20];
		char time[20];
		strftime(date, sizeof(date), "%d.%m.%y", now);
		strftime(time, sizeof(time), "%T", now);
		*(log.stream) << date << " " << time << "----";
	}

	void WriteParm(LOG log, Parm::PARM parm)
	{
		*(log.stream) << "\n-----Параметры:-----\n";

		char* data = new char[wcslen(parm.log) + 1];
		wcstombs(data, parm.log, wcslen(parm.log) + 1);
		*(log.stream) << "-log " << data << "\n";
		delete[] data;

		data = new char[wcslen(parm.out) + 1];
		wcstombs(data, parm.out, wcslen(parm.out) + 1);
		*(log.stream) << "-out : " << data << "\n";
		delete[] data;

		data = new char[wcslen(parm.in) + 1];
		wcstombs(data, parm.in, wcslen(parm.in) + 1);
		*(log.stream) << "-in: " << data << "\n";
		delete[] data;
	}

	void WriteIn(LOG log, In::IN in)
	{
		*(log.stream) << "-----Входные данные:-----\n";
		*(log.stream) << "Всего символов: " << in.size << "\n";
		*(log.stream) << "Всего строк: " << in.lines << "\n";
		*(log.stream) << "Пропущено: " << in.ignore << "\n";
	}

	void WriteError(LOG log, Error::ERROR error) {

		if (log.stream == NULL)
		{
			cout << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << endl << endl;
		}
		else
		{
			// Выводим информацию о входных данных в протокол
			*(log.stream) << "Входные данные:\n";
			*(log.stream) << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << endl << endl;
		}
	}

	void Close(LOG log)
	{
		if (log.stream != NULL)
		{
			log.stream->close();
			delete log.stream;
		}
	}
}