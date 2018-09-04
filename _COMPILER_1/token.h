#pragma once


enum tokenType {
	IDENTIFIER, // Идентификатор
	ENDOF, // Конец строки
	ERROR, // Ошибка
	FUNC, // fn
	CHAR, // аналогичен u32, но для символов в кодировке unicode
	INTEGER, // i32
	UINTEGER, // u32
	FLOAT, // f32
	DOUBLE, // f64
	VOID, // void
	KEYWORD, // Вводное слово
	STRLITERAL, // Строковый литерал
	OPPLUS, // +
	OPPLUSEQ, // +=
	OPMIN, // -
	OPMINEQ, // -=
	OPMULTI, // *
	OPMULTIEQ, // *=
	OPDIV, // /
	OPDIVEQ, // /=
	OPPLUSPLUS, // ++
	OPMINMIN, // --
	OPMORE, // >
	OPMOREEQ, // >=
	OPLESS, // <
	OPLESSEQ, // <=
	OPNOT, // !
	OPNOTEQ, // !=
	OPEQ, // =
	OPCOMPRARE, // ==
	AMP, // &
	DOT, // .
	COMMA, // ,
	DCOMMA, // ;
	LBR, // {
	RBR, // }
	LCBR, // (
	RCBR, // )

};