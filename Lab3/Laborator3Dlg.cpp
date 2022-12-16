
// Laborator3Dlg.cpp : implementation file
//

#include <cmath>

#include "pch.h"
#include "framework.h"
#include "Laborator3.h"
#include "Laborator3Dlg.h"
#include "afxdialogex.h"

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


// CLaborator3Dlg dialog



CLaborator3Dlg::CLaborator3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LABORATOR3_DIALOG, pParent)
	, A(0)
	, B(0)
	, Operatie(0)
	, Text(_T(""))
	, Rezultat(0)
	, inputN(0)
	, inputPrimulNumar(0)
	, inputAlDoileaNumar(0)
	, operatieTema(0)
	, valoareRezultat(0)
	, outputRezultat(_T("Rezultatul operatiei in Zn este:"))
	, Barstart(FALSE)
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_B, B);
	DDX_Radio(pDX, IDC_OPERATIE1, Operatie);
	DDX_Text(pDX, IDC_STATIC1, Text);
	DDX_Text(pDX, IDC_EDIT3, Rezultat);
	DDX_Text(pDX, IDC_INPUT_N, inputN);
	DDX_Text(pDX, IDC_INPUT_NUMAR_1, inputPrimulNumar);
	DDX_Text(pDX, IDC_INPUT_NUMAR_2, inputAlDoileaNumar);
	DDX_Radio(pDX, IDC_OPERATIE_ADUNARE, operatieTema);
	DDX_Text(pDX, IDC_OUTPUT_REZULTAT, valoareRezultat);
	DDX_Text(pDX, IDC_TEXT_REZULTAT, outputRezultat);
}

BEGIN_MESSAGE_MAP(CLaborator3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CLaborator3Dlg::OnBnClickedCalculeaza)
	ON_BN_CLICKED(IDC_BUTTON_CALCULEAZA, &CLaborator3Dlg::OnBnClickedButtonCalculeaza)
	

	
	//ON_NOTIFY(NM_CUSTOMDRAW, Progressbar1, &CLaborator3Dlg::OnNMCustomdrawProgressbar1)
	ON_BN_CLICKED(IDCANCEL, &CLaborator3Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CLaborator3Dlg::OnBnClickedButton3)
	ON_STN_CLICKED(IDC_TEXT_REZULTAT, &CLaborator3Dlg::OnStnClickedTextRezultat)
	ON_EN_CHANGE(IDC_A, &CLaborator3Dlg::OnEnChangeA)
END_MESSAGE_MAP()


// CLaborator3Dlg message handlers

BOOL CLaborator3Dlg::OnInitDialog()
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

void CLaborator3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLaborator3Dlg::OnPaint()
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
HCURSOR CLaborator3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLaborator3Dlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	switch (Operatie) {
	case 0:
		Rezultat = A + B;
		Text = "A+B=";
		Barstart = TRUE;

		break;
	case 1:
		Rezultat = A - B;
		Text = "A-B=";
		Barstart = TRUE;
		break;
	case 2:
		Rezultat = A * B;
		Text = "A*B=";
		Barstart = TRUE;
		break;
	case 3:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B;
		Barstart = TRUE;
		Text = "A/B=";
		break;
	case 4:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = floor(A / B);
		Barstart = TRUE;
		Text = "[A/B]=";
		break;
	case 5:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (A / B) - floor(A / B);
		Text = "{A/B}=";
		Barstart = TRUE;
		break;
	case 6:
		Rezultat = fmod(A, B);
		Barstart = TRUE;
		Text = "A%B=";
		break;
	default: AfxMessageBox((LPCWSTR)L"Nu s-a optat pentru o operatie");
	}
	UpdateData(FALSE);
}

void CLaborator3Dlg::OnBnClickedButtonCalculeaza()
{
	UpdateData();
	CString textOutput;
	switch (operatieTema)
	{
	case 0:
		valoareRezultat = (inputPrimulNumar + inputAlDoileaNumar) % inputN;
		textOutput.AppendFormat((LPCWSTR)_T("Rezultatul adunarii in Z%d este: "), inputN);
		outputRezultat = textOutput;
		break;
	case 1:
		valoareRezultat = (inputPrimulNumar * inputAlDoileaNumar) % inputN;
		textOutput.AppendFormat((LPCWSTR)_T("Rezultatul inmultirii in Z%d este: "), inputN);
		outputRezultat = textOutput;
		break;
	default: AfxMessageBox((LPCWSTR)_T("Nu s-a optat pentru o operatie"));
	}
	UpdateData(FALSE);
}


void CLaborator3Dlg::OnBnClickedSplit1()
{
	CString text;

}


void CLaborator3Dlg::OnBnClickedMfcmenubutton2()
{
	// TODO: Add your control notification handler code here
}




void CLaborator3Dlg::OnNMCustomdrawProgressbar1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if (Barstart == TRUE) {

		int duration = rand();
		
		pNMHDR->code = CDDS_PREPAINT;
		
		Barstart = FALSE;

		

	}

}


void CLaborator3Dlg::OnBnClickedCancel()
{
	UpdateData();

	//if (Text != _T("")) {
	Text = " asda";
			// _T("Operatia de ") + Text + _T("A fost incheiata");
		
	//}
	


	
}


void CLaborator3Dlg::OnBnClickedButton3()
{
	CDialogEx::OnCancel();
	// TODO: Add your control notification handler code here
}


void CLaborator3Dlg::OnStnClickedTextRezultat()
{
	// TODO: Add your control notification handler code here
}


void CLaborator3Dlg::OnEnChangeA()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
