var BrowserDetect = { 
    init: 
    function () {
        this.browser = this.searchString(this.dataBrowser) || "An unknown browser";
        this.version = this.searchVersion(navigator.userAgent) || this.searchVersion(navigator.appVersion) || "an unknown version";
        this.OS = this.searchString(this.dataOS) || "an unknown OS";
}, 
    searchString:
    function (d) {
        for (var a = 0; a < d.length; a++) {
            var b = d[a].string; var c = d[a].prop; this.versionSearchString = d[a].versionSearch || d[a].identity;
            if (b) { if (b.indexOf(d[a].subString) != -1) { return d[a].identity; } } else { if (c) { return d[a].identity; } } 
        } 
    },
    searchVersion:
    function (d) {
        var b = d.indexOf(this.versionSearchString);
        if (b == -1) { return; } var e;
        try { e = parseFloat(d.substring(b + this.versionSearchString.length + 1)); }
        catch (a) {
            var c = new RegExp("MSIE ([0-9]{1,}[.0-9]{0,})");
            if (c.exec(d) != null) { e = parseFloat(RegExp.$1); } 
        }
        return e;
    },

    dataBrowser: [  { string: navigator.userAgent, subString: "Chrome", identity: "Chrome" },
                    { string: navigator.userAgent, subString: "OmniWeb", versionSearch: "OmniWeb/", identity: "OmniWeb" },
                    { string: navigator.vendor, subString: "Apple", identity: "Safari", versionSearch: "Version" },
                    { prop: window.opera, identity: "Opera" },
                    { string: navigator.vendor, subString: "iCab", identity: "iCab" },
                    { string: navigator.vendor, subString: "KDE", identity: "Konqueror" },
                    { string: navigator.userAgent, subString: "Firefox", identity: "Firefox" },
                    { string: navigator.vendor, subString: "Camino", identity: "Camino" },
                    { string: navigator.userAgent, subString: "Netscape", identity: "Netscape" },
                    { string: navigator.userAgent, subString: "MSIE", identity: "Explorer", versionSearch: "MSIE" },
                    { string: navigator.userAgent, subString: "Gecko", identity: "Mozilla", versionSearch: "rv" },
                    { string: navigator.userAgent, subString: "Mozilla", identity: "Netscape", versionSearch: "Mozilla"}],

    dataOS: [   { string: navigator.platform, subString: "Win", identity: "Windows" },
                { string: navigator.platform, subString: "Mac", identity: "Mac" },
                { string: navigator.userAgent, subString: "iPhone", identity: "iPhone/iPod" },
                { string: navigator.platform, subString: "Linux", identity: "Linux"}]
};
BrowserDetect.init();
function _WGT_setLocalStore(b, f, a) {
    a = parseInt(a); if (!a || a == 0) { a = 100000000; }
    var e = new Date().getTime(); e += 3600 * 1000 * 24 * a;
    var g = f + "|||" + e;
    try { LCS_g_DataObject.setValue(b, g); }
    catch (d) {
        try { LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject.setValue(b, g); }
        catch (c) { } 
    }
} 
function _WGT_deleteLocalStore(a) {
    try { LCS_g_DataObject.setValue(a, "not set"); }
    catch (c) {
        try { LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject.setValue(a, "not set"); }
        catch (b) { } 
    } 
}
function _WGT_getLocalStore(a) {
    var f = new Date().getTime();
    var h;
    try { h = LCS_g_DataObject.getValue(a, "not set"); }
    catch (c) {
        try { h = LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject.getValue(a, "not set"); }
        catch (b) { } 
    }
    if (!h || h == "not set") { return null; }
    else {
        try {
            var i = h.split("|||"); var g = parseInt(i[1]);
            if (g < f) {
                try { LCS_g_DataObject.setValue(a, "not set"); }
                catch (c) {
                    try { LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject.setValue(a, "not set"); }
                    catch (b) { } 
                } return null;
            }
            else { return i[0]; } 
        }
        catch (d) { return null; } 
    } 
}
var LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_localScriptLoad = 
    function () {
        var a = document.createElement("script");
        if (document.location.href.indexOf("about:blank") == -1) {
            if (BrowserDetect.browser == "Chrome") { 
                a.src = "chrome-extension://jcmehbehjmelpfaipdkbfjfgbafjpfpj/webresources/main/js/loader.js"; }
            else {
                a.src = "//s3.amazonaws.com/www.secretwall.me/app/js/loader.js";
            }
            document.body.appendChild(a);
        } 
    };  