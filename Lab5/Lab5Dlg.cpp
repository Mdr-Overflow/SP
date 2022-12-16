
// Lab5Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab5.h"
#include "Lab5Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CLab5Dlg dialog



CLab5Dlg::CLab5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB5_DIALOG, pParent)
	, NewNumber(0)
	, Volum(0)
	, Medie(0)
	, Dispersie(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DATA, NewNumber);
	DDX_Text(pDX, IDC_VOLUM, Volum);
	DDX_Text(pDX, IDC_MEDIE, Medie);
	DDX_Text(pDX, IDC_DISPERSIE, Dispersie);

	DDX_Control(pDX, IDC_LIST, Serie);
}

BEGIN_MESSAGE_MAP(CLab5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CLab5Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_CALCULEAZA, &CLab5Dlg::OnBnClickedCalculeaza)
	ON_BN_CLICKED(IDC_CAUTAUNSORT, &CLab5Dlg::OnBnClickedCautaunsort)
	ON_BN_CLICKED(IDC_RMDUBLCATE, &CLab5Dlg::OnBnClickedRmdublcate)
	ON_BN_CLICKED(IDC_CAUTSORT, &CLab5Dlg::OnBnClickedCautsort)
	ON_BN_CLICKED(IDC_SORT, &CLab5Dlg::OnBnClickedSort)
END_MESSAGE_MAP()


// CLab5Dlg message handlers

BOOL CLab5Dlg::OnInitDialog()
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab5Dlg::OnPaint()
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
HCURSOR CLab5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab5Dlg::OnBnClickedAdd()
{
	if (Volum > MAXX)
	{
		CString Text;
		Text.Format((LPCWSTR)L"Seria de date are maxim %d de valori!", MAXX);
		AfxMessageBox(Text);
		return;
	}

	CString Data;
	GetDlgItemText(IDC_DATA, Data);
	((CListBox*)GetDlgItem(IDC_LIST))->AddString(Data);

	SerieLista[Volum++] = (double)wcstod(Data, NULL);
	SetDlgItemInt(IDC_VOLUM, Volum +1);

}


void CLab5Dlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	double Medie = 0, Disp = 0;

	for (int i = 0; i < Volum; i++)
		Medie += SerieLista[i];

	Medie /= Volum;
	for (int i = 0; i < Volum; i++)

		Disp += pow(SerieLista[i] - Medie, 2);

	Disp /= pow((double)Volum, 2);
	CString Text;
	Text.Format((LPCWSTR)L"%.2lf", Medie);
	SetDlgItemText(IDC_MEDIE, Text);

	Text.Format((LPCWSTR)L"%.2lf", Disp);
	SetDlgItemText(IDC_DISPERSIE, Text);

	double  Minim = 0, Maxim = 0;
	Minim = SerieLista[0];
	Maxim = SerieLista[0];
	for (int i = 1; i < Volum; i++) {
		if (Minim > SerieLista[i]) {
			Minim = SerieLista[i];
		}
		if (Maxim < SerieLista[i]) {
			Maxim = SerieLista[i];
		}
	}

	Text.Format((LPCWSTR)L"%.2lf", Minim);
	SetDlgItemText(IDC_MINIM, Text);

	Text.Format((LPCWSTR)L"%.2lf", Maxim);
	SetDlgItemText(IDC_MAXIM, Text);

	Text.Format((LPCWSTR)L"%.2lf", Maxim-Minim);
	SetDlgItemText(IDC_AMPLITUDINE, Text);
}


void CLab5Dlg::OnBnClickedCautaunsort()
{
	// TODO: Add your control notification handler code here
	CString Data;
	GetDlgItemText(IDC_NRFINDUNSORT, Data);
	double nr = (double)wcstod(Data, NULL);
	for (int i = 0; i < Volum; i++) {
		if (SerieLista[i] == nr) {
			CString Text;
			Text.Format((LPCWSTR)L"Numarul %.2lf a fost gasit la index %d!", nr,i);
			AfxMessageBox(Text);
			return;
		}
	}

	CString Text;
	Text.Format((LPCWSTR)L"Numarul nu a fost gasit!");
	AfxMessageBox(Text);
}


void CLab5Dlg::OnBnClickedRmdublcate()
{
	// TODO: Add your control notification handler code here
	double newSerieLista[MAXX];
	for (int i = 0; i < Volum-1; i++) {
		for (int j = i+1; j < Volum; j++) {
			if (SerieLista[i] == SerieLista[j]) {
				for (int z = j; z < Volum-1; z++) {
					SerieLista[z] = SerieLista[z+1];
				}
				Volum--;
			}
		}
	}
	CString Data;

	((CListBox*)GetDlgItem(IDC_LIST))->ResetContent();
	for (int i = 0; i < Volum; i++) {
		Data.Format((LPCWSTR)L"%.2lf", SerieLista[i]);
		((CListBox*)GetDlgItem(IDC_LIST))->AddString(Data);
	}
	SetDlgItemInt(IDC_VOLUM, Volum+1);
}


void CLab5Dlg::OnBnClickedCautsort()
{
	// TODO: Add your control notification handler code here
	CString Data;
	GetDlgItemText(IDC_NRFINDSORT, Data);
	double nr = (double)wcstod(Data, NULL);
	int upperBound = Volum-1;
	int lowerBouwn = 0;
	int midle = (int)(upperBound+lowerBouwn) / 2;

	while (upperBound > lowerBouwn+1) {
		if (CopySerieLista[midle] == nr) {
			CString Text;
			Text.Format((LPCWSTR)L"Numarul %.2lf a fost gasit la index %d!", nr, midle);
			AfxMessageBox(Text);
			return;
		}
		else if (CopySerieLista[midle] < nr) {
			lowerBouwn = midle;
			midle = (int)(upperBound + lowerBouwn) / 2;
		}
		else {
			upperBound = midle;
			midle = (int)(upperBound + lowerBouwn) / 2;
		}
	}

	CString Text;
	Text.Format((LPCWSTR)L"Numarul nu a fost gasit!");
	AfxMessageBox(Text);
}


void CLab5Dlg::OnBnClickedSort()
{
	// TODO: Add your control notification handler code 
	for (int i = 0; i < Volum; i++) {
		CopySerieLista[i] = SerieLista[i];
	}
	std::sort(CopySerieLista, CopySerieLista + Volum);
	((CListBox*)GetDlgItem(IDC_SORTEDLIST))->ResetContent();


	CString Data;

	for (int i = 0; i < Volum; i++) {
		Data.Format((LPCWSTR)L"%.2lf", CopySerieLista[i]);
		((CListBox*)GetDlgItem(IDC_SORTEDLIST))->AddString(Data);
	}
}
