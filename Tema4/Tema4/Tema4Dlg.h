
// Tema4Dlg.h : header file
//

#pragma once


// CTema4Dlg dialog
class CTema4Dlg : public CDialogEx
{
// Construction
public:
	CTema4Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMA4_DIALOG };
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
	CListBox Lista;
	int Calitate;
	int Tip;
	BOOL Reducere;
	long Pret;
	double Total;
	CComboBox Zile;
	afx_msg void OnBnClickedCalculeaza();
	int Numar;
	afx_msg void OnLbnSelchangeList();
	afx_msg void OnEnChangePret();
	afx_msg void OnEnChangeTotal();
	afx_msg void OnStnClickedStatic13();
	afx_msg void OnBnClickedCalitate1();
	afx_msg void OnBnClickedCalitate2();
	afx_msg void OnBnClickedCalitate3();
	afx_msg void OnBnClickedTip1();
	afx_msg void OnBnClickedTip2();
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnBnClickedReducere();
};
