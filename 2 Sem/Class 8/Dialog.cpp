#include "Dialog.h"
#include <iostream>
#include <string>
#include <cstdlib>

Dialog::Dialog() : Vector(), endState(0) {}

Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event)
{
    std::string opInt = "m+-sqz";
    std::string s;
    char code;

    std::cout << "\n> ";
    std::getline(std::cin, s);

    if (s.empty())
    {
        event.what = evNothing;
        return;
    }

    code = s[0];

    if (opInt.find(code) != std::string::npos)
    {
        event.what = evMessage;
        switch (code)
        {
        case 'm': event.command = cmMake; break;
        case '+': event.command = cmAdd; break;
        case '-': event.command = cmDel; break;
        case 's': event.command = cmShow; break;
        case 'z': event.command = cmGet; break;
        case 'q': event.command = cmQuit; break;
        default: event.what = evNothing; break;
        }

        if (event.what == evMessage && s.length() > 1)
        {
            std::string param = s.substr(1, s.length() - 1);
            event.a = atoi(param.c_str());
        }
        else
        {
            event.a = 0;
        }
    }
    else
    {
        event.what = evNothing;
        std::cout << "Неизвестная команда. Доступные команды: m, +, -, s, z, q" << std::endl;
    }
}

int Dialog::Execute()
{
    TEvent event;
    std::cout << "=== Программа управления группой ===" << std::endl;
    std::cout << "Команды:" << std::endl;
    std::cout << "  m N - создать группу из N элементов" << std::endl;
    std::cout << "  +    - добавить элемент в группу" << std::endl;
    std::cout << "  -    - удалить элемент из группы" << std::endl;
    std::cout << "  s    - показать всю группу" << std::endl;
    std::cout << "  z k  - показать имя элемента с номером k" << std::endl;
    std::cout << "  q    - выход" << std::endl;

    do
    {
        endState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return endState;
}

void Dialog::HandleEvent(TEvent& event)
{
    if (event.what == evMessage)
    {
        switch (event.command)
        {
        case cmMake:
            if (event.a > 0)
            {
                size = event.a;
                if (beg != nullptr) delete[] beg;
                beg = new Object * [size];
                cur = 0;
                std::cout << "Создана группа на " << size << " элементов" << std::endl;
            }
            else
            {
                std::cout << "Ошибка: размер должен быть больше 0" << std::endl;
            }
            ClearEvent(event);
            break;

        case cmAdd:
            Add();
            ClearEvent(event);
            break;

        case cmDel:
            Del();
            ClearEvent(event);
            break;

        case cmShow:
            Show();
            ClearEvent(event);
            break;

        case cmGet:
            Vector::HandleEvent(event);
            ClearEvent(event);
            break;

        case cmQuit:
            std::cout << "Завершение работы..." << std::endl;
            EndExec();
            ClearEvent(event);
            break;

        default:
            ClearEvent(event);
            break;
        }
    }
}
void Dialog::ClearEvent(TEvent& event)
{
    event.what = evNothing;
}
int Dialog::Valid()
{
    return endState != 0;
}
void Dialog::EndExec()
{
    endState = 1;
}