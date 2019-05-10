
// formViewStudyView.h : CformViewStudyView 类的接口
//

#pragma once

#include "resource.h"


class CformViewStudyView : public CFormView
{
protected: // 仅从序列化创建
	CformViewStudyView();
	DECLARE_DYNCREATE(CformViewStudyView)

public:
	enum{ IDD = IDD_FORMVIEWSTUDY_FORM };

// 特性
public:
	CformViewStudyDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CformViewStudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // formViewStudyView.cpp 中的调试版本
inline CformViewStudyDoc* CformViewStudyView::GetDocument() const
   { return reinterpret_cast<CformViewStudyDoc*>(m_pDocument); }
#endif

