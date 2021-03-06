/**
 * \file euclidianMoveParameters.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <vector>
#include <stddef.h>
#include "core/xml/generated/euclidianMoveParameters.h"

/**
 *  Looks extremely unsafe because it depends on the order of static initialization.
 *  Should check standard if this is ok
 *
 *  Also it's not clear why removing "= Reflection()" breaks the code;
 **/

namespace corecvs {
template<>
Reflection BaseReflection<EuclidianMoveParameters>::reflection = Reflection();
template<>
int BaseReflection<EuclidianMoveParameters>::dummy = EuclidianMoveParameters::staticInit();
} // namespace corecvs 

SUPPRESS_OFFSET_WARNING_BEGIN


using namespace corecvs;

int EuclidianMoveParameters::staticInit()
{

    ReflectionNaming &nameing = naming();
    nameing = ReflectionNaming(
        "Euclidian Move Parameters",
        "Euclidian Move Parameters",
        ""
    );

     getReflection()->objectSize = sizeof(EuclidianMoveParameters);
     

    DoubleField* field0 = new DoubleField
        (
          EuclidianMoveParameters::X_ID,
          offsetof(EuclidianMoveParameters, mX),
          0,
          "X",
          "X",
          "X",
          true,
         -50000,
         50000
        );
    field0->widgetHint=BaseField::SPIN_BOX;
    field0->precision=2;
    fields().push_back(field0);
    /*  */ 
    DoubleField* field1 = new DoubleField
        (
          EuclidianMoveParameters::Y_ID,
          offsetof(EuclidianMoveParameters, mY),
          0,
          "Y",
          "Y",
          "Y",
          true,
         -50000,
         50000
        );
    field1->widgetHint=BaseField::SPIN_BOX;
    field1->precision=2;
    fields().push_back(field1);
    /*  */ 
    DoubleField* field2 = new DoubleField
        (
          EuclidianMoveParameters::Z_ID,
          offsetof(EuclidianMoveParameters, mZ),
          0,
          "Z",
          "Z",
          "Z",
          true,
         -50000,
         50000
        );
    field2->widgetHint=BaseField::SPIN_BOX;
    field2->precision=2;
    fields().push_back(field2);
    /*  */ 
    DoubleField* field3 = new DoubleField
        (
          EuclidianMoveParameters::ALPHA_ID,
          offsetof(EuclidianMoveParameters, mAlpha),
          0,
          "alpha",
          "alpha",
          "alpha",
          true,
         -50000,
         50000
        );
    field3->widgetHint=BaseField::SPIN_BOX;
    field3->suffixHint="deg";
    field3->precision=2;
    fields().push_back(field3);
    /*  */ 
    DoubleField* field4 = new DoubleField
        (
          EuclidianMoveParameters::BETA_ID,
          offsetof(EuclidianMoveParameters, mBeta),
          0,
          "beta",
          "beta",
          "beta",
          true,
         -50000,
         50000
        );
    field4->widgetHint=BaseField::SPIN_BOX;
    field4->suffixHint="deg";
    field4->precision=2;
    fields().push_back(field4);
    /*  */ 
    DoubleField* field5 = new DoubleField
        (
          EuclidianMoveParameters::GAMMA_ID,
          offsetof(EuclidianMoveParameters, mGamma),
          0,
          "gamma",
          "gamma",
          "gamma",
          true,
         -50000,
         50000
        );
    field5->widgetHint=BaseField::SPIN_BOX;
    field5->suffixHint="deg";
    field5->precision=2;
    fields().push_back(field5);
    /*  */ 
    ReflectionDirectory &directory = *ReflectionDirectoryHolder::getReflectionDirectory();
    directory[std::string("Euclidian Move Parameters")]= &reflection;
   return 0;
}
int EuclidianMoveParameters::relinkCompositeFields()
{
   return 0;
}

SUPPRESS_OFFSET_WARNING_END


