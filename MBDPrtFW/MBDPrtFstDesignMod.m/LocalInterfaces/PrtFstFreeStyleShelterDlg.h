// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleShelterDlg.h
// The dialog : PrtFstFreeStyleShelterDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   DIALOG
//End CAA2 Wizard Generation Report
//
//  Sep 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstFreeStyleShelterDlg_H
#define PrtFstFreeStyleShelterDlg_H

#include "CATDlgDialog.h"
#include "CATDlgInclude.h"
#include "CATLISTPIUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "MBDWebservice.h"
#include "iostream"
using namespace std;


//----------------------------------------------------------------------

/**
 * Describe the purpose of your panel here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog framework.
 * (consult base class description).
 */
class PrtFstFreeStyleShelterDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstFreeStyleShelterDlg, CATDlgDialog )

  public:

  PrtFstFreeStyleShelterDlg();
  virtual ~PrtFstFreeStyleShelterDlg();

  void Build ();


  //COMBO按钮选择的响应
  CATBoolean ComboItemSearchCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean MainFstComboItemCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //对每一个COMBO信息进行更新
  HRESULT SetSearchItemComboList(CATListValCATUnicodeString astrKeyWords,CATDlgCombo * piDlgCombo);
  //获取所有WBSItem信息
  void GetAllWBSItemInfo(CATLISTV(CATUnicodeString) &listStrSearchItems);


//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgLabel*      _Label006;
 CATDlgLabel*      _Label007;
 CATDlgLabel*      _Label008;
 CATDlgLabel*      _Label009;
 CATDlgLabel*      _Label010;
 CATDlgCombo*      _Combo01;
 CATDlgCombo*      _Combo02;
 CATDlgCombo*      _Combo03;
 CATDlgCombo*      _Combo04;
 CATDlgCombo*      _Combo05;
 CATDlgPushButton*      _GoToSearchPB;
 CATDlgFrame*      _Frame002;
 CATDlgMultiList*      _SearchResultML;
 CATDlgFrame*      _Frame003;
 CATDlgPushButton*      _LastStepPB;
 CATDlgPushButton*      _NextStepPB;
 CATDlgFrame*      _Frame011;
 CATDlgMultiList*      _ChooseSheltersML;
 CATDlgFrame*      _Frame014;
 CATDlgPushButton*      _RemoveAllPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION

 //
 //定义COMBO列表
 CATLISTP(IUnknown)  m_ItemComboList;

 //记录WEBSERVICE ITEMS
 CATListPV m_plsStrCurrentWBSItem;
 CATLISTV(CATUnicodeString) m_alsStrCurrentWBSItem;
 //记录combo初始化名称
 CATLISTV(CATUnicodeString) m_alsStrCurrentWBSShow;

 //属性头名称
 CATUnicodeString m_lstStrPropertyName[16];
 CATUnicodeString m_lstStrPropertyName02[16];

 //
 int m_IChoosedIndex;
 CATUnicodeString m_StrCurrentDataBaseName; 

 //
 CATUnicodeString m_StrNextStepDataBaseName;
 CATLISTV(CATUnicodeString) m_strNextStepWBSItem; 


//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
