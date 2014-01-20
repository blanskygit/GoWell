#include "StdAfx.h"

#include <fstream>
#include <cerrno>
#include <comutil.h>

#include "JsInjector.h"

using namespace ATL;
using namespace std;

#define _S(a) \
    { HRESULT hr = (a); if (FAILED(hr)) return hr; } 

#define disp_cast(disp) \
    ((CComDispatchDriver&)(void(static_cast<IDispatch*>(disp)), reinterpret_cast<CComDispatchDriver&>(disp)))

struct ComInit {
    ComInit() { ::CoInitialize(NULL); }
    ~ComInit() { CoUninitialize(); }
};

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, (LPWSTR)buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}





JsInjector::JsInjector(void)
{
}


JsInjector::~JsInjector(void)
{
}



/*
int _tmain(int argc, _TCHAR* argv[])
{
    ComInit comInit;

    CComPtr<IWebBrowser2> ie;
    _S( ie.CoCreateInstance(L"InternetExplorer.Application", NULL, CLSCTX_LOCAL_SERVER) );
    _S( ie->put_Visible(VARIANT_TRUE) );
    CComVariant ve;
    _S( ie->Navigate2(&CComVariant(L"http://jsfiddle.net/"), &ve, &ve, &ve, &ve) );

    // wait for page to finish loading
    for (;;)
    {
        Sleep(250);
        READYSTATE rs = READYSTATE_UNINITIALIZED;
        ie->get_ReadyState(&rs);
        if ( rs == READYSTATE_COMPLETE )
            break;
    }
*/

/*
int JsInjector::injectJs(IHTMLDocument2* pDocument) 
{

    // inject __execScript into the main window

    // CComPtr<IDispatch> dispDoc;
    //_S( ie->get_Document(&dispDoc) );
    //CComPtr<IHTMLDocument2> htmlDoc;
    //_S( dispDoc->QueryInterface(&htmlDoc) );


	//ComInit comInit;


    //CComPtr<IHTMLWindow2> htmlWindow;
    //_S( pDocument->get_parentWindow(&htmlWindow) );

	IHTMLWindow2* pHtmlWindow;
	pDocument->get_parentWindow(&pHtmlWindow);

    //CComPtr<IDispatchEx> dispexWindow;
    //_S( htmlWindow->QueryInterface(&dispexWindow) );

	IDispatchEx* pDispexWindow;
	pHtmlWindow->QueryInterface(&pDispexWindow);

    //CComBSTR __execScript("__execScript");
    //CComBSTR __execScriptCode(L"(window.__execScript = function(exp) { return eval(exp); }, window.self)");

	BSTR __execScript = SysAllocString(L"__execScript");
	BSTR __execScriptCode = SysAllocString(L"(window.__execScript = function(exp) { return eval(exp); }, window.self)");


    DISPID dispid = -1;
    //_S( dispexWindow->GetDispID(CComBSTR("eval"), fdexNameCaseSensitive, &dispid) );
    //_S( disp_cast(dispexWindow).Invoke1(dispid, &CComVariant(__execScriptCode)) ); 

	pDispexWindow->GetDispID(SysAllocString(L"eval"), fdexNameCaseSensitive, &dispid);
	pDispexWindow->InvokeEx(dispid, &__execScriptCode);

    // inject __execScript into the child frame

    WCHAR szCode[1024];
    wsprintfW(szCode, L"document.all.tags(\"iframe\")[0].contentWindow.eval(\"%ls\")", __execScriptCode.m_str);

    dispid = -1;
    _S( dispexWindow->GetDispID(__execScript, fdexNameCaseSensitive, &dispid) );
    CComVariant vIframe;
    _S( disp_cast(dispexWindow).Invoke1(dispid, &CComVariant(szCode), &vIframe) ); // inject __execScript and return the iframe's window object
    _S( vIframe.ChangeType(VT_DISPATCH) );

    CComPtr<IDispatchEx> dispexIframe;
    _S( V_DISPATCH(&vIframe)->QueryInterface(&dispexIframe) );

    dispid = -1;
    _S( dispexIframe->GetDispID(__execScript, fdexNameCaseSensitive, &dispid) );
    _S( disp_cast(dispexIframe).Invoke1(dispid, &CComVariant("alert(document.URL)")) ); // call the code inside child iframe

	return 0;
}
*/

//int JsInjector::injectJs(IWebBrowser2* pWebBrowser, IHTMLDocument2* pDocument) 
int JsInjector::injectJs(IHTMLDocument2* pDocument) 
{
	IHTMLWindow2* pHtmlWindow;
	pDocument->get_parentWindow(&pHtmlWindow);

	 
     VARIANT vEmpty = {0};

	std::string fileName("C:\\testchat.js");
	std::string contents;
	int res = getFileContents(fileName.c_str(), contents);
	char errnoRes[12];
	string result = _itoa(res, errnoRes, 10);
	//contents = "alert(\"the js file retrieve rc = " + result + "\")";

	//return pHtmlWindow->execScript(SysAllocString(L"var script = document.createElement(\"script\");script.src = \"testchat.js\";document.body.appendChild(script);"), SysAllocString(L"javascript"),&vEmpty);
	

	//TCHAR NPath[MAX_PATH];
	//GetCurrentDirectory(MAX_PATH, NPath);
	
	//string currentDirectory = ExePath();
	//string currentDirectory((char*)NPath);

	//std::ifstream ifs("C:\\testchat.js");
    //std::string contents( (std::istreambuf_iterator<char>(ifs) ),
                       //(std::istreambuf_iterator<char>()    ) );

	/*
	HWND hwnd;
    HRESULT hr = pWebBrowser->get_HWND((LONG_PTR*)&hwnd);
    if (SUCCEEDED(hr))
    {
        // Output a message box when page is loaded.
        MessageBox(hwnd, _com_util::ConvertStringToBSTR(contents.c_str()), L"BHO", MB_OK);
    }
	*/

	//currentDirectory = "alert(\"the js file is " + contents + "\")";
	

	return pHtmlWindow->execScript(_com_util::ConvertStringToBSTR(contents.c_str()), SysAllocString(L"javascript"),&vEmpty);
	//return pHtmlWindow->execScript(SysAllocString(L"alert(\"JS Back Again!\")"), SysAllocString(L"javascript"),&vEmpty);
	//return pHtmlWindow->execScript(SysAllocString(L"var obj = new ActiveXObject(\"GoWell.JsInjector\");var myValue = obj.testJs2ExCall();alert(myValue);
}




int JsInjector::getFileContents(const char *filename, std::string& contents)
{
  std::ifstream in(filename, std::ios::in);
  if (in)
  {
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return contents.size();
  }
  //throw(errno);
  return 0;
}