
// SphericalImageDlg.h : header file
//

#pragma once
#include "afxwin.h"


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
	CStatic m_face_1;
	afx_msg void OnBnClickedOk();
};
