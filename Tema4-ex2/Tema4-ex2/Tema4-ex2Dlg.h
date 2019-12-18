
// Tema4-ex2Dlg.h : header file
//

#pragma once


// CTema4ex2Dlg dialog
class CTema4ex2Dlg : public CDialogEx
{
// Construction
public:
	CTema4ex2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMA4EX2_DIALOG };
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
//	ClistBox Lista;
	afx_msg void OnBnClickedCalculeaza();
	int Calitate;
	int Tip;
	BOOL Reducere;
	long Pret;
	double Total;
	CComboBox Zile;
	CListCtrl Lista;
};
