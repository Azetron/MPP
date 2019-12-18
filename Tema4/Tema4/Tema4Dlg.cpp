
// Tema4Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Tema4.h"
#include "Tema4Dlg.h"
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
public:
	afx_msg void OnLbnSelchangeList();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST, &CAboutDlg::OnLbnSelchangeList)
END_MESSAGE_MAP()


// CTema4Dlg dialog



CTema4Dlg::CTema4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEMA4_DIALOG, pParent)
	, Calitate(0)
	, Tip(0)
	, Reducere(FALSE)
	, Pret(0)
	, Total(0)
	, Numar(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTema4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, Lista);
	DDX_Radio(pDX, IDC_CALITATE1, Calitate);
	DDX_Radio(pDX, IDC_TIP1, Tip);
	DDX_Check(pDX, IDC_REDUCERE, Reducere);
	DDX_Text(pDX, IDC_PRET, Pret);
	DDX_Text(pDX, IDC_TOTAL, Total);
	DDX_Control(pDX, IDC_COMBO, Zile);
	DDX_Text(pDX, IDC_STATIC13, Numar);
}

BEGIN_MESSAGE_MAP(CTema4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CTema4Dlg::OnBnClickedCalculeaza)
	ON_LBN_SELCHANGE(IDC_LIST, &CTema4Dlg::OnLbnSelchangeList)
	ON_EN_CHANGE(IDC_PRET, &CTema4Dlg::OnEnChangePret)
	ON_EN_CHANGE(IDC_TOTAL, &CTema4Dlg::OnEnChangeTotal)
	ON_STN_CLICKED(IDC_STATIC13, &CTema4Dlg::OnStnClickedStatic13)
	ON_BN_CLICKED(IDC_CALITATE1, &CTema4Dlg::OnBnClickedCalitate1)
	ON_BN_CLICKED(IDC_CALITATE2, &CTema4Dlg::OnBnClickedCalitate2)
	ON_BN_CLICKED(IDC_CALITATE3, &CTema4Dlg::OnBnClickedCalitate3)
	ON_BN_CLICKED(IDC_TIP1, &CTema4Dlg::OnBnClickedTip1)
	ON_BN_CLICKED(IDC_TIP2, &CTema4Dlg::OnBnClickedTip2)
	ON_CBN_SELCHANGE(IDC_COMBO, &CTema4Dlg::OnCbnSelchangeCombo)
	ON_BN_CLICKED(IDC_REDUCERE, &CTema4Dlg::OnBnClickedReducere)
END_MESSAGE_MAP()


// CTema4Dlg message handlers

BOOL CTema4Dlg::OnInitDialog()
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
	Lista.AddString((LPCWSTR)L"Arizona Dream");
	Lista.AddString((LPCWSTR)L"Matrix");   
	Lista.AddString((LPCWSTR)L"Al saselea simt");  
	Lista.AddString((LPCWSTR)L"Al cincilea element");   
	Lista.AddString((LPCWSTR)L"Winx");   
	Lista.AddString((LPCWSTR)L"H2O");   
	Lista.AddString((LPCWSTR)L"Spiderman");  
	Lista.AddString((LPCWSTR)L"Mumia");
	Lista.AddString((LPCWSTR)L"24");   
	Lista.AddString((LPCWSTR)L"Stargate");  
	Lista.AddString((LPCWSTR)L"Star Trek");  
	Lista.AddString((LPCWSTR)L"Two Weeks Notice");  
	Lista.AddString((LPCWSTR)L"Miss Congeniality");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTema4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTema4Dlg::OnPaint()
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
HCURSOR CTema4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTema4Dlg::OnBnClickedCalculeaza()
{
	UpdateData();
	double red;
	if ((Zile.GetCurSel() + 1) < 5)
		red = 1;
	else
		if ((Zile.GetCurSel() + 1) < 10)
			red = 0.95;
		else red = 0.90;

	if (Calitate == 1)
		red = red - 0.05;
	else
		if (Calitate == 2)
			red = red - 0.10;

	if (Tip == 0)
		red = red - 0.10;
	else red = red - 0.05;

	Total = (Zile.GetCurSel() + 1) * Pret * Lista.GetSelCount() * (Reducere ? red : 1);
	UpdateData(FALSE);


}




void CTema4Dlg::OnEnChangePret() {

}
void CTema4Dlg::OnEnChangeTotal() {

}
void CTema4Dlg::OnStnClickedStatic13() {

}
void CTema4Dlg::OnBnClickedCalitate1() {

}
void CTema4Dlg::OnBnClickedCalitate2() {

}
void CTema4Dlg::OnBnClickedCalitate3() {

}
void CTema4Dlg::OnBnClickedTip1() {

}
void CTema4Dlg::OnBnClickedTip2() {

}
void CTema4Dlg::OnCbnSelchangeCombo() {

}
void CTema4Dlg::OnBnClickedReducere() {

}
void CTema4Dlg::OnLbnSelchangeList() {
	UpdateData();
	Numar = Lista.GetSelCount();
	UpdateData(FALSE);
}
void CAboutDlg::OnLbnSelchangeList() {

}