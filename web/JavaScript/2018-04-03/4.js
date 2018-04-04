document.addEventListener("DOMContentLoaded", function() {
    var elemT = document.getElementById('inputText');

    var elemB = document.getElementById('TextHandler');
    var elemB2 = document.getElementById('rbHandler');

    elemB.addEventListener('click', function () {
        console.log(elemT.value);
    })

    elemB2.addEventListener('click', function () {
        console.log(document.querySelector('input[name="rb"]:checked').value);
    })
});
