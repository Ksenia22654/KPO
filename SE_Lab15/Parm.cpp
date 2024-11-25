#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
	bool format(wchar_t* p, const wchar_t* type, int number, _TCHAR* argv[], int argc)
	{
		wchar_t* buff;

		if (number >= argc) return false;

		if (buff = wcsstr(argv[number], type))
		{
			if (wcslen(buff) < PARM_MAX_SIZE)
			{
				wcscpy(p, buff + wcslen(type));
				return true;
			}
			else
			{
				throw ERROR_THROW(104);
			}
		}
		else
		{
			return false;
		}
	}

	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM p;
		wchar_t* buff;
		if (argc > 1)
		{
			if (!format(p.in, L"-in:", 1, argv, argc)) throw ERROR_THROW(100);

			if (!format(p.out, PARM_OUT, 2, argv, argc))
			{
				wchar_t* buff1 = new wchar_t[wcslen(p.in)];
				wcscpy(buff1, p.in);
				wcscpy_s(p.out, wcsncat(buff1, PARM_OUT_DEFAULT_EXT, 4));

			}

			if (!format(p.log, PARM_LOG, 3, argv, argc))
			{
				wchar_t* buff1 = new wchar_t[wcslen(p.in)];

				wcscpy(buff1, p.in);
				wcscpy_s(p.log, wcsncat(buff1, PARM_LOG_DEFAULT_EXT, 4));

			}
		}
		else
		{
			throw ERROR_THROW(100);
		}
		return p;
	}
}