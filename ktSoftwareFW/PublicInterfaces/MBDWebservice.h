// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDWebservice.h
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
#ifndef MBDWebservice_H
#define MBDWebservice_H

#include "ktWebservice.h"
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href MBDWebservice constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new MBDWebservice;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktWebservice MBDWebservice: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     MBDWebservice ();
     virtual ~MBDWebservice ();

  // Copy constructor and equal operator
  // -----------------------------------
  MBDWebservice (MBDWebservice &);
  MBDWebservice& operator=(MBDWebservice&);


  //-----------------------------------------------------------------------
  //获取用户电脑信息
  static void GetUserComputerInfo(CATUnicodeString &strUserHostname,CATUnicodeString &strUserIpaddress);

  //通过Webservice Query
  static HRESULT QueryDataWebService(CATListValCATUnicodeString &strListOfSearchItems,CATListValCATUnicodeString &strListOfSearchResult);

  //通过Webservice Insert
  static HRESULT InsertDataWebService(CATListValCATUnicodeString astrKeyWords);

  //消息提示
  static void ShowDlgNotify(CATUnicodeString strTitle, CATUnicodeString strValue);

  //
  static HRESULT QueryByGSoap(CATListValCATUnicodeString &strListOfSearchItems,CATListValCATUnicodeString &strListOfSearchResult);


  //-----------------------------------------------------------------------

};

//-----------------------------------------------------------------------

#endif
