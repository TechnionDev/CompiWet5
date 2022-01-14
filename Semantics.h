#ifndef COMPIWET3__SEMANTICS_H_
#define COMPIWET3__SEMANTICS_H_

#include "hw3_output.hpp"
#include <string.h>
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
class OpenStatement;
class ClosedStatement;
class SimpleStatement;
class call;
class expList;
class type;
class typeAnnotation;
class exp;

extern int yylineno;


class Node {
  public:
	string val = "";
	int lineNum = 0;
	Node() = default;
	Node(string val, int lineNumber = -1) : val(val), lineNum(lineNumber) {};
	virtual ~Node() = default;

};
#define YYSTYPE Node*
class symbolRow {
  public:
	string name;
	int pos;
	vector<string> types;
	bool is_const;
	vector<bool> constFormals;
	bool isFunc = false;
	symbolRow(string name,
			  int pos,
			  vector<string> types,
			  bool is_const,
			  vector<bool> constFormals,
			  bool isFunc = false);
	symbolRow() = default;
	symbolRow(const symbolRow &row);
	bool operator==(symbolRow &other);
};

class symbolTable {
  public:
	symbolTable() = default;
	vector<symbolRow> SymbolTable;
	bool isWhileScope = false;
	bool contains(string id, vector<string> type);
};

void m_glob();

void m_newScope();

void m_newScopeWhile();

void m_endScope();

void end_scope();

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
	vector<formalsDecl> formalsVector;
	bool hasString = false;
	formals();
	formals(formalsList *formalsList);
};

class formalsList : public Node {
  public:
	vector<formalsDecl> formalsVector;
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
	vector<statement> vecStatements;
	statements(statement *statement);
	statements(statements *statements, statement *statement);
};

class statement : public Node {
  public:
	statement(OpenStatement *OpenStatement);
	statement(ClosedStatement *ClosedStatement);
};

class OpenStatement : public Node {
  public:
	OpenStatement(string keyWord, exp *exp, statement *statement, int lineNumber);
	OpenStatement(string firstKeyWord,
				  exp *exp,
				  ClosedStatement *ClosedStatement,
				  string econdKeyWord,
				  OpenStatement *OpenStatement,
				  int lineNumber);
	OpenStatement(string keyWord, exp *exp, OpenStatement *OpenStatement, int lineNumber);
};

class ClosedStatement : public Node {
  public:
	ClosedStatement(SimpleStatement *SimpleStatement);
	ClosedStatement(string firstKeyWord,
					exp *exp,
					ClosedStatement *closed_Statement,
					string secondKeyWord,
					ClosedStatement *closed_Statement2, int lineNumber);
	ClosedStatement(string keyWord, exp *exp, ClosedStatement *ClosedStatement, int lineNumber);
};

class SimpleStatement : public Node {
  public:
	SimpleStatement(Node *cmd); //return, break, continue
	SimpleStatement(statements *statements);
	SimpleStatement(typeAnnotation *typeAnnotation, type *type, Node *id);
	SimpleStatement(typeAnnotation *typeAnnotation, type *type, Node *id, exp *exp);
	SimpleStatement(Node *id, string assign, exp *exp);
	SimpleStatement(call *call);
	SimpleStatement(Node *node, exp *exp);

};

class call : public Node {
  public:
	string rettype;
	call(Node *id, expList *expList);
	call(Node *id);
};

class expList : public Node {
  public:
	vector<exp> expVector;
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
	bool isConst= false;
	typeAnnotation() = default;
	typeAnnotation(Node *annoType);
};

class exp : public Node {
  public:
	string expType;
	exp();
	exp(exp *exp);
	exp(exp *firstExp, string op, exp *secExp, int lineNum);
	exp(Node *id, string type);
	exp(call *call);
	exp(Node *val,int dontUseIT, bool isB);
	exp(bool val);
	exp(string op, exp *exp, int lineNum);
	exp(typeAnnotation *typeAnnotation, type *type, exp *exp, int lineNum);
};

#endif //COMPIWET3__SEMANTICS_H_
