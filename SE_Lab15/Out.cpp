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
		out << "����� ��������: " << in.size << endl;
		out << "����� �����: " << in.lines << endl;
		out << "���������: " << in.ignore << endl;
	}

	void writeOutError(OUT out, Error::ERROR error) {

		if (out.stream == NULL)
		{
			cout << "������ " << error.id << ": " << error.message
				<< ", ������ " << error.inext.line
				<< ", ������� " << error.inext.col << endl << endl;
		}
		else
		{
			// ������� ���������� � ������� ������ � ��������
			*(out.stream) << "������� ������:\n";
			*(out.stream) << "������ " << error.id << ": " << error.message
				<< ", ������ " << error.inext.line
				<< ", ������� " << error.inext.col << endl << endl;
		}
	}
}