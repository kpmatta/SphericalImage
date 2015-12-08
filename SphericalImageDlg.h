
// SphericalImageDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "PictureCtrl.h"


// CSphericalImageDlg dialog
class CSphericalImageDlg : public CDialogEx
{
// Construction
public:
	CSphericalImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SPHERICALIMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CPictureCtrl* m_pActiveCtrl = NULL;
	CPictureCtrl m_FrontCtrl;
	CPictureCtrl m_LeftCtrl;
	CPictureCtrl m_RightCtrl;
	CPictureCtrl m_BackCtrl;
	CPictureCtrl m_TopCtrl;
	CPictureCtrl m_DownCtrl;

	afx_msg void OnBnClickedOk();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPictureCtrl* GetActivePictureControl(CPoint point);
	void LoadImageToControl(CPictureCtrl* pActiveCtrl, LPCTSTR lpszImagePath);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnLoadimageLoadimage();
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
