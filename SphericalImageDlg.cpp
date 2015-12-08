
// SphericalImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SphericalImage.h"
#include "SphericalImageDlg.h"
#include "afxdialogex.h"
#include "PictureCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSphericalImageDlg dialog



CSphericalImageDlg::CSphericalImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSphericalImageDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSphericalImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_FACE_FRONT, m_FrontCtrl);
	DDX_Control(pDX, IDC_STATIC_FACE_LEFT, m_LeftCtrl);
	DDX_Control(pDX, IDC_STATIC_FACE_RIGHT, m_RightCtrl);
	DDX_Control(pDX, IDC_STATIC_FACE_BACK, m_BackCtrl);
	DDX_Control(pDX, IDC_STATIC_FACE_TOP, m_TopCtrl);
	DDX_Control(pDX, IDC_STATIC_FACE_DOWN, m_DownCtrl);
}

BEGIN_MESSAGE_MAP(CSphericalImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSphericalImageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CSphericalImageDlg::OnBnClickedOk)
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_LOADIMAGE_LOADIMAGE, &CSphericalImageDlg::OnLoadimageLoadimage)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CSphericalImageDlg message handlers

BOOL CSphericalImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	::DragAcceptFiles(m_hWnd, true);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSphericalImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSphericalImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		m_FrontCtrl.UpdateWindow();

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSphericalImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSphericalImageDlg::OnBnClickedButton1()
{
	CImage img1;
	int dimx = 340, dimy = 397;
	img1.Load(_T("D:\\Krishna\\Projects\\SphericalImage\\Images\\Front.bmp"));
	//filename = path on local system to the bitmap

	CDC *screenDC = GetDC();
	CDC mDC;
	mDC.CreateCompatibleDC(screenDC);
	CBitmap b;
	b.CreateCompatibleBitmap(screenDC, dimx, dimy);

	CBitmap *pob = mDC.SelectObject(&b);
	mDC.SetStretchBltMode(HALFTONE);
	img1.StretchBlt(mDC.m_hDC, 0, 0, dimx, dimy, 0, 0, img1.GetWidth(), img1.GetHeight(), SRCCOPY);
	mDC.SelectObject(pob);

	//m_face_1.ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	m_FrontCtrl.SetBitmap((HBITMAP)b.Detach());
	//m_pictureCtrl.SetBitmap((HBITMAP)b.Detach());
	ReleaseDC(screenDC);
}


void CSphericalImageDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CSphericalImageDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonDown(nFlags, point);
}

CPictureCtrl* CSphericalImageDlg::GetActivePictureControl(CPoint point)
{
	CPictureCtrl* pActiveCtrl = NULL;
	CRect rectCtrl;

	m_FrontCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_FrontCtrl;
	}

	m_LeftCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_LeftCtrl;
	}

	m_RightCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_RightCtrl;
	}

	m_BackCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_BackCtrl;
	}

	m_TopCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_TopCtrl;
	}

	m_DownCtrl.GetWindowRect(&rectCtrl);
	if (rectCtrl.PtInRect(point))
	{
		return &m_DownCtrl;
	}

	return NULL;;
}

void CSphericalImageDlg::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	m_pActiveCtrl = GetActivePictureControl(point);
	if (m_pActiveCtrl)
	{
		CMenu mnuPopup;
		mnuPopup.LoadMenu(IDR_POPUP_MENU);

		CMenu *pSub = mnuPopup.GetSubMenu(0);
		pSub->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}

void CSphericalImageDlg::LoadImageToControl(CPictureCtrl* pActiveCtrl, LPCTSTR lpszImagePath)
{
	CBitmap b;
	CDC mDC;
	CRect rect;
	CImage cImage;

	pActiveCtrl->m_csImageName = lpszImagePath;
	pActiveCtrl->GetWindowRect(&rect);

	cImage.Load(lpszImagePath);

	CDC *screenDC = GetDC();
	mDC.CreateCompatibleDC(screenDC);

	b.CreateCompatibleBitmap(screenDC, rect.Width(), rect.Height());

	CBitmap *pob = mDC.SelectObject(&b);
	mDC.SetStretchBltMode(HALFTONE);
	cImage.StretchBlt(mDC.m_hDC, 0, 0, rect.Width(), rect.Height(), 0, 0, cImage.GetWidth(), cImage.GetHeight(), SRCCOPY);
	mDC.SelectObject(pob);

	pActiveCtrl->SetBitmap((HBITMAP)b.Detach());
	ReleaseDC(screenDC);
}

void CSphericalImageDlg::OnLoadimageLoadimage()
{
	if (m_pActiveCtrl)
	{
		TCHAR szFilters[] = _T("BMP Files (*.bmp)|*.bmp|PNG Files (*.png)|*.png|");

		CFileDialog fileDlg(TRUE, _T("bmp"), _T("*.bmp"),
			OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);

		if (fileDlg.DoModal() == IDOK)
		{
			CString csImagePath = fileDlg.GetPathName();
			LoadImageToControl(m_pActiveCtrl, csImagePath);

			//CBitmap b;
			//CDC mDC;
			//CRect rect;
			//m_pActiveCtrl->GetWindowRect(&rect);


			//CString csImagePath = fileDlg.GetPathName();

			//

			//CImage cImage;
			//cImage.Load(csImagePath);
			////filename = path on local system to the bitmap

			//CDC *screenDC = GetDC();
			//mDC.CreateCompatibleDC(screenDC);

			//b.CreateCompatibleBitmap(screenDC, rect.Width(), rect.Height());

			//CBitmap *pob = mDC.SelectObject(&b);
			//mDC.SetStretchBltMode(HALFTONE);
			//cImage.StretchBlt(mDC.m_hDC, 0, 0, rect.Width(), rect.Height(), 0, 0, cImage.GetWidth(), cImage.GetHeight(), SRCCOPY);
			//mDC.SelectObject(pob);

			//m_pActiveCtrl->SetBitmap((HBITMAP)b.Detach());
			//ReleaseDC(screenDC);
		}
	}
}


void CSphericalImageDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: Add your message handler code here and/or call default
	int nCntFiles = DragQueryFile(hDropInfo, -1, 0, 0);
	if (nCntFiles)
	{
		CPoint point;
		CString csFileName;
		DragQueryPoint(hDropInfo, &point);
		ClientToScreen(&point);
		CPictureCtrl* pActiveCtrl = GetActivePictureControl(point);
		if (pActiveCtrl)
		{
			::DragQueryFile(hDropInfo, 0, csFileName.GetBuffer(_MAX_PATH), _MAX_PATH);
			csFileName.ReleaseBuffer();

			LoadImageToControl(pActiveCtrl, csFileName);
		}
	}

	CDialogEx::OnDropFiles(hDropInfo);
}
