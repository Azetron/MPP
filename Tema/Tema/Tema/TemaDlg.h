
// TemaDlg.h : header file
//

#pragma once


// CTemaDlg dialog
class CTemaDlg : public CDialogEx
{
// Construction
public:
	CTemaDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMA_DIALOG };
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
	int Nr;
	afx_msg void OnBnClickedDivizori();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};
