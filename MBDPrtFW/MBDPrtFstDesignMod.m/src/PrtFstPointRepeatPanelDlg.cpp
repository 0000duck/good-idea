// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// PrtFstPointRepeatPanelDlg.cpp
// The dialog : PrtFstPointRepeatPanelDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2013  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstPointRepeatPanelDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstPointRepeatPanelDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstPointRepeatPanelDlg::PrtFstPointRepeatPanelDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstPointRepeatPanelDlg",CATDlgWndNoButton|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
							   ,m_IChoosedIndex(0)
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _InstancesSpinner = NULL;
 _PitchSpinner = NULL;
 _Label013 = NULL;
 _Label014 = NULL;
 _Label015 = NULL;
 _FstTypeCombo = NULL;
 _Frame002 = NULL;
 _Label011 = NULL;
 _Label012 = NULL;
 _SpaceToRefEndPointSpinner = NULL;
 _RefEndPointExtremityEditor = NULL;
 _ExtremityPB = NULL;
 _PreviewPB = NULL;
 _Frame017 = NULL;
 _CheckB = NULL;
 _BestFitCheckB = NULL;
 _BestFitEditor = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstPointRepeatPanelDlg::~PrtFstPointRepeatPanelDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _InstancesSpinner = NULL;
 _PitchSpinner = NULL;
 _Label013 = NULL;
 _Label014 = NULL;
 _Label015 = NULL;
 _FstTypeCombo = NULL;
 _Frame002 = NULL;
 _Label011 = NULL;
 _Label012 = NULL;
 _SpaceToRefEndPointSpinner = NULL;
 _RefEndPointExtremityEditor = NULL;
 _ExtremityPB = NULL;
 _PreviewPB = NULL;
 _Frame017 = NULL;
 _CheckB = NULL;
 _BestFitCheckB = NULL;
 _BestFitEditor = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstPointRepeatPanelDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridColumnResizable(1,1);
// _InstancesSpinner = new CATDlgSpinner(_Frame001, "InstancesSpinner", CATDlgSpnEntry);
// _InstancesSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
//_InstancesSpinner -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
// _PitchSpinner = new CATDlgSpinner(_Frame001, "PitchSpinner", CATDlgSpnEntry);
// _PitchSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
//_PitchSpinner -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
 _Label013 = new CATDlgLabel(_Frame001, "Label013");
_Label013 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Label014 = new CATDlgLabel(_Frame001, "Label014");
_Label014 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Label015 = new CATDlgLabel(_Frame001, "Label015");
_Label015 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _FstTypeCombo = new CATDlgCombo(_Frame001, "FstTypeCombo", CATDlgCmbDropDown);
_FstTypeCombo -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridColumnResizable(1,1);
 _Label011 = new CATDlgLabel(_Frame002, "Label011");
_Label011 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Label012 = new CATDlgLabel(_Frame002, "Label012");
_Label012 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
// _SpaceToRefEndPointSpinner = new CATDlgSpinner(_Frame002, "SpaceToRefEndPointSpinner", CATDlgSpnEntry);
// _SpaceToRefEndPointSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
//_SpaceToRefEndPointSpinner -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _RefEndPointExtremityEditor = new CATDlgEditor(_Frame002, "RefEndPointExtremityEditor", CATDlgEdtReadOnly);
_RefEndPointExtremityEditor -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _ExtremityPB = new CATDlgPushButton(_Frame002, "ExtremityPB");
_ExtremityPB -> SetGridConstraints(0, 2, 1, 1, CATGRID_4SIDES);
 _PreviewPB = new CATDlgPushButton(this, "PreviewPB");
_PreviewPB -> SetGridConstraints(3, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
 _Frame017 = new CATDlgFrame(this, "Frame017", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame017 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _CheckB = new CATDlgCheckButton(_Frame017, "CheckB");
_CheckB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _BestFitCheckB = new CATDlgCheckButton(_Frame017, "BestFitCheckB");
_BestFitCheckB -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _BestFitEditor = new CATDlgEditor(_Frame017, "BestFitEditor", CATDlgEdtReadOnly);
_BestFitEditor -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

_InstancesSpinner = new CATDlgSpinner(_Frame001, "InstancesSpinner", CATDlgSpnEntry|CATDlgSpnDouble);
_InstancesSpinner -> SetFormat("%d");
_InstancesSpinner -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
_PitchSpinner = new CATDlgSpinner(_Frame001, "PitchSpinner", CATDlgSpnEntry|CATDlgSpnDouble);
_PitchSpinner ->  SetFormat("%d");
_PitchSpinner -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
_SpaceToRefEndPointSpinner = new CATDlgSpinner(_Frame002, "SpaceToRefEndPointSpinner", CATDlgSpnEntry|CATDlgSpnDouble);
_SpaceToRefEndPointSpinner -> SetFormat("%d");
_SpaceToRefEndPointSpinner -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);

//
_FstTypeCombo->SetLine("安装点个数模式");
_FstTypeCombo->SetLine("安装点间距模式");
_FstTypeCombo->SetLine("个数&间距模式");

//设置参数
double Start,StartZero, End, StepMM,StepNum;
Start = 1.0;
StartZero = 0.0;
End = 1e+6;
StepMM = 0.001;
StepNum = 1;
//
_InstancesSpinner->SetMinMaxStep(Start, End, StepNum);
_PitchSpinner->SetMinMaxStep(Start*0.001, End, StepMM);
_PitchSpinner->SetUnit(CATDlgControl::Millimeter);
_SpaceToRefEndPointSpinner->SetMinMaxStep(StartZero, End, StepMM);
_SpaceToRefEndPointSpinner->SetUnit(CATDlgControl::Millimeter);

//初始化状态
_PitchSpinner->SetSensitivity(CATDlgDisable);
_CheckB->SetState(CATDlgCheck,0);
_PreviewPB->SetSensitivity(CATDlgDisable);
_ExtremityPB->SetSensitivity(CATDlgDisable);
_BestFitCheckB->SetVisibility(CATDlgHide);
_BestFitEditor->SetVisibility(CATDlgHide);

//CAA2 WIZARD CALLBACK DECLARATION SECTION


//对第一个COMBO设置单独的响应函数
AddAnalyseNotificationCB (_FstTypeCombo,_FstTypeCombo->GetComboSelectNotification(),
						  (CATCommandMethod)&PrtFstPointRepeatPanelDlg::FstTypeComboItemCB,NULL);

//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}


//-------------------------------------------------------------------------
// Callback on RadBModify of _InstancesRB
//-------------------------------------------------------------------------
CATBoolean PrtFstPointRepeatPanelDlg::FstTypeComboItemCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
  // Add your code here
	//获得第一个COMBO所选的内容
	int tempIndex;
	tempIndex = _FstTypeCombo->GetSelect();
	m_IChoosedIndex=tempIndex;
	//
	if (tempIndex == 0)
	{
		_PitchSpinner->SetSensitivity(CATDlgDisable);
		_InstancesSpinner->SetSensitivity(CATDlgEnable);
		//
		_CheckB->SetVisibility(CATDlgShow);
		_SpaceToRefEndPointSpinner->SetSensitivity(CATDlgEnable);
		//
		_BestFitCheckB->SetVisibility(CATDlgHide);
		_BestFitEditor->SetVisibility(CATDlgHide);
		//
		_ExtremityPB->SetSensitivity(CATDlgEnable);

	}
	else if (tempIndex == 1)
	{
		_PitchSpinner->SetSensitivity(CATDlgEnable);
		_InstancesSpinner->SetSensitivity(CATDlgDisable);
		//
		_CheckB->SetVisibility(CATDlgShow);
		_SpaceToRefEndPointSpinner->SetSensitivity(CATDlgEnable);
		//
		_BestFitCheckB->SetVisibility(CATDlgShow);
		_BestFitEditor->SetVisibility(CATDlgShow);
		_BestFitEditor->SetText("");
		//
		_ExtremityPB->SetSensitivity(CATDlgEnable);
	}
	else if (tempIndex == 2)
	{
		_PitchSpinner->SetSensitivity(CATDlgEnable);
		_InstancesSpinner->SetSensitivity(CATDlgEnable);
		//
		_CheckB->SetVisibility(CATDlgHide);
		_SpaceToRefEndPointSpinner->SetSensitivity(CATDlgDisable);
		//
		_BestFitCheckB->SetVisibility(CATDlgHide);
		_BestFitEditor->SetVisibility(CATDlgHide);
		_ExtremityPB->SetSensitivity(CATDlgDisable);
	}

	return TRUE;
}
