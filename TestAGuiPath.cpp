#include "stdafx.h"
#include "TestMain.h"
#include "MfcLib/AGuiFun/AGuiPath.h"

void TestAGuiPath()
{
	CString strPath = AGuiFun::GetModuleDir();
	AGuiObj::AGuiLog()->AppendMsg("GetModuleDir() return:"+strPath);

	AGuiFun::GetRootDir(strPath);
	AGuiObj::AGuiLog()->AppendMsg("GetRootDir() return:"+strPath);

	strPath = AGuiFun::GetFilePath();
	AGuiObj::AGuiLog()->AppendMsg("GetFilePath() return:"+strPath);

	strPath = AGuiFun::GetParentDir();
	AGuiObj::AGuiLog()->AppendMsg("GetParentDir() return:"+strPath);

	strPath = AGuiFun::GetSystemDir();
	AGuiObj::AGuiLog()->AppendMsg("GetSystemDir() return:"+strPath);

	strPath = AGuiFun::GetConfigPath()+"a.txt";
	AGuiFun::DelDirFile(strPath);

	/*strPath+="agui\\path\\makedir\\a.txt";
	AGuiFun::MakeDir(strPath);
	AGuiFun::MakeDir("..\\Agui\\temp\\log\\abc");
	AGuiFun::MakeDir(".\\Agui\\temp\\log\\abcd");*/
}