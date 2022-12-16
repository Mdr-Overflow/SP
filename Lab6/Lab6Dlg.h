
// Lab6Dlg.h : header file
//

#pragma once
#define MAXX 50


// CLab6Dlg dialog
class CLab6Dlg : public CDialogEx
{
// Construction
public:
	CLab6Dlg(CWnd* pParent = nullptr);	// standard constructor

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
	int m_nCrt;
	CListBox Serie;
	CListBox Textt;
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedInainte();
	afx_msg void OnBnClickedInapoi();
	afx_msg void ActualizareFoto();
	HRESULT	PropertyTypeFromWORD(WORD, WCHAR* , UINT );
};
