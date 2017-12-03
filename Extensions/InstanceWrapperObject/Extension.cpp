/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2017 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#include "GDCpp/Extensions/ExtensionBase.h"

#include "InstanceWrapperObject.h"


void DeclareInstanceWrapperObjectExtension(gd::PlatformExtension & extension)
{
    extension.SetExtensionInformation("InstanceWrapperObject",
                              _("Instance Wrapper Object"),
                              _("This Extension enables the use of Instance Wrapper objects."),
                              "Franco Maciel",
                              "Open source (MIT License)");

    gd::ObjectMetadata & obj = extension.AddObject<InstanceWrapperObject>(
               "InstanceWrapper",
               _("Instance Wrapper"),
               _("Works as a container for another instance, like a \"variable object\""),
               "CppPlatform/Extensions/TiledSpriteIcon.png");

    #if defined(GD_IDE_ONLY)
    #if !defined(GD_NO_WX_GUI)
    InstanceWrapperObject::LoadEdittimeIcon();
    #endif
    obj.SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");
    
    obj.AddAction("SayHello",
                   _("Say hello"),
                   _("Displays a nice message in the console."),
                   _("Say hello for _PARAM0_"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced()
        .SetFunctionName("SayHello").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddAction("PointingAt",
                   _("Pointing at?"),
                   _("Displays the wrapped instance pointer address."),
                   _("Display where _PARAM0_ is pointing at"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced()
        .SetFunctionName("PointingAt").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddAction("SetInstance",
                   _("Set instance"),
                   _("Set the wrapper instance."),
                   _("Set _PARAM1_ as current _PARAM0_ instance"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .AddParameter("objectPtr", _("Object"))
        .MarkAsAdvanced()
        .SetFunctionName("SetInstance").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddAction("ClearInstance",
                   _("Clear instance"),
                   _("Clear the wrapper current instance."),
                   _("Clear current instance of _PARAM0_"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced()
        .SetFunctionName("ClearInstance").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddAction("DeleteInstance",
                   _("Delete instance"),
                   _("Delete from the scene the wrapper instance."),
                   _("Delete from scene the current instance of _PARAM0_"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .AddCodeOnlyParameter("currentScene", "")
        .MarkAsAdvanced()
        .SetFunctionName("DeleteInstance").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddCondition("CurrentInstance",
                   _("Current instance"),
                   _("Check if the object is the wrapper current instance."),
                   _("_PARAM1_ is the current instance of _PARAM0_"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .AddParameter("objectList", _("Object"))
        .MarkAsAdvanced()
        .SetFunctionName("CurrentInstance").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    obj.AddCondition("Empty",
                   _("Empty"),
                   _("Check if the wrapper is empty (has no current instance)."),
                   _("_PARAM0_ is empty"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced()
        .SetFunctionName("Empty").SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");

    #endif
}

/**
 * \brief This class declares information about the extension.
 */
class InstanceWrapperObjectCppExtension : public ExtensionBase
{
public:

    /**
     * Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    InstanceWrapperObjectCppExtension()
    {
        DeclareInstanceWrapperObjectExtension(*this);
        AddRuntimeObject<InstanceWrapperObject, RuntimeInstanceWrapperObject>(
            GetObjectMetadata("InstanceWrapperObject::InstanceWrapper"),
            "RuntimeInstanceWrapperObject");

        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
};

#if defined(ANDROID)
extern "C" ExtensionBase * CreateGDCppInstanceWrapperObjectExtension() {
    return new InstanceWrapperObjectCppExtension;
}
#elif !defined(EMSCRIPTEN)
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new InstanceWrapperObjectCppExtension;
}
#endif
