#pragma once


enum tokenType {
	IDENTIFIER, // �������������
	ENDOF, // ����� ������
	ERROR, // ������
	FUNC, // fn
	CHAR, // ���������� u32, �� ��� �������� � ��������� unicode
	INTEGER, // i32
	UINTEGER, // u32
	FLOAT, // f32
	DOUBLE, // f64
	VOID, // void
	KEYWORD, // ������� �����
	STRLITERAL, // ��������� �������
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