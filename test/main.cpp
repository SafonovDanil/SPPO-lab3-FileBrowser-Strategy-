#include <QCoreApplication>

#include "Unit.h"
#include "CppUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"
#include "ifactory.h"
#include "CppFactory.h"


//std::string generateProgram() {
// ClassUnit myClass( "MyClass" );
// myClass.add(
// std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
// ClassUnit::PUBLIC
// );
// myClass.add(
// std::make_shared< MethodUnit >( "testFunc2", "void",
//MethodUnit::STATIC ),
// ClassUnit::PRIVATE
// );
// myClass.add(
// std::make_shared< MethodUnit >( "testFunc3", "void",
//MethodUnit::VIRTUAL | MethodUnit::CONST ),
// ClassUnit::PUBLIC
// );
// auto method = std::make_shared< MethodUnit >( "testFunc4",
//"void", MethodUnit::STATIC );
// method->add( std::make_shared< PrintOperatorUnit >( R"(Hello,
//world!\n)" ) );
// myClass.add( method, ClassUnit::PROTECTED );
// return myClass.compile();
//}

std::string generateProgram(IFactory* factory) {
    
    std::shared_ptr<Unit> myClass = factory->createClassUnit("MyClass");


    myClass->add(factory->createMethodUnit("testFunc1", "void", 0), CppUnit::PUBLIC);

    myClass->add(factory->createMethodUnit("testFunc2", "void", CppMethodUnit::STATIC), CppUnit::PRIVATE);

    myClass->add(factory->createMethodUnit("testFunc3", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST), CppUnit::PUBLIC);

    auto method = factory->createMethodUnit("testFunc4", "void", CppMethodUnit::STATIC);

    method->add(factory->createPrintOperatorUnit(R"(Hello,world!\n)"));

    myClass->add(method, CppUnit::PROTECTED );

    return myClass->compile();
}


int main()
{
    CppFactory factory;
    std::cout << generateProgram(&factory) << std::endl;
    return 0;
}



