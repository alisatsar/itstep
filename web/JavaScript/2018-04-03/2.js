document.addEventListener("DOMContentLoaded", function() {
    var elems = document.getElementsByClassName('myB');

    for(var i = 0; i< elems.length; i++)
    {
        elems[i].addEventListener("click", function () {
            this.innerText = "newBText";
            console.log(this.innerHTML);
        })
    }
});
