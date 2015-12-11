#pragma once


// CPictureCtrl

class CPictureCtrl : public CStatic
{
	DECLARE_DYNAMIC(CPictureCtrl)

	CString m_csImagePath = _T("");

public:
	CPictureCtrl();
	virtual ~CPictureCtrl();

	//Loads an image from a file
	BOOL LoadFromFile(CString &szFilePath);


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};


