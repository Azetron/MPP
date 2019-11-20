
// MFCApplication4Dlg.h : header file
//

#pragma once


// CMFCApplication4Dlg dialog
class CMFCApplication4Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

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
//	int A;
//	int B;
	int Operatie;
//	CStatic Text;
	double Rezultat;
	afx_msg void OnBnClickedOperatie1();
	afx_msg void OnBnClickedOperatie2();
	afx_msg void OnBnClickedOperatie3();
	afx_msg void OnBnClickedOperatie4();
	afx_msg void OnBnClickedOperatie5();
	afx_msg void OnBnClickedOperatie6();
	afx_msg void OnBnClickedOperatie7();
	afx_msg void OnBnClickedButton1();
	CString Text;
	
	double A;
	double B;
};
