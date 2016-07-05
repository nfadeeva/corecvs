#ifndef EGOMOTION_PARAMETERS_H_
#define EGOMOTION_PARAMETERS_H_
/**
 * \file egomotionParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "reflection.h"
#include "defaultSetter.h"
#include "printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

namespace corecvs {
}
/*
 *  Additional includes for enum section.
 */

/**
 * \brief Egomotion Parameters 
 * Egomotion Parameters 
 **/
class EgomotionParameters : public BaseReflection<EgomotionParameters>
{
public:
    enum FieldId {
        TEST_ID,
        EGOMOTION_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief test 
     * test 
     */
    double mTest;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    double test() const
    {
        return mTest;
    }

    /* Section with setters */
    void setTest(double test)
    {
        mTest = test;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit(mTest,                      static_cast<const DoubleField *>  (fields()[TEST_ID]));
    }

    EgomotionParameters()
    {
        DefaultSetter setter;
        accept(setter);
    }

    EgomotionParameters(
          double test
    )
    {
        mTest = test;
    }

    friend ostream& operator << (ostream &out, EgomotionParameters &toSave)
    {
        PrinterVisitor printer(out);
        toSave.accept<PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        cout << *this;
    }
};
#endif  //EGOMOTION_PARAMETERS_H_