#include "Semantics.h"
#include "hw3_output.hpp"
#include <iostream>

vector<symbolTable> globSymTable = {};
vector<int> offsetStack = {};
bool mainExits = false;
string curFuncRetVal = "";
std::string curFuncName = "";
vector<string> curFuncFormals;
symbolRow::symbolRow(string name,
					 int pos,
					 vector<string> types,
					 bool is_const,
					 vector<bool> constFormals,
					 bool isFunc)
	: name(name),
	  pos(pos),
	  types(types),
	  is_const(is_const),
	  constFormals(constFormals),
	  isFunc(isFunc) {

}

symbolRow::symbolRow(const symbolRow &row) : name(row.name),
											 pos(row.pos),
											 types(row.types),
											 is_const(row.is_const),
											 constFormals(row.constFormals),
											 isFunc(row.isFunc) {

}

bool symbolRow::operator==(symbolRow &other) {
	return (this->name == other.name);// && (this->types == other.types);
}

void m_glob() {
	cout << "this is m_glob" << endl;
	symbolTable new_scope;
	vector<string> print_vec = {"VOID", "STRING"};
	symbolRow print_our("print", 0, print_vec, false, {}, true);
	vector<string> printi_vec = {"VOID", "INT"};
	symbolRow printi_our("printi", 0, printi_vec, false, {}, true);
	new_scope.SymbolTable.push_back(print_our);
	new_scope.SymbolTable.push_back(printi_our);
	globSymTable.push_back(new_scope);
	offsetStack.push_back(0);
	return;
}

void m_newScope() {
	cout << "this is m_newScope" << endl;
	//Create and insert new scope table
	symbolTable new_scope;
	globSymTable.push_back(new_scope);
	//Copy the last offset and insert as new offset on top of the stack
	offsetStack.push_back(offsetStack.back());
}

void m_newScopeWhile() {
	cout << "this is m_newScopeWhile" << endl;
	//Create and insert new scope table
	symbolTable new_scope;
	new_scope.isWhileScope = true;
	globSymTable.push_back(new_scope);
	//Copy the last offset and insert as new offset on top of the stack
	offsetStack.push_back(offsetStack.back());
}

void m_endScope() {
	cout << "this is m_endScope" << endl;
	end_scope();
}

void end_scope() {
	output::endScope();
	symbolTable table = globSymTable.back();
	globSymTable.pop_back();
	int offset = offsetStack.back();
	offsetStack.pop_back();
	for (auto it: table.SymbolTable) {
		if (!it.isFunc) {
			//ID
			output::printID(it.name, it.pos, it.types[0]);
		} else {
			//FUNCTION
			string retVal = it.types[0];
			it.types.erase(it.types.begin());
			string funcType = output::makeFunctionType(retVal, it.types);
			output::printID(it.name, 0, funcType);
		}
	}
}

symbolRow findSymbolRow(string id) {
	cout << "=====this is the size of globSymTable: " + to_string(globSymTable.size()) + "=======" << endl;
	symbolRow res = symbolRow("", -1, {""}, false, {false});
	for (auto itGlob = globSymTable.rbegin(); itGlob != globSymTable.rend(); itGlob++) {
		for (auto itScope = itGlob->SymbolTable.rbegin(); itScope != itGlob->SymbolTable.rend(); itScope++) {
			if (itScope->name == id) {
				res = *itScope;
				return res;
			}
		}
	}
	return res;
}

bool isIdentifierExists(string id) {
	bool res = false;
	symbolRow check = findSymbolRow(id);
	if (check.name == id) {
		res = true;
	}
	return res;
}

vector<string> findIdentifierType(string id) {
	vector<string> types = {};
	symbolRow identifier = findSymbolRow(id);
	if (!identifier.name.empty()) {
		types = identifier.types;
	}
	return types;
}

bool isIdentifierConst(string id) {
	bool res = false;
	symbolRow check = findSymbolRow(id);
	if (check.name == id) {
		res = check.is_const;
	}
	return res;
}
string getRetTypeFunc() {
	return curFuncRetVal;
}

bool isInWhile() {
	bool res = false;
	for (auto itGlob = globSymTable.rbegin(); itGlob != globSymTable.rend(); itGlob++) {
		if (itGlob->isWhileScope) {
			res = true;
		}
	}
	return res;
}
//////////////////////////////////////////////////

program::program() : Node("program") {
	cout << "this is program" << endl;
	if (!mainExits) {
		output::errorMainMissing();
		exit(0);
	}
	end_scope();
}

funcs::funcs() : Node("funcs") {
	cout << "this is funcs" << endl;
//todo:: nothing?
}

funcDecl::funcDecl(retType *retType, Node *id, formals *formals, statements *statements) : Node("funcDecl") {
	cout << "this is funcDecl" << endl;
	if (id->val == "main") {
		if (mainExits) {
			output::errorDef(yylineno, id->val);
			exit(0);
		}
		mainExits = true;
	}
	if (isIdentifierExists(id->val)) {
		output::errorDef(id->lineNum, id->val);
		exit(0);
	}
	if (formals->hasString && id->val != "print") {
		output::errorMismatch(id->lineNum);
		exit(0);
	}
	vector<string> funcTypes;
	vector<bool> funcConstTypes;
	funcTypes.push_back(retType->typeName);
	for (auto formal: formals->formalsVector) {
		funcTypes.push_back(formal.formalType);
		funcConstTypes.push_back(formal.isConst);
	}
	cout << "===== we are in funcDecl. and this is the size of globSymTable: " + to_string(globSymTable.size())
		+ "=======" << endl;
	symbolRow symbol_row(id->val, 0, funcTypes, false, funcConstTypes, true);
	globSymTable[0].SymbolTable.push_back(symbol_row);

	end_scope();
}

retType::retType(type *type) : Node("retType") {
	cout << "this is retType" << endl;
	this->typeName = type->typeName;
	curFuncRetVal = this->typeName;
}

retType::retType(Node *typeName) : Node("retType") {
	cout << "this is retType" << endl;
	if (typeName->val != "void") {
		cout << "this is retType error" << endl;
		output::errorSyn(typeName->lineNum);
		exit(0);
	}
	this->typeName = "VOID";
	curFuncRetVal = this->typeName;
}

formals::formals() : Node("formals") {
	cout << "this is formals" << endl;
	this->formalsVector = {};
	for (auto it: this->formalsVector) {
		curFuncFormals.push_back(it.formalType);
	}
}

formals::formals(formalsList *formals) : Node("formals") {
	cout << "this is formals" << endl;
	for (auto formal: formals->formalsVector) {
		for (auto nextFormal: formals->formalsVector) {
			if ((formal.isConst == nextFormal.isConst) && (formal.id == nextFormal.id)
				&& (formal.formalType == nextFormal.formalType)) {
				continue;
			}
			if (formal.id == nextFormal.id) {
				output::errorDef(yylineno, formal.id);
				exit(0);
			}
		}
	}
	int i = -1;
	for (auto it: formals->formalsVector) {
		if (it.formalType == "STRING") {
			this->hasString = true;
		}
		symbolRow formal(it.id, i, {it.formalType}, it.isConst, {}, false);
		globSymTable.back().SymbolTable.push_back(formal);
		i--;
	}
	this->formalsVector = formals->formalsVector;
	for (auto it: this->formalsVector) {
		curFuncFormals.push_back(it.formalType);
	}
}

formalsList::formalsList(formalsDecl *formalsDecl) : Node("formalsList") {
	cout << "this is formalsList" << endl;
	this->formalsVector.push_back(*formalsDecl);
}

formalsList::formalsList(formalsDecl *formalsDecl, formalsList *formalsList) : Node("formalsList") {
	cout << "this is formalList" << endl;
	this->formalsVector.push_back(*formalsDecl);
	this->formalsVector.insert(this->formalsVector.end(),
							   formalsList->formalsVector.begin(),
							   formalsList->formalsVector.end());
}

formalsDecl::formalsDecl(typeAnnotation *typeAnnotation, type *type, Node *id) : Node("formalsDecl") {
	cout << "this is formalsDecl" << endl;
	this->id = id->val;
	this->formalType = type->typeName;
	this->isConst = typeAnnotation->isConst;
}

statements::statements(statement *statement) : Node("statements") {
	cout << "this is statements" << endl;
	this->vecStatements.push_back(*statement);
}

statements::statements(statements *statements, statement *statement) : Node("statements") {
	cout << "this is statements" << endl;
	this->vecStatements = statements->vecStatements;
	this->vecStatements.push_back(*statement);
}

statement::statement(OpenStatement *OpenStatement) : Node("statement") {
	cout << "this is statement" << endl;
	//todo:: nothing?
}

statement::statement(ClosedStatement *ClosedStatement) : Node("statement") {
	cout << "this is statement" << endl;
	//todo:: nothing?
}

OpenStatement::OpenStatement(string keyWord, exp *exp, statement *statement, int lineNumber) : Node("OpenStatement") {
	cout << "this is OpenStatement" << endl;
	if (keyWord != "IF") {
		output::errorSyn(lineNumber);
		exit(0);
	}
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNumber);
		exit(0);
	}
	end_scope();
}

OpenStatement::OpenStatement(string firstKeyWord,
							 exp *exp,
							 ClosedStatement *ClosedStatement,
							 string secondKeyWord,
							 OpenStatement *OpenStatement, int lineNumber) : Node("OpenStatement") {
	cout << "this is OpenStatement" << endl;
	if (firstKeyWord != "IF" || secondKeyWord != "ELSE") {
		output::errorSyn(lineNumber);
		exit(0);
	}
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNumber);
		exit(0);
	}
	end_scope();
}

OpenStatement::OpenStatement(string keyWord, exp *exp, OpenStatement *OpenStatement, int lineNumber) : Node(
	"OpenStatement") {
	cout << "this is OpenStatement" << endl;
	if (keyWord != "WHILE") {
		output::errorSyn(lineNumber);
		exit(0);
	}
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNumber);
		exit(0);
	}
	end_scope();
}

ClosedStatement::ClosedStatement(SimpleStatement *SimpleStatement) : Node("ClosedStatement") {
	cout << "this is ClosedStatement" << endl;
	//todo:: nothing?
}

ClosedStatement::ClosedStatement(string firstKeyWord, exp *exp, ClosedStatement *closed_Statement,
								 string secondKeyWord, ClosedStatement *closed_Statement2, int lineNumber) : Node(
	"ClosedStatement") {
	cout << "this is ClosedStatement" << endl;
	if (firstKeyWord != "IF" || secondKeyWord != "ELSE") {
		output::errorSyn(lineNumber);
		exit(0);
	}
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNumber);
		exit(0);
	}
	end_scope();
}

ClosedStatement::ClosedStatement(string keyWord, exp *exp, ClosedStatement *ClosedStatement, int lineNumber) : Node(
	"ClosedStatement") {
	cout << "this is ClosedStatement" << endl;
	if (keyWord != "WHILE") {
		output::errorSyn(lineNumber);
		exit(0);
	}
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNumber);
		exit(0);
	}
	end_scope();
}

SimpleStatement::SimpleStatement(Node *cmd) : Node("SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	if (cmd->val == "RETURN") {
		string retFunc = getRetTypeFunc();
		if (retFunc == "" || retFunc != "VOID") {
			output::errorMismatch(cmd->lineNum);
			exit(0);
		}
	} else if (cmd->val == "BREAK") {
		if (!isInWhile()) {
			output::errorUnexpectedBreak(cmd->lineNum);
			exit(0);
		}
	} else if (cmd->val == "CONTINUE") {
		if (!isInWhile()) {
			output::errorUnexpectedContinue(cmd->lineNum);
			exit(0);
		}
	}
}
//return VOID, break, continue

SimpleStatement::SimpleStatement(statements *statements) : Node("SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	end_scope();
}    //LBRACE m_newScope statements RBRACE

SimpleStatement::SimpleStatement(typeAnnotation *typeAnnotation, type *type, Node *id) : Node("SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	if (isIdentifierExists(id->val)) {
		output::errorDef(id->lineNum, id->val);
		exit(0);
	}
	if (typeAnnotation->isConst) {
		output::errorConstDef(id->lineNum);
		exit(0);
	}
	int pos = offsetStack.back();
	offsetStack.back() = pos + 1;
	symbolRow newIdentifier(id->val, pos, {type->typeName}, typeAnnotation->isConst, {}, false);
	globSymTable.back().SymbolTable.push_back(newIdentifier);
} //typeAnnotation type ID SC

SimpleStatement::SimpleStatement(typeAnnotation *typeAnnotation, type *type, Node *id, exp *exp) : Node(
	"SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	if (isIdentifierExists(id->val)) {
		output::errorDef(id->lineNum, id->val);
		exit(0);
	}
	if (type->typeName != exp->expType) {
		output::errorMismatch(id->lineNum);
		exit(0);
	}
	int pos = offsetStack.back();
	offsetStack.back() = pos + 1;
	cout << "this is the pos: " + to_string(offsetStack.back() - 1) << endl;
	symbolRow newIdentifier(id->val, pos, {type->typeName}, typeAnnotation->isConst, {}, false);
	globSymTable.back().SymbolTable.push_back(newIdentifier);
	cout << "this is the name in the last row of the symTable: " + globSymTable.back().SymbolTable.back().name << endl;

}    //typeAnnotation type ID ASSIGN exp SC

SimpleStatement::SimpleStatement(Node *id, string assign, exp *exp) : Node("SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	if (assign != "ASSIGN") {
		output::errorSyn(id->lineNum);
		exit(0);
	}
	if (!isIdentifierExists(id->val)) {
		output::errorUndef(id->lineNum, id->val);
		exit(0);
	}
	vector<string> idType = findIdentifierType(id->val);
	if (idType.size() != 1 || idType[0] != exp->expType) {
		output::errorMismatch(id->lineNum);
		exit(0);
	}
	if (isIdentifierConst(id->val)) {
		output::errorConstMismatch(id->lineNum);
		exit(0);
	}
}//ID ASSIGN exp SC

SimpleStatement::SimpleStatement(call *call) : Node("SimpleStatement") {
	cout << "this is SimpleStatement" << endl;
	//todo:: nothing?
}

SimpleStatement::SimpleStatement(Node *node, exp *exp) : Node("SimpleStatement") {
	cout << "this is SimpleStatement (Node *node, exp *exp)" << endl;
	string func = getRetTypeFunc();
	cout << "this is the funcRet val in  RETURN exp SC: " + func << endl;
	if (func == "" || func != exp->expType) {
		output::errorMismatch(node->lineNum);
		exit(0);
	}
}//RETURN exp SC

call::call(Node *id, expList *expList) : Node("call") {
	if (id->val == curFuncName) {
		if (curFuncFormals.size() != expList->expVector.size() + 1) {
			output::errorPrototypeMismatch(yylineno, id->val, curFuncFormals);
			exit(0);
		}
		for (int i = 1; i < curFuncFormals.size(); i++) {
			if (curFuncFormals[i] != expList->expVector[i - 1].expType) {
				if (id->val == "printi") {
					if (expList->expVector[i - 1].expType != "BYTE") {
						output::errorPrototypeMismatch(yylineno, id->val, curFuncFormals);
						exit(0);
					}
				} else {
					output::errorPrototypeMismatch(yylineno, id->val, curFuncFormals);
					exit(0);
				}
			}
		}
		this->rettype = curFuncFormals[0];
	} else {
		symbolRow funcId = findSymbolRow(id->val);
		if (id->val != funcId.name || !funcId.isFunc) {
			output::errorUndefFunc(id->lineNum, id->val);
			exit(0);
		}
		if (funcId.types.size() != expList->expVector.size() + 1) {
			output::errorPrototypeMismatch(yylineno, id->val, funcId.types);
			exit(0);
		}
		for (int i = 1; i < funcId.types.size(); i++) {
			if (funcId.types[i] != expList->expVector[i - 1].expType) {
				if (id->val == "printi") {
					if (expList->expVector[i - 1].expType != "BYTE") {
						output::errorPrototypeMismatch(yylineno, id->val, funcId.types);
						exit(0);
					}
				} else {
					output::errorPrototypeMismatch(yylineno, id->val, funcId.types);
					exit(0);
				}
			}
		}
		this->rettype = funcId.types[0];
	}
}

call::call(Node *id) : Node("call") {
	if (id->val == curFuncName){
		if (curFuncFormals.size() != 1) {
			output::errorPrototypeMismatch(id->lineNum, id->val, curFuncFormals);
			exit(0);
		}
		this->rettype = curFuncFormals[0];
	}else{
		symbolRow funcId = findSymbolRow(id->val);
		if (id->val != funcId.name || !funcId.isFunc) {
			output::errorUndefFunc(id->lineNum, id->val);
			exit(0);
		}
		if (funcId.types.size() != 1) {
			output::errorPrototypeMismatch(id->lineNum, id->val, funcId.types);
			exit(0);
		}
		this->rettype = funcId.types[0];
	}
}

expList::expList(exp *exp1) : Node("expList") {
	cout << "this is expList" << endl;
	this->expVector.push_back(exp1);
}

expList::expList(exp *exp1, expList *expList) : Node("expList") {
	cout << "this is expList" << endl;
	this->expVector.push_back(*exp1);
	this->expVector.insert(this->expVector.end(), expList->expVector.begin(), expList->expVector.end());
}

type::type(Node *typeName) : Node("type") {
	cout << "this is type" << endl;
	cout << "this is the typeName->val: " + typeName->val << endl;
	if (typeName->val == "int") {
		this->typeName = "INT";
	} else if (typeName->val == "byte") {
		this->typeName = "BYTE";
	} else if (typeName->val == "bool") {
		this->typeName = "BOOL";
	} else {
		cout << "this is type error" << endl;
		output::errorSyn(typeName->lineNum);
		exit(0);
	}
}

typeAnnotation::typeAnnotation(Node *annoType) : Node("typeAnnotation") {
	cout << "this is typeAnnotation" << endl;
	if (annoType->val == "") {
		isConst = false;
	} else if (annoType->val == "const") {
		isConst = true;
	} else {
		output::errorSyn(annoType->lineNum);
		exit(0);
	}
}

exp::exp() : Node("exp") {
	cout << "this is exp" << endl;
	this->expType = "";
}

exp::exp(exp *exp) : Node("exp") {
	cout << "this is exp" << endl;
	this->expType = exp->expType;
}

exp::exp(exp *firstExp, string op, exp *secExp, int lineNum) : Node("exp") {
	cout << "this is exp" << endl;
	if (op == "MULT" || op == "DIV" || op == "PLUS" || op == "MINUS") {
		if ((firstExp->expType != "INT" && firstExp->expType != "BYTE")
			|| (secExp->expType != "INT" && secExp->expType != "BYTE")) {
			output::errorMismatch(lineNum);
			exit(0);
		}
		if (firstExp->expType == "INT" || secExp->expType == "INT") {
			this->expType = "INT";
		} else {
			this->expType = "BYTE";
		}
	} else if (op == "AND" || op == "OR") {
		cout << "im now in relOP" << endl;
		cout << "this is firstExp->expType " + firstExp->expType << endl;
		cout << "this is secExp->expType " + secExp->expType << endl;

		if ((firstExp->expType != "BOOL") || (secExp->expType != "BOOL")) {
			output::errorMismatch(lineNum);
			exit(0);
		}
		this->expType = "BOOL";
	} else if (op == "RELOPLEFT" || op == "RELOPNONASSOC") {
		if ((firstExp->expType != "INT" && firstExp->expType != "BYTE")
			|| (secExp->expType != "INT" && secExp->expType != "BYTE")) {
			output::errorMismatch(lineNum);
			exit(0);
		}
		this->expType = "BOOL";
	} else {
		output::errorSyn(lineNum);
		exit(0);
	}
}//MULT,DIV,PLUS,MINUS,AND,OR

exp::exp(Node *id, string type) : Node("exp") {
	cout << "this is exp (Node *id, string type)" << endl;
	if (type == "ID") {
		cout << "this is exp ID (Node *id, string type)" << endl;
		symbolRow res = findSymbolRow(id->val);
		cout << "this is res.name: " + res.name << endl;
		cout << "this is id->val: " + id->val << endl;

		if (res.name != id->val) {
			output::errorUndef(id->lineNum, id->val);
			exit(0);
		}
		if (res.isFunc) {
			cout << "res.isFunc is true" << endl;
			output::errorUndef(id->lineNum, id->val);
			exit(0);
		}
		this->expType = res.types[0];
	} else if (type == "STRING") {
		cout << "this is exp STRING (Node *id, string type)" << endl;
		this->expType = "STRING";
	}
	cout << "this is END exp (Node *id, string type)" << endl;

} //ID,STRING

exp::exp(call *call) : Node("exp") {
	cout << "this is exp" << endl;
	this->expType = call->rettype;
}//call

exp::exp(Node *val, int dontUseIT, bool isB) : Node("exp") {
	cout << "this is exp (Node *val, bool isB)" << endl;
	cout << "this is the val: " + val->val << endl;
	if (isB) {
		if (stoi(val->val) > 255) {
			string value = val->val;
			output::errorByteTooLarge(val->lineNum, val->val);
			exit(0);
		}
		this->expType = "BYTE";
	} else {
		this->expType = "INT";
	}
}//INT,BYTE

exp::exp(bool val) : Node("exp") {
	cout << "this is exp" << endl;
	this->expType = "BOOL";
}

exp::exp(string op, exp *exp, int lineNum) : Node("exp") {
	cout << "this is exp" << endl;
	if (exp->expType != "BOOL") {
		output::errorMismatch(lineNum);
		exit(0);
	}
	this->expType = "BOOL";
}

exp::exp(typeAnnotation *typeAnnotation, type *type, exp *exp, int lineNum) : Node("exp") {
	cout << "this is exp" << endl;
	if ((type->typeName != "INT" && type->typeName != "BYTE") || (exp->expType != "INT" && exp->expType != "BYTE")) {
		output::errorMismatch(lineNum);
		exit(0);
	}
	this->expType = type->typeName;
}