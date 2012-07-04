// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtService.h
// Header definition of PrtService
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef PrtService_H
#define PrtService_H

#include "ktPrtService.h"
#include "CATBaseUnknown.h"
#include "ktPubHeaders.h"
#include "CATListOfCATPathElement.h"
#include "CATMathDirectionf.h"
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATNavigController.h"



//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href PrtService constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new PrtService;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktPrtService PrtService: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     PrtService ();
     virtual ~PrtService ();

  // Copy constructor and equal operator
  // -----------------------------------
  PrtService (PrtService &);
  PrtService& operator=(PrtService&);


//**********************************************************************************************************************************************************************************************************************************************************
//环境变量操作
//**********************************************************************************************************************************************************************************************************************************************************
  
  //获取CATIA环境文件中的某个参数值
  //参数说明：iKey 变量名；oValue变量值
  static
  HRESULT GetEnvValue(const CATUnicodeString& iKey, CATUnicodeString& oValue);


//**********************************************************************************************************************************************************************************************************************************************************
//几何图形集操作分类
//**********************************************************************************************************************************************************************************************************************************************************

  //创造及获取几何图形集，
  static HRESULT CreateGSMTool(CATDocument* piDocument,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);
  static HRESULT ObtainGSMTool(CATDocument* piDocument,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //获取或者创建GSMTool
  static HRESULT CreateOrRetrieveGS(CATISpecObject_var iParentGS,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //查询几何图形集
  //参数说明：
  static 
  void CAAGsiSearchFeatureFromName(CATDocument * ipDoc, CATListValCATUnicodeString  &ListStrSearchedFeatName,CATListValCATISpecObject_var &ListValOfspSearchGSMTool);

  //创建几何图形集
  // -------------------------------------------------------------
  // iTopLevel = 1 / UNDER Part 
  // iTopLevel = 0 / UNDER Current feature  if spParentForTool not specify 
  // iTopLevel = 0 / UNDER  spParentForTool if spParentForTool  is specify
  // iDiag = 0 or -1  OK 
  // iDiag = 1  A GS  can only be inserted under another GS or directly under the part
  // iDiag = 2  A Body or an OGS can only be inserted under another Body or OGS  or directly under the part
  // iDiag = 3  Input Parent for tool is not a GS, OGS or Body
  // -------------------------------------------------------------
  static 
  HRESULT CAAGsiCreateGeometricFeatureSets (const CATIContainer_var &ispCont, const CATUnicodeString& iName,  const CATISpecObject_var & spInputParentTool ,CATISpecObject_var  & spSpecTool,  int & oDiag, int iTopLevel=1, int iType=0);

  //按照名称以某个父节点开始从CATIA结构树上检索几何图形集，仅限指定节点下一层
  static
  HRESULT SearchGSMToolByName(CATISpecObject_var spGSMToolRoot,CATUnicodeString strSearchName,CATISpecObject_var &spFoundResult);

  //按照名称以某个父节点开始从CATIA结构树上检索所有几何图形集，仅限指定节点下一层
  static
  HRESULT SearchALLSonFromRootGSMTool(CATISpecObject_var spGSMToolRoot,CATListValCATISpecObject_var &iolstspFoundResult,CATUnicodeString strSpecType = "CATIGSMTool");

  //VBA方式 向单个几何图形集设置参数
  static 
  void AddMBDGSMToolParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,CATISpecObject_var spSearchedGSMTool);

  //VBA方式 修改几何集下某些参数，如果参数不存在自动添加
  static
  void ModifyGSMToolsCertainParameters(CATDocument * piDoc,CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  //导出零件模型GSMTools中包含的所有参数，应用于 CATIA向LCA发送时！
  static 
  void ExportMBDGSMToolsParameters(CATListValCATISpecObject_var const &ListOfspGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // 查询得到某几何图形集下面所有参数
  static 
  void GetGSMToolsParameters(CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // 查询得到某几何图形集下面某些参数
  static 
  void GetGSMToolCertainParams(CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  // 设置某个几何图形集下面的某些个参数项的值
  static
  void SetGSMToolsCertainParams(CATDocument * piDoc,CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  //VBA方式 向所有MBD几何图形集设置参数，应用在LCA向CATIA发送数据时调用
  static 
  void ExportMBDPartParamToGSMTool(CATDocument * ipDoc,CATListValCATISpecObject_var const &ListOfspMBDGSMTools);

  //VBA方式 向单个几何图形集设置参数,作用包括清空以前的数据，并加入新的数据 
  static 
  void ModifyMBDParamToGSMTool(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,CATISpecObject_var spGSMTool);







//**********************************************************************************************************************************************************************************************************************************************************
//CATPart文件操作
//**********************************************************************************************************************************************************************************************************************************************************

  // 获得当前part文件的prtContainer
  static
  CATDocument * GetPrtDocument();

  //根据传入的Spec IID从文档DOC中获取所有Spec
  static void GetContentSpecsByNameFromDoc(CATDocument *piDoc, CATUnicodeString strSpecIID, CATListValCATISpecObject_var &iolistSpecs);

  //根据传入的Spec IID从文档Father GSMTool中获取所有Spec
  static void GetContentSpecsByNameFromGSMTool(CATISpecObject_var spFatherGSMTool,CATUnicodeString strSpecIID, CATListValCATISpecObject_var &iolistSpecs);

  //按照特征以及特征名称从容器中获取 某特征指针
  static CATBoolean ObtainChild(CATIPrtContainer* iPrtContainer,CATUnicodeString iType,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //设置颜色及透明度
  static HRESULT SetSpecObjColor(CATISpecObject_var iSpecObj,int iColor);
  static HRESULT SetSpecObjColor(CATISpecObject_var iSpecObj,int iColor,int iWidthOrSymbol, int iType);
  static HRESULT SetSpecObjOpacityAttr(CATISpecObject_var iSpecObj,CATUnicodeString iOpacityOrNoOpacity);

  //从文档指针获得PrdNumber
  static void GetPrdNumberFormDoc(CATDocument * ipiDocument,CATUnicodeString &iostrPrdNumber);




//**********************************************************************************************************************************************************************************************************************************************************
//特征操作
//**********************************************************************************************************************************************************************************************************************************************************

  //获取，设置特征ALIAS
  static CATUnicodeString GetAlias(IUnknown* iObj);
  static HRESULT SetAlias(IUnknown* iObj,CATUnicodeString iName);

  //插入特征到几何图形集
  static 
  HRESULT CAAGsiInsertInProceduralView(const CATISpecObject_var  ispObjectToAppend, CATISpecObject_var  ispInputParent);

  //几何图形集中特征更新
  static 
  HRESULT ObjectUpdate(const CATISpecObject_var & ispSpec);

  //刷新结构树上的特征
  static 
  HRESULT RedrawSpecNode(CATISpecObject_var spiObjNode);

  //设置特征属性，颜色，显示状态等
  static
  HRESULT SetSpecGraphProperty(CATISpecObject_var spSpecOnObject,CATVisPropertiesValues Attribut,CATVisPropertyType VisPropertyType, CATVisGeomType VisGeomType);

  //获得NavigController
  static
  HRESULT GetNavigController(CATNavigController *& pNavigController);

  //Expand/Collapse Specification Tree Nodes
  static
  void ExpandCollapseNode(CATBaseUnknown_var iObject);

  static
  void ExpandAllNode(CATBaseUnknown_var iObject);

  static
  void CollapseAllNode(CATBaseUnknown_var iObject);

  // -------------------------------------------------------------
  // Manage Litteral 
  // -------------------------------------------------------------
  //
  //Instanciate Litteral
  // --------------------------------
  // NomLitteral = 
  // "Length"
  // "Angle"
  // "Integer" 
  // "Real"
  // "Booleen" 
  static 
  CATICkeParm_var CAAGsiInstanciateLitteral (CATUnicodeString  NomLitteral,CATUnicodeString Name);

  //创建参数
  static 
  CATICkeParm_var LocalInstLitteral (void * Value, int IsValuate, CATUnicodeString NomLitteral,CATUnicodeString Name);

  //设置特征为隐藏或显示
  static
  HRESULT SetSpecObjShowAttr(CATISpecObject_var iSpecObj,CATUnicodeString iShowOrHide);

  //设置特征列表为隐藏或显示
  static
  HRESULT SetListSpecObjShowAttr(CATListValCATISpecObject_var &iListSpecObj,CATUnicodeString iShowOrHide);

  //获取特征为隐藏或显示
  static
  HRESULT GetSpecObjShowAttr(CATISpecObject_var iSpecObj,CATBoolean &iShowOrHide);

  //添加int 属性
  static BOOL SetSepcObjectAttrEx(const int iValue, const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //获取int 属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,int &iValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //获得long属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,long &lValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //添加double属性
  static BOOL SetSepcObjectAttrEx(const double dbValue,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);
  //获取double属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,double &dbValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //添加CATUnicodeString属性
  static BOOL SetSepcObjectAttrEx(const CATUnicodeString strValue,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //获取CATUnicodeString属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATUnicodeString &strValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //添加CATLISTV(CATUnicodeString)属性
  static BOOL SetSepcObjectAttrEx(CATLISTV(CATUnicodeString) lstStrings,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);
  
  //获取CATLISTV(CATUnicodeString)属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATLISTV(CATUnicodeString) &lstStrings,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //添加doubl list属性
  static BOOL SetSepcObjectAttrEx( CATRawColldouble doubleList,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //获取double list属性
  static BOOL GetSepcObjectAttrEx( BOOL &bIsExistKey,CATRawColldouble *&doubleList,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //添加CATISpecObject_var属性
  static BOOL SetSepcObjectAttrEx(CATISpecObject_var spObject,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //获取CATISpecObject_var属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATISpecObject_var &spObject,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //添加 CATLISTV(CATISpecObject_var)属性
  static BOOL SetSepcObjectAttrEx(CATLISTV(CATISpecObject_var) lstSpecObjects,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //获取CATLISTV(CATISpecObject_var)属性
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATLISTV(CATISpecObject_var) &lstSpecObjects,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //清除所有扩展属性
  static BOOL ClearSpecObjectAttEx(const CATISpecObject_var spSpecObject);

  //清除特定key的扩展属性
  static BOOL ClearSpecObjectAttEx(const CATISpecObject_var spSpecObject,CATListValCATUnicodeString lstStrKeys);

  //是否存在特定扩展属性
  static BOOL IsExistSpecObjectAttEx(const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //功能：特征拷贝
  static BOOL CopyFeatureToPartDocument(CATISpecObject_var &spSpecCopyResult, const CATISpecObject_var spObjectToCopy, const CATISpecObject_var spTarget,CATIProduct *piSourceInst,CATIProduct *piTargetInst, CATBoolean LinkMode,int iAttributeMode=3);







//**********************************************************************************************************************************************************************************************************************************************************
//PART文件自定义属性操作分类
//**********************************************************************************************************************************************************************************************************************************************************
  
  //功能：向part文件设置添加属性，先清空，后赋值
  static
  void AddMBDPartUserParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType=1,CATBoolean clearOrKeep = TRUE,CATBoolean readOrWrite =TRUE);

  //功能：向part文件设置更改属性
  static
  void ModifyMBDPartUserParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue);

  //功能：获得文档User Property里面所有参数信息
  static
  void GetMBDPartUserParams(CATDocument * ipDoc,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // 功能：获得文档User Property里面某些参数信息
  static
  void GetMBDPartUserCertainParams(CATDocument * ipDoc,CATListValCATUnicodeString  iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  // 功能：获得Instance PRD 用户自定义参数
  static 
  bool GetPrdUserCertainParams(CATIProduct_var spPrd,CATListValCATUnicodeString  iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  //功能：修改Instance PRD 中的某些用户自定义参数
  static 
  bool ModifyPrdUserCertainParams(CATIProduct_var spPrd,CATListValCATUnicodeString  iListStrName,CATListValCATUnicodeString  iListStrNameValue);

  //在用户自定义属性中添加枚举类型参数
  static 
  void SetUserPropertyParamEnum(CATDocument *piDocument,CATListValCATUnicodeString listStrParamName,CATListOfInt countNode,CATListValCATUnicodeString listStrParamValue);

  //设置几何集参数与用户自定义属性之间的关联关系
  static 
  void SetGSMToolUserPropertyRelations(CATDocument *piDocument,CATListValCATISpecObject_var listOfspGSMTools);

  //创建Datum特征
  static HRESULT ConvertToDatum(CATIGSMFactory_var  & ispGsmFact , const CATISpecObject_var & ispSpec,CATISpecObject_var iSpecParent,CATListValCATISpecObject_var& oAllDatums);







//**********************************************************************************************************************************************************************************************************************************************************
//高亮显示操作分类
//**********************************************************************************************************************************************************************************************************************************************************
  //添加高亮显示函数
  static
  void HighlightHSO(CATISpecObject_var spHSOSpec);

  //去除高亮显示元素
  static
  void RemoveHSO(CATISpecObject_var spHSOSpec);

  //清空高亮集
  static 
  BOOL ClearHSO();

  //高亮显示一组几何对象
  static 
  BOOL HighLightObjLst(CATLISTV(CATISpecObject_var) pObjLst);


//**********************************************************************************************************************************************************************************************************************************************************
//特征所含参数操作分类
//**********************************************************************************************************************************************************************************************************************************************************

  // 功能：向单个特征设置参数
  static 
  void AddSpecObjParams(CATDocument * ipDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType = 0);

  // 功能：修改特征下某些参数，如果参数不存在将自动添加
  static
  void ModifySpecObjCertainParams(CATDocument * piDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // 功能：修改特征下某些参数状态
  static
  void ModifySpecObjCertainParamsStatus(CATDocument * piDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName);

  // 功能：向单个特征设置参数：清空以前的数据，并加入新的数据，含类型选择条件
  static 
  void ClearAndAddSpecObjParams(CATDocument * ipDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType = 0);

  // 查询得到某特征下面所有参数，含类型选择条件
  static 
  void GetSpecObjAllParams(CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // 查询得到某特征下面某些参数，含类型选择条件
  static 
  void GetSpecObjCertainParams(CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  //在几何图形集中设置枚举类型，同样适用于在特征下创建
  static 
  void SetGSMToolParamEnum(CATDocument *piDocument,CATISpecObject_var spGSMTool,CATListValCATUnicodeString listStrParamName,CATListOfInt countNode,CATListValCATUnicodeString listStrParamValue);

  //从特征获取其中包含的所有Paramset
  static
  void GetParmSetFromSpeObjt(CATISpecObject_var ispObjt, CATListValCATISpecObject_var &iolstspParmSet);

  //从特征获取其中包含的特定名称的Paramset
  static
  void GetParmSetFromSpeObjt(CATISpecObject_var ispObjt, CATISpecObject_var &iospParmSet, CATUnicodeString istrParmName,int iType=0);

  //在特征身上创建Paramset
  static
  void CreateParmSetOnSpeObjt(CATDocument *piDoc,CATISpecObject_var &iospObjt, CATUnicodeString istrParmSetName, CATISpecObject_var &iospParamSet);

//**********************************************************************************************************************************************************************************************************************************************************
//各容器操作分类
//**********************************************************************************************************************************************************************************************************************************************************

  //从文档获取CATICkeParmFactory
  static HRESULT GetParamFactory(CATDocument *piDocument,CATICkeParmFactory_var &iospParmFact);

  //从文档获取CATIGSMFactory
  static HRESULT GetGSMFactory(CATDocument *piDocument,CATIGSMFactory_var &iospGSMFact);

  //获取当前Part文档Root Container
  static HRESULT ObtainCurrentRootContainer(CATIPrtContainer *&oRootContainer);

  //获取某Part文档Root Container
  static HRESULT ObtainRootContainer(CATDocument* iDoc,CATIPrtContainer *&oRootContainer);


//**********************************************************************************************************************************************************************************************************************************************************
//窗口操作分类
//**********************************************************************************************************************************************************************************************************************************************************

  //获取当前窗口最大值
  static void GetWindowMaxSize(int*  oHeight,int*  oWidth );

  //消息提示，交互模式可用
  static void ShowDlgNotify(CATUnicodeString strTitle, CATUnicodeString strValue);

  //错误消息框
  static void ktErrorMsgBox(const char* pMsg);
  static void ktErrorMsgBox(const int iNum);
  static void ktErrorMsgBox(const double dValue);

  //警告信息
  static void ktWarningMsgBox(const char* pMsg);
  static void ktWarningMsgBox(const int iNum);
  static void ktWarningMsgBox(const double dValue);

  //提示信息
  static void ktInfoMsgBox(const char* pMsg);
  static void ktInfoMsgBox(const int iNum);
  static void ktInfoMsgBox(const double dValue);


//**********************************************************************************************************************************************************************************************************************************************************
//PATHELEMENT操作分类
//**********************************************************************************************************************************************************************************************************************************************************

  //获取对象路径的字符串
  static void PathElementString(CATPathElement * ipPath,CATUnicodeString & oPathName,BOOL bIsBackward);

  //获取特征的CATPathElement
  static CATPathElement* ExtractPathElement(CATBaseUnknown* pObject);

  //获取对象路径的字符串
  static void GetPathElementString(CATPathElement * ipPath ,CATUnicodeString & oPathName, BOOL bIsBackward, int iLength);
  //---------------------------------------------------------------------------

  //=====================================================================================================================================
  //函数说明:从一个特征，构造CATPathElement。调用者Release释放pPathElement指针
  //参数说明:pPathElement--[out]返回的路径指针
  //         spSpecObject--[in]用于计算的对象
  //         pFatherPathElement--[in]用于计算的父路径。如果为NULL，使用当前激活路径
  //返回值:如果成功返回TRUE,否则返回FALSE。
  static BOOL GetPathElementFromSpecObject(CATPathElement* &pPathElement,const CATISpecObject_var spSpecObject,CATPathElement* pFatherPathElement=NULL);
  //=====================================================================================================================================
  //函数说明:从一个特征，构造CATPathElement。调用者Release释放pPathElement指针
  //参数说明:pPathElement--[out]返回的路径指针
  //         spSpecObject--[in]用于计算的对象
  //         spPrdInstance--[in]用于计算的父产品实例。不能为NULL_var
  //返回值:如果成功返回TRUE,否则返回FALSE。
  static BOOL GetPathElementFromSpecObject(CATPathElement* &pPathElement,const CATISpecObject_var spSpecObject,CATIProduct_var spPrdInstance);
  //=====================================================================================================================================
  //函数说明:释放PathElement列表
  //参数说明:lstPathElem--[in\out]释放对象
  //返回值:无
  static void FreePathElementLst(CATLISTP(CATPathElement) &lstPathElem);
  //=====================================================================================================================================
  //函数说明:获得全路径中的最后一个Product实例
  //参数说明:pPathElement--[in]路径对象
  //返回值:返回最后一Product实例
  static CATIProduct_var GetLastProductInstance(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //函数说明:获得全路径中的最后一个Product实例的全路径,调用者释放返回的路径指针
  //参数说明:pPathElement--[in]路径对象
  //返回值:返回最后一Product实例的全路径
  static CATPathElement* GetLastPrdInstPathElement(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //函数说明:获得全路径中的CATIPrtPart对象
  //参数说明:pPathElement--[in]路径对象
  //返回值:返回全路径中的CATIPrtPart对象
  static CATIPrtPart_var GetPrtPartObject(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //函数说明:获得全路径中的PrtPart的全路径,调用者释放返回的路径指针
  //参数说明:pPathElement--[in]路径对象
  //返回值:返回全路径中的PrtPart的全路径
  static CATPathElement* GetPrtPartPathElement(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //函数说明:获得全路径的最后一个特征
  //参数说明:pPathElement--[in]路径对象
  //返回值:返回全路径的最后一个特征
  static CATISpecObject_var GetLastSpecObject(CATPathElement* pPathElement);


//**********************************************************************************************************************************************************************************************************************************************************
//视图操作分类
//**********************************************************************************************************************************************************************************************************************************************************
  //模型居中
  static BOOL RollCameraToTopView(CATMathDirectionf  SightDir,CATMathDirectionf  upDir);

  //模型结构树高亮居中
  static void CenterSpecGraph(CATPathElement* piPathEle);

  //视图居中给定点对象
  static BOOL CenterViewPoints(const CATLISTV(CATMathPoint) lstMathPoints,double dIniRadius = 20);


//**********************************************************************************************************************************************************************************************************************************************************
//数学操作分类
//**********************************************************************************************************************************************************************************************************************************************************
  //四舍五入函数
  static double Round(double data, int prec);


};

//-----------------------------------------------------------------------

#endif
