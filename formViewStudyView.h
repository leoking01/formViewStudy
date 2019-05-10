
// formViewStudyView.h : CformViewStudyView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CformViewStudyView : public CFormView
{
protected: // �������л�����
	CformViewStudyView();
	DECLARE_DYNCREATE(CformViewStudyView)

public:
	enum{ IDD = IDD_FORMVIEWSTUDY_FORM };

// ����
public:
	CformViewStudyDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CformViewStudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
};

#ifndef _DEBUG  // formViewStudyView.cpp �еĵ��԰汾
inline CformViewStudyDoc* CformViewStudyView::GetDocument() const
   { return reinterpret_cast<CformViewStudyDoc*>(m_pDocument); }
#endif

