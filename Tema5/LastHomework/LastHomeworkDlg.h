
// LastHomeworkDlg.h : header file
//

#pragma once
#define MAX 50

// CLastHomeworkDlg dialog
class CLastHomeworkDlg : public CDialogEx
{
// Construction
public:
	CLastHomeworkDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LASTHOMEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	
	int Volum; 
	double Serie[MAX];
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
	afx_msg void OnBnClickedEx1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedEx3();
	int valoare;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedEx4();
//	int ex4;
//	double ex4;
	int ex4;
	afx_msg void OnBnClickedExercitiul5();
//	double final;
	int final;
	afx_msg void OnEnChangeEdit1();
};
