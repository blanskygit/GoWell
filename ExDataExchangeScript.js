//------------------------------------------------------------------
//	Attention, all variables and functions must have "LCS" prefix
//	or extremely extraordinary name to avoid intersection with page
//	variables.
//------------------------------------------------------------------
var LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject = new LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_DataExchageObject(); 					// Local data storage object.
//------------------------------------------------------------------
//	Data exchange object
//------------------------------------------------------------------
function LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_DataExchageObject() {
    // Storage for BHO interface.
    this.tool = null;

    // BHO interface.
    this.initTool = function (tool) {
        this.tool = tool;
        setTimeout("LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_localScriptLoad()", 0);
    };

    // Getting value from extension storage. If no value, defaultValue is returned.
    this.getValue = function (valueName, defaultValue) {
        var retVal = "";

        try {
            retVal = this.tool.getValue(valueName, defaultValue);
        }
        catch (LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_e) {
            if (LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_isDebugOn) alert("LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_DataExchageObject.getValue: " + LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_e.toString());
        }

        return retVal;
    }

    // Setting extension storage value.
    this.setValue = function (valueName, valueResult) {
        try {
            this.tool.setValue(valueName, valueResult);
        }
        catch (LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_e) {
            if (LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_isDebugOn) alert("LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_DataExchageObject.setValue: " + LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_e.toString());
        }
    }

    // Method for injecting remote script into a page
    this.injectRemoteScript = function (scriptURL) {
        alert("injectRemoteScript is not implemented for IE");
    }
}

function LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_initTool(tool) {
    LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_g_DataObject.initTool(tool);
}

function LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_checkInjectionDone() {
    return "LCS_2E19A0BC_BD92_4692_81D9_14706D1481AC_InjectionDone";
}
