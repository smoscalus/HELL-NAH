# HELL NAH - Локальная Embedded База Данных на C++

**Описание:**  
HELL NAH - это аккуратная, локальная, типизированная база данных, разработанная на C++ для одного клиента.  
Название символизирует противоположность хаосу предыдущей версии HELL YEAH.  

**Цель проекта:**  
- Хранение пользовательских данных локально в бинарных файлах  
- Поддержка шаблонных таблиц под любые POD-структуры  
- Простое и безопасное API для CRUD операций  
- Используется в образовательных целях для курсовой работы
  
## Архитектура
Data-Centric Layered Architecture
### Core → Storage → Engine → User
```
hellnot/
├── include/hellnah/Core/         # Core layer: фундаментальные сущности и правила формата (POD-структуры, RecordId, заголовки файлов/записей)
├── include/hellnah/Storage/      # Storage layer: работа с бинарными файлами (чтение/запись, сериализация/десериализация)
├── include/hellnah/Engine/       # Engine layer: публичный API для работы с таблицами и CRUD операциями
├── src/                          # Реализация классов Storage и Engine
│   ├── Storage/                  # Реализация логики работы с файлами
│   └── Engine/                   # Реализация API таблиц и базы
├── examples/                     # Примеры использования базы
├── tests/                        # Unit и интеграционные тесты
├── CMakeLists.txt                # Сборка проекта
└── README.md                     # Документация
```

HELL NAH разделена на три слоя:

1. **Core** — фундаментальные сущности
    - `RecordId` — генератор уникальных идентификаторов
    - Структуры данных (POD-типы для таблиц)
2. **Storage** — работа с бинарными файлами
    - Append-only запись
    - Сериализация и десериализация записей
    - Файловый заголовок и контроль версий
3. **Engine** — публичный интерфейс
    - Таблицы (`Table<T>`) для работы с конкретными типами
    - CRUD операции (`insert`, `get`, `remove`)
    
### Заголовок файла (DbHeader)
- `magic[8]` — идентификатор файла ("HELLNOT")
- `version` — версия формата

### Запись (RecordHeader)
- `id` — уникальный идентификатор записи
- `size` — размер данных
- `deleted` — 0/1

## Использование (пример кода)
```
#include "Database.h"

struct Student {
    uint32_t age;
    char name[32];
};

int main() {
    Database db("students.hellnot");

    auto students = db.open_table<Student>("students");

    auto id = students.insert({20, "Alex"});
    auto student = students.get(id);

    students.remove(id);
}
```
