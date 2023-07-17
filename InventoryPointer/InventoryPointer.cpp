// InventoryPointer
// Демонстрирует возврат указателя

#include <string>
#include <vector>
#include <iostream>
using namespace std;
// Возвращает указатель на строковый элемент
string* ptrToElement(vector<string>* const pVec, int i);
int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    // отображает строковый элемент, на который направлен возвращенный указатель
    cout << "Sending the object pointer to by returned pointer to cout:\n";
    cout << *(ptrToElement(&inventory, 0)) << "\n\n";
    // присваивает один указатель другому - малозатратная операция
    cout << "Assigning the returned pointer to another pointer.\n";
    string* pStr = ptrToElement(&inventory, 1);
    cout << "Sending the object pointer to by new pointer to cout:\n";
    cout << *pStr << "\n\n";
    // копирует строковый объект - затратная операция присваивания
    cout << "Assigning object pointed to by pointer to a string object.\n";
    string str = *(ptrToElement(&inventory, 2));
    cout << "Sending the new string object to cout:\n";
    cout << str << "\n\n";
    // изменение строкового объекта посредством возвращаемого указателя
    cout << "Altering an object to cout:\n";
    cout << inventory[1] << endl;
    return 0;
}
string* ptrToElement(vector<string>* const pVec, int i)
{
    // возвращает адрес строкового объекта, расположенного на позиции i
    // в том векторе, на который направлен указатель pVec
    return &((*pVec)[i]);
}
