#pragma once


// CPictureCtrl

class CPictureCtrl : public CStatic
{
	DECLARE_DYNAMIC(CPictureCtrl)

public:
	CPictureCtrl();
	virtual ~CPictureCtrl();

	CString m_csImageName;

protected:
	DECLARE_MESSAGE_MAP()
public:

};


