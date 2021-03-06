// MatChooseMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatChooseMainDlg.h"

#include <string>
using std::string;

#include "comutil.h"

#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#ifdef _DEBUG

# pragma comment(lib, "comsuppwd.lib")

#else

# pragma comment(lib, "comsuppw.lib")

#endif

# pragma comment(lib, "wbemuuid.lib")



// MatChooseMainDlg dialog

IMPLEMENT_DYNAMIC(MatChooseMainDlg, CDialog)

MatChooseMainDlg::MatChooseMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MatChooseMainDlg::IDD, pParent),m_piSon(NULL)
{
	if (NULL != m_piSon)
	{
		m_piSon->DestroyWindow();
		m_piSon = NULL;
	}
	//初始化COMBO ARRAY
	//m_alstCOMB.Add(m_COMBO01);
	/*m_alstCOMB.Add(m_COMBO02);
	m_alstCOMB.Add(m_COMBO03);
	m_alstCOMB.Add(m_COMBO04);
	m_alstCOMB.Add(m_COMBO05);
	m_alstCOMB.Add(m_COMBO06);
	m_alstCOMB.Add(m_COMBO07);*/

}


MatChooseMainDlg::~MatChooseMainDlg()
{
}

void MatChooseMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_COMBO01);
	DDX_Control(pDX, IDC_COMBO2, m_COMBO02);
	DDX_Control(pDX, IDC_COMBO3, m_COMBO03);
	DDX_Control(pDX, IDC_COMBO4, m_COMBO04);
	DDX_Control(pDX, IDC_COMBO5, m_COMBO05);
	DDX_Control(pDX, IDC_COMBO6, m_COMBO06);
	DDX_Control(pDX, IDC_COMBO7, m_COMBO07);
}


BEGIN_MESSAGE_MAP(MatChooseMainDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_NextStepPB, &MatChooseMainDlg::OnBnClickedNextsteppb)
	ON_BN_CLICKED(IDC_SearchPB, &MatChooseMainDlg::OnBnClickedSearchpb)
END_MESSAGE_MAP()


// MatChooseMainDlg message handlers

void MatChooseMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC dcMem; 
	dcMem.CreateCompatibleDC(&dc); 

	CRect rect1;
	GetClientRect(&rect1); 		

	CBitmap m_bitmap;
	m_bitmap.LoadBitmap(IDB_BITBackground);

	BITMAP bitMap;
	m_bitmap.GetBitmap(&bitMap);

	CBitmap *pbmpOld=dcMem.SelectObject(&m_bitmap);  
	dc.StretchBlt(0,(rect1.Height()-bitMap.bmHeight),bitMap.bmWidth,bitMap.bmHeight,&dcMem,0,0,bitMap.bmWidth,bitMap.bmHeight,SRCCOPY); 
}

HBRUSH MatChooseMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor==CTLCOLOR_BTN)  
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_SCROLLBAR)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_EDIT)
	{;
	pDC->SetTextColor(RGB(0,0,0));
	pDC->SetBkColor(RGB(255,255,255));
	HBRUSH b=CreateSolidBrush(RGB(255,255,255));
	return b;
	}
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}

	else if(nCtlColor==CTLCOLOR_MSGBOX )
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	return hbr;
}

void MatChooseMainDlg::OnBnClickedNextsteppb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new MatOtherInfoDlg(this);
	m_piSon->Create(IDD_OtherInfoDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

//查询函数，通过DLL访问数据库系统
HRESULT MatChooseMainDlg::QuaryDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult)
{
	HRESULT rc = E_FAIL;
	// method
	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef HRESULT (*lpFun)(BSTR* ,int ,BSTR *&, int&); 
	hDll = LoadLibrary(_T("MBDStdWebService.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("提示信息" );
		LocalFree( lpMsgBuf );
		return rc;
	}

	//	
	BSTR * ioQueryResult;
	int in0_nSizeIs = ialstCStrInput.GetSize();
	int out_nSizeIs = 0;
	BSTR *iStrQuery = new BSTR[in0_nSizeIs];

	//
	for (int i=0; i<in0_nSizeIs; i++)
	{
		//
		BSTR iobstr;
		CString cstr = ialstCStrInput.GetAt(i);
		CstringToBSTR(cstr,iobstr);
		iStrQuery[i]=iobstr;		
	}

	//
	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"MBDQuery");
		if (NULL==pMBDQuery)
		{
			AfxMessageBox(_T("DLL中函数寻找失败"));
		}


		//可能需要对输入条件进行判断，以求确定内容的可靠性
		HRESULT hr = pMBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

		if (SUCCEEDED(hr))
		{
			int i = 0;
			if (ioQueryResult != NULL)
			{
				while (NULL != *(ioQueryResult+i))
				{
					CString str(*(ioQueryResult+i));
					ioalstCStrResult.Add(str);
					//MessageBox(str,L"调用结果");
					i++;
				}
			}
		}

		::FreeLibrary(hDll);
	}
	
	//
	return S_OK;
}


HRESULT MatChooseMainDlg::InsertDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult)
{
	HRESULT rc = E_FAIL;
	// method
	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef HRESULT (*lpFun)(BSTR* ,int ,BSTR *&, int&); 
	hDll = LoadLibrary(_T("MBDStdWebService.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("提示信息" );
		LocalFree( lpMsgBuf );
		return rc;
	}
	//

	//	
	BSTR * ioQueryResult;
	int in0_nSizeIs = ialstCStrInput.GetSize();
	int out_nSizeIs = 0;
	BSTR *iStrQuery = new BSTR[in0_nSizeIs];

	//
	for (int i=0; i<in0_nSizeIs; i++)
	{
		//
		BSTR iobstr;
		CstringToBSTR(ialstCStrInput.GetAt(i),iobstr);
		iStrQuery[i]=iobstr;		
	}
	//

	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"MBDInsert");
		if (NULL==pMBDQuery)
		{
			AfxMessageBox(_T("DLL中函数寻找失败"));
		}


		//可能需要对输入条件进行判断，以求确定内容的可靠性

		HRESULT hr = pMBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

		if (SUCCEEDED(hr))
		{
			int i = 0;
			if (ioQueryResult != NULL)
			{
				while (NULL != *(ioQueryResult+i))
				{
					CString str(*(ioQueryResult+i));
					ioalstCStrResult.Add(str);
					//MessageBox(str,L"调用结果");
					i++;
				}
			}
		}

		::FreeLibrary(hDll);
	}

	return S_OK;
}

// 解析lic
string* MatChooseMainDlg::SplitString(string str, string split, int& iSubStrs)
{
	int iPos = 0; //分割符位置
	int iNums = 0; //分割符的总数
	string strTemp = str;
	string strRight;

	vector <string> iplist;  
	vector <string>::iterator iplist_Iter;

	iPos = strTemp.find(split);
	if (iPos != -1)
	{
		strTemp = strTemp.substr(iPos + split.length(), str.length() - iPos - split.length());
	}

	//计算子字符串
	while (iPos != -1)
	{
		iPos = strTemp.find(split);
		if (iPos == -1)
		{
			iplist.push_back(strTemp);
			break;
		}
		strRight = strTemp.substr(iPos + split.length(), strTemp.length() - iPos - split.length());
		string strLeft("");
		strLeft = strTemp.substr(0,iPos);
		iplist.push_back(strLeft);

		strTemp = strRight;
		iNums++;
	}


	// 获得各个"#FEATURE"
	int j = 0;
	iSubStrs = iplist.size();
	string *pStrSplit = new string[iplist.size()];
	string strlicValue,strlicName("SIGN=");

	for ( iplist_Iter =iplist.begin( ),j = 0; iplist_Iter != iplist.end( ); iplist_Iter ++ ,j++)
	{
		iPos = iplist_Iter->find(strlicName);
		strlicValue = iplist_Iter->substr(iPos + strlicName.length(), iplist_Iter->length() - iPos - strlicName.length());

		CString cstrTran(strlicValue.c_str());

		cstrTran.Remove(L'\\');
		//cstrTran.Remove(L'\n');
		cstrTran.Remove(L' ');

		string strCs_str = CStringA(cstrTran);

		*(pStrSplit+j) = strCs_str;

	}

	return pStrSplit;
}

//Cstring To BSTR Convert
void MatChooseMainDlg::CstringToBSTR(CString icstr, BSTR &iobstr)
{
	iobstr=icstr.AllocSysString();
}


//Cstring To BSTR Convert
void MatChooseMainDlg::BSTRToCstring(CString &iocstr, BSTR ibstr)
{
	CString str(ibstr == NULL ? L"":ibstr);
    iocstr = str;
}

void MatChooseMainDlg::OnBnClickedSearchpb()
{
	// TODO: 在此添加控件通知处理程序代码
	CStringArray ialstCStrInput,ioalstCStrResult;
	//
	CString cstr01(_T("DatabaseName=F_BEAD_FLANGE_SPEC_INFO"));
	ialstCStrInput.Add(cstr01);
	//
	QuaryDatabase(ialstCStrInput,ioalstCStrResult);

	//
	for (int i=0; i<ioalstCStrResult.GetSize(); i++)
	{
		MessageBox(ioalstCStrResult.GetAt(i),L"调用结果");
	}
}