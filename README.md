# HELL NAH - Локальна Embedded База Даних на C++

**Опис:**  
HELL NAH - це акуратна, локальна, типізована база даних, розроблена на C++ для одного клієнта.  
Назва символізує протилежність хаосу попередньої версії HELL YEAH.  

**Мета проєкту:**  
- Зберігання користувацьких даних локально у бінарних файлах  
- Підтримка шаблонних таблиць під будь-які POD-структури  
- Простий та безпечний API для CRUD операцій  
- Використовується в освітніх цілях для курсової роботи

## Архітектура
Data-Centric Layered Architecture
### Core → Storage → Engine → User
```
hellnot/
├── include/hellnah/Core/         # Core layer: фундаментальні сутності та правила формату (POD-структури, RecordId, заголовки файлів/записів)
├── include/hellnah/Storage/      # Storage layer: робота з бінарними файлами (читання/запис, серіалізація/десеріалізація)
├── include/hellnah/Engine/       # Engine layer: публічний API для роботи з таблицями та CRUD операціями
├── src/                          # Реалізація класів Storage та Engine
│   ├── Storage/                  # Реалізація логіки роботи з файлами
│   └── Engine/                   # Реалізація API таблиць та бази
├── examples/                     # Приклади використання бази
├── tests/                        # Unit та інтеграційні тести
├── CMakeLists.txt                # Збірка проєкту
└── README.md                     # Документація
```

HELL NAH розділена на три шари:

1. **Core** — фундаментальні сутності
    - `RecordId` — генератор унікальних ідентифікаторів
    - Структури даних (POD-типи для таблиць)
2. **Storage** — робота з бінарними файлами
    - Append-only запис
    - Серіалізація та десеріалізація записів
    - Файловий заголовок та контроль версій
3. **Engine** — публічний інтерфейс
    - Таблиці (`Table<T>`) для роботи з конкретними типами
    - CRUD операції (`insert`, `get`, `remove`)
    
### Заголовок файлу (DbHeader)
- `magic[8]` — ідентифікатор файлу ("HELLNOT")
- `version` — версія формату

### Запис (RecordHeader)
- `id` — унікальний ідентифікатор запису
- `size` — розмір даних
- `deleted` — 0/1

## Використання (приклад коду)
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
