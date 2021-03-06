# Калькулятор :S
### Шо, как, где, почему
На вход подается строка вида `12.3+3/5*(1+3^2)`.  
Пробелы в выражении нормально обрабатываются, но различные некорректные строки (например: `12++3`) пока отсеивать не умеет.  
Также в планах есть реализация графического интерфейса.  
Все введённые числа для удобства сразу переводятся в обычные дроби ***(т.к. изначальная задача- вывести ответ в виде обыкновенной дроби)***
***
### Кастомный тип для чисел с плавающей точкой (O_o зачем?)
У стандартного float, ввиду некоторых особенностей, при касте к std::string вылезали рандомные цифры на месте малых разрядов. Поэтому было решено сделать собственный тип для чисел с плавающей точкой, который хранил бы количество значимых знаков после запятой.  
`по-хорошему это нафиг не нужный геморрой, т.к. получается, что я сначала кастую строку к float, а затем обратно кастую к строке, затем разбиваю на два int. Но мне просто стало интересно это реализовать. (Никитка- дурачок)`
***
### Простые дроби
Также был реализован класс **SimpleFraction** с перегруженными операторами, а также методом `relax` для упрощения дроби (с помощью алгоритма Евклида). Кроме этого есть отдельная функция для перевода из кастомного типа для чисел с плавающей точкой к обычной дроби (зачем это вообще было сделано, описал выше).
***
### Доступные операторы
* `^` :ballot_box_with_check:
* `*` :ballot_box_with_check:
* `/` :ballot_box_with_check:
* `+` :ballot_box_with_check:
* `-` :ballot_box_with_check:
* `()` :ballot_box_with_check: 
***
### Дерево выполнения выражения
Существует дерево из элементов **EquationNode**, каждый из которых умеет рекурсивно вычислять своё значение с помощью своих потомков.
***
### Алгоритм
* Происходит ввод выражения, после этого оно разбивается на токены `(в вектор отдельно записываются операторы и числа)` :ballot_box_with_check:
* Разбитое на токены выражение упрощается для корректного построения дерева :ballot_box_with_check:
* На основе данного вектора строится дерево, узлами которого являются операторы, листами числа. :ballot_box_with_check:
* Вычисления происходят в порядке выполнения DFS :ballot_box_with_check:
* Корректно отрабатывает с отрицательными числами :ballot_box_with_check:
* Корректно отрабатывает со скобками :ballot_box_with_check:
***
### Ввод выражения
**`Аргумент в коммандной строке`**  
Если выражение не содержит скобок, то можно его вводить в произвольном формате (например `"2 +   3 -3"` или `2 +3    ^  4`).  
В противном случае, необходимо заключить выражение в двойные кавычки (например `"2+3^1"` или `" 2 +    4^  1"`)  
**`Ввод после запуска исполняемого файла`**  
Выражение можно вводить в произвольном формате, но не заключая его в кавычки.  
**`GUI`**  
:construction:
