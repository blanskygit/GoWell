// GoWellBHO.cpp : Implementation of CGoWellBHO

#include "stdafx.h"
#include "GoWellBHO.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To connect the event handler to the browser through the event map, call DispEventAdvise during the processing of SetSite. 
// Likewise, use DispEventUnadvise to break the connection.

STDMETHODIMP CGoWellBHO::SetSite(IUnknown* pUnkSite)
{
    if (pUnkSite != NULL)
    {
        // Cache the pointer to IWebBrowser2.
        HRESULT hr = pUnkSite->QueryInterface(IID_IWebBrowser2, (void **)&m_spWebBrowser);
        if (SUCCEEDED(hr))
        {
            // Register to sink events from DWebBrowserEvents2.
            hr = DispEventAdvise(m_spWebBrowser);
            if (SUCCEEDED(hr))
            {
                m_fAdvised = TRUE;
            }
        }
    }
    else
    {
        // Unregister event sink.
        if (m_fAdvised)
        {
            DispEventUnadvise(m_spWebBrowser);
            m_fAdvised = FALSE;
        }

        // Release cached pointers and other resources here.
        m_spWebBrowser.Release();
    }

    // Call base class implementation.
    return IObjectWithSiteImpl<CGoWellBHO>::SetSite(pUnkSite);
}


/**
// Simple OnDocumentComplete event handler.
void STDMETHODCALLTYPE CGoWellBHO::OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL)
{
    // Retrieve the top-level window from the site.
    HWND hwnd;
    HRESULT hr = m_spWebBrowser->get_HWND((LONG_PTR*)&hwnd);
    if (SUCCEEDED(hr))
    {
        // Output a message box when page is loaded.
        MessageBox(hwnd, L"GoWell Rules Again555!", L"BHO", MB_OK);
    }
}
*/



///////////////////////////////////////////////////////////////////////////////////////////////
// The OnDocumentComplete event handler now does two new things. First, it compares the cached 
// WebBrowser pointer to the object for which the event is fired; if they are equal, the event 
// is for the top-level window and the document is fully loaded. Second, it retrieves a pointer 
// to the document object and passes it to RemoveImages.

void STDMETHODCALLTYPE CGoWellBHO::OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL)
{
    HRESULT hr = S_OK;

    // Query for the IWebBrowser2 interface.
    CComQIPtr<IWebBrowser2> spTempWebBrowser = pDisp;

    // Is this event associated with the top-level browser?
    if (spTempWebBrowser && m_spWebBrowser &&
        m_spWebBrowser.IsEqualObject(spTempWebBrowser))
    {
        // Get the current document object from browser...
        CComPtr<IDispatch> spDispDoc;
        hr = m_spWebBrowser->get_Document(&spDispDoc);
        if (SUCCEEDED(hr))
        {
            // ...and query for an HTML document.
            CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
            if (spHTMLDoc != NULL)
            {
                // Finally, remove the images.
                RemoveImages(spHTMLDoc);
				//m_jsInjector.injectJs(m_spWebBrowser, spHTMLDoc);
				m_jsInjector.injectJs(spHTMLDoc);
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interacting with the DOM in C++ is more verbose than JavaScript, but the code flow is essentially the same.
// The preceding code iterates over each item in the images collection. In script, it is clear whether the 
// collection element is being accessed by ordinal or by name; however, in C++ you must manually disambiguate 
// these arguments by passing an empty variant. We again rely on an ATL helper class—this time CComVariant—to 
// minimize the amount of code that we have to write.

void CGoWellBHO::RemoveImages(IHTMLDocument2* pDocument)
{
    CComPtr<IHTMLElementCollection> spImages;

    // Get the collection of images from the DOM.
    HRESULT hr = pDocument->get_images(&spImages);
    if (hr == S_OK && spImages != NULL)
    {
        // Get the number of images in the collection.
        long cImages = 0;
        hr = spImages->get_length(&cImages);
        if (hr == S_OK && cImages > 0)
        {
            for (int i = 0; i < cImages; i++)
            {
                CComVariant svarItemIndex(i);
                CComVariant svarEmpty;
                CComPtr<IDispatch> spdispImage;

                // Get the image out of the collection by index.
                hr = spImages->item(svarItemIndex, svarEmpty, &spdispImage);
                if (hr == S_OK && spdispImage != NULL)
                {
                    // First, query for the generic HTML element interface...
                    CComQIPtr<IHTMLElement> spElement = spdispImage;

                    if (spElement)
                    {
                        // ...then ask for the style interface.
                        CComPtr<IHTMLStyle> spStyle;
                        hr = spElement->get_style(&spStyle);

                        // Set display="none" to hide the image.
                        if (hr == S_OK && spStyle != NULL)
                        {
                            static const CComBSTR sbstrNone(L"none");
                            spStyle->put_display(sbstrNone);
                        }
                    }
                }
            }
        }
    }
}

// CGoWellBHO


