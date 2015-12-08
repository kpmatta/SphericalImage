// PictureCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "PictureCtrl.h"
#include "resource.h"


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
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CPictureCtrl message handlers




void CPictureCtrl::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: Add your message handler code here
	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_POPUP_MENU));
	CMenu *pSub = menu.GetSubMenu(0);
	// Modify menu items here if necessary (e.g. gray out items)
	int nCmd = pSub->TrackPopupMenuEx(
		TPM_LEFTALIGN | TPM_RIGHTBUTTON | TPM_VERPOSANIMATION | TPM_RETURNCMD | TPM_NONOTIFY,
		point.x, point.y, AfxGetMainWnd(), NULL);
	if (nCmd)
		SendMessage(WM_COMMAND, nCmd);

}


void CPictureCtrl::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CStatic::OnRButtonDown(nFlags, point);
}


void CPictureCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CStatic::OnLButtonDown(nFlags, point);
}


BOOL CPictureCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class

	return CStatic::PreTranslateMessage(pMsg);
}
