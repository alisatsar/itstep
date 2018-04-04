document.addEventListener("DOMContentLoaded", function() {
    var elem = document.getElementById('myButton');

    /*elem.onclick = function () {
     console.log('element ty id');
     };*/

    elem.addEventListener('click', function () {
        console.log('addEventlistener');
    });

    elem.addEventListener('click', function () {
        console.log('323423');
    });
});
