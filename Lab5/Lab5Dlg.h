
// Lab5Dlg.h : header file
//

#pragma once
#define MAXX 50

// CLab5Dlg dialog
class CLab5Dlg : public CDialogEx
{
// Construction
public:
	CLab5Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB5_DIALOG };
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
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedCalculeaza();
	double NewNumber;
	int Volum=0;
	double Medie;
	double Dispersie;
	double SerieLista[MAXX];
	double CopySerieLista[MAXX];
	CListBox Serie;
	afx_msg void OnEnChangeMinim();
	afx_msg void OnBnClickedCautaunsort();
	afx_msg void OnBnClickedRmdublcate();
	afx_msg void OnBnClickedCautsort();
	afx_msg void OnBnClickedSort();
};
