// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// MBDNoteModifyDlg.h
// The dialog : MBDNoteModifyDlg
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
//  Mar 2010  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDNoteModifyDlg_H
#define MBDNoteModifyDlg_H
//ktsoftware PubHeader
#include "ktPubHeaders.h"


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
class MBDNoteModifyDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDNoteModifyDlg, CATDlgDialog )

  public:

  MBDNoteModifyDlg();
  virtual ~MBDNoteModifyDlg();

  void Build ();

  CATDlgEditor* GetMBDNoteModifyNameEditor();
  CATDlgEditor* GetMBDNoteModifyValueEditor();



  private:


//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgEditor*      _MBDModifyNameEditor;
 CATDlgEditor*      _MBDModifyValueEditor;
//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
