#include "FST.h"
#include "iostream"

// задает значени€ дл€ символа (c) и номера конечной вершины (nn),
// куда должен быть выполнен переход по этому символу.
FST::RELATION::RELATION(char c, short nn)
{
    symbol = c;
    nnode = nn;
};

//  онструктор по умолчанию
FST::NODE::NODE() // по умолчанию
{
    n_relation = 0;
    RELATION* relations = nullptr;
};

// создаЄт вершину с переходами
FST::NODE::NODE(short n, RELATION rel, ...) // с параметрами
{
    n_relation = n;
    RELATION* p = &rel;
    relations = new RELATION[n];

    for (short i = 0; i < n; i++) relations[i] = p[i];
};


// s Ч строку дл€ проверки
// ns Ч количество состо€ний автомата
// n, ... Ч список вершин(объектов NODE), задающих структуру автомата
FST::FST::FST(const char* s, short ns, NODE n, ...)
{
    string = s;
    nstates = ns;
    nodes = new NODE[ns];

    NODE* p = &n;
    for (int k = 0; k < ns; k++) nodes[k] = p[k];

    rstates = new short[nstates];
    memset(rstates, 0xff, sizeof(short) * nstates); //  массив состо€ний заполн€етс€ значени€ми 0xff, что эквивалентно значению -1
    rstates[0] = 0; // начинает с вершины 0
    position = -1;
};

bool step(FST::FST& fst, short*& rstates)
{
    bool rc = false;

    // ћен€ем местами rstates и fst.rstates
    std::swap(rstates, fst.rstates);

    // ѕроходим по всем состо€ни€м автомата
    for (short i = 0; i < fst.nstates; i++)
    {
        // ≈сли текущее состо€ние активно (совпадает с позицией в строке)
        if (rstates[i] == fst.position)
        {
            // ѕроходим по всем возможным переходам из этого состо€ни€
            for (short j = 0; j < fst.nodes[i].n_relation; j++)
            {
                // ≈сли символ перехода совпадает с текущим символом строки
                if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
                {
                    // ќбновл€ем новое состо€ние в массиве rstates
                    fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
                    rc = true;
                }
            }
        }
    }

    return rc;
}

bool FST::execute(FST& fst)
{
    short* rstates = new short[fst.nstates];
    memset(rstates, 0xff, sizeof(short) * fst.nstates);
    short lstring = strlen(fst.string);
    bool rc = true;

    for (short i = 0; i < lstring && rc; i++)
    {
        fst.position++;
        rc = step(fst, rstates);
    };

    delete[] rstates;

    return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
}