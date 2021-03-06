// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignCmd.h
// The state chart based command: PrtFstDesignCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   STATECOMMAND
//End CAA2 Wizard Generation Report
//
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstDesignCmd_H
#define PrtFstDesignCmd_H

#include "ktPubHeaders.h"
#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "PrtFstDesignDlg.h"
#include "CATFeatureImportAgent.h"
#include "CATPathElementAgent.h"
#include "CATHSO.h"
#include "CAT3DBagRep.h"
#include "CAT3DManipulator.h"

//
#include "PrtFstAccessDlg.h"
#include "PrtFstFreeStyleDlg.h"
#include "PrtFstKnowledgeBasedDlg.h"

#include "PrtFstFreeStyleMainBoltDlg.h"
#include "PrtFstFreeStyleNutDlg.h"
#include "PrtFstFreeStyleWasherDlg.h"
#include "PrtFstFreeStyleShelterDlg.h"

#include "PrtFstKnowledgeMainBoltDlg.h"
#include "PrtFstKnowledgeNutDlg.h"
#include "PrtFstKnowledgeWasherDlg.h"

//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class PrtFstDesignCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstDesignCmd, CATStateCommand )

  public:

  PrtFstDesignCmd();
  virtual ~PrtFstDesignCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();

  //消息框响应函数
  void OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void ApplyDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //判断是否为ZP模型
  BOOL IsThisZPPrt(CATUnicodeString istrDocName);

  //各种转换消息响应函数
  CATBoolean ChoosePoints( void *UsefulData);
  CATBoolean ChooseFirstSurfs( void *UsefulData);
  CATBoolean ChooseSecSurfs( void *UsefulData);
  //
  CATBoolean ActivePointsSL( void *UsefulData);
  CATBoolean ActiveFirstSurfSL( void *UsefulData);
  CATBoolean ActiveSecSurfSL( void *UsefulData);
  //
  CATBoolean ChoosePrds( void *UsefulData);
  CATBoolean ActivePrdSL( void *UsefulData);  
  CATBoolean ChoosePointGSM( void *UsefulData);  
  CATBoolean ActivePointGSMPB( void *UsefulData);  
  //
  //过滤函数
  CATBoolean SeletedIsPart(CATDialogAgent * iAgent, void * iUsefulData);
  //高亮显示当前所选行
  void ShowSeletedLine(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs);
  //删除所有点
  void DeleteAllPointsCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //反向安装方向
  void ReverseDirCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data); 
  //选择紧固件类型
  void ChooseFstCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data); 
  //选择查看紧固件详细信息响应
  void ChoosedFstNormalInfoMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data); 
  //在IOS中显示标记点
  void ShowPointInfoInISO(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs);
  //判断一个曲面特征是否在另一个数组中
  BOOL IsTheSpecInLstSpec(CATISpecObject_var iSpec, CATListValCATISpecObject_var iLstSpec);
  //获得传入特征的的父级节点
  HRESULT GetLinkImportPrd(CATISpecObject_var& ispFeature,CATIProduct_var &ospSourcePrd);
  //箭头的回调函数
  void CBManipulator(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //根据输入条件创建点线模型
  void CreateFstLineAndCircle();
  //获取放置点线模型的零件几何图形集
  void GetPartsJointGSMTool(CATISpecObject_var &iospJointGSMTool,CATListValCATUnicodeString ilstStrPartsInstName);
  //按照参数信息创建点线模型
  void CreateFstLinesAndCircles(CATISpecObject_var ispPoint01,CATISpecObject_var ispPoint02,CATISpecObject_var ispJointTypeGSMTool,CATISpecObject_var ispPosPoint);
  //计算安装方向及夹持厚度，为紧固件选择提供依据
  void CalculateJoinThickInTop(CATListValCATISpecObject_var ilstspSurf01,CATListValCATISpecObject_var ilstspSurf02, CATListValCATISpecObject_var ilstspPoints);
  //转变OK APPLY按钮的显示状态
  void ChangeOKApplyState();
  //设置或者修改 紧固件描述 中的类型信息
  void SetOrChangeJstTypeInfo(CATISpecObject_var iospJointGSMTool,CATUnicodeString strChooseFstType,double idCount,CATListValCATUnicodeString ilststrJstTypeInfoName, CATListValCATUnicodeString ilststrJstTypeInfoValue);
  //从PV列表中获得指定的字符串
  void GetStrlistFromListPV(int iCount,CATListPV ipListStrName,CATListValCATUnicodeString &ioalstName);
  //清理紧固件信息数组函数
  void ClearFstInfoLst();


  //---------------------------------
  //对ACCESS DLG的消息响应
  //---------------------------------
  void OkFstAccessDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void CloseFstAccessDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void AccessDlgGoToChoosePBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //
  //---------------------------------
  //对FreeStyle DLG的消息响应
  //---------------------------------
  void CloseFstFreeStyleDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  
  //
  //---------------------------------
  //对FreeStyle MainBolt DLG的消息响应
  //---------------------------------
  void CloseFstFreeStyleMainBoltDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleMainBoltDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleMainBoltDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleMainBoltDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleMainBoltDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  
  //---------------------------------
  //对FreeStyle Nut DLG的消息响应
  //---------------------------------
  void CloseFstFreeStyleNutDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleNutDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleNutDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleNutDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleNutDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //---------------------------------
  //对FreeStyle Washer DLG的消息响应
  //---------------------------------
  void CloseFstFreeStyleWasherDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void FstFreeStyleWasherDlgChooseWashersMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgRemovePBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleWasherDlgClearAllPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean OnWasherPushItemSelectCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);


  //---------------------------------
  //对FreeStyle Shelter DLG的消息响应
  //---------------------------------
  void CloseFstFreeStyleShelterDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleShelterDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleShelterDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleShelterDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstFreeStyleShelterDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void FstFreeStyleShelterDlgClearAllPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean OnShelterPushItemSelectCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  
  //
  //---------------------------------
  //对KnowledgeBased DLG的消息响应
  //---------------------------------
  void CloseFstKnowledgeBasedDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //
  //
  //---------------------------------
  //对KnowledgeBased MainBolt DLG的消息响应
  //---------------------------------
  void CloseFstKnowledgeBasedMainBoltDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedMainBoltDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedMainBoltDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedMainBoltDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedMainBoltDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //---------------------------------
  //对KnowledgeBased Nut DLG的消息响应
  //---------------------------------
  void CloseFstKnowledgeBasedNutDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedNutDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedNutDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedNutDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //---------------------------------
  //对KnowledgeBased Washer DLG的消息响应
  //---------------------------------
  void CloseFstKnowledgeBasedWasherDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedWasherDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedWasherDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedWasherDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void FstKnowledgeBasedWasherDlgChooseWashersMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedWasherDlgRemovePBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedWasherDlgClearAllPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean OnKnowledgeBasedWasherPushItemSelectCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //---------------------------------
  //对KnowledgeBased Shelter DLG的消息响应
  //---------------------------------
  void CloseFstKnowledgeBasedShelterDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedShelterDlgGoToSearchPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedShelterDlgLastStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedShelterDlgNextStepPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void FstKnowledgeBasedShelterDlgSearchResultsMLCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void FstKnowledgeBasedShelterDlgClearAllPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean OnKnowledgeBasedShelterPushItemSelectCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //根据输入的行数信息从数据列表中获取希望的字符串信息
  void GetChoosedMLValue(int idLine,CATListPV iplstMainFstResults, CATListValCATUnicodeString &iolstStrValue);

private:
	PrtFstDesignDlg *m_pDlg;

	//文档指针
	CATDocument *m_piDoc;
	CATUnicodeString m_strDocName;
	CATFrmEditor *m_piEditor;
	CATHSO *m_piHSO;
	CATISO *m_piISO;

	//定义代理
	CATFeatureImportAgent *m_piFirstSurfAgt,*m_piSecSurfAgt,*m_piPointsAgt,*m_piPointGSMAgt;
	CATPathElementAgent *m_piPrdAgt;
	CATDialogAgent *m_piPointSLAgt,*m_piFirstSurfSLAgt,*m_piSecSurfSLAgt,*m_piPrdSLAgt,*m_piPointGSMPBAgt;

	//存储中间数据变量
	CATListValCATISpecObject_var m_lstSpecPoints,m_lstSpecPrds;
	CATListValCATISpecObject_var m_lstSpecFirstSurfs,m_lstSpecSecSurfs;

	//夹持厚度最大值及最小值
	double m_dJstThickMax,m_dJstThickMin, m_dFirstPrdThickMin,m_dFirstPrdThickMax;

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------
	//定义字符串列表指针，从动态DLL中获取这些信息，此值将直接写入特征属性中
	//---------------------------------------------------------
	CATListPV  m_pListStrPropertyName,m_pListStrPropertyValue; //标准号信息
	CATListPV  m_pListStrSpecialName,m_pListStrSpecialValue; //规格号信息

	CATListValCATUnicodeString m_alistStrFSTType; //存储紧固件类型：螺栓，螺钉，铆钉，螺母，垫片，格式：螺栓|六角螺栓
	CATListValCATUnicodeString m_lststrCirclePositions; //螺母、垫片的安装位置，需要写入特征属性中
	
	//从交互选择中获取如下信息
	CATListValCATUnicodeString m_alistStrFSTName; //存储紧固件标识号
	double m_dMainFstLength, m_dMainFstThickLimit;
	CATListOfDouble m_lstCircleRadiusValues,m_lstCircleThicks;
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------

	//定义标识，确认是否已经选择了紧固件
	CATBoolean m_userChoosedFlag;

	//ZP模型紧固件计数器
	double m_dFstMaxIndex;

	//--------------------------------------------------------
	//紧固件选择对话框
	//--------------------------------------------------------
	PrtFstAccessDlg *m_pFstAccessDlg;
	//
	PrtFstFreeStyleDlg *m_pFstFreeStyleDlg;
	//
	PrtFstFreeStyleMainBoltDlg *m_pFstFreeStyleMainBoltDlg;
	PrtFstFreeStyleNutDlg *m_pFstFreeStyleNutDlg;
	PrtFstFreeStyleWasherDlg *m_pFstFreeStyleWasherDlg;
	//
	PrtFstFreeStyleShelterDlg *m_pFstFreeStyleShelterDlg;

	//自由选择获取的所有紧固件属性信息
	CATListPV m_plstMainFstResults01; //主紧固件标准号信息
	CATListValCATUnicodeString m_lstStrMainFstTitles01;
	CATListValCATUnicodeString m_lstStrMainFstChoosed01;
	CATListPV m_plstMainFstResults02; //主紧固件标识号信息
	CATListValCATUnicodeString m_lstStrMainFstTitles02;
	CATListValCATUnicodeString m_lstStrMainFstChoosed02;
	//
	CATUnicodeString m_strMainFstTypeFlag;
	//记录头部类型及头部厚度值，解决：沉头、半沉头、埋头、半埋头类型安装点下移位置值，讨论后废弃
	CATUnicodeString m_strMainFstHeadType;
	double m_dHeadThickness;
	
	//记录所选公称直径参数值
	CATUnicodeString m_strdFstDiameterValue;
	double m_dFstDiameterValue;
	//记录所选的**余量**
	double m_dLeftCheck;
	
	//
	//螺母信息
	CATListPV m_plstNutFstResults01; //螺母标准号信息
	CATListValCATUnicodeString m_lstStrNutFstTitles01;
	CATListValCATUnicodeString m_lstStrNutFstChoosed01;
	CATListPV m_plstNutFstResults02; //螺母规格号信息
	CATListValCATUnicodeString m_lstStrNutFstTitles02;
	CATListValCATUnicodeString m_lstStrNutFstChoosed02;
	//
	CATUnicodeString m_strNutFstTypeFlag;

	//
	//记录所选螺母厚度参数值
	CATUnicodeString m_strdNutFstThickValue;
	double m_dNutFstThickValue;

	//
	//垫圈信息
	CATListPV m_plstWasherFstResults01; //垫圈标准号信息
	CATListValCATUnicodeString m_lstStrWasherFstTitles01;
	CATListValCATUnicodeString m_lstStrWasherFstChoosed01;
	CATListPV m_plstWasherFstResults02; //垫圈规格号信息
	CATListValCATUnicodeString m_lstStrWasherFstTitles02;
	CATListValCATUnicodeString m_lstStrWasherFstChoosed02;
	//
	CATUnicodeString m_strWasherFstTypeFlag;

	//右键context按钮对话框
	CATDlgContextualMenu  *m_pContextMenu;
	CATDlgPushItem * m_pPushItemSelect;

	//垫圈所选信息
	CATListPV m_plstWasherFstChoosedTitles01;  //垫圈标准号信息
	CATListPV m_plstWasherFstChoosedResults01; //垫圈标准号信息
	CATListPV m_plstWasherFstChoosedTitles02;  //垫圈规格号信息
	CATListPV m_plstWasherFstChoosedResults02; //垫圈规格号信息
	//垫圈位置信息
	CATListValCATUnicodeString m_lstStrWasherPos;
	
	//所选时候的厚度
	double m_dSearchedWasherThick;
	double m_dChoosedWasherThick;
	//垫圈厚度总值
	double m_dWasherFstThickValueStart,m_dWasherFstThickValueEnd;
	//
	CATListValCATUnicodeString m_lstStrWasherFstTypeFlag;
	//
	int m_IndexChoosedWasher;

	//保护罩
	CATListPV m_plstShelterFstResults01; //保护罩标准号信息
	CATListValCATUnicodeString m_lstStrShelterFstTitles01;
	CATListValCATUnicodeString m_lstStrShelterFstChoosed01;
	CATListPV m_plstShelterFstResults02; //保护罩规格号信息
	CATListValCATUnicodeString m_lstStrShelterFstTitles02;
	CATListValCATUnicodeString m_lstStrShelterFstChoosed02;
	//
	CATUnicodeString m_strShelterFstTypeFlag;

	//右键context按钮对话框
	CATDlgContextualMenu  *m_pShelterContextMenu;
	CATDlgPushItem * m_pShelterPushItemSelect;

	//垫圈所选信息
	CATListValCATUnicodeString m_lstShelterFstChoosedTitles01;  //保护罩标准号信息
	CATListValCATUnicodeString m_lstShelterFstChoosedResults01; //保护罩标准号信息
	CATListValCATUnicodeString m_lstShelterFstChoosedTitles02;  //保护罩规格号信息
	CATListValCATUnicodeString m_lstShelterFstChoosedResults02; //保护罩规格号信息
	//保护罩位置信息
	CATUnicodeString m_strShelterPos;
	CATUnicodeString m_strChoosedShelterFstTypeFlag;

	//[9/22/2012 xyuser]
	//添加知识捕获功能
	CATUnicodeString m_strSendKnowMainFst;
	CATUnicodeString m_strSendKnowNutFst;
	CATListValCATUnicodeString m_lststrSendKnowWasherFst;

	//-----------------------------------------------------------------------------
	//知识选择对话框
	//-----------------------------------------------------------------------------
	PrtFstKnowledgeBasedDlg *m_pFstKnowledgeBasedDlg;
	PrtFstKnowledgeMainBoltDlg *m_pFstKnowledgeMainBoltDlg;
	PrtFstKnowledgeNutDlg *m_pFstKnowledgeNutDlg;
	PrtFstKnowledgeWasherDlg *m_pFstKnowledgeWasherDlg;
	PrtFstFreeStyleShelterDlg *m_pFstKnowledgeShelterDlg;

	//知识库选取信息
	CATListValCATUnicodeString m_lstStrKnowledgeFstTitles, m_lstStrKnowledgeFstChoosed;
	CATListPV m_plstKnowledgeFstResults;

	//右键context按钮对话框
	CATDlgContextualMenu  *m_pKnowWasherContextMenu;
	CATDlgPushItem * m_pKnowWasherPushItemSelect;

	//右键context按钮对话框
	CATDlgContextualMenu  *m_pKnowShelterContextMenu;
	CATDlgPushItem * m_pKnowShelterPushItemSelect;


};

//----------------------------------------------------------------------

#endif
