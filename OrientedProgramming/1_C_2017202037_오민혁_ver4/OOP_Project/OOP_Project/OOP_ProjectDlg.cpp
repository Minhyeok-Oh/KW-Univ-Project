
// OOP_ProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "afxdialogex.h"
#include "Board.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// COOPProjectDlg 대화 상자



COOPProjectDlg::COOPProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOP_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COOPProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COOPProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
//	ON_WM_MENUSELECT()
	ON_COMMAND(ID_32771, &COOPProjectDlg::On32771)
	ON_COMMAND(ID_32772, &COOPProjectDlg::On32772)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32773, &COOPProjectDlg::On32773)
	ON_COMMAND(ID_32774, &COOPProjectDlg::On32774)
END_MESSAGE_MAP()
int DragX1, DragY1, DragX2, DragY2, ColorSignal = 1, Turn = 0, Flag = 0, RotationSignal = 0;



// COOPProjectDlg 메시지 처리기
Board board;
BOOL COOPProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	SetWindowText(_T("2048 Game"));
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	LogFile.Open(_T("log.txt"), CFile::modeCreate | CFile::modeWrite);

	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COOPProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COOPProjectDlg::OnPaint()
{
	

	Invalidate(FALSE); // re paint

	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CPen MyPen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* Pen = dc.SelectObject(&MyPen);

	
	int size = 128; // block size
	int initialx1 = 0, initialy1 = 0, initialx2 = size, initialy2 = size;


	CBrush white(RGB(255, 255, 255)); CBrush yellow(RGB(255, 255, 0)); CBrush orange(RGB(255, 127, 0)); CBrush green(RGB(0, 255, 0)); CBrush blue(RGB(0, 0, 255));	CBrush gray(RGB(166, 166, 166));	CBrush pink(RGB(255, 0, 255));	CBrush cyan(RGB(0, 255, 255));	CBrush purple(RGB(128, 0, 128));	CBrush violet(RGB(112, 48, 160));	CBrush brown(RGB(207, 110, 54));	CBrush red(RGB(255, 0, 0));

	CFont font;
	font.CreatePointFont(300,_T("굴림체"));
	dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int x1 = initialx1 + x * size, x2 = initialx2 + x * size, y1 = initialy1 + y * size, y2 = initialy2 + y * size;
			Block* Current = board.SearchBlock(x, y);
			int Color = Current->GetNumber();
			////////////// ** Set Block Color ** ////////////
			dc.SelectObject(&white);
			if (ColorSignal == 1) {
				if (Color == 0)
					dc.SelectObject(&white);
				else if (Color == 2)
					dc.SelectObject(&yellow);
				else if (Color == 4)
					dc.SelectObject(&orange);
				else if (Color == 8)
					dc.SelectObject(&green);
				else if (Color == 16)
					dc.SelectObject(&blue);
				else if (Color == 32)
					dc.SelectObject(&gray);
				else if (Color == 64)
					dc.SelectObject(&pink);
				else if (Color == 128)
					dc.SelectObject(&cyan);
				else if (Color == 256)
					dc.SelectObject(&purple);
				else if (Color == 512)
					dc.SelectObject(&violet);
				else if (Color == 1024)
					dc.SelectObject(&brown);
				else if (Color == 2048)
					dc.SelectObject(&red);
			}
			dc.Rectangle(x1,y1,x2,y2); 
			// *** INPUT NUMBER TEXT ***/////////////////////////////// 
			if (Color == 0);
			else if (Color == 2) // Text Center | One Line | Vertical Center
				dc.DrawText(_T("2"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER  );
			else if (Color == 4)
				dc.DrawText(_T("4"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 8)
				dc.DrawText(_T("8"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 16)
				dc.DrawText(_T("16"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 32)
				dc.DrawText(_T("32"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 64)
				dc.DrawText(_T("64"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 128)
				dc.DrawText(_T("128"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 256)
				dc.DrawText(_T("256"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 512)
				dc.DrawText(_T("512"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 1024)
				dc.DrawText(_T("1024"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
			else if (Color == 2048)
				dc.DrawText(_T("2048"), CRect(x1, y1, x2, y2), DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		}
	}
	MyPen.DeleteObject();

	
	if (board.isWin() == 1) {
		if (MessageBox(L"Continue ?", L"WIN!!", MB_YESNO | MB_ICONEXCLAMATION | MB_ICONWARNING) == IDNO) {
			exit(1);
			DestroyWindow();
		}
	}
	else if (board.isLose() == 1) {
		if (MessageBox(L"Do you want new game ?", L"LOSE!!", MB_YESNO | MB_ICONSTOP) == IDNO) {
			DestroyWindow();
			exit(1);
		}
		else {
			board.ResetGame();
			OnPaint();
		}
		
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COOPProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COOPProjectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_UP:			
		if (board.Move('u')) {
			board.RandomBlock();
			Turn++;
			if (Flag == 1)
				board.OutLog(LogFile, Turn, 1);
		}
		break;
	case VK_DOWN:
		if (board.Move('d')) {
			board.RandomBlock();
			Turn++;
			if(Flag==1)
				board.OutLog(LogFile, Turn, 2);
		}
		break;
	case VK_RIGHT:
		if (board.Move('r')) {
			board.RandomBlock();
			Turn++;
			if(Flag==1)
				board.OutLog(LogFile, Turn, 3);
		}
		break;
	case VK_LEFT:
		if (board.Move('l')) {
			board.RandomBlock();
			Turn++;
			if(Flag==1)
				board.OutLog(LogFile, Turn, 4);
		}
		break;
	}
	
	
	OnPaint();

	
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL COOPProjectDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam) {
			UINT nRepCnt = (UINT)((pMsg->lParam) & 0x0000FFFF);
			UINT nFlags = (UINT)((pMsg->lParam) >> 16);
			this->OnKeyDown(pMsg->wParam, nRepCnt, nFlags);
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


//void COOPProjectDlg::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
//{
//	if (nFlags = MK_LBUTTON) {
//		if (nItemID == ID_32771) {
//			MessageBox(L"HI", L"HI", MB_OK);
//		}
//		else if (nItemID == ID_32772) {
//
//		}
//	}
//	
//	CDialogEx::OnMenuSelect(nItemID, nFlags, hSysMenu);
//	
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}


void COOPProjectDlg::On32771() // ColorSignal = 1
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ColorSignal = 1;
	OnPaint();
}


void COOPProjectDlg::On32772() // ColorSignal = 0
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ColorSignal = 0;
	OnPaint();
}


void COOPProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (point.x >= 0 && point.x <= 128 * 4 && point.y >= 0 && point.y <= 128 * 4) {
		DragX1 = point.x;
		DragY1 = point.y;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void COOPProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	DragX2 = point.x; DragY2 = point.y;
	if (DragX2 >= 0 && DragX2 <= 128 * 4 && DragX1 >= 0 && DragX1 <= 128 * 4 && DragY1 >= 0 && DragY1 <= 128 * 4 && DragY2 >= 0 && DragY2 <= 128 * 4) {
		if (DragX2 - DragX1 > 0) {
			board.Clockwise();
			Turn++;
			if (Flag == 1)
				board.OutLog(LogFile, Turn, 5);
			RedrawWindow();
		}
		else {
			board.Counterclockwise();
			Turn++;
			if (Flag == 1) {
				board.OutLog(LogFile, Turn, 6);
			}
			RedrawWindow();
		}
		
	}
	DragX1 = DragY1 = DragX2 = DragY2 = 0;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void COOPProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnMouseMove(nFlags, point);
}


void COOPProjectDlg::On32773() // create log file
{
	Flag = 1;
	OnPaint();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void COOPProjectDlg::On32774() // do not create log file
{
	Flag = 0;
	OnPaint();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
