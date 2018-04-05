$(document).ready(function() {
    // $('.cl').on('click', function(){
    //     console.log($(this).text("bye"));
    // })
    //
    // $('.cl').on('click', function(){
    //     console.log($('#inp').val());
    // })

    $('.cl').on('click', function(){
        var value = $('#inp').val();
         $('#dataTb').append('<tr>\
             <td>'+value+'</td>\
             <td><button class="delBtn">X</button></td>\
             </tr>');
        $('#dataTb').addClass('bordered');
    })

    $(document).on('click', '.delBtn', function(){
        $(this).closest('tr').remove();
        if($('#dataTb').find('tr').length < 1)
        {
            $('#dataTb').removeClass('bordered');
        }

    })

    // $('#show').on('click', function() {
    //     $('#ss').show('slow');
    // });
    //
    // $('#hide').on('click', function() {
    //     $('#ss').hide('slow');
    // });

    $('.bt').on('click', function() {
        if($(this).attr('data-action') =='show')
        {
            $('#ss').show(1000);
        }
        else
        {
            $('#ss').hide(1000);
        }
    });
});
