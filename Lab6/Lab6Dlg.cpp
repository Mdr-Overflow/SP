
// Lab6Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab6.h"
#include "Lab6Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <algorithm>
#include <gdiplus.h>
#include <stdio.h>
#include <windows.h>
#include <strsafe.h>
using namespace Gdiplus;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define N 5

#define L1 BITMAP "1.bmp"

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


// CLab6Dlg dialog



CLab6Dlg::CLab6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB6_DIALOG, pParent)
	, NewNumber(0)
	, Volum(0)
	, Medie(0)
	, Dispersie(0)
	, m_nCrt(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Textt);
}
	

BEGIN_MESSAGE_MAP(CLab6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INAINTE, &CLab6Dlg::OnBnClickedInainte)
	ON_BN_CLICKED(IDC_INAPOI, &CLab6Dlg::OnBnClickedInapoi)
	ON_BN_CLICKED(IDC_EXIT, &CLab6Dlg::OnBnClickedExit)

END_MESSAGE_MAP()


// CLab6Dlg message handlers

BOOL CLab6Dlg::OnInitDialog()
{
	
	int m_nCrt = 1;
	ActualizareFoto();


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

void CLab6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab6Dlg::OnPaint()
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
HCURSOR CLab6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Helper function
HRESULT CLab6Dlg::PropertyTypeFromWORD(WORD index, WCHAR* string, UINT maxChars)
{
	HRESULT hr = E_FAIL;

	WCHAR* propertyTypes[] = {
	   L"Nothing",                   // 0
	   L"PropertyTagTypeByte",       // 1
	   L"PropertyTagTypeASCII",      // 2
	   L"PropertyTagTypeShort",      // 3
	   L"PropertyTagTypeLong",       // 4
	   L"PropertyTagTypeRational",   // 5
	   L"Nothing",                   // 6
	   L"PropertyTagTypeUndefined",  // 7
	   L"Nothing",                   // 8
	   L"PropertyTagTypeSLONG",      // 9
	   L"PropertyTagTypeSRational" }; // 10

	hr = StringCchCopyW(string, maxChars, propertyTypes[index]);
	CString s;
	s.Format(hr);
	((CEdit*)GetDlgItem(IDC_EDIT5))->SetWindowTextW(s);
	return hr;
}



void CLab6Dlg::ActualizareFoto()
{

	
	// TODO: Add your implementation code here.
	CString sTitlu;
	sTitlu.Format((LPCWSTR)L"Album de Fotografii - #%d", m_nCrt);
	SetWindowText(sTitlu);
	//incarcare imagine
	static CBitmap bmpFoto;
	if (bmpFoto.m_hObject)bmpFoto.DeleteObject();
	bmpFoto.LoadBitmap(m_nCrt);
	((CStatic*)GetDlgItem(IDC_FOTO))->SetBitmap(bmpFoto);


	//activari/dezactivari butoane
	GetDlgItem(IDC_INAINTE)->EnableWindow(m_nCrt < N ? TRUE : FALSE);
	GetDlgItem(IDC_INAPOI)->EnableWindow(m_nCrt > 1 ? TRUE : FALSE);

	/// GET PROP

	// Initialize GDI+
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	UINT  size = 0;
	UINT  count = 0;

	#define MAX_PROPTYPE_SIZE 30
	WCHAR strPropertyType[MAX_PROPTYPE_SIZE] = L"";

	Bitmap* pBitmap = Bitmap::FromHBITMAP(bmpFoto, NULL);

	pBitmap->GetPropertySize(&size, &count);
	printf("There are %d pieces of metadata in the file.\n\n", count);

	// GetAllPropertyItems returns an array of PropertyItem objects.
	// Allocate a buffer large enough to receive that array.
	PropertyItem* pPropBuffer = (PropertyItem*)malloc(size);

	// Get the array of PropertyItem objects.
	pBitmap->GetAllPropertyItems(size, count, pPropBuffer);

	// For each PropertyItem in the array, display the id, type, and length.
	for (UINT j = 0; j < count; ++j)
	{
		// Convert the property type from a WORD to a string.
		PropertyTypeFromWORD(
			pPropBuffer[j].type, strPropertyType, MAX_PROPTYPE_SIZE);

		printf("Property Item %d\n", j);
		printf("  id: 0x%x\n", pPropBuffer[j].id);
		wprintf(L"  type: %s\n", strPropertyType);
		printf("  length: %d bytes\n\n", pPropBuffer[j].length);
	}

	free(pPropBuffer);

	GdiplusShutdown(gdiplusToken);

	////////////////////////////////////// get Data

	if (m_nCrt == 1) {
		
		((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"12/12/2000");
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(L"Poza");
		((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(L"Compoziite Artistica");

	}

	if (m_nCrt == 2) {

		((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"12/12/2001");
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(L"Blie");
		((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(L"Compoziite Artistica 2");

	}
	if (m_nCrt == 3) {

		((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"12/12/2002");
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(L"Fotografie");
		((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(L"Compoziite Artistica");

	}
	if (m_nCrt == 4) {

		((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"12/12/2003");
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(L"O poza");
		((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(L"Compoziite Artistica 3");

	}

	if (m_nCrt == 5) {

		((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"12/12/2004");
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(L"Cea mai poza");
		((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(L"Compoziite Artistica");

	}


} // main










void CLab6Dlg::OnBnClickedInainte()
{
	// TODO: Add your control notification handler code here
	if (m_nCrt < N)
	{
		m_nCrt++;
		ActualizareFoto();
	}
}
void CLab6Dlg::OnBnClickedInapoi()
{
	// TODO: Add your control notification handler code here
	if (m_nCrt > 1)
	{
		m_nCrt--;
		ActualizareFoto();
	}
}

void CLab6Dlg::OnBnClickedExit() {
	EndDialog(-1);
}