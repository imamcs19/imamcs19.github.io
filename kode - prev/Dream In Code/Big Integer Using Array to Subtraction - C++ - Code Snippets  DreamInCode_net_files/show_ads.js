(function(){
var K={google_ad_channel:{url_param:"channel",gfp:1},google_ad_format:{url_param:"format",gfp:0},google_ad_host:{url_param:"host",gfp:1},google_ad_output:{url_param:"output",gfp:0},google_ad_override:{url_param:"google_ad_override",gfp:0},google_ad_region:{url_param:"region",gfp:1},google_ad_section:{url_param:"region",gfp:1},google_ad_slot:{url_param:"slotname",gfp:0},google_ad_type:{url_param:"ad_type",gfp:1},google_adtest:{url_param:"adtest",gfp:1},google_alternate_ad_url:{url_param:"alternate_ad_url",
gfp:1},google_alternate_color:{url_param:"alt_color",gfp:1},google_analytics_webpropids:{url_param:"ga_wpids",gfp:0},google_bid:{url_param:"bid",gfp:1},google_city:{url_param:"gcs",gfp:1},google_color_bg:{url_param:"color_bg",gfp:1},google_color_border:{url_param:"color_border",gfp:1},google_color_line:{url_param:"color_line",gfp:1},google_color_link:{url_param:"color_link",gfp:1},google_color_text:{url_param:"color_text",gfp:1},google_color_url:{url_param:"color_url",gfp:1},google_contents:{url_param:"contents",
gfp:1},google_correlator:{url_param:"correlator",gfp:0},google_country:{url_param:"gl",gfp:1},google_cpa_choice:{url_param:"cpa_choice",gfp:0},google_cust_age:{url_param:"cust_age",gfp:1},google_cust_ch:{url_param:"cust_ch",gfp:1},google_cust_gender:{url_param:"cust_gender",gfp:1},google_cust_id:{url_param:"cust_id",gfp:1},google_cust_interests:{url_param:"cust_interests",gfp:1},google_cust_job:{url_param:"cust_job",gfp:1},google_cust_l:{url_param:"cust_l",gfp:1},google_cust_lh:{url_param:"cust_lh",
gfp:1},google_cust_u_url:{url_param:"cust_u_url",gfp:1},google_disable_video_autoplay:{url_param:"disable_video_autoplay",gfp:1},google_ed:{url_param:"ed",gfp:1},google_encoding:{url_param:"oe",gfp:1},google_feedback:{url_param:"feedback_link",gfp:1},google_flash_version:{url_param:"flash",gfp:1},google_gl:{url_param:"gl",gfp:1},google_hints:{url_param:"hints",gfp:1},google_image_size:{url_param:"image_size",gfp:0},google_kw:{url_param:"kw",gfp:1},google_kw_type:{url_param:"kw_type",gfp:1},google_language:{url_param:"hl",
gfp:1},google_last_modified_time:{url_param:"lmt",gfp:0},google_max_num_ads:{url_param:"num_ads",gfp:0},google_max_radlink_len:{url_param:"max_radlink_len",gfp:0},google_num_radlinks:{url_param:"num_radlinks",gfp:0},google_num_radlinks_per_unit:{url_param:"num_radlinks_per_unit",gfp:0},google_only_ads_with_video:{url_param:"only_ads_with_video",gfp:0},google_page_location:{url_param:"loc",gfp:0},google_page_url:{url_param:"url",gfp:0},google_referrer_url:{url_param:"ref",gfp:1},google_region:{url_param:"gr",
gfp:1},google_reuse_colors:{url_param:"reuse_colors",gfp:1},google_rl_dest_url:{url_param:"rl_dest_url",gfp:0},google_rl_filtering:{url_param:"rl_filtering",gfp:0},google_rl_mode:{url_param:"rl_mode",gfp:0},google_rt:{url_param:"rt",gfp:0},google_safe:{url_param:"adsafe",gfp:1},google_skip:{url_param:"skip",gfp:0},google_targeting:{url_param:"targeting",gfp:1},google_ui_features:{url_param:"ui",gfp:1}};function D(b){var a=K[b];return a?a.url_param:null}var Q=document;function T(){var b=Q.cookie,a=
Math.round((new Date).getTime()/1000),d=b.indexOf("__utma=")>-1,f=b.indexOf("__utmb=")>-1,c=b.indexOf("__utmc=")>-1,e,g={};if(d){e=b.split("__utma=")[1].split(";")[0].split(".");g.sid=(!f||!c?a:e[4])+"";g.vid=e[1]+"."+e[2];g.from_cookie=true}else{g.sid=window&&window.gaGlobal&&window.gaGlobal.sid?window.gaGlobal.sid:a+"";g.vid=window&&window.gaGlobal&&window.gaGlobal.vid?window.gaGlobal.vid:Math.round(Math.random()*2147483647)+"."+a;g.from_cookie=false}g.hid=window&&window.gaGlobal&&window.gaGlobal.hid?
window.gaGlobal.hid:Math.round(Math.random()*2147483647);window.gaGlobal=g;return g}(function(){function b(){}b.prototype.l=function(f){var c=f.indexOf("#")+1;return c?f.substr(c):""};b.prototype.n=function(f){return/[&<>\"]/.test(f)?f.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/\"/g,"&quot;"):f};b.prototype.b=function(f){var c="<iframe";for(var e in f){c+=" "+e+'="'+this.n(f[e])+'"'}return c+"></iframe>"};b.prototype.m=function(f,c){try{return f.frames[c]}catch(e){return null}};
b.prototype.e=function(f){var c=document.createElement("iframe");for(var e in f){c.setAttribute(e,f[e])}return c};b.prototype.i=function(f,c){var e=this;document.body.appendChild(e.e({id:f,name:f,src:c,width:0,height:0,frameBorder:0}))};b.prototype.r=function(f,c){var e=this;document.write(e.b({id:f,name:f,src:c,width:0,height:0,frameBorder:0}))};b.prototype.g=function(f,c){var e=[],g=f.length,l=0;while(l<g){var j=f.substr(l,c),k=j.length;if(l+k<g){for(var i=1;i<3;++i){if(j.charAt(k-i)=="%"){j=j.substr(0,
k-=i)}}}e.push(j);l+=k}return e};b.prototype.a=function(f,c,e){if(!window[f]){var g=window[f]=new c;for(var l=0;l<e.length;++l){g[e[l][0]]=e[l][1]}}};var a=b.prototype,d=[["getHash",a.l],["htmlEscape",a.n],["makeIframeTag",a.b],["getIframe",a.m],["makeIframeNode",a.e],["appendHiddenIframe",a.i],["writeHiddenIframe",a.r],["splitURIComponent",a.g],["exportSingleton",a.a],["MAX_URL_LENGTH",4095],["IDI_DEFAULT_POLLING_INTERVAL",1000]];b.prototype.a("IDICommon",b,d)})();(function(){function b(c,e){for(var g in e){c[g]=
e[g]}}function a(){var c=this;c.s=window.location.href.replace(/([^:\/])\/.*$/,"$1/robots.txt");c.t="";c.k={};c.c={};c.f={};c.u={};c.o={}}a.prototype.w=function(c,e){var g=this,l=g.c[c];if(isNaN(l)){throw new Error("Invalid module id");}else{var j=g.d(g.u[c]),k=encodeURIComponent(e)+"$",i=IDICommon.MAX_URL_LENGTH-1-j.length,o=IDICommon.g(k,i),n=o.length;for(var q=0;q<n;++q){IDICommon.i(c+"_"+(l+q),j+"#"+o[q])}g.c[c]+=n}};a.prototype.p=function(c,e,g){var l=this;l.h(c);l.o[c]=window.setInterval(function(){l.v(c,
e)},typeof g=="object"&&g.pollingInterval||IDICommon.IDI_DEFAULT_POLLING_INTERVAL)};a.prototype.h=function(c){var e=this;window.clearInterval(e.o[c]);e.o[c]=0};a.prototype.x=function(c){this.s=c};a.prototype.q=function(c){this.t=c};a.prototype.d=function(c){return this.t||c.replace(/([^:\/]\/).*$/,"$1ig/idi_relay")};a.prototype.v=function(c,e){var g=this,l=window.frames[c];if(l){var j;while(j=IDICommon.m(l,c+"_"+g.k[c])){try{if(j.location.href=="about:blank"){break}}catch(k){break}g.f[c]+=IDICommon.l(j.location.href);
++g.k[c]}var i=g.f[c].split("$"),o=i.length-1;if(o>0){g.f[c]=i[o];for(var n=0;n<o;++n){e(decodeURIComponent(i[n]),c)}}}};a.prototype.j=function(c,e,g,l,j){var k=this,i={frameBorder:0,scrolling:"no"},o,n,q,A,t;if(typeof j=="object"){o=j.iframeAttrs;n=j.callback;q=j.userPrefs;A=j.pollingInterval;t=j.parentDivId}if(typeof o=="object"){b(i,o)}b(i,{id:e,name:e,src:c,width:g,height:l});k.k[e]=0;k.c[e]=0;k.f[e]="";k.u[e]=c;var u=[];if(typeof q=="object"){for(var r in q){u.push(encodeURIComponent(r)+"="+
encodeURIComponent(q[r]))}}if(typeof n=="function"){u.push("idi_hr="+encodeURIComponent(k.s));k.p(e,n,j)}if(u.length){var v=u.join("&");if(i.src.length+1+v.length>IDICommon.MAX_URL_LENGTH){v+="$";var y=k.d(c),N=IDICommon.MAX_URL_LENGTH-1-y.length,F=IDICommon.g(v,N),G=F.length;for(var r=0;r<G;++r){var C=e+"_"+r,H=y+"#"+F[r];if(t){var z=document.getElementById(t);z.innerHTML=z.innerHTML+k.e({id:C,name:C,src:H,width:0,height:0,frameBorder:0})}else{IDICommon.r(C,H)}}k.c[e]+=G;v=""}i.src+="#"+v}if(t){var z=
document.getElementById(t);z.innerHTML=z.innerHTML+IDICommon.b(i)}else{document.write(IDICommon.b(i))}};var d=a.prototype,f=[["setHostRelayUrl",d.x],["setModuleRelayUrl",d.q],["getModuleRelayUrl",d.d],["createModule",d.j],["postMessageToModule",d.w],["registerListener",d.p],["unregisterListener",d.h]];IDICommon.a("IDIHost",a,f)})();function w(b){return b!=null?'"'+b+'"':'""'}function R(b){if(typeof encodeURIComponent=="function"){return encodeURIComponent(b)}else{return escape(b)}}function m(b,a){if(b&&
a){window.google_ad_url+="&"+b+"="+a}}function h(b){var a=window,d=D(b),f=a[b];m(d,f)}function s(b,a){if(a){m(b,R(a))}}function p(b){var a=window,d=D(b),f=a[b];s(d,f)}function x(b,a){var d=window,f=D(b),c=d[b];if(f&&c&&typeof c=="object"){c=c[a%c.length]}m(f,c)}function U(b,a){var d=b.screen,f=navigator.javaEnabled(),c=-a.getTimezoneOffset();if(d){m("u_h",d.height);m("u_w",d.width);m("u_ah",d.availHeight);m("u_aw",d.availWidth);m("u_cd",d.colorDepth)}m("u_tz",c);m("u_his",history.length);m("u_java",
f);if(navigator.plugins){m("u_nplug",navigator.plugins.length)}if(navigator.mimeTypes){m("u_nmime",navigator.mimeTypes.length)}}function E(b){if(b){b=b.toLowerCase();if(b.substring(0,3)!="ca-"){b="ca-"+b}}return b}function aa(b,a){var d=document.getElementById(b);d.style.height=a+"px"}function V(b,a,d){window.clearTimeout(d);var f=/^google_resize_flash_ad_idi\((\d+)\)/,c=b.match(f);if(c){aa(a,c[1])}}function ba(b,a,d,f){d=d.substring(0,2000);d=d.replace(/%\w?$/,"");if(b.google_ad_output=="js"&&(b.google_ad_request_done||
b.google_radlink_request_done)){a.write('<script language="JavaScript1.1" src='+w(d)+"><\/script>")}else if(b.google_ad_output=="html"){if(b.name!="google_ads_frame"){if(f!=null){a.write('<div id="'+f+'">')}if(W(b.google_ad_output,b.google_ad_client)){IDIHost.q("http://pagead2.googlesyndication.com/pagead/idi_relay.html");var c="google_inline_div"+b.google_num_ad_slots,e="<div id="+w(c)+' style="position:relative;"></div><div style="position:relative;width:'+b.google_ad_width+"px;height:"+b.google_ad_height+
'px;z-index:-1"></div>';a.write(e);var g="google_frame"+b.google_num_ad_slots,l=b.setTimeout(function(){IDIHost.h(g)},5000);IDIHost.j(d,g,b.google_ad_width,b.google_ad_height,{callback:function(j,k){V(j,k,l)},pollingInterval:500,iframeAttrs:{style:"position: absolute;left:0px",marginWidth:"0",marginHeight:"0",vspace:"0",hspace:"0",allowTransparency:"true"},parentDivId:c})}else{a.write('<iframe name="google_ads_frame" width='+w(b.google_ad_width)+" height="+w(b.google_ad_height)+" frameborder="+w(b.google_ad_frameborder)+
" src="+w(d)+' marginwidth="0" marginheight="0" vspace="0" hspace="0" allowtransparency="true" scrolling="no">');a.write("</iframe>")}if(f!=null){a.write("</div>")}}}else if(b.google_ad_output=="textlink"){a.write('<script language="JavaScript1.1" src='+w(d)+"><\/script>")}}function $(b){for(var a in K){b[a]=null}}function O(){var b=null,a=window,d=document,f=new Date,c=f.getTime(),e=a.google_ad_format;if(a.google_cpa_choice!=b){a.google_ad_url="http://pagead2.googlesyndication.com/cpa/ads?";a.google_ad_url+=
"client="+escape(E(a.google_ad_client));a.google_ad_region="_google_cpa_region_";h("google_cpa_choice");if(typeof d.characterSet!="undefined"){s("oe",d.characterSet)}else if(typeof d.charset!="undefined"){s("oe",d.charset)}}else{a.google_ad_url="http://pagead2.googlesyndication.com/pagead/ads?";a.google_ad_url+="client="+escape(E(a.google_ad_client))}h("google_ad_host");var g=a.google_num_slots_by_client,l=a.google_num_slots_by_channel,j=a.google_prev_ad_formats_by_region,k=a.google_prev_ad_slotnames_by_region;
if(a.google_ad_region==b&&a.google_ad_section!=b){a.google_ad_region=a.google_ad_section}var i=a.google_ad_region==b?"":a.google_ad_region,o=false;if(e){o=e.indexOf("_0ads")>0}else if(a.google_ad_output!="html"&&a.google_num_radlinks>0){o=true}if(o){if(a.google_num_0ad_slots){a.google_num_0ad_slots=a.google_num_0ad_slots+1}else{a.google_num_0ad_slots=1}if(a.google_num_0ad_slots>3){return false}}else if(a.google_cpa_choice==b){if(a.google_num_ad_slots){a.google_num_ad_slots=a.google_num_ad_slots+1}else{a.google_num_ad_slots=
1}if(a.google_num_slots_to_rotate){j[i]=b;k[i]=b;if(a.google_num_slot_to_show==b){a.google_num_slot_to_show=c%a.google_num_slots_to_rotate+1}if(a.google_num_slot_to_show!=a.google_num_ad_slots){return false}}else if(a.google_num_ad_slots>6&&i==""){return false}}m("dt",f.getTime());h("google_language");if(a.google_country){h("google_country")}else{h("google_gl")}h("google_region");p("google_city");p("google_hints");h("google_safe");h("google_encoding");h("google_last_modified_time");p("google_alternate_ad_url");
h("google_alternate_color");h("google_skip");h("google_targeting");var n=a.google_ad_client;if(!g[n]){g[n]=1;g.length+=1}else{g[n]+=1}if(j[i]){s("prev_fmts",j[i].toLowerCase());if(g.length>1){m("slot",g[n])}}if(k[i]){s("prev_slotnames",k[i].toLowerCase())}if(e&&!a.google_ad_slot){s("format",e.toLowerCase());if(j[i]){j[i]=j[i]+","+e}else{j[i]=e}}if(a.google_ad_slot){if(k[i]){k[i]=k[i]+","+a.google_ad_slot}else{k[i]=a.google_ad_slot}}h("google_max_num_ads");m("output",a.google_ad_output);h("google_adtest");
h("google_ad_slot");p("google_correlator");if(a.google_ad_channel){var q=a.google_ad_channel;s("google_ad_channel",q);var A="",t=q.split("+");for(var u=0;u<t.length;u++){var r=t[u];if(!l[r]){l[r]=1}else{A+=r+"+"}}s("pv_ch",A)}p("google_page_url");x("google_color_bg",c);x("google_color_text",c);x("google_color_link",c);x("google_color_url",c);x("google_color_border",c);x("google_color_line",c);if(a.google_reuse_colors)m("reuse_colors",1);else m("reuse_colors",0);h("google_kw_type");p("google_kw");
p("google_contents");h("google_num_radlinks");h("google_max_radlink_len");h("google_rl_filtering");h("google_rl_mode");h("google_rt");p("google_rl_dest_url");h("google_num_radlinks_per_unit");h("google_ad_type");h("google_image_size");h("google_ad_region");h("google_feedback");p("google_referrer_url");p("google_page_location");h("google_bid");h("google_cust_age");h("google_cust_gender");h("google_cust_interests");h("google_cust_id");h("google_cust_job");h("google_cust_u_url");h("google_cust_l");h("google_cust_lh");
h("google_cust_ch");h("google_ed");p("google_ui_features");p("google_only_ads_with_video");p("google_disable_video_autoplay");if(J(a,d)&&d.body){var v=d.body.scrollHeight,y=d.body.clientHeight;if(y&&v){s("cc",Math.round(y*100/v))}}T();m("ga_vid",a.gaGlobal.vid);m("ga_sid",a.gaGlobal.sid);m("ga_hid",a.gaGlobal.hid);m("ga_fc",a.gaGlobal.from_cookie);p("google_analytics_webpropids");h("google_ad_override");h("google_flash_version");U(a,f);return true}function L(){var b=window,a=document;if(!O()){return}ba(b,
a,b.google_ad_url,null);$(b)}function S(b,a,d){L();return true}function J(b,a){return b.top.location==a.location}function I(b,a){var d=a.documentElement;if(J(b,a))return false;if(b.google_ad_width&&b.google_ad_height){var f=1,c=1;if(b.innerHeight){f=b.innerWidth;c=b.innerHeight}else if(d&&d.clientHeight){f=d.clientWidth;c=d.clientHeight}else if(a.body){f=a.body.clientWidth;c=a.body.clientHeight}if(c>2*b.google_ad_height||f>2*b.google_ad_width){return false}}return true}function X(b){var a=window,
d=document,f=d.location,c=d.referrer,e=null,g=a.onerror;a.onerror=b;if(a.google_ad_frameborder==e){a.google_ad_frameborder=0}if(a.google_ad_output==e){a.google_ad_output="html"}if(a.google_ad_format==e&&a.google_ad_output=="html"){a.google_ad_format=a.google_ad_width+"x"+a.google_ad_height}if(a.google_page_url==e){a.google_page_url=c;if(!I(a,d)){a.google_page_url=f;a.google_last_modified_time=Date.parse(d.lastModified)/1000;a.google_referrer_url=c}}else{a.google_page_location=c;if(!I(a,d)){a.google_page_location=
f}}if(a.google_num_slots_by_channel==e){a.google_num_slots_by_channel=[]}if(a.google_num_slots_by_client==e){a.google_num_slots_by_client=[]}if(a.google_prev_ad_formats_by_region==e){a.google_prev_ad_formats_by_region=[]}if(a.google_prev_ad_slotnames_by_region==e){a.google_prev_ad_slotnames_by_region=[]}if(a.google_correlator==e){a.google_correlator=(new Date).getTime()}if(a.google_adslot_loaded==e){a.google_adslot_loaded={}}if(a.google_adContentsBySlot==e){a.google_adContentsBySlot={}}if(a.google_flash_version==
e){a.google_flash_version=P().toString()}a.onerror=g}function M(b){if(b in B){return B[b]}return B[b]=navigator.userAgent.toLowerCase().indexOf(b)!=-1}var B={};function W(b,a){if(b!="html"){return false}var d={};d["ca-pub-7027491298716603"]=true;d["ca-pub-8344185808443527"]=true;return d[E(a)]!=null}function Z(b){var a={},d=b.split("?"),f=d[d.length-1].split("&");for(var c=0;c<f.length;c++){var e=f[c].split("=");if(e[0]){try{a[e[0].toLowerCase()]=e.length>1?(window.decodeURIComponent?decodeURIComponent(e[1].replace(/\+/g,
" ")):unescape(e[1])):""}catch(g){}}}return a}function Y(){var b=window,a=Z(document.URL);if(a.google_ad_override){b.google_ad_override=a.google_ad_override}}function P(){var b=0;if(navigator.plugins&&navigator.mimeTypes.length){var a=navigator.plugins["Shockwave Flash"];if(a&&a.description){b=a.description.replace(/([a-zA-Z]|\s)+/,"").split(".")[0]}}else if(navigator.userAgent&&navigator.userAgent.indexOf("Windows CE")>=0){b=3;var d=1;while(d){try{d=new ActiveXObject("ShockwaveFlash.ShockwaveFlash."+
(b+1));b++}catch(f){d=null}}}else if(M("msie")&&!window.opera){try{var d=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7")}catch(f){try{var d=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");b=6;d.AllowScriptAccess="always"}catch(f){if(b==6){return b}}try{d=new ActiveXObject("ShockwaveFlash.ShockwaveFlash")}catch(f){}}if(d!=null){b=d.GetVariable("$version").split(" ")[1].split(",")[0]}}return b}Y();X(S);L();
})()