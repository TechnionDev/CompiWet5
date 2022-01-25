#ifndef COMPIWET5__SEMANTICS_H_
#define COMPIWET5__SEMANTICS_H_

#include "hw3_output.hpp"
#include <string.h>
#include "register.h"
#include "bp.hpp"
#include <iostream>
using namespace std;
class Node;
class symbolTable;
class program;
class funcs;
class funcDecl;
class retType;
class formals;
class formalsList;
class formalsDecl;
class statements;
class statement;
class call;
class expList;
class type;
class typeAnnotation;
class exp;
class Marker;
extern int yylineno;
class RegisterManager;
extern RegisterManager registerManager;
extern CodeBuffer &buffer;

class Node {
  public:
	string val = "";
	int lineNum = 0;
	string NodeType = "";
	string NodeId = "";
	int64_t NodeNumericVal = -1;
	string NodeRegister = "";
	string NodeStringVar = "";
	string NodeStringLength = "";
	std::vector<pair<int, BranchLabelIndex>> trueList;
	std::vector<pair<int, BranchLabelIndex>> falseList;
	std::vector<pair<int, BranchLabelIndex>> nextList;
	std::vector<pair<int, BranchLabelIndex>> startLoopList;
	string nextInstruction;
	Node() = default;
	Node(string val, int lineNumber = -1) : val(val), lineNum(lineNumber) {};
	virtual ~Node() = default;

	void loadExp();
	void ifCode();
	void elseCode();
	void backPatchIf(string falseLabel);
	void endWhile(string startLabel, exp *exp);
	void emitCallCode(expList *expList);
	void emitWhileExp(string cmpReg);
};
#define YYSTYPE Node*
class symbolRow {
  public:
	string name;
	int pos;
	std::vector<string> types;
	bool is_const;
	std::vector<bool> constFormals;
	bool isFunc = false;
	symbolRow(string name,
			  int pos,
			  std::vector<string> types,
			  bool is_const,
			  std::vector<bool> constFormals,
			  bool isFunc = false);
	symbolRow() = default;
	symbolRow(const symbolRow &row);
	bool operator==(symbolRow &other);
};

class symbolTable {
  public:
	symbolTable() = default;
	std::vector<symbolRow> SymbolTable;
	bool isWhileScope = false;
	bool contains(string id, std::vector<string> type);
};

bool isIdentifierExists(string id);

void m_glob();

void m_newScope();

void m_newScopeWhile();

void m_endScope();

void end_scope();

void addFunction(retType *retType, Node *funcName, formals *formals);
//////////////////////////////////////////////////

class program : public Node {
  public:
	program();
	program(const program &Prog);
};

class funcs : public Node {
  public:
	funcs();
};

class funcDecl : public Node {
  public:
	funcDecl(retType *retType, Node *id, formals *formals, statements *statements);
};

class retType : public Node {
  public:
	string typeName;
	retType(type *type);
	retType(Node *typeName);
};

class formals : public Node {
  public:
	std::vector<formalsDecl> formalsVector;
	bool hasString = false;
	formals();
	formals(formalsList *formalsList);
};

class formalsList : public Node {
  public:
	std::vector<formalsDecl> formalsVector;
	formalsList(formalsDecl *formalsDecl);
	formalsList(formalsDecl *formalsDecl, formalsList *formalsList);
};

class formalsDecl : public Node {
  public:
	string formalType;
	bool isConst;
	string id;
	formalsDecl(typeAnnotation *typeAnnotation, type *type, Node *id);
};

class statements : public Node {
  public:
	std::vector<statement *> vecStatements;
	statements(statement *statement);
	statements(statements *statements, statement *statement);
};

class statement : public Node {
  public:
	statement(string keyWord, exp *exp, statement *statement, int lineNumber);//IF,WHILE
	statement(string firstKeyWord,
			  exp *exp,
			  statement *firstStatement,
			  string secondKeyWord,
			  statement *secondStatement,
			  int lineNumber); //IF ELSE
	statement(Node *cmd); //return, break, continue
	statement(statements *statements);
	statement(typeAnnotation *typeAnnotation, type *type, Node *id);
	statement(typeAnnotation *typeAnnotation, type *type, Node *id, exp *exp);
	statement(Node *id, string assign, exp *exp);
	statement(call *call);
	statement(Node *node, exp *exp);

};

class call : public Node {
  public:
	string rettype;
	call(Node *id, expList *expList);
	call(Node *id);
};

class expList : public Node {
  public:
	std::vector<exp *> expVector;
	expList(exp *exp1);
	expList(exp *exp1, expList *expList);
};

class type : public Node {
  public:
	string typeName;
	type(Node *typeName);
};

class typeAnnotation : public Node {
  public:
	bool isConst = false;
	typeAnnotation() = default;
	typeAnnotation(Node *annoType);
};

class exp : public Node {
  public:
	string expType;
	bool isLiteral = false;
	exp();
	exp(exp *exp);
	exp(exp *firstExp, string op, exp *secExp, int lineNum);
	exp(exp *firstExp, string op, exp *secExp, int lineNum, Marker *marker);
	exp(Node *id, string type);
	exp(call *call);
	exp(Node *val, int dontUseIT, bool isB);
	exp(bool val);
	exp(string op, exp *exp, int lineNum);
	exp(typeAnnotation *typeAnnotation, type *type, exp *exp, int lineNum);
};

class Marker : public Node {
  public:
	Marker();
};
#endif //COMPIWET5__SEMANTICS_H_
