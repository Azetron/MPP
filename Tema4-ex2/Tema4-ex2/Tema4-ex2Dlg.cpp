
// Tema4-ex2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Tema4-ex2.h"
#include "Tema4-ex2Dlg.h"
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


// CTema4ex2Dlg dialog



CTema4ex2Dlg::CTema4ex2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEMA4EX2_DIALOG, pParent)
	, Calitate(0)
	, Tip(0)
	, Reducere(FALSE)
	, Pret(0)
	, Total(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTema4ex2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST, Lista);
	DDX_Radio(pDX, IDC_CALITATE1, Calitate);
	DDX_Radio(pDX, IDC_TIP1, Tip);
	DDX_Check(pDX, IDC_REDUCERE, Reducere);
	DDX_Text(pDX, IDC_PRET, Pret);
	DDX_Text(pDX, IDC_TOTAL, Total);
	DDX_Control(pDX, IDC_COMBO, Zile);
	DDX_Control(pDX, IDC_LIST, Lista);
}

BEGIN_MESSAGE_MAP(CTema4ex2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CTema4ex2Dlg::OnBnClickedCalculeaza)
END_MESSAGE_MAP()


// CTema4ex2Dlg message handlers

BOOL CTema4ex2Dlg::OnInitDialog()
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
	CRect rect;
	Lista.GetClientRect(&rect);
	int nColInterval = rect.Width() / 5;

	Lista.InsertColumn(0, _T("Titlu"), LVCFMT_LEFT, nColInterval * 3);
	Lista.InsertColumn(1, _T("Anul"), LVCFMT_LEFT, nColInterval);
	Lista.InsertColumn(2, _T("Durata"), LVCFMT_LEFT, rect.Width() - 4 * nColInterval);

	LVITEM lvi;
	CString strItem;
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("The Matrix"));
	lvi.iItem = 0;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	strItem.Format(_T("1999"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	strItem.Format(_T("136 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Mumia"));
	lvi.iItem = 1;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	strItem.Format(_T("1999"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	strItem.Format(_T("124 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Spiderman"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	strItem.Format(_T("2002"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	strItem.Format(_T("121 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTema4ex2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTema4ex2Dlg::OnPaint()
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
HCURSOR CTema4ex2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTema4ex2Dlg::OnBnClickedCalculeaza()
{
	UpdateData();
	double v;
	if ((Zile.GetCurSel() + 1) < 5)
		v = 1;
	else
		if ((Zile.GetCurSel() + 1) < 10)
			v = 0.95;
		else v = 0.90;

	if (Calitate == 1) {
		v = v - 0.05;
	}
		
	else {
		if (Calitate == 2) {
			v = v - 0.10;
		}
	}
	if (Tip == 0) {
		v = v - 0.10;
	}
	else {
		v = v - 0.05;
	} 

	Total = (Zile.GetCurSel() + 1) * Pret * Lista.GetSelectedCount() * (Reducere ? v : 1);
	UpdateData(FALSE);

}
