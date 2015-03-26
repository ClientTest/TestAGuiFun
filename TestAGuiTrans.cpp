#include "stdafx.h"
#include "TestMain.h"
#include "MfcLib/AGuiFun/AGuiTrans.h"

void TestAGuiTrans()
{
	PBYTE pBuf=NULL;
	CString strSrc="ÖÐ¹úwhg1234785522";
	CString strRes="";
	pBuf = AGuiFun::String2PBYTE(strSrc);
	if(pBuf)
	{
		strRes = AGuiFun::PBYTE2String(pBuf);
		//delete[] pBuf;
		AGuiObj::AGuiLog()->AppendMsg("PBYTE2String="+strRes);
	}
}