## Главный цикл:
Игровой цикл обрабатывает пользовательский ввод, но не ожидает его.<br>
Цикл продолжает крутиться всегда. <br>
Events() обрабатывает пользовательский ввод с момента прошлого вызова<br>
update() продвигает симуляцию игры на один шаг<br>
render() рисует игру<br>
swap() свапает буфер, 
<a href="https://martalex.gitbooks.io/gameprogrammingpatterns/content/chapter-3/3.1-double-buffering.html">технология двойной буферизации</a>
```
while (true)
{
  Events()
  update(delta t) or animate, interpolate
  render() const
  swap()
}
```

 


### Дополнительно:
<b> $ENV{CFLAGS} </b> 
переменная среды. Environmental Variables.<br> 
от родительского процесса наследуем все переменные среды (например, PATH)<br>


