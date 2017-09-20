function setgrid() {
	var input = prompt('Enter the size grid you want by entering in one side');
	if (input > 0 && input <= 128) {
	var square_size = $('.container').width()/input-2;
	for(var i=0; i < input; i++) {
		for(var j=0; j < input; j++) {
			$('.container').append('<div class="square"></div>');
		}
		$('.container').append('<div class="row"></div>');
	}
	
$('.square').css('width', square_size);
$('.square').css('height', square_size);


$('.square').mouseenter(function() {
    $(this).addClass('highlight');
});
}

else {
	alert("Please enter a number between 0 and 128");
}

}
function cleargrid() {
	$('.square').removeClass('highlight');
	$('.square').css('background', '');
}

function showInstructions() {
    $('.instructions').slideToggle('fast');
}

function randomcolor() {
	cleargrid();
	setgrid();
    $('.square').mouseenter(function() {
    	$(this).css('background', 'rgb(' + (Math.floor(Math.random() * 256)) + ',' + (Math.floor(Math.random() * 256)) + ',' + (Math.floor(Math.random() * 256)) + ')');
    });
}

