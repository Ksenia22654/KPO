#include <iostream>
#include "FST.h"

int main()
{
	setlocale(LC_ALL, "ru");

	// ---------------------------------------------------------
	cout << "Тест 1: abc end" << endl;

	FST::FST fst1(
		"ab",
		2,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE()
	);

	if (FST::execute(fst1))
		cout << "Цепочка " << fst1.string << " распознана" << endl;
	else cout << "Цепочка " << fst1.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 2: proc( )(start(cos()+sin(x)))  end" << endl;

	FST::FST fst2(
		"pr",
		3,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		//FST::NODE(1, FST::RELATION('o', 3)),
		//FST::NODE(1, FST::RELATION('c', 4)),
		//FST::NODE(1, FST::RELATION('(', 5)),
		//FST::NODE(1, FST::RELATION(' ', 6)),
		//FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		//FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		//FST::NODE(1, FST::RELATION('s', 9)),
		//FST::NODE(1, FST::RELATION('t', 10)),
		//FST::NODE(1, FST::RELATION('a', 11)),
		//FST::NODE(1, FST::RELATION('r', 12)),
		//FST::NODE(1, FST::RELATION('t', 13)),
		//FST::NODE(1, FST::RELATION('(', 14)),
		//FST::NODE(1, FST::RELATION('c', 15)),
		//FST::NODE(1, FST::RELATION('o', 16)),
		//FST::NODE(1, FST::RELATION('s', 17)), // 16
		//FST::NODE(1, FST::RELATION('(', 18)), // 17
		//FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		//FST::NODE(1, FST::RELATION('+', 20)), // 19
		//FST::NODE(1, FST::RELATION('s', 21)), // 20
		//FST::NODE(1, FST::RELATION('i', 22)), // 21
		//FST::NODE(1, FST::RELATION('n', 23)), // 22
		//FST::NODE(1, FST::RELATION('(', 24)), // 23
		//FST::NODE(1, FST::RELATION('x', 25)), // 24
		//FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		//FST::NODE(1, FST::RELATION(')', 27)), // 26
		//FST::NODE(1, FST::RELATION(')', 7)), // 27
		//FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		//FST::NODE(1, FST::RELATION('n', 30)), // 29
		//FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst2))
		cout << "Цепочка " << fst2.string << " распознана" << endl;
	else cout << "Цепочка " << fst2.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 3: proc( )(start(cos(yy)+sin(xxx)))   end" << endl;

	FST::FST fst3(
		"proc( )(start(cos(yy)+sin(xxx)))   end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst3))
		cout << "Цепочка " << fst3.string << " распознана" << endl;
	else cout << "Цепочка " << fst3.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 4: proc( )(start(cos(yyy)+sin(xxxx))) end" << endl;

	FST::FST fst4(
		"proc( )(start(cos(yyy)+sin(xxxx))) end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst4))
		cout << "Цепочка " << fst4.string << " распознана" << endl;
	else cout << "Цепочка " << fst4.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 5: proc( )(start(cos(yyyy)+sin(xxxxx))) end" << endl;

	FST::FST fst5(
		"proc( )(start(cos(yyyy)+sin(xxxxx))) end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst5))
		cout << "Цепочка " << fst5.string << " распознана" << endl;
	else cout << "Цепочка " << fst5.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 6: proc( )(start(cos(yyyyy)+sin(xxxxxx)))          end" << endl;

	FST::FST fst6(
		"proc( )(start(cos(yyyyy)+sin(xxxxxx)))          end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst6))
		cout << "Цепочка " << fst6.string << " распознана" << endl;
	else cout << "Цепочка " << fst6.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 7: proc( ) end" << endl;

	FST::FST fst7(
		"proc( ) end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst7))
		cout << "Цепочка " << fst7.string << " распознана" << endl;
	else cout << "Цепочка " << fst7.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 8: proc( )(start(cos(y))) end" << endl;

	FST::FST fst8(
		"proc( )(start(cos(y)+sin(x))) end ",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst8))
		cout << "Цепочка " << fst8.string << " распознана" << endl;
	else cout << "Цепочка " << fst8.string << " не распознана" << endl;

	// ---------------------------------------------------------
	cout << "\nТест 9: proc( )(start(cos(zy)+sin(xy))) end" << endl;

	FST::FST fst9(
		"proc( )(start(cos(zy)+sin(xy))) end",
		32,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION(' ', 6)),
		FST::NODE(2, FST::RELATION(' ', 6), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION('(', 8), FST::RELATION(' ', 28)),
		FST::NODE(1, FST::RELATION('s', 9)),
		FST::NODE(1, FST::RELATION('t', 10)),
		FST::NODE(1, FST::RELATION('a', 11)),
		FST::NODE(1, FST::RELATION('r', 12)),
		FST::NODE(1, FST::RELATION('t', 13)),
		FST::NODE(1, FST::RELATION('(', 14)),
		FST::NODE(1, FST::RELATION('c', 15)),
		FST::NODE(1, FST::RELATION('o', 16)),
		FST::NODE(1, FST::RELATION('s', 17)), // 16
		FST::NODE(1, FST::RELATION('(', 18)), // 17
		FST::NODE(2, FST::RELATION('y', 18), FST::RELATION(')', 19)), // 18
		FST::NODE(1, FST::RELATION('+', 20)), // 19
		FST::NODE(1, FST::RELATION('s', 21)), // 20
		FST::NODE(1, FST::RELATION('i', 22)), // 21
		FST::NODE(1, FST::RELATION('n', 23)), // 22
		FST::NODE(1, FST::RELATION('(', 24)), // 23
		FST::NODE(1, FST::RELATION('x', 25)), // 24
		FST::NODE(2, FST::RELATION('x', 25), FST::RELATION(')', 26)), // 25
		FST::NODE(1, FST::RELATION(')', 27)), // 26
		FST::NODE(1, FST::RELATION(')', 7)), // 27
		FST::NODE(2, FST::RELATION(' ', 28), FST::RELATION('e', 29)), // 28
		FST::NODE(1, FST::RELATION('n', 30)), // 29
		FST::NODE(1, FST::RELATION('d', 31)), // 30


		FST::NODE()
	);

	if (FST::execute(fst8))
		cout << "Цепочка " << fst9.string << " распознана" << endl;
	else cout << "Цепочка " << fst9.string << " не распознана" << endl;
}