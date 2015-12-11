#pragma once


// CPictureCtrl

class CPictureCtrl : public CStatic
{
	DECLARE_DYNAMIC(CPictureCtrl)

	CString m_csImagePath = _T("");

public:
	CPictureCtrl();
	virtual ~CPictureCtrl();

	CString m_csImageName;

protected:
	DECLARE_MESSAGE_MAP()
public:

};


