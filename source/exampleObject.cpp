#include "../include/exampleObject.h"
using namespace std;

Animal::Animal()
{
    cout << "Animal created" << endl;
}
Animal::~Animal()
{
    cout << "Animal destroyed" << endl;
}
void Animal::speak()
{
    cout << "Meow" << endl;
}