#include "MainWindow.h"

DuiLib::CDuiString MainWindow::GetSkinFolder()
{
	return _T("");
}

DuiLib::CDuiString MainWindow::GetSkinFile()
{
	return _T("MainWindow.xml");
}

LPCTSTR MainWindow::GetWindowClassName(void) const
{
	return _T("MainView");
}

//CDuiString MainWindow::GetZIPFileName() const
//{
//	return _T("Res.zip");
//}

void MainWindow::InitWindow()
{
	m_pBtnClose = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btnClose")));
	m_pBtnGuanjiaLink = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("GuanjiaLink")));
	__super::InitWindow();
}

void MainWindow::CloseWindow()
{
	this->Close();
	::PostQuitMessage(0);
}

void MainWindow::OnFinalMessage(HWND hWnd)
{
	__super::OnFinalMessage(hWnd);
	delete this;
}

CControlUI* MainWindow::CreateControl(LPCTSTR pstrClass)
{
	return __super::CreateControl(pstrClass);
}

void	MainWindow::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender->GetName() == _T("btnClose"))
		{
			CloseWindow();
		}
	}
}

void MainWindow::OnPrepare()
{

}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;

	if (uMsg == WM_CREATE)
	{
		m_PaintManager.Init(m_hWnd);

		CDialogBuilder builder;
		CControlUI* pRoot = builder.Create(_T("MainWindow.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml需要放到exe目录下
		ASSERT(pRoot && "Failed to parse XML");

		m_PaintManager.AttachDialog(pRoot);
		m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
		return lRes;
	}
	// 以下3个消息WM_NCACTIVATE、WM_NCCALCSIZE、WM_NCPAINT用于屏蔽系统标题栏
	else if (uMsg == WM_NCACTIVATE)
	{
		if (!::IsIconic(m_hWnd))
		{
			return (wParam == 0) ? TRUE : FALSE;
		}
	}
	else if (uMsg == WM_NCCALCSIZE)
	{
		return 0;
	}
	else if (uMsg == WM_NCPAINT)
	{
		return 0;
	}

	if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
	{
		return lRes;
	}

	return __super::HandleMessage(uMsg, wParam, lParam);
}