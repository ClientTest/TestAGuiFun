#ifndef WHG_TESTMAIN_H
#define WHG_TESTMAIN_H
#include "AGuiLog/IAGuiLOG.h"

void TestAGuiString();
void TestAGuiPath();
void TestAguiApp();
void TestAGuiTrans();

static void TestMainFun()
{
	TestAGuiString();
	TestAGuiPath();
	TestAGuiTrans();
	//TestAguiApp();
}

#endif