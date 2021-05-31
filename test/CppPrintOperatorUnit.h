#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "Unit.h"

class CppPrintOperatorUnit : public Unit {
public:
 explicit CppPrintOperatorUnit( const std::string& text ) :
m_text( text ) { }
 std::string compile( unsigned int level = 0 ) const {
 return generateShift( level ) + "printf( \"" + m_text
+ "\" );\n";
 }
private:
 std::string m_text;
};

#endif // PRINTOPERATORUNIT_H
