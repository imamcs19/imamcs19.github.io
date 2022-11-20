var TFtimeout = 15;
if (window.TF_FP_TIMER) TFtimeout = TF_FP_TIMER;
var TFticker = TFtimeout;
var TFdebug = false;
var TFonclick = null;
var TFaa, TFac, TFaw, TFacc, TFap;
var TFtohndlr = null;
window.onerror = err;

if (!window.TF_FP_LOGO) /* XXX Default logo here! */
	TF_FP_LOGO = "http://www.tribalfusion.com/img/topnav/logo.gif";

// This is a URL which loads the media but does not count the ad 
if (window.TF_FP_CACHEURL) {
if (TFdebug)
		alert("adurl " +TF_FP_CACHEURL);
	TFcacheURL = window.TF_FP_CACHEURL;
}
else {
if (TFdebug)
		alert("adurl " +TF_FP_ADURL);
	TFcacheURL = TF_FP_ADURL;
}

function err(msg, url, linenum) {
	if (TFdebug)
		alert("error occurred: " + msg + "url: " + url+ " line=" + linenum);
}

// allow these to be set up in a different file
var TF_getFPHdr, TF_getFPFtr, TF_getFPStatus, TF_getFPAltStatus;
if (window.TFgetFPHdr) {
	//console.debug("**** FPHDR**");
	TF_getFPHdr = TFgetFPHdr;
	TF_getFPFtr = TFgetFPFtr;
	TF_getFPStatus = TFgetFPStatus;
	TF_getFPAltStatus = TFgetFPAltStatus;
}
else {
	//console.debug("else");
	TF_getFPHdr = getFPHdr;
	TF_getFPFtr = getFPFtr;
	TF_getFPStatus = getFPStatus;
	TF_getFPAltStatus = getFPAltStatus;
}

function getFPHdr(logo, to) {
	return null;
}

function getFPFtr(logo, to) {
	//console.debug("get Footer");
	var s = '<table width="900">';
  s += '<col style="width:450" ><col style="width:425" ><col style="width:160" ><col style="width:160" ><tr>';  
  s += '<td><img src="' + logo + '"></td><td><strong>A D V E R T I S E M E N T</strong></td>';
  s += '<td><div id="TF_FP_STATUS">Your page is loading...</div></td>';
  s += '<td><a href="javascript:parent.TFreplayAd()">Replay Ad</a></td>';
  s += '</tr></table>';
  return s;
}

function getFPStatus(loaded, secs) {
	//console.debug("in fpstatus");
	if (!loaded) { return "Loading requested page...";}
	else return '<a href="javascript:parent.TFskipAd()">Skip Ad(' + secs + ')</a>';
}

function getFPAltStatus(loaded, secs) {
	return null;
}

function getAdHTML() {
	//console.debug("Adhtml");

	if (TFdebug) alert("getAdHTML start");

	var s = "";
	/*
	var s = '<html>';

	if (window.TF_FP_HFSTYLEURL) 
		s += '<head><link rel="stylesheet" href="' + TF_FP_HFSTYLEURL + 
			 '" type="text/css">';
	s += '<body onload="javascript:parent.adLoaded()">';
*/
	var hf = TF_getFPHdr(TF_FP_LOGO, TFticker);
	if (hf) 
		s += hf;

	s += '<iframe id="TFAA" border="0" onload="javascript:adLoaded()" '; 
	if (window.TF_FP_WIDTH && window.TF_FP_HEIGHT)
		s += '" width="' + TF_FP_WIDTH + '" height="' + TF_FP_HEIGHT + '" ';
	s += 'frameborder="no" scrolling="no" src="';
	s += TFcacheURL;
	s += '"><\/iframe>';

	var hf = TF_getFPFtr(TF_FP_LOGO, TFticker);
	if (hf != null) 
		s += hf;

	/*
	s += '</body></html>';
	*/
	if (TFdebug) alert("getAdHTML end");

	return s;
}

function getPreloadHTML(nextpage) {
	//nextpage="http://www.tribalfusion.com";
	//console.debug("get preload  " + nextpage);
	var s = '';
//	var s = '<html><body onload="javascript:parent.nextPageLoaded()">';
//	s += '<iframe id="TFAC" border="0" frameborder="no" scrolling="no" src="';
	s += '<iframe id="TFAC" onload="javascript:parent.nextPageLoaded()" border="0" frameborder="no" scrolling="no" src="';
	s += nextpage;
	s += '" style="display:block;height:0%" width="100%"><\/iframe>';
	return s;
}

function getPlayURLHTML() {
//	var s = '<html><body>';
	var s = '';
	s += '<img width="0" height="0" src="' + TF_FP_PLAYURL + 
		'?rand=' + new Date().getTime() + '">';
//		'?rand=' + new Date().getTime() + '"></body></html>';
	if (TFdebug) 
		alert("play html=" + s);
	return s;
}

function writeInvisDiv(id) {
	// Use document from enclosing frame?
	var f = document.createElement('DIV');
	f.id = id;
//	f.style.display = "block";
	f.style.display = "none";
	f.style.height = '100%';
	f.width = '100%';
	//f.style.width = '0%';
	f.marginwidth = f.marginheight = '0';

	var b = document.body;

	var n = null;
	n = document.getElementById(id) 
	// For Mozilla, a reload leaves these guys around

	b.insertBefore(f, b.childNodes[0]);
	
	return f;

}

function loadDivs() {
	if (TFdebug) alert("start load ad");

	TFacc = writeInvisDiv("TFACC");

	if (window.TF_FP_PLAYURL) {
		TFap = writeInvisDiv("TFAP");
	}

	TFaw = writeInvisDiv("TFAW");
	
//	if (navigator.appName=="Netscape")
//		window.onload = setupAd; 
		window.onload = setupAdTimer;
//	else
//		window.document.body.onload = setupAd;

	if (TFdebug) alert("done load ad");
}

function maximizeFrame(frame) {
	var cols = "";
	var sib = frame.previousSibling;
	while (sib) {
		cols += "*,"
		sib = sib.previousSibling;
	}
	cols += "100%";
	//frame.parentNode.cols = "*,*,*";
	frame.parentNode.cols = cols;
	frame.parentNode.rows = "";
}

function tf_hideNodes(node, fElement) {
//	alert("node.tagName=" + node.tagName + "/node.id=" + node.id);
	if (node.nodeType == 3) {
//		if (node.length < 20) return;
		// text node
		node.nodeValue = '';
		return false;
	}
	var hasOurFrame = false;
	var frame = null;
	if (node == fElement) {
//		alert("node == fElement");
		if (fElement.tagName == "FRAME") {
			maximizeFrame(fElement);
		}
		return true;
	}
	else {
		if (node.tagName == "FRAME" || node.tagName == "IFRAME") {
			frame = node;
			node = node.contentWindow.document.body;
		}
		if (node.hasChildNodes()) {
			for (var i = 0 ; i < node.childNodes.length; i++) {
				 var nodeHasOurFrame = tf_hideNodes(node.childNodes[i], fElement);
				 hasOurFrame = hasOurFrame || nodeHasOurFrame;
			}
		
		} 
//		else {
//			alert("node " + node.tagName + "," + node.id + " has no children");
//		}

		if (!hasOurFrame) {
//			alert(node.tagName);
			if (node.style)
				node.style.display = 'none';
			if (frame != null) 
				frame.style.display = 'none';
		}
		else {
			node.style.width = node.style.height = '100%';
			node.width = node.height = '100%';
			if (frame != null) {
				frame.style.width = frame.style.height = '100%';
				if (frame.tagName != "FRAME") {
					frame.height = frame.width = '100%';
				}
				if (frame.tagName == "FRAME") {
					maximizeFrame(frame);
				}
			}
		}

		return hasOurFrame;
	}
	return false;
}


function makeAdVisible(dst) {
	//console.debug("before changing source");
	TFaa.src = TF_FP_ADURL; 
//console.debug("make ad visible");
	// This is to preload the next page into the cache while the ad is visible
//	TFacc.src = 'javascript:parent.getPreloadHTML("' + dst + '")';
	TFacc.innerHTML = getPreloadHTML(dst);

	var cs = window.document.body.childNodes;
	for (var i = 0; i < cs.length;  i++) {
		var c = cs[i];
		if (c != TFac && c != TFaw && c != TFaa) {
			if (c.style) 
				c.style.display = 'none';
			else if (c.nodeType == 3) 
				c.nodeValue = '';
		}
	}

	if (window != top) {

		var f = window.frameElement;
		var topBody = top.document.body;
		tf_hideNodes(topBody, f);

		topBody.bottomMargin = topBody.leftMargin = topBody.rightMargin = topBody.topMargin = '0';

		f.frameBorder = 'no';
		f.border = '0';
		f.scrolling = "no";
		if (f.tagName != "FRAME") {
			f.height = f.width = '100%';
		}
		f.style.height = '100%';
		f.style.width = '100%';
		f.style.display = "block";
		f.marginHeight = 0;
		f.marginWidth = 0;
	}


//	var bd = window.document.body;
//	bd.bottomMargin = bd.leftMargin = bd.rightMargin = bd.topMargin = '0';

//	TFaw.style.height='100%';
TFaw.style.backgroundColor= '#FFFFFF';
	TFaw.style.display = 'block';
	TFaw.height = TFaw.width = '100%';
	TFaw.align="center";
	TFaw.style.height = TFaw.style.width = '100%';


	if (TFdebug) alert("finished makeAdVisible");

	if (window.TF_FP_PLAYURL)
//		TFap.src = 'javascript:parent.getPlayURLHTML()';
		TFap.innerHTML = getPlayURLHTML();
}


function lkClk(_ev) {
	if (TFonclick) TFonclick();

	var el;
	if (window.event)
	    el = window.event.srcElement;
	else
		el = _ev.target;

	/* XXX need to check for forms? */
	if ((el.tagName == 'A' || el.tagName == 'AREA') && el.href && targetIsTop(el.target)) {
		// Skip relative URL within the same doc
		if (!suitableURL(el.href, el.pathname))
			return true;

		// Skip events which already have a javascript action for them
		if (el.onclick) 
			return;

		if (TFdebug) alert("makeAdVisible called");
		
		makeAdVisible(el.href);

		if (window.event)
			window.event.returnValue = false;
		return false;
	}

	return true;
}

function suitableURL(href, pathname) {
	if (pathname == window.location.pathname) {
		return false;
	}
	if (href.indexOf("javascript:") != -1 || href.indexOf("mailto:") != -1) 
		return false;
	return true;
}

function targetIsTop(target) {
	if (!target) {
		var t = document.getElementsByTagName("BASE");
		if (t && t.length > 0 && t[0].target)
			return targetIsTop(t[0].target);
		return window == top; 
	}
	if (target == '_top') return true;
	if (target == '_parent') return window.parent == top;
	if (target == '_self') return window == top;
	for (w = window; w && w != w.top; w = w.parent) 
		if (w.name == target) return w == w.top;
	return false;
}
 
function TFreplayAd() {
  TFaa.src = TF_FP_ADURL;  
  if (window.TF_FP_TIMER) TFticker = TF_FP_TIMER;
  else TFticker = 15;
}

function TFpauseAd() {
  if (TFtohndlr) {
    clearTimeout(TFtohndlr); 
    TFtohndlr = null;
    setStatus(true, TFticker, TFtimeout, false);
  }
}

function TFskipAd() {
	if (TFacc != null && TFac != null) {
//		TFaw.style.height = "0%";
//		TFacc.style.height = "100%";
		top.location = TFac.src;
//		TFacc.src = "about:blank";
	}
}

function setOnClk() {
	if (TFdebug)
		alert("in setOnClk");

	var b = window.document.body;
	if (b.onclick != lkClk)
		TFonclick = b.onclick;
	b.onclick = lkClk;
}

function adLoaded() {
	if (TFdebug) alert('adloaded');

//	TFaa = TFaw.contentWindow.document.getElementById("TFAA");
	TFaa = document.getElementById("TFAA");
	if (TFaa == null) 
		alert("ERROR: can't find TFAA frame");
	else {
		setOnClk();
	}
	return true;
}

// Start the countdown
function nextPageLoaded() {
	//console.debug("next page");
//	TFac = TFacc.contentWindow.document.getElementById("TFAC");
	TFac = document.getElementById("TFAC");
	if (TFac == null) alert("ERROR: can't find TFAC frame");
	if (TFdebug)
		alert("next page loaded: " + TFac.src);
	ticker();
}

function ticker() {
	//console.debug("ticker");
	TFtohndlr = null;
	if (TFticker == 0){ 
		TFskipAd();
	}
	else {
		//console.debug("calling set Status ");
		setStatus(true, TFticker, TFtimeout, true);
		TFticker = TFticker - 1;
		TFtohndlr = setTimeout("ticker()", 1000);
	}
}

function setStatus(loaded, secs, timeout, running) {
//  var fdoc = TFaw.contentWindow.document;
//  var el = fdoc.getElementById("TF_FP_STATUS");
//console.debug("setting the sttaus");
	var el = document.getElementById("TF_FP_STATUS");
	if (el) {
		//console.debug("inisde setStatus as e1 is true")
		el.innerHTML = TF_getFPStatus(loaded,secs,timeout,running);
	}
//	el = fdoc.getElementById("TF_FP_ALT_STATUS");
	el = document.getElementById("TF_FP_ALT_STATUS");
	if (el) {
		el.innerHTML = TF_getFPAltStatus(loaded,secs,timeout,running);
	}
}

function setupAdTimer() {
	/* timer set due to weird Firefox bug, that causes the cursor/status to be stuck */
	window.setTimeout(setupAd, 100);
}

function setupAd() {
	if (TFdebug) alert("setting up ad");
	
//	TFaw.src = 'javascript:parent.getAdHTML()';

	TFaw.innerHTML = getAdHTML();
	return true;

}

if (document.getElementById) {
	loadDivs();
}

if (TFdebug) alert("finished init script");
