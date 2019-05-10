
// formViewStudyView.cpp : CformViewStudyView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CformViewStudyView ����/����

CformViewStudyView::CformViewStudyView()
	: CFormView(CformViewStudyView::IDD)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CformViewStudyView ���

#ifdef _DEBUG
void CformViewStudyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CformViewStudyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CformViewStudyDoc* CformViewStudyView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CformViewStudyDoc)));
	return (CformViewStudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CformViewStudyView ��Ϣ�������


void CformViewStudyView::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���

	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	CRect rt(0,50,200,200);
	pDC->MoveTo(0,50);
	pDC->LineTo(200,200);
	pDC->DrawText(_T("�����ڶԻ����ϴ�������ͼ"),&rt,DT_LEFT);


}


BOOL CformViewStudyView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CFormView::OnDrop(pDataObject, dropEffect, point);
}


DROPEFFECT CformViewStudyView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CFormView::OnDragEnter(pDataObject, dwKeyState, point);
}
