def makebold(a):
    def wrapped():
        return "<b>" + a() + "<b>"
    return wrapped

def makeitalic(a):
    def wrapped():
        return "<i>" + a() + "</i>"
    return wrapped

@makeitalic
@makebold
def hello():
    return "hello habr"

print(hello())

("\n\nPress the enter key to exit.")

#вывод <i><b>hello habr<b></i>


def shout(word = "yes"):
    return word.capitalize() + "!"

print(shout()) # выведет: 'Да!'

# Так как функция - это объект, вы связать её с переменнной,
# как и любой другой объект
scream = shout
