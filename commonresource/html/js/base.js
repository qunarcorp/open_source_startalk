//时间块上的时间的显示
//最早的时间
function getOldestTime() {
    var times = document.querySelectorAll('[data-use=\'time\']');
    if (0 == times.length)
        return 0;
    var lasttime = times[0];
    var ds = lasttime.dataset;
    if (!!ds['value'])
        return parseInt(ds['value']);
    else
        return 0;
}

//最新的时间
function getLastestTime() {
    var times = document.querySelectorAll('[data-use=\'time\']');
    if (0 == times.length)
        return 0;
    var lasttime = times[times.length - 1];
    var ds = lasttime.dataset;
    if (!!ds['value'])
        return parseInt(ds['value']);
    else
        return 0;
}
//气泡消息中的消息时间
//最早的消息气泡中的消息时间
function getMsgBubbleOldestTime()
{
	
	var times = document.querySelectorAll('[data-use=\'msgbubbletime\']');
    if (0 == times.length)
	{	
		return 0;
	}
    var lasttime = times[0];
    var ds = lasttime.dataset;
    if (!!ds['value'])
	return parseInt(ds['value']);
    else
	return 0;
}
//最近的消息气泡中的
function getMsgBubbleLastestTime()
{
	var times = document.querySelectorAll('[data-use=\'msgbubbletime\']');
    if (0 == times.length)
	{
		return 0;
	}    
    var lasttime = times[times.length - 1];
    var ds = lasttime.dataset;
    if (!!ds['value'])
	{
		return parseInt(ds['value']);
	}    
    else
        return 0;
}

function addStyle(stylePath) {
    var container = document.getElementsByTagName("head")[0];
    var addStyle = document.createElement("link");
    addStyle.rel = "stylesheet";
    addStyle.type = "text/css";
    addStyle.media = "screen";
    addStyle.href = stylePath;
    container.appendChild(addStyle);
}

function clearImageBorder() {
    var imgs = document.querySelectorAll('[data-opentool=\'viewer\']');
    for (var j = 0; j < imgs.length; j++) {
        var aimg = imgs[j];
        aimg.style.border = 'none';
    }
    if (!!CLIENT_API)
        CLIENT_API.jsImageClicked("", "");
}

function selectImage(e) {

    var selectionNode = window.getSelection();
    if ('' != selectionNode) {
        if (!selectionNode.containsNode(e.srcElement, true)) {
            // 焦点不在选中区域，那么就将已经选中的
            selectionNode.removeAllRanges();
            
        }
    }

    if ('IMG' === e.srcElement.tagName) {
        var imgNode = e.srcElement;
        var ds = imgNode.dataset;
        if (!!ds['opentool'] && 'viewer' === ds['opentool']) {
            clearImageBorder();
            imgNode.style.border = '1px solid #666666'

            var imgID = ds['imgid'];
            var src = imgNode.src;

            if (!!CLIENT_API)
                CLIENT_API.jsImageClicked(src, imgID);
            
            var selectionNode = window.getSelection();
            // 焦点不在选中区域，那么就将已经选中的
            selectionNode.removeAllRanges();
            
            // range内没有东西不能接受ctrl+c的事件。这里人为的给加个空的range
            var range = document.createRange();
            window.getSelection().addRange(range);
            
            return;
        }
    }

    clearImageBorder();
}

function contextRequest(e) {

    if ('IMG' === e.srcElement.tagName) {
        var imgNode = e.srcElement;
        var ds = imgNode.dataset;
        if (!!ds['opentool'] && 'viewer' === ds['opentool']) {
            clearImageBorder();
            imgNode.style.border = '1px solid #666666'

            var imgID = ds['imgid'];
            var src = imgNode.src;

            if (!!CLIENT_API)
                CLIENT_API.jsImageClicked(src, imgID);
            preContextMenu(e);
            return;
        }
    }

    clearImageBorder();
    preContextMenu(e);

}

function myClosest(cel, cls) {
    var pn = cel;
    if (!!pn) {
        var pcls = pn.className;
        if (cls === pcls)
            return pn;
        else
            return myClosest(pn.parentNode, cls);
    }
    return null;
}

function preContextMenu(e, type) {
    if (!!!CLIENT_API)
        return;

    var selectionNode = window.getSelection();
    if ('' != selectionNode) {
        if (!selectionNode.containsNode(e.srcElement, true)) {
            // 焦点不在选中区域，那么就将已经选中的
            selectionNode.removeAllRanges();
            window.getSelection().addRange(range);
        }
        CLIENT_API.customCentextMenu('', '0'); // 一般的菜单
        return;
    }

    var tare = myClosest(e.srcElement, 'balloon-inside');
    var otherNode = myClosest(tare, 'other');
    var menuOption = type;

    if (!!tare) {
        var eid = tare.dataset['id'];
        if (!!eid) {
            if (!('IMG' === e.srcElement.tagName)) {
                // 图片内不需要气泡选中选中
                _selectNode(tare);
                e.preventDefault();
                e.stopPropagation();
            }
            if (!!otherNode)
                CLIENT_API.customCentextMenu(eid, '0');
            else
                CLIENT_API.customCentextMenu(eid, '10000');

            return;
        }
    }

    CLIENT_API.customCentextMenu('', '0');
}

function _selectNode(node)
{
    if (document.selection) {
        var range = document.body.createTextRange();
        range.moveToElementText(node);
        range.select();
    } else if (window.getSelection) {
        var range = document.createRange();
        range.selectNode(node);
        window.getSelection().addRange(range);
    }
}

function updateUserName(userid, name) {
    var usernames = document.querySelectorAll('[data-name=\'' + userid + '\']');
    for (var j = 0; j < usernames.length; j++) {
        var aname = usernames[j];
        aname.innerText = name;
    }
}

function replaceMessage(id, htmlStr) {
    var y = document.getElementById(id);
    y.innerHTML = htmlStr;
}

document.body.addEventListener('click', selectImage);
document.body.addEventListener('contextmenu', contextRequest);
document.body.addEventListener('dblclick', function(e) {

    if ('IMG' === e.srcElement.tagName) {
        var imgNode = e.srcElement;
        var ds = imgNode.dataset;
        if (!!ds['opentool'] && 'viewer' === ds['opentool']) {
            clearImageBorder();
            imgNode.style.border = '1px solid #666666'

            var imgID = ds['imgid'];
            var src = imgNode.src;
            if (!!CLIENT_API)
                CLIENT_API.jsImageDbClicked(src, imgID);

            return;
        }
    }

    clearImageBorder();
});
document.body.addEventListener('keydown', function(e) {
    if (e.keyCode == 32) {
        if (CLIENT_API != undefined) {
            CLIENT_API.jsSpaceClicked();
        }
        e.stopPropagation();
        e.preventDefault();
        return;
    }
}, false);




function setOtherFont(fontname, size, color) {
    var localCSS = getstyle(".other .balloon-inside");
    localCSS.fontSize = size + "pt";
    localCSS.fontFamily = fontname;
    localCSS.color = color;
}


function setSelfFont(fontname, size, color) {
    var localCSS = getstyle(".self .balloon-inside");
    localCSS.fontSize = size + "pt";
    localCSS.fontFamily = fontname;
    localCSS.color = color;
	
	setStatusfontfamy(fontname);
}

function LoadImgFail(id) {
    var y = document.getElementById(id);

    y.setAttribute("src", "./image/LoadImagefail.png");
}


function openNewLink(url) {
    CLIENT_API.openNewLink(url);
}

function onVoicePlayClicked(id) {
    CLIENT_API.jsOpenVoice(id);
}

function setVoicePlayed(id) {
    var voiceicon = id + "_voiceicon";

    document.getElementById(voiceicon).style.display = 'none';
}

function changeuserIcon(uid, src) {
    var userimags = document.querySelectorAll('[data-resourcehead=\'' + uid + '\']');
    for (var j = 0; j < userimags.length; j++) {
        var aimg = userimags[j];
		aimg.src = src + '?' + Math.random();
    }
}

function changeusername(uid, name) {
    var spans = document.querySelectorAll('[data-resourcename=\'' + uid + '\']');
    for (var j = 0; j < spans.length; j++) {
        var aspan = spans[j];
        aspan.innerText = name;
    }
}

function onVoicePlayClicked(id) {
    CLIENT_API.jsOpenVoice(id);
}

function setVoicePlayed(id) {
    var voiceicon = id + "_voiceicon";

    document.getElementById(voiceicon).style.display = 'none';
}


// 组成员（别人）点击显示快捷菜单
function onPopMenuClick(resource) {
    CLIENT_API.jsGroupPopMenu(resource);
}

function removeElement(eid) {
    var x = document.getElementById(eid);
    if (x) {
        var _parentElement = x.parentNode;
        if (_parentElement) {
            _parentElement.removeChild(x);
        }
    }
}


function findmsgMao(msgid) {
    var newNode = document.createElement("a"); //创建一个P标签
    newNode.href = "#" + msgid;
    newNode.style.display = "none";
    document.body.appendChild(newNode);
    newNode.click();
    newNode.remove();
}


if (typeof MessageStatus == "undefined") {
    var MessageStatus = {};　　　
    MessageStatus.SendSuccess = 0;　　　　　　　　
    MessageStatus.Sending = 1;　　　　　　　　　　　
    MessageStatus.SendFail = 2;　　　　　　　
}

function resendmessage(id) {
    var imgnode = document.getElementById(id);
    if (imgnode) {
        var ds = imgnode.dataset;

        if (!!ds['msgid']) {
            var msgid = ds['msgid'];

            if (!!ds['sendfail'] && MessageStatus.SendFail == ds['sendfail']) {
                if (!!CLIENT_API)
                    CLIENT_API.jsReSendMessage(msgid);
            }

            return;
        }
    }
}

function updateMessageStatus(msgid, status) {

    var sendimg = document.getElementById(msgid + '_loadingimg');
    if (!!sendimg) {
        if (status == MessageStatus.Sending) {
            sendimg.src = 'image/loading.gif';
            var ds = sendimg.dataset;
            ds['sendfail'] = MessageStatus.Sending;
            sendimg.style.display='';
        }
        if (status == MessageStatus.SendFail) {
            sendimg.src = 'image/tanhao.png';
            var ds = sendimg.dataset;
            ds['sendfail'] = MessageStatus.SendFail;
            sendimg.style.display='';
        }
        if (status== MessageStatus.SendSuccess) {
            sendimg.style.display='none';
        }
    }
}
function updateMessageSendPicSrc(msgid, msgsrc)
{
	
	var imgnode = document.getElementById(msgid);
    if (imgnode) {
		
        var ds = imgnode.dataset;
        if (!!ds['imgid'] && msgid==ds['imgid'] ) {
			
			imgnode.src = msgsrc;
		//	jslog(imgnode.src);
            return;
        }
    }
	/*jslog(' msgid = ' + msgid + '     msgsrc = ' + msgsrc);
	var userimags = document.querySelectorAll('[data-opentool=\'viewer\']');
	var lenght = userimags.length;
	jslog(' lenght = ' + lenght);
    for (var j = 0; j < userimags.length; j++) {
		jslog(' into loop for ' );
        var aimg = userimags[j];
		if(aimg.id == msgid)
		{
			jslog('msgsrc = ' + msgsrc);
			
			aimg.src = msgsrc;
			jslog('aimg.src = ' + aimg.src);
			break;
		}
		
    }*/
	
}
/*function cleanEmptyPage(){

	var list = document.querySelector('[data-use="section"]');
	var childnode = list.children;
	var nlength = childnode.length;
	for(var i = 0; i < nlength; i++)
	{
		var node = childnode[0];
		node.parentNode.removeChild(node);
	}
	 PAGE.flag = true;
}*/
var sharedSelectable = false;
function setMessagesSelectable(bSelect)
{
    var inputs = document.getElementsByName('messageshared');
    sharedSelectable = !bSelect?false:!sharedSelectable;
    for (var i = 0; i < inputs.length; i++) {
        inputs[i].style.display= sharedSelectable?'':'none';
        if (!sharedSelectable) {
            inputs[i].checked = false;
        }
    }
    CLIENT_API.jsConversationDialogMesssageSelectedStatus(sharedSelectable);
}

function shareSelectMessages(shareconversaionId)
{
	//jslog(shareconversaionId);
    var ids = new Array();
    var inputs = document.getElementsByName('messageshared');

    for (var i = 0; i < inputs.length; i++) {
        var ainput = inputs[i];
        if (ainput.checked) {
            ids.push(ainput.value)
        }
    }

    if (!!CLIENT_API)
        CLIENT_API.jsShareSelectMessage(shareconversaionId, ids);
}
function onMessageShareSelect() {

    var ncount = 0;
    var inputs = document.getElementsByName('messageshared');
    for (var i = 0; i < inputs.length; i++) {
        var ainput = inputs[i];
        if (ainput.checked) {
            ncount++;
        }
    }

    CLIENT_API.jsShareSelectMessageCountChange(ncount);
}
function getScrollpos(data) {
	
    var scrollToppos = document.body.scrollTop;
    
    
   CLIENT_API.jsGetScrollTop(data,scrollToppos);
}

function getScrollposInhtml()
{
	//滚动条距离顶部的高度
	var scrolltopheight =  document.body.scrollTop;
	//可视区域的高度
	var viewareaheight = document.body.clientHeight;
	//整个html的高度
	var holdhtmlheight = document.body.scrollHeight;
	
	
	return  holdhtmlheight - scrolltopheight;
	
}

function setScrollpos(pos) {
	
	//获取整个html的高度
	var holdhtmlheight = document.body.scrollHeight;
	document.body.scrollTop = holdhtmlheight - pos;
}

function noticeat(id){
   var times = document.querySelectorAll('[data-use=\'at\']');
   for (var i = 0; i < times.length; i++) {
       var atinfo = times[i];
       var ds = atinfo.dataset;
       if (!!ds['atid']&&id==ds['atid']) {
           atinfo.className='atinfonotice';
       }
       else {
            atinfo.className='atinfonomal';
       }
   }
}

/*function keepCurrentPageMessageCount()
 {
	//获取页面html中的消息条数
	//包括居中的时间，包括消息，包括’以下是未读消息‘等提示信息
	var list = document.querySelector('[data-use="section"]');
	var childnode = list.children;
	var nlength = childnode.length;
	if( (nlength > CurrentPageMsgCount) && !unreadMsgTip )
	{
		jslog('nlength > CurrentPageMsgCount) && !unreadMsgTip' );
		for(var i = 0; i < nlength - CurrentPageMsgCount; i++)
		{
			var node = childnode[0];
			node.parentNode.removeChild(node);
		}
		
		//接着看第一条信息和第二条信息的时间的比较
		var firsttime = childnode[0].getAttribute("data-value");
		var secondtime = childnode[1].getAttribute("data-value");
		
		var firsttype = childnode[0].getAttribute("data-use");
		var secondtype = childnode[1].getAttribute("data-use");
		//第一条消息不是newline 类型的信息
		
		
		if( (firsttime != null) && (firsttime  < secondtime) )
		{
			PAGE_API.showkeepMsgCount(firsttime);		
		}
		if( firsttime == null )
		{
			PAGE_API.showkeepMsgCount(secondtime);
		}
		if( (firsttime == secondtime) && (firsttype == secondtype) )
		{
			PAGE_API.showkeepMsgCount(firsttime);
		}
	}
	
	
 }*/


 window.addEventListener("copy", function (e) {
    
    var selectionNode = window.getSelection();

    if ('' != selectionNode) {
        CLIENT_API.jsWebCopyEvent();
    }
    else
    {
        CLIENT_API.jsSingleImageCopy();
    }
 });


function replyWechatUser(messageid) {
    CLIENT_API.jsReplyWechatUser(messageid);
}
 
 
 /* 酒店的结算员业务引入，增加的简单http get api 调用*/
 function httpgetapicall(apiurl){
	 CLIENT_API.jshttpgetapicall(apiurl);
    /*  $.ajax({
                url:apiurl,
                type:"get",
                dataType:"json",
                success : function (resp) {
                    alert("更新结果"+resp);
                },
                error : function(XMLHttpRequest, textStatus, errorThrown){
                    alert('error' + ' ' +apiurl);
					alert(XMLHttpRequest.readyState);
					alert('textStatus:' + textStatus);
					jslog('jsbase error======' + ' ' + textStatus + ' ' + apiurl);
                }
            });*/
 }
 function gotoVideoRoom(msgid){
	 CLIENT_API.jsgotoVideoRoom(msgid);
 }
 
 function getCurrentHtmlInfobyMsgId(msgid, conversationId)
 {
	var times = document.querySelectorAll('[data-use=\'at\']');
	var exist = false;
	var firstmsgid;
	var length = times.length;
	for (var i = 0; i < times.length; i++) {
       var atinfo = times[i];
       var ds = atinfo.dataset;
       if (!!ds['atid']&&msgid==ds['atid']) {
           exist = true;
		   break;
       }
   }
   
   if(exist)
   {
	   
	   findmsgMao(msgid);
	   noticeat(msgid);
	   return;
   }
   else
   {
	   var ids = document.querySelectorAll('[data-id]');
	   var length = ids.length;
	  
	   if (0 == ids.length)
        return 0;
		var firstitem = ids[0];
		var ds = firstitem.dataset;
		
		if (!!ds['id'])
		{
			var id = ds['id'];
			CLIENT_API.jsRetunfirstMsgid(msgid, id, conversationId);
		}
        
	   
   }
 }
 function checkHtml(htmlStr) {
    var  reg = /<[^>]+>/g;
    return reg.test(htmlStr);
}

function textSize(text) {
	var span = document.createElement("span");
	var result = {};
	result.width = span.offsetWidth;
	result.height = span.offsetHeigh; 
	span.style.visibility = "hidden";
	document.body.appendChild(span);
	if(typeof span.textContent != "undefined")
		span.textContent = text;
	else span.innerText = text;
	//result.width = span.offsetWidth - result.width;
	result.width = span.offsetWidth;
	result.height = span.offsetHeight - result.height;
	span.parentNode.removeChild(span);
	return result.width;
}

 function setwidth() {
	
	 var width = document.documentElement.clientWidth;
	 
	 var widthend = width*0.9;
	 if(widthend <= 360)
	 {
		 return;
	 }
	 else
	 {
		//行的最大宽度 
		 
		widthend = widthend - 100;
		var contentcode = document.querySelectorAll('[data-user=\'contentcode\']');
	
		var length = contentcode.length;
		//jslog("     code length=     " + length);
		for (var j = 0; j < contentcode.length; j++) 
		{
			var maxwidth = 0;
			var content = contentcode[j];
			
			var codeNodes = content.getElementsByTagName("code");
			for (var k=0;k<codeNodes.length; k++){
			    var codeNode = codeNodes[k];
				var value = codeNode.innerHTML;
				var arr = [];
				//jslog("     code content=     " + value);
				if(checkHtml(value))
				{
					arr = value.split("<br>")
					//jslog("     code fomat is <br>  and length=    " + arr.length );
					for(var n = 0; n < arr.length; n++)
					{
						
						//jslog("   num  content=   " + n + "    " + arr[n]);
						var id = "LC" + (n+1);
						
						var spansvalue = arr[n]; 
						
						var patt = new RegExp('/<span.*>(.*)<\/span>/isU');
						var textvalue;
						if(patt.test(spansvalue))
						{
							textvalue = $("#" + id).text(); 
							var spvalue = $("span").text();
						}
						else
						{
							textvalue = spansvalue;
						}
							
						
						
						var nwidth = textSize(textvalue);
						//jslog("   content  length =   " + nwidth);
						if(nwidth >= maxwidth)
						{
							maxwidth = nwidth;
						}
	
					}
	
				}
				else
				{
					arr = value.split("\n");
					//jslog("arr.length=" +arr.length);
					for(var n = 0; n < arr.length; n++)
					{
						var text = arr[n];
						//alert("text=" +text);
						var nwidth = textSize(text);
						//jslog("nwidth=" + nwidth);
						if(nwidth >= maxwidth)
						{
							maxwidth = nwidth;
						}
					}
				}
				
				
				
				
            }
			maxwidth = maxwidth - 200;
			if(widthend <= maxwidth)
			{
				content.style.width = widthend  + "px";
				jslog("   widthend <= maxwidth:   " + maxwidth + "   ======   " + widthend + width);
			}
			else 
			{
				if(maxwidth > 0)
				{
					content.style.width = maxwidth + "px";
				}
				else
				{
					content.style.width = widthend + "px";
				}
				
				jslog("   widthend > maxwidth:    " + maxwidth + "======" + widthend + width);
			}
		}
		
		
		//var cont = document.getElementById("codecontent").innerHTML;
		//alert(cont);
	 }
}
function getspanval(spval, id)
{
	var spans = document.getElementById(id);
	alert(spans.length);
	var nwidth = spans.offsetWidth;
	alert(nwidth);
	var value;
	//for(var j = 0; j < spans.length; j++)
	//{
	//	var spanNode = spans[k];
	//	alert(spanNode.innerHTML);
	//	value += spanNode.innerHTML;
	//}
	//alert(value);
}

function setloadstatus(type)
{
	if(type==0)
	{
		jslog('000');
		document.getElementById("loading").style.display = 'inline-block';
		document.getElementById("loaded").style.display = 'none';
		document.getElementById("loadover").style.display = 'none';
	}
	else if(type==1)
	{
		jslog('111');
		document.getElementById("loading").style.display = 'none';
		document.getElementById("loaded").style.display = 'inline-block';
		document.getElementById("loadover").style.display = 'none';
	}
	else
	{
		jslog('else');
		document.getElementById("loading").style.display = 'none';
		document.getElementById("loaded").style.display = 'none';
		document.getElementById("loadover").style.display = 'inline-block';
	}
	
}
//运营抢单状态的改变
	function QiangdanMessageStatus(id, bDisabled, strDisplay)
	{
			
		//var btnDeal = document.getElementById(id);
		
		//if(!!btnDeal){
			
		//	btnDeal.disabled=bDisabled;
		//	btnDeal.innerHTML = strDisplay;
		//}
		
		var param = '[data-user=\'' + id + '\']';
		var btnDeal = document.querySelectorAll(param);
	
		for (var i = 0; i < btnDeal.length; i++) {
			 var varbtn = btnDeal[i];
			if (!!varbtn) {
				varbtn.disabled=bDisabled;
				varbtn.innerHTML = strDisplay;
			}
		}
	}
	
	function setMsgtatus(msgid, strDisplay)
	{
		var msgstatusary = document.querySelectorAll('[data-user=\'msgstatus\']');
		
		var length = msgstatusary.length;
		//alert("     code length=     " + length);
		for (var i = 0; i < msgstatusary.length; i++) 
		{
			var oneinfo = msgstatusary[i];
			var ds = oneinfo.dataset;
			//alert("id= " + ds['id']);
			if (!!ds['id']&&ds['id']==msgid) {
				//alert(' ds.innerHTML ' + oneinfo.innerHTML);
				oneinfo.innerHTML = strDisplay;
				oneinfo.style.display = 'inline-block';
				break;
			}
		}
	}
	
	function setStatusfontfamy(fontfamiliy)
	{
		//alert(fontfamiliy);
		var localCSS = getstyle(".self .svalue");
		
		localCSS.fontFamily = fontfamiliy;
		//localCSS.color = #FF0000;
	}

