#include"stdafx.h"
#include"out.h"

namespace Out
{
	OUT getout(wchar_t outfile[])
	{
		OUT out{};
		out.stream = new ofstream;
		out.stream->open(outfile);
		if (!out.stream->is_open()) throw ERROR_THROW(112);
		wcscpy_s(out.outfile, outfile);
		return out;
	}

	void writeOut(wchar_t outfile[], In::IN in)
	{
		ofstream out;
		out.open(outfile);

		if (!out.is_open())
		{
			throw ERROR_THROW(110);
		}

		out << in.text << endl;
		out << "Всего символов: " << in.size << endl;
		out << "Всего строк: " << in.lines << endl;
		out << "Пропущено: " << in.ignore << endl;
	}

	void writeOutError(OUT out, Error::ERROR error) {

		if (out.stream == NULL)
		{
			cout << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << endl << endl;
		}
		else
		{
			// Выводим информацию о входных данных в протокол
			*(out.stream) << "Входные данные:\n";
			*(out.stream) << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << endl << endl;
		}
	}
}