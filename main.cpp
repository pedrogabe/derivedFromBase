#include <iostream>

using namespace std;

class base
{
protected:
    int _baseId;
    int _anotherNumber;
public:
    base(int a, int b)
    {
        _baseId = a;
        _anotherNumber = b;
    }
    int getId()
    {
        return _baseId;
    }
    int getNumber()
    {
        return _anotherNumber;
    }
    void setNumber(int n)
    {
        _anotherNumber=n;
    }
};


class derived:base
{
private:
    int _derivedId;
public:
    derived(base a, int c) : base(a)
    {
        _derivedId=c;
    }
    void doThing()
    {
        cout << _baseId<< endl;
        cout << _anotherNumber << endl;
        cout << _derivedId << endl;
    }
};


int main(){
    base base_a(1,3);
    cout << base_a.getId() << endl; //Muestra 1
    cout << base_a.getNumber() << endl; //Muestra 3

    cout << "" << endl;
    derived der_a(base_a, 7);
    der_a.doThing();    //Muestra 1: El atributo heredado _baseId cuyo valor es una copia del _baseId del parámetro a del constructor, que a su vez es una copia de base_a
                        //Muestra 3: El atributo heredado _anotherNumber cuyo valor es una copia del _anotherNumber del parámetro a del constructor, que a su vez es una copia de base_a
                        //Muestra 7: El atributo privado _derivedId cuyo valor es una copia del parámetro c del constructor

    cout << "" << endl;
    base_a.setNumber(4);
    cout << base_a.getNumber() << endl; //Muestra 4

    cout << "" << endl;
    der_a.doThing();    //Muestra 1: El atributo heredado _baseId cuyo valor es una copia del _baseId del parámetro a del constructor, que a su vez es una copia de base_a al momento de instanciarse der_a
                        //Muestra 3: El atributo heredado _anotherNumber cuyo valor es una copia del _anotherNumber del parámetro a del constructor, que a su vez es una copia de base_a al momento de instanciarse der_a
                        //Muestra 7: El atributo privado _derivedId cuyo valor es una copia del parámetro c del constructor

    return 0;
}
