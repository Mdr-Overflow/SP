
// Laborator3Dlg.h : header file
//

#pragma once


// CLaborator3Dlg dialog
class CLaborator3Dlg : public CDialogEx
{
// Construction
public:
	CLaborator3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABORATOR3_DIALOG };
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
	double A;
	double B;
	int Operatie;
	CString Text;
	CString outputRezultat;
	double Rezultat;
	afx_msg void OnBnClickedCalculeaza();
	afx_msg void OnBnClickedButtonCalculeaza();
	int inputN;
	int inputPrimulNumar;
	int inputAlDoileaNumar;
	int operatieTema;
	int valoareRezultat;
	afx_msg void OnBnClickedSplit1();
	afx_msg void OnBnClickedMfcmenubutton2();
	afx_msg void OnNMCustomdrawProgress3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawProgressbar1(NMHDR* pNMHDR, LRESULT* pResult);
	BOOL Barstart;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnStnClickedTextRezultat();
	afx_msg void OnEnChangeA();
};
