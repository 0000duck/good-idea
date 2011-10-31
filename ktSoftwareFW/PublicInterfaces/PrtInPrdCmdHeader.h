// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtInPrdCmdHeader.h
// Header definition of PrtInPrdCmdHeader
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef PrtInPrdCmdHeader_H
#define PrtInPrdCmdHeader_H

#include "ktECmdHeader.h"
#include "CATCommandHeader.h"
#include "PrdService.h"

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href PrtInPrdCmdHeader constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new PrtInPrdCmdHeader;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktECmdHeader PrtInPrdCmdHeader: public CATCommandHeader
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
	 PrtInPrdCmdHeader (const CATString&  iHeaderID, const CATString&  iLoadName, const CATString&  iClassName,void*  iArgument);
     virtual ~PrtInPrdCmdHeader ();

	 CATCommandHeader * Clone();


  private:

  // Copy constructor and equal operator
  // -----------------------------------
  PrtInPrdCmdHeader (CATCommandHeader *iHeaderToCopy);

  void UIActivatedCmd(CATCallbackEvent iPublishedEvent,		
					void *iPublishingObject, 
					CATNotification *iPublishNotification,
					CATSubscriberData iUsefulData,
					CATCallback iCallbackId); 

  CATCallback   m_UIActivatedCallback;

};

//-----------------------------------------------------------------------

#endif
