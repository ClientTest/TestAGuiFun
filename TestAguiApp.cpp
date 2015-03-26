#include "stdafx.h"
#include "MfcLib/AGuiFun/AGuiApp.h"
#include "MfcLib/AGuiFun/AGuiPath.h"

void TestAguiApp()
{
	CString strPath="";
	strPath.Format("%sGameZECK.exe",AGuiFun::GetModuleDir());
	AGuiFun::CMDStartApp(strPath,"");
}