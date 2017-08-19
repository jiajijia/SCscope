Revised by Jiajijia in 8.191035

#pragma once

#include "CommonHeader.h"
#include <afxcoll.h>

// CCommonDoc document

class CCommonDoc : public CDocument
{
	DECLARE_DYNCREATE(CCommonDoc)

public:
	CCommonDoc();
	virtual ~CCommonDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()

	CMapStringToPtr m_MemberList;
	CMapStringToPtr m_FuncList;
	CMapStringToPtr m_ViewList;
public:

	// register member
	void RegisterMember(LPCTSTR key, void* value)
	{
		m_MemberList.SetAt(key,value);
	}

	//  register function
	void RegisterFunction(LPCTSTR key, LPPROC value)
	{
		m_FuncList.SetAt(key,value);
	}
	//  get member pointer
	void* GetPointer(LPCTSTR key);
	//  get function pointer
	LPPROC GetFunction(LPCTSTR key);

	//Register View
	void RegisterView(LPCTSTR key, CView* pView)
	{
		m_ViewList.SetAt(key,pView);
	}
	//Get View
	CView* GetView(LPCTSTR key);
	// Update All View
	void UpdateViews();
	// Update All Frame
	void UpdateFrames();
	// Pointer to Parent Doc
	CCommonDoc* m_pParentDoc;
	// Config File Path
	CString m_strConfigFile;
	CString m_strSection;
	UINT GetProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefault);
	CString GetProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszDefault=NULL);
	double GetProfileDouble(LPCTSTR lpszSection, LPCTSTR lpszEntry, double dDefault);
	BOOL WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue);
	BOOL WriteProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszValue);
	BOOL WriteProfileDouble(LPCTSTR lpszSection, LPCTSTR lpszEntry, double dValue);
	virtual int InitDocument(LPVOID pParam);
};
