
// Lab4Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab4.h"
#include "Lab4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>

void EnablePrintfAtMFC()
{
	if (AttachConsole(ATTACH_PARENT_PROCESS))
	{
		FILE* pCout;
		freopen_s(&pCout, "CONOUT$", "w", stdout);
		std::cout.clear();
		std::wcout.clear();
	}
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
 
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab4Dlg dialog



CLab4Dlg::CLab4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB4_DIALOG, pParent)
	, Reducere(FALSE)
	, Pret(0)
	, Total(0)
	, Total_DVD(0)
	, Text_Lei(_T(""))
	, Moneda(_T("Lei"))
{	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, Lista);
	DDX_Control(pDX, IDC_COMBO, Zile);
	DDX_Control(pDX, IDC_COMBO2, moneda);
	DDX_Check(pDX, IDC_REDUCERE, Reducere);
	DDX_Text(pDX, IDC_PRET, Pret);
	//DDX_LBString(pDX, IDC_STATIC9, REZOLUTIE);
	DDX_Text(pDX, IDC_TOTAL, Total);
	DDX_Text(pDX, IDC_TOTAL2, Total_DVD);
	DDX_Control(pDX, IDC_COMBO6, categorie);
	DDX_Control(pDX, IDC_COMBO3, calitate_Film);
	DDX_Control(pDX, IDC_COMBO4, calitate_Audio);
	DDX_Control(pDX, IDC_COMBO5, recording_type);
	//DDX_Text(pDX, IDC_MONEDA,Text_Lei);
	DDX_Control(pDX, IDC_TREE1, TREE);
	DDX_Control(pDX, IDC_COMBO7, Add_Categorie);
	DDX_Control(pDX, IDC_COMBO8, Add_CategorieItem);
	
}

BEGIN_MESSAGE_MAP(CLab4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CLab4Dlg::OnBnClickedCalculeaza)
	ON_LBN_SELCHANGE(IDC_LIST, &CLab4Dlg::OnLbnSelchangeList)`		`	1!!!+
	//ON_BN_CLICKED(IDC_REDUCERE, &CLab4Dlg::OnBnClickedReducere)
	//ON_CBN_SELCHANGE(IDC_COMBO2, &CLab4Dlg::OnCbnSelchangeCombo2)

	//ON_EN_CHANGE(IDC_TOTAL, &CLab4Dlg::OnEnChangeTotal)

	//ON_CBN_SELCHANGE(IDC_COMBO, &CLab4Dlg::OnCbnSelchangeCombo)
	//ON_STN_CLICKED(IDC_STATIC35, &CLab4Dlg::OnStnClickedStatic35)
	//ON_STN_CLICKED(IDC_MONEDA, &CLab4Dlg::OnStnClickedMoneda)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CLab4Dlg::OnCbnSelchangeCombo6)
	//ON_CBN_SELCHANGE(IDC_COMBO5, &CLab4Dlg::OnCbnSelchangeCombo5)
	//ON_CBN_SELCHANGE(IDC_COMBO3, &CLab4Dlg::OnCbnSelchangeCombo3)
	//ON_CBN_SELCHANGE(IDC_COMBO4, &CLab4Dlg::OnCbnSelchangeCombo4)
	ON_EN_CHANGE(IDC_TOTAL2, &CLab4Dlg::OnEnChangeTotal2)
	ON_BN_CLICKED(IDC_CALCULEAZA2, &CLab4Dlg::OnBnClickedCalculeaza2)
	//ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CLab4Dlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_PRET, &CLab4Dlg::OnEnChangePret)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CLab4Dlg::OnTvnSelchangedTree2)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CLab4Dlg::OnCbnSelchangeCombo7)
	ON_CBN_SELCHANGE(IDC_COMBO8, &CLab4Dlg::OnCbnSelchangeCombo8)
END_MESSAGE_MAP()


// CLab4Dlg message handlers

BOOL CLab4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// Initializeza cu 0 nr. de DVD-uri
	NR_DVD = 0;
		

	//tree control
	HTREEITEM hItem, hCar;


	hItem = TREE.InsertItem(L"Categorii", TVI_ROOT);
	

	/*.InsertItem(L"BH-733", hCar);
	TREE.InsertItem(L"SD-397", hCar);
	TREE.InsertItem(L"JU-538", hCar);
	TREE.InsertItem(L"DI-285", hCar);
	TREE.InsertItem(L"AK-830", hCar);
	hCar = TREE.InsertItem(L"Compact", hItem);
	TREE.InsertItem(L"HG-490", hCar);
	TREE.InsertItem(L"PE-473", hCar);
	hCar = TREE.InsertItem(L"Standard", hItem);
	TREE.InsertItem(L"SO-398", hCar);
	TREE.InsertItem(L"DF-438", hCar);
	TREE.InsertItem(L"IS-833", hCar);
	hCar = TREE.InsertItem(L"Full Size", hItem);
	TREE.InsertItem(L"PD-304", hCar);
	hCar = TREE.InsertItem(L"Mini Van", hItem);
	TREE.InsertItem(L"ID-497", hCar);
	TREE.InsertItem(L"RU-304", hCar);
	TREE.InsertItem(L"DK-905", hCar);
	hCar = TREE.InsertItem(L"SUV", hItem);
	TREE.InsertItem(L"FE-948", hCar);
	TREE.InsertItem(L"AD-940", hCar);
	hCar = TREE.InsertItem(L"Truck", hItem);
	TREE.InsertItem(L"HD-394", hCar);*/







	// TODO: Add extra initialization here
	Lista.AddString((LPCWSTR)L"Pulp Fiction");
	Lista.AddString((LPCWSTR)L"Avatar 2");
	Lista.AddString((LPCWSTR)L"The Avengers:Infinity War");
	Lista.AddString((LPCWSTR)L"Generic Western 2");
	Lista.AddString((LPCWSTR)L"American Psycho");
	Lista.AddString((LPCWSTR)L"The Wolf of Wallstreet");
	return TRUE; // return TRUE  unless you set the focus to a control
}

void CLab4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab4Dlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	UpdateData();


	if (Zile.GetCurSel() == CB_ERR)
		Zile.SetCurSel(0);
	if (moneda.GetCurSel() == CB_ERR)
		moneda.SetCurSel(0);
	if (categorie.GetCurSel() == CB_ERR)
		categorie.SetCurSel(0);
	if (calitate_Film.GetCurSel() == CB_ERR)
		calitate_Film.SetCurSel(0);
	if (calitate_Audio.GetCurSel() == CB_ERR)
		calitate_Audio.SetCurSel(0);
	if (recording_type.GetCurSel() == CB_ERR)
		recording_type.SetCurSel(0);


	DOUBLE Fhd = 1;
	DOUBLE Shd = 1;
	DOUBLE ZileSale = 1;
	if (calitate_Film.GetCurSel() == 3)
		Fhd = 1.5; 
	if (calitate_Film.GetCurSel() == 4)
		Fhd = 2;

	if (recording_type.GetCurSel() == 1)
		Shd = 1.5;

	if (Zile.GetCurSel() >= 1)
		ZileSale = 0.6;

	if (moneda.GetCurSel() == 0) {
		Total = ((DOUBLE)Zile.GetCurSel() + 1) *ZileSale * Pret * (DOUBLE)Lista.GetSelCount() * ( ((DOUBLE)calitate_Film.GetCurSel()+1) * 0.34) * Fhd *
			(((DOUBLE)calitate_Audio.GetCurSel()+1) * 0.5) * ((DOUBLE)recording_type.GetCurSel()+1) * Shd  * (Reducere ? 0.75 : 1);
		
	}
	else {

		Total = ((DOUBLE)Zile.GetCurSel() + 1) * ZileSale * Pret * (DOUBLE)Lista.GetSelCount() * (((DOUBLE)calitate_Film.GetCurSel() + 1) * 0.34) * Fhd *
			(((DOUBLE)calitate_Audio.GetCurSel() + 1) * 0.5) * ((DOUBLE)recording_type.GetCurSel() + 1) * Shd * (Reducere ? 0.75 : 1) * 4.92;
		
	}
	UpdateData(FALSE);

Text_Lei = "Lei";
UpdateData(TRUE);

}

void CLab4Dlg::OnLbnSelchangeList()
{

	

	NR_DVD = Lista.GetSelCount();
	Total_DVD = NR_DVD;

	UpdateData(FALSE);
}



void CLab4Dlg::OnCbnSelchangeCombo6()
{

	if (categorie.GetCurSel() == 0)
	{
		while (Lista.GetCount() > 0)
		{
			int i = 0;
			Lista.DeleteString(i);
			i++;
		}

		Lista.AddString((LPCWSTR)L"Pulp Fiction");
		Lista.AddString((LPCWSTR)L"Avatar 2");
		Lista.AddString((LPCWSTR)L"The Avengers:Infinity War");
		Lista.AddString((LPCWSTR)L"Generic Western 2");
		Lista.AddString((LPCWSTR)L"American Psycho");
		Lista.AddString((LPCWSTR)L"The Wolf of Wallstreet");

		calitate_Film.ShowWindow(SW_SHOW);
	}



	if (categorie.GetCurSel() == 1)
	{
		while (Lista.GetCount() > 0)
		{
			int i = 0;
			Lista.DeleteString(i);
			i++;
		}

		Lista.AddString((LPCWSTR)L"Popular Video Example");
		Lista.AddString((LPCWSTR)L"Some Video");
		Lista.AddString((LPCWSTR)L"NatGeo elephants video");
		Lista.AddString((LPCWSTR)L"Some Video2");

		calitate_Film.ShowWindow(SW_SHOW);
	}

	if (categorie.GetCurSel() == 2)
	{
		while (Lista.GetCount() > 0)
		{
			int i = 0;
			Lista.DeleteString(i);
			i++;
		}

		Lista.AddString((LPCWSTR)L"Popular Song Example");
		Lista.AddString((LPCWSTR)L"Album 1");
		Lista.AddString((LPCWSTR)L"Animal Sounds");
		
		calitate_Film.ShowWindow(SW_HIDE);

	}


}

void CLab4Dlg::OnCbnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
}


void CLab4Dlg::OnCbnSelchangeCombo4()
{
	// TODO: Add your control notification handler code here
}


void CLab4Dlg::OnEnChangeTotal2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLab4Dlg::OnBnClickedCalculeaza2()  // HERE <<<<<<<<<<<<<<----
{

	HTREEITEM hItem, hChildItem;
	HTREEITEM ROOT = TREE.GetRootItem();

	CString Result;
	CString ResultChild;
	Add_Categorie.GetLBText(Add_Categorie.GetCurSel(),Result);
	Add_CategorieItem.GetLBText(Add_CategorieItem.GetCurSel(), ResultChild);

	hItem = TREE.InsertItem(Result, ROOT);
	hChildItem= TREE.InsertItem(ResultChild, hItem);

	UpdateData();



}


void CLab4Dlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CLab4Dlg::OnEnChangePret()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLab4Dlg::OnTvnSelchangedTree2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CLab4Dlg::OnCbnSelchangeCombo7()
{

	if (Add_Categorie.GetCurSel() == 0) {  //Film

		
		while (Add_CategorieItem.GetCount() > 0)
		{
			int i = 0;
			Add_CategorieItem.DeleteString(i);
			i++;
		}

		Add_CategorieItem.AddString(L"Awesome Movie 2");
		Add_CategorieItem.AddString(L"A Quiet Place");
		Add_CategorieItem.AddString(L"6th Sense");


	}

	if (Add_Categorie.GetCurSel() == 1) {  //Video

		while (Add_CategorieItem.GetCount() > 0)
		{
			int i = 0;
			Add_CategorieItem.DeleteString(i);
			i++;
		}


		Add_CategorieItem.AddString(L"Awesome Video 2");
		Add_CategorieItem.AddString(L"Short Plant Documentary");
		


	}

	if (Add_Categorie.GetCurSel() == 2) {  //Audio

		while (Add_CategorieItem.GetCount() > 0)
		{
			int i = 0;
			Add_CategorieItem.DeleteString(i);
			i++;
		}

		
		Add_CategorieItem.AddString(L"MC Escher Song");
		


	}






}


void CLab4Dlg::OnCbnSelchangeCombo8()
{
	
}
