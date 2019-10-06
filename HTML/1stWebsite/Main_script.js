 var urlMenu = document.getElementById('Language');
	urlMenu.onchange = function () 
	{
		var userOption = this.options[this.selectedIndex];
	
		if (userOption.value != "nothing") 
		{
		}
			open(userOption.value, "LNG page", "");
			
	}