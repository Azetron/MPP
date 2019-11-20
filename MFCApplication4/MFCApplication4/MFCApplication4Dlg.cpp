
// MFCApplication4Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication4Dlg dialog



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	
	, Operatie(0)
	, Rezultat(0)
	, Text(_T(""))
	
	
	, A(0)
	, B(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_A, A);
	//  DDX_Text(pDX, IDC_B, B);
	DDX_Radio(pDX, IDC_OPERATIE1, Operatie);
	//  DDX_Control(pDX, IDC_STATIC1, Text);
	DDX_Text(pDX, IDC_EDIT1, Rezultat);
	//  DDX_Text(pDX, IDC_STATIC1, Text);

	DDX_Text(pDX, IDC_STATIC1, Text);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_B, B);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPERATIE1, &CMFCApplication4Dlg::OnBnClickedOperatie1)
	ON_BN_CLICKED(IDC_OPERATIE2, &CMFCApplication4Dlg::OnBnClickedOperatie2)
	ON_BN_CLICKED(IDC_OPERATIE3, &CMFCApplication4Dlg::OnBnClickedOperatie3)
	ON_BN_CLICKED(IDC_OPERATIE4, &CMFCApplication4Dlg::OnBnClickedOperatie4)
	ON_BN_CLICKED(IDC_OPERATIE5, &CMFCApplication4Dlg::OnBnClickedOperatie5)
	ON_BN_CLICKED(IDC_OPERATIE6, &CMFCApplication4Dlg::OnBnClickedOperatie6)
	ON_BN_CLICKED(IDC_OPERATIE7, &CMFCApplication4Dlg::OnBnClickedOperatie7)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication4Dlg message handlers

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication4Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnBnClickedOperatie1()
{

		Operatie = 0;
}


void CMFCApplication4Dlg::OnBnClickedOperatie2()
{
	Operatie = 1;
}


void CMFCApplication4Dlg::OnBnClickedOperatie3()
{
	Operatie = 2;
}


void CMFCApplication4Dlg::OnBnClickedOperatie4()
{
	Operatie = 3;
}


void CMFCApplication4Dlg::OnBnClickedOperatie5()
{
	Operatie = 4;
}


void CMFCApplication4Dlg::OnBnClickedOperatie6()
{
	Operatie = 5;
}


void CMFCApplication4Dlg::OnBnClickedOperatie7()
{
	Operatie = 6;
}


void CMFCApplication4Dlg::OnBnClickedButton1()
{
	UpdateData();
	switch (Operatie) {
	case 0:
		Rezultat = A + B;
		Text = "A+B=";
		break;
	case 1:
		Rezultat = A - B;
		Text = "A-B=";
		break;
	case 2:
		Rezultat = A * B;
		Text = "A*B=";
		break;
	case 3:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B;
		Text = "A/B=";
		break;
	case 4:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = A / B;
		Text = "[A/B]=";
		break;
	case 5:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B - A / B;
		Text = "{A/B}=";
		break;
	case 6:
		Rezultat = fmod (A , B);
		Text = "A%B=";
		break;
	default: AfxMessageBox((LPCWSTR)L"Nu s-a optat pentru o operatie");
	}
	UpdateData(FALSE);
}
