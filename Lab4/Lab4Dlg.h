
// Lab4Dlg.h : header file
//

#pragma once


// CLab4Dlg dialog
class CLab4Dlg : public CDialogEx
{
// Construction
public:
	CLab4Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
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
	LONG NR_DVD;
public:
	CListBox Lista;
	CString Moneda;
	CComboBox Zile;
	CComboBox moneda;
	CComboBox recording_type;
	CComboBox calitate_Audio;
	CComboBox calitate_Film;
	CComboBox categorie;
	CComboBox ComboList[6];
	CString REZOLUTIE;
	BOOL Reducere;
	CTreeCtrl TREE;
	CComboBox Add_Categorie;
	CComboBox Add_CategorieItem;
	long Pret;
	double Total;
	double Total_DVD;
	CString Text_Lei;
	afx_msg void OnBnClickedCalculeaza();
	afx_msg void OnLbnSelchangeList();
	afx_msg void OnBnClickedReducere();
	afx_msg void OnCbnSelchangeCombo2();
	CButton s;
	afx_msg void OnStnClickedStatic6();
	afx_msg void OnEnChangeTotal();
	afx_msg void OnStnClickedStatic3();
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnStnClickedStatic35();
	afx_msg void OnStnClickedMoneda();
	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnEnChangeTotal2();
	afx_msg void OnBnClickedCalculeaza2();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangePret();
	afx_msg void OnTvnSelchangedTree2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelchangeCombo7();
	afx_msg void OnCbnSelchangeCombo8();
};
