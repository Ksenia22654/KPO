#pragma once

#include "stdafx.h"
#include "in.h" 
#include "log.h"

namespace Out
{
    struct OUT      // протокол
    {
        wchar_t outfile[PARM_MAX_SIZE]; // имя файла протокола
        std::ofstream* stream;      // выходной поток протокола
    };
    void writeOut(wchar_t outfile[], In::IN in);
    void writeOutError(OUT out, Error::ERROR error);
    OUT getout(wchar_t outfile[]);
}
