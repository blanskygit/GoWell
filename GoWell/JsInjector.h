#pragma once


#include <tchar.h>
#include <ExDisp.h>
#include <mshtml.h>
#include <dispex.h>
#include <atlbase.h>
#include <atlcomcli.h>
#include <string>



class JsInjector
{


public:
	JsInjector(void);
	virtual ~JsInjector(void);

	// int injectJs(IWebBrowser2* pWebBrowser, IHTMLDocument2* pDocument);
	int injectJs(IHTMLDocument2* pDocument);

private:

	int getFileContents(const char *filename, std::string& contents);
};

