// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignDlg.h
// The dialog : PrtFstDesignDlg
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
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstDesignDlg_H
#define PrtFstDesignDlg_H

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
class PrtFstDesignDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstDesignDlg, CATDlgDialog )

  public:

  PrtFstDesignDlg();
  virtual ~PrtFstDesignDlg();

  void Build ();


  protected:

  private:


//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgSelectorList*      _PointsSL;
 CATDlgFrame*      _Frame002;
 CATDlgLabel*      _Label008;
 CATDlgLabel*      _Label009;
 CATDlgSelectorList*      _FirstSurfSL;
 CATDlgSelectorList*      _SecondSurfSL;
 CATDlgPushButton*      _DirectionPB;
 CATDlgLabel*      _Label014;
 CATDlgFrame*      _Frame003;
 CATDlgPushButton*      _ChooseFstPB;
 CATDlgFrame*      _Frame004;
 CATDlgEditor*      _SpecInfoEditor;
 CATDlgPushButton*      _ShowDetailInfoPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
