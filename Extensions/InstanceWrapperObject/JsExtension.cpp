/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/
#if defined(GD_IDE_ONLY)
#include "GDCore/Extensions/PlatformExtension.h"

#include "InstanceWrapperObject.h"

#include <iostream>


void DeclareInstanceWrapperObjectExtension(gd::PlatformExtension & extension);

/**
 * \brief This class declares information about the JS extension.
 */
class InstanceWrapperObjectJsExtension : public gd::PlatformExtension
{
public:

    /**
     * Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    InstanceWrapperObjectJsExtension()
    {
        DeclareInstanceWrapperObjectExtension(*this);

        GetObjectMetadata("InstanceWrapperObject::InstanceWrapper").SetIncludeFile("Extensions/InstanceWrapperObject/instancewrapperruntimeobject.js");

        GetAllActionsForObject("InstanceWrapperObject::InstanceWrapper")["InstanceWrapperObject::SetInstance"]
          .SetFunctionName("setInstance").SetIncludeFile("Extensions/InstanceWrapperObject/instancewrapperruntimeobject.js");
        GetAllActionsForObject("InstanceWrapperObject::InstanceWrapper")["InstanceWrapperObject::ClearInstance"]
          .SetFunctionName("clearInstance").SetIncludeFile("Extensions/InstanceWrapperObject/instancewrapperruntimeobject.js");
        GetAllConditionsForObject("InstanceWrapperObject::InstanceWrapper")["InstanceWrapperObject::Empty"]
          .SetFunctionName("empty").SetIncludeFile("Extensions/InstanceWrapperObject/instancewrapperruntimeobject.js");
        
        GetAllConditions()["InstanceWrapperObject::CurrentInstance"].codeExtraInformation
          .SetIncludeFile("Extensions/InstanceWrapperObject/instancewrapperruntimeobject.js")
          .SetFunctionName("gdjs.InstanceWrapperObject.currentInstance");

        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
};

#if defined(EMSCRIPTEN)
extern "C" gd::PlatformExtension * CreateGDJSInstanceWrapperObjectExtension() {
    return new InstanceWrapperObjectJsExtension;
}
#else
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" gd::PlatformExtension * GD_EXTENSION_API CreateGDJSExtension() {
    return new InstanceWrapperObjectJsExtension;
}
#endif
#endif
