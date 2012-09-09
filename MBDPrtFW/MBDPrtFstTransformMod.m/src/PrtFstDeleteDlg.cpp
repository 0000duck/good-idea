// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstDeleteDlg.cpp
// The dialog : PrtFstDeleteDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstDeleteDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstDeleteDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstDeleteDlg::PrtFstDeleteDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstDeleteDlg",CATDlgWndBtnOKCancel|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _Frame008 = NULL;
 _FSTLineSL = NULL;
 _Frame010 = NULL;
 _RemoveSelPB = NULL;
 _RemoveAllPB = NULL;
 _Frame002 = NULL;
 _Frame003 = NULL;
 _InstanceInfoML = NULL;
 _Frame004 = NULL;
 _ExternalInfoML = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION


//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION


//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION


//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstDeleteDlg::~PrtFstDeleteDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _Frame008 = NULL;
 _FSTLineSL = NULL;
 _Frame010 = NULL;
 _RemoveSelPB = NULL;
 _RemoveAllPB = NULL;
 _Frame002 = NULL;
 _Frame003 = NULL;
 _InstanceInfoML = NULL;
 _Frame004 = NULL;
 _ExternalInfoML = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstDeleteDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(0,1);
 SetGridRowResizable(1,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridRowResizable(0,1);
 _Frame001 -> SetGridColumnResizable(0,1);
 _Frame008 = new CATDlgFrame(_Frame001, "Frame008", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame008 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame008 -> SetGridRowResizable(0,1);
 _Frame008 -> SetGridColumnResizable(0,1);
 _FSTLineSL = new CATDlgSelectorList(_Frame008, "FSTLineSL");
 _FSTLineSL -> SetVisibleTextHeight(15);
 _FSTLineSL -> SetVisibleTextWidth(40);
_FSTLineSL -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame010 = new CATDlgFrame(_Frame008, "Frame010", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame010 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _RemoveSelPB = new CATDlgPushButton(_Frame010, "RemoveSelPB");
_RemoveSelPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _RemoveAllPB = new CATDlgPushButton(_Frame010, "RemoveAllPB");
_RemoveAllPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridRowResizable(0,1);
 _Frame002 -> SetGridColumnResizable(0,1);
 _Frame002 -> SetGridColumnResizable(1,1);
 _Frame003 = new CATDlgFrame(_Frame002, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridRowResizable(0,1);
 _Frame003 -> SetGridColumnResizable(0,1);
 _InstanceInfoML = new CATDlgMultiList(_Frame003, "InstanceInfoML");
 CATUnicodeString InstanceInfoMLTitles [ 2 ];
 InstanceInfoMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstDeleteDlg", "Frame002.Frame003.InstanceInfoML.ColumnTitle1");
 InstanceInfoMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstDeleteDlg", "Frame002.Frame003.InstanceInfoML.ColumnTitle2");
 _InstanceInfoML -> SetColumnTitles(2, InstanceInfoMLTitles);
 _InstanceInfoML -> SetVisibleColumnCount( 15 );
_InstanceInfoML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame004 = new CATDlgFrame(_Frame002, "Frame004", CATDlgGridLayout);
_Frame004 -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame004 -> SetGridRowResizable(0,1);
 _Frame004 -> SetGridColumnResizable(0,1);
 _ExternalInfoML = new CATDlgMultiList(_Frame004, "ExternalInfoML");
 CATUnicodeString ExternalInfoMLTitles [ 2 ];
 ExternalInfoMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstDeleteDlg", "Frame002.Frame004.ExternalInfoML.ColumnTitle1");
 ExternalInfoMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstDeleteDlg", "Frame002.Frame004.ExternalInfoML.ColumnTitle2");
 _ExternalInfoML -> SetColumnTitles(2, ExternalInfoMLTitles);
 _ExternalInfoML -> SetVisibleColumnCount( 15 );
_ExternalInfoML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//
_InstanceInfoML->SetColumnTextWidth(0,20);
_InstanceInfoML->SetColumnTextWidth(1,20);

_ExternalInfoML->SetColumnTextWidth(0,20);
_ExternalInfoML->SetColumnTextWidth(1,20);

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

