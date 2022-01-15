#include "register.h"
#include "bp.hpp"

RegisterManager registerManager;

string RegisterManager::getCurrentRegisterName() {
	return "%t_" + to_string(this->counter);
}

string RegisterManager::getNextRegisterName() {
	this->counter++;
	return "%t_" + to_string(this->counter);
}

string RegisterManager::getVarRegister(string var,string valueNotID) {
	if (isIdentifierExists(var)) {
		return this->varName2Register[var];
	}
	return valueNotID;
}

void RegisterManager::createRegister(Node *node, string value, string id) {
	//for declaring or reassigning a variable
}

string RegisterManager::createArithmeticOp(exp *firstExp, exp *secondExp, string op) {
	firstExp->loadExp();
	secondExp->loadExp();
	stringstream code;
	string firstReg;
	string secondReg;
	auto res = this->varName2Register.find((firstExp->NodeId));
	if (res != this->varName2Register.end()) {
		firstReg = res->second;
	} else {
		firstReg = firstExp->NodeRegister;
		//TODO::DO WE REALLY NEED THIS ELSE?
	}
	res = this->varName2Register.find((secondExp->NodeId));
	if (res != this->varName2Register.end()) {
		secondReg = res->second;
	} else {
		secondReg = secondExp->NodeRegister;
		//TODO::DO WE REALLY NEED THIS ELSE?
	}
	if (op == "DIV") {
		code << "call void @checkDiv(i32 " << secondReg << ")" << endl;
	}
	code << this->getNextRegisterName() << " = " << op << " i32 " << firstReg << " , " << secondReg << endl;
	if (firstExp->expType == "BYTE" && secondExp->expType == "BYTE") {
		string currReg = this->getCurrentRegisterName();
		code << this->getNextRegisterName() << "=" << "trunc i32" << currReg << "to i8" << endl;
		currReg = this->getCurrentRegisterName();
		code << this->getNextRegisterName() << "=" << "zext i8 " << currReg << "to i32" << endl;
	}
	return code.str();
}

string RegisterManager::loadVarName(string varName) {
	string stackRegister = this->varName2StackReg[varName];
	if (stackRegister != "") {
		//need to load to register
		string newReg = this->getNextRegisterName();
		buffer.emit(newReg + " = load i32, i32* " + stackRegister);
		this->varName2Register[varName] = newReg;
		return newReg;
	} else {
		return this->varName2Register[varName];
	}
}

string RegisterManager::createStringConstant() {
	stringstream stringConstant;
	stringConstant <<"w"<< this->stringCounter;
	this->stringCounter++;
	return stringConstant.str();
}

string RegisterManager::commperCodeGen(exp *firstExp, string op, exp *secExp) {
	stringstream code;
	string reg = this->getNextRegisterName();
	code << reg << " = icmp ";
	if (op == "==") {
		code << "eq ";
	} else if (op == "!=") {
		code << "ne ";
	} else if (op == "<") {
		code << "slt ";
	} else if (op == "<=") {
		code << "sle ";
	} else if (op == ">") {
		code << "sgt ";
	} else if (op == ">=") {
		code << "sge ";
	}
	code << "i32 " << firstExp->NodeRegister << ", " << secExp->NodeRegister << endl;
	string res = this->getNextRegisterName();
	code << res << " = zext i1 " << reg << " to i32";
	buffer.emit(code.str());
	return res;
}