
// LastHomeworkDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "LastHomework.h"
#include "LastHomeworkDlg.h"
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


// CLastHomeworkDlg dialog



CLastHomeworkDlg::CLastHomeworkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LASTHOMEWORK_DIALOG, pParent)
	, valoare(0)
	
	, ex4(0)
	, final(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLastHomeworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EXERCITIUL3, valoare);
	//  DDX_Text(pDX, IDC_EXERCITIUL4, ex4);
	//  DDX_Text(pDX, IDC_EXERCITIUL4, ex4);
	DDX_Text(pDX, IDC_EXERCITIUL4, ex4);
	DDX_Text(pDX, IDC_EDIT1, final);
	DDX_Text(pDX, IDC_EDIT1, final);
}

BEGIN_MESSAGE_MAP(CLastHomeworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLastHomeworkDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CLastHomeworkDlg::OnBnClickedButton2)
	
	ON_BN_CLICKED(IDC_EX1, &CLastHomeworkDlg::OnBnClickedEx1)
	ON_BN_CLICKED(IDC_BUTTON3, &CLastHomeworkDlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_Ex3, &CLastHomeworkDlg::OnBnClickedEx3)
	ON_BN_CLICKED(IDC_BUTTON4, &CLastHomeworkDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_Ex4, &CLastHomeworkDlg::OnBnClickedEx4)
	ON_BN_CLICKED(IDC_EXERCITIUL5, &CLastHomeworkDlg::OnBnClickedExercitiul5)
	ON_EN_CHANGE(IDC_EDIT1, &CLastHomeworkDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CLastHomeworkDlg message handlers

BOOL CLastHomeworkDlg::OnInitDialog()
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
	Volum = 0; 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLastHomeworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLastHomeworkDlg::OnPaint()
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
HCURSOR CLastHomeworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLastHomeworkDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if (Volum > MAX) {
		CString Text;    
		Text.Format((LPCWSTR)L"Seria  de  date  are  maxim  %d  de valori!", MAX);    
		AfxMessageBox(Text); 
		return;
	}
	CString Data;
	GetDlgItemText(IDC_DATA, Data);
	((CListBox*)GetDlgItem(IDC_LISTA))->AddString(Data);
	Serie[Volum++] = wcstod(Data, NULL);
	SetDlgItemInt(IDC_VOLUM, Volum);
	
}


void CLastHomeworkDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	double Medie = 0, Disp = 0;
	for (int i = 0; i < Volum; i++) {
		Medie += Serie[i];
	}
	Medie /= Volum;
	for (int i = 0; i < Volum; i++) {
		Disp += pow(Serie[i] - Medie, 2);
	}
	Disp /= pow((double)Volum, 2);
	CString Text;
	Text.Format((LPCWSTR)L"%.2lf", Medie);
	//SetDlgItemText(IDC_MEDIE, Text);
	Text.Format((LPCWSTR)L"%.2lf", Disp);
	//SetDlgItemText(IDC_DISPERSIE, Text);
}



void CLastHomeworkDlg::OnBnClickedEx1()
{
	double maxim = 0, minim = Serie[1], amplitudine = 0;
	CString text;
	for (int i = 0; i < Volum; i++) {
		if (maxim < Serie[i]) {
			maxim = Serie[i];
			
		}
		if (minim > Serie[i]) {
			minim = Serie[i];
		}
	}
	amplitudine = maxim - minim;
	CString Text;
	CString Text1;
	CString Text2;
	Text.Format((LPCWSTR)L"%.2lf", maxim);
	SetDlgItemText(IDC_MAXIM, Text);
	Text1.Format((LPCWSTR)L"%.2lf", minim);
	SetDlgItemText(IDC_MINIM, Text1);
	Text2.Format((LPCWSTR)L"%.2lf", amplitudine);
	SetDlgItemText(IDC_AMPLITUDINE, Text2);
}


void CLastHomeworkDlg::OnBnClickedButton3()
{
	CString Text;
	if (Volum == 1) {
		Text.Format((LPCWSTR)L"Doar valoarea %d in lista", Volum);
		AfxMessageBox(Text);
	}
	for (int i = 0; i < Volum - 1; i++)
		for (int j = i + 1; j < Volum; j++)
			if (Serie[i] == Serie[j])
			{
				((CListBox*)GetDlgItem(IDC_LISTA))->DeleteString(j);
				for (int k = j; k < Volum - 1; k++)
				{
					Serie[k] = Serie[k + 1];
				}
				j--;
				Volum--;
			}
	SetDlgItemInt(IDC_VOLUM, Volum);
	
	
}

//((CListBox*)GetDlgItem(IDC_LISTA))->DeleteString(i + 1);


void CLastHomeworkDlg::OnBnClickedButton4()
{
	UpdateData();
	int cifra = valoare;
	int contor = 0;
	int compar = 0;
	CString Text;
	for (int i = 0; i < Volum; i++) {
		contor += 1;
		if (cifra == Serie[i]) {
			Text.Format((LPCWSTR)L"Cifra se afla pe pozitia : %d", contor);
			AfxMessageBox(Text);
			return;
		}

	}
}


void CLastHomeworkDlg::OnBnClickedEx4()
{
	CString text;
	int l = 0;
	int r = Volum;
	int mid;
	GetDlgItemText(IDC_EXERCITIUL4, text);
	double v = wcstod(text, NULL);
	while (l < r) {
		mid = (l + r) / 2;
		if (Serie[mid] == v)
		{
			text.Format((LPCWSTR)L"%d", mid);
			AfxMessageBox(text);
			return;
		}
		if (v < Serie[mid]) {
			r = mid - 1;
		}
		if (v > Serie[mid]) {
			l = mid + 1;
		}	
	}
	for (int i = 0; i < Volum; i++)
		if (Serie[i] == v)
		{
			text.Format((LPCWSTR)L"%d", i);
			AfxMessageBox(text);
			return;
		}
}


void CLastHomeworkDlg::OnBnClickedExercitiul5()
{
	CString Data;
	int corect = 0;
	double aux = 0;
	for (int i = 0; i < Volum; i++) {
		for (int j = i+1; j < Volum; j++) {
			aux = Serie[i];
			Serie[i] = Serie[j];
			Serie[j] = aux;
		}
	}
	for (int i = 0; i < Volum; i++) {
		corect = Serie[i];
		Data.Format((LPCWSTR)L"%d", corect);
		SetDlgItemText(IDC_EDIT1, Data);
		GetDlgItemText(IDC_EDIT1, Data);
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(Data);
	}
}


void CLastHomeworkDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
