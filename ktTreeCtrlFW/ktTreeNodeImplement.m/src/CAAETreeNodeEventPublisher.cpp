// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CAAETreeNodeEventPublisher.cpp
// Provide implementation to interface
//    CATITreeNodeEventPublisher
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#include "CAAETreeNodeEventPublisher.h"

#include "TreeNodeSelectNotif.h"

#include "TreeNodeCxtMenuNotif.h"

#include "CATCallbackManager.h"
 
CATImplementClass(CAAETreeNodeEventPublisher,
                  DataExtension,
                  CATEventSubscriber,
                  CATTreeNodeObj );
 

//-----------------------------------------------------------------------------
// CAAETreeNodeEventPublisher : constructor
//-----------------------------------------------------------------------------
CAAETreeNodeEventPublisher::CAAETreeNodeEventPublisher():
    CATEventSubscriber()
{
}

//-----------------------------------------------------------------------------
// CAAETreeNodeEventPublisher : destructor
//-----------------------------------------------------------------------------
CAAETreeNodeEventPublisher::~CAAETreeNodeEventPublisher()
{
}
 
// Link the implementation to its interface
// ---------------------------------------



//TIE or TIEchain definitions
#include "TIE_CATITreeNodeEventPublisher.h"
TIE_CATITreeNodeEventPublisher( CAAETreeNodeEventPublisher);


//Methods implementation

//-----------------------------------------------------------------------------
// Implements CATITreeNodeEventPublisher::PublishTreeNodeSelectEvent
//-----------------------------------------------------------------------------
HRESULT CAAETreeNodeEventPublisher::PublishTreeNodeSelectEvent ()
{
	TreeNodeSelectNotif * pTreeNodeSelectNotif = new TreeNodeSelectNotif();

	GetCallbackManager() -> DispatchCallbacks(pTreeNodeSelectNotif,this);

	delete pTreeNodeSelectNotif;

	return S_OK;
}

//-----------------------------------------------------------------------------
// Implements CATITreeNodeEventPublisher::PublishTreeNodeCxtMenuEvent
//-----------------------------------------------------------------------------
HRESULT CAAETreeNodeEventPublisher::PublishTreeNodeCxtMenuEvent ()
{
	TreeNodeCxtMenuNotif * pTreeNodeCxtMenuNotif = new TreeNodeCxtMenuNotif();

	pTreeNodeCxtMenuNotif -> SetRequestCxtMenuTreeNode(this);

	GetCallbackManager() -> DispatchCallbacks(pTreeNodeCxtMenuNotif,this);

	delete pTreeNodeCxtMenuNotif;

	return S_OK;
}

