
// Tema2Dlg.h : header file
//

#pragma once


// CTema2Dlg dialog
class CTema2Dlg : public CDialogEx
{
// Construction
public:
	CTema2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMA2_DIALOG };
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
	int A;
	int B;
//	int cmMdc;
	int cmmmc;
	afx_msg void OnBnClickedcalculeaza();
	int cmMdc;
};
