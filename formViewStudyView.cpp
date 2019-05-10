
// formViewStudyView.cpp : CformViewStudyView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "formViewStudy.h"
#endif

#include "formViewStudyDoc.h"
#include "formViewStudyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CformViewStudyView

IMPLEMENT_DYNCREATE(CformViewStudyView, CFormView)

BEGIN_MESSAGE_MAP(CformViewStudyView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CformViewStudyView 构造/析构

CformViewStudyView::CformViewStudyView()
	: CFormView(CformViewStudyView::IDD)
{
	// TODO: 在此处添加构造代码

}

CformViewStudyView::~CformViewStudyView()
{
}

void CformViewStudyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CformViewStudyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CformViewStudyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CformViewStudyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CformViewStudyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CformViewStudyView 诊断

#ifdef _DEBUG
void CformViewStudyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CformViewStudyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CformViewStudyDoc* CformViewStudyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CformViewStudyDoc)));
	return (CformViewStudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CformViewStudyView 消息处理程序


void CformViewStudyView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类

	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	CRect rt(0,50,200,200);
	pDC->MoveTo(0,50);
	pDC->LineTo(200,200);
	pDC->DrawText(_T("这是在对话框上创建的视图"),&rt,DT_LEFT);


}


BOOL CformViewStudyView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CFormView::OnDrop(pDataObject, dropEffect, point);
}


DROPEFFECT CformViewStudyView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CFormView::OnDragEnter(pDataObject, dwKeyState, point);
}
