## Главный цикл:
Игровой цикл обрабатывает пользовательский ввод, но не ожидает его.
Цикл продолжает крутиться всегда.
```
while (true)
{
 $ Events()
 $ update(delta t) or animate, interpolate
 $ render() const
 $ swap()
}
```

 


### Дополнительно:
<b> $ENV{CFLAGS} </b> 
переменная среды. Environmental Variables.<br> 
от родительского процесса наследуем все переменные среды (например, PATH)<br>

