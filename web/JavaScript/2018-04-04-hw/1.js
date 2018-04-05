//1. Удаление строки в таблице по нажатии на кнопку. Без id и data-id

//2. В инпуте автоматически приводить вводимый текст к большому регистру

document.addEventListener("DOMContentLoaded", function() {
	var bToLower = document.getElementById('toLower');
	var inputEl = document.getElementById('input').value;
	
	
	inputEl.addEventListener('keyup', function(){
		this.innerText = this.value.toUpperCase();
		//document.getElementById('input').value = inputEl.toLowerCase();
	});
	
	var delBtn = document.getElementsByClassName('delButton');
	
	for( var i = 0; i<delBtn.length; i++){
		delBtn[i].addEventListener('click', function(){
			this.closest('tr').remove();
		});
	}
});
