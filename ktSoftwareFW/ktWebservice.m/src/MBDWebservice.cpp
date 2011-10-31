// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDWebservice.cpp
// Header definition of MBDWebservice
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#include "MBDWebservice.h"

#include "winsock2.h"
#include "winsock.h"
#include "comutil.h"

#ifdef _DEBUG
# pragma comment(lib, "comsuppwd.lib")
#else
# pragma comment(lib, "comsuppw.lib")
#endif
# pragma comment(lib, "wbemuuid.lib")
# pragma comment(lib, "comsupp.lib")

#include "CATApplicationFrame.h"
#include "CATDlgWindow.h"
#include "CATDlgNotify.h"

#include "MBDServicesHttpBinding.nsmap"
#include "soapMBDServicesHttpBindingProxy.h"

//C++ HEADER
#include "iostream"
using namespace std;
 
CATImplementClass( MBDWebservice,
                   Implementation, 
                   CATBaseUnknown,
                   CATNull );
 
//-----------------------------------------------------------------------------
// MBDWebservice : constructor
//-----------------------------------------------------------------------------
MBDWebservice::MBDWebservice():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// MBDWebservice : destructor
//-----------------------------------------------------------------------------
MBDWebservice::~MBDWebservice()
{
}
 
//-----------------------------------------------------------------------------
// MBDWebservice : copy constructor
//-----------------------------------------------------------------------------
MBDWebservice::MBDWebservice(MBDWebservice& original):
   CATBaseUnknown(original)
{
}
 
//-----------------------------------------------------------------------------
// MBDWebservice : equal operator
//-----------------------------------------------------------------------------
MBDWebservice& MBDWebservice::operator=(MBDWebservice& original)
{
   CATBaseUnknown::operator=(original);
   return *this;
}

//-----------------------------------------------------------------------------
// ktWebservice : constructor
//-----------------------------------------------------------------------------
void MBDWebservice::GetUserComputerInfo(CATUnicodeString &strUserHostname,CATUnicodeString &strUserIpaddress)
{

	//--------------------------------------------------------------
	// [5/25/2010 ev5adm]
	char szhostname[128];

	if( gethostname(szhostname, 128) == 0 )
	{
		strUserHostname = szhostname ;
		//cout<<"用户主机名："<<strUserHostname.ConvertToChar()<<endl;

		// 获得主机ip地址
		struct hostent * phost;
		int i;
		phost = gethostbyname(szhostname);
		i=0;
		int j;
		int h_length=4;
		for( j = 0; j<h_length; j++ )
		{
			CATUnicodeString addr;

			if( j > 0 )
				strUserIpaddress += ".";

			int addrint = (unsigned int)((unsigned char*)phost->h_addr_list[i])[j];
			addr.BuildFromNum(addrint);

			//addr.Format("%u", (unsigned int)((unsigned char*)phost->h_addr_list[i])[j]);
			strUserIpaddress += addr;
		}

		//cout<<"IP地址是："<<strUserIpaddress<<endl;
	}

	wchar_t * userName = new wchar_t[MAX_PATH];
	DWORD size=MAX_PATH;

	::GetUserName(userName,&size);

	CATUnicodeString strUserName(""); strUserName.BuildFromWChar(userName);
	strUserHostname = strUserName;

}


HRESULT MBDWebservice::QueryDataWebService(CATListValCATUnicodeString &strListOfSearchItems,CATListValCATUnicodeString &strListOfSearchResult)
{
	HRESULT hr = S_OK;

	//调用DLL通过webservice查询结果
	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef HRESULT (*lpFun)(BSTR* ,int ,BSTR *&, int&); 
	hDll = LoadLibrary(_T("MBDWebService.dll"));
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
		return E_FAIL;
	}

	BSTR *ioQueryResult;
	int in0_nSizeIs = strListOfSearchItems.Size();
	int out_nSizeIs = 0;

	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"MBDQuery");
		if (NULL==pMBDQuery)
		{
			//AfxMessageBox(_T("DLL中函数寻找失败"));
		}

		//可能需要对输入条件进行判断，以求确定内容的可靠性
		BSTR *iStrQuery = new BSTR[in0_nSizeIs];

		for (int j = 1; j <= in0_nSizeIs; j++)
		{
			strListOfSearchItems[j].ConvertToBSTR(iStrQuery+j-1);
		}

		hr = pMBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

		for (int i = 1; i <= out_nSizeIs; i++)
		{
			CATUnicodeString strConvert;
			strConvert.BuildFromBSTR(ioQueryResult[i - 1]);
			strListOfSearchResult.Append(strConvert);
		}

		::FreeLibrary(hDll);
	}

	return hr;
}



HRESULT MBDWebservice::InsertDataWebService(CATListValCATUnicodeString astrKeyWords)
{
	HRESULT hr = S_OK;

	//调用DLL通过webservice查询结果
	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef HRESULT (*lpFun)(BSTR* ,int ,BSTR *&, int&); 
	hDll = LoadLibrary(_T("MBDWebService.dll"));
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
		return E_FAIL;
	}

	BSTR *ioInsertResult;
	int in0_nSizeIs = astrKeyWords.Size();
	int out_nSizeIs = 0;

	if (NULL!=hDll)
	{
		lpFun pMBDInsert = (lpFun)GetProcAddress(hDll,"MBDInsert");
		if (NULL==pMBDInsert)
		{
			//AfxMessageBox(_T("DLL中函数寻找失败"));
		}

		//可能需要对输入条件进行判断，以求确定内容的可靠性
		BSTR *iStrInsert = new BSTR[in0_nSizeIs];
		for (int j = 1; j <= in0_nSizeIs; j++)
		{
			astrKeyWords[j].ConvertToBSTR(iStrInsert+j-1);
		}

		hr = pMBDInsert(iStrInsert,in0_nSizeIs,ioInsertResult,out_nSizeIs);

		::FreeLibrary(hDll);
	}

	return hr;
}


//
void MBDWebservice::ShowDlgNotify(CATUnicodeString strTitle, CATUnicodeString strValue)
{
	CATApplicationFrame *pApplication = CATApplicationFrame::GetFrame(); 
	if (NULL != pApplication) 
	{ 
		CATDlgWindow * pMainWindow = pApplication->GetMainWindow();
		CATDlgNotify *pNotifyDlg = new CATDlgNotify (pMainWindow, "MBD Notify", CATDlgNfyWarning);
		if (NULL != pNotifyDlg) 
		{
			pNotifyDlg->DisplayBlocked(strValue,strTitle);
			pNotifyDlg->RequestDelayedDestruction(); 
		}
	}
}


HRESULT MBDWebservice::QueryByGSoap(CATListValCATUnicodeString &strListOfSearchItems,CATListValCATUnicodeString &strListOfSearchResult)
{
	//MBDServicesHttpBindingProxy service;

	////构造输入变量
	//_kt1__Query ns1__Query; 
	//ns1__Query.in0 = new kt1__ArrayOfString();

	//for (int i = 1; i <= strListOfSearchItems.Size(); i ++)
	//{
	//	ns1__Query.in0->string.push_back(strListOfSearchItems[i].ConvertToChar());
	//}

	////调用输出变量
	//_kt1__QueryResponse ns1__QueryResponse;
	//
	////调用函数
	//if (service.Query(&ns1__Query, &ns1__QueryResponse) == SOAP_OK)
	//{
	//	//解析结果
	//	ns1__QueryResponse.out->string;
	//	std::vector <string>::iterator iplist_Iter;

	//	for ( iplist_Iter =ns1__QueryResponse.out->string.begin( ); iplist_Iter != ns1__QueryResponse.out->string.end( ); iplist_Iter++)
	//	{
	//		strListOfSearchResult.Append(iplist_Iter->c_str());
	//	}

	//}

	//else return E_FAIL;


	return S_OK;

}

 
