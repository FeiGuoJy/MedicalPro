#include"MainWindow.h"
#include <exdisp.h>
#include <comdef.h>
#include "ControlEx.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	MainWindow* pFrame = new MainWindow();
	if( pFrame == NULL ) return 0;
	pFrame->Create(NULL, _T("MainView"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();//:ShowWindow(*pFrame, SW_SHOW); 
	
	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}