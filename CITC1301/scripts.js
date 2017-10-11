
 	function showSocial() {

 		var x = document.getElementById("mySocial");
 		if (x.style.display === "flex") {
 			x.style.display="none";
 		} else {
 			x.style.display="flex";
 		}
 	}




	function showSection() {
		var x = document.getElementById("resources");
		if (x.style.display === "block") {
			x.style.display="none";
		} else {
			x.style.display="block";
		}
	}



 


	function showSection1() {
		var x = document.getElementById("books");
		if (x.style.display === "block") {
			x.style.display="none";
		} else {
			x.style.display="block";
		}
	}



 




	function changePic() {
		document.getElementById("myPic").src="me.jpg";
	}



	function changePic1() {
	  document.getElementById("myPic").src="eat.jpg";
	
	}




	function swapBackground() {
		var a = document.getElementById("body");
		var x = document.getElementById("pageOne");
		var y = document.getElementById("pageTwo");
		var z= document.getElementById("top");

		a.style.backgroundImage = "url('vintage-concrete.png')";
		x.style.backgroundImage = "url('topography.png')";
		y.style.backgroundImage = "url('concrete-texture.png')";
	 	z.style.backgroundImage = "url('vintage-concrete.png')";
	
	}


	function reload() {
		location.reload();
	}

