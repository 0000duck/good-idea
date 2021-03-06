// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstKnowledgeWasherDlg.h
// The dialog : PrtFstKnowledgeWasherDlg
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
#ifndef PrtFstKnowledgeWasherDlg_H
#define PrtFstKnowledgeWasherDlg_H

#include "CATDlgDialog.h"
#include "CATDlgInclude.h"

//----------------------------------------------------------------------

/**
 * Describe the purpose of your panel here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog framework.
 * (consult base class description).
 */
class PrtFstKnowledgeWasherDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstKnowledgeWasherDlg, CATDlgDialog )

  public:

  PrtFstKnowledgeWasherDlg();
  virtual ~PrtFstKnowledgeWasherDlg();

  void Build ();

//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgMultiList*      _SearchResultsML;
 CATDlgFrame*      _Frame006;
 CATDlgRadioButton*      _PosSTARTRB;
 CATDlgRadioButton*      _PosENDRB;
 CATDlgFrame*      _Frame002;
 CATDlgLabel*      _Label009;
 CATDlgLabel*      _Label010;
 CATDlgEditor*      _ThickLeftEditor;
 CATDlgEditor*      _EndLeftEditor;
 CATDlgFrame*      _Frame003;
 CATDlgMultiList*      _ChooseWashersML;
 CATDlgFrame*      _Frame014;
 CATDlgPushButton*      _RemovePB;
 CATDlgPushButton*      _ClearAllPB;
 CATDlgFrame*      _Frame004;
 CATDlgPushButton*      _LastStepPB;
 CATDlgPushButton*      _NextStepPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION


 //����ͷ����
 CATUnicodeString m_lstStrPropertyName[11];
 CATUnicodeString m_lstStrPropertyName02[14];



};

//----------------------------------------------------------------------

#endif
