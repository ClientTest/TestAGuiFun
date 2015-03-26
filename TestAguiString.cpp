#include "stdafx.h"
#include "TestMain.h"
#include "MfcLib/AGuiFun/AGuiString.h"

void TestAGuiString()
{
	CString str = "whg黄河之10086水天上来ag10086ui";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	for(int i=0;i<str.GetLength();i++)
	{
		CString strMsg="";
		if(AGuiFun::IsDigitLetter(str,i))
		{
			strMsg.Format("第%d个字符是数字字符\n",i);
		}
		else if(AGuiFun::IsEnglishLetter(str,i))
		{
			strMsg.Format("第%d个字符是英文字符\n",i);
		}
		else if (AGuiFun::IsChaneseLetter(str,i))
		{
			strMsg.Format("第%d个字符是中文字符\n",i);
		}
		 else
		{
			strMsg.Format("第%d个字符什么都不是，oh No !!!\n",i);
		}
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	CString strLimit="";
	for(int i=1;i<=str.GetLength()+2;i++)
	{
		strLimit=AGuiFun::LimitString(str,i);
		CString strMsg="";
		strMsg.Format("长度为%d的子字符串=%s\n",i,strLimit);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	if(!AGuiFun::IsChaneseLetter(str))
	{
		CString strMsg="";
		strMsg.Format("不是所有字符都为中文\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	if(!AGuiFun::IsEnglishLetter(str))
	{
		CString strMsg="";
		strMsg.Format("不是所有字符都为英文\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	if(!AGuiFun::IsDigitLetter(str))
	{
		CString strMsg="";
		strMsg.Format("不是所有字符都为数字\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	str	= "位卑未敢忘忧国";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsChaneseLetter(str))
	{
		CString strMsg="";
		strMsg.Format("所有字符都为中文\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	str	= "helloword";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsEnglishLetter(str))
	{
		CString strMsg="";
		strMsg.Format("所有字符都为英文\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	str	= "5201314";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsDigitLetter(str))
	{
		CString strMsg="";
		strMsg.Format("所有字符都为数字\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	{
		int nFirstPos,nLastPos;
		str = "   whg  10086  王阳明   ";
		AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
		nFirstPos = AGuiFun::FindFirstNotOf(str,' ');
		nLastPos = AGuiFun::FindLastNotOf(str,' ');
		CString strMsg="";
		str = AGuiFun::TrimString(str);
		strMsg.Format("nFirstPos=%d,nLastPos=%dstr=%s;\n",nFirstPos,nLastPos,str);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	str="&whg&&agui&&&&hello&world&&&";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	vector<CString> vecRes;
	int nLen = AGuiFun::SplitByChar(str,'&',vecRes);
	for(int i=0;i<nLen;i++)
	{
		CString strMsg="";
		strMsg.Format("子字符串%d=%s;\n",i,vecRes.at(i));
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	{
		str="sdf便是人间好时节AguIhelloaguiworldgui";
		AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
		int nFirstPos,nLastPos;
		nFirstPos = AGuiFun::FindFirstNoCase(str,"aGUi");
		nLastPos = AGuiFun::FindLastNoCase(str,"aGUi");
		CString strMsg="";
		CString strReverse = AGuiFun::ReverseString(str);
		strMsg.Format("nFirstPos=%d,nLastPos=%d,ReverseString=%s;\n",nFirstPos,nLastPos,strReverse);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	{
		str="sdf便是人间好时节AguIhelloaguiworldaguiAGUIAgui";
		AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
		CString strMsg="";
		CString strPlaceFirst = AGuiFun::ReplaceFirstNoCase(str,"agui","wuhuagui");
		CString strPlaceLast = AGuiFun::ReplaceLastNoCase(str,"agui","wuhuagui");
		CString strPlaceAll = AGuiFun::ReplaceAllNoCase(str,"agui","wuhuagui");
		strMsg.Format("str=%s\n,ReplaceFirstNoCase=%s\n,ReplaceLastNoCase=%s\n,ReplaceAllNoCase=%s\n",str,strPlaceFirst,strPlaceLast,strPlaceAll);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
}