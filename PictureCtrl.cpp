// PictureCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SphericalImage.h"
#include "PictureCtrl.h"


// CPictureCtrl

IMPLEMENT_DYNAMIC(CPictureCtrl, CStatic)

CPictureCtrl::CPictureCtrl()
{

}

CPictureCtrl::~CPictureCtrl()
{
}


BEGIN_MESSAGE_MAP(CPictureCtrl, CStatic)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CPictureCtrl message handlers




void CPictureCtrl::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO: Add your message handler code here
}


void CPictureCtrl::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CStatic::OnRButtonDown(nFlags, point);
}
