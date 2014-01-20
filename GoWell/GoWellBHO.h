// GoWellBHO.h : Declaration of the CGoWellBHO

#pragma once
#include "resource.h"       // main symbols



#include "GoWell_i.h"

// This file defines interface identifiers for IWebBrowser2 and the events that are used later in the project.
#include <shlguid.h>     // IID_IWebBrowser2, DIID_DWebBrowserEvents2, etc

// Defines the dispatch IDs for browser events.
#include <exdispid.h> // DISPID_DOCUMENTCOMPLETE, etc.

#include <mshtml.h>         // DOM interfaces

#include "JsInjector.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CGoWellBHO

class ATL_NO_VTABLE CGoWellBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGoWellBHO, &CLSID_GoWellBHO>,
	public IObjectWithSiteImpl<CGoWellBHO>,
	public IDispatchImpl<IGoWellBHO, &IID_IGoWellBHO, &LIBID_GoWellLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  indiciate that we want to handle events defined by the DWebBrowserEvents2 interface by adding a class 
	// definition for IDispEventImpl, which provides an easy and safe alternative to Invoke for handling events. 
	// IDispEventImpl works in conjunction with an event sink map to route events to the appropriate handler function.
	public IDispEventImpl<1, CGoWellBHO, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1>
{
public:
	CGoWellBHO() 
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GOWELLBHO)

DECLARE_NOT_AGGREGATABLE(CGoWellBHO)

BEGIN_COM_MAP(CGoWellBHO)
	COM_INTERFACE_ENTRY(IGoWellBHO)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ATL macros that route the event to a new OnDocumentComplete event handler method, which takes the same arguments, 
// in the same order, as defined by the DocumentComplete event.
// The number supplied to the SINK_ENTRY_EX macro (1) refers to the first parameter of the IDispEventImpl class 
// definition and is used to distinguish between events from different interfaces, if necessary. 
// Also note that you cannot return a value from the event handler; that's OK because Internet Explorer ignores values 
// returned from Invoke anyway.

BEGIN_SINK_MAP(CGoWellBHO)
    SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOCUMENTCOMPLETE, OnDocumentComplete)
END_SINK_MAP()

    // DWebBrowserEvents2
    void STDMETHODCALLTYPE OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL); 




	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//The STDMETHOD macro is an ATL convention that marks the method as virtual and ensures that it has the right calling convention
	// for the public COM interface. It helps to demarcate COM interfaces from other public methods that may exist on the class. 
	// The STDMETHODIMP macro is likewise used when implementing the member method.

	STDMETHOD(SetSite)(IUnknown *pUnkSite);

public:


private:

	//A member variable to store the browser site
    CComPtr<IWebBrowser2>  m_spWebBrowser;

	//A member variable to track whether the object has established a connection with the browser.
	BOOL m_fAdvised; 

	// method to contain the C++ implementation of the JavaScript
	void RemoveImages(IHTMLDocument2 *pDocument);

	// My JS Injector
	JsInjector m_jsInjector;


};

OBJECT_ENTRY_AUTO(__uuidof(GoWellBHO), CGoWellBHO)
