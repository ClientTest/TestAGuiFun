#include "stdafx.h"
#include "TestMain.h"
#include "MfcLib/AGuiFun/AGuiString.h"

void TestAGuiString()
{
	CString str = "whg�ƺ�֮10086ˮ������ag10086ui";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	for(int i=0;i<str.GetLength();i++)
	{
		CString strMsg="";
		if(AGuiFun::IsDigitLetter(str,i))
		{
			strMsg.Format("��%d���ַ��������ַ�\n",i);
		}
		else if(AGuiFun::IsEnglishLetter(str,i))
		{
			strMsg.Format("��%d���ַ���Ӣ���ַ�\n",i);
		}
		else if (AGuiFun::IsChaneseLetter(str,i))
		{
			strMsg.Format("��%d���ַ��������ַ�\n",i);
		}
		 else
		{
			strMsg.Format("��%d���ַ�ʲô�����ǣ�oh No !!!\n",i);
		}
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	CString strLimit="";
	for(int i=1;i<=str.GetLength()+2;i++)
	{
		strLimit=AGuiFun::LimitString(str,i);
		CString strMsg="";
		strMsg.Format("����Ϊ%d�����ַ���=%s\n",i,strLimit);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	if(!AGuiFun::IsChaneseLetter(str))
	{
		CString strMsg="";
		strMsg.Format("���������ַ���Ϊ����\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	if(!AGuiFun::IsEnglishLetter(str))
	{
		CString strMsg="";
		strMsg.Format("���������ַ���ΪӢ��\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	if(!AGuiFun::IsDigitLetter(str))
	{
		CString strMsg="";
		strMsg.Format("���������ַ���Ϊ����\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	str	= "λ��δ�����ǹ�";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsChaneseLetter(str))
	{
		CString strMsg="";
		strMsg.Format("�����ַ���Ϊ����\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	str	= "helloword";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsEnglishLetter(str))
	{
		CString strMsg="";
		strMsg.Format("�����ַ���ΪӢ��\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	str	= "5201314";
	AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
	if(AGuiFun::IsDigitLetter(str))
	{
		CString strMsg="";
		strMsg.Format("�����ַ���Ϊ����\n");
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}

	{
		int nFirstPos,nLastPos;
		str = "   whg  10086  ������   ";
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
		strMsg.Format("���ַ���%d=%s;\n",i,vecRes.at(i));
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
	{
		str="sdf�����˼��ʱ��AguIhelloaguiworldgui";
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
		str="sdf�����˼��ʱ��AguIhelloaguiworldaguiAGUIAgui";
		AGuiObj::AGuiLog()->AppendMsg("str=:-------"+str);
		CString strMsg="";
		CString strPlaceFirst = AGuiFun::ReplaceFirstNoCase(str,"agui","wuhuagui");
		CString strPlaceLast = AGuiFun::ReplaceLastNoCase(str,"agui","wuhuagui");
		CString strPlaceAll = AGuiFun::ReplaceAllNoCase(str,"agui","wuhuagui");
		strMsg.Format("str=%s\n,ReplaceFirstNoCase=%s\n,ReplaceLastNoCase=%s\n,ReplaceAllNoCase=%s\n",str,strPlaceFirst,strPlaceLast,strPlaceAll);
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
}