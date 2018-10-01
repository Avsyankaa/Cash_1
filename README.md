# Лабораторная работа #2

> Кэш - промежуточный буфер с быстрым доступом, содержащий информацию, которая может быть запрошена с наибольшей вероятностью. Доступ к данным в кэше осуществляется быстрее, чем выборка исходных данных из более медленной памяти или удаленного источника, однако её объём существенно ограничен по сравнению с хранилищем исходных данных.

### Задача

Для каждого из вариантов проходов (*прямой*, *обратный* и *случайный*) целочисленного массива 
провести исследование зависимости времени от размера.

Каждое исследование включает в себя серию эксперементов c определенными размерами.
Количество экспериментов в серии определяется следующим образом:

```cpp
1/2 * cache_sizes['1'] < 2^x < 2^(x+1) < ... < 2^(x+n) < 3/2 * cache_sizes['max']
```

### Пример

В примере ниже показано, что для процессора с тремя уровнями кэша (`2mb`, `4mb`, `8mb`)
необходимо провести серию из 5 эксперементов.

```cpp
cache_size['1'] = 2 mb;
cache_size['2'] = 4 mb;
cache_size['3'] = 8 mb;

// 1mb < 2mb < 4mb < 8mb < 12mb
```

### Структура эксперимента

Каждый эксперемент состоит из 3 шагов:

```
1. Создание буфера
2. Прогревание кэша
// <-- время начала эксперемнта
3. Циклический проход (1000 итераций)
// <-- время окончание эксперемента
```

### Результаты

Ниже представлен формат и пример отчета:

```yaml
investigation:                                       |  investigaion:
  travel_variant: <вариант_прохода>                  |    travel_order: "direction"
  experiments:                                       |    experiments:
  - experiment:                                      |    - experiment:
      number:                                        |        number: 1
      input_data:                                    |        input_data:
        buffer_size: <размер_буфера>                 |          buffer_size: "1mb"
      results:                                       |        results:
        duration: <продолжительность>                |          duration: "1ns"
  - experiment:                                      |    - experiment:
      number: <номер_эксперимента>                   |        number: 2
      input_data:                                    |        input_data:
        buffer_size: <размер_буфера>                 |          buffer_size: "2mb"
      results:                                       |        results:
        duration: <продолжительность>                |          duration: "2ns"
                                                     |
investigation:                                       |  investigation:
...                                                  |  ...
```

В отчет также необходимо добавить общий график с результатами всех исследований.
