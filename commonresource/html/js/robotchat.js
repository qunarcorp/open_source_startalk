// 在抢单之后需要调整抢单按钮的状态
function modeRobotDealBtnState(id,bDisabled,strDisplay){	
	var btnDeal = document.getElementById(id);
	if(!!btnDeal){
		btnDeal.disabled=bDisabled;
		btnDeal.innerHTML = strDisplay;
	}
}

