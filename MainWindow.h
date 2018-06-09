#pragma once

#include "stdafx.h"
class MainWindow : public WindowImplBase, public INotifyUI {

public:
	virtual CDuiString GetSkinFolder() override;

	virtual CDuiString GetSkinFile() override;

	virtual LPCTSTR GetResourceID() const
	{
		return MAKEINTRESOURCE(IDR_ZIPRES1);
	};

	virtual UILIB_RESOURCETYPE GetResourceType() const
	{
		return UILIB_ZIPRESOURCE;
	};

	virtual LPCTSTR GetWindowClassName(void) const override;

	virtual void InitWindow() override;

	virtual void    Notify(TNotifyUI& msg);

	virtual void OnFinalMessage(HWND hWnd);

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	/*virtual CDuiString GetZIPFileName() const;*/
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	void OnPrepare();

private:
	void CloseWindow();

private:
	CButtonUI* m_pBtnClose;
	CButtonUI* m_pBtnGuanjiaLink;
};