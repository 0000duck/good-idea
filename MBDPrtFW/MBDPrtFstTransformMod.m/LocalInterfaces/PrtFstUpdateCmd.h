// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstUpdateCmd.h
// The state chart based command: PrtFstUpdateCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   STATECOMMAND
//End CAA2 Wizard Generation Report
//
//  May 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstUpdateCmd_H
#define PrtFstUpdateCmd_H

#include "ktKerExcel.h"
#include "ktPubHeaders.h"
#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "PrtFstUpdateDlg.h"

class PrtFstUpdateDlg;

//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class PrtFstUpdateCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstUpdateCmd, CATStateCommand )

  public:

  PrtFstUpdateCmd();
  virtual ~PrtFstUpdateCmd();

 /**
 * Defines the command automata.
 * <br>
 * <i>(states, transitions and agents)</i>
 */
  virtual void     BuildGraph();

  //消息框响应函数
  void OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //
  BOOL IsThisZPPrt(CATUnicodeString istrDocName);

  //
  //检查线模型的更新情况，是否超出安装长度要求，检验规则：长度-夹层
  HRESULT CheckFstLineLengthInfo(CATListValCATISpecObject_var &alistSpecLine,CATListValCATISpecObject_var &alistSpecCircle);

  //
  //对错误紧固件处理PB的响应
  void ReportAndMarkCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void DeleteAllErrorCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //
  void OpenOK(CATCommand * iSendingCommand, CATNotification * iSentNotification,CATCommandClientData iUsefulData);

  //
  void GetSeletedFSTLine(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void GetSeletedFSTLineSuccess(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  
private:

	//对话框指针
	PrtFstUpdateDlg *m_pDlg;

	//文档指针
	CATDocument *m_piDoc;
	CATUnicodeString m_strDocName;
	CATFrmEditor *m_piEditor;
	CATHSO *m_piHSO;
	CATISO *m_piISO; 

	//数据列表
	CATListValCATISpecObject_var m_alistSuccessfulSpec, m_alistErrorSpec;
	//失效类型
	CATListValCATUnicodeString m_aliststrSuccessfulInfo,m_aliststrErrorInfo;
	//
	CATDlgFile *m_pFileDlg;
	//
	CATUnicodeString m_strFilePath;

	//用户自定义上下检验容差
	double m_dLowerValue,m_dUpperValue;
};

//----------------------------------------------------------------------

#endif
