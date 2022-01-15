#ifndef COMPIWET5__REGISTER_H_
#define COMPIWET5__REGISTER_H_
#include <string>
#include <map>
#include "Semantics.h"
#include "bp.hpp"
#include <sstream>
using namespace std;
extern CodeBuffer& buffer;
class Node;
class exp;
class RegisterManager {
  public:
	int counter = 0;
	int stringCounter = 0;
	map<string, string> varName2Register;
	map<string, string> varName2StackReg;
	RegisterManager() = default;
	string getCurrentRegisterName();
	string getNextRegisterName();
	string getVarRegister(string var, string valueNotID);
	void createRegister(Node *node, string value, string id); //for declaring or reassigning a variable
	string createArithmeticOp(exp *leftExp, exp *rightExp, string op); // MUL,DIV,PLUS,MINUS
	string loadVarName(string varName);
	string storeVar(string var, string varValue);
	string createStringConstant();
	string commperCodeGen(exp* firstExp, string op, exp* secExp);
};

#endif //COMPIWET5__REGISTER_H_
