// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CAATreeCtrl.cpp
// Header definition of CAATreeCtrl
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#include "CAATreeCtrl.h"

#include "CATNavigController.h"

#include "TreeNodeSelectNotif.h"

#include "TreeNodeCxtMenuNotif.h"

#include "CATITreeNodeContent.h"

#include "CATIGraphNode.h"

#include "CATInstantiateComponent.h"

#include "CATIRedrawEvent.h"

#include "CATDlgGridConstraints.h"

#include "CATDlgContextualMenu.h"

#include "CAATreeNodeEventAgent.h"

 
CATImplementClass( CAATreeCtrl,
                   Implementation, 
                   CATDlgContainer,
                   CATNull );
 
//-----------------------------------------------------------------------------
// CAATreeCtrl : constructor
//-----------------------------------------------------------------------------
CAATreeCtrl::CAATreeCtrl(CATDialog*  iParent,const CATString&  iObjectName, CATDlgStyle iStyle):
    CATDlgContainer(iParent, iObjectName, iStyle)
{
	_pRootTreeNodeObjList = new CATLISTP(CATBaseUnknown);


	 SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);


	DRECT oContRec;
	GetRectDimensions(&oContRec);

	_pNavigBox = new CATNavigBox(this, "CAATreeCtrl", NULL, Indented, "ObjNavDefault",oContRec.dx,oContRec.dy);


	CATDlgFrame* pDlgFrame = _pNavigBox -> GetBoxFrame();

	pDlgFrame -> SetRectDimensions(oContRec);



	_pTreeEventListener = new CAATreeNodeEventAgent(_pNavigBox);


	CATNavigController * pNavigController;
	pNavigController = _pNavigBox->GetController();
	pNavigController -> SetDepth(-1);



	AddAnalyseNotificationCB (this, 
                        GetResizeNotification(),
                        (CATCommandMethod)&CAATreeCtrl::OnTreeCtrlReSizeCB,
                        NULL);

	AddCallback(_pTreeEventListener,TreeNodeSelectNotif::ClassName(),(CATSubscriberMethod)&CAATreeCtrl::OnTreeNodeSelectCB, NULL);

	AddCallback(_pTreeEventListener,TreeNodeCxtMenuNotif::ClassName(),(CATSubscriberMethod)&CAATreeCtrl::OnTreeNodeCxtMenuCB, NULL);
}

//-----------------------------------------------------------------------------
// CAATreeCtrl : destructor
//-----------------------------------------------------------------------------
CAATreeCtrl::~CAATreeCtrl()
{

	delete _pTreeEventListener;
	_pTreeEventListener = NULL;
	



	while(_pRootTreeNodeObjList->Size() != 0)
	{
		CATBaseUnknown * pTreeNodeObject = (*_pRootTreeNodeObjList)[1];

		if (pTreeNodeObject != NULL)
		{
			_pRootTreeNodeObjList -> RemoveValue(pTreeNodeObject);

			pTreeNodeObject -> Release();

			pTreeNodeObject = NULL;
		}
	}



	_pNavigBox = NULL;

	delete _pRootTreeNodeObjList;
	_pRootTreeNodeObjList = NULL;
}
 
//-----------------------------------------------------------------------------
// CAATreeCtrl : copy constructor
//-----------------------------------------------------------------------------
CAATreeCtrl::CAATreeCtrl(CAATreeCtrl& original):
   CATDlgContainer(original)
{
}
 
//-----------------------------------------------------------------------------
// CAATreeCtrl : equal operator
//-----------------------------------------------------------------------------
CAATreeCtrl& CAATreeCtrl::operator=(CAATreeCtrl& original)
{
   CATDlgContainer::operator=(original);
   return *this;
}
 
void CAATreeCtrl::OnTreeCtrlReSizeCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	DRECT oContRec;
	GetRectDimensions(&oContRec);


	CATDlgFrame* pDlgFrame = _pNavigBox -> GetBoxFrame();

	pDlgFrame -> SetRectDimensions(oContRec);
}

void CAATreeCtrl::OnTreeNodeSelectCB(CATCallbackEvent event, void * client, CATNotification * iNotification,
						CATSubscriberData data, CATCallback callback)
{
	GetCallbackManager() -> DispatchCallbacks(iNotification,this);
}

void CAATreeCtrl::OnTreeNodeCxtMenuCB(CATCallbackEvent event, void * client, CATNotification * iNotification,
						CATSubscriberData data, CATCallback callback)
{
	GetCallbackManager() -> DispatchCallbacks(iNotification,this);
}

void CAATreeCtrl::GetSelectedTreeNode (CATBaseUnknown ** pSelectedTreeNode)
{
	if (pSelectedTreeNode == NULL)
	{
		return ;
	}

	_pTreeEventListener->GetCurrentSelectNode(pSelectedTreeNode);
}

void CAATreeCtrl::SelectTreeNode (CATBaseUnknown * pTreeNode)
{
	const CATNavigController * pNavigController = NULL;

	pNavigController = _pNavigBox->GetController();


	CATListValCATBaseUnknown_var * pNodeList = NULL ;
    pNodeList = pNavigController -> GetAssociatedElements(pTreeNode);

	if (pNodeList != NULL)
	{
		CATBaseUnknown_var spNode = (*pNodeList)[1];

		CATINavigElement_var spNavigElement = spNode ;

		spNavigElement ->ProcessAfterSelect();

		delete pNodeList ;
        pNodeList = NULL ;
	}
}

void CAATreeCtrl::GetTreeNodeData(CATBaseUnknown * pTreeNode, void **oContent)
{
	HRESULT rc;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> GetNodeContent(oContent);

		piTreeNodeContent -> Release();
		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::SetTreeNodeData(CATBaseUnknown * pTreeNode, void * iContent)
{
	HRESULT rc;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> SetNodeContent(iContent);

		piTreeNodeContent -> Release();
		piTreeNodeContent = NULL;
	}
}

CATDlgContextualMenu * CAATreeCtrl::GetTreeNodeContextualMenu(CATBaseUnknown * pTreeNode)
{
	HRESULT rc;

	CATDlgContextualMenu * pCxtMenu = NULL;

	CATNavigController * pNavigController = NULL;

	pNavigController = _pNavigBox -> GetController();


	CATListValCATBaseUnknown_var * pNodeList = NULL ;

	pNodeList = pNavigController -> GetAssociatedElements(pTreeNode);


	CATBaseUnknown_var spNode = (*pNodeList)[1];


	CATIGraphNode *piGraphNode = NULL;

	rc = spNode -> QueryInterface(IID_CATIGraphNode,(void**)&piGraphNode);

	pCxtMenu = piGraphNode->GetContextualMenu();

	piGraphNode -> Release();
	piGraphNode = NULL;


	delete pNodeList;
	pNodeList = NULL;


	pTreeNode -> Release();
	pTreeNode = NULL;


	return pCxtMenu;

	//HRESULT rc;

	//CATNavigController * pNavigController = NULL;

	//pNavigController = _pNavigBox -> GetController();


	//CATListValCATBaseUnknown_var * pNodeList = NULL ;

 //   pNodeList = pNavigController -> GetAssociatedElements(pTreeNode);


	//if (pNodeList == NULL)
	//{
	//	return NULL;
	//}


	//CATBaseUnknown_var spNode = (*pNodeList)[1];

	//CATIGraphNode *piGraphNode = NULL;

	//rc = spNode -> QueryInterface(IID_CATIGraphNode,(void**)&piGraphNode);

	//CATDlgContextualMenu * pDlgContextualMenu = piGraphNode -> GetContextualMenu();

	////piGraphNode -> Release();
	////piGraphNode = NULL;



	//CATDlgContextualMenu * pDlgContextualMenu = new CATDlgContextualMenu((CATDialog *)this,"CxtMenu", CATDlgCtxEmpty);
	////CATDlgContextualMenu * pDlgContextualMenu = GetContextualMenu();


	//return pDlgContextualMenu;
}

void CAATreeCtrl::GetTreeNodeText(CATBaseUnknown * pTreeNode, CATUnicodeString & oName)
{
	HRESULT rc;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> GetName(oName);

		piTreeNodeContent -> Release();
		piTreeNodeContent = NULL;
	}
}


void CAATreeCtrl::SetTreeNodeText(CATBaseUnknown * pTreeNode, const CATUnicodeString & iName)
{
	HRESULT rc;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> SetName(iName);


		CATIRedrawEvent * piRedrawEvent = NULL;                
		rc =pTreeNode->QueryInterface(IID_CATIRedrawEvent, (void**)&piRedrawEvent);
		if (SUCCEEDED(rc))
		{
			piRedrawEvent->Redraw();

			piRedrawEvent->Release();
			piRedrawEvent= NULL ;
		}


		piTreeNodeContent -> Release();
		piTreeNodeContent = NULL;



		//CATNavigController * pNavigController = NULL;

		//pNavigController = _pNavigBox -> GetController();


		//CATListValCATBaseUnknown_var * pNodeList = NULL ;

		//pNodeList = pNavigController -> GetAssociatedElements(pTreeNode);


		//if (pNodeList != NULL)
		//{
		//	CATBaseUnknown_var spNode = (*pNodeList)[1];

		//	CATINavigElement_var spNavigElement = spNode ;

		//	spNavigElement -> Update();


		//	delete pNodeList ;
		//	pNodeList = NULL ;
		//}
	}
}



void CAATreeCtrl::AddRootTreeNode(CATBaseUnknown * pTreeRootNode)
{
	if((pTreeRootNode == NULL) || (_pRootTreeNodeObjList == NULL))
		return;

	_pRootTreeNodeObjList -> Append(pTreeRootNode);

	pTreeRootNode -> AddRef();

	_pNavigBox -> AddRoot(pTreeRootNode);


	_pTreeEventListener -> AddTreeNodeObjToListen(pTreeRootNode);
}

void CAATreeCtrl::AddRootTreeNode(CATUnicodeString TreeNodeText, CATUnicodeString TreeNodeIcon)
{
	HRESULT rc;

	CATBaseUnknown * pTreeRootNode = NULL;

	::CATInstantiateComponent("CATTreeNodeObj",IID_CATBaseUnknown,(void**)&pTreeRootNode);

	if((pTreeRootNode == NULL) || (_pRootTreeNodeObjList == NULL))
		return;


	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeRootNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	piTreeNodeContent -> SetName(TreeNodeText);

	piTreeNodeContent -> SetIconName(TreeNodeIcon);

	piTreeNodeContent -> Release();

	piTreeNodeContent = NULL;


	_pRootTreeNodeObjList -> Append(pTreeRootNode);

	//////pTreeRootNode -> AddRef();

	_pNavigBox -> AddRoot(pTreeRootNode);


	_pTreeEventListener -> AddTreeNodeObjToListen(pTreeRootNode);
}

void CAATreeCtrl::AddChildTreeNode(CATBaseUnknown * pFatherTreeNode, CATBaseUnknown * pChildTreeNodeToAdd)
{
	HRESULT rc;

	if((pFatherTreeNode == NULL) || (pChildTreeNodeToAdd == NULL))
		return;


	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pFatherTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> AddSubTreeNodeObj(pChildTreeNodeToAdd);

		_pTreeEventListener -> AddTreeNodeObjToListen(pChildTreeNodeToAdd);



		CATIRedrawEvent * piRedrawEvent = NULL;                
		rc =pFatherTreeNode->QueryInterface(IID_CATIRedrawEvent, (void**)&piRedrawEvent);
		if (SUCCEEDED(rc))
		{
			piRedrawEvent->Redraw();

			piRedrawEvent->Release();
			piRedrawEvent= NULL ;
		}


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::AddChildTreeNode(CATBaseUnknown * pFatherTreeNode, CATUnicodeString TextOfChildTreeNodeToAdd, CATUnicodeString TreeNodeIcon)
{
	HRESULT rc;

	CATBaseUnknown * pChildTreeNode = NULL;

	::CATInstantiateComponent("CATTreeNodeObj",IID_CATBaseUnknown,(void**)&pChildTreeNode);

	if((pFatherTreeNode == NULL) || (pChildTreeNode == NULL))
		return;


	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pChildTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		piTreeNodeContent -> SetName(TextOfChildTreeNodeToAdd);

		piTreeNodeContent -> SetIconName(TreeNodeIcon);

		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;

	}



	rc = pFatherTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> AddSubTreeNodeObj(pChildTreeNode);

		_pTreeEventListener -> AddTreeNodeObjToListen(pChildTreeNode);



		CATIRedrawEvent * piRedrawEvent = NULL;                
		rc =pFatherTreeNode->QueryInterface(IID_CATIRedrawEvent, (void**)&piRedrawEvent);
		if (SUCCEEDED(rc))
		{
			piRedrawEvent->Redraw();

			piRedrawEvent->Release();
			piRedrawEvent= NULL ;
		}




		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::RemoveTreeNode(CATBaseUnknown * pTreeNode)
{
	HRESULT rc;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		//移除此树节点上的消息监视
		_pTreeEventListener -> RemoveTreeNodeObjToListen(pTreeNode);


		CATBaseUnknown * pFatherNode = NULL;

		rc = piTreeNodeContent -> GetFatherNode(&pFatherNode);

		if (pFatherNode != NULL)         //移除树节点不为树的根节点时
		{
			CATITreeNodeContent * piFatherTreeNodeContent = NULL;

			rc = pFatherNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piFatherTreeNodeContent);

			if (SUCCEEDED(rc) && piFatherTreeNodeContent!=NULL)
			{
				rc = piFatherTreeNodeContent -> RemoveSubTreeNodeObj(pTreeNode);


				piFatherTreeNodeContent -> Release();

				piFatherTreeNodeContent = NULL;
			}



			CATIRedrawEvent * piRedrawEvent = NULL;                
			rc =pFatherNode->QueryInterface(IID_CATIRedrawEvent, (void**)&piRedrawEvent);
			if (SUCCEEDED(rc))
			{
				piRedrawEvent->Redraw();

				piRedrawEvent->Release();
				piRedrawEvent= NULL ;
			}



			pFatherNode -> Release();

			pFatherNode = NULL;
		}
		else                            //移除树节点为树的根节点时
		{
			_pNavigBox -> RemoveRoot(pTreeNode);

			_pRootTreeNodeObjList -> RemoveValue(pTreeNode);

			pTreeNode -> Release();

			pTreeNode = NULL;
		}



		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}


void CAATreeCtrl::RemoveAllTreeNode()
{
	for(int i = 1;i<=_pRootTreeNodeObjList->Size();i++)	
	{
		CATBaseUnknown * pTreeNode = (*_pRootTreeNodeObjList)[i];

		RemoveTreeNode(pTreeNode);
	}

	_pRootTreeNodeObjList -> RemoveAll();
}

void CAATreeCtrl::GetRootTreeNodeAt(int iTreeNodeIndex, CATBaseUnknown **  opTreeNodeObject)
{
	if ((opTreeNodeObject == NULL) || (_pRootTreeNodeObjList == NULL))
		return;

	if((iTreeNodeIndex < 1) || (iTreeNodeIndex > _pRootTreeNodeObjList->Size()))
	{
		* opTreeNodeObject = NULL;
		return;
	}
	else
	{
		*opTreeNodeObject = (*_pRootTreeNodeObjList)[iTreeNodeIndex];

		if (*opTreeNodeObject != NULL)
		{
			(*opTreeNodeObject) -> AddRef();
		}
	}
}

//得到在根节点级上某节点的序号
void CAATreeCtrl::GetCertainRootTreeNodeLocate(int &oTreeNodeRank, CATBaseUnknown *ipTreeNodeObject)
{
	oTreeNodeRank = -1;

	if ((ipTreeNodeObject == NULL) || (_pRootTreeNodeObjList == NULL))
	{
		oTreeNodeRank = -1;
		return;
	}

	oTreeNodeRank = (*_pRootTreeNodeObjList).Locate(ipTreeNodeObject);
}

void CAATreeCtrl::GetChildTreeNodeAt(CATBaseUnknown * pFatherTreeNode, int iTreeNodeRank, CATBaseUnknown **  opTreeNodeObject)
{
	HRESULT rc;

	if((pFatherTreeNode == NULL) || (opTreeNodeObject == NULL))
		return;	


	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pFatherTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		int Count = 0;
		piTreeNodeContent -> GetNumberOfSubTreeNodeObj(&Count);


		if ((iTreeNodeRank < 1) || (iTreeNodeRank >Count))
		{
			*opTreeNodeObject = NULL;
		}
		else
		{
			piTreeNodeContent -> GetSubTreeNodeObj(iTreeNodeRank, opTreeNodeObject);
		}


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

//得到在pFatherTreeNode级下某节点的序号
void CAATreeCtrl::GetCertainChildTreeNodeLocate(CATBaseUnknown * pFatherTreeNode, int &oTreeNodeRank, CATBaseUnknown * ipTreeNodeObject)
{
	HRESULT rc;
	oTreeNodeRank = -1;

	if((pFatherTreeNode == NULL) || (ipTreeNodeObject == NULL))
	{
		oTreeNodeRank = -1;
		return;	
	}

	CATITreeNodeContent * piTreeNodeContent = NULL;
	rc = pFatherTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		piTreeNodeContent -> Locate(ipTreeNodeObject,&oTreeNodeRank);

		piTreeNodeContent -> Release();
		piTreeNodeContent = NULL;
	}

}


void CAATreeCtrl::GetFatherTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown ** opFatherTreeNode)
{
	HRESULT rc;

	if((pTreeNode == NULL) || (opFatherTreeNode == NULL))
		return;	

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		piTreeNodeContent -> GetFatherNode(opFatherTreeNode);


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::GetNextSiblingTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown **opSiblingTreeNode)
{
	HRESULT rc;

	if((pTreeNode == NULL) || (opSiblingTreeNode == NULL))
		return;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		CATBaseUnknown * pFatherNode = NULL;

		rc = piTreeNodeContent -> GetFatherNode(&pFatherNode);

		if (pFatherNode != NULL)         //树节点不为树的根节点时
		{
			CATITreeNodeContent * piFatherTreeNodeContent = NULL;

			rc = pFatherNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piFatherTreeNodeContent);


			if (SUCCEEDED(rc) && piFatherTreeNodeContent!=NULL)
			{
				int RankTemp = 0;
				rc = piFatherTreeNodeContent -> Locate(pTreeNode, &RankTemp);

				RankTemp++;

				rc = piFatherTreeNodeContent -> GetSubTreeNodeObj(RankTemp, opSiblingTreeNode);


				piFatherTreeNodeContent -> Release();

				piFatherTreeNodeContent = NULL;
			}

			pFatherNode -> Release();

			pFatherNode = NULL;
		}
		else                            //树节点为树的根节点时
		{
			int Rank = 0;
			Rank = _pRootTreeNodeObjList -> Locate(pTreeNode);

			Rank++;

			if((Rank < 1) || (Rank >_pRootTreeNodeObjList->Size()))
			{
				*opSiblingTreeNode = NULL;
			}
			else
			{
				*opSiblingTreeNode = (*_pRootTreeNodeObjList)[Rank];

				(*opSiblingTreeNode) -> AddRef();
			}
		}


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::GetPrevSiblingTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown **opSiblingTreeNode)
{
	HRESULT rc;

	if((pTreeNode == NULL) || (opSiblingTreeNode == NULL))
		return;

	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		CATBaseUnknown * pFatherNode = NULL;

		rc = piTreeNodeContent -> GetFatherNode(&pFatherNode);

		if (pFatherNode != NULL)         //树节点不为树的根节点时
		{
			CATITreeNodeContent * piFatherTreeNodeContent = NULL;

			rc = pFatherNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piFatherTreeNodeContent);


			if (SUCCEEDED(rc) && piFatherTreeNodeContent!=NULL)
			{
				int RankTemp = 0;
				rc = piFatherTreeNodeContent -> Locate(pTreeNode, &RankTemp);

				RankTemp--;

				rc = piFatherTreeNodeContent -> GetSubTreeNodeObj(RankTemp, opSiblingTreeNode);


				piFatherTreeNodeContent -> Release();

				piFatherTreeNodeContent = NULL;
			}


			pFatherNode -> Release();

			pFatherNode = NULL;
		}
		else                            //树节点为树的根节点时
		{
			int Rank = 0;
			Rank = _pRootTreeNodeObjList -> Locate(pTreeNode);

			Rank--;

			if((Rank < 1) || (Rank >_pRootTreeNodeObjList->Size()))
			{
				*opSiblingTreeNode = NULL;
			}
			else
			{
				*opSiblingTreeNode = (*_pRootTreeNodeObjList)[Rank];

				(*opSiblingTreeNode) -> AddRef();
			}
		}


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}

void CAATreeCtrl::GetChildTreeNodeCount(CATBaseUnknown * pTreeNode, int * oCount)
{
	HRESULT rc;

	if((pTreeNode == NULL) || (oCount == NULL))
		return;	


	CATITreeNodeContent * piTreeNodeContent = NULL;

	rc = pTreeNode -> QueryInterface(IID_CATITreeNodeContent,(void**)&piTreeNodeContent);

	if (SUCCEEDED(rc) && piTreeNodeContent!=NULL)
	{
		rc = piTreeNodeContent -> GetNumberOfSubTreeNodeObj(oCount);


		piTreeNodeContent -> Release();

		piTreeNodeContent = NULL;
	}
}


void CAATreeCtrl::GetRootTreeNodeCount(int * oCount)
{
	* oCount = _pRootTreeNodeObjList -> Size();
}


void CAATreeCtrl::ExpandTreeNode (CATBaseUnknown * pTreeNode)
{
	const CATNavigController * pNavigController = NULL;

	pNavigController = _pNavigBox->GetController();


	CATListValCATBaseUnknown_var * pNodeList = NULL ;
    pNodeList = pNavigController -> GetAssociatedElements(pTreeNode);

	if (pNodeList != NULL)
	{
		CATBaseUnknown_var spNode = (*pNodeList)[1];

		CATINavigElement_var spNavigElement = spNode ;

		spNavigElement ->ProcessAfterExpand();

		delete pNodeList ;
        pNodeList = NULL ;
	}	
}