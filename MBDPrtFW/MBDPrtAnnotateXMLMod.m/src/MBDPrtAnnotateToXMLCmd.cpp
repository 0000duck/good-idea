// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDPrtAnnotateToXMLCmd.cpp
// The state chart based command: MBDPrtAnnotateToXMLCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#include "MBDPrtAnnotateToXMLCmd.h"
#include "CATMathPlane.h"

#include "CATCreateExternalObject.h"
CATCreateClass( MBDPrtAnnotateToXMLCmd);

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
MBDPrtAnnotateToXMLCmd::MBDPrtAnnotateToXMLCmd() :
  CATStateCommand ("MBDPrtAnnotateToXMLCmd", CATDlgEngOneShot, CATCommandModeShared) 
	  ,m_pSaveFileDlg(NULL),m_strSaveFilePath(NULL)
	  ,m_piDoc(NULL)
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
{
	m_piDoc = PrtService::GetPrtDocument();
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
MBDPrtAnnotateToXMLCmd::~MBDPrtAnnotateToXMLCmd()
{

	if (m_pSaveFileDlg != NULL)
	{
		m_pSaveFileDlg->RequestDelayedDestruction();
	}

}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void MBDPrtAnnotateToXMLCmd::BuildGraph()
{

	// 定义具体实现细节
	// 打开一个SaveFile对话框
	CATString iFileName("存储零件MBD附注信息到XML文件");
	m_pSaveFileDlg = new CATDlgFile((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),iFileName,CATDlgFolderChooser | CATDlgWndModal);
	m_pSaveFileDlg->SetVisibility(CATDlgShow);

	CATUnicodeString DocStorageName = m_piDoc->storageName();
	int flag = DocStorageName.SearchSubString(":\\");
	if (flag != -1)
	{
		int dirPos = DocStorageName.SearchSubString("\\",0,CATUnicodeString::CATSearchModeBackward);
		CATUnicodeString DocStoragePath = DocStorageName.SubString(0,dirPos);
		m_pSaveFileDlg->SetDirectory(DocStoragePath);

		//cout<<"零件存储路径："<<DocStoragePath.ConvertToChar()<<endl;
	}
	else
	{
		m_pSaveFileDlg->SetDirectory("c:\\");
	}

	// 两个消息响应
	AddAnalyseNotificationCB(m_pSaveFileDlg, 
		m_pSaveFileDlg->GetDiaCANCELNotification(), 
		(CATCommandMethod)&MBDPrtAnnotateToXMLCmd::OnSaveFileCancelAction, 
		NULL);  

	AddAnalyseNotificationCB(m_pSaveFileDlg, 
		m_pSaveFileDlg->GetWindCloseNotification(), 
		(CATCommandMethod)&MBDPrtAnnotateToXMLCmd::OnSaveFileCancelAction, 
		NULL); 

	int iTypeOfInput = 0;
	AddAnalyseNotificationCB(m_pSaveFileDlg, 
		m_pSaveFileDlg->GetDiaOKNotification(), 
		(CATCommandMethod)&MBDPrtAnnotateToXMLCmd::OnSaveFileOKAction, 
		&iTypeOfInput); 
}

// 点击cancel
void MBDPrtAnnotateToXMLCmd::OnSaveFileCancelAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//Specify that the command is finished
	if (m_pSaveFileDlg != NULL)
	{
		m_pSaveFileDlg->RequestDelayedDestruction();
		m_pSaveFileDlg = NULL;
	}

	//Specify that the command is finished
	RequestDelayedDestruction();
}

//
void MBDPrtAnnotateToXMLCmd::OnSaveFileOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	// 1 得到打开文件的全路径
	m_pSaveFileDlg->GetDirectory(m_strSaveFilePath);
	
	// 2 获取零件名称
	//获取零部件名称
	CATUnicodeString StrPartNumber;
	CATInit_var spInitOnDoc(m_piDoc);
	// 获得相应的容器类
	CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
	CATIPrtPart_var spPart = piPrtCont->GetPart();
	CATISpecObject_var spSpecOnPart = spPart;
	// 获得Product，更改零件编号
	CATIProduct_var spProduct = spPart->GetProduct( );
	StrPartNumber = spProduct->GetPartNumber();

	// 3 创建XML文档
	CATUnicodeString uXMLFileName;
	uXMLFileName = m_strSaveFilePath + "\\" + StrPartNumber + ".xml";

	CATIDOMElement_var spRoot;
	XMLService * piMBDXMLService = new XMLService();
	piMBDXMLService->CreateXMLDoc(uXMLFileName,"MBDAnnotation",spRoot);

	// 4 添加从CATIA解析出的附注信息
	CATIDOMElement_var iopNewElm;
	CATUnicodeString    uName;
	CATUnicodeString    uValue;
	CATListOfCATUnicodeString listAttNames;
	CATListOfCATUnicodeString listAttValues;
	piMBDXMLService->addXMLNode(spRoot,iopNewElm,"PartNumber",StrPartNumber,listAttNames,listAttValues,FALSE);
	
	// 4.1 查看本地的配置文件查找需要导出的CATIA几何图形集名称
	CATUnicodeString StrODataPath;
	DirFileService::GetCurrentDataPath(StrODataPath);
	CATUnicodeString strCustomMBDAnnotateXML = StrODataPath + "\\KTCustomConfig\\MBDAnnotateXML\\MBDAnnotateToXML.txt";

	CATListValCATUnicodeString ioastrFileContent;
	HRESULT hr = DirFileService::ReadFileByLines(strCustomMBDAnnotateXML,ioastrFileContent);

	if (SUCCEEDED (hr))
	{
		//获取catia结构树上对应几何图形集
		CATListValCATUnicodeString  ListStrSearchedFeatName;
		CATListValCATUnicodeString  ListStrXMLNodeName;
		CATListValCATISpecObject_var ListValOfspSearchGSMTool;

		for (int i = 1; i <= ioastrFileContent.Size(); i ++)
		{
			CATLISTV(CATUnicodeString) oStrVector;
			CHandleString::ParseStringByFBToken(ioastrFileContent[i],"<",">",oStrVector);

			if (oStrVector.Size() == 2)
			{
				ListStrSearchedFeatName.Append(oStrVector[1]);
				ListStrXMLNodeName.Append(oStrVector[2]);
			}
			
		}

		// 获取几何图形集的指针
		PrtService::CAAGsiSearchFeatureFromName(m_piDoc, ListStrSearchedFeatName,ListValOfspSearchGSMTool);
		CATListOfCATUnicodeString listGSMAttNames;
		CATListOfCATUnicodeString listGSMAttValues;
		
		for (int j = 1; j <= ListValOfspSearchGSMTool.Size(); j ++)
		{
			if (NULL_var != ListValOfspSearchGSMTool[j])
			{
				piMBDXMLService->addXMLNode(spRoot,iopNewElm,ListStrXMLNodeName[j],"",listAttNames,listAttValues,TRUE);

				// 获取几何集下面包含的参数
				PrtService::GetGSMToolsParameters(ListValOfspSearchGSMTool[j],listGSMAttNames,listGSMAttValues);

				for (int k = 1; k <= listGSMAttNames.Size(); k ++)
				{
					CATIDOMElement_var spLineElm;
					piMBDXMLService->addXMLNode(iopNewElm,spLineElm,"Line",listGSMAttValues[k],listAttNames,listAttValues,FALSE); 
				}

				listGSMAttNames.RemoveAll();
				listGSMAttValues.RemoveAll();
			}
		}
	
	}

	// 存储XML到本地
	piMBDXMLService->SaveXMLDoc(uXMLFileName);
	PrtService::ShowDlgNotify("存储信息","完成CATIA MBD附注信息解析，存储路径如下：\n" + uXMLFileName);

	// 退出交互命令程序
	// 析构选择对话框
	if (m_pSaveFileDlg != NULL)
	{
		m_pSaveFileDlg->RequestDelayedDestruction();
		m_pSaveFileDlg = NULL;
	}
	delete piMBDXMLService;

	// 退出cmd
	RequestDelayedDestruction();

}
